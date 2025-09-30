#ifndef mk_include_guard_mk_lang_bitness_h
#define mk_include_guard_mk_lang_bitness_h


#include "mk_lang_arch.h"


#define mk_lang_bitness_16 1001
#define mk_lang_bitness_32 1002
#define mk_lang_bitness_64 1003


#if mk_lang_arch_is_x8616
#define mk_lang_bitness mk_lang_bitness_16
#elif mk_lang_arch_is_x8632 || mk_lang_arch_is_alpha || mk_lang_arch_is_ppc || mk_lang_arch_is_mips || mk_lang_arch_is_arm32 || mk_lang_arch_is_emscripten
#define mk_lang_bitness mk_lang_bitness_32
#elif mk_lang_arch_is_x8664 || mk_lang_arch_is_ia64 || mk_lang_arch_is_arm64 || mk_lang_arch_is_arm64ec
#define mk_lang_bitness mk_lang_bitness_64
#else
#error xxxxxxxxxx
#endif


#define mk_lang_bitness_is_16 (mk_lang_bitness == mk_lang_bitness_16)
#define mk_lang_bitness_is_32 (mk_lang_bitness == mk_lang_bitness_32)
#define mk_lang_bitness_is_64 (mk_lang_bitness == mk_lang_bitness_64)


#endif
