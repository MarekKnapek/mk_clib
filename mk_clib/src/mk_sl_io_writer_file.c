#include "mk_sl_io_writer_file.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_os.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction.h"
#include "mk_sl_uint8.h"


#if mk_lang_os == mk_lang_os_windows
#include "mk_sl_io_writer_file_windows.h"
#define mk_sl_io_writer_file_impl_open_n    mk_sl_io_writer_file_windows_open_n
#define mk_sl_io_writer_file_impl_open_w    mk_sl_io_writer_file_windows_open_w
#define mk_sl_io_writer_file_impl_open_tx_n mk_sl_io_writer_file_windows_open_tx_n
#define mk_sl_io_writer_file_impl_open_tx_w mk_sl_io_writer_file_windows_open_tx_w
#define mk_sl_io_writer_file_impl_write     mk_sl_io_writer_file_windows_write
#define mk_sl_io_writer_file_impl_close     mk_sl_io_writer_file_windows_close
#elif mk_lang_os == mk_lang_os_linux
#include "mk_sl_io_writer_file_linux.h"
#define mk_sl_io_writer_file_impl_open_n    mk_sl_io_writer_file_linux_open_n
#define mk_sl_io_writer_file_impl_open_w    mk_sl_io_writer_file_linux_open_w
#define mk_sl_io_writer_file_impl_open_tx_n mk_sl_io_writer_file_linux_open_tx_n
#define mk_sl_io_writer_file_impl_open_tx_w mk_sl_io_writer_file_linux_open_tx_w
#define mk_sl_io_writer_file_impl_write     mk_sl_io_writer_file_linux_write
#define mk_sl_io_writer_file_impl_close     mk_sl_io_writer_file_linux_close
#elif mk_lang_os == mk_lang_os_c
#include "mk_sl_io_writer_file_portable.h"
#define mk_sl_io_writer_file_impl_open_n    mk_sl_io_writer_file_portable_open_n
#define mk_sl_io_writer_file_impl_open_w    mk_sl_io_writer_file_portable_open_w
#define mk_sl_io_writer_file_impl_open_tx_n mk_sl_io_writer_file_portable_open_tx_n
#define mk_sl_io_writer_file_impl_open_tx_w mk_sl_io_writer_file_portable_open_tx_w
#define mk_sl_io_writer_file_impl_write     mk_sl_io_writer_file_portable_write
#define mk_sl_io_writer_file_impl_close     mk_sl_io_writer_file_portable_close
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_n(mk_sl_io_writer_file_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(writer);

	return mk_sl_io_writer_file_impl_open_n(&writer->m_file_handle, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_w(mk_sl_io_writer_file_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(writer);

	return mk_sl_io_writer_file_impl_open_w(&writer->m_file_handle, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_tx_n(mk_sl_io_writer_file_pt const writer, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(tx);

	return mk_sl_io_writer_file_impl_open_tx_n(&writer->m_file_handle, name, &tx->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_tx_w(mk_sl_io_writer_file_pt const writer, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(tx);

	return mk_sl_io_writer_file_impl_open_tx_w(&writer->m_file_handle, name, &tx->m_data);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_write(mk_sl_io_writer_file_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept
{
	return mk_sl_io_writer_file_impl_write(&writer->m_file_handle, buf, len, written);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_close(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	mk_lang_assert(writer);

	return mk_sl_io_writer_file_impl_close(&writer->m_file_handle);
}
