#include "mk_clib_app_vc.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_platform.h"
#include "mk_lang_pow2.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_mt_thread.h"
#include "mk_lib_text_encoding.h"
#include "mk_lib_vc.h"
#include "mk_sl_io_async_iocp.h"
#include "mk_sl_io_async_reader_file.h"
#include "mk_sl_io_async_thread.h"
#include "mk_sl_io_async_writer_file.h"
#include "mk_sl_io_console.h"
#include "mk_sl_io_transaction.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memset_t_name mk_clib_app_vc_memse_tu8
#define mk_lang_memset_t_type mk_sl_cui_uint8_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_strlen_t_name mk_clib_app_vc_strlen_pc
#define mk_lang_strlen_t_type mk_lang_types_pchar_t
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"

#define mk_lang_strlen_t_name mk_clib_app_vc_strlen_wc
#define mk_lang_strlen_t_type mk_lang_types_wchar_t
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"


#if mk_lib_mt_thread_has
#define mk_clib_app_vc_max_threads (1024)
#define mk_clib_app_vc_max_tasks (4 * mk_clib_app_vc_max_threads)
#else
#define mk_clib_app_vc_max_tasks 1
#endif
#define mk_clib_app_vc_iocp_idx_reader 1
#define mk_clib_app_vc_iocp_idx_writer 2
#define mk_clib_app_vc_vhd_volume_align (1ul * 1024ul * 1024ul)
#define mk_clib_app_vc_io_block_len (64ul * 1024ul)
#define mk_clib_app_vc_io_block_align (64ul * 1024ul)
#define mk_clib_app_vc_io_blocks_len_min (8ul * 1024ul * 1024ul)
#define mk_clib_app_vc_io_blocks_count_min_a (mk_clib_app_vc_io_blocks_len_min / mk_clib_app_vc_io_block_len)
#define mk_clib_app_vc_io_blocks_count_min_b ((mk_clib_app_vc_max_tasks * mk_lib_vc_block_len) / mk_clib_app_vc_io_block_len)
#define mk_clib_app_vc_io_blocks_count mk_lang_max(mk_clib_app_vc_io_blocks_count_min_a, mk_clib_app_vc_io_blocks_count_min_b)
#define mk_clib_app_vc_io_blocks_len_real (mk_clib_app_vc_io_blocks_count * mk_clib_app_vc_io_block_len)


union mk_clib_app_vc_iorp_data_u
{
	mk_sl_io_async_reader_file_iorp_t m_read;
	mk_sl_io_async_writer_file_iorp_t m_write;
};
typedef union mk_clib_app_vc_iorp_data_u mk_clib_app_vc_iorp_data_t;
typedef mk_clib_app_vc_iorp_data_t const mk_clib_app_vc_iorp_data_ct;
typedef mk_clib_app_vc_iorp_data_t* mk_clib_app_vc_iorp_data_pt;
typedef mk_clib_app_vc_iorp_data_t const* mk_clib_app_vc_iorp_data_pct;

struct mk_clib_app_vc_iorp_s
{
	mk_clib_app_vc_iorp_data_t m_data;
	mk_lang_types_usize_t m_transfered;
	mk_lang_types_bool_t m_finished;
};
typedef struct mk_clib_app_vc_iorp_s mk_clib_app_vc_iorp_t;
typedef mk_clib_app_vc_iorp_t const mk_clib_app_vc_iorp_ct;
typedef mk_clib_app_vc_iorp_t* mk_clib_app_vc_iorp_pt;
typedef mk_clib_app_vc_iorp_t const* mk_clib_app_vc_iorp_pct;

#if mk_lib_mt_thread_has

struct mk_clib_app_vc_task_s
{
	mk_sl_cui_uint64_t m_block_id;
	mk_lib_vc_block_pt m_block;
};
typedef struct mk_clib_app_vc_task_s mk_clib_app_vc_task_t;
typedef mk_clib_app_vc_task_t const mk_clib_app_vc_task_ct;
typedef mk_clib_app_vc_task_t* mk_clib_app_vc_task_pt;
typedef mk_clib_app_vc_task_t const* mk_clib_app_vc_task_pct;

#define mk_lib_mt_ring_t_name mk_clib_app_vc_mtring
#define mk_lib_mt_ring_t_element mk_clib_app_vc_task_t
#define mk_lib_mt_ring_t_count mk_clib_app_vc_max_tasks
#include "mk_lib_mt_ring_inl_fileh.h"
#include "mk_lib_mt_ring_inl_filec.h"

#define mk_sl_fixed_vector_t_name mk_clib_app_vc_fixed_vector
#define mk_sl_fixed_vector_t_element mk_clib_app_vc_task_t
#define mk_sl_fixed_vector_t_count (mk_clib_app_vc_io_blocks_len_real / mk_lib_vc_block_len)
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_filec.h"

#define mk_lang_swap_t_name mk_clib_app_vc_task_swap
#define mk_lang_swap_t_type mk_clib_app_vc_task_t
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"

#endif


struct mk_clib_app_vc_s
{
	mk_lang_types_bool_t m_wide;
	mk_lang_types_sint_t m_argc;
	mk_lang_types_pchar_pcpct m_argv;
	mk_lib_vc_seqid_t m_seqid;
	mk_lib_vc_seq_schedules_t m_schedules;
	mk_sl_cui_uint64_t m_vol_len;
	mk_sl_io_transaction_t m_tx;
	mk_sl_io_async_iocp_t m_iocp;
	mk_sl_io_async_reader_file_t m_reader;
	mk_sl_io_async_writer_file_t m_writer;
	mk_sl_cui_uint64_t m_block_id_to_decrypt;
	mk_sl_cui_uint64_t m_block_id_to_write;
	mk_sl_cui_uint64_t m_block_id_max;
	mk_sl_cui_uint64_t m_file_pos_to_read;
	mk_sl_cui_uint64_t m_file_pos_max_read;
	mk_sl_cui_uint64_t m_file_pos_to_write;
	mk_sl_cui_uint64_t m_file_pos_written;
	mk_lang_types_uint_t m_idx_rr;
	mk_lang_types_uint_t m_idx_rf;
	mk_lang_types_uint_t m_idx_dr;
	mk_lang_types_uint_t m_idx_df;
	mk_lang_types_uint_t m_idx_wr;
	mk_lang_types_uint_t m_idx_wf;
	mk_sl_cui_uint8_pt m_buf;
	#if mk_lib_mt_thread_has
	mk_clib_app_vc_mtring_t m_decrypt_submit;
	mk_clib_app_vc_mtring_t m_decrypt_receieve;
	mk_clib_app_vc_fixed_vector_t m_finished;
	mk_lib_mt_thread_t m_threads[mk_clib_app_vc_max_threads];
	#endif
	mk_lang_types_uint_t m_threads_count;
	mk_clib_app_vc_iorp_t m_iorps[mk_clib_app_vc_io_blocks_count];
	#if mk_sl_io_async_thread_needs
	mk_sl_io_async_thread_t m_io_async_thread;
	#endif
	mk_sl_cui_uint8_t m_buffer[mk_lang_roundup_size(mk_clib_app_vc_io_blocks_len_real, mk_clib_app_vc_io_block_align)];
};
typedef struct mk_clib_app_vc_s mk_clib_app_vc_t;
typedef mk_clib_app_vc_t const mk_clib_app_vc_ct;
typedef mk_clib_app_vc_t* mk_clib_app_vc_pt;
typedef mk_clib_app_vc_t const* mk_clib_app_vc_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_request_read(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_pt iorp;
	mk_sl_cui_uint8_pt ptr;
	mk_sl_cui_uint64_t tu64a;
	mk_sl_cui_uint64_t tu64b;
	mk_lang_types_ulong_t tul;
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = cap - (vc->m_idx_rr - vc->m_idx_wf);
	if(cnt != 0)
	{
		idx = vc->m_idx_rr % cap;
		iorp = &vc->m_iorps[idx];
		ptr = &vc->m_buf[idx * mk_clib_app_vc_io_block_len];
		mk_sl_cui_uint64_sub3_wrap_cid_cod(&vc->m_file_pos_max_read, &vc->m_file_pos_to_read, &tu64a);
		mk_sl_cui_uint64_shr3(&tu64a, 32, &tu64b);
		if(mk_sl_cui_uint64_is_zero(&tu64b))
		{
			mk_sl_cui_uint64_to_bi_ulong(&tu64a, &tul);
		}
		else
		{
			tul = mk_lang_limits_ulong_max;
		}
		len = ((mk_lang_types_usize_t)(mk_lang_min(tul, ((mk_lang_types_ulong_t)(mk_clib_app_vc_io_block_len)))));
		if(len != 0)
		{
			iorp->m_transfered = 0;
			iorp->m_finished = mk_lang_false;
			err = mk_sl_io_async_reader_file_iorp_construct_args(&iorp->m_data.m_read, ptr, len, &vc->m_file_pos_to_read); mk_lang_check_rereturn(err);
			err = mk_sl_io_async_reader_file_request_read(&vc->m_reader, &iorp->m_data.m_read); mk_lang_check_rereturn(err);
			tul = mk_clib_app_vc_io_block_len; mk_sl_cui_uint64_from_bi_ulong(&tu64a, &tul); mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_file_pos_to_read, &tu64a);
			++vc->m_idx_rr;
			*did = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_read(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_pt iorp;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_rr - vc->m_idx_rf;
	if(cnt != 0)
	{
		idx = vc->m_idx_rf % cap;
		iorp = &vc->m_iorps[idx];
		if(iorp->m_finished)
		{
			mk_lang_check_return(iorp->m_transfered % mk_lib_vc_block_len == 0);
			++vc->m_idx_rf;
			*did = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_request_decrypt(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_pt iorp;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint8_pt buf;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_clib_app_vc_task_t tasks[mk_clib_app_vc_io_block_len / mk_lib_vc_block_len];
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t success;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_rf - vc->m_idx_dr;
	if(cnt != 0)
	{
		idx = vc->m_idx_dr % cap;
		iorp = &vc->m_iorps[idx];
		mk_sl_cui_uint64_sub3_wrap_cid_cod(&vc->m_block_id_max, &vc->m_block_id_to_decrypt, &ta);
		mk_sl_cui_uint64_shr3(&ta, 32, &tb);
		if(mk_sl_cui_uint64_is_zero(&tb))
		{
			mk_sl_cui_uint64_to_bi_ulong(&ta, &tul);
		}
		else
		{
			tul = mk_lang_limits_ulong_max;
		}
		ta = vc->m_block_id_to_decrypt;
		mk_lang_assert(iorp->m_finished);
		mk_lang_assert(iorp->m_transfered % mk_lib_vc_block_len == 0);
		err = mk_sl_io_async_reader_file_iorp_buf(&iorp->m_data.m_read, &buf); mk_lang_check_rereturn(err);
		mk_lang_assert(((mk_lang_types_uintptr_t)(buf)) % mk_lib_vc_block_len == 0);
		mk_lang_assert(((mk_lang_types_uintptr_t)(buf)) % mk_clib_app_vc_io_block_align == 0);
		n = ((mk_lang_types_sint_t)(iorp->m_transfered)) / mk_lib_vc_block_len;
		n = ((mk_lang_types_sint_t)(mk_lang_min(((mk_lang_types_ulong_t)(n)), tul)));
		if(n != 0)
		{
			for(i = 0; i != n; ++i)
			{
				mk_lang_assert(mk_sl_cui_uint64_le(&ta, &vc->m_block_id_max));
				tasks[i].m_block_id = ta;
				tasks[i].m_block = &((mk_lib_vc_block_pt)(buf))[i];
				mk_sl_cui_uint64_inc1(&ta);
			}
			err = mk_clib_app_vc_mtring_rw_try_push_back_many(&vc->m_decrypt_submit, &tasks[0], n, &success); mk_lang_check_rereturn(err);
			if(success)
			{
				vc->m_block_id_to_decrypt = ta;
				++vc->m_idx_dr;
				*did = mk_lang_true;
			}
		}
	}
	return 0;
#else
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_pt iorp;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint8_pt buf;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_vc_block_pt block;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_rf - vc->m_idx_dr;
	if(cnt != 0)
	{
		idx = vc->m_idx_dr % cap;
		iorp = &vc->m_iorps[idx];
		mk_sl_cui_uint64_sub3_wrap_cid_cod(&vc->m_block_id_max, &vc->m_block_id_to_decrypt, &ta);
		mk_sl_cui_uint64_shr3(&ta, 32, &tb);
		if(mk_sl_cui_uint64_is_zero(&tb))
		{
			mk_sl_cui_uint64_to_bi_ulong(&ta, &tul);
		}
		else
		{
			tul = mk_lang_limits_ulong_max;
		}
		ta = vc->m_block_id_to_decrypt;
		mk_lang_assert(iorp->m_finished);
		mk_lang_assert(iorp->m_transfered % mk_lib_vc_block_len == 0);
		err = mk_sl_io_async_reader_file_iorp_buf(&iorp->m_data.m_read, &buf); mk_lang_check_rereturn(err);
		mk_lang_assert(((mk_lang_types_uintptr_t)(buf)) % mk_lib_vc_block_len == 0);
		mk_lang_assert(((mk_lang_types_uintptr_t)(buf)) % mk_clib_app_vc_io_block_align == 0);
		n = ((mk_lang_types_sint_t)(iorp->m_transfered)) / mk_lib_vc_block_len;
		n = ((mk_lang_types_sint_t)(mk_lang_min(((mk_lang_types_ulong_t)(n)), tul)));
		if(n != 0)
		{
			for(i = 0; i != n; ++i)
			{
				mk_lang_assert(mk_sl_cui_uint64_le(&ta, &vc->m_block_id_max));
				block = &((mk_lib_vc_block_pt)(buf))[i];
				mk_lib_vc_seq_decrypt_block(vc->m_seqid, &vc->m_schedules, &ta, block, block);
				mk_sl_cui_uint64_inc1(&ta);
			}
			vc->m_block_id_to_decrypt = ta;
			++vc->m_idx_dr;
			++vc->m_idx_df;
			*did = mk_lang_true;
		}
	}
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_decrypt(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_usize_t count;
	mk_clib_app_vc_task_t tasks[mk_clib_app_vc_io_block_len / mk_lib_vc_block_len];
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	count = ((mk_lang_types_usize_t)(mk_lang_countof(tasks)));
	err = mk_clib_app_vc_mtring_rw_try_pop_front_few_copy(&vc->m_decrypt_receieve, &tasks[0], &count); mk_lang_check_rereturn(err);
	if(count != 0)
	{
		mk_clib_app_vc_fixed_vector_rw_push_back_many(&vc->m_finished, &tasks[0], count);
		*did = mk_lang_true;
	}
	return 0;
#else
	mk_lang_assert(vc);
	mk_lang_assert(did);

	((mk_lang_types_void_t)(vc));
	((mk_lang_types_void_t)(did));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_received(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_sl_io_async_reader_file_iorp_pt iorpa;
	mk_clib_app_vc_task_pt dst;
	mk_lang_types_sint_t found;
	mk_lang_types_sint_t target_count;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t block_id_min;
	mk_sl_cui_uint64_t block_id_max;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t j;
	mk_clib_app_vc_task_pt task;
	mk_clib_app_vc_task_t first;
	mk_sl_io_async_reader_file_iorp_pt iorpb;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_dr - vc->m_idx_df;
	if(cnt != 0)
	{
		idx = vc->m_idx_df % cap;
		iorpa = &vc->m_iorps[idx].m_data.m_read;
		dst = mk_lang_null;
		found = 0;
		target_count = mk_clib_app_vc_io_block_len / mk_lib_vc_block_len;
		ta = vc->m_block_id_to_write;
		tb = vc->m_block_id_max;
		mk_sl_cui_uint64_from_bi_sint(&tc, &target_count);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&tc, &ta);
		if(!mk_sl_cui_uint64_gt(&tc, &tb))
		{
			tb = tc;
		}
		else
		{
			mk_sl_cui_uint64_sub2_wrap_cid_cod(&tc, &tb);
			mk_sl_cui_uint64_to_bi_sint(&tc, &target_count);
		}
		block_id_min = ta;
		block_id_max = tb;
		count = ((mk_lang_types_sint_t)(mk_clib_app_vc_fixed_vector_rw_size(&vc->m_finished)));
		if(count >= target_count)
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				j = (n - 1) - i;
				task = mk_clib_app_vc_fixed_vector_rw_at(&vc->m_finished, j);
				if(mk_sl_cui_uint64_ge(&task->m_block_id, &block_id_min) && mk_sl_cui_uint64_lt(&task->m_block_id, &block_id_max))
				{
					if(mk_sl_cui_uint64_eq(&task->m_block_id, &block_id_min))
					{
						first = *task;
					}
					++found;
					if(dst)
					{
						mk_clib_app_vc_task_swap_fn(task, dst);
						--dst;
					}
					if(found == target_count)
					{
						mk_lang_assert(first.m_block);
						mk_lang_assert(((mk_lang_types_uintptr_t)(first.m_block)) % mk_clib_app_vc_io_block_align == 0);
						mk_lang_assert((((mk_sl_cui_uint8_pct)(first.m_block)) - &vc->m_buf[0]) % mk_clib_app_vc_io_block_len == 0);
						idx = ((mk_lang_types_uint_t)((((mk_sl_cui_uint8_pct)(first.m_block)) - &vc->m_buf[0]) / mk_clib_app_vc_io_block_len));
						mk_clib_app_vc_fixed_vector_rw_pop_back_many(&vc->m_finished, target_count);
						iorpb = &vc->m_iorps[idx].m_data.m_read;
						mk_lang_assert(iorpb == iorpa);
						mk_sl_cui_uint64_from_bi_sint(&ta, &target_count); mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_block_id_to_write, &ta);
						++vc->m_idx_df;
						*did = mk_lang_true;
						break;
					}
				}
				else
				{
					if(!dst)
					{
						dst = task;
					}
				}
			}
		}
	}
	return 0;
#else
	mk_lang_assert(vc);
	mk_lang_assert(did);

	((mk_lang_types_void_t)(vc));
	((mk_lang_types_void_t)(did));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_request_write(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cap;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_t iorpr;
	mk_clib_app_vc_iorp_pt iorp;
	mk_sl_cui_uint64_t tu64;
	mk_clib_app_vc_iorp_t iorpw;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t tul;
	mk_lang_types_usize_t transfered;
	mk_lang_types_usize_t len;
	mk_sl_cui_uint8_pt buf;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_df - vc->m_idx_wr;
	if(cnt != 0)
	{
		idx = vc->m_idx_wr % cap;
		iorp = &vc->m_iorps[idx];
		iorpr = *iorp;
		mk_lang_assert((err = mk_sl_io_async_reader_file_iorp_buf(&iorpr.m_data.m_read, &buf), err == 0 && buf));
		mk_lang_assert((err = mk_sl_io_async_reader_file_iorp_buf(&iorpr.m_data.m_read, &buf), err == 0 && ((mk_lang_types_uintptr_t)(buf)) % mk_lang_alignof(mk_lib_vc_block_t) == 0));
		mk_lang_assert((err = mk_sl_io_async_reader_file_iorp_buf(&iorpr.m_data.m_read, &buf), err == 0 && ((mk_lang_types_uintptr_t)(buf)) % mk_lib_vc_block_len == 0));
		mk_lang_assert((err = mk_sl_io_async_reader_file_iorp_buf(&iorpr.m_data.m_read, &buf), err == 0 && ((mk_lang_types_uintptr_t)(buf)) % mk_clib_app_vc_io_block_len == 0));
		mk_lang_assert((err = mk_sl_io_async_reader_file_iorp_len(&iorpr.m_data.m_read, &len), err == 0 && len == mk_clib_app_vc_io_block_len));
		mk_lang_assert(iorpr.m_finished);
		mk_lang_assert(iorpr.m_transfered % mk_lib_vc_block_len == 0);
		err = mk_sl_io_async_reader_file_iorp_buf(&iorpr.m_data.m_read, &buf); mk_lang_check_rereturn(err);
		transfered = iorpr.m_transfered;
		err = mk_sl_io_async_writer_file_iorp_construct_args(&iorpw.m_data.m_write, buf, transfered, &vc->m_file_pos_to_write); mk_lang_check_rereturn(err);
		iorpw.m_finished = mk_lang_false;
		iorpw.m_transfered = 0;
		*iorp = iorpw;
		err = mk_sl_io_async_writer_file_request_write(&vc->m_writer, &iorp->m_data.m_write); mk_lang_check_rereturn(err);
		tul = ((mk_lang_types_ulong_t)(transfered)); mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul); mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_file_pos_to_write, &tu64);
		++vc->m_idx_wr;
		*did = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_write(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_usize_t len;
	mk_lang_types_uint_t cap;
	mk_lang_types_sint_t err;
	mk_lang_types_uint_t cnt;
	mk_lang_types_uint_t idx;
	mk_clib_app_vc_iorp_pt iorp;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint64_t tu64;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cap = ((mk_lang_types_uint_t)(mk_lang_countof(vc->m_iorps)));
	cnt = vc->m_idx_wr - vc->m_idx_wf;
	if(cnt != 0)
	{
		idx = vc->m_idx_wf % cap;
		iorp = &vc->m_iorps[idx];
		if(iorp->m_finished)
		{
			err = mk_sl_io_async_writer_file_iorp_len(&iorp->m_data.m_write, &len); mk_lang_check_rereturn(err);
			mk_lang_check_return(iorp->m_transfered == len);
			tui = ((mk_lang_types_uint_t)(iorp->m_transfered));
			mk_sl_cui_uint64_from_bi_uint(&tu64, &tui);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_file_pos_written, &tu64);
			++vc->m_idx_wf;
			*did = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_clib_app_vc_iorp_pt mk_clib_app_vc_iocpr_to_iorp(mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_usize_t offset;
	mk_clib_app_vc_iorp_pt rp;

	mk_lang_assert(iorp);

	offset = mk_lang_offsetof(mk_clib_app_vc_iorp_t, m_data);
	rp = ((mk_clib_app_vc_iorp_pt)(((mk_lang_types_uchar_pt)(iorp)) - offset));
	return rp;
}

mk_lang_nodiscard static mk_lang_inline mk_clib_app_vc_iorp_pt mk_clib_app_vc_iocpw_to_iorp(mk_sl_io_async_writer_file_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_usize_t offset;
	mk_clib_app_vc_iorp_pt rp;

	mk_lang_assert(iorp);

	offset = mk_lang_offsetof(mk_clib_app_vc_iorp_t, m_data);
	rp = ((mk_clib_app_vc_iorp_pt)(((mk_lang_types_uchar_pt)(iorp)) - offset));
	return rp;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_one_iorp(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t key;
	mk_lang_types_usize_t transfered;
	mk_lang_types_usize_t len;
	mk_lang_types_bool_t has;
	mk_lang_types_bool_t failed;
	mk_sl_io_async_iocp_iorp_t iocpiorp;
	mk_sl_io_async_reader_file_iorp_pt iorpr;
	mk_sl_io_async_writer_file_iorp_pt iorpw;
	mk_clib_app_vc_iorp_pt iorp;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	err = mk_sl_io_async_iocp_peek(&vc->m_iocp, &iocpiorp); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_iocp_iorp_has(&iocpiorp, &has); mk_lang_check_rereturn(err);
	if(has)
	{
		err = mk_sl_io_async_iocp_iorp_failed(&iocpiorp, &failed); mk_lang_check_rereturn(err); mk_lang_check_return(!failed);
		err = mk_sl_io_async_iocp_iorp_key(&iocpiorp, &key); mk_lang_check_rereturn(err);
		mk_lang_check_return(key == mk_clib_app_vc_iocp_idx_reader || key == mk_clib_app_vc_iocp_idx_writer);
		if(key == mk_clib_app_vc_iocp_idx_reader)
		{
			err = mk_sl_io_async_iocp_iorp_r(&iocpiorp, &iorpr); mk_lang_check_rereturn(err);
			err = mk_sl_io_async_iocp_iorp_transfered(&iocpiorp, &transfered); mk_lang_check_rereturn(err);
			err = mk_sl_io_async_reader_file_iorp_len(iorpr, &len); mk_lang_check_rereturn(err);
			mk_lang_check_return(transfered == len);
			iorp = mk_clib_app_vc_iocpr_to_iorp(iorpr);
			iorp->m_transfered = transfered;
			iorp->m_finished = mk_lang_true;
			*did = mk_lang_true;
		}
		else if(key == mk_clib_app_vc_iocp_idx_writer)
		{
			err = mk_sl_io_async_iocp_iorp_w(&iocpiorp, &iorpw); mk_lang_check_rereturn(err);
			err = mk_sl_io_async_iocp_iorp_transfered(&iocpiorp, &transfered); mk_lang_check_rereturn(err);
			err = mk_sl_io_async_writer_file_iorp_len(iorpw, &len); mk_lang_check_rereturn(err);
			mk_lang_check_return(transfered == len);
			iorp = mk_clib_app_vc_iocpw_to_iorp(iorpw);
			iorp->m_transfered = transfered;
			iorp->m_finished = mk_lang_true;
			*did = mk_lang_true;
		}
		else
		{
			mk_lang_assert(mk_lang_false);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_iorp_r(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cnt = vc->m_idx_rr - vc->m_idx_rf;
	if(cnt != 0)
	{
		err = mk_clib_app_vc_collect_one_iorp(vc, did); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_iorp_w(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cnt = vc->m_idx_wr - vc->m_idx_wf;
	if(cnt != 0)
	{
		err = mk_clib_app_vc_collect_one_iorp(vc, did); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_collect_iorp(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const dyd) mk_lang_noexcept
{
	mk_lang_types_bool_t did;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(dyd);

	did = mk_lang_false;
	if(!did){ err = mk_clib_app_vc_collect_iorp_r(vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_iorp_w(vc, &did); mk_lang_check_rereturn(err); }
	if(did)
	{
		*dyd = did;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_wait_one_iorp(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_async_iocp_iorp_t iocpiorp;
	mk_lang_types_bool_t has;
	mk_lang_types_bool_t failed;
	mk_lang_types_usize_t key;
	mk_sl_io_async_reader_file_iorp_pt iorpr;
	mk_clib_app_vc_iorp_pt iorp;
	mk_lang_types_usize_t transfered;
	mk_lang_types_usize_t len;
	mk_sl_io_async_writer_file_iorp_pt iorpw;

	mk_lang_assert(vc);

	#if mk_sl_io_async_thread_needs
	err = mk_sl_io_async_thread_poke(&vc->m_io_async_thread); mk_lang_check_rereturn(err);
	#endif
	err = mk_sl_io_async_iocp_wait(&vc->m_iocp, &iocpiorp); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_iocp_iorp_has(&iocpiorp, &has); mk_lang_check_rereturn(err); mk_lang_assert(has);
	err = mk_sl_io_async_iocp_iorp_failed(&iocpiorp, &failed); mk_lang_check_rereturn(err); mk_lang_check_return(!failed);
	err = mk_sl_io_async_iocp_iorp_key(&iocpiorp, &key); mk_lang_check_rereturn(err);
	mk_lang_check_return(key == mk_clib_app_vc_iocp_idx_reader || key == mk_clib_app_vc_iocp_idx_writer);
	if(key == mk_clib_app_vc_iocp_idx_reader)
	{
		err = mk_sl_io_async_iocp_iorp_r(&iocpiorp, &iorpr); mk_lang_check_rereturn(err); mk_lang_assert(iorpr);
		iorp = mk_clib_app_vc_iocpr_to_iorp(iorpr);
		err = mk_sl_io_async_iocp_iorp_transfered(&iocpiorp, &transfered); mk_lang_check_rereturn(err);
		err = mk_sl_io_async_reader_file_iorp_len(iorpr, &len); mk_lang_check_rereturn(err);
		mk_lang_check_return(transfered == len);
		iorp->m_transfered = transfered;
		iorp->m_finished = mk_lang_true;
	}
	else if(key == mk_clib_app_vc_iocp_idx_writer)
	{
		err = mk_sl_io_async_iocp_iorp_w(&iocpiorp, &iorpw); mk_lang_check_rereturn(err); mk_lang_assert(iorpw);
		iorp = mk_clib_app_vc_iocpw_to_iorp(iorpw);
		err = mk_sl_io_async_iocp_iorp_transfered(&iocpiorp, &transfered); mk_lang_check_rereturn(err);
		err = mk_sl_io_async_writer_file_iorp_len(iorpw, &len); mk_lang_check_rereturn(err);
		mk_lang_check_return(transfered == len);
		iorp->m_transfered = transfered;
		iorp->m_finished = mk_lang_true;
	}
	else
	{
		mk_lang_assert(mk_lang_false);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_wait_iorp_r(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cnt = vc->m_idx_rr - vc->m_idx_rf;
	if(cnt != 0)
	{
		err = mk_clib_app_vc_wait_one_iorp(vc); mk_lang_check_rereturn(err);
		*did = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_wait_iorp_w(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_uint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cnt = vc->m_idx_wr - vc->m_idx_wf;
	if(cnt != 0)
	{
		err = mk_clib_app_vc_wait_one_iorp(vc); mk_lang_check_rereturn(err);
		*did = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_wait_iorp(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const dyd) mk_lang_noexcept
{
	mk_lang_types_bool_t did;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(dyd);

	did = mk_lang_false;
	if(!did){ err = mk_clib_app_vc_wait_iorp_r(vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_wait_iorp_w(vc, &did); mk_lang_check_rereturn(err); }
	if(did)
	{
		*dyd = did;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_wait_crypt(mk_clib_app_vc_pt const vc, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_uint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(did);

	cnt = vc->m_idx_dr - vc->m_idx_df;
	if(cnt != 0)
	{
		err = mk_clib_app_vc_mtring_ro_wait_til_non_empty(&vc->m_decrypt_receieve); mk_lang_check_rereturn(err);
		*did = mk_lang_true;
	}
	return 0;
#else
	mk_lang_assert(vc);
	mk_lang_assert(did);

	((mk_lang_types_void_t)(vc));
	((mk_lang_types_void_t)(did));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_round(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_bool_t did;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	did = mk_lang_false;
	if(!did){ err = mk_clib_app_vc_request_read    (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_read    (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_request_decrypt (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_decrypt (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_received(vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_request_write   (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_write   (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_collect_iorp    (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_wait_crypt      (vc, &did); mk_lang_check_rereturn(err); }
	if(!did){ err = mk_clib_app_vc_wait_iorp       (vc, &did); mk_lang_check_rereturn(err); }
	mk_lang_assert(did);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_decrypt_impl_4(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_static_assert(mk_clib_app_vc_io_blocks_len_real % mk_clib_app_vc_io_block_len == 0);
	mk_lang_static_assert(mk_lang_pow2_is(mk_clib_app_vc_io_blocks_count));

	mk_lang_assert(vc);

	while(!mk_sl_cui_uint64_eq(&vc->m_file_pos_written, &vc->m_vol_len))
	{
		err = mk_clib_app_vc_round(vc); mk_lang_check_rereturn(err);
	}
	return 0;
}

#if mk_lib_mt_thread_has
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_threads_job_impl_1(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_vc_task_t task;
	mk_lang_types_bool_t end;

	mk_lang_assert(vc);

	for(;;)
	{
		err = mk_clib_app_vc_mtring_rw_pop_front_copy(&vc->m_decrypt_submit, &task); mk_lang_check_rereturn(err);
		end = mk_sl_cui_uint64_is_zero(&task.m_block_id) && task.m_block == mk_lang_null;
		if(!end)
		{
			mk_lib_vc_seq_decrypt_block(vc->m_seqid, &vc->m_schedules, &task.m_block_id, task.m_block, task.m_block);
			err = mk_clib_app_vc_mtring_rw_push_back_one(&vc->m_decrypt_receieve, &task); mk_lang_check_rereturn(err);
		}
		if(end)
		{
			break;
		}
	}
	return 0;
}
#endif

#if mk_lib_mt_thread_has
mk_lang_nodiscard static mk_lang_types_sint_t mk_clib_app_vc_threads_job(mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_clib_app_vc_pt vc;
	mk_lang_types_sint_t err;

	mk_lang_assert(context);

	vc = ((mk_clib_app_vc_pt)(context));
	err = mk_clib_app_vc_threads_job_impl_1(vc); mk_lang_check_rereturn(err);
	return 0;
}
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_threads_init(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t cnt;
	mk_lang_types_sint_t err;

	mk_lang_static_assert((mk_clib_app_vc_io_blocks_len_real / mk_lib_vc_block_len) >= mk_clib_app_vc_max_tasks);

	mk_lang_assert(vc);

	cnt = mk_lang_countof(vc->m_threads);
	err = mk_lib_mt_thread_create_all(&vc->m_threads[0], &cnt, &mk_clib_app_vc_threads_job, vc); mk_lang_check_rereturn(err);
	vc->m_threads_count = cnt;
	return 0;
#else
	mk_lang_assert(vc);

	((mk_lang_types_void_t)(vc));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_threads_finish(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_clib_app_vc_task_t task;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	mk_sl_cui_uint64_set_zero(&task.m_block_id);
	task.m_block = mk_lang_null;
	n = vc->m_threads_count;
	for(i = 0; i != n; ++i)
	{
		err = mk_clib_app_vc_mtring_rw_push_back_one(&vc->m_decrypt_submit, &task); mk_lang_check_rereturn(err);
	}
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_join(&vc->m_threads[i]); mk_lang_check_rereturn(err);
		err = mk_lib_mt_thread_destroy(&vc->m_threads[i]); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(vc);

	((mk_lang_types_void_t)(vc));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_decrypt_impl_3(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_threads_init(vc); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_decrypt_impl_4(vc);
	err = mk_clib_app_vc_threads_finish(vc); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_decrypt_impl_2(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_mtring_rw_construct(&vc->m_decrypt_receieve); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_decrypt_impl_3(vc);
	err = mk_clib_app_vc_mtring_rw_destroy(&vc->m_decrypt_receieve); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
#else
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_decrypt_impl_3(vc); mk_lang_check_rereturn(err);
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_decrypt_impl_1(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_lib_mt_thread_has
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_mtring_rw_construct(&vc->m_decrypt_submit); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_decrypt_impl_2(vc);
	err = mk_clib_app_vc_mtring_rw_destroy(&vc->m_decrypt_submit); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
#else
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_decrypt_impl_2(vc); mk_lang_check_rereturn(err);
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_decrypt(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	vc->m_idx_rr = 0;
	vc->m_idx_rf = 0;
	vc->m_idx_dr = 0;
	vc->m_idx_df = 0;
	vc->m_idx_wr = 0;
	vc->m_idx_wf = 0;
	#if mk_lib_mt_thread_has
	mk_clib_app_vc_fixed_vector_rw_construct(&vc->m_finished);
	#endif
	err = mk_clib_app_vc_decrypt_impl_1(vc); mk_lang_check_rereturn(err);
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_chs(mk_lang_types_ulong_t const blocks, mk_lang_types_ulong_pt const out_c, mk_lang_types_ulong_pt const out_h, mk_lang_types_ulong_pt const out_s) mk_lang_noexcept
{
	mk_lang_types_ulong_t b;
	mk_lang_types_ulong_t s;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t ch;
	mk_lang_types_ulong_t c;

	mk_lang_assert(out_c);
	mk_lang_assert(out_h);
	mk_lang_assert(out_s);
	mk_lang_assert(out_c != out_h);
	mk_lang_assert(out_c != out_s);
	mk_lang_assert(out_h != out_s);

	b = blocks;
	b = mk_lang_min(b, 65535ul * 16ul * 255ul);
	if(b >= 65535ul * 16ul * 63ul)
	{
		s = 255ul;
		h = 16ul;
		ch = b / s;
	}
	else
	{
		s = 17ul;
		ch = b / s;
		h = (ch + 1023ul) / 1024ul;
		h = mk_lang_max(h, 4);
		if(ch >= (h * 1024ul) || h > 16ul)
		{
			s = 31ul;
			h = 16ul;
			ch = b / s;
		}
		if(ch >= (h * 1024ul))
		{
			s = 63ul;
			h = 16ul;
			ch = b / s;
		}
	}
	c = ch / h;
	*out_c = c;
	*out_h = h;
	*out_s = s;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_checksum(mk_lib_vc_block_pt const block) mk_lang_noexcept
{
	mk_sl_cui_uint32_t checksum;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(block);

	mk_sl_cui_uint32_set_zero(&checksum);
	n = mk_lib_vc_block_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&block->m_data.m_uint8s[i], &tuc);
		mk_sl_cui_uint32_from_bi_uchar(&tu32, &tuc);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&checksum, &tu32);
	}
	mk_sl_cui_uint32_not1(&checksum);
	mk_sl_uint_32_to_8_be(&checksum, &block->m_data.m_uint8s[64]);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_generate(mk_lib_vc_block_pt const block, mk_sl_cui_uint64_pct const disk_len) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_ulong_t blocks;
	mk_lang_types_ulong_t c;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t s;
	mk_lang_types_sint_t ptr;
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ushort_t tus;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(block);
	mk_lang_assert(disk_len);
	mk_lang_assert((mk_sl_cui_uint64_shl3(disk_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(disk_len, 9 + 32, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */

	mk_sl_cui_uint64_shr3(disk_len, 9, &tu64);
	mk_sl_cui_uint64_to_bi_ulong(&tu64, &blocks);
	mk_clib_app_vc_vhd_footer_chs(blocks, &c, &h, &s);
	ptr = 0;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'o'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'n'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'e'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 't'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'x'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* cookie */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* features */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* file format version */
	mk_sl_cui_uint64_set_max(&tu64); mk_sl_uint_64_to_8_be(&tu64, &block->m_data.m_uint8s[ptr]); ptr += 8; /* data offset */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* time stamp */
	tpc = 'v'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'p'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = ' '; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator application */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* creator version */
	tpc = 'W'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = '2'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'k'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator host OS */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* original size */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* current size */
	tus = ((mk_lang_types_ushort_t)(c)); mk_sl_cui_uint16_from_bi_ushort(&tu16, &tus); mk_sl_uint_16_to_8_be(&tu16, &block->m_data.m_uint8s[ptr]); ptr += 2; /* cylinders */
	tuc = ((mk_lang_types_uchar_t)(h)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* heads */
	tuc = ((mk_lang_types_uchar_t)(s)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* sectors */ /* disk geometry */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* disk type */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* checksum */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* unique id */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* saved state */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memse_tu8_fn(&block->m_data.m_uint8s[ptr], &tu8, mk_lib_vc_block_len - ptr); /* reserved */
	mk_clib_app_vc_vhd_footer_checksum(block);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_vhd_write_footer(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint64_t tu64;
	mk_sl_cui_uint64_t disk_len;
	mk_sl_cui_uint8_pt buf;
	mk_lib_vc_block_pt block;
	mk_clib_app_vc_iorp_pt iorp;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	tul = mk_clib_app_vc_vhd_volume_align; mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
	mk_sl_cui_uint64_add3_wrap_cid_cod(&vc->m_vol_len, &tu64, &disk_len);
	buf = &vc->m_buf[0];
	block = ((mk_lib_vc_block_pt)(buf));
	mk_clib_app_vc_vhd_footer_generate(block, &disk_len);
	iorp = &vc->m_iorps[0];
	err = mk_sl_io_async_writer_file_iorp_construct_args(&iorp->m_data.m_write, buf, mk_lib_vc_block_len, &vc->m_file_pos_to_write); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_writer_file_request_write(&vc->m_writer, &iorp->m_data.m_write); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_wait_one_iorp(vc); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_writer_file_iorp_destroy(&iorp->m_data.m_write); mk_lang_check_rereturn(err);
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_chs_from_bytes(mk_sl_cui_uint32_pct const bytes, mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pt const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t blocks;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32a;
	mk_sl_cui_uint32_t tu32b;
	mk_sl_cui_uint32_t cylinders;
	mk_sl_cui_uint32_t heads;
	mk_sl_cui_uint32_t sectors;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t tu8a;
	mk_sl_cui_uint8_t tu8b;

	mk_lang_assert(bytes);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert((mk_sl_cui_uint32_shl3(bytes, 32 - 9, &blocks), mk_sl_cui_uint32_is_zero(&blocks)));
	mk_lang_assert((mk_sl_cui_uint32_shr3(bytes, 9, &blocks), mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), mk_lang_pow2_is(tul)));

	mk_sl_cui_uint32_shr3(bytes, 9, &blocks);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &tu32b);
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&tu32b, &tu32a, &cylinders);
	mk_lang_assert((mk_sl_cui_uint32_shr3(&cylinders, 10, &tu32a), mk_sl_cui_uint32_is_zero(&tu32a)));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&cylinders, &tu32a, &tu32b);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&tu32b, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub2_wrap_cid_cod(&blocks, &tu32b);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), tul < 255 * 63));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &heads);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&heads, &tul), tul < 255));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&heads, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub3_wrap_cid_cod(&blocks, &tu32b, &sectors);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&sectors, &tul), tul < 63));
	mk_sl_cui_uint32_inc1(&sectors);
	mk_sl_cui_uint32_to_bi_uchar(&heads, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(a, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(c, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&sectors, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8a, &tuc);
	mk_sl_cui_uint32_shr2(&cylinders, 8);
	mk_sl_cui_uint32_shl2(&cylinders, 6);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8b, &tuc);
	mk_sl_cui_uint8_or3(&tu8a, &tu8b, b);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_mbr_header_generate(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t ptr;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t align;
	mk_sl_cui_uint8_t chs[3];
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_static_assert(mk_lang_pow2_is(mk_clib_app_vc_vhd_volume_align));

	mk_lang_assert(vc);
	mk_lang_assert((mk_sl_cui_uint64_shl3(&vc->m_vol_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(&vc->m_vol_len, 32 + 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */

	ptr = 0;
	tul = mk_clib_app_vc_vhd_volume_align; mk_sl_cui_uint32_from_bi_ulong(&align, &tul);
	mk_clib_app_vc_chs_from_bytes(&align, &chs[0], &chs[1], &chs[2]);
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memse_tu8_fn(&vc->m_buf[ptr], &tu8, 446); ptr += 446; /* bootstrap code */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* status or physical drive */
	vc->m_buf[ptr++] = chs[0]; /* h */
	vc->m_buf[ptr++] = chs[1]; /* cs */
	vc->m_buf[ptr++] = chs[2]; /* c */
	tuc = 0x06; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* partition type */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* h */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* cs */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* c */
	mk_sl_cui_uint32_shr3(&align, 9, &tu32); mk_sl_uint_32_to_8_le(&tu32, &vc->m_buf[ptr]); ptr += 4; /* partition start lba */
	mk_sl_cui_uint64_shr3(&vc->m_vol_len, 9, &tu64); mk_sl_cui_uint64_to_bi_ulong(&tu64, &tul); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_le(&tu32, &vc->m_buf[ptr]); ptr += 4; /* partition len blocks */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memse_tu8_fn(&vc->m_buf[ptr], &tu8, mk_lib_vc_block_len - ptr - 2); ptr += (mk_lib_vc_block_len - ptr - 2);
	tuc = 0x55; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8;
	tuc = 0xaa; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); vc->m_buf[ptr++] = tu8; /* boot signature */
	mk_lang_assert(ptr == mk_lib_vc_block_len);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_vhd_write_header_and_align(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_static_assert(mk_clib_app_vc_vhd_volume_align >= mk_lib_vc_block_len);
	mk_lang_static_assert(mk_clib_app_vc_vhd_volume_align % mk_clib_app_vc_io_block_len == 0);
	mk_lang_static_assert(mk_clib_app_vc_vhd_volume_align / mk_clib_app_vc_io_block_len <= mk_clib_app_vc_io_blocks_count);
	mk_lang_static_assert(mk_clib_app_vc_vhd_volume_align <= mk_clib_app_vc_io_blocks_len_real);

	mk_lang_assert(vc);

	mk_clib_app_vc_vhd_mbr_header_generate(vc);
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_clib_app_vc_memse_tu8_fn(&vc->m_buf[mk_lib_vc_block_len], &tu8, mk_clib_app_vc_io_block_len - mk_lib_vc_block_len);
	err = mk_sl_io_async_writer_file_iorp_construct_args(&vc->m_iorps[0].m_data.m_write, &vc->m_buf[0], mk_lang_min(mk_clib_app_vc_io_block_len, mk_clib_app_vc_vhd_volume_align), &vc->m_file_pos_to_write); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_writer_file_request_write(&vc->m_writer, &vc->m_iorps[0].m_data.m_write); mk_lang_check_rereturn(err);
	tul = mk_lang_min(mk_clib_app_vc_io_block_len, mk_clib_app_vc_vhd_volume_align); mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_file_pos_to_write, &tu64);
	tul = mk_clib_app_vc_io_block_len; mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
	mk_clib_app_vc_memse_tu8_fn(&vc->m_buf[mk_clib_app_vc_io_block_len], &tu8, mk_lib_vc_block_len);
	n = mk_clib_app_vc_vhd_volume_align / mk_clib_app_vc_io_block_len;
	for(i = 1; i != n; ++i)
	{
		err = mk_sl_io_async_writer_file_iorp_construct_args(&vc->m_iorps[i].m_data.m_write, &vc->m_buf[mk_clib_app_vc_io_block_len], mk_clib_app_vc_io_block_len, &vc->m_file_pos_to_write); mk_lang_check_rereturn(err);
		err = mk_sl_io_async_writer_file_request_write(&vc->m_writer, &vc->m_iorps[i].m_data.m_write); mk_lang_check_rereturn(err);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_file_pos_to_write, &tu64);
	}
	for(i = 0; i != n; ++i)
	{
		err = mk_clib_app_vc_wait_one_iorp(vc); mk_lang_check_rereturn(err);
		err = mk_sl_io_async_writer_file_iorp_destroy(&vc->m_iorps[i].m_data.m_write); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_7(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t tul;

	mk_lang_assert(vc);

	err = mk_sl_io_async_iocp_associate_w(&vc->m_iocp, &vc->m_writer, mk_clib_app_vc_iocp_idx_writer); mk_lang_check_rereturn(err);
	tul = mk_lib_vc_offsets_volume / mk_lib_vc_block_len; mk_sl_cui_uint64_from_bi_ulong(&vc->m_block_id_to_decrypt, &tul);
	vc->m_block_id_to_write = vc->m_block_id_to_decrypt;
	mk_sl_cui_uint64_shr3(&vc->m_vol_len, 9, &vc->m_block_id_max); mk_sl_cui_uint64_add2_wrap_cid_cod(&vc->m_block_id_max, &vc->m_block_id_to_decrypt);
	tul = mk_lib_vc_offsets_volume; mk_sl_cui_uint64_from_bi_ulong(&vc->m_file_pos_to_read, &tul);
	mk_sl_cui_uint64_add3_wrap_cid_cod(&vc->m_file_pos_to_read, &vc->m_vol_len, &vc->m_file_pos_max_read);
	mk_sl_cui_uint64_set_zero(&vc->m_file_pos_to_write);
	err = mk_clib_app_vc_vhd_write_header_and_align(vc); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_decrypt(vc); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_vhd_write_footer(vc); mk_lang_check_rereturn(err);
	#if mk_sl_io_async_thread_needs
	err = mk_sl_io_async_thread_flush(&vc->m_io_async_thread); mk_lang_check_rereturn(err);
	#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_open_writer(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_io_async_thread_pt thread;
	mk_lang_types_pchar_pcpct argsn;
	mk_lang_types_pchar_pct namen;
	mk_lang_types_wchar_pcpct argsw;
	mk_lang_types_wchar_pct namew;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	#if mk_sl_io_async_thread_needs
	thread = &vc->m_io_async_thread;
	#else
	thread = mk_lang_null;
	#endif
	if(!vc->m_wide)
	{
		argsn = ((mk_lang_types_pchar_pcpct)(vc->m_argv));
		namen = argsn[4];
		err = mk_sl_io_async_writer_file_open_tx_n(&vc->m_writer, namen, &vc->m_tx, thread);
		if(err != 0)
		{
			err = mk_sl_io_async_writer_file_open_n(&vc->m_writer, namen, thread); mk_lang_check_rereturn(err);
		}
	}
	else
	{
		argsw = ((mk_lang_types_wchar_pcpct)(vc->m_argv));
		namew = argsw[4];
		err = mk_sl_io_async_writer_file_open_tx_w(&vc->m_writer, namew, &vc->m_tx, thread);
		if(err != 0)
		{
			err = mk_sl_io_async_writer_file_open_w(&vc->m_writer, namew, thread); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_6(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_open_writer(vc); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_work_impl_7(vc);
	err = mk_sl_io_async_writer_file_close(&vc->m_writer); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_password_to_utf8(mk_lang_types_bool_t const wide, mk_lang_types_pchar_pct const str_password, mk_sl_cui_uint8_pt const password_utf8_buf, mk_lang_types_sint_t const password_utf8_buf_len, mk_sl_cui_uint8_pct* const password_utf8, mk_lang_types_sint_pt const password_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(str_password);
	mk_lang_assert(password_utf8_buf);
	mk_lang_assert(password_utf8_buf_len >= 64);
	mk_lang_assert(password_utf8);
	mk_lang_assert(password_len);

	if(!wide)
	{
		mk_lang_assert(mk_clib_app_vc_strlen_pc_fn(((mk_lang_types_pchar_pct)(str_password))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
		len = ((mk_lang_types_sint_t)(mk_clib_app_vc_strlen_pc_fn(((mk_lang_types_pchar_pct)(str_password))))); mk_lang_check_return(len <= password_utf8_buf_len);
		*password_utf8 = ((mk_sl_cui_uint8_pct)(str_password));
		*password_len = len;
	}
	else
	{
		mk_lang_assert(mk_clib_app_vc_strlen_wc_fn(((mk_lang_types_wchar_pct)(str_password))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
		len = ((mk_lang_types_sint_t)(mk_clib_app_vc_strlen_wc_fn(((mk_lang_types_wchar_pct)(str_password)))));
		err = mk_lib_text_encoding_wide_to_utf8(((mk_lang_types_wchar_pct)(str_password)), len, ((mk_lang_types_pchar_pt)(password_utf8_buf)), password_utf8_buf_len, password_len); mk_lang_check_rereturn(err);
		*password_utf8 = &password_utf8_buf[0];
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_submit_header_read_and_wait(mk_clib_app_vc_pt const vc, mk_clib_app_vc_iorp_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(iorp);

	iorp->m_transfered = 0;
	iorp->m_finished = mk_lang_false;
	err = mk_sl_io_async_reader_file_request_read(&vc->m_reader, &iorp->m_data.m_read); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_wait_one_iorp(vc); mk_lang_check_rereturn(err);
	mk_lang_check_return(iorp->m_finished);
	err = mk_sl_io_async_reader_file_iorp_len(&iorp->m_data.m_read, &len); mk_lang_check_rereturn(err); mk_lang_check_return(iorp->m_transfered == len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_header(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_clib_app_vc_iorp_pt iorp;
	mk_sl_cui_uint64_t pos;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;
	mk_lib_vc_salt_pct salt;
	mk_lib_vc_block_pt block;
	mk_lib_vc_block_pt decrypted;
	mk_sl_cui_uint8_pt password_utf8_buf;
	mk_lang_types_pchar_pct str_password;
	mk_lang_types_pchar_pct str_pim;
	mk_sl_cui_uint8_pct password_utf8;
	mk_lang_types_sint_t password_len;
	mk_lang_types_ulong_t cost;

	mk_lang_assert(vc);

	vc->m_buf = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align_ptr(&vc->m_buffer[0], mk_clib_app_vc_io_block_align)));
	ptr = &vc->m_buf[0] + mk_lib_vc_salt_len;
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align_ptr(ptr, mk_lib_vc_block_len)));
	ptr = ptr - mk_lib_vc_salt_len;
	iorp = &vc->m_iorps[0];
	mk_sl_cui_uint64_set_zero(&pos);
	err = mk_sl_io_async_reader_file_iorp_construct_args(&iorp->m_data.m_read, ptr, mk_lib_vc_block_len, &pos); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_submit_header_read_and_wait(vc, iorp);
	err = mk_sl_io_async_reader_file_iorp_destroy(&iorp->m_data.m_read); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	salt = ((mk_lib_vc_salt_pct)(ptr));
	ptr = ptr + mk_lib_vc_salt_len;
	mk_lang_assert(((mk_lang_types_uintptr_t)(ptr)) % mk_lib_vc_block_len == 0);
	block = ((mk_lib_vc_block_pt)(ptr));
	decrypted = &block[1];
	password_utf8_buf = ((mk_sl_cui_uint8_pt)(&block[2]));
	str_password = vc->m_argv[2];
	str_pim = vc->m_argv[3];
	err = mk_clib_app_vc_password_to_utf8(vc->m_wide, str_password, &password_utf8_buf[0], 4 * 1024, &password_utf8, &password_len); mk_lang_check_rereturn(err);
	err = mk_lib_vc_parse_cost(vc->m_wide, str_pim, &cost); mk_lang_check_rereturn(err);
	err = mk_lib_vc_try_decrypt_header(mk_lib_vc_kdfid_e_dummy, password_utf8, password_len, salt, cost, block, decrypted, &vc->m_seqid, &vc->m_schedules, &vc->m_vol_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_5(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err = mk_sl_io_async_iocp_associate_r(&vc->m_iocp, &vc->m_reader, mk_clib_app_vc_iocp_idx_reader); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_header(vc); mk_lang_check_rereturn(err);
	err = mk_clib_app_vc_work_impl_6(vc); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_close_async(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_types_sint_t err_a;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err_a = mk_sl_io_async_thread_join(&vc->m_io_async_thread);
	err_b = mk_sl_io_async_thread_destroy(&vc->m_io_async_thread);
	mk_lang_check_rereturn(err_a);
	mk_lang_check_rereturn(err_b);
	return 0;
#else
	mk_lang_assert(vc);

	((mk_lang_types_void_t)(vc));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_4(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_sl_io_async_thread_create(&vc->m_io_async_thread); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_work_impl_5(vc);
	err = mk_clib_app_vc_close_async(vc); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
#else
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_work_impl_5(vc); mk_lang_check_rereturn(err);
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_open_reader(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_sl_io_async_thread_pt thread;
	mk_lang_types_pchar_pcpct argsn;
	mk_lang_types_pchar_pct namen;
	mk_lang_types_wchar_pcpct argsw;
	mk_lang_types_wchar_pct namew;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	#if mk_sl_io_async_thread_needs
	thread = &vc->m_io_async_thread;
	#else
	thread = mk_lang_null;
	#endif
	if(!vc->m_wide)
	{
		argsn = ((mk_lang_types_pchar_pcpct)(vc->m_argv));
		namen = argsn[1];
		err = mk_sl_io_async_reader_file_open_tx_n(&vc->m_reader, namen, &vc->m_tx, thread);
		if(err != 0)
		{
			err = mk_sl_io_async_reader_file_open_n(&vc->m_reader, namen, thread); mk_lang_check_rereturn(err);
		}
	}
	else
	{
		argsw = ((mk_lang_types_wchar_pcpct)(vc->m_argv));
		namew = argsw[1];
		err = mk_sl_io_async_reader_file_open_tx_w(&vc->m_reader, namew, &vc->m_tx, thread);
		if(err != 0)
		{
			err = mk_sl_io_async_reader_file_open_w(&vc->m_reader, namew, thread); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_3(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_clib_app_vc_open_reader(vc); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_work_impl_4(vc);
	err = mk_sl_io_async_reader_file_close(&vc->m_reader); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_2(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);

	err = mk_sl_io_async_iocp_construct(&vc->m_iocp, 1); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_work_impl_3(vc);
	err = mk_sl_io_async_iocp_destroy(&vc->m_iocp); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work_impl_1(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err_b = mk_clib_app_vc_work_impl_2(vc);
	if(err_b == 0)
	{
		err = mk_sl_io_transaction_commit(&vc->m_tx); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_sl_io_transaction_abort(&vc->m_tx); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_open_tx(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	err = mk_sl_io_transaction_create(&vc->m_tx);
	if(err != 0)
	{
		err = mk_sl_io_transaction_dummy(&vc->m_tx); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_work(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_wide == mk_lang_false || vc->m_wide == mk_lang_true);
	mk_lang_assert(vc->m_argc == 5);
	mk_lang_assert(vc->m_argv);

	err = mk_clib_app_vc_open_tx(vc); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_vc_work_impl_1(vc);
	err = mk_sl_io_transaction_close(&vc->m_tx); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_readme_n(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_pchar_pcpct args;
	mk_lang_types_pchar_pct fmt;
	mk_lang_types_pchar_pct exe_name;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t buf[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_wide == mk_lang_false);

	mk_lang_check_return(vc->m_argc >= 1);
	args = ((mk_lang_types_pchar_pcpct)(vc->m_argv));
	mk_lang_check_return(args);
	mk_lang_check_return(args[0]);
	mk_lang_check_return(args[0][0] != '\0');
	fmt = "Example usage: %s <input_file> <password> <pim> <output_file>\n";
	exe_name = mk_lang_exe_name_get_n(args[0]);
	tsi = mk_lib_fmt_n_snprintf(&buf[0], mk_lang_countof(buf), fmt, exe_name); mk_lang_check_return(tsi > 0);
	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&buf[0])), tsi); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_readme_w(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_wchar_pcpct args;
	mk_lang_types_wchar_pct fmt;
	mk_lang_types_wchar_pct exe_name;
	mk_lang_types_sint_t tsi;
	mk_lang_types_wchar_t buf[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_wide == mk_lang_true);

	mk_lang_check_return(vc->m_argc >= 1);
	args = ((mk_lang_types_wchar_pcpct)(vc->m_argv));
	mk_lang_check_return(args);
	mk_lang_check_return(args[0]);
	mk_lang_check_return(args[0][0] != L'\0');
	fmt = L"Example usage: %s <input_file> <password> <pim> <output_file>\n";
	exe_name = mk_lang_exe_name_get_w(args[0]);
	tsi = mk_lib_fmt_w_snprintf(&buf[0], mk_lang_countof(buf), fmt, exe_name); mk_lang_check_return(tsi > 0);
	err = mk_sl_io_console_write_w(((mk_sl_cui_uint8_pct)(&buf[0])), tsi); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_readme(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	if(!vc->m_wide){ err = mk_clib_app_vc_readme_n(vc); mk_lang_check_rereturn(err); }
	else           { err = mk_clib_app_vc_readme_w(vc); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_validate_n(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_pchar_pcpct args;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_wide == mk_lang_false);

	mk_lang_check_return(vc->m_argc == 5);
	args = ((mk_lang_types_pchar_pcpct)(vc->m_argv));
	mk_lang_check_return(args);
	n = vc->m_argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(args[i]);
		mk_lang_check_return(args[i][0] != '\0');
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_validate_w(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_wchar_pcpct args;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(vc);
	mk_lang_assert(vc->m_wide == mk_lang_true);

	mk_lang_check_return(vc->m_argc == 5);
	args = ((mk_lang_types_wchar_pcpct)(vc->m_argv));
	mk_lang_check_return(args);
	n = vc->m_argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(args[i]);
		mk_lang_check_return(args[i][0] != L'\0');
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_validate(mk_clib_app_vc_pt const vc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);

	if(!vc->m_wide){ err = mk_clib_app_vc_validate_n(vc); mk_lang_check_rereturn(err); }
	else           { err = mk_clib_app_vc_validate_w(vc); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_run(mk_clib_app_vc_pt const vc, mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vc);
	mk_lang_assert(wide == mk_lang_false || wide == mk_lang_true);

	vc->m_wide = wide;
	vc->m_argc = argc;
	vc->m_argv = argv;
	err = mk_clib_app_vc_validate(vc);
	if(err == 0){ err = mk_clib_app_vc_work  (vc); mk_lang_check_rereturn(err); }
	else        { err = mk_clib_app_vc_readme(vc); mk_lang_check_rereturn(err); }
	return 0;
}


mk_clib_app_vc_t g_mk_clib_app_vc;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_vc_arg(mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_static_assert(mk_clib_app_vc_io_blocks_len_real % mk_lib_vc_block_len == 0);

	mk_lang_assert(wide == mk_lang_false || wide == mk_lang_true);

	mk_lang_cpuid_init();
	err = mk_clib_app_vc_run(&g_mk_clib_app_vc, wide, argc, argv); mk_lang_check_rereturn(err);
	return 0;
}
