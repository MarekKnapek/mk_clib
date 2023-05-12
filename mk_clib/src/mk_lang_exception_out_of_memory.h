#ifndef include_guard_mk_lang_exception_out_of_memory
#define include_guard_mk_lang_exception_out_of_memory


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


struct mk_lang_exception_out_of_memory_s
{
	mk_lang_size_t m_requested_bytes;
};
typedef struct mk_lang_exception_out_of_memory_s mk_lang_exception_out_of_memory_t;
typedef mk_lang_exception_out_of_memory_t const mk_lang_exception_out_of_memory_ct;
typedef mk_lang_exception_out_of_memory_t* mk_lang_exception_out_of_memory_pt;
typedef mk_lang_exception_out_of_memory_t const* mk_lang_exception_out_of_memory_pct;


mk_lang_jumbo void mk_lang_exception_out_of_memory_make(mk_lang_exception_pt const ex, mk_lang_size_t const requested_bytes) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_exception_out_of_memory.c"
#endif
#endif
