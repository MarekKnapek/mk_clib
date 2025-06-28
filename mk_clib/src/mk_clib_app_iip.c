#ifndef mk_include_guard_mk_clib_app_iip_c
#define mk_include_guard_mk_clib_app_iip_c
#include "mk_clib_app_iip.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
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
#include "mk_lang_runtime_bool.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_client_connection.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_random.h"
#include "mk_sl_time.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);

	err = mk_lib_iip_crypt_elgamal_key_pri_generate_random(&destination->m_key_elgamal_pri); mk_lang_check_rereturn(err);
	err = mk_lib_iip_crypt_dsa_sha1_key_pri_generate_random(&destination->m_key_dsa_sha1_pri); mk_lang_check_rereturn(err);
	mk_lib_iip_crypt_elgamal_key_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_writer_file_open_n(&writer, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_writer_file_open_n(&writer, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_elgamal_pub_single_to_str_hexf_n(&destination->m_key_elgamal_pub.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pub.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(destination); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(destination, file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(destination); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(destination, file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];
	mk_lang_types_bool_t is_valid;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_reader_file_open_n(&reader, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pri_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);

	is_valid = mk_lib_iip_crypt_dsa_sha1_key_pri_is_valid(&destination->m_key_dsa_sha1_pri); mk_lang_check_return(is_valid);
	mk_lib_iip_crypt_elgamal_key_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_reader_file_open_n(&reader, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pri_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pub_single_from_str_hex_n(&destination->m_key_elgamal_pub.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_from_str_hex_n(&destination->m_key_dsa_sha1_pub.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_s
{
	mk_lib_iip_cp_client_connection_tasks_t m_connections;
	mk_lang_types_usize_t m_last_connection_idx;
	//mk_lib_net_waitables_vrt_t m_waitables;
	//mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_iip_destination;
	//mk_lib_iip_cp_types_sessionid_t m_session_id;
};
typedef struct mk_clib_app_iip_s mk_clib_app_iip_t;
mk_lang_typedef(mk_clib_app_iip);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_construct(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_lib_iip_cp_client_connection_tasks_rw_construct(&app->m_connections); mk_lang_check_rereturn(err);
	app->m_last_connection_idx = 0;
	//err = mk_lib_net_waitables_vrt_rw_construct_void(&app->m_waitables); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_destroy(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_lib_iip_cp_client_connection_tasks_rw_destroy(&app->m_connections); mk_lang_check_rereturn(err);
	//err = mk_lib_net_waitables_vrt_rw_destroy(&app->m_waitables); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_step(mk_clib_app_iip_pt const app, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_bool_t would_block;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_connection_task_ppt connection_ptr;
	mk_lib_iip_cp_client_connection_task_pt connection_obj;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	count = mk_lib_iip_cp_client_connection_tasks_rw_size(&app->m_connections);
	if(count != 0)
	{
		would_block = mk_lang_false;
		n = count;
		for(i = 0; i != n; ++i)
		{
			idx = app->m_last_connection_idx % count;
			++app->m_last_connection_idx;
			connection_ptr = mk_lib_iip_cp_client_connection_tasks_rw_at(&app->m_connections, idx); mk_lang_assert(connection_ptr); connection_obj = *connection_ptr; mk_lang_assert(connection_obj);
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
			err = mk_lib_iip_cp_client_connection_task_rw_step(connection_obj, allow_to_block, &stp_res); mk_lang_check_rereturn(err);
			if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_something)
			{
				*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
				break;
			}
			if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_would_block)
			{
				would_block = mk_lang_true;
			}
		}
		if(i == n)
		{
			if(would_block)
			{
				*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
			}
			else
			{
				*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
			}
		}
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_prrw_run_single_blocking(mk_clib_app_iip_pt const app, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t allow_to_block;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	allow_to_block = mk_lang_true;
	stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
	err = mk_clib_app_iip_rw_step(app, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_run_non_blocking_result(mk_clib_app_iip_pt const app, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t allow_to_block;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	allow_to_block = mk_lang_false;
	do
	{
		stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
		err = mk_clib_app_iip_rw_step(app, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	}while(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_something);
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_run_non_blocking_void(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
	err = mk_clib_app_iip_rw_run_non_blocking_result(app, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_run_force(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_result_t step_result;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	for(;;)
	{
		step_result = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
		err = mk_clib_app_iip_rw_run_non_blocking_result(app, &step_result); mk_lang_check_rereturn(err); mk_lang_assert(step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
		if(step_result == mk_lib_iip_cp_client_connection_task_result_e_did_nothing)
		{
			break;
		}
		step_result = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
		err = mk_clib_app_iip_prrw_run_single_blocking(app, &step_result); mk_lang_check_rereturn(err); mk_lang_assert(step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
		if(step_result == mk_lib_iip_cp_client_connection_task_result_e_did_nothing)
		{
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_new_connection(mk_clib_app_iip_pt const app, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_handle_pt const connection_handle) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_connection_task_pt connection;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_connection_handle_t handle;

	mk_lang_assert(app);
	mk_lang_assert(settings);
	mk_lang_assert(connection_handle);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*connection), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); connection = ((mk_lib_iip_cp_client_connection_task_pt)(mem)); mk_lang_assert(connection);
	handle.m_elements[0] = ((mk_lib_iip_cp_client_connection_handle_base_t)(connection));
	err = mk_lib_iip_cp_client_connection_task_rw_construct(connection, settings); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_tasks_rw_push_back_move_single(&app->m_connections, &connection); mk_lang_check_rereturn(err);
	*connection_handle = handle;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_rw_new_session(mk_clib_app_iip_pt const app, mk_lib_iip_cp_client_connection_handle_pt const connection_handle, mk_lib_iip_cp_client_session_settings_pct const session_settings, mk_lib_iip_cp_client_session_handle_pt const session_handle) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt connection;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lib_iip_cp_client_session_handle_t handle;

	mk_lang_assert(app);
	mk_lang_assert(connection_handle);
	mk_lang_assert(session_settings);
	mk_lang_assert(session_handle);

	connection = ((mk_lib_iip_cp_client_connection_task_pt)(connection_handle->m_elements[0])); mk_lang_assert(connection);
	err = mk_lib_iip_cp_client_connection_task_rw_new_session(connection, session_settings, &session); mk_lang_check_rereturn(err); mk_lang_assert(session);
	handle.m_elements[0] = ((mk_lib_iip_cp_client_session_handle_base_t)(session));
	*session_handle = handle;
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_from_cmd_line(mk_lib_iip_cp_client_connection_settings_pt settings, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t param_idx;
	mk_lang_tchar_pct param_buf;
	mk_lang_types_sint_t param_len;
	mk_lang_types_pchar_t param_store[64];
	mk_lang_types_pchar_pct param_ptr;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(settings);
	mk_lang_assert(argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	mk_lang_check_return(argc == 3);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 1);
	}

	param_idx = 1;
	param_buf = argv[param_idx];
	param_len = lens[param_idx];
	param_len = mk_lang_min(param_len, mk_lang_countof(param_store));
	mk_lang_tchar_to_bi_pchar_many(&param_buf[0], &param_store[0], param_len);
	param_ptr = &param_store[0];

	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));

	param_idx = 2;
	param_buf = argv[param_idx];
	param_len = lens[param_idx];
	param_len = mk_lang_min(param_len, mk_lang_countof(param_store));
	mk_lang_tchar_to_bi_pchar_many(&param_buf[0], &param_store[0], param_len);
	param_ptr = &param_store[0];

	err = mk_lib_net_tcp_port_parse_pc(&settings->m_destination.m_tcp_port, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_check_return(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	settings->m_authentication.m_user_name.m_len = 0;

	settings->m_authentication.m_password.m_len = 0;

	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_from_hardcoded_k_ip[] = "127.0.0.1";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_from_hardcoded_k_port[] = "7654";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_from_hardcoded(mk_lib_iip_cp_client_connection_settings_pt settings) mk_lang_noexcept
{
	mk_lang_types_pchar_pct param_ptr;
	mk_lang_types_sint_t param_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(settings);

	param_ptr = &mk_clib_app_iip_parse_settings_from_hardcoded_k_ip[0];
	param_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_from_hardcoded_k_ip);

	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));

	param_ptr = &mk_clib_app_iip_parse_settings_from_hardcoded_k_port[0];
	param_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_from_hardcoded_k_port);

	err = mk_lib_net_tcp_port_parse_pc(&settings->m_destination.m_tcp_port, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_check_return(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	settings->m_authentication.m_user_name.m_len = 0;

	settings->m_authentication.m_password.m_len = 0;

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_connection_settings_t connection_settings_1;
	mk_lib_iip_cp_client_session_settings_t session_settings_1;
	mk_lib_iip_cp_client_session_settings_t session_settings_2;
	/*mk_lib_iip_cp_client_connection_settings_t settings_2;
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t destination_3;
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t destination_4;*/
	mk_clib_app_iip_t app;
	mk_lib_iip_cp_client_connection_handle_t connection_1;
	mk_lib_iip_cp_client_session_handle_t session_1;
	mk_lib_iip_cp_client_session_handle_t session_2;
	/*mk_lib_iip_cp_client_connection_handle_t connection_2;
	mk_lib_iip_cp_client_session_handle_t session_3;
	mk_lib_iip_cp_client_session_handle_t session_4;*/

	err = mk_clib_app_iip_parse_settings_from_cmd_line(&connection_settings_1, argc, argv, lens); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&session_settings_1.m_destination, "destination1.txt"); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&session_settings_2.m_destination, "destination2.txt"); mk_lang_check_rereturn(err);
	session_settings_2.m_destination.m_key_elgamal_pri = session_settings_1.m_destination.m_key_elgamal_pri;
	session_settings_2.m_destination.m_key_elgamal_pub = session_settings_1.m_destination.m_key_elgamal_pub;

	/*err = mk_clib_app_iip_parse_settings_from_hardcoded(&settings_2); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&destination_3, "destination3.txt"); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&destination_4, "destination4.txt"); mk_lang_check_rereturn(err);*/

	err = mk_clib_app_iip_rw_construct(&app); mk_lang_check_rereturn(err);

	err = mk_clib_app_iip_rw_new_connection(&app, &connection_settings_1, &connection_1); mk_lang_check_rereturn(err);

	mk_lib_iip_cp_client_session_handle_set_zero(&session_settings_1.m_master_session);
	err = mk_clib_app_iip_rw_new_session(&app, &connection_1, &session_settings_1, &session_1); mk_lang_check_rereturn(err);

	session_settings_2.m_master_session = session_1;
	err = mk_clib_app_iip_rw_new_session(&app, &connection_1, &session_settings_2, &session_2); mk_lang_check_rereturn(err);

	err = mk_clib_app_iip_rw_run_force(&app); mk_lang_check_rereturn(err);

	/*err = mk_clib_app_iip_rw_new_connection(&app, &settings_2, &connection_2); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_session(&app, &connection_2, &destination_3, &session_3); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_session(&app, &connection_2, &destination_4, &session_4); mk_lang_check_rereturn(err);*/


	/*err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_rw_new_connection(&app, &settings, &connection); mk_lang_check_rereturn(err);*/

	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_only(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_pub(&destination_1, "destination3.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_only(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/

	err = mk_clib_app_iip_rw_destroy(&app); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[4 * 1024];
	mk_sl_time_timestamp_t time_val;
	mk_lang_types_sint_t time_len;
	mk_lang_types_pchar_t time_str[mk_sl_time_k_str_len];

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("iip")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("exe name: %t")), exe_name, exe_len); mk_lang_check_return(len >= 1); mk_lang_check_return(len <= mk_lang_countof(buf)); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	mk_sl_time_timestamp_get_now(&time_val);
	time_len = mk_sl_time_timestamp_to_text(&time_val, &time_str[0], mk_lang_countof(time_str)); mk_lang_assert(time_len == mk_lang_countof(time_str));
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("time: %ht")), &time_str[0], time_len); mk_lang_check_return(len >= 1); mk_lang_check_return(len <= mk_lang_countof(buf)); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_iip_cp_mallocator_global_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_iip_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_iip_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}

#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_iip_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_iip_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_iip_global_deinit(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n("Gud.");
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_iip_args(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	err = mk_clib_app_iip_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(std_argc, std_argv, &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_iip_global_deinit(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n("Gud.");
	return 0;
}


#endif


#endif
