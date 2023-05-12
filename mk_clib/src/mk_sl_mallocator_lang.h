#ifndef include_guard_mk_sl_mallocator_lang
#define include_guard_mk_sl_mallocator_lang


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void mk_sl_mallocator_lang_init(void) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_lang_deinit(void) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_lang_allocate(mk_lang_exception_t* const ex, mk_lang_size_t const size_bytes, void** const mem) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_lang_deallocate(void const* const mem, mk_lang_size_t const size_bytes) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_lang_reallocate(mk_lang_exception_t* const ex, void const* const old_mem, mk_lang_size_t const old_size_bytes, mk_lang_size_t const new_size_bytes, void** const new_mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocator_lang.c"
#endif
#endif
