#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_concat.h"
#include "mk_lang_min.h"


#if \
defined mk_lang_bui_divmod_bt && \
defined mk_lang_bui_divmod_bt2 && \
defined mk_lang_bui_divmod_bt3 && \
defined mk_lang_bui_divmod_lena && \
defined mk_lang_bui_divmod_lenb && \
defined mk_lang_bui_divmod_endian && \
defined mk_lang_bui_divmod_alg && \
defined mk_lang_bui_divmod_name
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
#else
#define mk_lang_bui_divmod_inl_defd_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_inl_defd_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_inl_defd_bt3 mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_fora_bui_tn), _t)
#define mk_lang_bui_divmod_inl_defd_lena mk_lang_fora_count_n
#define mk_lang_bui_divmod_inl_defd_lenb mk_lang_fora_count2_n
#define mk_lang_bui_divmod_inl_defd_endian mk_lang_fora_endian_value
#define mk_lang_bui_divmod_inl_defd_alg mk_lang_fora_divalg_id
#define mk_lang_bui_divmod_inl_defd_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_fora_bui_tn, _), mk_lang_fora_count_n), _), mk_lang_fora_count2_n), _), mk_lang_fora_endian_name), _), mk_lang_fora_divalg_id)
#define mk_lang_bui_divmod_inl_defd_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to2_, mk_lang_fora_bui_tn), _has)
#define mk_lang_bui_divmod_inl_defd_bt3_has mk_lang_concat(mk_lang_concat(mk_lang_bui_to3_, mk_lang_fora_bui_tn), _has)
#endif

#define mk_lang_bui_divmod_inl_defd_fn mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_inl_defd_name)
#define mk_lang_bui_divmod_inl_defd_lenc mk_lang_bui_divmod_inl_defd_lena
#define mk_lang_bui_divmod_inl_defd_lend mk_lang_min(mk_lang_bui_divmod_inl_defd_lena, mk_lang_bui_divmod_inl_defd_lenb)

#if mk_lang_bui_divmod_inl_defd_endian == mk_lang_endian_little
#define mk_lang_bui_divmod_inl_defd_endian_idxa(x) (x)
#define mk_lang_bui_divmod_inl_defd_endian_idxb(x) (x)
#define mk_lang_bui_divmod_inl_defd_endian_idxc(x) (mk_lang_bui_divmod_inl_defd_endian_idxa(x))
#define mk_lang_bui_divmod_inl_defd_endian_idxd(x) (x)
#elif mk_lang_bui_divmod_inl_defd_endian == mk_lang_endian_big
#define mk_lang_bui_divmod_inl_defd_endian_idxa(x) ((mk_lang_bui_divmod_inl_defd_lena - 1) - (x))
#define mk_lang_bui_divmod_inl_defd_endian_idxb(x) ((mk_lang_bui_divmod_inl_defd_lenb - 1) - (x))
#define mk_lang_bui_divmod_inl_defd_endian_idxc(x) (mk_lang_bui_divmod_inl_defd_endian_idxa(x))
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