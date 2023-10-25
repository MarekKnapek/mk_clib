#ifndef mk_include_guard_mk_lang_sizet
#define mk_include_guard_mk_lang_sizet


#if defined __cplusplus
#include "mk_lang_intptrt.h"
#include <cstddef> /* std::size_t */
#define mk_lang_usize_t std::size_t
#define mk_lang_ssize_t mk_lang_sintptr_t
#else
#include "mk_lang_intptrt.h"
#include <stddef.h> /* size_t */
#define mk_lang_usize_t size_t
#define mk_lang_ssize_t mk_lang_sintptr_t
#endif


#endif
