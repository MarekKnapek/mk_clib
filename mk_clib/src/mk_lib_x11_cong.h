#ifndef mk_include_guard_mk_lib_x11_cong
#define mk_include_guard_mk_lib_x11_cong


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_x11_headers.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_display(Display** const display_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_value(mk_lang_types_sint_pt const screen_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_rootw(Window* const rootw_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_black(mk_lang_types_ulong_pt const black_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_white(mk_lang_types_ulong_pt const white_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_set_default_screen_black(mk_lang_types_ulong_t const black) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_set_default_screen_white(mk_lang_types_ulong_t const white) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_wmdelete(Atom* const wmdelete) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_x11_cong.c"
#endif
#endif
