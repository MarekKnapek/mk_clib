#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_sl_io_reader_buffered_inl_defd.h"


#define mk_sl_io_reader_buffered_inl_filec_name mk_lang_concat(mk_sl_io_reader_buffered_inl_defd_name, _memcpyu8)
#define mk_lang_memcpy_t_name mk_sl_io_reader_buffered_inl_filec_name
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_sl_io_reader_buffered_inl_filec_memcpyu8 mk_lang_concat(mk_sl_io_reader_buffered_inl_filec_name, _fn)


#define mk_sl_io_reader_buffered_inl_filec_is_valid(x) \
	( \
		(x)->m_buf && \
		(x)->m_buf_len > 0 && \
		(x)->m_cursor >= 0 && \
		(x)->m_cursor <= (x)->m_end && \
		(x)->m_end <= (x)->m_buf_len && \
		mk_lang_true \
	)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_init(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_sl_io_reader_buffered_inl_defd_base_pt const base, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const buf_len) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(base);
	mk_lang_assert(buf);
	mk_lang_assert(buf_len);

	reader->m_base = base;
	reader->m_buf = buf;
	reader->m_buf_len = buf_len;
	reader->m_cursor = 0;
	reader->m_end = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_read(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt bf;
	mk_lang_types_usize_t rem;
	mk_lang_types_usize_t avail;
	mk_lang_types_usize_t amount;
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t r;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_buffered_inl_filec_is_valid(reader));

	bf = buf;
	rem = len;
	do
	{
		avail = reader->m_end - reader->m_cursor;
		if(avail == 0)
		{
			err = mk_sl_io_reader_buffered_inl_defd_base_read(reader->m_base, &reader->m_buf[0], reader->m_buf_len, &r); mk_lang_check_rereturn(err); mk_lang_check_return(r >= mk_lang_min(rem, reader->m_buf_len));
			reader->m_cursor = 0;
			reader->m_end = r;
			avail = reader->m_end - reader->m_cursor;
		}
		amount = mk_lang_min(rem, avail);
		mk_sl_io_reader_buffered_inl_filec_memcpyu8(&bf[0], &reader->m_buf[reader->m_cursor], amount);
		bf += amount; rem -= amount;
		reader->m_cursor += amount;
	}while(rem != 0);
	*read = len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_seek_rel(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_buffered_inl_filec_is_valid(reader));

	if(offset > 0 && reader->m_cursor + offset <= reader->m_end)
	{
		/* reader->m_cursor += offset; */
		mk_lang_assert(mk_lang_false); /* todo */
	}
	else if(offset > 0)
	{
		err = mk_sl_io_reader_buffered_inl_defd_base_seek_rel(reader->m_base, offset - ((mk_lang_types_slong_t)(reader->m_end - reader->m_cursor))); mk_lang_check_rereturn(err);
		reader->m_cursor = 0;
		reader->m_end = 0;
	}
	else
	{
		mk_lang_assert(mk_lang_false); /* todo */
	}
	return 0;
}


#undef mk_sl_io_reader_buffered_inl_filec_name
#undef mk_sl_io_reader_buffered_inl_filec_memcpyu8
#undef mk_sl_io_reader_buffered_inl_filec_is_valid


#include "mk_sl_io_reader_buffered_inl_defu.h"


#undef mk_sl_io_reader_buffered_t_name
#undef mk_sl_io_reader_buffered_t_base
