#include "mk_sl_io_async_iocp_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_reader_file_windows.h"
#include "mk_sl_io_async_writer_file_windows.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_iocp.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_construct(mk_sl_io_async_iocp_windows_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept
{
	mk_win_base_handle_t wiocp;

	mk_lang_assert(iocp);
	mk_lang_assert(concurrency >= 0);

	wiocp = mk_win_kernel_iocp_create(mk_win_base_handle_invalid_g, mk_win_base_handle_null_g, 0, ((mk_win_base_dword_t)(concurrency))); mk_lang_check_return(wiocp.m_data);
	iocp->m_iocp = wiocp;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_associate_r(mk_sl_io_async_iocp_windows_pt const iocp, mk_sl_io_async_reader_file_windows_pt const reader, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_win_base_handle_t wiocp;

	mk_lang_assert(iocp);
	mk_lang_assert(iocp->m_iocp.m_data);
	mk_lang_assert(reader);
	mk_lang_assert(reader->m_file.m_data != mk_win_base_handle_invalid);

	wiocp = mk_win_kernel_iocp_create(reader->m_file, iocp->m_iocp, ((mk_win_base_usize_t)(key)), 0); mk_lang_check_return(wiocp.m_data == iocp->m_iocp.m_data);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_associate_w(mk_sl_io_async_iocp_windows_pt const iocp, mk_sl_io_async_writer_file_windows_pt const writer, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_win_base_handle_t wiocp;

	mk_lang_assert(iocp);
	mk_lang_assert(iocp->m_iocp.m_data);
	mk_lang_assert(writer);
	mk_lang_assert(writer->m_file.m_data != mk_win_base_handle_invalid);

	wiocp = mk_win_kernel_iocp_create(writer->m_file, iocp->m_iocp, ((mk_win_base_usize_t)(key)), 0); mk_lang_check_return(wiocp.m_data == iocp->m_iocp.m_data);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_peek(mk_sl_io_async_iocp_windows_pt const iocp, mk_sl_io_async_iocp_iorp_windows_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	iorp->m_b = mk_win_kernel_iocp_get_status(iocp->m_iocp, &iorp->m_transfered, &iorp->m_key, &iorp->m_iorp, 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_wait(mk_sl_io_async_iocp_windows_pt const iocp, mk_sl_io_async_iocp_iorp_windows_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	iorp->m_b = mk_win_kernel_iocp_get_status(iocp->m_iocp, &iorp->m_transfered, &iorp->m_key, &iorp->m_iorp, mk_win_base_infinite);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_windows_destroy(mk_sl_io_async_iocp_windows_pt const iocp) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(iocp);

	b = mk_win_kernel_handle_close_handle(iocp->m_iocp); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_has(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_lang_types_bool_pt const has) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(has);

	*has = !(iorp->m_b == mk_win_base_false && iorp->m_iorp == mk_win_base_null);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_failed(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_lang_types_bool_pt const failed) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(failed);

	*failed = iorp->m_b == mk_win_base_false && iorp->m_iorp != mk_win_base_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_key(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_lang_types_usize_pt const key) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(key);

	*key = iorp->m_key;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_transfered(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_lang_types_usize_pt const transfered) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(transfered);

	*transfered = ((mk_lang_types_usize_t)(iorp->m_transfered));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_r(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_sl_io_async_reader_file_iorp_windows_pt* const r) mk_lang_noexcept
{
	mk_lang_types_usize_t offset;
	mk_sl_io_async_reader_file_iorp_windows_pt rr;

	mk_lang_assert(iorp);
	mk_lang_assert(r);

	offset = mk_lang_offsetof(mk_sl_io_async_reader_file_iorp_windows_t, m_overlapped);
	rr = ((mk_sl_io_async_reader_file_iorp_windows_pt)(((mk_lang_types_uchar_pt)(iorp->m_iorp)) - offset));
	*r = rr;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_windows_w(mk_sl_io_async_iocp_iorp_windows_pt const iorp, mk_sl_io_async_writer_file_iorp_windows_pt* const w) mk_lang_noexcept
{
	mk_lang_types_usize_t offset;
	mk_sl_io_async_writer_file_iorp_windows_pt ww;

	mk_lang_assert(iorp);
	mk_lang_assert(w);

	offset = mk_lang_offsetof(mk_sl_io_async_writer_file_iorp_windows_t, m_overlapped);
	ww = ((mk_sl_io_async_writer_file_iorp_windows_pt)(((mk_lang_types_uchar_pt)(iorp->m_iorp)) - offset));
	*w = ww;
	return 0;
}
