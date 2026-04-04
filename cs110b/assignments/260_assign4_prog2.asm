
; Program template

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data

A DWORD ?
B DWORD 1
C1 DWORD 2	; C is a reserved word
D DWORD 3
E DWORD 4
F DWORD 5
G DWORD 6
H DWORD 7
I DWORD 8
J DWORD 9
K DWORD 10
L DWORD 11
M DWORD 12
N DWORD 13
O DWORD 14
P DWORD 15

.code
main proc

mov eax, 0 ; initialize eax to 0

; d*e = 3*4 (add E three times)
add eax, E
add eax, E
add eax, E

mov ebx, eax ; ebx=12

; *f = 12*5 (add ebx four more times, eax already has 12)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=60

; *g = 60*6 (add ebx five more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=360

; *h = 360*7 (add ebx six more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=2520

; *i = 2520*8 (add ebx seven more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=20,160

; *j = 20160*9 (add ebx eight more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=181,440

; *k = 181440*10 (add ebx nine more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

mov ebx, eax ; ebx=1,814,400

; *l = 1814400*11 (add ebx ten more times)
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx
add eax, ebx

; + b + c + m + n + o + p
add eax, B
add eax, C1
add eax, M
add eax, N
add eax, O
add eax, P

mov A, eax

	invoke ExitProcess,0
main endp
end main
