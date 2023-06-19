#ifndef mk_include_guard_mk_lang_arch
#define mk_include_guard_mk_lang_arch


#define mk_lang_arch_x8616      1001
#define mk_lang_arch_x8632      1002
#define mk_lang_arch_x8664      1003
#define mk_lang_arch_ia64       1004
#define mk_lang_arch_alpha      1005
#define mk_lang_arch_ppc        1006
#define mk_lang_arch_mips       1007
#define mk_lang_arch_arm32      1008
#define mk_lang_arch_arm64      1009
#define mk_lang_arch_emscripten 1010

#if defined __EMSCRIPTEN__
#define mk_lang_arch mk_lang_arch_emscripten
#elif defined _MSC_VER && defined _M_ARM64
#define mk_lang_arch mk_lang_arch_arm64
#elif defined _MSC_VER && defined _M_ARM
#define mk_lang_arch mk_lang_arch_arm32
#elif defined _MSC_VER && defined _M_MRX000
#define mk_lang_arch mk_lang_arch_mips
#elif defined _MSC_VER && (defined _M_PPC || defined _M_MPPC)
#define mk_lang_arch mk_lang_arch_ppc
#elif defined _MSC_VER && defined _M_ALPHA
#define mk_lang_arch mk_lang_arch_alpha
#elif defined _MSC_VER && defined _M_IA64
#define mk_lang_arch mk_lang_arch_ia64
#elif (defined _MSC_VER && (defined _M_X64 || defined _M_AMD64))
#define mk_lang_arch mk_lang_arch_x8664
#elif defined __amd64__
#define mk_lang_arch mk_lang_arch_x8664
#elif defined _MSC_VER && defined _M_IX86 && (!defined _M_I86 && !defined M_I86)
#define mk_lang_arch mk_lang_arch_x8632
#elif (defined __WATCOMC__ || defined __WATCOM_CPLUSPLUS__) && (defined __386__ || defined _M_I386 || defined M_I386)
#define mk_lang_arch mk_lang_arch_x8632
#elif defined __i386__
#define mk_lang_arch mk_lang_arch_x8632
#elif defined _MSC_VER && (defined _M_I86 || defined M_I86)
#define mk_lang_arch mk_lang_arch_x8616
#elif (defined __WATCOMC__ || defined __WATCOM_CPLUSPLUS__) && (defined __I86__ || defined _M_I86 || defined M_I86)
#define mk_lang_arch mk_lang_arch_x8616
#else
#define mk_lang_arch 0
#endif


#define mk_lang_bitness_16 2001
#define mk_lang_bitness_32 2002
#define mk_lang_bitness_64 2003

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_lang_bitness mk_lang_bitness_16
#elif mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_alpha || mk_lang_arch == mk_lang_arch_ppc || mk_lang_arch == mk_lang_arch_mips || mk_lang_arch == mk_lang_arch_arm32 || mk_lang_arch == mk_lang_arch_emscripten
#define mk_lang_bitness mk_lang_bitness_32
#elif mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_arm64
#define mk_lang_bitness mk_lang_bitness_64
#else
#define mk_lang_bitness 0
#endif


#endif
