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










;_memcpy proc
;	push edi
;	push esi
;	mov edi, dword ptr ss:[esp + 3 * 4]
;	mov esi, dword ptr ss:[esp + 4 * 4]
;	mov ecx, dword ptr ss:[esp + 5 * 4]
;	cld
;	cmp ecx, 8 - 1
;	jle rest
;	mov eax, edi
;	xor eax, esi
;	test al, 3
;	jne rest
;	mov eax, ecx
;	mov edx, edi
;	and edx, 3
;	mov ecx, 4
;	sub ecx, edx
;	sub eax, ecx
;	rep movsb byte ptr es:[edi], byte ptr ds:[esi]
;	mov ecx, eax
;	shr ecx, 2
;	rep movsd dword ptr es:[edi], dword ptr ds:[esi]
;	mov ecx, eax
;	and ecx, 3
;rest:
;	rep movsb byte ptr es:[edi], byte ptr ds:[esi]
;	pop esi
;	pop edi
;	ret
;_memcpy endp
