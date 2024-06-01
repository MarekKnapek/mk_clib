#include "mk_sl_io_async_thread_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_thread.h"
#include "mk_lib_mt_thread_name.h"
#include "mk_sl_io_async_iocp_portable.h"
#include "mk_sl_io_async_reader_file_portable.h"
#include "mk_sl_io_async_writer_file_portable.h"

#if mk_lib_mt_thread_has

#define mk_lib_mt_ring_t_name mk_sl_io_async_thread_portable_ring
#define mk_lib_mt_ring_t_element mk_sl_io_async_thread_portable_task_t
#define mk_lib_mt_ring_t_count 512
#include "mk_lib_mt_ring_inl_filec.h"

#else

#define mk_sl_ring_t_name mk_sl_io_async_thread_portable_ring
#define mk_sl_ring_t_element mk_sl_io_async_thread_portable_task_t
#define mk_sl_ring_t_count 512
#include "mk_sl_ring_inl_filec.h"

#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_async_thread_portable_proc_impl_4(mk_sl_io_async_thread_portable_pt const thread, mk_sl_io_async_thread_portable_task_pt const task) mk_lang_noexcept
{
	mk_sl_io_async_reader_file_portable_pt reader;
	mk_sl_io_async_reader_file_iorp_portable_pt iorpr;
	mk_lang_types_slong_t pos;
	mk_lang_types_void_pt buf;
	mk_lang_types_sint_t ret;
	mk_lang_types_sint_t err;
	mk_sl_io_async_writer_file_portable_pt writer;
	mk_sl_io_async_writer_file_iorp_portable_pt iorpw;

	mk_lang_assert(thread);
	mk_lang_assert(task);
	mk_lang_assert(task->m_type == 0 || task->m_type == 1);

	if(task->m_type == 0)
	{
		reader = task->m_file.m_data.m_read;
		iorpr = task->m_iorp.m_data.m_read;
		mk_sl_cui_uint64_to_bi_slong(&iorpr->m_pos, &pos);
		buf = ((mk_lang_types_void_pt)(iorpr->m_buf));
		ret = fseek(reader->m_file, pos, SEEK_SET); mk_lang_check_return(ret == 0);
		iorpr->m_transfered = fread(buf, 1, iorpr->m_len, reader->m_file);
		err = mk_sl_io_async_iocp_portable_post_read_finished(reader->m_iocp, reader, iorpr); mk_lang_check_rereturn(err);
	}
	else
	{
		writer = task->m_file.m_data.m_write;
		iorpw = task->m_iorp.m_data.m_write;
		mk_sl_cui_uint64_to_bi_slong(&iorpw->m_pos, &pos);
		buf = ((mk_lang_types_void_pt)(iorpw->m_buf));
		ret = fseek(writer->m_file, pos, SEEK_SET); mk_lang_check_return(ret == 0);
		iorpw->m_transfered = fwrite(buf, 1, iorpw->m_len, writer->m_file);
		err = mk_sl_io_async_iocp_portable_post_write_finished(writer->m_iocp, writer, iorpw); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_async_thread_portable_proc_impl_3(mk_sl_io_async_thread_portable_pt const thread, mk_sl_io_async_thread_portable_task_pt const task, mk_lang_types_bool_pt const end) mk_lang_noexcept
{
	mk_lang_types_bool_t e;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(task);
	mk_lang_assert(task->m_type == 0 || task->m_type == 1 || task->m_type == 2);
	mk_lang_assert(end);

	e = task->m_type == 2;
	*end = e;
	if(!e)
	{
		err = mk_sl_io_async_thread_portable_proc_impl_4(thread, task); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_async_thread_portable_proc_impl_2(mk_sl_io_async_thread_portable_pt const thread, mk_lang_types_bool_pt const end) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err;
	mk_sl_io_async_thread_portable_task_t task;

	mk_lang_assert(thread);
	mk_lang_assert(end);

	err = mk_sl_io_async_thread_portable_ring_rw_pop_front_copy(&thread->m_ring, &task); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_thread_portable_proc_impl_3(thread, &task, end); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_sl_io_async_thread_portable_task_pt task;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(end);

	task = mk_sl_io_async_thread_portable_ring_rw_pop_front_one(&thread->m_ring);
	err = mk_sl_io_async_thread_portable_proc_impl_3(thread, task, end); mk_lang_check_rereturn(err);
	return 0;
#endif
}

#if mk_lib_mt_thread_has
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_async_thread_portable_proc_impl_1(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t end;

	mk_lang_assert(thread);

	err = mk_lib_mt_thread_name_set("backgroundio"); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_async_thread_portable_proc_impl_2(thread, &end); mk_lang_check_rereturn(err);
		if(end)
		{
			break;
		}
	}
	return 0;
}
#endif

#if mk_lib_mt_thread_has
mk_lang_nodiscard static mk_lang_types_sint_t mk_sl_io_async_thread_portable_proc(mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_async_thread_portable_pt thread;

	mk_lang_assert(context);

	thread = ((mk_sl_io_async_thread_portable_pt)(context));
	err = mk_sl_io_async_thread_portable_proc_impl_1(thread); mk_lang_check_rereturn(err);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_create(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);

	err = mk_sl_io_async_thread_portable_ring_rw_construct(&thread->m_ring); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_create(&thread->m_thread, &mk_sl_io_async_thread_portable_proc, thread);
	if(err_b != 0)
	{
		err = mk_sl_io_async_thread_portable_ring_rw_destroy(&thread->m_ring); mk_lang_check_rereturn(err);
		mk_lang_check_rereturn(err_b);
	}
	return 0;
#else
	mk_lang_assert(thread);

	mk_sl_io_async_thread_portable_ring_rw_construct(&thread->m_ring);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_add_r(mk_sl_io_async_thread_portable_pt const thread, mk_sl_io_async_reader_file_portable_pt const reader, mk_sl_io_async_reader_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_sl_io_async_thread_portable_task_t task;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(reader);
	mk_lang_assert(iorp);

	task.m_type = 0;
	task.m_file.m_data.m_read = reader;
	task.m_iorp.m_data.m_read = iorp;
	err = mk_sl_io_async_thread_portable_ring_rw_push_back_one(&thread->m_ring, &task); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_sl_io_async_thread_portable_task_t task;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t end;

	mk_lang_assert(thread);
	mk_lang_assert(reader);
	mk_lang_assert(iorp);

	task.m_type = 0;
	task.m_file.m_data.m_read = reader;
	task.m_iorp.m_data.m_read = iorp;
	if(mk_sl_io_async_thread_portable_ring_rw_is_full(&thread->m_ring))
	{
		err = mk_sl_io_async_thread_portable_proc_impl_2(thread, &end); mk_lang_check_rereturn(err); mk_lang_assert(!end);
	}
	mk_sl_io_async_thread_portable_ring_rw_push_back_one(&thread->m_ring, &task);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_add_w(mk_sl_io_async_thread_portable_pt const thread, mk_sl_io_async_writer_file_portable_pt const writer, mk_sl_io_async_writer_file_iorp_portable_pt const iorp) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_sl_io_async_thread_portable_task_t task;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(writer);
	mk_lang_assert(iorp);

	task.m_type = 1;
	task.m_file.m_data.m_write = writer;
	task.m_iorp.m_data.m_write = iorp;
	err = mk_sl_io_async_thread_portable_ring_rw_push_back_one(&thread->m_ring, &task); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_sl_io_async_thread_portable_task_t task;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t end;

	mk_lang_assert(thread);
	mk_lang_assert(writer);
	mk_lang_assert(iorp);

	task.m_type = 1;
	task.m_file.m_data.m_write = writer;
	task.m_iorp.m_data.m_write = iorp;
	if(mk_sl_io_async_thread_portable_ring_rw_is_full(&thread->m_ring))
	{
		err = mk_sl_io_async_thread_portable_proc_impl_2(thread, &end); mk_lang_check_rereturn(err); mk_lang_assert(!end);
	}
	mk_sl_io_async_thread_portable_ring_rw_push_back_one(&thread->m_ring, &task);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_poke(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#else
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t end;

	mk_lang_assert(thread);

	if(!mk_sl_io_async_thread_portable_ring_rw_is_empty(&thread->m_ring))
	{
		err = mk_sl_io_async_thread_portable_proc_impl_2(thread, &end); mk_lang_check_rereturn(err); mk_lang_assert(!end);
	}
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_flush(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_sl_io_async_thread_portable_task_t task;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);

	task.m_type = 2;
	err = mk_sl_io_async_thread_portable_ring_rw_push_back_one(&thread->m_ring, &task); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_thread_portable_ring_rw_wait_til_empty(&thread->m_ring); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t end;

	mk_lang_assert(thread);

	while(!mk_sl_io_async_thread_portable_ring_rw_is_empty(&thread->m_ring))
	{
		err = mk_sl_io_async_thread_portable_proc_impl_2(thread, &end); mk_lang_check_rereturn(err); mk_lang_assert(!end);
	}
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_join(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);

	err = mk_lib_mt_thread_join(&thread->m_thread); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(thread);

	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_portable_destroy(mk_sl_io_async_thread_portable_pt const thread) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err_a;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);

	err_a = mk_lib_mt_thread_destroy(&thread->m_thread);
	err_b = mk_sl_io_async_thread_portable_ring_rw_destroy(&thread->m_ring);
	mk_lang_check_rereturn(err_a);
	mk_lang_check_rereturn(err_b);
	return 0;
#else
	mk_lang_assert(thread);

	return 0;
#endif
}
