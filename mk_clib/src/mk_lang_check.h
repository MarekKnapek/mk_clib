#ifndef mk_include_guard_mk_lang_check_h
#define mk_include_guard_mk_lang_check_h


#include "mk_lang_constexpr.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if defined mk_lang_check_rethrow_debug_want && (mk_lang_check_rethrow_debug_want) == 1
#define mk_lang_check_rethrow_debug_have 1
#elif defined mk_lang_check_rethrow_debug_want && (mk_lang_check_rethrow_debug_want) == 0
#define mk_lang_check_rethrow_debug_have 0
#elif !defined mk_lang_check_rethrow_debug_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_check_rethrow_debug_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_check_rethrow_debug_have 0
#else
#define mk_lang_check_rethrow_debug_have 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_lang_check_debug_want && (mk_lang_check_debug_want) == 1
#define mk_lang_check_debug_have 1
#elif defined mk_lang_check_debug_want && (mk_lang_check_debug_want) == 0
#define mk_lang_check_debug_have 0
#elif !defined mk_lang_check_debug_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_check_debug_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_check_debug_have 0
#else
#define mk_lang_check_debug_have 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_lang_check_extra_want && (mk_lang_check_extra_want) == 1
#define mk_lang_check_extra_have 1
#elif defined mk_lang_check_extra_want && (mk_lang_check_extra_want) == 0
#define mk_lang_check_extra_have 0
#elif !defined mk_lang_check_extra_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_check_extra_have 0
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_check_extra_have 0
#else
#define mk_lang_check_extra_have 0
#endif
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_lang_check_likely_want && (mk_lang_check_likely_want) == 1
#define mk_lang_check_likely_have 1
#elif defined mk_lang_check_likely_want && (mk_lang_check_likely_want) == 0
#define mk_lang_check_likely_have 0
#elif !defined mk_lang_check_likely_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_check_likely_have 0
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_check_likely_have 0
#else
#define mk_lang_check_likely_have 0
#endif
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_lang_check_rethrow_debug_have == 0
#define mk_lang_check_debug_break_rethrow_impl()
#elif mk_lang_check_rethrow_debug_have == 1
#include "mk_lang_debug_break.h"
#define mk_lang_check_debug_break_rethrow_impl() mk_lang_debug_break()
#else
#error xxxxxxxxxx
#endif

#if mk_lang_check_debug_have == 0
#define mk_lang_check_line 1
#define mk_lang_check_debug_break()
#define mk_lang_check_debug_break_rethrow()
#elif mk_lang_check_debug_have == 1
#include "mk_lang_debug_break.h"
#define mk_lang_check_line ((mk_lang_types_sint_t)(__LINE__))
#define mk_lang_check_debug_break() mk_lang_debug_break()
#define mk_lang_check_debug_break_rethrow() mk_lang_check_debug_break_rethrow_impl()
#else
#error xxxxxxxxxx
#endif

#if mk_lang_check_extra_have == 1
#define mk_lang_check_to_bool(x) mk_lang_check_to_bool_impl(!!(x))
#elif mk_lang_check_extra_have == 0
#define mk_lang_check_to_bool(x) (!!(x))
#else
#error xxxxxxxxxx
#endif

#if mk_lang_check_likely_have == 1
#include "mk_lang_likely.h"
#define mk_lang_check_attr_likely mk_lang_likely
#define mk_lang_check_attr_unlikely mk_lang_unlikely
#elif mk_lang_check_likely_have == 0
#define mk_lang_check_attr_likely
#define mk_lang_check_attr_unlikely
#else
#error xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_check_to_bool_impl(mk_lang_types_bool_t const b) mk_lang_noexcept;


#define mk_lang_check_return(x)     do{ if(!mk_lang_check_to_bool(x)){ mk_lang_check_attr_unlikely mk_lang_check_debug_break(); return mk_lang_check_line; } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_break(x)      do{ if(!mk_lang_check_to_bool(x)){ mk_lang_check_attr_unlikely mk_lang_check_debug_break(); break;                     } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_goto_exret(x) do{ if(!mk_lang_check_to_bool(x)){ mk_lang_check_attr_unlikely mk_lang_check_debug_break(); goto exret;                } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_crash(x)      do{ if(!mk_lang_check_to_bool(x)){ mk_lang_check_attr_unlikely mk_lang_check_debug_break(); mk_lang_crash();           } }while(mk_lang_runtime_bool_fn_false)

#define mk_lang_check_rereturn(x)     do{ mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_check_attr_unlikely mk_lang_check_debug_break_rethrow(); return err_private;            } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_rebreak(x)      do{ mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_check_attr_unlikely mk_lang_check_debug_break_rethrow(); break;                         } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_regoto_exret(x) do{ mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_check_attr_unlikely mk_lang_check_debug_break_rethrow(); (x) = err_private; goto exret; } }while(mk_lang_runtime_bool_fn_false)
#define mk_lang_check_recrash(x)      do{ mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_check_attr_unlikely mk_lang_check_debug_break_rethrow(); mk_lang_crash();               } }while(mk_lang_runtime_bool_fn_false)

#define mk_lang_check_todo() do{ mk_lang_check_return(mk_lang_runtime_bool_fn_false); }while(mk_lang_runtime_bool_fn_false)


#if mk_lang_jumbo_have == 1
#include "mk_lang_check.c"
#endif
#endif
