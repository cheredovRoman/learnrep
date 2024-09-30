; *************************************************************************
; 16-bit MS-DOS COM 
; EXE File size: 542 Bytes
; Created by Visual MASM (http://www.visualmasm.com)
; For 16-bit DOS running restricts under Windows 2000/XP see below. 
; *************************************************************************
.model	small						; Designate the application as EXE file
				
.data
				db 256 dup(?)     			; Выделение памяти для стека  
	messout 	db 'Result: $'    			; Сообщение при выводе результата
 	messin 		db 'Enter number: $'    	; Сообщение при вводе
 	MesMat		db 'Matrix',0Dh, 0Ah, '$'
 	space		db ' $'                 	; Пробел
 	endl		db 0Dh, 0Ah, '$'            ; Переход на новую строку
	pNmb		db 10 dup(?),'$' 			; Переменная для вывода числа, здесь лежит число после преобразования в строку
	input_Buf 	db 06,00,5 dup(?)    		; Переменная для хранения числа пользователя
	min			dw ?
	sum			dw ?
	flag		dw 0
	result		dw 0
 
 	; Объявление квадратной матрицы
	matrix macro name,length
			 name 	dw length*length dup (0)		                       
	endm                         
	 
.code
	include bin2str.asm ; подпрограмма преобразования числа 2сфт в строку
	include str2bin.asm ; подпрограмма преобразования строки в двоичное число
	
	; Ввод пользовательского числа и сохранение его в в переменную num
	input macro num						
			 Print messin 				; Вывод сообщения	
			 lea dx,input_buf 			; в dx - адрес буфера ввода
			 mov ah,0ah 				; в AH - номер функции ввода числа с клавиатуры
			 int 21h 					; вызов прерывания ввода числа с клавиатуры
			 mov bx,dx 					; перегрузить в bx адрес буфера
			 inc bx 					; увеличить адрес на единицу
			 call str2bin 				; обратиться к подпрограмме преобразования
			 mov num,ax
	endm
	
	; Вывод строки в консоль
	Print macro string     
			lea dx, string
			mov ah, 09h
			int 21h
	endm
	
	; Вывод числа в консоль                        
	PrintNumber macro name
 			mov ax,name                 
			lea bx,pNmb     
			call bin2str    ; обратиться к подпрограмме преобразования
			Print pNmb+1	; Вывод числа
			Print space     ; Вывод сообщения
	endm
	
	; Заполнение матрицы пользовательскими числами
	MatrixInput macro name,length 
 			i=0
			rept length*length
				Input name+i			
				i=i+2                       
				Print endl	
			endm
	endm
	
	; Вывод матрицы в консоль
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
	
	; Поиск минимума в массиве (или например в строке матрицы)
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
	; Суммирование элементов массива (или строки матрицы)
	SumRow macro name,length
			i=0
			mov ax,0
			rept length
				add ax,name+i
				i=i+2	
			endm
			mov sum,ax
	endm
	; Проверка есть ли элемент в массиве (или в строке матрицы)
	CheckElement macro name, length, element
			i=0
			rept length
				.if(name+i == element)
					mov flag,1
				.endif
				i=i+2
			endm
			
	endm
	; Макрос задания
	; Результат сохранятся в переменную result
	Zadanie macro name, length
			mov result,0						; Обнуление результата
			j=0
			FindMin name,length					; Поиск минимума в матрице
			rept length                         ; Для каждой строки матрицы
				mov ax,min                      
				CheckElement name+j,length, ax  ; Проверить есть ли минимум в строке
				.if(flag == 1)                  ; Если есть
					SumRow name+j,length        ; Суммирование всех элементов этой строки
					mov ax,sum
					add result,ax               ; добавить сумму к перменной result
					mov flag,0                  ; обнулить флаг
				.endif	
				j=j+(length*2)	                ; Переход на следущую строку
			endm
	endm
		
	main	proc
			; Выделения памяти для стека
			mov ax,@data
			mov ds,ax

       		; Основная часть программы
       		
       		; Матрица A 2x2
       		matrix A,2			; Объявление матрицы A (2x2)
	       	MatrixInput A,2		; Заполнение матрицы
			Print MesMat	    ; Вывод сообщения
        	PrintMatrix A,2     ; Вывод матрицы в консоль
			Zadanie A,2         ; Макрос задания
			Print messout       ; Вывод сообщения
			PrintNumber result  ; Напечатать результат работы макроса задания
			Print endl          ; Вывод сообщения       

			; Матрица B 3x3
 			matrix B,3			; Объявление матрицы A (2x2)
	       	MatrixInput B,3     ; Заполнение матрицы
			Print MesMat	    ; Вывод сообщения
        	PrintMatrix B,3     ; Вывод матрицы в консоль
			Zadanie B,3         ; Макрос задания
			Print messout       ; Вывод сообщения
			PrintNumber result  ; Напечатать результат работы макроса задания
			Print endl          ; Вывод сообщения

			; Матрица D 4x4
 			matrix D,4			; Объявление матрицы A (2x2)
	       	MatrixInput D,4     ; Заполнение матрицы
			Print MesMat	    ; Вывод сообщения
        	PrintMatrix D,4     ; Вывод матрицы в консоль
			Zadanie D,4         ; Макрос задания
			Print messout       ; Вывод сообщения
			PrintNumber result  ; Напечатать результат работы макроса задания
			Print endl          ; Вывод сообщения

			; Выход из программы
			mov	ax,4c00h
			int	21h					
	main	endp
	
end	main
