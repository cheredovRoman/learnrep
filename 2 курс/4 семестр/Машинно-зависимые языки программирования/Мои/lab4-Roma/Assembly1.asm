; *************************************************************************
; 16-bit MS-DOS COM 
; EXE File size: 542 Bytes
; Created by Visual MASM (http://www.visualmasm.com)
; For 16-bit DOS running restricts under Windows 2000/XP see below. 
; *************************************************************************
.model	small						; Designate the application as EXE file
				
.data
				db 256 dup(?)     			; ��������� ������ ��� �����  
	messout 	db 'Result: $'    			; ��������� ��� ������ ����������
 	messin 		db 'Enter number: $'    	; ��������� ��� �����
 	MesMat		db 'Matrix',0Dh, 0Ah, '$'
 	space		db ' $'                 	; ������
 	endl		db 0Dh, 0Ah, '$'            ; ������� �� ����� ������
	pNmb		db 10 dup(?),'$' 			; ���������� ��� ������ �����, ����� ����� ����� ����� �������������� � ������
	input_Buf 	db 06,00,5 dup(?)    		; ���������� ��� �������� ����� ������������
	min			dw ?
	sum			dw ?
	flag		dw 0
	result		dw 0
 
 	; ���������� ���������� �������
	matrix macro name,length
			 name 	dw length*length dup (0)		                       
	endm                         
	 
.code
	include bin2str.asm ; ������������ �������������� ����� 2��� � ������
	include str2bin.asm ; ������������ �������������� ������ � �������� �����
	
	; ���� ����������������� ����� � ���������� ��� � � ���������� num
	input macro num						
			 Print messin 				; ����� ���������	
			 lea dx,input_buf 			; � dx - ����� ������ �����
			 mov ah,0ah 				; � AH - ����� ������� ����� ����� � ����������
			 int 21h 					; ����� ���������� ����� ����� � ����������
			 mov bx,dx 					; ����������� � bx ����� ������
			 inc bx 					; ��������� ����� �� �������
			 call str2bin 				; ���������� � ������������ ��������������
			 mov num,ax
	endm
	
	; ����� ������ � �������
	Print macro string     
			lea dx, string
			mov ah, 09h
			int 21h
	endm
	
	; ����� ����� � �������                        
	PrintNumber macro name
 			mov ax,name                 
			lea bx,pNmb     
			call bin2str    ; ���������� � ������������ ��������������
			Print pNmb+1	; ����� �����
			Print space     ; ����� ���������
	endm
	
	; ���������� ������� ����������������� �������
	MatrixInput macro name,length 
 			i=0
			rept length*length
				Input name+i			
				i=i+2                       
				Print endl	
			endm
	endm
	
	; ����� ������� � �������
	PrintMatrix macro name,length
			i=0
			rept length
				rept length
					PrintNumber name+i			
					i=i+2                       
				endm
				Print endl
			endm
	endm
	
	; ����� �������� � ������� (��� �������� � ������ �������)
	FindMin macro name,length
		    mov ax, 999999
	        i=0
	        rept length*length
        		.if(name+i < ax)
        			mov ax,name+i
        		.endif
        		i=i+2        	
	        endm
	        mov min,ax	        
	endm
	; ������������ ��������� ������� (��� ������ �������)
	SumRow macro name,length
			i=0
			mov ax,0
			rept length
				add ax,name+i
				i=i+2	
			endm
			mov sum,ax
	endm
	; �������� ���� �� ������� � ������� (��� � ������ �������)
	CheckElement macro name, length, element
			i=0
			rept length
				.if(name+i == element)
					mov flag,1
				.endif
				i=i+2
			endm
			
	endm
	; ������ �������
	; ��������� ���������� � ���������� result
	Zadanie macro name, length
			mov result,0						; ��������� ����������
			j=0
			FindMin name,length					; ����� �������� � �������
			rept length                         ; ��� ������ ������ �������
				mov ax,min                      
				CheckElement name+j,length, ax  ; ��������� ���� �� ������� � ������
				.if(flag == 1)                  ; ���� ����
					SumRow name+j,length        ; ������������ ���� ��������� ���� ������
					mov ax,sum
					add result,ax               ; �������� ����� � ��������� result
					mov flag,0                  ; �������� ����
				.endif	
				j=j+(length*2)	                ; ������� �� �������� ������
			endm
	endm
		
	main	proc
			; ��������� ������ ��� �����
			mov ax,@data
			mov ds,ax

       		; �������� ����� ���������
       		
       		; ������� A 2x2
       		matrix A,2			; ���������� ������� A (2x2)
	       	MatrixInput A,2		; ���������� �������
			Print MesMat	    ; ����� ���������
        	PrintMatrix A,2     ; ����� ������� � �������
			Zadanie A,2         ; ������ �������
			Print messout       ; ����� ���������
			PrintNumber result  ; ���������� ��������� ������ ������� �������
			Print endl          ; ����� ���������       

			; ������� B 3x3
 			matrix B,3			; ���������� ������� A (2x2)
	       	MatrixInput B,3     ; ���������� �������
			Print MesMat	    ; ����� ���������
        	PrintMatrix B,3     ; ����� ������� � �������
			Zadanie B,3         ; ������ �������
			Print messout       ; ����� ���������
			PrintNumber result  ; ���������� ��������� ������ ������� �������
			Print endl          ; ����� ���������

			; ������� D 4x4
 			matrix D,4			; ���������� ������� A (2x2)
	       	MatrixInput D,4     ; ���������� �������
			Print MesMat	    ; ����� ���������
        	PrintMatrix D,4     ; ����� ������� � �������
			Zadanie D,4         ; ������ �������
			Print messout       ; ����� ���������
			PrintNumber result  ; ���������� ��������� ������ ������� �������
			Print endl          ; ����� ���������

			; ����� �� ���������
			mov	ax,4c00h
			int	21h					
	main	endp
	
end	main
