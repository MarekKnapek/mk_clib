#ifndef mk_include_guard_mk_lang_builtin
#define mk_include_guard_mk_lang_builtin


#if defined __has_builtin
#if __has_builtin(__builtin_assume)
#define mk_lang_builtin_has_assume 1
#else
#define mk_lang_builtin_has_assume 0
#endif
#else
#define mk_lang_builtin_has_assume 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_unreachable)
#define mk_lang_builtin_has_unreachable 1
#else
#define mk_lang_builtin_has_unreachable 0
#endif
#else
#define mk_lang_builtin_has_unreachable 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_debugtrap)
#define mk_lang_builtin_has_debugtrap 1
#else
#define mk_lang_builtin_has_debugtrap 0
#endif
#else
#define mk_lang_builtin_has_debugtrap 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_trap)
#define mk_lang_builtin_has_trap 1
#else
#define mk_lang_builtin_has_trap 0
#endif
#else
#define mk_lang_builtin_has_trap 0
#endif


#endif
