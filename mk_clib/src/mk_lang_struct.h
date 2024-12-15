#ifndef mk_include_guard_mk_lang_struct
#define mk_include_guard_mk_lang_struct


#define mk_lang_struct(x) \
	struct x##_s; \
	typedef struct x##_s x##_t; \
	typedef x##_t const x##_ct; \
	typedef x##_t* x##_pt; \
	typedef x##_t const* x##_pct; \
	typedef x##_pt* x##_ppt; \
	typedef x##_pt* x##_pcpt; \
	typedef x##_pct* x##_ppct; \
	typedef x##_pct const* x##_pcpct; \


#if mk_lang_jumbo_want == 1
/*#include "mk_lang_struct.c"*/
#endif
#endif
