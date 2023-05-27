#ifndef include_guard_mk_win_kernel_synchronization
#define include_guard_mk_win_kernel_synchronization


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_a_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_w_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_t_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_synchronization.c"
#endif
#endif
