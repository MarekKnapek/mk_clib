#ifndef mk_include_guard_mk_lang_debug_break_h
#define mk_include_guard_mk_lang_debug_break_h


#if defined mk_lang_debug_break_want && (mk_lang_debug_break_want) == 1
#define mk_lang_debug_break_want2 1
#elif defined mk_lang_debug_break_want && (mk_lang_debug_break_want) == 0
#define mk_lang_debug_break_want2 0
#elif !defined mk_lang_debug_break_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_debug_break_want2 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_debug_break_want2 0
#else
#define mk_lang_debug_break_want2 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_lang_debug_break_want2

#include "mk_lang_builtin.h"
#include "mk_lang_msvc.h"

#if mk_lang_msvc_ver >= mk_lang_msvc_ver_6

#pragma intrinsic(__debugbreak)
#define mk_lang_debug_break_have 1
#define mk_lang_debug_break() __debugbreak()

#elif mk_lang_builtin_has_debugtrap

#define mk_lang_debug_break_have 1
#define mk_lang_debug_break() __builtin_debugtrap()

#elif mk_lang_builtin_has_trap

#define mk_lang_debug_break_have 1
#define mk_lang_debug_break() __builtin_trap()

#else

#define mk_lang_debug_break_have 0
#define mk_lang_debug_break() ((mk_lang_types_void_t)(0))

#endif

#else

#define mk_lang_debug_break_have 0
#define mk_lang_debug_break() ((mk_lang_types_void_t)(0))

#endif


#endif
