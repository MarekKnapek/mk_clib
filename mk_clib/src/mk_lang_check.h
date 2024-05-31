#ifndef mk_include_guard_mk_lang_check
#define mk_include_guard_mk_lang_check


#include "mk_lang_builtin.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_check_to_bool_impl(mk_lang_types_bool_t const b) mk_lang_noexcept;


#if defined NDEBUG
#define mk_lang_check_line 1
#define mk_lang_check_debug_break()
#define mk_lang_check_debug_break_rethrow()
#else
#define mk_lang_check_line ((mk_lang_types_sint_t)(__LINE__))
#if mk_lang_msvc_ver >= 1200l /* vs6 */
#define mk_lang_check_debug_break() __debugbreak()
#elif mk_lang_builtin_has_debugtrap
#define mk_lang_check_debug_break() __builtin_debugtrap()
#elif mk_lang_builtin_has_trap
#define mk_lang_check_debug_break() __builtin_trap()
#else
#define mk_lang_check_debug_break()
#endif
#define mk_lang_check_debug_break_rethrow() /*mk_lang_check_debug_break()*/
#endif


#if defined mk_lang_check_extra && mk_lang_check_extra == 1
#define mk_lang_check_to_bool(x) mk_lang_check_to_bool_impl(!!(x))
#else
#define mk_lang_check_to_bool(x) (!!(x))
#endif


#define mk_lang_check_return(x)     { if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); return mk_lang_check_line; } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_break(x)      { if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); break;                     } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_goto_exret(x) { if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); goto exret;                } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_crash(x)      { if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); mk_lang_crash();           } } ((mk_lang_types_void_t)(0))

#define mk_lang_check_rereturn(x)     { mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_unlikely mk_lang_check_debug_break_rethrow(); return err_private;            } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_rebreak(x)      { mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_unlikely mk_lang_check_debug_break_rethrow(); break;                         } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_regoto_exret(x) { mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_unlikely mk_lang_check_debug_break_rethrow(); (x) = err_private; goto exret; } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_recrash(x)      { mk_lang_types_sint_t err_private mk_lang_constexpr_init; err_private = ((mk_lang_types_sint_t)(x)); if(err_private != 0){ mk_lang_unlikely mk_lang_check_debug_break_rethrow(); mk_lang_crash();               } } ((mk_lang_types_void_t)(0))


#if mk_lang_jumbo_want == 1
#include "mk_lang_check.c"
#endif
#endif
