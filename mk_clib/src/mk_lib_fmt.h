#ifndef mk_include_guard_mk_lib_fmt_h
#define mk_include_guard_mk_lib_fmt_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_tchar.h"


#define mk_lib_fmt_t_name mk_lib_fmt_n
#define mk_lib_fmt_t_wide 0
#include "mk_lib_fmt_inl_fileh.h"
#include "mk_lib_fmt_inl_fileu.h"

#define mk_lib_fmt_t_name mk_lib_fmt_w
#define mk_lib_fmt_t_wide 1
#include "mk_lib_fmt_inl_fileh.h"
#include "mk_lib_fmt_inl_fileu.h"


#define mk_lib_fmt_lit_and_len(x) (x), mk_lang_countstr((x))


#if mk_lang_tchar_wchar_have
#define mk_lib_fmt_t_snnprintf mk_lib_fmt_w_snnprintf
#else
#define mk_lib_fmt_t_snnprintf mk_lib_fmt_n_snnprintf
#endif


#if mk_lang_jumbo_have
#include "mk_lib_fmt.c"
#endif
#endif
