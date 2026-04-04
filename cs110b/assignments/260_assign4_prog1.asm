; Program template

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	A DWORD ?
	B DWORD 5
	C1 DWORD 10
	D DWORD 4
	E DWORD 6
	F DWORD 7
	G DWORD 8
	H DWORD 2
	I DWORD 3
	J DWORD 12

.code
main proc
mov eax, 0

; B+C = 5+10
add eax, B
add eax, C1

; D*B = 4*5 (add B four times)
add eax, B
add eax, B
add eax, B
add eax, B

; B*E = 5*6 (add E five times)
add eax, E
add eax, E
add eax, E
add eax, E
add eax, E

; E*F = 6*7 (add F six times)
add eax, F
add eax, F
add eax, F
add eax, F
add eax, F
add eax, F

; F*G = 7*8 (add G seven times)
add eax, G
add eax, G
add eax, G
add eax, G
add eax, G
add eax, G
add eax, G

; D*D = 4*4 (add D four times)
add eax, D
add eax, D
add eax, D
add eax, D

; B*B = 5*5 (add B five times)
add eax, B
add eax, B
add eax, B
add eax, B
add eax, B

; H*I = 2*3 (add I two times)
add eax, I
add eax, I

; I*D = 3*4 (add D three times)
add eax, D
add eax, D
add eax, D

; H+J
add eax, H
add eax, J

mov A, eax

	invoke ExitProcess,0
main endp
end main
