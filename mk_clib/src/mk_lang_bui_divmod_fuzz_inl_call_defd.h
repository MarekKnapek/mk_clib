#include "mk_lang_concat.h"
#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"


#define mk_lang_bui_divmod_fuzz_inl_call_defd_lt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_st mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_fora_bui2_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_lena mk_lang_fora_count_n
#define mk_lang_bui_divmod_fuzz_inl_call_defd_lenb mk_lang_fora_count2_n
#define mk_lang_bui_divmod_fuzz_inl_call_defd_endian_value mk_lang_fora_endian_value
#define mk_lang_bui_divmod_fuzz_inl_call_defd_endian_name mk_lang_fora_endian_name
#define mk_lang_bui_divmod_fuzz_inl_call_defd_divalg mk_lang_fora_divalg_id
#define mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_lt mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_st mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_fora_bui2_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_has2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_fora_bui2_tn), _has)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_has3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_fora_bui2_tn), _has)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_fn \
	mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_bui_divmod_fuzz_t_, \
	mk_lang_fora_bui_tn), _), \
	mk_lang_fora_bui2_tn), _), \
	mk_lang_bui_divmod_fuzz_inl_call_defd_lena), _), \
	mk_lang_bui_divmod_fuzz_inl_call_defd_lenb), _), \
	mk_lang_bui_divmod_fuzz_inl_call_defd_endian_name), _), \
	mk_lang_bui_divmod_fuzz_inl_call_defd_divalg)
#if \
( \
	(mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_lt >= mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_st) && \
	((mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_lt % mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_st) == 0) && \
	(mk_lang_bui_divmod_fuzz_inl_call_defd_lena <= (mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_st)) && \
	(mk_lang_bui_divmod_fuzz_inl_call_defd_lenb <= (mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_call_defd_sizeof_st)) && \
	( \
		(mk_lang_bui_divmod_fuzz_inl_call_defd_lena == 1 && mk_lang_bui_divmod_fuzz_inl_call_defd_lenb == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_call_defd_divalg == 2 && mk_lang_bui_divmod_fuzz_inl_call_defd_has2 == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_call_defd_divalg == 3 && mk_lang_bui_divmod_fuzz_inl_call_defd_has3 == 1) \
	) \
)
#define mk_lang_bui_divmod_fuzz_inl_call_defd_valid 1
#else
#define mk_lang_bui_divmod_fuzz_inl_call_defd_valid 0
#endif
