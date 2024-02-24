#ifndef mk_include_guard_mk_win_kernel_synchronization
#define mk_include_guard_mk_win_kernel_synchronization


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"
#include "mk_win_tstring.h"


#define mk_win_kernel_synchronization_wait_object_0  0x00000000ul
#define mk_win_kernel_synchronization_wait_abandoned 0x00000080ul
#define mk_win_kernel_synchronization_wait_timeout   0x00000102ul
#define mk_win_kernel_synchronization_wait_failed    0xfffffffful

#define mk_win_kernel_synchronization_infinite 0xfffffffful


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_a_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_pchar_lpct const name) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_w_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_wchar_lpct const name) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_t_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_for_single_object(mk_win_base_handle_t const handle, mk_win_base_dword_t const timeout_ms) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_for_multiple_objects(mk_win_base_dword_t const count, mk_win_base_handle_lpct const handles, mk_win_base_bool_t const wait_all, mk_win_base_dword_t timeout_ms) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_get_overlapped_result(mk_win_base_handle_t const file, mk_win_kernel_files_overlapped_lpct const overlapped, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_bool_t const wait) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_reset_event(mk_win_base_handle_t const event) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_set_event(mk_win_base_handle_t const event) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_synchronization.c"
#endif
#endif
