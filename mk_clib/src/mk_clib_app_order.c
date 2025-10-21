#ifndef mk_include_guard_mk_clib_app_order_c
#define mk_include_guard_mk_clib_app_order_c
#include "mk_clib_app_order.h"

#include "mk_sl_string.h"
#include "mk_lang_clobber.h"
#include "mk_lang_string.h"
#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
#include "mk_lang_check.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_roundup.h"
#include "mk_lang_rt.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_str_match.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_fmt.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_dynamic_ring.h"
#include "mk_sl_io_directory_iterator.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_speedometer.h"
#include "mk_sl_stopwatch.h"


mk_lang_extern_force_c mk_lang_types_sint_t mk_win_base_cdecl __CxxFrameHandler4(mk_lang_types_void_pt const a, mk_lang_types_void_pt const b, mk_lang_types_void_pt const c, mk_lang_types_void_pt const d) mk_lang_noexcept
{
	((mk_lang_types_void_t)(a));
	((mk_lang_types_void_t)(b));
	((mk_lang_types_void_t)(c));
	((mk_lang_types_void_t)(d));
	return 0;
}


#if mk_lang_bitness_is_16
#define mk_clib_app_order_buff_size 4 * 1024
#define mk_clib_app_order_buff_algn 4 * 1024
#elif mk_lang_bitness_is_32
#define mk_clib_app_order_buff_size 64 * 1024
#define mk_clib_app_order_buff_algn 64 * 1024
#elif mk_lang_bitness_is_64
#define mk_clib_app_order_buff_size 256 * 1024
#define mk_clib_app_order_buff_algn 256 * 1024
#endif
union mk_clib_app_order_buff_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lang_roundup_add(mk_clib_app_order_buff_size, mk_clib_app_order_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_order_buff_data_u mk_clib_app_order_buff_data_t;
struct mk_clib_app_order_buff_s
{
	mk_lang_alignas(mk_clib_app_order_buff_algn) mk_clib_app_order_buff_data_t m_data;
};
typedef struct mk_clib_app_order_buff_s mk_clib_app_order_buff_t;
mk_lang_typedef(mk_clib_app_order_buff);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_tchar_pct arg_hash_buf;
	mk_lang_tchar_pct arg_file_buf;
	mk_lang_types_sint_t arg_hash_len;
	mk_lang_types_sint_t arg_file_len;
/*
	mk_sl_speedometer_t speedometer;
	mk_lang_types_bool_t want;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lib_crypto_hash_stream_any2_t hasher;
	mk_sl_cui_uint8_pt ptr;
	mk_clib_app_order_buff_t buff;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t input_file;
	mk_lang_types_sint_t read;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t progress_str_a[64];
	mk_lang_tchar_t progress_str_b[2 * mk_lang_countof(progress_str_a)];
	mk_sl_cui_uint8_t digest[mk_lib_crypto_hash_stream_any1_digest_max_len_v];
*/
	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 0);
	}
	arg_hash_buf = argv[1];
	arg_file_buf = argv[2];
	arg_hash_len = lens[1];
	arg_file_len = lens[2]; ((mk_lang_types_void_t)(arg_file_len));
	return 0;
}

























struct mk_clib_app_order_dependency_s
{
	mk_sl_string_t m_name;
};
typedef struct mk_clib_app_order_dependency_s mk_clib_app_order_dependency_t;
mk_lang_typedef(mk_clib_app_order_dependency);

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_construct_void(mk_clib_app_order_dependency_pt const dependency) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);

	err = mk_sl_string_rw_construct(&dependency->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_construct_copy(mk_clib_app_order_dependency_pt const dependency, mk_clib_app_order_dependency_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);
	mk_lang_assert(src);

	err = mk_sl_string_rw_copy_construct(&dependency->m_name, &src->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_construct_move(mk_clib_app_order_dependency_pt const dependency, mk_clib_app_order_dependency_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);
	mk_lang_assert(src);

	err = mk_sl_string_rw_move_construct(&dependency->m_name, &src->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_assign_copy(mk_clib_app_order_dependency_pt const dependency, mk_clib_app_order_dependency_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);
	mk_lang_assert(src);

	err = mk_sl_string_rw_copy_assign(&dependency->m_name, &src->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_assign_move(mk_clib_app_order_dependency_pt const dependency, mk_clib_app_order_dependency_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);
	mk_lang_assert(src);

	err = mk_sl_string_rw_move_assign(&dependency->m_name, &src->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_destroy(mk_clib_app_order_dependency_pt const dependency) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);

	err = mk_sl_string_rw_destroy(&dependency->m_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_dependency_rw_set_name(mk_clib_app_order_dependency_pt const dependency, mk_lang_types_pchar_pct const name_buf, mk_lang_types_sint_t const name_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dependency);
	mk_lang_assert(name_buf || name_len == 0);
	mk_lang_assert(name_len >= 0);

	err = mk_sl_string_rw_clear(&dependency->m_name); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_push_back_copy_many(&dependency->m_name, name_buf, ((mk_lang_types_usize_t)(name_len))); mk_lang_check_rereturn(err);
	return 0;
}

#define mk_sl_vector_t_name mk_clib_app_order_dependencies
#define mk_sl_vector_t_element_type mk_clib_app_order_dependency_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_custom
#define mk_sl_vector_t_element_construct_void mk_clib_app_order_dependency_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_clib_app_order_dependency_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_clib_app_order_dependency_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_clib_app_order_dependency_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_clib_app_order_dependency_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_clib_app_order_dependency_rw_assign_move
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

struct mk_clib_app_order_file_s
{
	mk_sl_string_t m_name;
	mk_clib_app_order_dependencies_t m_dependencies;
};
typedef struct mk_clib_app_order_file_s mk_clib_app_order_file_t;
mk_lang_typedef(mk_clib_app_order_file);

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_construct_void(mk_clib_app_order_file_pt const file) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);

	err = mk_sl_string_rw_construct(&file->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_construct(&file->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_construct_copy(mk_clib_app_order_file_pt const file, mk_clib_app_order_file_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);
	mk_lang_assert(src);

	err = mk_sl_string_rw_copy_construct(&file->m_name, &src->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_copy_construct(&file->m_dependencies, &src->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_construct_move(mk_clib_app_order_file_pt const file, mk_clib_app_order_file_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);
	mk_lang_assert(src);

	err = mk_sl_string_rw_move_construct(&file->m_name, &src->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_move_construct(&file->m_dependencies, &src->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_assign_copy(mk_clib_app_order_file_pt const file, mk_clib_app_order_file_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);
	mk_lang_assert(src);

	err = mk_sl_string_rw_copy_assign(&file->m_name, &src->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_copy_assign(&file->m_dependencies, &src->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_assign_move(mk_clib_app_order_file_pt const file, mk_clib_app_order_file_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);
	mk_lang_assert(src);

	err = mk_sl_string_rw_move_assign(&file->m_name, &src->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_move_assign(&file->m_dependencies, &src->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_destroy(mk_clib_app_order_file_pt const file) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(file);

	err = mk_sl_string_rw_destroy(&file->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_destroy(&file->m_dependencies); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_file_rw_add_dependency(mk_clib_app_order_file_pt const file, mk_lang_types_pchar_pct const name_buf, mk_lang_types_sint_t const name_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_order_dependency_pt dependency;

	mk_lang_assert(file);
	mk_lang_assert(name_buf || name_len == 0);
	mk_lang_assert(name_len >= 0);

	err = mk_clib_app_order_dependencies_rw_reserve_additional(&file->m_dependencies, 1); mk_lang_check_rereturn(err);
	dependency = mk_clib_app_order_dependencies_rw_back(&file->m_dependencies) + 1;
	err = mk_clib_app_order_dependency_rw_construct_void(dependency); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependency_rw_set_name(dependency, name_buf, name_len); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_dependencies_rw_push_back_void(&file->m_dependencies, 1); mk_lang_check_rereturn(err);
	return 0;
}

#define mk_sl_vector_t_name mk_clib_app_order_files
#define mk_sl_vector_t_element_type mk_clib_app_order_file_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_custom
#define mk_sl_vector_t_element_construct_void mk_clib_app_order_file_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_clib_app_order_file_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_clib_app_order_file_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_clib_app_order_file_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_clib_app_order_file_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_clib_app_order_file_rw_assign_move
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

struct mk_clib_app_order_feature_s
{
	mk_sl_string_t m_name;
	mk_clib_app_order_files_t m_files;
};
typedef struct mk_clib_app_order_feature_s mk_clib_app_order_feature_t;
mk_lang_typedef(mk_clib_app_order_feature);

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_feature_rw_construct_void(mk_clib_app_order_feature_pt const feature) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(feature);

	err = mk_sl_string_rw_construct(&feature->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_files_rw_construct(&feature->m_files); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_feature_rw_destroy(mk_clib_app_order_feature_pt const feature) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(feature);

	err = mk_sl_string_rw_destroy(&feature->m_name); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_files_rw_destroy(&feature->m_files); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_feature_rw_set_name(mk_clib_app_order_feature_pt const feature, mk_lang_types_pchar_pct const name_buf, mk_lang_types_sint_t const name_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(feature);
	mk_lang_assert(name_buf || name_len == 0);
	mk_lang_assert(name_len >= 0);

	err = mk_sl_string_rw_clear(&feature->m_name); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_reserve_at_least(&feature->m_name, ((mk_lang_types_usize_t)(name_len + 1))); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_push_back_copy_many(&feature->m_name, name_buf, ((mk_lang_types_usize_t)(name_len))); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_add_and_remove_null_terminator(&feature->m_name); mk_lang_check_rereturn(err);
	return 0;
}

/* features */









#include "mk_lang_typedef.h"


struct mk_clib_app_order_s
{
	mk_sl_string_t m_path;
	mk_sl_string_t m_name;
	mk_sl_dynamic_ring_pc_t m_buffer;
	mk_sl_io_directory_iterator_t m_directory_iterator;
};
typedef struct mk_clib_app_order_s mk_clib_app_order_t;
mk_lang_typedef(mk_clib_app_order);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t find_str(mk_lang_types_pchar_pct const haystack_buf, mk_lang_types_sint_t const haystack_len, mk_lang_types_pchar_pct const needle_buf, mk_lang_types_sint_t const needle_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t m;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t f;

	mk_lang_assert(haystack_buf || haystack_len == 0);
	mk_lang_assert(haystack_len >= 0);
	mk_lang_assert(needle_buf || needle_len == 0);
	mk_lang_assert(needle_len >= 0);

	if(needle_len <= haystack_len)
	{
		n = haystack_len - needle_len + 1;
		for(i = 0; i != n; ++i)
		{
			m = needle_len;
			for(j = 0; j != m; ++j)
			{
				if(haystack_buf[i + j] != needle_buf[j])
				{
					break;
				}
			}
			if(j == m)
			{
				f = i;
				break;
			}
		}
		if(i == n)
		{
			f = -1;
		}
		else
		{
			mk_lang_clobber(&f);
		}
	}
	else
	{
		f = -1;
	}
	return f;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t find_nl(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t f;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	f = find_str(str_buf, str_len, "\x0d\x0a", 2);
	return f;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_rw_construct(mk_clib_app_order_pt const order) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(order);

	err = mk_sl_string_rw_construct(&order->m_path); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_construct(&order->m_name); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_pc_rw_construct(&order->m_buffer); mk_lang_check_rereturn(err);
	err = mk_sl_io_directory_iterator_rw_construct_void(&order->m_directory_iterator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_rw_destroy(mk_clib_app_order_pt const order) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(order);

	err = mk_sl_string_rw_destroy(&order->m_path); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_destroy(&order->m_name); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_pc_rw_destroy(&order->m_buffer); mk_lang_check_rereturn(err);
	err = mk_sl_io_directory_iterator_rw_destroy(&order->m_directory_iterator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_rw_set_path(mk_clib_app_order_pt const order, mk_lang_types_pchar_pct const path) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(order);
	mk_lang_assert(path);
	mk_lang_assert(path[0] != '\0');

	err = mk_sl_string_rw_clear(&order->m_path); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_push_back_copy_many(&order->m_path, path, ((mk_lang_types_usize_t)(mk_lang_str_len_n(path)))); mk_lang_check_rereturn(err);
	err = mk_sl_io_directory_iterator_rw_reset(&order->m_directory_iterator); mk_lang_check_rereturn(err);
	err = mk_sl_io_directory_iterator_rw_construct(&order->m_directory_iterator, path); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_pr_process_line(mk_clib_app_order_pt const order, mk_lang_types_pchar_pct const line_buf, mk_lang_types_sint_t const line_len) mk_lang_noexcept
{
	//mk_lang_types_pchar_t const prefix[] = "#include \"";

	mk_lang_assert(order);
	mk_lang_assert(line_buf || line_len == 0);
	mk_lang_assert(line_len >= 0);

	((void)(order));
	((void)(line_buf));
	((void)(line_len));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_pr_process_buffer(mk_clib_app_order_pt const order, mk_sl_dynamic_ring_pc_pt const string) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_pct ptr;
	mk_lang_types_sint_t nl;
	mk_lang_types_sint_t err;

	mk_lang_assert(string);
	mk_lang_assert(mk_sl_dynamic_ring_pc_ro_is_consolidated(string));

	for(;;)
	{
		len = mk_sl_dynamic_ring_pc_ro_get_sise_a(string); mk_lang_assert(len >= 0);
		ptr = mk_sl_dynamic_ring_pc_ro_get_data_a(string); mk_lang_assert(ptr || len == 0);
		nl = find_nl(ptr, len);
		if(nl == -1)
		{
			break;
		}
		mk_lang_assert(nl < len);
		err = mk_clib_app_order_pr_process_line(order, ptr, nl); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_pc_rw_pop_front_many(string, ((mk_lang_types_usize_t)(nl + 2))); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_pr_process_file_obj(mk_clib_app_order_pt const order, mk_sl_io_reader_file_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t chunk_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_pt ptr;
	mk_lang_types_sint_t read;

	mk_lang_assert(order);
	mk_lang_assert(reader);

	chunk_len = 4 * 1024;
	err = mk_sl_dynamic_ring_pc_rw_clear(&order->m_buffer); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_dynamic_ring_pc_rw_reserve_additional(&order->m_buffer, ((mk_lang_types_usize_t)(chunk_len))); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_pc_rw_push_back_void(&order->m_buffer, ((mk_lang_types_usize_t)(chunk_len))); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_pc_rw_consolidate(&order->m_buffer); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_pc_rw_pop_back_many(&order->m_buffer, ((mk_lang_types_usize_t)(chunk_len))); mk_lang_check_rereturn(err);
		len = mk_sl_dynamic_ring_pc_rw_get_sise_a(&order->m_buffer);
		ptr = mk_sl_dynamic_ring_pc_rw_get_data_a(&order->m_buffer) + len;
		err = mk_sl_io_reader_file_read(reader, ((mk_sl_cui_uint8_pt)(ptr)), chunk_len, &read); mk_lang_check_rereturn(err);
		if(read == 0)
		{
			break;
		}
		err = mk_sl_dynamic_ring_pc_rw_push_back_void(&order->m_buffer, ((mk_lang_types_usize_t)(read))); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_pr_process_buffer(order, &order->m_buffer); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_pr_process_file_name(mk_clib_app_order_pt const order, mk_lang_types_pchar_pct const file_name_buf) mk_lang_noexcept
{
	mk_lang_types_sint_t file_name_len;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_t nul;
	mk_sl_io_reader_file_t reader;

	mk_lang_assert(order);
	mk_lang_assert(file_name_buf);
	mk_lang_assert(file_name_buf[0] != '\0');

	if
	(!(
		(file_name_buf[0] == '.' && file_name_buf[1] == '\0') ||
		(file_name_buf[0] == '.' && file_name_buf[1] == '.' && file_name_buf[2] == '\0') ||
		(mk_lang_false)
	))
	{
		file_name_len = mk_lang_str_len_n(file_name_buf); mk_lang_assert(file_name_len >= 1); mk_lang_assert(file_name_len < s_mk_win_dll_kernel_files_max_path);
		err = mk_sl_string_rw_clear(&order->m_name); mk_lang_check_rereturn(err);
		err = mk_sl_string_rw_push_back_copy_many(&order->m_name, file_name_buf, ((mk_lang_types_usize_t)(file_name_len))); mk_lang_check_rereturn(err);
		err = mk_sl_string_rw_push_back_copy_many(&order->m_path, file_name_buf, ((mk_lang_types_usize_t)(file_name_len))); mk_lang_check_rereturn(err);
		nul = '\0'; err = mk_sl_string_rw_push_back_copy_single(&order->m_path, &nul); mk_lang_check_rereturn(err);
		err = mk_sl_io_reader_file_open_n(&reader, mk_sl_string_ro_data(&order->m_path)); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_pr_process_file_obj(order, &reader); mk_lang_check_rereturn(err);
		err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
		err = mk_sl_string_rw_pop_back_many(&order->m_path, ((mk_lang_types_usize_t)(file_name_len + 1))); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_rw_run(mk_clib_app_order_pt const order) mk_lang_noexcept
{
	mk_lang_types_pchar_t star;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct file_name_buf;
	mk_lang_types_bool_t is_done;

	mk_lang_assert(order);

	star = '*';
	for(;;)
	{
		err = mk_sl_io_directory_iterator_rw_get_name(&order->m_directory_iterator, &file_name_buf); mk_lang_check_rereturn(err);
		err = mk_sl_string_rw_pop_back_single(&order->m_path); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_pr_process_file_name(order, file_name_buf); mk_lang_check_rereturn(err);
		err = mk_sl_string_rw_push_back_copy_single(&order->m_path, &star); mk_lang_check_rereturn(err);
		err = mk_sl_io_directory_iterator_rw_next(&order->m_directory_iterator); mk_lang_check_rereturn(err);
		err = mk_sl_io_directory_iterator_rw_is_end(&order->m_directory_iterator, &is_done); mk_lang_check_rereturn(err);
		if(is_done)
		{
			break;
		}
	}
	return 0;
}
















mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[512];

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("Example usage:")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t SHA-1 message.txt")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t SHA3-512 video.avi")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("Available algorithms:")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);


	{
		mk_lang_types_pchar_pct path;
		mk_clib_app_order_t order;

		path = "c:\\dev\\mnt\\mkdisk\\dev\\repos\\mk_clib_wtb\\mk_clib\\src\\*";
		err = mk_clib_app_order_rw_construct(&order); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_rw_set_path(&order, path); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_rw_run(&order); mk_lang_check_rereturn(err);
		err = mk_clib_app_order_rw_destroy(&order); mk_lang_check_rereturn(err);
	}
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_order_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_order_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_order_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_order_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	mk_lang_cpuid_init();
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_init(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_order_wargs(argc, &argv[0], &lens[0]);
	err = mk_sl_mallocator_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_order_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[3];

	mk_lang_cpuid_init();
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_order_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		lens[0] = mk_lang_str_len_t(argv[0]);
		lens[1] = mk_lang_str_len_t(argv[1]);
		lens[2] = mk_lang_str_len_t(argv[2]);
		err = mk_clib_app_order_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	err = mk_sl_mallocator_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
