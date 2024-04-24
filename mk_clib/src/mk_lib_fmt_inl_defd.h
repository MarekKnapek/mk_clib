#include "mk_lang_concat.h"
#include "mk_lang_types.h"


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
#elif mk_lib_fmt_inl_defd_wide == 1
#define mk_lib_fmt_inl_defd_base mk_lang_types_wchar
#define mk_lib_fmt_inl_defd_char_c(x) L ## x
#else
#error xxxxxxxxxx
#endif

#define mk_lib_fmt_inl_defd_char_t mk_lang_concat(mk_lib_fmt_inl_defd_base, _t)
#define mk_lib_fmt_inl_defd_char_pt mk_lang_concat(mk_lib_fmt_inl_defd_base, _pt)
#define mk_lib_fmt_inl_defd_char_pct mk_lang_concat(mk_lib_fmt_inl_defd_base, _pct)

#define mk_lib_fmt_inl_defd_fn_vsnprintf mk_lang_concat(mk_lib_fmt_inl_defd_name, _vsnprintf)
#define mk_lib_fmt_inl_defd_fn_snprintf mk_lang_concat(mk_lib_fmt_inl_defd_name, _snprintf)
