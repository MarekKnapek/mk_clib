#include "mk_sl_io_async_iocp_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_reader_file_portable.h"
#include "mk_sl_io_async_writer_file_portable.h"

#define mk_lib_mt_ring_t_name mk_sl_io_async_iocp_portable_ring
#define mk_lib_mt_ring_t_element mk_sl_io_async_iocp_iorp_portable_t
#define mk_lib_mt_ring_t_count 32
#include "mk_lib_mt_ring_inl_filec.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_construct(mk_sl_io_async_iocp_portable_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(iocp);
	mk_lang_assert(concurrency >= 0);

	err = mk_sl_io_async_iocp_portable_ring_rw_construct(&iocp->m_iorps); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_associate_r(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_reader_file_portable_pt const reader, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(reader);

	reader->m_key = key;
	reader->m_iocp = iocp;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_associate_w(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_writer_file_portable_pt const writer, mk_lang_types_usize_t const key) mk_lang_noexcept
{
	mk_lang_assert(iocp);
	mk_lang_assert(writer);

	writer->m_key = key;
	writer->m_iocp = iocp;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_post_read_finished(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_reader_file_portable_pt const reader, mk_sl_io_async_reader_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_sl_io_async_iocp_iorp_portable_t iocpiorp;
	mk_lang_types_sint_t err;

	mk_lang_assert(iocp);
	mk_lang_assert(reader);
	mk_lang_assert(reader->m_iocp == iocp);
	mk_lang_assert(iorp);

	iocpiorp.m_kind = 0;
	iocpiorp.m_file.m_data.m_reader = reader;
	iocpiorp.m_data.m_reader = iorp;
	err = mk_sl_io_async_iocp_portable_ring_rw_push_back_one(&iocp->m_iorps, &iocpiorp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_post_write_finished(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_writer_file_portable_pt const writer, mk_sl_io_async_writer_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_sl_io_async_iocp_iorp_portable_t iocpiorp;
	mk_lang_types_sint_t err;

	mk_lang_assert(iocp);
	mk_lang_assert(writer);
	mk_lang_assert(writer->m_iocp == iocp);
	mk_lang_assert(iorp);

	iocpiorp.m_kind = 1;
	iocpiorp.m_file.m_data.m_writer = writer;
	iocpiorp.m_data.m_writer = iorp;
	err = mk_sl_io_async_iocp_portable_ring_rw_push_back_one(&iocp->m_iorps, &iocpiorp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_peek(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_iocp_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t success;

	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	err = mk_sl_io_async_iocp_portable_ring_rw_try_pop_front_copy(&iocp->m_iorps, iorp, &success); mk_lang_check_rereturn(err);
	if(!success)
	{
		iorp->m_kind = 2;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_wait(mk_sl_io_async_iocp_portable_pt const iocp, mk_sl_io_async_iocp_iorp_portable_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(iocp);
	mk_lang_assert(iorp);

	err = mk_sl_io_async_iocp_portable_ring_rw_pop_front_copy(&iocp->m_iorps, iorp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_portable_destroy(mk_sl_io_async_iocp_portable_pt const iocp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(iocp);

	err = mk_sl_io_async_iocp_portable_ring_rw_destroy(&iocp->m_iorps); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_has(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_lang_types_bool_pt const has) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(has);

	*has = iorp->m_kind != 2;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_failed(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_lang_types_bool_pt const failed) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(failed);

	*failed = mk_lang_false; /* todo */
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_key(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_lang_types_usize_pt const key) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(key);

	if(iorp->m_kind == 0)
	{
		*key = iorp->m_file.m_data.m_reader->m_key;
	}
	else if(iorp->m_kind == 1)
	{
		*key = iorp->m_file.m_data.m_writer->m_key;
	}
	else
	{
		mk_lang_assert(mk_lang_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_transfered(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_lang_types_usize_pt const transfered) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(transfered);

	if(iorp->m_kind == 0)
	{
		*transfered = iorp->m_data.m_reader->m_transfered;
	}
	else if(iorp->m_kind == 1)
	{
		*transfered = iorp->m_data.m_writer->m_transfered;
	}
	else
	{
		mk_lang_assert(mk_lang_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_r(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_sl_io_async_reader_file_iorp_portable_pt* const r) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_kind == 0);
	mk_lang_assert(r);

	*r = iorp->m_data.m_reader;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_iocp_iorp_portable_w(mk_sl_io_async_iocp_iorp_portable_pt const iorp, mk_sl_io_async_writer_file_iorp_portable_pt* const w) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_kind == 1);
	mk_lang_assert(w);

	*w = iorp->m_data.m_writer;
	return 0;
}
