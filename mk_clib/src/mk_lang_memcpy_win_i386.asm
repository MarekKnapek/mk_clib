.model flat

.code

_memcpy proc
	push edi
	push esi
	mov edi, dword ptr ss:[esp + 3 * 4]
	mov esi, dword ptr ss:[esp + 4 * 4]
	mov ecx, dword ptr ss:[esp + 5 * 4]
	cld
	rep movsb byte ptr es:[edi], byte ptr ds:[esi]
	pop esi
	pop edi
	ret
_memcpy endp

end
