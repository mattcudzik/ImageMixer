;inputA inputB numOfPixels factor output
;RCX	RDX		R8			R9		stack

;R10	R11		R8			R9		R12	

.code
MixValues2 proc
	
	mov r10, rcx		;inputA - R10
	mov r11, rdx		;inputB - R11
	mov r12, [rsp+8*5]	;output - R12 (from stack)
	mov rcx, r8			;set loop counter

lp:
	xor rax, rax
	xor rbx, rbx

	mov al, [r10]	;read pixel A
	shl eax, 16		;make space for pixel B
	mov bl, [r11]	;read pixel B
	mov al, bl		;EAX = |0A||0B|

	imul rax, r9	;RAX = |A*u|B*u|
	shl rbx, 8		;RBX = B*256
		
	sub bx, ax		;RBX = B*256-B*u

	shr rax, 16		;RAX = A*u

	add bx, ax		;RBX = B*256-B*u+A*u
	
	shr rbx, 8		;RBX = (B*256-B*u+A*u)/256

	mov [r12], bl	;save to memory

	;move to next pixel
	inc r10
	inc r11
	inc r12

	loop lp
	ret
MixValues2 endp


;inputA inputB numOfPixels factor output
;RCX	RDX	   R8		   R9	  stack

MixValues3 proc
	mov r10, rcx
	mov r11, rdx
	mov r12, [rsp+8*5]
	mov rcx, r8

	mov rbx, r9
	

	mov rax, 256
	sub rax, rbx
	mov ah, bl		;RAX = |0000|u|u-1|

	pxor mm6, mm6

	movd mm7, rax

	punpcklbw mm7, mm6
	punpckldq mm7, mm7

led:
	movq mm0, [r10]	;mm0 = |x|x|x|x|A3|A2|A1|A0|
	movq mm1, [r11]	;mm1 = |x|x|x|x|B3|B2|B1|B0|

	punpcklbw mm0, mm6	;mm0 = |00 A3|00 A2|00 A1|00 A0|
	punpcklbw mm1, mm6	;mm1 = |00 B3|00 B2|00 B1|00 B0|
	
	movq mm2, mm0
	movq mm3, mm1

	punpcklwd mm0, mm1	;mm0 = |00 B1|00 A1|00 B0|00 A0|
	punpckhwd mm2, mm3	;mm2 = |00 B3|00 A3|00 B2|00 A2|

						;mm7 = |u|1-u|u|1-u|

	pmaddwd mm0, mm7	;mm0 = |u*B1 + (1-u)*A1|u*B0 + (1-u)*A0|
	pmaddwd mm2, mm7	;mm0 = |u*B3 + (1-u)*A3|u*B2 + (1-u)*A2|

	psrld     mm0, 8
	psrld     mm2, 8

	packssdw  mm0, mm2
	packuswb mm0, mm6

	movq rax, mm0
	mov [r12], eax

	add r10, 4
	add r11, 4
	add r12, 4
	sub rcx, 4

	jrcxz abc
	jmp led
abc:
	ret
MixValues3 endp

;inputA inputB numOfPixels factor output
;RCX	RDX	   R8		   R9	  stack

MixValues1 proc
	mov r10, rcx
	mov r11, rdx
	mov r12, [rsp+8*5]
	mov rcx, r8

	mov rbx, r9

	mov rax, 256
	sub rax, rbx
	mov ah, bl		;RAX = |0000|u|u-1|

	movq xmm7, rax

	PMOVZXBW xmm7, xmm7
	punpckldq xmm7, xmm7
	punpckldq xmm7, xmm7

mainLoop:
	movups xmm0, [r10]	;mm0 = |x|x|x|x|A3|A2|A1|A0|
	movups xmm1, [r11]	;mm1 = |x|x|x|x|B3|B2|B1|B0|

	PMOVZXBW xmm0, xmm0		;mm0 = |00 A3|00 A2|00 A1|00 A0|
	PMOVZXBW xmm1, xmm1		;mm1 = |00 B3|00 B2|00 B1|00 B0|
	
	movups xmm2, xmm0
	movups xmm3, xmm1

	punpcklwd xmm0, xmm1	;mm0 = |00 B1|00 A1|00 B0|00 A0|
	punpckhwd xmm2, xmm3	;mm2 = |00 B3|00 A3|00 B2|00 A2|

							;mm7 = |u|1-u|u|1-u|

	pmaddwd xmm0, xmm7	;mm0 = |u*B1 + (1-u)*A1|u*B0 + (1-u)*A0|
	pmaddwd xmm2, xmm7	;mm2 = |u*B3 + (1-u)*A3|u*B2 + (1-u)*A2|

	psrld     xmm0, 8	;mm0/256
	psrld     xmm2, 8	;mm2/256

	packssdw  xmm0, xmm2
	packuswb xmm0, xmm6

	movq rax, xmm0
	mov [r12], rax

	add r10, 8
	add r11, 8
	add r12, 8
	sub rcx, 8

	cmp rcx, 0
	jle endProcedure
	jmp mainLoop
endProcedure:
	ret
MixValues1 endp
end