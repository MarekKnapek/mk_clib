mk_lang_rt_terminate proto

.code

memcmp proc
	jmp mk_lang_rt_terminate
memcmp endp

end
