#include "mk_sl_io_async_reader_file_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_iocp_portable.h"
#include "mk_sl_io_async_thread_portable.h"
#include "mk_sl_io_transaction_portable.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* FILE fopen fclose fread fseek SEEK_SET _wfopen */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_open_n(mk_sl_io_async_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
	FILE* file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(thread);

	file = fopen(name, "rb"); mk_lang_check_return(file);
	reader->m_file = file;
	reader->m_iocp = mk_lang_null;
	reader->m_thread = thread;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_open_w(mk_sl_io_async_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 /* todo: earlier? */
	FILE* file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');
	mk_lang_assert(thread);

	file = _wfopen(name, L"rb"); mk_lang_check_return(file);
	reader->m_file = file;
	reader->m_iocp = mk_lang_null;
	reader->m_thread = thread;
	return 0;
#else
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');
	mk_lang_assert(thread);

	return mk_lang_check_line;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_open_tx_n(mk_sl_io_async_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_portable_pt const tx, mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);
	mk_lang_assert(thread);

	return mk_lang_check_line;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_open_tx_w(mk_sl_io_async_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_portable_pt const tx, mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);
	mk_lang_assert(thread);

	return mk_lang_check_line;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_request_read(mk_sl_io_async_reader_file_portable_pt const reader, mk_sl_io_async_reader_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reader);
	mk_lang_assert(reader->m_file);
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_buf || iorp->m_len == 0);
	mk_lang_assert(iorp->m_len >= 0);

	err = mk_sl_io_async_thread_portable_add_r(reader->m_thread, reader, iorp);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_portable_close(mk_sl_io_async_reader_file_portable_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(reader->m_file);

	ret = fclose(reader->m_file); mk_lang_check_return(ret == 0);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_construct_void(mk_sl_io_async_reader_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	iorp->m_buf = mk_lang_null;
	iorp->m_len = 0;
	mk_sl_cui_uint64_set_zero(&iorp->m_pos);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_construct_args(mk_sl_io_async_reader_file_iorp_portable_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint64_t ta;

	mk_lang_assert(iorp);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= ((mk_lang_types_usize_t)(0)) && len <= ((mk_lang_types_usize_t)(mk_lang_limits_slong_max)));
	mk_lang_assert(pos);

	mk_sl_cui_uint64_to_bi_ulong(pos, &tul); mk_sl_cui_uint64_shr3(pos, 32, &ta); mk_lang_assert(tul <= ((mk_lang_types_ulong_t)(mk_lang_limits_slong_max))); mk_lang_assert(mk_sl_cui_uint64_is_zero(&ta));
	iorp->m_buf = buf;
	iorp->m_len = len;
	iorp->m_pos = *pos;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_reconstruct(mk_sl_io_async_reader_file_iorp_portable_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	return mk_sl_io_async_reader_file_iorp_portable_construct_args(iorp, buf, len, pos);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_buf(mk_sl_io_async_reader_file_iorp_portable_pt const iorp, mk_sl_cui_uint8_pt* const buf) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(buf);

	*buf = iorp->m_buf;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_len(mk_sl_io_async_reader_file_iorp_portable_pt const iorp, mk_lang_types_usize_pt const len) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(len);

	*len = iorp->m_len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_pos(mk_sl_io_async_reader_file_iorp_portable_pt const iorp, mk_sl_cui_uint64_pt const pos) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(pos);

	*pos = iorp->m_pos;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_portable_destroy(mk_sl_io_async_reader_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	((mk_lang_types_void_t)(iorp));
	return 0;
}
