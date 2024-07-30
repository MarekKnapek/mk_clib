#ifndef mk_include_guard_mk_win_user_region
#define mk_include_guard_mk_win_user_region


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


mk_win_base_make_handle(mk_win_user_region)


#if mk_lang_jumbo_want == 1
#include "mk_win_user_region.c"
#endif
#endif
