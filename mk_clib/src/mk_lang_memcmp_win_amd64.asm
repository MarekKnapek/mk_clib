RtlCompareMemory proto

.code

memcmp proc
	push r8
	call RtlCompareMemory
	pop r8
	sub rax, r8
	ret
memcmp endp

end
