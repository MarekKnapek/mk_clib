#ifndef mk_include_guard_lang_sizet
#define mk_include_guard_lang_sizet


#if defined __cplusplus
#include <cstddef> /* std::size_t */
#define mk_lang_size_t std::size_t
#else
#include <stddef.h> /* size_t */
#define mk_lang_size_t size_t
#endif


#endif
