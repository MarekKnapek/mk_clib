#ifndef mk_include_guard_mk_lang_test_h
#define mk_include_guard_mk_lang_test_h


#include "mk_lang_configuration.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"


#if defined mk_lang_test_detail_want && (mk_lang_test_detail_want) == 1
#define mk_lang_test_detail_have 1
#elif defined mk_lang_test_detail_want && (mk_lang_test_detail_want) == 0
#define mk_lang_test_detail_have 0
#elif !defined mk_lang_test_detail_want
#if mk_lang_configuration_is_debug
#define mk_lang_test_detail_have 1
#elif mk_lang_configuration_is_release
#define mk_lang_test_detail_have 1
#else
#error xxxxxxxxxx
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_lang_test_detail_have
#include "mk_lang_countof.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
mk_lang_jumbo mk_lang_types_void_t mk_lang_test_detail_print_impl(mk_lang_types_pchar_pct const msg_buf, mk_lang_types_sint_t const msg_len) mk_lang_noexcept;
#define mk_lang_test_detail_lit(x) x, mk_lang_countstr(x)
#define mk_lang_test_detail_print(x) mk_lang_test_detail_print_impl(mk_lang_test_detail_lit("test_failed--->" __FILE__ ":" mk_lang_stringify(__LINE__) "`" mk_lang_stringify(x) "'<---test_failed"))
#define mk_lang_test_failed(x) ((mk_lang_types_void_t)(mk_lang_test_detail_print(x), mk_lang_debug_break(), mk_lang_crash()))
#else
#define mk_lang_test_failed(x) ((mk_lang_types_void_t)(mk_lang_crash()))
#endif


#define mk_lang_test(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(mk_lang_test_failed(x)))))


#if mk_lang_jumbo_have
#include "mk_lang_test.c"
#endif
#endif
