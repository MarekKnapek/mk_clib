#include "mk_sl_io_reader_file.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction.h"
#include "mk_sl_uint8.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_reader_file_windows.h"
#define mk_sl_io_reader_file_impl_open_n    mk_sl_io_reader_file_windows_open_n
#define mk_sl_io_reader_file_impl_open_w    mk_sl_io_reader_file_windows_open_w
#define mk_sl_io_reader_file_impl_open_tx_n mk_sl_io_reader_file_windows_open_tx_n
#define mk_sl_io_reader_file_impl_open_tx_w mk_sl_io_reader_file_windows_open_tx_w
#define mk_sl_io_reader_file_impl_read      mk_sl_io_reader_file_windows_read
#define mk_sl_io_reader_file_impl_seek_rel  mk_sl_io_reader_file_windows_seek_rel
#define mk_sl_io_reader_file_impl_close     mk_sl_io_reader_file_windows_close
#elif mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_reader_file_linux.h"
#define mk_sl_io_reader_file_impl_open_n    mk_sl_io_reader_file_linux_open_n
#define mk_sl_io_reader_file_impl_open_w    mk_sl_io_reader_file_linux_open_w
#define mk_sl_io_reader_file_impl_open_tx_n mk_sl_io_reader_file_linux_open_tx_n
#define mk_sl_io_reader_file_impl_open_tx_w mk_sl_io_reader_file_linux_open_tx_w
#define mk_sl_io_reader_file_impl_read      mk_sl_io_reader_file_linux_read
#define mk_sl_io_reader_file_impl_seek_rel  mk_sl_io_reader_file_linux_seek_rel
#define mk_sl_io_reader_file_impl_close     mk_sl_io_reader_file_linux_close
#elif mk_lang_platform == mk_lang_platform_portable
#include "mk_sl_io_reader_file_portable.h"
#define mk_sl_io_reader_file_impl_open_n    mk_sl_io_reader_file_portable_open_n
#define mk_sl_io_reader_file_impl_open_w    mk_sl_io_reader_file_portable_open_w
#define mk_sl_io_reader_file_impl_open_tx_n mk_sl_io_reader_file_portable_open_tx_n
#define mk_sl_io_reader_file_impl_open_tx_w mk_sl_io_reader_file_portable_open_tx_w
#define mk_sl_io_reader_file_impl_read      mk_sl_io_reader_file_portable_read
#define mk_sl_io_reader_file_impl_seek_rel  mk_sl_io_reader_file_portable_seek_rel
#define mk_sl_io_reader_file_impl_close     mk_sl_io_reader_file_portable_close
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_n(mk_sl_io_reader_file_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_reader_file_impl_open_n(&reader->m_file_handle, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_w(mk_sl_io_reader_file_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_reader_file_impl_open_w(&reader->m_file_handle, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_tx_n(mk_sl_io_reader_file_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(tx);

	return mk_sl_io_reader_file_impl_open_tx_n(&reader->m_file_handle, name, &tx->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_tx_w(mk_sl_io_reader_file_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(tx);

	return mk_sl_io_reader_file_impl_open_tx_w(&reader->m_file_handle, name, &tx->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_read(mk_sl_io_reader_file_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_reader_file_impl_read(&reader->m_file_handle, buf, len, read);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_seek_rel(mk_sl_io_reader_file_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_reader_file_impl_seek_rel(&reader->m_file_handle, offset);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_close(mk_sl_io_reader_file_pt const reader) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_reader_file_impl_close(&reader->m_file_handle);
}
