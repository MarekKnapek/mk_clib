#ifndef mk_include_guard_mk_lang_bitness
#define mk_include_guard_mk_lang_bitness


#include "mk_lang_arch.h"


#define mk_lang_bitness_16 2001
#define mk_lang_bitness_32 2002
#define mk_lang_bitness_64 2003

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_lang_bitness mk_lang_bitness_16
#elif mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_alpha || mk_lang_arch == mk_lang_arch_ppc || mk_lang_arch == mk_lang_arch_mips || mk_lang_arch == mk_lang_arch_arm32 || mk_lang_arch == mk_lang_arch_emscripten
#define mk_lang_bitness mk_lang_bitness_32
#elif mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_arm64 || mk_lang_arch == mk_lang_arch_arm64ec
#define mk_lang_bitness mk_lang_bitness_64
#else
#error xxxxxxxxxx
#endif


#endif
