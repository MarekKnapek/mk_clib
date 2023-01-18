#ifndef mk_include_guard_lang_intptrt
#define mk_include_guard_lang_intptrt


#if defined __cplusplus && __cplusplus >= 201103l
#include <cstdint> /* INTPTR_MIN INTPTR_MAX UINTPTR_MAX std::uintptr_t std::intptr_t */
#if defined INTPTR_MIN && defined INTPTR_MAX && defined UINTPTR_MAX
#define mk_lang_intptrt_has 1
#define mk_lang_uintptr_t std::uintptr_t
#define mk_lang_sintptr_t std::intptr_t
#else
#define mk_lang_intptrt_has 0
#endif
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
#include <stdint.h> /* INTPTR_MIN INTPTR_MAX UINTPTR_MAX uintptr_t intptr_t */
#if defined INTPTR_MIN && defined INTPTR_MAX && defined UINTPTR_MAX
#define mk_lang_intptrt_has 1
#define mk_lang_uintptr_t uintptr_t
#define mk_lang_sintptr_t intptr_t
#else
#define mk_lang_intptrt_has 0
#endif
#else
#define mk_lang_intptrt_has 0
#endif

#if mk_lang_intptrt_has == 0
#include "mk_lang_arch.h"
#if mk_lang_arch == mk_lang_arch_x8616
#define mk_lang_uintptr_t unsigned int
#define mk_lang_sintptr_t signed int
#elif mk_lang_arch == mk_lang_arch_x8632
#define mk_lang_uintptr_t unsigned long int
#define mk_lang_sintptr_t signed long int
#elif mk_lang_arch == mk_lang_arch_x8664
#include "mk_lang_llong.h"
#define mk_lang_uintptr_t mk_lang_ullong_t
#define mk_lang_sintptr_t mk_lang_sllong_t
#else
#include "mk_lang_lllong.h"
#define mk_lang_uintptr_t mk_lang_ulllong_t
#define mk_lang_sintptr_t mk_lang_slllong_t
#endif
#endif


#endif
