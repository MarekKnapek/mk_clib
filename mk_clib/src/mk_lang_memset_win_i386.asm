.model flat

.code

_memset proc
	push edi
	mov edi, dword ptr ss:[esp + 2 * 4]
	mov eax, dword ptr ss:[esp + 3 * 4]
	mov ecx, dword ptr ss:[esp + 4 * 4]
	rep stosb
	pop edi
	ret
_memset endp

end
