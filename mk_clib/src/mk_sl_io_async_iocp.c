#include "mk_sl_io_async_iocp.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_reader_file.h"
#include "mk_sl_io_async_writer_file.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_async_iocp_windows.h"
#define mk_sl_io_async_reader_file_iorp_impl_pt mk_sl_io_async_reader_file_iorp_windows_pt
#define mk_sl_io_async_writer_file_iorp_impl_pt mk_sl_io_async_writer_file_iorp_windows_pt
#define mk_sl_io_async_iocp_impl_construct   mk_sl_io_async_iocp_windows_construct
#define mk_sl_io_async_iocp_impl_associate_r mk_sl_io_async_iocp_windows_associate_r
#define mk_sl_io_async_iocp_impl_associate_w mk_sl_io_async_iocp_windows_associate_w
#define mk_sl_io_async_iocp_impl_peek        mk_sl_io_async_iocp_windows_peek
#define mk_sl_io_async_iocp_impl_wait        mk_sl_io_async_iocp_windows_wait
#define mk_sl_io_async_iocp_impl_destroy     mk_sl_io_async_iocp_windows_destroy
#define mk_sl_io_async_iocp_iorp_impl_has        mk_sl_io_async_iocp_iorp_windows_has
#define mk_sl_io_async_iocp_iorp_impl_failed     mk_sl_io_async_iocp_iorp_windows_failed
#define mk_sl_io_async_iocp_iorp_impl_key        mk_sl_io_async_iocp_iorp_windows_key
#define mk_sl_io_async_iocp_iorp_impl_transfered mk_sl_io_async_iocp_iorp_windows_transfered
#define mk_sl_io_async_iocp_iorp_impl_r          mk_sl_io_async_iocp_iorp_windows_r
#define mk_sl_io_async_iocp_iorp_impl_w          mk_sl_io_async_iocp_iorp_windows_w
#elif mk_lang_platform == mk_lang_platform_portable || mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_async_iocp_portable.h"
#define mk_sl_io_async_reader_file_iorp_impl_pt mk_sl_io_async_reader_file_iorp_portable_pt
#define mk_sl_io_async_writer_file_iorp_impl_pt mk_sl_io_async_writer_file_iorp_portable_pt
#define mk_sl_io_async_iocp_impl_construct   mk_sl_io_async_iocp_portable_construct
#define mk_sl_io_async_iocp_impl_associate_r mk_sl_io_async_iocp_portable_associate_r
#define mk_sl_io_async_iocp_impl_associate_w mk_sl_io_async_iocp_portable_associate_w
#define mk_sl_io_async_iocp_impl_peek        mk_sl_io_async_iocp_portable_peek
#define mk_sl_io_async_iocp_impl_wait        mk_sl_io_async_iocp_portable_wait
#define mk_sl_io_async_iocp_impl_destroy     mk_sl_io_async_iocp_portable_destroy
#define mk_sl_io_async_iocp_iorp_impl_has        mk_sl_io_async_iocp_iorp_portable_has
#define mk_sl_io_async_iocp_iorp_impl_failed     mk_sl_io_async_iocp_iorp_portable_failed
#define mk_sl_io_async_iocp_iorp_impl_key        mk_sl_io_async_iocp_iorp_portable_key
#define mk_sl_io_async_iocp_iorp_impl_transfered mk_sl_io_async_iocp_iorp_portable_transfered
#define mk_sl_io_async_iocp_iorp_impl_r          mk_sl_io_async_iocp_iorp_portable_r
#define mk_sl_io_async_iocp_iorp_impl_w          mk_sl_io_async_iocp_iorp_portable_w
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_construct(mk_sl_io_async_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept
{
	mk_lang_assert(iocp);

	return mk_sl_io_async_iocp_impl_construct(&iocp->m_iocp, concurrency);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_associate_r(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_reader_file_pt const reader, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(reader);

	return mk_sl_io_async_iocp_impl_associate_r(&iocp->m_iocp, &reader->m_reader, key);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_associate_w(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_writer_file_pt const writer, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(writer);

	return mk_sl_io_async_iocp_impl_associate_w(&iocp->m_iocp, &writer->m_writer, key);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_peek(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_iocp_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_impl_peek(&iocp->m_iocp, &iorp->m_iorp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_wait(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_iocp_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_impl_wait(&iocp->m_iocp, &iorp->m_iorp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_destroy(mk_sl_io_async_iocp_pt const iocp) mk_lang_noexcept
{
	mk_lang_assert(iocp);

	return mk_sl_io_async_iocp_impl_destroy(&iocp->m_iocp);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_has(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_bool_pt const has) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_has(&iorp->m_iorp, has);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_failed(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_bool_pt const failed) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_failed(&iorp->m_iorp, failed);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_key(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_usize_pt const key) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_key(&iorp->m_iorp, key);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_transfered(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_usize_pt const transfered) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_transfered(&iorp->m_iorp, transfered);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_r(mk_sl_io_async_iocp_iorp_pt const iorp, mk_sl_io_async_reader_file_iorp_pt* const r) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_r(&iorp->m_iorp, ((mk_sl_io_async_reader_file_iorp_impl_pt*)(r)));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_w(mk_sl_io_async_iocp_iorp_pt const iorp, mk_sl_io_async_writer_file_iorp_pt* const w) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	return mk_sl_io_async_iocp_iorp_impl_w(&iorp->m_iorp, ((mk_sl_io_async_writer_file_iorp_impl_pt*)(w)));
}
