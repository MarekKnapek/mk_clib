define(`mk_lang_builtin_mm_check', `dnl
#if defined __has_builtin
#if __has_builtin(__builtin_$1)
#define mk_lang_builtin_has_$1 1
#else
#define mk_lang_builtin_has_$1 0
#endif
#else
#define mk_lang_builtin_has_$1 0
#endif
')dnl`'
dnl
dnl
dnl
#ifndef mk_include_guard_mk_lang_builtin_h
#define mk_include_guard_mk_lang_builtin_h


mk_lang_builtin_mm_check(`addc')
mk_lang_builtin_mm_check(`addcb')
mk_lang_builtin_mm_check(`addcl')
mk_lang_builtin_mm_check(`addcll')
mk_lang_builtin_mm_check(`addcs')
mk_lang_builtin_mm_check(`assume')
mk_lang_builtin_mm_check(`debugtrap')
mk_lang_builtin_mm_check(`rotateleft16')
mk_lang_builtin_mm_check(`rotateleft32')
mk_lang_builtin_mm_check(`rotateleft64')
mk_lang_builtin_mm_check(`rotateleft8')
mk_lang_builtin_mm_check(`rotateright16')
mk_lang_builtin_mm_check(`rotateright32')
mk_lang_builtin_mm_check(`rotateright64')
mk_lang_builtin_mm_check(`rotateright8')
mk_lang_builtin_mm_check(`subc')
mk_lang_builtin_mm_check(`subcb')
mk_lang_builtin_mm_check(`subcl')
mk_lang_builtin_mm_check(`subcll')
mk_lang_builtin_mm_check(`subcs')
mk_lang_builtin_mm_check(`trap')
mk_lang_builtin_mm_check(`unreachable')

#endif
