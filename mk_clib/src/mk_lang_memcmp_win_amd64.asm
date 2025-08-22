RtlCompareMemory proto

.code

memcmp proc
	mov qword ptr [rsp +  8], rbx
	mov qword ptr [rsp + 16], rsi
	push rdi
	sub rsp, 32
	mov rbx, r8
	mov rdi, rdx
	mov rsi, rcx
	call RtlCompareMemory
	mov r8, rax
	cmp rax, rbx
	jne nonequal
	xor eax, eax
	mov rbx, qword ptr [ rsp + 48 ]
	mov rsi, qword ptr [ rsp + 56 ]
	add rsp, 32
	pop rdi
	ret 0
nonequal:
	movzx eax, byte ptr [ rsi + rax ]
	movzx ecx, byte ptr [ rdi + r8 ]
	mov rbx, qword ptr [ rsp + 48 ]
	sub eax, ecx
	mov rsi, qword ptr [ rsp + 56 ]
	add rsp, 32
	pop rdi
	ret 0
memcmp endp

end
