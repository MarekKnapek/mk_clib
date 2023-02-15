#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_min.h"
#include "mk_lang_sizeof.h"


#define mk_lang_bui_divmod_fuzz_inl_func_defd_lt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_st mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_fora_bui2_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_lena mk_lang_fora_count_n
#define mk_lang_bui_divmod_fuzz_inl_func_defd_lenb mk_lang_fora_count2_n
#define mk_lang_bui_divmod_fuzz_inl_func_defd_lend mk_lang_min(mk_lang_bui_divmod_fuzz_inl_func_defd_lena, mk_lang_bui_divmod_fuzz_inl_func_defd_lenb)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_endian_value mk_lang_fora_endian_value
#define mk_lang_bui_divmod_fuzz_inl_func_defd_endian_name mk_lang_fora_endian_name
#define mk_lang_bui_divmod_fuzz_inl_func_defd_divalg mk_lang_fora_divalg_id
#define mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_lt mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_fora_bui2_tn), _t)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_has2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_fora_bui2_tn), _has)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_has3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_fora_bui2_tn), _has)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_maska ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1)) << ((mk_lang_bui_divmod_fuzz_inl_func_defd_lena) * (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st) * (mk_lang_charbit) - 1))) - ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1)))) << 1)) + ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1))))
#define mk_lang_bui_divmod_fuzz_inl_func_defd_maskb ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1)) << ((mk_lang_bui_divmod_fuzz_inl_func_defd_lenb) * (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st) * (mk_lang_charbit) - 1))) - ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1)))) << 1)) + ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(1))))
#if mk_lang_bui_divmod_fuzz_inl_func_defd_endian_value == mk_lang_endian_little
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxa(x) (x)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxb(x) (x)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxd(x) (x)
#elif mk_lang_bui_divmod_fuzz_inl_func_defd_endian_value == mk_lang_endian_big
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxa(x) ((mk_lang_bui_divmod_fuzz_inl_func_defd_lena - 1) - (x))
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxb(x) ((mk_lang_bui_divmod_fuzz_inl_func_defd_lenb - 1) - (x))
#define mk_lang_bui_divmod_fuzz_inl_func_defd_idxd(x) ((mk_lang_bui_divmod_fuzz_inl_func_defd_lend - 1) - (x))
#endif
#define mk_lang_bui_divmod_fuzz_inl_func_defd_fn \
	mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_bui_divmod_fuzz_t_, \
	mk_lang_fora_bui_tn), _), \
	mk_lang_fora_bui2_tn), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_lena), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_lenb), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_endian_name), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_divalg)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_divmod \
	mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_concat(mk_lang_concat( \
	mk_lang_bui_divmod_, \
	mk_lang_fora_bui2_tn), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_lena), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_lenb), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_endian_name), _), \
	mk_lang_bui_divmod_fuzz_inl_func_defd_divalg)
#if \
( \
	(mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_lt >= mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st) && \
	((mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_lt % mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st) == 0) && \
	(mk_lang_bui_divmod_fuzz_inl_func_defd_lena <= (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st)) && \
	(mk_lang_bui_divmod_fuzz_inl_func_defd_lenb <= (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st)) && \
	( \
		(mk_lang_bui_divmod_fuzz_inl_func_defd_lena == 1 && mk_lang_bui_divmod_fuzz_inl_func_defd_lenb == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_func_defd_divalg == 2 && mk_lang_bui_divmod_fuzz_inl_func_defd_has2 == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_func_defd_divalg == 3 && mk_lang_bui_divmod_fuzz_inl_func_defd_has3 == 1) \
	) \
)
#define mk_lang_bui_divmod_fuzz_inl_func_defd_valid 1
#else
#define mk_lang_bui_divmod_fuzz_inl_func_defd_valid 0
#endif
