#ifndef mk_include_guard_mk_win_kernel_process
#define mk_include_guard_mk_win_kernel_process


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_process_get_current(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_process.c"
#endif
#endif
