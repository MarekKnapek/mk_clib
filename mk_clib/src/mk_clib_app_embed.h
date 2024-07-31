#ifndef mk_include_guard_mk_clib_app_embed
#define mk_include_guard_mk_clib_app_embed


#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_embed_arg(mk_lang_types_bool_t const wide, mk_win_base_instance_t const instance, mk_win_base_instance_t const prev, mk_win_base_wchar_lpct const cmd_line, mk_lang_types_sint_t const show) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_embed.c"
#endif
#endif
