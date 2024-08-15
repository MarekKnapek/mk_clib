#ifndef mk_include_guard_mk_win_api_ms_win_core_synch_l1_2_0
#define mk_include_guard_mk_win_api_ms_win_core_synch_l1_2_0


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_api_ms_win_core_synch_l1_2_0_wait_on_address(mk_win_base_void_pvt const address, mk_win_base_void_pt const compare_address, mk_win_base_usize_t const address_size, mk_win_base_dword_t const milliseconds) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_api_ms_win_core_synch_l1_2_0_wake_by_address_single(mk_win_base_void_pt const address) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_api_ms_win_core_synch_l1_2_0_wake_by_address_all(mk_win_base_void_pt const address) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_api_ms_win_core_synch_l1_2_0.c"
#endif
#endif
