#include "mk_win_sl_file_istream_buffered_512_8.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_max.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_memory_management.h"
#include "mk_win_kernel_synchronization.h"
#include "mk_win_sl_exception_gle.h"


struct mk_win_sl_file_istream_buffered_512_8_state_s
{
	mk_win_base_handle_t m_handle;
	unsigned m_curr_idx;
	mk_win_base_dword_t m_curr_size;
	mk_win_base_dword_t m_curr_pos;
};
typedef struct mk_win_sl_file_istream_buffered_512_8_state_s mk_win_sl_file_istream_buffered_512_8_state_t;
typedef mk_win_sl_file_istream_buffered_512_8_state_t const mk_win_sl_file_istream_buffered_512_8_state_ct;
typedef mk_win_sl_file_istream_buffered_512_8_state_t* mk_win_sl_file_istream_buffered_512_8_state_pt;
typedef mk_win_sl_file_istream_buffered_512_8_state_t const* mk_win_sl_file_istream_buffered_512_8_state_pct;
typedef mk_win_sl_file_istream_buffered_512_8_state_t mk_win_base_far* mk_win_sl_file_istream_buffered_512_8_state_lpt;
typedef mk_win_sl_file_istream_buffered_512_8_state_t mk_win_base_far const* mk_win_sl_file_istream_buffered_512_8_state_lpct;
typedef mk_win_sl_file_istream_buffered_512_8_state_t mk_win_base_near* mk_win_sl_file_istream_buffered_512_8_state_npt;
typedef mk_win_sl_file_istream_buffered_512_8_state_t mk_win_base_near const* mk_win_sl_file_istream_buffered_512_8_state_npct;


mk_lang_jumbo void mk_win_sl_file_istream_buffered_512_8_ro_destroy(mk_win_sl_file_istream_buffered_512_8_pct const istream) mk_lang_noexcept
{
	mk_win_sl_file_istream_buffered_512_8_state_lpt state;
	mk_win_kernel_files_overlapped_lpt overlapped;
	int i;
	mk_win_base_bool_t waited;
	mk_win_base_bool_t closed;
	mk_win_base_bool_t freed;

	mk_lang_assert(istream);

	state = ((mk_win_sl_file_istream_buffered_512_8_state_lpt)(((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (512 * 8)));
	overlapped = ((mk_win_kernel_files_overlapped_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_lang_max(sizeof(mk_win_sl_file_istream_buffered_512_8_state_t), sizeof(mk_win_kernel_files_overlapped_t))));
	for(i = 0; i != 8; ++i)
	{
		waited = mk_win_kernel_synchronization_wait_for_single_object(overlapped[i].m_event, mk_win_kernel_synchronization_infinite);
		if(waited != 0) mk_lang_unlikely
		{
			mk_lang_assert(0); /* todo? crash? */
		}
		closed = mk_win_kernel_handle_close_handle(overlapped[i].m_event);
		if(closed == 0) mk_lang_unlikely
		{
			mk_lang_assert(0); /* todo? crash? */
		}
	}
	freed = mk_win_kernel_memory_management_virtual_free(istream->m_buffers_and_state_and_overlappeds, 0, mk_win_kernel_memory_management_type_e_release);
	if(freed == 0) mk_lang_unlikely
	{
		mk_lang_assert(0); /* todo? crash? */
	}
}


mk_lang_jumbo void mk_win_sl_file_istream_buffered_512_8_rw_destroy(mk_win_sl_file_istream_buffered_512_8_pt const istream) mk_lang_noexcept
{
	mk_win_sl_file_istream_buffered_512_8_ro_destroy(istream);
}


mk_lang_jumbo void mk_win_sl_file_istream_buffered_512_8_rw_construct(mk_win_sl_file_istream_buffered_512_8_pt const istream, mk_lang_exception_pt const ex, mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_size_t size;
	mk_win_sl_file_istream_buffered_512_8_state_lpt state;
	mk_win_kernel_files_overlapped_lpt overlapped;
	int i;
	mk_win_base_bool_t read;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(istream);
	mk_lang_assert(ex);
	mk_lang_assert(handle != s_mk_win_base_handle_invalid);

	size = 0;
	size += 512 * 8;
	size += mk_lang_max(sizeof(mk_win_sl_file_istream_buffered_512_8_state_t), sizeof(mk_win_kernel_files_overlapped_t)) * (1 + 8);
	istream->m_buffers_and_state_and_overlappeds = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, size, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite);
	if(!istream->m_buffers_and_state_and_overlappeds) mk_lang_unlikely
	{
		mk_lang_exception_out_of_memory_make(ex, size);
		return;
	}
	state = ((mk_win_sl_file_istream_buffered_512_8_state_lpt)(((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (512 * 8)));
	state->m_handle = handle;
	state->m_curr_idx = 8 - 1;
	state->m_curr_size = 0;
	state->m_curr_pos = 0;
	overlapped = ((mk_win_kernel_files_overlapped_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_lang_max(sizeof(mk_win_sl_file_istream_buffered_512_8_state_t), sizeof(mk_win_kernel_files_overlapped_t))));
	for(i = 0; i != 8; ++i)
	{
		overlapped[i].m_event = mk_win_base_null;
	}
	for(i = 0; i != 8; ++i)
	{
		overlapped[i].m_event = mk_win_kernel_synchronization_t_create_event(mk_win_base_null, mk_win_base_true, mk_win_base_true, mk_win_base_null);
		if(!overlapped[i].m_event) mk_lang_unlikely
		{
			mk_win_sl_exception_gle_make_from_current(ex);
			return;
		}
	}
	for(i = 0; i != 8 - 1; ++i)
	{
		overlapped[i].m_offset_lo = i * 512;
		overlapped[i].m_offset_hi = 0;
		read = mk_win_kernel_files_read_file(state->m_handle, ((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (i * 512), 512, mk_win_base_null, &overlapped[i]);
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(read == 0 && err == mk_win_kernel_errors_id_e_handle_eof)
		{
			break;
		}
		if(!(read != 0 || err == mk_win_kernel_errors_id_e_io_pending)) mk_lang_unlikely
		{
			mk_win_sl_exception_gle_make_from_id(ex, err);
			return;
		}
	}
}

mk_lang_jumbo void mk_win_sl_file_istream_buffered_512_8_rw_read(mk_win_sl_file_istream_buffered_512_8_pt const istream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const destination, mk_lang_types_usize_t const requested_bytes, mk_lang_types_usize_pt const read_bytes) mk_lang_noexcept
{
	mk_win_sl_file_istream_buffered_512_8_state_lpt state;
	mk_win_kernel_files_overlapped_lpt overlapped;
	mk_lang_types_uchar_pt dst;
	mk_lang_types_usize_t remaining;
	mk_win_base_bool_t reseted;
	mk_win_base_bool_t read;
	mk_win_kernel_errors_id_t err;
	mk_win_base_dword_t waited;
	mk_win_base_bool_t got;
	mk_win_base_dword_t bytes_transfered;
	mk_win_base_dword_t n;

	*read_bytes = 0;
	state = ((mk_win_sl_file_istream_buffered_512_8_state_lpt)(((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (512 * 8)));
	overlapped = ((mk_win_kernel_files_overlapped_lpt)(((mk_win_base_uchar_lpt)(state)) + mk_lang_max(sizeof(mk_win_sl_file_istream_buffered_512_8_state_t), sizeof(mk_win_kernel_files_overlapped_t))));
	dst = ((mk_lang_types_uchar_pt)(destination));
	remaining = requested_bytes;
	while(remaining != 0)
	{
		if(state->m_curr_size - state->m_curr_pos == 0)
		{
			overlapped[state->m_curr_idx].m_offset_lo = overlapped[(state->m_curr_idx - 1) % 8].m_offset_lo + 512;
			overlapped[state->m_curr_idx].m_offset_hi = 0; /* todo */
			reseted = mk_win_kernel_synchronization_reset_event(overlapped[state->m_curr_idx].m_event);
			if(reseted == 0) mk_lang_unlikely
			{
				mk_win_sl_exception_gle_make_from_current(ex);
				return;
			}
			read = mk_win_kernel_files_read_file(state->m_handle, ((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (state->m_curr_idx * 512), 512, mk_win_base_null, &overlapped[state->m_curr_idx]);
			err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
			if(!(read != 0 || (err == mk_win_kernel_errors_id_e_io_pending || err == mk_win_kernel_errors_id_e_handle_eof))) mk_lang_unlikely
			{
				mk_win_sl_exception_gle_make_from_id(ex, err);
				return;
			}
			state->m_curr_idx = (state->m_curr_idx + 1) % 8;
			waited = mk_win_kernel_synchronization_wait_for_single_object(overlapped[state->m_curr_idx].m_event, mk_win_kernel_synchronization_infinite);
			if(waited != 0) mk_lang_unlikely
			{
				mk_win_sl_exception_gle_make_from_current(ex);
				return;
			}
			got = mk_win_kernel_synchronization_get_overlapped_result(state->m_handle, &overlapped[state->m_curr_idx], &bytes_transfered, mk_win_base_true);
			err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
			if(got == 0 && err == mk_win_kernel_errors_id_e_handle_eof)
			{
				break;
			}
			if(got == 0) mk_lang_unlikely
			{
				mk_win_sl_exception_gle_make_from_id(ex, err);
				return;
			}
			state->m_curr_size = bytes_transfered;
			state->m_curr_pos = 0;
		}
		n = ((mk_win_base_dword_t)(mk_lang_min(remaining, ((mk_lang_types_usize_t)(state->m_curr_size - state->m_curr_pos)))));
		mk_lang_memcpy(dst, ((mk_win_base_uchar_lpt)(istream->m_buffers_and_state_and_overlappeds)) + (state->m_curr_idx * 512) + state->m_curr_pos, n);
		state->m_curr_pos += n;
		remaining -= n;
		dst += n;
		*read_bytes += n;
	}
}
