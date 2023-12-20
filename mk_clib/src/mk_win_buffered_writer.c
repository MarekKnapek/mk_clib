#include "mk_win_buffered_writer.h"

#include "mk_lang_assert.h"
#include "mk_lang_min.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"

#define mk_lang_memcpy_t_name mk_win_buffered_writer_memcpy
#define mk_lang_memcpy_t_base mk_lang_types_uchar
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_ro_destroy(mk_win_buffered_writer_pct const bw) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;

	mk_lang_assert(bw);

	if(bw->m_pos != 0)
	{
		b = mk_win_kernel_files_write_file(bw->m_file, ((mk_lang_types_uchar_pct)(bw->m_buffer)) + 0, bw->m_pos, &nwritten, mk_win_base_null); mk_lang_check_return(b != 0 && nwritten == bw->m_pos);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_destroy(mk_win_buffered_writer_pt const bw) mk_lang_noexcept
{
	return mk_win_buffered_writer_ro_destroy(bw);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_construct(mk_win_buffered_writer_pt const bw, mk_win_base_handle_t const file, mk_win_base_void_pt const buffer, mk_win_base_usize_t const len) mk_lang_noexcept
{
	mk_lang_assert(bw);
	mk_lang_assert(file.m_data != mk_win_base_handle_invalid);
	mk_lang_assert(buffer);
	mk_lang_assert(len > 0 && len % 1024 == 0);

	bw->m_file = file;
	bw->m_buffer = buffer;
	bw->m_len = len;
	bw->m_pos = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_write(mk_win_buffered_writer_pt const bw, mk_win_base_void_pct const buff, mk_win_base_usize_t const len) mk_lang_noexcept
{
	mk_win_base_usize_t rem;
	mk_win_base_usize_t to_copy;
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;

	mk_lang_assert(bw);
	mk_lang_assert(buff || len == 0);
	mk_lang_assert(len >= 0);

	if(!(bw->m_pos == 0 && len >= bw->m_len))
	{
		rem = bw->m_len - bw->m_pos;
		to_copy = mk_lang_min(rem, len);
		mk_win_buffered_writer_memcpy_fn(((mk_lang_types_uchar_pt)(bw->m_buffer)) + bw->m_pos, ((mk_lang_types_uchar_pct)(buff)), to_copy);
		rem = len - to_copy;
		if(rem != 0)
		{
			b = mk_win_kernel_files_write_file(bw->m_file, bw->m_buffer, bw->m_len, &nwritten, mk_win_base_null); mk_lang_check_return(b != 0 && nwritten == bw->m_len);
			if(!(len >= bw->m_len))
			{
				mk_win_buffered_writer_memcpy_fn(((mk_lang_types_uchar_pt)(bw->m_buffer)) + 0, ((mk_lang_types_uchar_pct)(buff)) + to_copy, rem);
				bw->m_pos = rem;
			}
			else
			{
				b = mk_win_kernel_files_write_file(bw->m_file, ((mk_lang_types_uchar_pct)(buff)) + to_copy, rem, &nwritten, mk_win_base_null); mk_lang_check_return(b != 0 && nwritten == rem);
				bw->m_pos = 0;
			}
		}
		else
		{
			bw->m_pos += to_copy;
		}
	}
	else
	{
		b = mk_win_kernel_files_write_file(bw->m_file, buff, len, &nwritten, mk_win_base_null); mk_lang_check_return(b != 0 && nwritten == len);
	}
	return 0;
}
