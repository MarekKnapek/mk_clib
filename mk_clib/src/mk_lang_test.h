#ifndef mk_include_guard_mk_lang_test_h
#define mk_include_guard_mk_lang_test_h


#include "mk_lang_types.h"
#include "mk_lang_stringify.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_crash.h"
#include "mk_lang_countof.h"


#if defined mk_lang_test_detail_want && (mk_lang_test_detail_want) == 1
#define mk_lang_test_detail_have 1
#elif defined mk_lang_test_detail_want && (mk_lang_test_detail_want) == 0
#define mk_lang_test_detail_have 0
#elif !defined mk_lang_test_detail_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_test_detail_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_test_detail_have 1
#else
#define mk_lang_test_detail_have 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_lang_test_detail_have
mk_lang_jumbo mk_lang_types_void_t mk_lang_test_detail_impl(mk_lang_types_pchar_pct const msg_buf, mk_lang_types_sint_t const msg_len) mk_lang_noexcept;
#define mk_lang_test_detail_lit(x) x, mk_lang_countstr(x)
#define mk_lang_test_detail_print() mk_lang_test_detail_impl(mk_lang_test_detail_lit("fail--->" __FILE__ ":" mk_lang_stringify(__LINE__) "<---fail"))
#else
#define mk_lang_test_detail_print()
#endif


#define mk_lang_test(x) do{ if(!(x)){ mk_lang_test_detail_print(); mk_lang_debug_break(); mk_lang_crash(); } }while(mk_lang_runtime_bool_fn_false)


#if mk_lang_jumbo_have
#include "mk_lang_test.c"
#endif
#endif
