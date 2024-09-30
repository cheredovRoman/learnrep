; ��楤�� �८�ࠧ������ ��ப� ᨬ����� � ����筮� �᫮.
; �室 - ds:bx   - ���� ��ப�
; ��室 - ax - �᫮ � ������
;
str2bin  proc
	push bx
	push cx
	sub ax,ax        ; ���㫨�� ax
	sub ch,ch        ; ������ ch
        mov cl,byte ptr [bx]  ; ���稪 ᨬ����� - � CX
blanks: cmp byte ptr[bx+1],' '   ;横� �ய�᪠ �஡����
        jne chk_neg
	inc bx
        loop blanks
        jmp  good        ; �� �����㦥�� �ᥫ. १���� - 0
;
; ������騥 ������� �믮������� � ��砥 �����  "-"
;
chk_neg: cmp byte ptr [bx+1],'-'
	jne chk_pos
	inc bx               ; �த������ 㪠��⥫�
	dec cx               ; 㬥����� ���稪
	call conv_ab         ; �맢��� �ணࠬ�� �८�ࠧ������
        jc thru              ;
	cmp ax,32768         ; �᫮ < -32768
	ja  no_good          ; ��, �訡��
        neg ax               ; �������� ���� �᫠
        js  good             ; o'key , ��室��
;
; ������騥 ������� �믮������� � ��砥, �᫨ ���� �� �����
;
chk_pos: cmp byte ptr [bx+1],'+'   ; sign '+' ?
        jne go_conv           ; ��� , ��� �� �८�ࠧ������
        inc bx                ; ᬥ���� 㪠��⥫� � ��ப�
        dec cx                ; 㬥����� ���稪 ᨬ�����
go_conv: call conv_ab         ; �८�ࠧ����� ��ப� � �᫮
        jc thru               ; � ��砥 �訡�� - �� ��室
        cmp ax,32767          ; �᫮ �� ᫨誮� ������ ?
        ja no_good            ; ᫨誮� ������, �訡��
good:   clc                   ; ������ 䫠� CY
        jnc thru              
no_good: stc                  ; set carry flag
thru:   pop cx                ; ����⠭����� ���祭�� ॣ���஢
	pop bx
	jmp skipit
;
; ��楤�� ᮡ�⢥��� �८�ࠧ������ �᫠
;
conv_ab proc
	push bp
	push bx
	push si
	mov  bp,bx      ; �������� 㪠��⥫� �� ��ப� � bp
        sub  bx,bx      ; ������ bx
range:  cmp byte ptr ds:[bp+1],'0'  ; ᨬ��� - ��� ?
        jb  non_dig                 ; ��� �� ���
        cmp byte ptr ds:[bp+1],'9'  ; ᨬ��� > '9'
        jbe digit                   ; ᨬ��� - ���
non_dig: stc                        ; ��⠭����� 䫠� �訡��
        jc end_conv                 ; � ��� �� ��楤���
digit:  mov si,10
	push dx                     ; ��࠭��� dx
        mul si                      ; (ax)*(si)->(dx;ax)
        pop dx                      ; ����⠭����� dx
        mov bl,ds:[bp+1]            ; ����� ��।��� ᨬ��� �� ��ப�
        and bx,0fh                  ; �८�ࠧ����� ᨬ��� � ����筮�
        add ax,bx                   ; �������� ����� � ��஬� १�����
        jc  end_conv                ; �᫨ १���� ᫨誮� �����,� ���
        inc bp                      ; ���� ᫥� ���� � ��ப�
        loop range                  ; �������� 横� �� �������� ᨬ�����
        clc                         ; ����� 䫠� ��७��(��� �訡��)
end_conv:   pop si                    ; ����⠭����� ॣ����� � ���
         pop bx
         pop bp
         ret
conv_ab  endp
skipit:   ret
str2bin  endp
