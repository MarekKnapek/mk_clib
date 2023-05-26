#ifndef include_guard_mk_sl_mem_istream
#define include_guard_mk_sl_mem_istream


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


struct mk_sl_mem_istream_s
{
	mk_lang_types_void_pct m_begin;
	mk_lang_types_void_pct m_end;
};
typedef struct mk_sl_mem_istream_s mk_sl_mem_istream_t;
typedef mk_sl_mem_istream_t const mk_sl_mem_istream_ct;
typedef mk_sl_mem_istream_t* mk_sl_mem_istream_pt;
typedef mk_sl_mem_istream_t const* mk_sl_mem_istream_pct;


mk_lang_jumbo void mk_sl_mem_istream_ro_destroy(mk_sl_mem_istream_pct const mem_istream) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_mem_istream_rw_destroy(mk_sl_mem_istream_pt const mem_istream) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_mem_istream_rw_construct_ptrs(mk_sl_mem_istream_pt const mem_istream, mk_lang_types_void_pct const begin, mk_lang_types_void_pct const end) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mem_istream_rw_construct_ptr_size(mk_sl_mem_istream_pt const mem_istream, mk_lang_types_void_pct const begin, mk_lang_types_usize_t const bytes_count) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mem_istream_rw_read(mk_sl_mem_istream_pt const mem_istream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const destination, mk_lang_types_usize_t const requested_bytes, mk_lang_types_usize_pt const read_bytes) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mem_istream.c"
#endif
#endif
