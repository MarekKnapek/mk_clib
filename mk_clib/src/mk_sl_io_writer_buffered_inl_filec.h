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


#include "mk_sl_io_writer_buffered_inl_defd.h"


#define mk_sl_io_writer_buffered_inl_filec_name mk_lang_concat(mk_sl_io_writer_buffered_inl_defd_name, _memcpyu8)
#define mk_lang_memcpy_t_name mk_sl_io_writer_buffered_inl_filec_name
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_sl_io_writer_buffered_inl_filec_memcpyu8 mk_lang_concat(mk_sl_io_writer_buffered_inl_filec_name, _fn)


#define mk_sl_io_writer_buffered_inl_filec_is_valid(x) \
	( \
		(x)->m_buf && \
		(x)->m_buf_len > 0 && \
		(x)->m_cursor >= 0 && \
		(x)->m_cursor <= (x)->m_buf_len && \
		mk_lang_true \
	)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_buffered_inl_defd_init(mk_sl_io_writer_buffered_inl_defd_pt const writer, mk_sl_io_writer_buffered_inl_defd_base_pt const base, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const buf_len) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(base);
	mk_lang_assert(buf);
	mk_lang_assert(buf_len);

	writer->m_base = base;
	writer->m_buf = buf;
	writer->m_buf_len = buf_len;
	writer->m_cursor = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_buffered_inl_defd_write(mk_sl_io_writer_buffered_inl_defd_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct bf;
	mk_lang_types_usize_t rem;
	mk_lang_types_usize_t free;
	mk_lang_types_usize_t amount;
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t w;

	mk_lang_assert(writer);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(written);
	mk_lang_assert(mk_sl_io_writer_buffered_inl_filec_is_valid(writer));

	bf = buf;
	rem = len;
	do
	{
		free = writer->m_buf_len - writer->m_cursor;
		amount = mk_lang_min(rem, free);
		mk_sl_io_writer_buffered_inl_filec_memcpyu8(&writer->m_buf[writer->m_cursor], &bf[0], amount);
		bf += amount; rem -= amount;
		writer->m_cursor += amount;
		if(writer->m_cursor == writer->m_buf_len)
		{
			err = mk_sl_io_writer_buffered_inl_defd_base_write(writer->m_base, &writer->m_buf[0], writer->m_buf_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == writer->m_buf_len);
			writer->m_cursor = 0;
		}
	}while(rem != 0);
	*written = len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_buffered_inl_defd_flush(mk_sl_io_writer_buffered_inl_defd_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t w;

	mk_lang_assert(writer);
	mk_lang_assert(mk_sl_io_writer_buffered_inl_filec_is_valid(writer));

	if(writer->m_cursor != 0)
	{
		err = mk_sl_io_writer_buffered_inl_defd_base_write(writer->m_base, &writer->m_buf[0], writer->m_cursor, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == writer->m_cursor);
	}
	return 0;
}


#undef mk_sl_io_writer_buffered_inl_filec_name
#undef mk_sl_io_writer_buffered_inl_filec_memcpyu8
#undef mk_sl_io_writer_buffered_inl_filec_is_valid


#include "mk_sl_io_writer_buffered_inl_defu.h"


#undef mk_sl_io_writer_buffered_t_name
#undef mk_sl_io_writer_buffered_t_base
