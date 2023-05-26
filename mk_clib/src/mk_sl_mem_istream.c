#include "mk_sl_mem_istream.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_mem_istream_ro_check(mk_sl_mem_istream_pct const mem_istream) mk_lang_noexcept;


mk_lang_jumbo void mk_sl_mem_istream_ro_destroy(mk_sl_mem_istream_pct const mem_istream) mk_lang_noexcept
{
	mk_lang_assert(mk_sl_mem_istream_ro_check(mem_istream));
}


mk_lang_jumbo void mk_sl_mem_istream_rw_destroy(mk_sl_mem_istream_pt const mem_istream) mk_lang_noexcept
{
	mk_sl_mem_istream_ro_destroy(mem_istream);
}


mk_lang_jumbo void mk_sl_mem_istream_rw_construct_ptrs(mk_sl_mem_istream_pt const mem_istream, mk_lang_types_void_pct const begin, mk_lang_types_void_pct const end) mk_lang_noexcept
{
	mk_lang_assert(mem_istream);
	mk_lang_assert(end >= begin);

	mem_istream->m_begin = begin;
	mem_istream->m_end = end;

	mk_lang_assert(mk_sl_mem_istream_ro_check(mem_istream));
}

mk_lang_jumbo void mk_sl_mem_istream_rw_construct_ptr_size(mk_sl_mem_istream_pt const mem_istream, mk_lang_types_void_pct const begin, mk_lang_types_usize_t const bytes_count) mk_lang_noexcept
{
	mk_lang_assert(mem_istream);

	mem_istream->m_begin = begin;
	mem_istream->m_end = ((mk_lang_types_void_pct)(((mk_lang_types_uchar_pct)(begin)) + bytes_count));

	mk_lang_assert(mk_sl_mem_istream_ro_check(mem_istream));
}

mk_lang_jumbo void mk_sl_mem_istream_rw_read(mk_sl_mem_istream_pt const mem_istream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const destination, mk_lang_types_usize_t const requested_bytes, mk_lang_types_usize_pt const read_bytes) mk_lang_noexcept
{
	mk_lang_types_usize_t max;
	mk_lang_types_usize_t real;

	mk_lang_assert(mk_sl_mem_istream_ro_check(mem_istream));
	mk_lang_assert(ex);

	max = ((mk_lang_types_usize_t)(((mk_lang_types_uinptr_t)(((mk_lang_types_uinptr_t)(mem_istream->m_end)) - ((mk_lang_types_uinptr_t)(mem_istream->m_begin))))));
	real = mk_lang_min(max, requested_bytes);
	mk_lang_memcpy(destination, mem_istream->m_begin, real);
	mem_istream->m_begin = ((mk_lang_types_void_pct)(((mk_lang_types_uchar_pct)(mem_istream->m_begin)) + real));
	*read_bytes = real;

	mk_lang_assert(mk_sl_mem_istream_ro_check(mem_istream));
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_mem_istream_ro_check(mk_sl_mem_istream_pct const mem_istream) mk_lang_noexcept
{
	return
		(mem_istream) &&
		(mem_istream->m_end >= mem_istream->m_begin)
	;
}
