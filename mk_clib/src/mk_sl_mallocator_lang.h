#ifndef mk_include_guard_sl_mallocator_lang
#define mk_include_guard_sl_mallocator_lang


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void* mk_sl_mallocator_lang_allocate(mk_lang_size_t const bytes_count) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_lang_deallocate(void const* const ptr) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocator_lang.c"
#endif
#endif
