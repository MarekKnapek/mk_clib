#ifndef mk_include_guard_mk_win_comctl_base
#define mk_include_guard_mk_win_comctl_base


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_win_comctl_base_init(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_comctl_base.c"
#endif
#endif
