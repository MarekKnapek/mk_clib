#ifndef mk_include_guard_mk_lang_builtin_h
#define mk_include_guard_mk_lang_builtin_h


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

#if defined __has_builtin
#if __has_builtin(__builtin_addcb)
#define mk_lang_builtin_has_addcb 1
#else
#define mk_lang_builtin_has_addcb 0
#endif
#else
#define mk_lang_builtin_has_addcb 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_addcs)
#define mk_lang_builtin_has_addcs 1
#else
#define mk_lang_builtin_has_addcs 0
#endif
#else
#define mk_lang_builtin_has_addcs 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_addc)
#define mk_lang_builtin_has_addc 1
#else
#define mk_lang_builtin_has_addc 0
#endif
#else
#define mk_lang_builtin_has_addc 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_addcl)
#define mk_lang_builtin_has_addcl 1
#else
#define mk_lang_builtin_has_addcl 0
#endif
#else
#define mk_lang_builtin_has_addcl 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_addcll)
#define mk_lang_builtin_has_addcll 1
#else
#define mk_lang_builtin_has_addcll 0
#endif
#else
#define mk_lang_builtin_has_addcll 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_subcb)
#define mk_lang_builtin_has_subcb 1
#else
#define mk_lang_builtin_has_subcb 0
#endif
#else
#define mk_lang_builtin_has_subcb 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_subcs)
#define mk_lang_builtin_has_subcs 1
#else
#define mk_lang_builtin_has_subcs 0
#endif
#else
#define mk_lang_builtin_has_subcs 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_subc)
#define mk_lang_builtin_has_subc 1
#else
#define mk_lang_builtin_has_subc 0
#endif
#else
#define mk_lang_builtin_has_subc 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_subcl)
#define mk_lang_builtin_has_subcl 1
#else
#define mk_lang_builtin_has_subcl 0
#endif
#else
#define mk_lang_builtin_has_subcl 0
#endif

#if defined __has_builtin
#if __has_builtin(__builtin_subcll)
#define mk_lang_builtin_has_subcll 1
#else
#define mk_lang_builtin_has_subcll 0
#endif
#else
#define mk_lang_builtin_has_subcll 0
#endif


#endif
