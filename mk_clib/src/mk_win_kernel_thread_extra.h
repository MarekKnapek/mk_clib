#ifndef mk_include_guard_mk_win_kernel_thread_extra
#define mk_include_guard_mk_win_kernel_thread_extra


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_win_kernel_thread_extra_description_set(mk_win_base_handle_t const thread, mk_win_base_wchar_lpct const description, mk_win_base_hresult_pt const ret) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_thread_extra.c"
#endif
#endif
