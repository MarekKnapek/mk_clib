#ifndef include_guard_mk_win_gdi
#define include_guard_mk_win_gdi


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_jumbo int mk_win_gdi_a_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept;
mk_lang_jumbo int mk_win_gdi_w_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept;
mk_lang_jumbo int mk_win_gdi_t_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi.c"
#endif
#endif
