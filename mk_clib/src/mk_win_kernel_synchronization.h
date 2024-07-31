#ifndef mk_include_guard_mk_win_kernel_synchronization
#define mk_include_guard_mk_win_kernel_synchronization


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_one(mk_win_base_handle_t const object, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_kernel_synchronization_interlocked_increment(mk_win_base_slong_lpt const addend) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_kernel_synchronization_interlocked_decrement(mk_win_base_slong_lpt const addend) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_kernel_synchronization_interlocked_exchange(mk_win_base_slong_lpt const target, mk_win_base_slong_t const value) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_synchronization.c"
#endif
#endif
