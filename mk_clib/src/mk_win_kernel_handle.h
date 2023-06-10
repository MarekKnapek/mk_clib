#ifndef mk_include_guard_mk_win_kernel_handle
#define mk_include_guard_mk_win_kernel_handle


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_handle_close_handle(mk_win_base_handle_t const handle) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_handle.c"
#endif
#endif
