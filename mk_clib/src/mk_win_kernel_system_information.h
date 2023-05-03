#ifndef mk_include_guard_win_kernel_system_information
#define mk_include_guard_win_kernel_system_information


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_system_information_get_version(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_system_information.c"
#endif
#endif
