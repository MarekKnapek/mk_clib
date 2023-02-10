#include "mk_lang_bui_divmod_fuzz_inl_call_def.h"


#if \
( \
	(mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_st <= mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_lt) && \
	((mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_lt % mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_st) == 0) && \
	(mk_lang_bui_divmod_fuzz_inl_call_lena <= (mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_st)) && \
	(mk_lang_bui_divmod_fuzz_inl_call_lenb <= (mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_st)) && \
	( \
		(mk_lang_bui_divmod_fuzz_inl_call_lena == 1 && mk_lang_bui_divmod_fuzz_inl_call_lenb == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_call_alg == 2 && mk_lang_bui_divmod_fuzz_inl_call_def_has2 == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_call_alg == 3 && mk_lang_bui_divmod_fuzz_inl_call_def_has3 == 1) \
	) \
)
mk_lang_bui_divmod_fuzz_inl_call_def_fn(data, size);
#endif


#include "mk_lang_bui_divmod_fuzz_inl_call_undef.h"


#undef mk_lang_bui_divmod_fuzz_inl_call_alg
