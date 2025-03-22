#ifndef mk_include_guard_mk_lang_crash_h
#define mk_include_guard_mk_lang_crash_h


#if defined mk_lang_crash_detail_want && (mk_lang_crash_detail_want) == 1
#define mk_lang_crash_detail_have 1
#elif defined mk_lang_crash_detail_want && (mk_lang_crash_detail_want) == 0
#define mk_lang_crash_detail_have 0
#elif !defined mk_lang_crash_detail_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_crash_detail_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_crash_detail_have 0
#else
#define mk_lang_crash_detail_have 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_types.h"


#if mk_lang_crash_detail_have


#include "mk_lang_runtime_bool.h"
#include "mk_lang_stringify.h"

mk_lang_noreturn mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_impl(mk_lang_types_pchar_pct const msg) mk_lang_noexcept;

#define mk_lang_crash() do{ if(mk_lang_runtime_bool_fn_true){ mk_lang_crash_impl("crash--->" __FILE__ ":" mk_lang_stringify(__LINE__) "<---crash"); } }while(mk_lang_runtime_bool_fn_false)


#else


mk_lang_noreturn mk_lang_jumbo mk_lang_types_void_t mk_lang_crash(mk_lang_types_void_t) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have == 1
#include "mk_lang_crash.c"
#endif
#endif
