#ifndef mk_include_guard_mk_lang_check
#define mk_include_guard_mk_lang_check


#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_check_to_bool_impl(mk_lang_types_bool_t const b) mk_lang_noexcept;


#if defined NDEBUG
#define mk_lang_check_line 1
#define mk_lang_check_debug_break()
#else
#define mk_lang_check_line ((mk_lang_types_sint_t)(__LINE__))
#define mk_lang_check_debug_break() __debugbreak()
#endif


#if defined mk_lang_check_extra && mk_lang_check_extra == 1
#define mk_lang_check_to_bool(x) mk_lang_check_to_bool_impl(!!(x))
#else
#define mk_lang_check_to_bool(x) (!!(x))
#endif


#define mk_lang_check_return(x) do{ if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); return mk_lang_check_line; } }while(0)
#define mk_lang_check_break(x) { if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); break; } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_goto_exret(x) do{ if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); goto exret; } }while(0)
#define mk_lang_check_crash(x) do{ if(!mk_lang_check_to_bool(x)){ mk_lang_unlikely mk_lang_check_debug_break(); mk_lang_crash(); } }while(0)
#define mk_lang_check_rereturn(x) do{ mk_lang_types_sint_t err_; err_ = ((mk_lang_types_sint_t)(x)); if(err_ != 0){ mk_lang_unlikely return err_; } }while(0)
#define mk_lang_check_rebreak(x) { mk_lang_types_sint_t err_; err_ = ((mk_lang_types_sint_t)(x)); if(err_ != 0){ mk_lang_unlikely break; } } ((mk_lang_types_void_t)(0))
#define mk_lang_check_regoto_exret(x) do{ mk_lang_types_sint_t err_; err_ = ((mk_lang_types_sint_t)(x)); if(err_ != 0){ mk_lang_unlikely ret = err_; goto exret; } }while(0)


#if mk_lang_jumbo_want == 1
#include "mk_lang_check.c"
#endif
#endif
