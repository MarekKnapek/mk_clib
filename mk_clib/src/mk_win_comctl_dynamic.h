#ifndef mk_include_guard_mk_win_comctl_dynamic
#define mk_include_guard_mk_win_comctl_dynamic


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


mk_lang_jumbo mk_lang_types_void_t mk_win_comctl_dynamic_init(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_comctl_dynamic.c"
#endif
#endif
