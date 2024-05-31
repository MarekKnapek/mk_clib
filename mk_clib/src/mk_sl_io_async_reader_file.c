#include "mk_sl_io_async_reader_file.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_thread.h"
#include "mk_sl_io_transaction.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_async_reader_file_windows.h"
#define mk_sl_io_async_reader_file_impl_open_n       mk_sl_io_async_reader_file_windows_open_n
#define mk_sl_io_async_reader_file_impl_open_w       mk_sl_io_async_reader_file_windows_open_w
#define mk_sl_io_async_reader_file_impl_open_tx_n    mk_sl_io_async_reader_file_windows_open_tx_n
#define mk_sl_io_async_reader_file_impl_open_tx_w    mk_sl_io_async_reader_file_windows_open_tx_w
#define mk_sl_io_async_reader_file_impl_request_read mk_sl_io_async_reader_file_windows_request_read
#define mk_sl_io_async_reader_file_impl_close        mk_sl_io_async_reader_file_windows_close
#define mk_sl_io_async_reader_file_iorp_impl_construct_void mk_sl_io_async_reader_file_iorp_windows_construct_void
#define mk_sl_io_async_reader_file_iorp_impl_construct_args mk_sl_io_async_reader_file_iorp_windows_construct_args
#define mk_sl_io_async_reader_file_iorp_impl_reconstruct    mk_sl_io_async_reader_file_iorp_windows_reconstruct
#define mk_sl_io_async_reader_file_iorp_impl_buf            mk_sl_io_async_reader_file_iorp_windows_buf
#define mk_sl_io_async_reader_file_iorp_impl_len            mk_sl_io_async_reader_file_iorp_windows_len
#define mk_sl_io_async_reader_file_iorp_impl_pos            mk_sl_io_async_reader_file_iorp_windows_pos
#define mk_sl_io_async_reader_file_iorp_impl_destroy        mk_sl_io_async_reader_file_iorp_windows_destroy
#elif mk_lang_platform == mk_lang_platform_portable || mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_async_reader_file_portable.h"
#define mk_sl_io_async_reader_file_impl_open_n       mk_sl_io_async_reader_file_portable_open_n
#define mk_sl_io_async_reader_file_impl_open_w       mk_sl_io_async_reader_file_portable_open_w
#define mk_sl_io_async_reader_file_impl_open_tx_n    mk_sl_io_async_reader_file_portable_open_tx_n
#define mk_sl_io_async_reader_file_impl_open_tx_w    mk_sl_io_async_reader_file_portable_open_tx_w
#define mk_sl_io_async_reader_file_impl_request_read mk_sl_io_async_reader_file_portable_request_read
#define mk_sl_io_async_reader_file_impl_close        mk_sl_io_async_reader_file_portable_close
#define mk_sl_io_async_reader_file_iorp_impl_construct_void mk_sl_io_async_reader_file_iorp_portable_construct_void
#define mk_sl_io_async_reader_file_iorp_impl_construct_args mk_sl_io_async_reader_file_iorp_portable_construct_args
#define mk_sl_io_async_reader_file_iorp_impl_reconstruct    mk_sl_io_async_reader_file_iorp_portable_reconstruct
#define mk_sl_io_async_reader_file_iorp_impl_buf            mk_sl_io_async_reader_file_iorp_portable_buf
#define mk_sl_io_async_reader_file_iorp_impl_len            mk_sl_io_async_reader_file_iorp_portable_len
#define mk_sl_io_async_reader_file_iorp_impl_pos            mk_sl_io_async_reader_file_iorp_portable_pos
#define mk_sl_io_async_reader_file_iorp_impl_destroy        mk_sl_io_async_reader_file_iorp_portable_destroy
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_n(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert((mk_sl_io_async_thread_needs && thread) || (!mk_sl_io_async_thread_needs && !thread));

	#if mk_sl_io_async_thread_needs
	return mk_sl_io_async_reader_file_impl_open_n(&reader->m_reader, name, &thread->m_thread);
	#else
	((mk_lang_types_void_pt)(thread));
	return mk_sl_io_async_reader_file_impl_open_n(&reader->m_reader, name);
	#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_w(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert((mk_sl_io_async_thread_needs && thread) || (!mk_sl_io_async_thread_needs && !thread));

	#if mk_sl_io_async_thread_needs
	return mk_sl_io_async_reader_file_impl_open_w(&reader->m_reader, name, &thread->m_thread);
	#else
	mk_lang_assert(!thread);
	((mk_lang_types_void_pt)(thread));
	return mk_sl_io_async_reader_file_impl_open_w(&reader->m_reader, name);
	#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_tx_n(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_pt const tx, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(tx);
	mk_lang_assert((mk_sl_io_async_thread_needs && thread) || (!mk_sl_io_async_thread_needs && !thread));

	#if mk_sl_io_async_thread_needs
	return mk_sl_io_async_reader_file_impl_open_tx_n(&reader->m_reader, name, &tx->m_data, &thread->m_thread);
	#else
	((mk_lang_types_void_pt)(thread));
	return mk_sl_io_async_reader_file_impl_open_tx_n(&reader->m_reader, name, &tx->m_data);
	#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_tx_w(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_pt const tx, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(tx);
	mk_lang_assert((mk_sl_io_async_thread_needs && thread) || (!mk_sl_io_async_thread_needs && !thread));

	#if mk_sl_io_async_thread_needs
	return mk_sl_io_async_reader_file_impl_open_tx_w(&reader->m_reader, name, &tx->m_data, &thread->m_thread);
	#else
	((mk_lang_types_void_pt)(thread));
	return mk_sl_io_async_reader_file_impl_open_tx_w(&reader->m_reader, name, &tx->m_data);
	#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_request_read(mk_sl_io_async_reader_file_pt const reader, mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_impl_request_read(&reader->m_reader, &iorp->m_iorp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_close(mk_sl_io_async_reader_file_pt const reader) mk_lang_noexcept
{
	mk_lang_assert(reader);

	return mk_sl_io_async_reader_file_impl_close(&reader->m_reader);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_construct_void(mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_construct_void(&iorp->m_iorp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_construct_args(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_construct_args(&iorp->m_iorp, buf, len, pos);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_reconstruct(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_reconstruct(&iorp->m_iorp, buf, len, pos);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_buf(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt* const buf) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_buf(&iorp->m_iorp, buf);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_len(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_lang_types_usize_pt const len) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_len(&iorp->m_iorp, len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_pos(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint64_pt const pos) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_pos(&iorp->m_iorp, pos);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_destroy(mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_reader_file_iorp_impl_destroy(&iorp->m_iorp);
}
