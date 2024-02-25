#define mk_lang_jumbo_want 1


#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
#include "mk_lang_charbit.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpp.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_limits.h"
#include "mk_lang_log2.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_pow.h"
#include "mk_lang_pow2.h"
#include "mk_lib_fmt.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"
#include "mk_win_advapi_security.h"
#include "mk_win_base.h"
#include "mk_win_buffered_writer.h"
#include "mk_win_kernel_communication.h"
#include "mk_win_kernel_console.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_memory_management.h"
#include "mk_win_kernel_process.h"
#include "mk_win_kernel_system_information.h"
#include "mk_win_main_heap.h"
#include "mk_win_mallocator_main_heap.h"
#include "mk_win_mt.h"
#include "mk_win_tstring.h"

#if mk_lang_bitness == mk_lang_bitness_32
#define mk_lang_bui_t_name mkdefrag_bui32
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mkdefrag_bui32_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_t_name mkdefrag_cui64
#define mk_sl_cui_t_base mkdefrag_bui32
#define mk_sl_cui_t_count 2
#define mk_sl_cui_t_endian mk_lang_endian_little
#define mk_sl_cui_t_disable_big_div 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mkdefrag_cui64_sizebits_d 64
#define mkdefrag_cui64_c(a, b) {{ ((mkdefrag_bui32_t)(b)), ((mkdefrag_bui32_t)(a)) }}
#elif mk_lang_bitness == mk_lang_bitness_64
#define mk_lang_bui_t_name mkdefrag_bui64
#define mk_lang_bui_t_base ullong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mkdefrag_bui64_sizebits_d (mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#define mk_sl_cui_t_name mkdefrag_cui64
#define mk_sl_cui_t_base mkdefrag_bui64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_endian mk_lang_endian_little
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mkdefrag_cui64_sizebits_d 64
#define mkdefrag_cui64_c(a, b) {{ ((mkdefrag_bui64_t)(((mkdefrag_bui64_t)(((mkdefrag_bui64_t)(a)) << 32)) | ((mkdefrag_bui64_t)(a)))) }}
#else
#error xxxxxxxxxx
#endif

#define mk_lang_memcpy_t_name memcpyw
#define mk_lang_memcpy_t_base mk_win_base_wchar
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memmove_t_name memmovew
#define mk_lang_memmove_t_base mk_win_base_wchar
#include "mk_lang_memmove_inl_fileh.h"
#include "mk_lang_memmove_inl_filec.h"

#define mk_lang_memcpy_t_name memcpyu8
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memcmp_t_name memcmpw
#define mk_lang_memcmp_t_base mk_win_base_wchar
#include "mk_lang_memcmp_inl_fileh.h"
#include "mk_lang_memcmp_inl_filec.h"

struct fff_s
{
	mk_lang_types_ushort_t m_path_len;
	mk_win_base_handle_t m_file;
	mk_win_base_handle_t m_fff;
	mk_lang_types_bool_t m_is_dir;
	mk_lang_types_bool_t m_is_stream;
	mk_lang_types_ushort_t m_sub_len;
	mk_win_base_wchar_t m_sub_buf[s_mk_win_kernel_files_max_path];
};
typedef struct fff_s fff_t;
typedef fff_t const fff_ct;
typedef fff_t* fff_pt;
typedef fff_t const* fff_pct;

#define mk_sl_buffer_t_name fff
#define mk_sl_buffer_t_mallocator mk_win_mallocator_main_heap
#include "mk_sl_buffer_inl_fileh.h"
#include "mk_sl_buffer_inl_filec.h"
#define mk_sl_vector_t_name fff
#define mk_sl_vector_t_elem_t fff_t
#define mk_sl_vector_t_buffer_tn mk_sl_buffer_fff
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

struct mkdefrag_s
{
	mk_win_base_wchar_lpt m_str;
	mk_lang_types_sint_t m_len;
	mk_lang_types_sint_t m_cap;
	mk_sl_vector_fff_t m_fffs;
	mk_win_base_handle_t m_volume;
	mk_win_base_void_lpt m_tmp_a_buf;
	mk_lang_types_sint_t m_tmp_a_cap;
	mk_win_base_void_lpt m_tmp_b_buf;
	mk_lang_types_sint_t m_tmp_b_cap;
	mk_win_base_void_lpt m_file_pointers_buf;
	mk_lang_types_sint_t m_file_pointers_cap;
	mk_win_base_void_lpt m_volume_bitmap_buf;
	mk_lang_types_sint_t m_volume_bitmap_cap;
};
typedef struct mkdefrag_s mkdefrag_t;
typedef mkdefrag_t const mkdefrag_ct;
typedef mkdefrag_t* mkdefrag_pt;
typedef mkdefrag_t const* mkdefrag_pct;


static mk_lang_types_pchar_t const s_crlf_ascii[2] = { '\x0d', '\x0a' };
static mk_win_base_wchar_t const s_crlf_utf16[2] = { L'\x0d', L'\x0a' };


static mk_win_base_handle_t g_out_file;
static mk_lang_types_bool_t g_out_redicrected;
static mk_lang_types_bool_t g_out_once;
static mk_lang_types_bool_t g_out_use_utf8; /* or oem */
static mk_win_buffered_writer_t g_out_writer;


#define debug_print(x) write_ascii((x), pstrlen((x)))


#if defined NDEBUG
#define mkdefrag_main mayn
#else
#define mkdefrag_main main
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t wstrlenus(mk_win_base_wchar_lpct const str) mk_lang_noexcept
{
	mk_win_base_wchar_lpct ptr;
	mk_lang_types_usize_t len;

	mk_lang_assert(str);

	ptr = str;
	while(ptr[0] != L'\0')
	{
		++ptr;
	}
	len = ((mk_lang_types_usize_t)(ptr - str));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t wstrlensi(mk_win_base_wchar_lpct const str) mk_lang_noexcept
{
	mk_lang_types_usize_t lenus;
	mk_lang_types_sint_t lensi;

	mk_lang_assert(str);

	lenus = wstrlenus(str); mk_lang_check_crash(lenus <= mk_lang_limits_sint_max);
	lensi = ((mk_lang_types_sint_t)(lenus));
	return lensi;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t pstrlen(mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr;
	mk_lang_types_sint_t len;

	mk_lang_assert(str);

	ptr = str;
	while(*ptr)
	{
		++ptr;
	}
	len = ((mk_lang_types_sint_t)(ptr - str));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t all_of(mk_win_base_wchar_pct const a, mk_win_base_wchar_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	n = c;
	for(i = 0; i != n; ++i)
	{
		if(a[i] != *b)
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16_fallback_encoding(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len, mk_win_tstring_cp_t const encoding) mk_lang_noexcept
{
	mk_win_base_pchar_t invalid;
	mk_win_base_bool_t used_invalid_a;
	mk_win_base_bool_t used_invalid_b;
	mk_lang_types_sint_t cnt_a;
	mk_win_base_pchar_t buff[80];
	mk_win_base_pchar_pt ptr;
	mk_lang_exception_t ex;
	mk_lang_types_sint_t cnt_b;
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 1);
	mk_lang_assert(g_out_file.m_data);

	invalid = '?';
	used_invalid_a = mk_win_base_false;
	used_invalid_b = mk_win_base_false;
	cnt_a = mk_win_tstring_wide_to_ansi(encoding, encoding != mk_win_tstring_cp_e_utf8 ? mk_win_tstring_flags_wc_e_no_best_fit_chars : mk_win_tstring_flags_wc_e_none, str, len, mk_win_base_null, 0, encoding != mk_win_tstring_cp_e_utf8 ? &invalid : mk_win_base_null, encoding != mk_win_tstring_cp_e_utf8 ? &used_invalid_a : mk_win_base_null); mk_lang_check_return(cnt_a >= 1);
	if(cnt_a <= mk_lang_countof(buff))
	{
		ptr = &buff[0];
	}
	else
	{
		mk_lang_exception_make_none(&ex);
		mk_win_mallocator_main_heap_allocate(&ex, cnt_a, ((mk_lang_types_void_ppt)(&ptr))); mk_lang_check_return(!mk_lang_exception_is(&ex) && ptr);
	}
	cnt_b = mk_win_tstring_wide_to_ansi(encoding, encoding != mk_win_tstring_cp_e_utf8 ? mk_win_tstring_flags_wc_e_no_best_fit_chars : mk_win_tstring_flags_wc_e_none, str, len, ptr, cnt_a, encoding != mk_win_tstring_cp_e_utf8 ? &invalid : mk_win_base_null, encoding != mk_win_tstring_cp_e_utf8 ? &used_invalid_b : mk_win_base_null); mk_lang_check_return(cnt_b == cnt_a && used_invalid_b == used_invalid_a);
	err = mk_win_buffered_writer_rw_write(&g_out_writer, ptr, cnt_a); mk_lang_check_rereturn(err);
	if(ptr != &buff[0])
	{
		mk_win_mallocator_main_heap_deallocate(ptr, cnt_a);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16_fallback_oem(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	return write_utf16_fallback_encoding(str, len, mk_win_tstring_cp_e_oemcp);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16_fallback_utf8(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	return write_utf16_fallback_encoding(str, len, mk_win_tstring_cp_e_utf8);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16_fallback_utf16(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 1);

	err = mk_win_buffered_writer_rw_write(&g_out_writer, str, len * ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t)))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16_fallback_dispatch(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_dword_t len_lo;
	mk_win_base_dword_t len_hi;
	mk_lang_types_bool_t is_new_file;
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 0);

	if(!g_out_once)
	{
		g_out_once = mk_lang_true;
		len_lo = mk_win_kernel_files_get_file_size(g_out_file, &len_hi);
		if(len_lo == s_mk_win_kernel_files_invalid_file_size && mk_win_kernel_errors_get_last() != mk_win_kernel_errors_id_e_success)
		{
			is_new_file = mk_lang_true;
		}
		else
		{
			if(len_lo == 0 && len_hi == 0)
			{
				is_new_file = mk_lang_true;
			}
			else
			{
				is_new_file = mk_lang_false;
			}
		}
		g_out_use_utf8 = is_new_file;
	}
	if(g_out_use_utf8)
	{
		err = write_utf16_fallback_utf8(str, len); mk_lang_check_rereturn(err);
	}
	else
	{
		err = write_utf16_fallback_oem(str, len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_utf16(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 0);

	if(g_out_file.m_data && len > 0)
	{
		if(!g_out_redicrected)
		{
			b = mk_win_kernel_console_w_write(g_out_file, str, len, &nwritten, mk_win_base_null); mk_lang_check_return((b != 0 && nwritten == len) || (b == 0));
			if(!b)
			{
				g_out_redicrected = mk_lang_true;
				err = write_utf16_fallback_dispatch(str, len); mk_lang_check_rereturn(err);
			}
		}
		else
		{
			err = write_utf16_fallback_dispatch(str, len); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_path_utf16(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 0);

	if
	(
		len >= 7 &&
		str[0] == L'\\' &&
		str[1] == L'\\' &&
		str[2] == L'?' &&
		str[3] == L'\\' &&
		((str[4] >= L'a' || str[4] <= L'z') || (str[4] >= L'A' || str[4] <= L'Z')) &&
		str[5] == L':' &&
		str[6] == L'\\'
	)
	{
		err = write_utf16(str + 4, len - 4); mk_lang_check_rereturn(err);
	}
	else
	{
		err = write_utf16(str, len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t write_ascii(mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_wchar_t buff[80];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_win_base_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 0);

	if(len <= mk_lang_countof(buff))
	{
		n = len;
		for(i = 0; i != n; ++i)
		{
			buff[i] = ((mk_win_base_wchar_t)(str[i]));
		}
		err = write_utf16(&buff[0], len); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(0); /* todo */
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_move_file(mkdefrag_pt const mkdefrag, mk_win_base_ullong_t const position, mk_win_base_ullong_t const vclusters) mk_lang_noexcept
{
	mk_win_kernel_communication_move_file_data_t mf;
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];
	mk_lang_types_sint_t err;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(mkdefrag->m_volume.m_data != mk_win_base_handle_invalid);

	mf.m_file = mk_sl_vector_fff_ro_get_data_back(&mkdefrag->m_fffs)->m_file;
	mf.m_starting_vcn = 0;
	mf.m_starting_lcn = position;
	mf.m_clusters_count = vclusters;
	b = mk_win_kernel_communication_device_io_control(mkdefrag->m_volume, mk_win_kernel_communication_ioctl_id_e_fsctl_move_file, &mf, ((mk_win_base_dword_t)(sizeof(mf))), mk_win_base_null, 0, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last(); mk_lang_check_return((b != 0 && nwritten == 0) || (b == 0));
	if(b == 0)
	{
		tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not move file. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
		err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_volume_get_partial_position(mkdefrag_pt const mkdefrag, mk_win_base_ullong_t const vclusters, mk_lang_types_sint_t const align, mk_win_kernel_communication_volume_bitmap_buffer_lpct const bitmap, mk_win_base_ullong_t const starting_lcn, mk_lang_types_sint_t const clusters, mk_win_base_ullong_pt const position, mk_win_base_ullong_pt const bytes_zero, mk_lang_types_bool_pt const found) mk_lang_noexcept
{
	mk_lang_types_sint_t start;
	mk_win_base_ullong_t len;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);
	mk_lang_assert(bitmap);
	mk_lang_assert(clusters >= 1);
	mk_lang_assert(clusters % mk_lang_charbit == 0);
	mk_lang_assert(position);
	mk_lang_assert(bytes_zero);
	mk_lang_assert(found);

	start = 0;
	len = 0;
	n = clusters / mk_lang_charbit;
	i = 0;
	for(i = 0; i < n; ++i)
	{
		if(bitmap->m_bitmap_arr[i] == 0)
		{
			start = i;
			for(++i; i != n && bitmap->m_bitmap_arr[i] == 0; ++i)
			{
			}
			len = i - start;
			if(start == 0)
			{
				len += *bytes_zero;
			}
			if(len * mk_lang_charbit >= vclusters + 0xf)
			{
				if(start != 0)
				{
					*position = starting_lcn + start * mk_lang_charbit;
				}
				*position = *position + align;
				*bytes_zero = len;
				*found = mk_lang_true;
				break;
			}
		}
	}
	if(!*found)
	{
		if(len != 0 && bitmap->m_bitmap_arr[n - 1] == 0)
		{
			*bytes_zero = len;
			if(start != 0)
			{
				*position = starting_lcn + start * mk_lang_charbit;
			}
		}
		else
		{
			*bytes_zero = 0;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_volume_get_position(mkdefrag_pt const mkdefrag, mk_win_base_ullong_t const vclusters, mk_lang_types_sint_t const align, mk_win_base_ullong_pt const position_out) mk_lang_noexcept
{
	mk_win_base_wchar_pt volume_mount_point;
	mk_lang_types_sint_t rem;
	mk_win_base_bool_t b;
	mk_win_base_wchar_pt volume_name;
	mk_lang_types_sint_t len;
	mk_win_kernel_communication_volume_bitmap_buffer_lpt bitmap;
	mk_win_kernel_communication_starting_lcn_input_buffer_t lcn_start;
	mk_win_base_dword_t nwritten;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t clusters;
	mk_win_base_ullong_t position;
	mk_win_base_ullong_t bytes_zero;
	mk_lang_types_bool_t found;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(vclusters >= 2);
	mk_lang_assert(align >= 0 && align <= 0xf);
	mk_lang_assert(position_out);

	volume_mount_point = ((mk_win_base_wchar_pt)(mkdefrag->m_tmp_a_buf));
	rem = mkdefrag->m_tmp_a_cap / ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t))); mk_lang_assert(rem >= mk_win_base_page_64k);
	b = GetVolumePathNameW(mkdefrag->m_str, volume_mount_point, rem); mk_lang_check_return(b != 0);
	volume_name = ((mk_win_base_wchar_pt)(mkdefrag->m_tmp_b_buf));
	rem = mkdefrag->m_tmp_b_cap / ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t))); mk_lang_assert(rem >= mk_win_base_page_64k);
	b = GetVolumeNameForVolumeMountPointW(volume_mount_point, volume_name, rem); mk_lang_check_return(b != 0);
	len = wstrlensi(volume_name); mk_lang_check_return(len >= 2);
	if(volume_name[len - 1] == L'\\')
	{
		volume_name[len - 1] = L'\0';
		--len;
	}
	mkdefrag->m_volume = mk_win_kernel_files_w_create_file(volume_name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_none, mk_win_base_handle_null_g);
	if(mkdefrag->m_volume.m_data != mk_win_base_handle_invalid)
	{
		position = 0;
		bytes_zero = 0;
		found = mk_lang_false;
		bitmap = ((mk_win_kernel_communication_volume_bitmap_buffer_lpt)(mkdefrag->m_volume_bitmap_buf));
		lcn_start.m_starting_lcn = 0;
		for(;;)
		{
			b = mk_win_kernel_communication_device_io_control(mkdefrag->m_volume, mk_win_kernel_communication_ioctl_id_e_fsctl_get_volume_bitmap, &lcn_start, ((mk_win_base_dword_t)(sizeof(lcn_start))), bitmap, mkdefrag->m_volume_bitmap_cap, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last(); mk_lang_check_return((b != 0 && nwritten >= ((mk_lang_types_sint_t)(sizeof(*bitmap))) && nwritten <= mkdefrag->m_volume_bitmap_cap) || (b == 0 && gle == mk_win_kernel_errors_id_e_more_data));
			if((b != 0) || (b == 0 && gle == mk_win_kernel_errors_id_e_more_data))
			{
				mk_lang_check_return(bitmap->m_starting_lcn == lcn_start.m_starting_lcn);
				clusters = (((mk_lang_types_sint_t)(nwritten)) - (((mk_lang_types_sint_t)(sizeof(bitmap->m_starting_lcn))) + ((mk_lang_types_sint_t)(sizeof(bitmap->m_bitmap_size))))) * mk_lang_charbit;
				clusters = ((mk_lang_types_sint_t)(mk_lang_min(((mk_win_base_ullong_t)(clusters)), bitmap->m_bitmap_size)));
				err = mkdefrag_rw_volume_get_partial_position(mkdefrag, vclusters, align, bitmap, lcn_start.m_starting_lcn, clusters, &position, &bytes_zero, &found); mk_lang_check_rereturn(err);
				if(found)
				{
					*position_out = position;
					break;
				}
				if(!(b == 0 && gle == mk_win_kernel_errors_id_e_more_data))
				{
					break;
				}
				lcn_start.m_starting_lcn = bitmap->m_starting_lcn + clusters;
			}
			else
			{
				tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not read volume bitmap. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
				err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
				break;
			}
		}
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not open volume. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
		err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_file_get_details(mkdefrag_pt const mkdefrag, mk_win_base_ullong_pt const vclusters_out, mk_lang_types_sint_pt const fragments_out, mk_lang_types_sint_pt const align_out) mk_lang_noexcept
{
	static mk_win_base_ullong_t const s_invalid_lcn = ((mk_win_base_ullong_t)(((mk_win_base_sllong_t)(-1))));

	fff_pt curr;
	mk_win_kernel_communication_starting_vcn_input_buffer_t vcn_start;
	mk_win_kernel_communication_retrieval_pointers_buffer_lpt vcn_buffer;
	mk_lang_types_sint_t extents;
	mk_win_base_ullong_t vclusters;
	mk_win_base_ullong_t pclusters;
	mk_lang_types_sint_t fragments;
	mk_lang_types_sint_t align;
	mk_win_base_ullong_t prev_lcn;
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;
	mk_win_base_dword_t gle;
	mk_lang_types_bool_t bad;
	mk_lang_types_sint_t n;
	mk_win_base_ullong_t curr_vcn;
	mk_lang_types_sint_t i;
	mk_win_base_ullong_t next_vcn;
	mk_win_base_ullong_t curr_lcn;
	mk_win_base_ullong_t diff_vcn;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];
	mk_lang_types_sint_t err;
	mk_win_base_ullong_t last_pclusters_len;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(vclusters_out);
	mk_lang_assert(fragments_out);
	mk_lang_assert(align_out);

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr && !curr->m_is_dir && curr->m_file.m_data != mk_win_base_handle_invalid);
	vcn_start.m_starting_vcn = 0;
	vcn_buffer = ((mk_win_kernel_communication_retrieval_pointers_buffer_lpt)(mkdefrag->m_file_pointers_buf));
	extents = 0;
	vclusters = 0;
	pclusters = 0;
	fragments = 1;
	align = -1;
	prev_lcn = s_invalid_lcn;
	b = mk_win_kernel_communication_device_io_control(curr->m_file, mk_win_kernel_communication_ioctl_id_e_fsctl_get_retrieval_pointers, &vcn_start, ((mk_win_base_dword_t)(sizeof(vcn_start))), vcn_buffer, mkdefrag->m_file_pointers_cap, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last();
	if((b != 0) || (b == 0 && gle == mk_win_kernel_errors_id_e_more_data))
	{
		bad = mk_lang_false;
		for(;;)
		{
			mk_lang_check_return(nwritten >= ((mk_lang_types_sint_t)(sizeof(vcn_buffer))) && nwritten <= mkdefrag->m_file_pointers_cap);
			mk_lang_check_return(vcn_buffer->m_starting_vcn == vcn_start.m_starting_vcn);
			mk_lang_check_return(vcn_buffer->m_extents_count >= 1 && vcn_buffer->m_extents_count <= ((mk_win_base_dword_t)(mk_lang_limits_sint_max)));
			mk_lang_check_return(((mk_win_base_dword_t)(extents)) <= ((mk_win_base_dword_t)(mk_lang_limits_sint_max)) - vcn_buffer->m_extents_count);
			n = ((mk_lang_types_sint_t)(vcn_buffer->m_extents_count));
			extents += n;
			curr_vcn = vcn_start.m_starting_vcn;
			for(i = 0; i != n; ++i)
			{
				next_vcn = vcn_buffer->m_extents_arr[i].m_next_vcn;
				curr_lcn = vcn_buffer->m_extents_arr[i].m_lcn;
				mk_lang_check_return(next_vcn > curr_vcn);
				diff_vcn = next_vcn - curr_vcn;
				if(curr_lcn != s_invalid_lcn)
				{
					pclusters += diff_vcn;
					if(prev_lcn != s_invalid_lcn)
					{
						if(!(prev_lcn + last_pclusters_len == curr_lcn))
						{
							++fragments;
						}
					}
					if(align == -1)
					{
						align = ((mk_lang_types_uint_t)(curr_lcn)) % 0xf;
					}
					prev_lcn = curr_lcn;
					last_pclusters_len = diff_vcn;
				}
				curr_vcn = next_vcn;
			}
			vclusters = vcn_buffer->m_extents_arr[vcn_buffer->m_extents_count - 1].m_next_vcn;
			vcn_start.m_starting_vcn = vcn_buffer->m_extents_arr[vcn_buffer->m_extents_count - 1].m_next_vcn;
			b = mk_win_kernel_communication_device_io_control(curr->m_file, mk_win_kernel_communication_ioctl_id_e_fsctl_get_retrieval_pointers, &vcn_start, ((mk_win_base_dword_t)(sizeof(vcn_start))), vcn_buffer, mkdefrag->m_file_pointers_cap, &nwritten, mk_win_base_null); gle = mk_win_kernel_errors_get_last();
			if((b != 0) || (b == 0 && gle == mk_win_kernel_errors_id_e_more_data))
			{
			}
			else if(b == 0 && gle == mk_win_kernel_errors_id_e_handle_eof)
			{
				break;
			}
			else
			{
				tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not get extents info. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
				err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
				bad = mk_lang_true;
				break;
			}
		}
		if(!bad)
		{
			mk_lang_assert(fragments <= extents);
			mk_lang_assert(extents <= vclusters);
			mk_lang_assert(pclusters <= vclusters);
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Extents:           %d\x0d\x0a", &extents  ); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg)); err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Virtual clusters:  %llu\x0d\x0a", &vclusters); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg)); err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Physical clusters: %llu\x0d\x0a", &pclusters); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg)); err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Fragments:         %d\x0d\x0a", &fragments); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg)); err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
			*vclusters_out = vclusters;
			*fragments_out = fragments;
			*align_out = align;
		}
	}
	else if(b == 0 && gle == mk_win_kernel_errors_id_e_handle_eof)
	{
		static mk_lang_types_pchar_t const s_resident[] = "Fragments: 1 (resident)\x0d\x0a";
		err = write_ascii(&s_resident[0], mk_lang_countstr(s_resident)); mk_lang_check_rereturn(err);
	}
	else
	{
		tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not get extents info. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
		err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_add_stream(mkdefrag_pt const mkdefrag, fff_pct const curr, mk_win_mt_find_stream_data_pct const data) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_wchar_t const s_main_stream_name[] = L"::$DATA";

	mk_lang_types_sint_t len;
	mk_lang_exception_t ex;
	fff_pt next;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(curr);
	mk_lang_assert(data);

	if(!memcmpw_fn(&data->m_stream_name[0], &s_main_stream_name[0], mk_lang_countof(s_main_stream_name)))
	{
		len = wstrlensi(&data->m_stream_name[0]);
		if(curr->m_sub_len + len <= mk_lang_countof(curr->m_sub_buf))
		{
			mk_lang_exception_make_none(&ex);
			mk_sl_vector_fff_rw_reserve_one(&mkdefrag->m_fffs, &ex); mk_lang_check_return(!mk_lang_exception_is(&ex));
			mk_sl_vector_fff_rw_push_back_from_capacity_one(&mkdefrag->m_fffs);
			next = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(next);
			next->m_path_len = curr->m_path_len;
			next->m_file.m_data = mk_win_base_handle_invalid;
			next->m_fff.m_data = mk_win_base_handle_invalid;
			next->m_is_stream = mk_lang_true;
			next->m_sub_len = curr->m_sub_len + len;
			memcpyw_fn(&next->m_sub_buf[0], &curr->m_sub_buf[0], curr->m_sub_len);
			memcpyw_fn(&next->m_sub_buf[curr->m_sub_len], &data->m_stream_name[0], len);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_enumerate_streams_and_pop_back(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_t curr;
	mk_win_base_handle_t find;
	mk_win_mt_find_stream_data_t data;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];

	mk_lang_assert(mkdefrag);

	curr = *mk_sl_vector_fff_ro_get_data_back(&mkdefrag->m_fffs);
	mk_sl_vector_fff_rw_pop_back_one(&mkdefrag->m_fffs);
	if(!curr.m_is_stream)
	{
		find = FindFirstStreamW(&mkdefrag->m_str[0], mk_win_mt_stream_info_levels_e_findstreaminfostandard, &data, 0);
		if(find.m_data != mk_win_base_handle_invalid)
		{
			err = mkdefrag_rw_add_stream(mkdefrag, &curr, &data); mk_lang_check_rereturn(err);
			for(;;)
			{
				b = FindNextStreamW(find, &data);
				if(b != 0)
				{
					err = mkdefrag_rw_add_stream(mkdefrag, &curr, &data); mk_lang_check_rereturn(err);
				}
				else
				{
					gle = mk_win_kernel_errors_get_last();
					if(gle == mk_win_kernel_errors_id_e_handle_eof)
					{
						break;
					}
					else
					{
						tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not get next stream info. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
						err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
						break;
					}
				}
			}
			b = mk_win_kernel_files_find_close(find); mk_lang_check_return(b != 0);
		}
		else
		{
			gle = mk_win_kernel_errors_get_last();
			if(gle == mk_win_kernel_errors_id_e_handle_eof)
			{
				/* no streams can be found */
			}
			else if(gle == mk_win_kernel_errors_id_e_invalid_parameter)
			{
				/* filesystem does not support streams */
			}
			else
			{
				tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not get stream info. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
				err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_process_file(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t fragments;
	mk_win_base_ullong_t vclusters;
	mk_lang_types_sint_t align;
	mk_win_base_ullong_t position;
	mk_win_base_bool_t b;

	mk_lang_assert(mkdefrag);

	fragments = 0;
	err = mkdefrag_rw_file_get_details(mkdefrag, &vclusters, &fragments, &align); mk_lang_check_rereturn(err);
	if(fragments >= 2)
	{
		position = 0;
		err = mkdefrag_rw_volume_get_position(mkdefrag, vclusters, align, &position); mk_lang_check_rereturn(err);
		if(position != 0)
		{
			err = mkdefrag_rw_move_file(mkdefrag, position, vclusters); mk_lang_check_rereturn(err);
		}
		else
		{
			static mk_lang_types_pchar_t const s_no_find[] = "Could not find contiguous free space for entire file.\x0d\x0a";
			err = write_ascii(&s_no_find[0], mk_lang_countstr(s_no_find)); mk_lang_check_rereturn(err);
			err = write_ascii(&s_crlf_ascii[0], mk_lang_countof(s_crlf_ascii)); mk_lang_check_rereturn(err);
		}
		if(mkdefrag->m_volume.m_data != mk_win_base_handle_invalid)
		{
			b = mk_win_kernel_handle_close_handle(mkdefrag->m_volume); mk_lang_check_return(b != 0);
			mkdefrag->m_volume.m_data == mk_win_base_handle_invalid;
		}
	}
	b = mk_win_kernel_handle_close_handle(mk_sl_vector_fff_ro_get_data_back(&mkdefrag->m_fffs)->m_file); mk_lang_check_return(b != 0);
	err = mkdefrag_rw_enumerate_streams_and_pop_back(mkdefrag); mk_lang_check_rereturn(err);
	err = write_ascii(&s_crlf_ascii[0], mk_lang_countof(s_crlf_ascii)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_append_fd(mkdefrag_pt const mkdefrag, mk_win_kernel_files_w_find_data_pct const fd) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	fff_pt curr;
	mk_lang_types_sint_t slash_adjust;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_exception_t ex;
	fff_pt next;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(fd);

	len = wstrlensi(&fd->m_name[0]); mk_lang_check_return(len >= 1 && len < s_mk_win_kernel_files_max_path);
	if
	(!(
		(len == 1 && fd->m_name[0] == L'.') ||
		(len == 2 && fd->m_name[0] == L'.' && fd->m_name[1] == L'.')
	))
	{
		curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
		if(mkdefrag->m_str[curr->m_path_len - 1] != L'\\' && mkdefrag->m_str[curr->m_path_len - 1] != L'/'){ slash_adjust = 0; }else{ slash_adjust = -1; }
		mkdefrag->m_str[curr->m_path_len + slash_adjust + 0] = L'\\';
		memcpyw_fn(&mkdefrag->m_str[curr->m_path_len + slash_adjust + 1], &curr->m_sub_buf[0], curr->m_sub_len);
		tsi = curr->m_path_len + slash_adjust + curr->m_sub_len + (curr->m_sub_len != 0 ? 1 : 0);
		mkdefrag->m_str[tsi + 0] = L'\\';
		memcpyw_fn(&mkdefrag->m_str[tsi + 1], &fd->m_name[0], len);
		mkdefrag->m_str[tsi + 1 + len + 0] = s_crlf_utf16[0];
		mkdefrag->m_str[tsi + 1 + len + 1] = s_crlf_utf16[1];
		err = write_path_utf16(mkdefrag->m_str, tsi + 1 + len + mk_lang_countof(s_crlf_utf16)); mk_lang_check_rereturn(err);
		if(!((fd->m_attributes & mk_win_kernel_files_attribute_e_reparse_point) != 0))
		{
			mk_lang_exception_make_none(&ex);
			mk_sl_vector_fff_rw_reserve_one(&mkdefrag->m_fffs, &ex); mk_lang_check_return(!mk_lang_exception_is(&ex));
			curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
			mk_sl_vector_fff_rw_push_back_from_capacity_one(&mkdefrag->m_fffs);
			next = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(next);
			next->m_path_len = tsi;
			next->m_file.m_data = mk_win_base_handle_invalid;
			next->m_fff.m_data = mk_win_base_handle_invalid;
			next->m_is_stream = mk_lang_false;
			next->m_sub_len = len;
			memcpyw_fn(&next->m_sub_buf[0], &fd->m_name[0], len);
		}
		else
		{
			static mk_lang_types_pchar_t const s_reparse[] = "Reparse point\x0d\x0a";
			err = write_ascii(&s_reparse[0], mk_lang_countstr(s_reparse)); mk_lang_check_rereturn(err);
			err = write_ascii(&s_crlf_ascii[0], mk_lang_countof(s_crlf_ascii)); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_continue_fff(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_pt curr;
	mk_win_base_bool_t b;
	mk_win_kernel_files_w_find_data_t fd;
	mk_lang_types_sint_t err;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];

	mk_lang_assert(mkdefrag);

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
	mk_lang_assert(curr->m_file.m_data != mk_win_base_handle_invalid);
	mk_lang_assert(curr->m_is_dir);
	mk_lang_assert(curr->m_fff.m_data != mk_win_base_handle_invalid);
	mk_lang_assert(curr->m_path_len >= 1);
	b = mk_win_kernel_files_w_find_next_file(curr->m_fff, &fd);
	if(b != 0)
	{
		err = mkdefrag_rw_append_fd(mkdefrag, &fd); mk_lang_check_rereturn(err);
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		if(gle != mk_win_kernel_errors_id_e_no_more_files)
		{
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not enumerate files. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
			err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
		}
		b = mk_win_kernel_files_find_close(curr->m_fff); mk_lang_check_return(b != 0);
		b = mk_win_kernel_handle_close_handle(curr->m_file); mk_lang_check_return(b != 0);
		mk_sl_vector_fff_rw_pop_back_one(&mkdefrag->m_fffs);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_open_fff(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_pt curr;
	mk_lang_types_sint_t slash_adjust;
	mk_lang_types_sint_t len;
	mk_win_kernel_files_w_find_data_t fd;
	mk_lang_types_sint_t err;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];
	mk_win_base_bool_t b;

	mk_lang_assert(mkdefrag);

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
	mk_lang_assert(curr->m_file.m_data != mk_win_base_handle_invalid);
	mk_lang_assert(curr->m_is_dir);
	mk_lang_assert(curr->m_fff.m_data == mk_win_base_handle_invalid);
	mk_lang_assert(curr->m_path_len >= 1);
	if(mkdefrag->m_str[curr->m_path_len - 1] != L'\\' && mkdefrag->m_str[curr->m_path_len - 1] != L'/'){ slash_adjust = 0; }else{ slash_adjust = -1; }
	mkdefrag->m_str[curr->m_path_len + slash_adjust + 0] = L'\\';
	memcpyw_fn(&mkdefrag->m_str[curr->m_path_len + slash_adjust + 1], &curr->m_sub_buf[0], curr->m_sub_len);
	len = curr->m_path_len + slash_adjust + curr->m_sub_len + (curr->m_sub_len != 0 ? 1 : 0);
	mkdefrag->m_str[len + 0] = L'\\';
	mkdefrag->m_str[len + 1] = L'*';
	mkdefrag->m_str[len + 2] = L'\0';
	curr->m_fff = mk_win_kernel_files_w_find_first_file(mkdefrag->m_str, &fd);
	if(curr->m_fff.m_data != mk_win_base_handle_invalid)
	{
		err = mkdefrag_rw_append_fd(mkdefrag, &fd); mk_lang_check_rereturn(err);
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		if(gle != mk_win_kernel_errors_id_e_file_not_found)
		{
			tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not enumerate files. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
			err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
		}
		b = mk_win_kernel_handle_close_handle(curr->m_file); mk_lang_check_return(b != 0);
		mk_sl_vector_fff_rw_pop_back_one(&mkdefrag->m_fffs);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_drive_letter_adjust(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_lang_assert(mkdefrag);

	if(mkdefrag->m_len == 7)
	{
		if
		(
			mkdefrag->m_str[0] == L'\\' &&
			mkdefrag->m_str[1] == L'\\' &&
			mkdefrag->m_str[2] == L'?' &&
			mkdefrag->m_str[3] == L'\\' &&
			mkdefrag->m_str[5] == L':' &&
			mkdefrag->m_str[6] == L'\0'
		)
		{
			mkdefrag->m_str[6] = L'\\';
			mkdefrag->m_str[7] = L'\0';
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_ro_print_stream(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_pt curr;
	mk_lang_types_sint_t slash_adjust;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(mkdefrag);

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
	if(curr->m_is_stream)
	{
		if(mkdefrag->m_str[curr->m_path_len - 1] != L'\\' && mkdefrag->m_str[curr->m_path_len - 1] != L'/'){ slash_adjust = 0; }else{ slash_adjust = -1; }
		len = curr->m_path_len + slash_adjust + (curr->m_sub_len != 0 ? 1 : 0) + curr->m_sub_len;
		mkdefrag->m_str[len + 0] = s_crlf_utf16[0];
		mkdefrag->m_str[len + 1] = s_crlf_utf16[1];
		err = write_path_utf16(mkdefrag->m_str, len + mk_lang_countof(s_crlf_utf16)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_open_file(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_pt curr;
	mk_lang_types_sint_t slash_adjust;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;
	mk_win_kernel_by_handle_file_information_t info;
	mk_win_base_dword_t gle;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_t msg[80];

	mk_lang_assert(mkdefrag);

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
	mk_lang_assert(curr->m_file.m_data == mk_win_base_handle_invalid);
	mk_lang_assert(curr->m_path_len >= 1);
	if(mkdefrag->m_str[curr->m_path_len - 1] != L'\\' && mkdefrag->m_str[curr->m_path_len - 1] != L'/'){ slash_adjust = 0; }else{ slash_adjust = -1; }
	mkdefrag->m_str[curr->m_path_len + slash_adjust + 0] = L'\\';
	memcpyw_fn(&mkdefrag->m_str[curr->m_path_len + slash_adjust + 1], &curr->m_sub_buf[0], curr->m_sub_len);
	len = curr->m_path_len + slash_adjust + (curr->m_sub_len != 0 ? 1 : 0) + curr->m_sub_len;
	err = mkdefrag_ro_print_stream(mkdefrag); mk_lang_check_rereturn(err);
	mkdefrag->m_str[len + 0] = L'\0';
	err = mkdefrag_rw_drive_letter_adjust(mkdefrag); mk_lang_check_rereturn(err);
	curr->m_file = mk_win_kernel_files_w_create_file(mkdefrag->m_str, mk_win_advapi_base_right_specific_file_e_read_attributes, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_backup_semantics, mk_win_base_handle_null_g);
	if(curr->m_file.m_data != mk_win_base_handle_invalid)
	{
		b = GetFileInformationByHandle(curr->m_file, &info); mk_lang_check_return(b != 0);
		curr->m_is_dir = (info.m_file_attributes & mk_win_kernel_files_attribute_e_directory) != 0;
		if(curr->m_is_dir)
		{
			static mk_lang_types_pchar_t const s_directory[] = "Directory\x0d\x0a";
			err = write_ascii(&s_directory[0], mk_lang_countstr(s_directory)); mk_lang_check_rereturn(err);
			err = write_ascii(&s_crlf_ascii[0], mk_lang_countof(s_crlf_ascii)); mk_lang_check_rereturn(err);
		}
	}
	else
	{
		gle = mk_win_kernel_errors_get_last();
		tsi = mk_lib_fmt_snprintf(&msg[0], mk_lang_countof(msg), "Could not open file. Error: %u 0x%x\x0d\x0a", &gle, &gle); mk_lang_assert(tsi >= 1 && tsi <= mk_lang_countstr(msg));
		err = write_ascii(&msg[0], tsi); mk_lang_check_rereturn(err);
		err = write_ascii(&s_crlf_ascii[0], mk_lang_countof(s_crlf_ascii)); mk_lang_check_rereturn(err);
		mk_sl_vector_fff_rw_pop_back_one(&mkdefrag->m_fffs);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_process_one(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	fff_pt curr;
	mk_lang_types_sint_t err;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(!mk_sl_vector_fff_ro_is_empty(&mkdefrag->m_fffs));
	mk_lang_assert(mk_sl_vector_fff_ro_get_data_back(&mkdefrag->m_fffs));

	curr = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(curr);
	if(curr->m_file.m_data != mk_win_base_handle_invalid)
	{
		if(!curr->m_is_dir)
		{
			err = mkdefrag_rw_process_file(mkdefrag); mk_lang_check_rereturn(err);
		}
		else
		{
			if(curr->m_fff.m_data != mk_win_base_handle_invalid)
			{
				err = mkdefrag_rw_continue_fff(mkdefrag); mk_lang_check_rereturn(err);
			}
			else
			{
				err = mkdefrag_rw_open_fff(mkdefrag); mk_lang_check_rereturn(err);
			}
		}
	}
	else
	{
		err = mkdefrag_rw_open_file(mkdefrag); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_process_all(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mkdefrag);

	while(!mk_sl_vector_fff_ro_is_empty(&mkdefrag->m_fffs))
	{
		err = mkdefrag_rw_process_one(mkdefrag); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_ro_print_str(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(mkdefrag->m_str);
	mk_lang_assert(mkdefrag->m_str[0] != L'\0');
	mk_lang_assert(mkdefrag->m_len >= 1);

	mkdefrag->m_str[mkdefrag->m_len + 0] = s_crlf_utf16[0];
	mkdefrag->m_str[mkdefrag->m_len + 1] = s_crlf_utf16[1];
	err = write_path_utf16(mkdefrag->m_str, mkdefrag->m_len + mk_lang_countof(s_crlf_utf16)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_adjust_name(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_win_base_wchar_lpt str;
	mk_lang_types_sint_t rem;
	mk_win_base_handle_t file_a;
	mk_win_base_dword_t tdw;
	mk_lang_types_sint_t len;
	mk_win_base_handle_t file_b;
	mk_win_base_bool_t b;
	mk_win_kernel_by_handle_file_information_t info_a;
	mk_win_kernel_by_handle_file_information_t info_b;

	mk_lang_assert(mkdefrag);
	mk_lang_assert(mkdefrag->m_len >= 1);
	mk_lang_assert(mkdefrag->m_str);
	mk_lang_assert(mkdefrag->m_str[0] != L'\0');
	
	str = ((mk_win_base_wchar_lpt)(mkdefrag->m_tmp_a_buf));
	rem = mkdefrag->m_tmp_a_cap / ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t)));
	mkdefrag->m_str[mkdefrag->m_len] = L'\0';
	file_a = mk_win_kernel_files_w_create_file(mkdefrag->m_str, mk_win_advapi_base_right_specific_file_e_read_attributes, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_backup_semantics, mk_win_base_handle_null_g);
	if(file_a.m_data != mk_win_base_handle_invalid)
	{
		tdw = GetFinalPathNameByHandleW(file_a, str, rem, 0); mk_lang_check_return(tdw <= mk_lang_limits_sint_max); len = ((mk_lang_types_sint_t)(tdw));
		if(len != 0 && len < rem)
		{
			file_b = mk_win_kernel_files_w_create_file(str, mk_win_advapi_base_right_specific_file_e_read_attributes, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_backup_semantics, mk_win_base_handle_null_g);
			if(file_a.m_data != mk_win_base_handle_invalid)
			{
				b = GetFileInformationByHandle(file_a, &info_a); mk_lang_check_return(b != 0);
				b = GetFileInformationByHandle(file_b, &info_b); mk_lang_check_return(b != 0);
				if
				(
					info_a.m_volume_serial_number == info_b.m_volume_serial_number &&
					info_a.m_file_index_low == info_b.m_file_index_low &&
					info_a.m_file_index_high == info_b.m_file_index_high
				)
				{
					memmovew_fn(&mkdefrag->m_str[0], str, len);
					mkdefrag->m_len = len;
				}
				b = mk_win_kernel_handle_close_handle(file_b); mk_lang_check_return(b != 0);
			}
		}
		b = mk_win_kernel_handle_close_handle(file_a); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_append_dummy(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	fff_pt fff;

	mk_lang_assert(mkdefrag);

	mk_lang_exception_make_none(&ex);
	mk_sl_vector_fff_rw_reserve_one(&mkdefrag->m_fffs, &ex); mk_lang_check_return(!mk_lang_exception_is(&ex));
	mk_sl_vector_fff_rw_push_back_from_capacity_one(&mkdefrag->m_fffs);
	fff = mk_sl_vector_fff_rw_get_data_back(&mkdefrag->m_fffs); mk_lang_assert(fff);
	fff->m_path_len = mkdefrag->m_len;
	fff->m_file.m_data = mk_win_base_handle_invalid;
	fff->m_fff.m_data = mk_win_base_handle_invalid;
	fff->m_is_stream = mk_lang_false;
	fff->m_sub_len = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_st_enable_backup(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_luid_t backup;
	mk_win_base_handle_t token;
	mk_win_advapi_security_token_privileges_t privs;

	b = mk_win_advapi_security_lookup_privilege_value_w(mk_win_base_null, mk_win_advapi_base_privilege_name_w_se_backup, &backup); mk_lang_check_return(b != 0);
	b = mk_win_advapi_security_open_process_token(mk_win_kernel_process_get_current(), mk_win_advapi_base_right_specific_token_e_query | mk_win_advapi_base_right_specific_token_e_adjust_privileges, &token); mk_lang_check_return(b != 0);
	privs.m_count = 1;
	privs.m_privileges[0].m_luid = backup;
	privs.m_privileges[0].m_attributes = mk_win_advapi_security_privilege_attribute_e_enabled;
	b = mk_win_advapi_security_adjust_token_privileges(token, mk_win_base_false, &privs, 0, mk_win_base_null, mk_win_base_null); mk_lang_check_return(b != 0);
	b = mk_win_kernel_handle_close_handle(token); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_construct(mkdefrag_pt const mkdefrag, mk_win_base_wchar_lpt const str, mk_lang_types_sint_t const len, mk_lang_types_sint_t const cap) mk_lang_noexcept
{
	mk_lang_assert(mkdefrag);
	mk_lang_assert(str);
	mk_lang_assert(len >= 0);

	mkdefrag->m_str = str;
	mkdefrag->m_len = len;
	mkdefrag->m_cap = cap;
	mk_sl_vector_fff_rw_construct(&mkdefrag->m_fffs);
	mkdefrag->m_volume.m_data == mk_win_base_handle_invalid;
	mkdefrag->m_tmp_a_cap = 2 * mk_win_base_page_64k;
	mkdefrag->m_tmp_a_buf = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, mkdefrag->m_tmp_a_cap, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite); mk_lang_check_return(mkdefrag->m_tmp_a_buf);
	mkdefrag->m_tmp_b_cap = 2 * mk_win_base_page_64k;
	mkdefrag->m_tmp_b_buf = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, mkdefrag->m_tmp_b_cap, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite); mk_lang_check_return(mkdefrag->m_tmp_b_buf);
	mkdefrag->m_file_pointers_cap = mk_win_base_page_64k;
	mkdefrag->m_file_pointers_buf = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, mkdefrag->m_file_pointers_cap, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite); mk_lang_check_return(mkdefrag->m_file_pointers_buf);
	mkdefrag->m_volume_bitmap_cap = mk_win_base_page_64k;
	mkdefrag->m_volume_bitmap_buf = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, mkdefrag->m_volume_bitmap_cap, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite); mk_lang_check_return(mkdefrag->m_volume_bitmap_buf);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkdefrag_rw_destroy(mkdefrag_pt const mkdefrag) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(mkdefrag);

	if(mkdefrag->m_tmp_a_buf){ b = mk_win_kernel_memory_management_virtual_free(mkdefrag->m_tmp_a_buf, 0, mk_win_kernel_memory_management_type_e_release); mk_lang_check_return(b != 0); }
	if(mkdefrag->m_tmp_b_buf){ b = mk_win_kernel_memory_management_virtual_free(mkdefrag->m_tmp_b_buf, 0, mk_win_kernel_memory_management_type_e_release); mk_lang_check_return(b != 0); }
	if(mkdefrag->m_volume_bitmap_buf){ b = mk_win_kernel_memory_management_virtual_free(mkdefrag->m_volume_bitmap_buf, 0, mk_win_kernel_memory_management_type_e_release); mk_lang_check_return(b != 0); }
	if(mkdefrag->m_file_pointers_buf){ b = mk_win_kernel_memory_management_virtual_free(mkdefrag->m_file_pointers_buf, 0, mk_win_kernel_memory_management_type_e_release); mk_lang_check_return(b != 0); }
	mk_sl_vector_fff_rw_destroy(&mkdefrag->m_fffs);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t process_path_root(mk_win_base_wchar_lpt const str, mk_lang_types_sint_t const len, mk_lang_types_sint_t const cap) mk_lang_noexcept
{
	mkdefrag_t mkdefrag;
	mk_lang_types_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 0);
	mk_lang_assert(cap >= mk_win_base_page_64k);

	err = mkdefrag_st_enable_backup(); mk_lang_check_rereturn(err);
	err = mkdefrag_rw_construct(&mkdefrag, str, len, cap); mk_lang_check_rereturn(err);
	err = mkdefrag_rw_adjust_name(&mkdefrag); mk_lang_check_rereturn(err);
	err = mkdefrag_ro_print_str(&mkdefrag); mk_lang_check_rereturn(err);
	err = mkdefrag_rw_append_dummy(&mkdefrag); mk_lang_check_rereturn(err);
	err = mkdefrag_rw_process_all(&mkdefrag); mk_lang_check_rereturn(err);
	err = mkdefrag_rw_destroy(&mkdefrag); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t process_path_current(mk_win_base_void_t) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_base_dword_t curr_dir_cap;
	mk_win_base_dword_t curr_dir_mem_len;
	mk_win_base_wchar_lpt curr_dir_str;
	mk_win_base_dword_t curr_dir_len;
	mk_lang_types_sint_t err;

	mk_lang_exception_make_none(&ex);
	curr_dir_cap = mk_win_base_page_64k;
	curr_dir_mem_len = curr_dir_cap * ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t)));
	mk_win_mallocator_main_heap_allocate(&ex, curr_dir_mem_len, ((mk_lang_types_void_ppt)(&curr_dir_str))); mk_lang_check_return(!mk_lang_exception_is(&ex) && curr_dir_str);
	curr_dir_len = mk_win_kernel_system_information_get_current_directory_w(curr_dir_cap, curr_dir_str); mk_lang_check_return(curr_dir_len != 0 && curr_dir_len < curr_dir_cap);
	err = process_path_root(curr_dir_str, ((mk_lang_types_sint_t)(curr_dir_len)), ((mk_lang_types_sint_t)(curr_dir_cap))); mk_lang_check_rereturn(err);
	mk_win_mallocator_main_heap_deallocate(curr_dir_str, curr_dir_mem_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t process_path_arg(mk_win_base_wchar_lpct const str, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_base_dword_t curr_dir_cap;
	mk_win_base_dword_t curr_dir_mem_len;
	mk_win_base_wchar_lpt curr_dir_str;
	mk_lang_types_sint_t err;

	mk_lang_assert(str);
	mk_lang_assert(len >= 1 && len <= mk_win_base_page_64k);

	mk_lang_exception_make_none(&ex);
	curr_dir_cap = mk_win_base_page_64k;
	curr_dir_mem_len = curr_dir_cap * ((mk_lang_types_sint_t)(sizeof(mk_win_base_wchar_t)));
	mk_win_mallocator_main_heap_allocate(&ex, curr_dir_mem_len, ((mk_lang_types_void_ppt)(&curr_dir_str))); mk_lang_check_return(!mk_lang_exception_is(&ex) && curr_dir_str);
	memcpyw_fn(curr_dir_str, str, len);
	err = process_path_root(curr_dir_str, len, ((mk_lang_types_sint_t)(curr_dir_cap))); mk_lang_check_rereturn(err);
	mk_win_mallocator_main_heap_deallocate(curr_dir_str, curr_dir_mem_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t process_cmd_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t first;
	mk_lang_types_bool_t at_least_one;
	mk_win_base_wchar_lpt cmd_line;
	mk_win_base_wchar_lpct ptr;
	mk_win_base_wchar_lpct arg;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	first = mk_lang_true;
	at_least_one = mk_lang_false;
	cmd_line = GetCommandLineW(); mk_lang_check_return(cmd_line && cmd_line[0] != L'\0');
	ptr = cmd_line;
	for(;;)
	{
		while(ptr[0] == L' ')
		{
			++ptr;
		}
		if(ptr[0] == L'\0')
		{
			break;
		}
		if(ptr[0] == L'"')
		{
			arg = ptr + 1;
			do
			{
				++ptr;
			}while(ptr[0] != L'"' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
			if(ptr[0] == L'"')
			{
				++ptr;
			}
		}
		else
		{
			arg = ptr;
			do
			{
				++ptr;
			}while(ptr[0] != L' ' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
		}
		if(len == 0)
		{
			continue;
		}
		if(first)
		{
			first = mk_lang_false;
		}
		else
		{
			at_least_one = mk_lang_true;
			err = process_path_arg(arg, len); mk_lang_check_rereturn(err);
		}
	}
	if(!at_least_one)
	{
		err = process_path_current(); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_types_sint_t mkdefrag_main(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_void_pt buff;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	g_out_file = mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_e_output); mk_lang_check_return(g_out_file.m_data != mk_win_base_handle_invalid);
	buff = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, mk_win_base_page_64k, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite); mk_lang_check_return(buff);
	err = mk_win_buffered_writer_rw_construct(&g_out_writer, g_out_file, buff, mk_win_base_page_64k); mk_lang_check_rereturn(err);
	mk_win_main_heap_init();
	mk_win_mallocator_main_heap_init();
	err = process_cmd_line(); mk_lang_check_rereturn(err);
	mk_win_mallocator_main_heap_deinit();
	mk_win_main_heap_deinit();
	err = mk_win_buffered_writer_rw_destroy(&g_out_writer); mk_lang_check_rereturn(err);
	b = mk_win_kernel_memory_management_virtual_free(buff, 0, mk_win_kernel_memory_management_type_e_release); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_types_sint_t mk_win_base_cdecl mainCRTStartup(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mkdefrag_main(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_c mk_lang_types_void_pt mk_win_base_cdecl memcpyu8_wrp(mk_lang_types_void_pt const dst, mk_lang_types_void_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	memcpyu8_fn(((mk_sl_cui_uint8_pt)(dst)), ((mk_sl_cui_uint8_pct)(src)), cnt);
	return dst;
}

#if defined NDEBUG

mk_lang_extern_c mk_lang_noreturn mk_lang_types_void_t mk_win_base_cdecl abort(mk_lang_types_void_t) mk_lang_noexcept
{
	ExitProcess(1);
}

#endif
