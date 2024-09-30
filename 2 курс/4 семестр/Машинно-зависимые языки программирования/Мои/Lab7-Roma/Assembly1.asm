.386 ; Enable 80386+ instruction set
.model flat, stdcall ; Flat, 32-bit memory model (not used in 64-bit)
option casemap: none ; Case sensitive syntax
; *************************************************************************
; Our Window procedure prototype
; *************************************************************************
WndProc proto :DWORD,:DWORD,:DWORD,:DWORD
; *************************************************************************
; Our main application procedure prototype
; *************************************************************************
WinMain proto :DWORD,:DWORD,:DWORD,:DWORD
print_text proto :DWORD
draw_house proto :DWORD
draw_picture proto :DWORD,:DWORD
; *************************************************************************
include \masm32\include\windows.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include \masm32\include\gdi32.inc
; *************************************************************************
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\gdi32.lib

; *************************************************************************
; Our initialized data section. Here we declare our strings.
; *************************************************************************
.data
	ClassName db "OurWindow",0
	WindowTitle db "OurWindow",0
; *************************************************************************
; Our un-initialized data section. We don't care about the values assigned.
; *************************************************************************
.data?
hInstance HINSTANCE ?
CommandLine LPSTR ? 
.code

start:
	
	szText MACRO Name, Text:VARARG
		 LOCAL lbl
		 jmp lbl
		 Name db Text,0
		 lbl:
 	ENDM
	
	RGB MACRO red,green,blue
		 
		 xor eax,eax
		 mov ah,blue
		 shl eax,8
		 mov ah,green
		 mov al,red
	ENDM
	
	invoke GetModuleHandle, NULL ; Handle экземпляра
	mov hInstance,eax ; приложения
	invoke GetCommandLine ; указатель на командную строку
	mov CommandLine,eax ;
	invoke WinMain, hInstance,NULL,
 	CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
		LOCAL wc:WNDCLASSEX
		LOCAL msg:MSG
		LOCAL hWin:HWND
		mov wc.cbSize,SIZEOF WNDCLASSEX
		mov wc.style, CS_HREDRAW or CS_VREDRAW or CS_DBLCLKS
		mov wc.lpfnWndProc, OFFSET WndProc
		mov wc.cbClsExtra,NULL
		mov wc.cbWndExtra,NULL
		push hInst
		pop wc.hInstance
		mov wc.hbrBackground,COLOR_BTNFACE+1
		mov wc.lpszMenuName,NULL
		mov wc.lpszClassName,OFFSET ClassName
		invoke LoadIcon,NULL,IDI_APPLICATION 
		mov wc.hIcon,eax
		mov wc.hIconSm,eax
		invoke LoadCursor,NULL,IDC_ARROW
		mov wc.hCursor,eax
		invoke RegisterClassEx, addr wc
		invoke CreateWindowEx,NULL, ADDR ClassName, ADDR WindowTitle, WS_OVERLAPPEDWINDOW,
		 CW_USEDEFAULT,0, CW_USEDEFAULT,0, NULL,NULL,hInstance,NULL
		mov hWin,eax
		invoke ShowWindow, hWin,SW_SHOWNORMAL
		invoke UpdateWindow, hWin
		.WHILE TRUE
			invoke GetMessage, ADDR msg,NULL,0,0
			.BREAK .IF (!eax)
			invoke TranslateMessage, ADDR msg
			invoke DispatchMessage, ADDR msg
		.ENDW
		mov eax,msg.wParam
		ret
	WinMain endp

	WndProc proc hWnd:DWORD, uMsg:DWORD, wParam:DWORD,
		lParam:DWORD
		LOCAL hDC :DWORD
		LOCAL Ps:PAINTSTRUCT
		.IF uMsg==WM_DESTROY
		invoke PostQuitMessage,NULL
		.ELSEIF uMsg == WM_PAINT
			invoke BeginPaint,hWnd,ADDR Ps
	 		mov hDC, eax
			invoke print_text,hDC
			invoke draw_house,hDC
			invoke draw_picture,hWnd,hDC
			invoke EndPaint,hWnd,ADDR Ps
		.ELSE
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
		ret
		.ENDIF
		xor eax,eax
		ret
	WndProc endp
	
	; Функция которая печатает текст 
	print_text proc hDC :HDC
		LOCAL hObj :DWORD
		LOCAL hOldObj :DWORD
		szText String1,"Vector Picture"
		szText String2,"Raster Picture"
		;Вывод текста ANSI-шрифтом, дескриптор уже существует
		invoke GetStockObject,ANSI_FIXED_FONT
		mov hObj,eax
		invoke SelectObject,hDC,hObj
		mov hOldObj,eax
		invoke TextOut,hDC,150,400,offset String1,14
		invoke SelectObject,hDC,hOldObj
		invoke DeleteObject,hObj
		;Вывод текста ANSI-VAR шрифтом
		invoke GetStockObject,ANSI_VAR_FONT
		mov hObj,eax
		invoke SelectObject,hDC,hObj
		mov hOldObj,eax
		invoke TextOut,hDC,623,400,offset String2,14
		invoke SelectObject,hDC,hOldObj
		invoke DeleteObject,hObj
		ret
	print_text endp
	
	; Функция для изображения домика в векторной графике 
	draw_house proc hDC :HDC
		LOCAL lb:LOGBRUSH
		
		invoke MoveToEx,hDC,100,150,0
		invoke LineTo,hDC,200,25
		
		invoke MoveToEx,hDC,200,25,0
		invoke LineTo,hDC,300,150
		
		mov lb.lbStyle,BS_HATCHED
	 	mov lb.lbColor,BLACK_BRUSH
	 	mov lb.lbHatch,HS_BDIAGONAL
	 	invoke CreateBrushIndirect,addr lb
	 	invoke SelectObject,hDC,eax
	 	invoke Rectangle,hDC,100,150,300,350
	 	
	 	RGB 0, 191, 255
        invoke CreateSolidBrush,eax
        invoke SelectObject,hDC,eax
        invoke Rectangle,hDC,150,200,250,300
	 	
        invoke MoveToEx,hDC,200,200,0
		invoke LineTo,hDC,200,300
		
		invoke MoveToEx,hDC,150,250,0
		invoke LineTo,hDC,250,250
             
	 	invoke DeleteObject,eax
		ret 
	draw_house endp
	
	; Функция рисует растровое изображение  <--
	draw_picture proc hWin:DWORD,  hDC:DWORD
		LOCAL hBmp :DWORD
		LOCAL hOld :DWORD
 		LOCAL memDC :DWORD
		invoke LoadBitmap,hInstance,100
		mov hBmp, eax	
 		invoke CreateCompatibleDC,hDC
 		mov memDC, eax
 		invoke SelectObject,memDC,hBmp
		mov hOld, eax
	 	invoke BitBlt,hDC,500,100,650,500,memDC,0,0,SRCCOPY
	 	invoke SelectObject,memDC,hOld
	 	invoke DeleteDC,memDC
	 	ret
	draw_picture endp
end start
