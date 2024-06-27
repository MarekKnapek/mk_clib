RtlFillMemory proto

.code

memset proc
	xchg rdx, r8
	jmp RtlFillMemory
memset endp

end
