#ifndef mk_include_guard_mk_sl_io_async_iocp
#define mk_include_guard_mk_sl_io_async_iocp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"


struct mk_sl_io_async_reader_file_s;
typedef struct mk_sl_io_async_reader_file_s mk_sl_io_async_reader_file_t;
typedef mk_sl_io_async_reader_file_t const mk_sl_io_async_reader_file_ct;
typedef mk_sl_io_async_reader_file_t* mk_sl_io_async_reader_file_pt;
typedef mk_sl_io_async_reader_file_t const* mk_sl_io_async_reader_file_pct;

struct mk_sl_io_async_reader_file_iorp_s;
typedef struct mk_sl_io_async_reader_file_iorp_s mk_sl_io_async_reader_file_iorp_t;
typedef mk_sl_io_async_reader_file_iorp_t const mk_sl_io_async_reader_file_iorp_ct;
typedef mk_sl_io_async_reader_file_iorp_t* mk_sl_io_async_reader_file_iorp_pt;
typedef mk_sl_io_async_reader_file_iorp_t const* mk_sl_io_async_reader_file_iorp_pct;

struct mk_sl_io_async_writer_file_s;
typedef struct mk_sl_io_async_writer_file_s mk_sl_io_async_writer_file_t;
typedef mk_sl_io_async_writer_file_t const mk_sl_io_async_writer_file_ct;
typedef mk_sl_io_async_writer_file_t* mk_sl_io_async_writer_file_pt;
typedef mk_sl_io_async_writer_file_t const* mk_sl_io_async_writer_file_pct;

struct mk_sl_io_async_writer_file_iorp_s;
typedef struct mk_sl_io_async_writer_file_iorp_s mk_sl_io_async_writer_file_iorp_t;
typedef mk_sl_io_async_writer_file_iorp_t const mk_sl_io_async_writer_file_iorp_ct;
typedef mk_sl_io_async_writer_file_iorp_t* mk_sl_io_async_writer_file_iorp_pt;
typedef mk_sl_io_async_writer_file_iorp_t const* mk_sl_io_async_writer_file_iorp_pct;


#if mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_async_iocp_windows.h"
typedef mk_sl_io_async_iocp_windows_t mk_sl_io_async_iocp_impl_t;
typedef mk_sl_io_async_iocp_iorp_windows_t mk_sl_io_async_iocp_iorp_impl_t;
typedef mk_sl_io_async_iocp_iorp_impl_t* mk_sl_io_async_iocp_iorp_impl_pt;
#elif mk_lang_platform == mk_lang_platform_portable || mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_async_iocp_portable.h"
typedef mk_sl_io_async_iocp_portable_t mk_sl_io_async_iocp_impl_t;
typedef mk_sl_io_async_iocp_iorp_portable_t mk_sl_io_async_iocp_iorp_impl_t;
typedef mk_sl_io_async_iocp_iorp_impl_t* mk_sl_io_async_iocp_iorp_impl_pt;
#else
#error xxxxxxxxxx todo
#endif


struct mk_sl_io_async_iocp_s
{
	mk_sl_io_async_iocp_impl_t m_iocp;
};
typedef struct mk_sl_io_async_iocp_s mk_sl_io_async_iocp_t;
typedef mk_sl_io_async_iocp_t const mk_sl_io_async_iocp_ct;
typedef mk_sl_io_async_iocp_t* mk_sl_io_async_iocp_pt;
typedef mk_sl_io_async_iocp_t const* mk_sl_io_async_iocp_pct;

struct mk_sl_io_async_iocp_iorp_s
{
	mk_sl_io_async_iocp_iorp_impl_t m_iorp;
};
typedef struct mk_sl_io_async_iocp_iorp_s mk_sl_io_async_iocp_iorp_t;
typedef mk_sl_io_async_iocp_iorp_t const mk_sl_io_async_iocp_iorp_ct;
typedef mk_sl_io_async_iocp_iorp_t* mk_sl_io_async_iocp_iorp_pt;
typedef mk_sl_io_async_iocp_iorp_t const* mk_sl_io_async_iocp_iorp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_construct(mk_sl_io_async_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_associate_r(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_reader_file_pt const reader, mk_lang_types_usize_t const key) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_associate_w(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_writer_file_pt const writer, mk_lang_types_usize_t const key) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_peek(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_iocp_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_wait(mk_sl_io_async_iocp_pt const iocp, mk_sl_io_async_iocp_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_destroy(mk_sl_io_async_iocp_pt const iocp) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_has(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_bool_pt const has) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_failed(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_bool_pt const failed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_key(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_usize_pt const key) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_transfered(mk_sl_io_async_iocp_iorp_pt const iorp, mk_lang_types_usize_pt const transfered) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_r(mk_sl_io_async_iocp_iorp_pt const iorp, mk_sl_io_async_reader_file_iorp_pt* const r) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_w(mk_sl_io_async_iocp_iorp_pt const iorp, mk_sl_io_async_writer_file_iorp_pt* const w) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_async_iocp.c"
#endif
#endif
