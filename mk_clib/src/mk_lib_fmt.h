#ifndef mk_include_guard_mk_lib_fmt
#define mk_include_guard_mk_lib_fmt


#include "mk_lang_jumbo.h"


#define mk_lib_fmt_t_name mk_lib_fmt_n
#define mk_lib_fmt_t_wide 0
#include "mk_lib_fmt_inl_fileh.h"
#undef mk_lib_fmt_t_name
#undef mk_lib_fmt_t_wide

#define mk_lib_fmt_t_name mk_lib_fmt_w
#define mk_lib_fmt_t_wide 1
#include "mk_lib_fmt_inl_fileh.h"
#undef mk_lib_fmt_t_name
#undef mk_lib_fmt_t_wide


#if mk_lang_jumbo_want == 1
#include "mk_lib_fmt.c"
#endif
#endif
