#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"


#define mk_lang_bui_divmod_fuzz_inl_func_def_fn \
	mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_bui_divmod_fuzz_t_, \
	mk_lang_bui_divmod_fuzz_inl_func_lt), _), \
	mk_lang_bui_divmod_fuzz_inl_func_st), _), \
	mk_lang_to_num_as), _), \
	mk_lang_to_num_bs), _), \
	mk_lang_bui_divmod_fuzz_inl_func_endian), _), \
	mk_lang_bui_divmod_fuzz_inl_func_alg)
#define mk_lang_bui_divmod_fuzz_inl_func_def_lt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_fuzz_inl_func_lt), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_def_st mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_divmod_fuzz_inl_func_st), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_divmod_fuzz_inl_func_lt), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_divmod_fuzz_inl_func_st), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_def_has2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_bui_divmod_fuzz_inl_func_st), _has)
#define mk_lang_bui_divmod_fuzz_inl_func_def_has3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_bui_divmod_fuzz_inl_func_st), _has)
