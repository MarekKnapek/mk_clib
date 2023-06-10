#ifndef mk_include_guard_mk_lang_intmaxt
#define mk_include_guard_mk_lang_intmaxt


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_intmaxt_has 1
#include <cstdint> /* std::uintmax_t std::intmax_t */
#define mk_lang_uintmax_t std::uintmax_t
#define mk_lang_sintmax_t std::intmax_t
#elif mk_lang_version_at_least_c_99
#define mk_lang_intmaxt_has 1
#include <stdint.h> /* uintmax_t intmax_t */
#define mk_lang_uintmax_t uintmax_t
#define mk_lang_sintmax_t intmax_t
#else
#define mk_lang_intmaxt_has 0
#include "mk_lang_lllong.h"
#define mk_lang_uintmax_t mk_lang_ulllong_t
#define mk_lang_sintmax_t mk_lang_slllong_t
#endif


#endif
