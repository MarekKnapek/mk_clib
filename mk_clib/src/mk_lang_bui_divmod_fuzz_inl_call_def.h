#include "mk_lang_concat.h"
#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"


#define mk_lang_bui_divmod_fuzz_inl_call_def_fn \
	mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_bui_divmod_fuzz_t_, \
	mk_lang_bui_divmod_fuzz_inl_call_lt), _), \
	mk_lang_bui_divmod_fuzz_inl_call_st), _), \
	mk_lang_bui_divmod_fuzz_inl_call_lena), _), \
	mk_lang_bui_divmod_fuzz_inl_call_lenb), _), \
	mk_lang_bui_divmod_fuzz_inl_call_endian), _), \
	mk_lang_bui_divmod_fuzz_inl_call_alg)
#define mk_lang_bui_divmod_fuzz_inl_call_def_lt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_fuzz_inl_call_lt), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_def_st mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_fuzz_inl_call_st), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_lt mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_divmod_fuzz_inl_call_lt), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_def_sizeof_st mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_divmod_fuzz_inl_call_st), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_def_has2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_fuzz_inl_call_st), _has)
#define mk_lang_bui_divmod_fuzz_inl_call_def_has3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_bui_divmod_fuzz_inl_call_st), _has)
