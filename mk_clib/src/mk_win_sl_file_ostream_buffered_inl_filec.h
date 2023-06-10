#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_exception.h"
#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_max.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_memory_management.h"
#include "mk_win_kernel_synchronization.h"
#include "mk_win_sl_exception_gle.h"
#include "mk_win_sl_tdw.h"
#include "mk_win_tstring.h"


#include "mk_win_sl_file_ostream_buffered_inl_defd.h"


struct mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_s
{
	mk_win_kernel_files_overlapped_t m_overlapped;
	mk_win_base_dword_t m_submitted;
};
typedef struct mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_s mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t const mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_ct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_pt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t const* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_pct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t mk_win_base_far* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t mk_win_base_far const* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t mk_win_base_near* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_npt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t mk_win_base_near const* mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_npct;

struct mk_win_sl_file_ostream_buffered_inl_defd_state_s
{
	mk_win_base_handle_t m_file_handle;
	unsigned m_curr_idx;
	mk_win_base_dword_t m_curr_pos;
	mk_win_base_bool_t m_missing_slot;
	mk_lang_types_bool_t m_own;
};
typedef struct mk_win_sl_file_ostream_buffered_inl_defd_state_s mk_win_sl_file_ostream_buffered_inl_defd_state_t;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t const mk_win_sl_file_ostream_buffered_inl_defd_state_ct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t* mk_win_sl_file_ostream_buffered_inl_defd_state_pt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t const* mk_win_sl_file_ostream_buffered_inl_defd_state_pct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t mk_win_base_far* mk_win_sl_file_ostream_buffered_inl_defd_state_lpt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t mk_win_base_far const* mk_win_sl_file_ostream_buffered_inl_defd_state_lpct;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t mk_win_base_near* mk_win_sl_file_ostream_buffered_inl_defd_state_npt;
typedef mk_win_sl_file_ostream_buffered_inl_defd_state_t mk_win_base_near const* mk_win_sl_file_ostream_buffered_inl_defd_state_npct;


#define mk_win_sl_file_ostream_buffered_state_overlapped_size mk_lang_max(sizeof(mk_win_sl_file_ostream_buffered_inl_defd_state_t), sizeof(mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_t))


mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_private_rw_construct(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_size_t size;
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;
	int i;

	mk_lang_assert(ostream);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	size = 0;
	size += mk_win_sl_file_ostream_buffered_inl_defd_bytes;
	size += mk_win_sl_file_ostream_buffered_state_overlapped_size;
	size += sizeof(mk_win_kernel_files_overlapped_t) * mk_win_sl_file_ostream_buffered_inl_defd_count;
	ostream->m_state = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, size, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite);
	if(mk_lang_check_if_failed(ostream->m_state)) mk_lang_unlikely { mk_lang_exception_out_of_memory_make(ex, size); return; }
	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
	for(i = 0; i != mk_win_sl_file_ostream_buffered_inl_defd_count; ++i)
	{
		overlapped[i].m_overlapped.m_event = mk_win_base_null;
	}
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_private_rw_open_file_name(mk_lang_exception_pt const ex, mk_win_tstring_tchar_pct const file_name, mk_win_base_handle_pt const file_handle) mk_lang_noexcept
{
	mk_win_advapi_base_security_attributes_t sa;
	mk_win_base_handle_t fh;

	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(file_name && *file_name);
	mk_lang_assert(file_handle);

	sa.m_size = ((mk_win_base_dword_t)(sizeof(sa)));
	sa.m_security_descriptor = mk_win_base_null;
	sa.m_inheritable = mk_win_base_false;
	fh = mk_win_kernel_files_t_create_file
	(
		file_name,
		((mk_win_base_dword_t)(mk_win_advapi_base_right_generic_e_write | mk_win_advapi_base_right_generic_e_read)),
		mk_win_kernel_files_share_e_delete,
		&sa,
		mk_win_kernel_files_create_e_create_always,
		mk_win_kernel_files_attribute_e_normal | mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped,
		mk_win_base_null
	);
	mk_lang_assert(fh != mk_win_base_null);
	if(mk_lang_check_if_failed(fh != s_mk_win_base_handle_invalid)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	*file_handle = fh;
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_private_rw_submit_write_curr_and_advance(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;
	mk_win_base_bool_t reset;
	mk_win_base_void_lpt buff;
	mk_win_base_bool_t write;
	mk_win_kernel_errors_id_t err;

	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(unsigned));
	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
	mk_lang_assert(state->m_curr_pos != 0);
	if(!overlapped[state->m_curr_idx].m_overlapped.m_event)
	{
		overlapped[state->m_curr_idx].m_overlapped.m_event = mk_win_kernel_synchronization_t_create_event(mk_win_base_null, mk_win_base_true, mk_win_base_true, mk_win_base_null);
		if(mk_lang_check_if_failed(overlapped[state->m_curr_idx].m_overlapped.m_event)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	}
	reset = mk_win_kernel_synchronization_reset_event(overlapped[state->m_curr_idx].m_overlapped.m_event);
	if(mk_lang_check_if_failed(reset != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	buff = ((mk_win_base_uchar_lpt)(ostream->m_state)) + (state->m_curr_idx * mk_win_sl_file_ostream_buffered_inl_defd_size);
	overlapped[state->m_curr_idx].m_submitted = state->m_curr_pos;
	write = mk_win_kernel_files_write_file(state->m_file_handle, buff, state->m_curr_pos, mk_win_base_null, &overlapped[state->m_curr_idx].m_overlapped);
	err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
	if(mk_lang_check_if_failed((write != 0) || (err == mk_win_kernel_errors_id_e_io_pending))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	state->m_curr_idx = (state->m_curr_idx + 1) % mk_win_sl_file_ostream_buffered_inl_defd_count;
	state->m_curr_pos = 0;
	state->m_missing_slot = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_private_rw_wait_idx(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex, int const idx) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;
	mk_win_base_dword_t waited;
	mk_win_base_bool_t got;
	mk_win_base_dword_t bytes_transfered;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(idx >= 0 && idx < mk_win_sl_file_ostream_buffered_t_count);

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
	if(overlapped[idx].m_overlapped.m_event)
	{
		waited = mk_win_kernel_synchronization_wait_for_single_object(overlapped[idx].m_overlapped.m_event, mk_win_kernel_synchronization_infinite);
		if(mk_lang_check_if_failed(waited == 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		got = mk_win_kernel_synchronization_get_overlapped_result(state->m_file_handle, &overlapped[idx].m_overlapped, &bytes_transfered, mk_win_base_true);
		if(mk_lang_check_if_failed(got != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		if(mk_lang_check_if_failed(bytes_transfered == overlapped[idx].m_submitted)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; } /* todo might throw success */
	}
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_private_rw_wait_write_curr_and_prepare_curr_based_on_prev(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;
	mk_sl_cui_wtdw_t cui1;
	mk_sl_cui_wtdw_t cui2;
	mk_win_base_dword_t size;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
	mk_win_sl_file_ostream_buffered_inl_defd_private_rw_wait_idx(ostream, ex, ((int)(state->m_curr_idx))); mk_lang_exception_if_is_return(ex);
	mk_sl_cui_wtdw_from_bi_uint(&cui1, &overlapped[(state->m_curr_idx - 1) % mk_win_sl_file_ostream_buffered_inl_defd_count].m_overlapped.m_offset_hi);
	mk_sl_cui_wtdw_shl2(&cui1, 32);
	mk_sl_cui_wtdw_from_bi_uint(&cui2, &overlapped[(state->m_curr_idx - 1) % mk_win_sl_file_ostream_buffered_inl_defd_count].m_overlapped.m_offset_lo);
	mk_sl_cui_wtdw_or2(&cui1, &cui2);
	size = mk_win_sl_file_ostream_buffered_inl_defd_size;
	mk_sl_cui_wtdw_from_bi_uint(&cui2, &size);
	mk_lang_assert(!mk_sl_cui_wtdw_would_overflow_add_cc(&cui1, &cui2));
	mk_sl_cui_wtdw_add2_wrap_cid_cod(&cui1, &cui2);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped[state->m_curr_idx].m_overlapped.m_offset_lo);
	mk_sl_cui_wtdw_shr2(&cui1, 32);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped[state->m_curr_idx].m_overlapped.m_offset_hi);
	state->m_missing_slot = mk_lang_false;
}


mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_reconstruct_from_file_handle(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_win_base_handle_t const file_handle, mk_lang_types_bool_t const own) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(file_handle != mk_win_base_null && file_handle != s_mk_win_base_handle_invalid);

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
	state->m_file_handle = file_handle;
	state->m_curr_idx = 0;
	state->m_curr_pos = 0;
	state->m_missing_slot = mk_lang_false;
	state->m_own = own;
	overlapped[0].m_overlapped.m_offset_lo = 0;
	overlapped[0].m_overlapped.m_offset_hi = 0;
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_reconstruct_from_file_name(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex, mk_win_tstring_tchar_pct const file_name) mk_lang_noexcept
{
	mk_win_base_handle_t file_handle;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_file_ostream_buffered_inl_defd_private_rw_open_file_name(ex, file_name, &file_handle); mk_lang_exception_if_is_return(ex);
	mk_win_sl_file_ostream_buffered_inl_defd_rw_reconstruct_from_file_handle(ostream, file_handle, mk_lang_true);
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_construct_from_file_handle(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex, mk_win_base_handle_t const file_handle, mk_lang_types_bool_t const own) mk_lang_noexcept
{
	mk_lang_assert(ostream);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_file_ostream_buffered_inl_defd_private_rw_construct(ostream, ex); mk_lang_exception_if_is_return(ex);
	mk_win_sl_file_ostream_buffered_inl_defd_rw_reconstruct_from_file_handle(ostream, file_handle, own);
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_construct_from_file_name(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex, mk_win_tstring_tchar_pct const file_name) mk_lang_noexcept
{
	mk_win_base_handle_t file_handle;

	mk_lang_assert(ostream);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_file_ostream_buffered_inl_defd_private_rw_open_file_name(ex, file_name, &file_handle); mk_lang_exception_if_is_return(ex);
	mk_win_sl_file_ostream_buffered_inl_defd_rw_construct_from_file_handle(ostream, ex, file_handle, mk_lang_true); mk_lang_exception_if_is_return(ex);
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_submit_write(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	if(state->m_curr_pos != 0)
	{
		mk_win_sl_file_ostream_buffered_inl_defd_private_rw_submit_write_curr_and_advance(ostream, ex); mk_lang_exception_if_is_return(ex);
	}
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_close(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	int i;
	mk_win_base_bool_t closed;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	mk_win_sl_file_ostream_buffered_inl_defd_rw_submit_write(ostream, ex); mk_lang_exception_if_is_return(ex);
	for(i = 0; i != mk_win_sl_file_ostream_buffered_inl_defd_count; ++i)
	{
		mk_win_sl_file_ostream_buffered_inl_defd_private_rw_wait_idx(ostream, ex, ((int)((state->m_curr_idx + i) % mk_win_sl_file_ostream_buffered_inl_defd_count))); mk_lang_exception_if_is_return(ex);
	}
	if(state->m_own)
	{
		closed = mk_win_kernel_handle_close_handle(state->m_file_handle);
		if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		state->m_own = mk_lang_false;
	}
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_destroy(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt overlapped;
	int i;
	mk_win_base_bool_t closed;
	mk_win_base_bool_t freed;

	mk_lang_assert(ostream);

	mk_lang_exception_make_none(&ex);
	mk_win_sl_file_ostream_buffered_inl_defd_rw_close(ostream, &ex);
	if(mk_lang_exception_is(&ex)) mk_lang_unlikely { mk_lang_assert(0); /* todo? crash? */ }
	if(ostream->m_state)
	{
		state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
		overlapped = ((mk_win_sl_file_ostream_buffered_inl_defd_overlapped2_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_win_sl_file_ostream_buffered_state_overlapped_size));
		for(i = 0; i != mk_win_sl_file_ostream_buffered_inl_defd_count && overlapped[i].m_overlapped.m_event != mk_win_base_null; ++i)
		{
			closed = mk_win_kernel_handle_close_handle(overlapped[i].m_overlapped.m_event);
			if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_lang_assert(0); /* todo? crash? */ }
		}
		freed = mk_win_kernel_memory_management_virtual_free(ostream->m_state, 0, mk_win_kernel_memory_management_type_e_release);
		if(mk_lang_check_if_failed(freed != 0)) mk_lang_unlikely { mk_lang_assert(0); /* todo? crash? */ }
	}
}

mk_lang_jumbo void mk_win_sl_file_ostream_buffered_inl_defd_rw_write(mk_win_sl_file_ostream_buffered_inl_defd_pt const ostream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const source, mk_lang_types_usize_t const bytes_to_write, mk_lang_types_usize_pt const bytes_written) mk_lang_noexcept
{
	mk_win_sl_file_ostream_buffered_inl_defd_state_lpt state;
	mk_lang_types_uchar_pct src;
	mk_lang_types_usize_t remaining;
	mk_win_base_void_lpt buff;
	mk_win_base_dword_t n;

	mk_lang_assert(ostream);
	mk_lang_assert(ostream->m_state);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(bytes_written);

	state = ((mk_win_sl_file_ostream_buffered_inl_defd_state_lpt)(((mk_win_base_uchar_lpt)(ostream->m_state)) + mk_win_sl_file_ostream_buffered_inl_defd_bytes));
	*bytes_written = 0;
	src = ((mk_lang_types_uchar_pct)(source));
	remaining = bytes_to_write;
	while(remaining != 0)
	{
		if(state->m_missing_slot)
		{
			mk_win_sl_file_ostream_buffered_inl_defd_private_rw_wait_write_curr_and_prepare_curr_based_on_prev(ostream, ex); mk_lang_exception_if_is_return(ex);
		}
		buff = ((mk_win_base_uchar_lpt)(ostream->m_state)) + (state->m_curr_idx * mk_win_sl_file_ostream_buffered_inl_defd_size) + state->m_curr_pos;
		n = ((mk_win_base_dword_t)(mk_lang_min(remaining, ((mk_lang_types_usize_t)(mk_win_sl_file_ostream_buffered_inl_defd_size - state->m_curr_pos)))));
		mk_lang_memcpy(buff, src, n);
		state->m_curr_pos += n;
		remaining -= n;
		src += n;
		*bytes_written += n;
		if(state->m_curr_pos == mk_win_sl_file_ostream_buffered_inl_defd_size)
		{
			mk_win_sl_file_ostream_buffered_inl_defd_private_rw_submit_write_curr_and_advance(ostream, ex); mk_lang_exception_if_is_return(ex);
		}
	}
}


#undef mk_win_sl_file_ostream_buffered_state_overlapped_size


#include "mk_win_sl_file_ostream_buffered_inl_defu.h"


#undef mk_win_sl_file_ostream_buffered_t_name
#undef mk_win_sl_file_ostream_buffered_t_count
#undef mk_win_sl_file_ostream_buffered_t_size
