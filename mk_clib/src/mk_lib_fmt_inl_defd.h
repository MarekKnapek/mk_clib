#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lib_fmt_t_name) && \
	(defined mk_lib_fmt_t_wide && ((mk_lib_fmt_t_wide) == 0 || (mk_lib_fmt_t_wide) == 1)) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_lib_fmt_inl_defd_name mk_lib_fmt_t_name
#define mk_lib_fmt_inl_defd_wide (mk_lib_fmt_t_wide)


#if mk_lib_fmt_inl_defd_wide == 0
#define mk_lib_fmt_inl_defd_base mk_lang_types_pchar
#define mk_lib_fmt_inl_defd_char_c(x) x
#define mk_sl_cui_uint32_to_str_hex_u mk_sl_cui_uint32_to_str_hex_n
#define mk_sl_cui_uint32_to_str_dec_u mk_sl_cui_uint32_to_str_dec_n
#define mk_sl_cui_uint64_to_str_hex_u mk_sl_cui_uint64_to_str_hex_n
#define mk_sl_cui_uint64_to_str_dec_u mk_sl_cui_uint64_to_str_dec_n
#elif mk_lib_fmt_inl_defd_wide == 1
#define mk_lib_fmt_inl_defd_base mk_lang_types_wchar
#define mk_lib_fmt_inl_defd_char_c(x) L ## x
#define mk_sl_cui_uint32_to_str_hex_u mk_sl_cui_uint32_to_str_hex_w
#define mk_sl_cui_uint32_to_str_dec_u mk_sl_cui_uint32_to_str_dec_w
#define mk_sl_cui_uint64_to_str_hex_u mk_sl_cui_uint64_to_str_hex_w
#define mk_sl_cui_uint64_to_str_dec_u mk_sl_cui_uint64_to_str_dec_w
#else
#error xxxxxxxxxx
#endif

#define mk_lib_fmt_inl_defd_char_t mk_lang_concat(mk_lib_fmt_inl_defd_base, _t)
#define mk_lib_fmt_inl_defd_char_pt mk_lang_concat(mk_lib_fmt_inl_defd_base, _pt)
#define mk_lib_fmt_inl_defd_char_pct mk_lang_concat(mk_lib_fmt_inl_defd_base, _pct)


#define mk_lib_fmt_inl_defd_vsnnprintf_s mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_s)
#define mk_lib_fmt_inl_defd_vsnnprintf_t mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_t)
#define mk_lib_fmt_inl_defd_vsnnprintf_n mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_n)
#define mk_lib_fmt_inl_defd_vsnnprintf_x mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_x)
#define mk_lib_fmt_inl_defd_vsnnprintf_u mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_u)
#define mk_lib_fmt_inl_defd_vsnnprintf_d mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_d)
#define mk_lib_fmt_inl_defd_vsnnprintf_ht mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_ht)
#define mk_lib_fmt_inl_defd_vsnnprintf_llx mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_llx)
#define mk_lib_fmt_inl_defd_vsnnprintf_llu mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_llu)
#define mk_lib_fmt_inl_defd_vsnnprintf_lld mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf_lld)
#define mk_lib_fmt_inl_defd_vsnnprintf mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnnprintf)


#define mk_lib_fmt_inl_defd_snnprintf mk_lang_concat(mk_lib_fmt_inl_defd_name, _snnprintf)
