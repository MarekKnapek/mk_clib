mk_lang_rt_terminate proto

.code

__std_terminate proc
	jmp mk_lang_rt_terminate
__std_terminate endp

end
