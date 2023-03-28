#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_concat.h"
#include "mk_lang_min.h"


#if \
	defined mk_lang_bui_divmod_btn && \
	defined mk_lang_bui_divmod_bt && \
	defined mk_lang_bui_divmod_bt2 && \
	defined mk_lang_bui_divmod_bt3 && \
	defined mk_lang_bui_divmod_lena && \
	defined mk_lang_bui_divmod_lenb && \
	defined mk_lang_bui_divmod_endian && \
	defined mk_lang_bui_divmod_alg && \
	defined mk_lang_bui_divmod_name && \
	1
#define mk_lang_bui_divmod_inl_defd_btn mk_lang_bui_divmod_btn
#define mk_lang_bui_divmod_inl_defd_bt mk_lang_bui_divmod_bt
#define mk_lang_bui_divmod_inl_defd_bt2 mk_lang_bui_divmod_bt2
#define mk_lang_bui_divmod_inl_defd_bt3 mk_lang_bui_divmod_bt3
#define mk_lang_bui_divmod_inl_defd_lena mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_inl_defd_lenb mk_lang_bui_divmod_lenb
#define mk_lang_bui_divmod_inl_defd_endian mk_lang_bui_divmod_endian
#define mk_lang_bui_divmod_inl_defd_alg mk_lang_bui_divmod_alg
#define mk_lang_bui_divmod_inl_defd_name mk_lang_bui_divmod_name
#define mk_lang_bui_divmod_inl_defd_bt2_has 1
#define mk_lang_bui_divmod_inl_defd_bt3_has 1
#elif \
	defined mk_lang_bui_divmod_btn && \
	defined mk_lang_bui_divmod_bt && \
	defined mk_lang_bui_divmod_bt2 && \
	defined mk_lang_bui_divmod_lena && \
	defined mk_lang_bui_divmod_lenb && \
	defined mk_lang_bui_divmod_endian && \
	defined mk_lang_bui_divmod_alg && \
	defined mk_lang_bui_divmod_name && \
	1
#define mk_lang_bui_divmod_inl_defd_btn mk_lang_bui_divmod_btn
#define mk_lang_bui_divmod_inl_defd_bt mk_lang_bui_divmod_bt
#define mk_lang_bui_divmod_inl_defd_bt2 mk_lang_bui_divmod_bt2
#define mk_lang_bui_divmod_inl_defd_lena mk_lang_bui_divmod_lena
#define mk_lang_bui_divmod_inl_defd_lenb mk_lang_bui_divmod_lenb
#define mk_lang_bui_divmod_inl_defd_endian mk_lang_bui_divmod_endian
#define mk_lang_bui_divmod_inl_defd_alg mk_lang_bui_divmod_alg
#define mk_lang_bui_divmod_inl_defd_name mk_lang_bui_divmod_name
#define mk_lang_bui_divmod_inl_defd_bt2_has 1
#define mk_lang_bui_divmod_inl_defd_bt3_has 0
#else
#define mk_lang_bui_divmod_inl_defd_btn mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)
#define mk_lang_bui_divmod_inl_defd_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)), _t)
#define mk_lang_bui_divmod_inl_defd_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)), _t)
#define mk_lang_bui_divmod_inl_defd_bt3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)), _t)
#define mk_lang_bui_divmod_inl_defd_lena mk_lang_concat(mk_lang_bui_divmod_for_count, _n)
#define mk_lang_bui_divmod_inl_defd_lenb mk_lang_concat(mk_lang_bui_divmod_for_count2, _n)
#define mk_lang_bui_divmod_inl_defd_endian mk_lang_concat(mk_lang_bui_divmod_for_endian, _value)
#define mk_lang_bui_divmod_inl_defd_alg mk_lang_concat(mk_lang_bui_divmod_for_divalg, _id)
#define mk_lang_bui_divmod_inl_defd_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn), _), mk_lang_concat(mk_lang_bui_divmod_for_count, _n)), _), mk_lang_concat(mk_lang_bui_divmod_for_count2, _n)), _), mk_lang_concat(mk_lang_bui_divmod_for_endian, _name)), _), mk_lang_concat(mk_lang_bui_divmod_for_divalg, _id))
#define mk_lang_bui_divmod_inl_defd_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)), _has)
#define mk_lang_bui_divmod_inl_defd_bt3_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_concat(mk_lang_bui_divmod_for_bui, _tn)), _has)
#endif

#define mk_lang_bui_divmod_inl_defd_lenc mk_lang_bui_divmod_inl_defd_lena
#define mk_lang_bui_divmod_inl_defd_lend mk_lang_min(mk_lang_bui_divmod_inl_defd_lena, mk_lang_bui_divmod_inl_defd_lenb)
#define mk_lang_bui_divmod_inl_defd_fn_overlap mk_lang_concat(mk_lang_overlap_, mk_lang_bui_divmod_inl_defd_btn)
#define mk_lang_bui_divmod_inl_defd_fn_simple_lena mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_lena)
#define mk_lang_bui_divmod_inl_defd_fn_simple_lenb mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_lenb)
#define mk_lang_bui_divmod_inl_defd_fn_simple_1_1 mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_1_1)
#define mk_lang_bui_divmod_inl_defd_fn_simple_0 mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_0)
#define mk_lang_bui_divmod_inl_defd_fn_simple_bigger mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_bigger)
#define mk_lang_bui_divmod_inl_defd_fn_simple_x_1 mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_x_1)
#define mk_lang_bui_divmod_inl_defd_fn_simple_n_1 mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_n_1)
#define mk_lang_bui_divmod_inl_defd_fn_complex_n_n mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _complex_n_n)
#define mk_lang_bui_divmod_inl_defd_fn_simple_n_n mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name), _simple_n_n)
#define mk_lang_bui_divmod_inl_defd_fn mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name)

#if mk_lang_bui_divmod_inl_defd_endian == mk_lang_endian_little
#define mk_lang_bui_divmod_inl_defd_endian_idxa(x) (x)
#define mk_lang_bui_divmod_inl_defd_endian_idxb(x) (x)
#define mk_lang_bui_divmod_inl_defd_endian_idxc(x) (x)
#define mk_lang_bui_divmod_inl_defd_endian_idxd(x) (x)
#elif mk_lang_bui_divmod_inl_defd_endian == mk_lang_endian_big
#define mk_lang_bui_divmod_inl_defd_endian_idxa(x) ((mk_lang_bui_divmod_inl_defd_lena - 1) - (x))
#define mk_lang_bui_divmod_inl_defd_endian_idxb(x) ((mk_lang_bui_divmod_inl_defd_lenb - 1) - (x))
#define mk_lang_bui_divmod_inl_defd_endian_idxc(x) ((mk_lang_bui_divmod_inl_defd_lenc - 1) - (x))
#define mk_lang_bui_divmod_inl_defd_endian_idxd(x) ((mk_lang_bui_divmod_inl_defd_lend - 1) - (x))
#endif

#if mk_lang_bui_divmod_inl_defd_lena == 1 && mk_lang_bui_divmod_inl_defd_lenb == 1
#define mk_lang_bui_divmod_inl_defd_valid 1
#elif mk_lang_bui_divmod_inl_defd_alg == 2 && mk_lang_bui_divmod_inl_defd_bt2_has == 1
#define mk_lang_bui_divmod_inl_defd_valid 1
#elif mk_lang_bui_divmod_inl_defd_alg == 3 && mk_lang_bui_divmod_inl_defd_bt3_has == 1
#define mk_lang_bui_divmod_inl_defd_valid 1
#else
#define mk_lang_bui_divmod_inl_defd_valid 0
#endif
