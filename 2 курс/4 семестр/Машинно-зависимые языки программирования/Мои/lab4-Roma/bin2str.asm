; ��楤�� �८�ࠧ������ ����筮�� �᫠ � ��ப� ᨬ�����
; �室 - ax - �᫮;
; ��室 - ��ப� �� ����� ds:bx
bin2str proc
        push dx
	push cx
	push bx
	push si
	push ax
	mov cx,6
fill_buff:
        mov byte ptr [bx+1],' '    ; ��������� ��ப� �஡�����
	inc bx
	loop fill_buff
	mov  si,10                 ; �����⮢����� � ������� �� 10
        or  ax,ax                  ; �᫨ � (ax) ����⥫쭮� �᫮
        jns clr_div
        neg ax                     ; � �������� ��� ����
clr_div:
        sub dx,dx                  ; ������ ������ �������� ��������
        div si                     ;(dx;ax)/10 -> (१ -> ax, ���->dx)
        add dx,'0'                 ; �८�ࠧ����� ���⮪ � ᨬ�. ���
        dec bx
        mov [bx+1],dl              ; ��������� ��।�. ���� � ��ப�
        or  ax,ax                  ; � ॣ���� ax - 0?
        jnz clr_div                ; ���, ������� ��楤���
        pop ax
	or ax,ax                   ; ���.�᫮ ����⥫쭮 ?
        jns no_more                ; ���, ⮣�� ��
        dec bx
        mov byte ptr [bx+1],'-'    ; �������� � ��ப� ���� '-'
no_more:   
        pop si
        pop bx
        mov byte ptr [bx],6                  ; �������� ���稪 ᨬ�����
        pop cx
        pop dx
        ret
bin2str endp
