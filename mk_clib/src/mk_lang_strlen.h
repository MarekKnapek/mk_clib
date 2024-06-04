#ifndef mk_include_guard_mk_lang_strlen
#define mk_include_guard_mk_lang_strlen


#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"


#define mk_lang_strlen_t_name mk_lang_strlen_n
#define mk_lang_strlen_t_type mk_lang_types_pchar_t
#include "mk_lang_strlen_inl_fileh.h"
#undef mk_lang_strlen_t_name
#undef mk_lang_strlen_t_type

#define mk_lang_strlen_t_name mk_lang_strlen_w
#define mk_lang_strlen_t_type mk_lang_types_wchar_t
#include "mk_lang_strlen_inl_fileh.h"
#undef mk_lang_strlen_t_name
#undef mk_lang_strlen_t_type


#if mk_lang_jumbo_want == 1
#include "mk_lang_strlen.c"
#endif
#endif
