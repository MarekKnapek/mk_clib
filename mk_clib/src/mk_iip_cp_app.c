#include "mk_iip_cp_base.h"
#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_client_intr.h"
#include "mk_iip_cp_destination.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_message_serialize.h"
#include "mk_iip_cp_session_intr.h"
#include "mk_iip_cp_socket_tcp_intr.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_string.h"
#include "mk_lang_stringify.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_fmt.h"
#include "mk_lib_zlib.h"
#include "mk_sl_io_console.h"
#include "mk_sl_net_windows.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"
#include "mk_win_kernel_console.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static mk_lang_types_bool_t mk_iip_cp_app_g_ctrl_c;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_starting(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_starting_str "Starting.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_starting_str[0])), mk_lang_countstr(main_log_starting_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_generate_destination_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_generate_destination_beg_str ">>> Generate new destination.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_generate_destination_beg_str[0])), mk_lang_countstr(main_log_generate_destination_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_generate_destination_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_generate_destination_end_str "<<< Generate new destination.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_generate_destination_end_str[0])), mk_lang_countstr(main_log_generate_destination_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_connect_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_connect_beg_str ">>> Connect to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_connect_beg_str[0])), mk_lang_countstr(main_log_connect_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_connect_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_connect_end_str "<<< Connect to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_connect_end_str[0])), mk_lang_countstr(main_log_connect_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_create_session_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_create_session_beg_str ">>> Create session.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_create_session_beg_str[0])), mk_lang_countstr(main_log_create_session_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_create_session_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_create_session_end_str "<<< Create session.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_create_session_end_str[0])), mk_lang_countstr(main_log_create_session_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_query_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_query_beg_str ">>> Query domain name.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_query_beg_str[0])), mk_lang_countstr(main_log_query_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_query_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_query_end_str "<<< Query domain name.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_query_end_str[0])), mk_lang_countstr(main_log_query_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_accept_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_accept_beg_str ">>> Accept.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_accept_beg_str[0])), mk_lang_countstr(main_log_accept_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_accept_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_accept_end_str "<<< Accept.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_accept_end_str[0])), mk_lang_countstr(main_log_accept_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_read_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_read_beg_str ">>> Read.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_read_beg_str[0])), mk_lang_countstr(main_log_read_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_read_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_read_end_str "<<< Read.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_read_end_str[0])), mk_lang_countstr(main_log_read_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_beg_str ">>> Send data.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_beg_str[0])), mk_lang_countstr(main_log_send_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_end_str "<<< Send data.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_end_str[0])), mk_lang_countstr(main_log_send_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_close_sessions_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_close_sessions_beg_str ">>> Send close sessions messages to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_close_sessions_beg_str[0])), mk_lang_countstr(main_log_send_close_sessions_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_close_sessions_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_close_sessions_end_str "<<< Send close sessions messages to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_close_sessions_end_str[0])), mk_lang_countstr(main_log_send_close_sessions_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_disconnect_beg(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_disconnect_beg_str ">>> Send disconnect message to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_disconnect_beg_str[0])), mk_lang_countstr(main_log_send_disconnect_beg_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_send_disconnect_end(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_send_disconnect_end_str "<<< Send disconnect message to I2P I2CP server.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_send_disconnect_end_str[0])), mk_lang_countstr(main_log_send_disconnect_end_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_ending(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_ending_str "Ending.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_ending_str[0])), mk_lang_countstr(main_log_ending_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t main_log_gud(mk_lang_types_void_t) mk_lang_noexcept
{
	#define main_log_gud_str "Gud.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&main_log_gud_str[0])), mk_lang_countstr(main_log_gud_str)); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_iip_cp_app_arg_generate_destination[] = "/generate_destination";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_iip_cp_app_arg_use_destination[] = "/use_destination";


#define mk_iip_cp_default_ipv4_d "127.0.0.1"
#define mk_iip_cp_default_port_tcp_num_d 8654
#define mk_iip_cp_default_port_tcp_str_d mk_lang_stringify(mk_iip_cp_default_port_tcp_num_d)
#define mk_iip_cp_default_username "a"
#define mk_iip_cp_default_password "a"
#define mk_iip_cp_default_nickname "mkiipcp"
#define mk_iip_cp_default_domain "reg.i2p"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_generate_destination_inner(mk_iip_cp_type_destination_elgamal_dsa_pt destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_intr_t client;
	mk_iip_cp_client_data_request_generate_destination_t request_generate_destination;
	mk_iip_cp_client_data_response_generate_destination_t response_generate_destination;

	mk_lang_assert(destination);

	err = main_log_starting(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_construct(&client); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_tick_until_idle(&client); mk_lang_check_rereturn(err);

	err = main_log_generate_destination_beg(); mk_lang_check_rereturn(err);
	request_generate_destination.m_destination = destination;
	response_generate_destination.m_destination = mk_lang_null;
	err = mk_iip_cp_client_intr_rw_generate_destination(&client, &request_generate_destination, &response_generate_destination); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_tick_until_idle(&client); mk_lang_check_rereturn(err);
	mk_lang_check_return(response_generate_destination.m_destination == destination);
	err = main_log_generate_destination_end(); mk_lang_check_rereturn(err);

	err = main_log_ending(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_destruct(&client); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_generate_destination(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_type_destination_elgamal_dsa_t my_destination;
	FILE* f;
	mk_lang_types_usize_t sz;
	mk_lang_types_sint_t st;

	mk_lang_assert(argc == 3 && mk_lang_strlen_n_fn(argv[1]) == mk_lang_countstr(mk_iip_cp_app_arg_generate_destination) && mk_lang_string_memcmp_pc_fn(argv[1], &mk_iip_cp_app_arg_generate_destination[0], mk_lang_countstr(mk_iip_cp_app_arg_generate_destination)) == 0);

	err = mk_iip_cp_app_generate_destination_inner(&my_destination); mk_lang_check_rereturn(err);
	f = fopen(argv[2], "wb"); mk_lang_check_return(f);
	sz = fwrite(&my_destination, 1, sizeof(my_destination), f); mk_lang_check_return(sz == sizeof(my_destination));
	st = fclose(f); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_compress(mk_iip_cp_type_buffer_pct const in, mk_iip_cp_type_buffer_pt const out) mk_lang_noexcept
{
	/*mk_lang_types_sint_t idx;
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(in);
	mk_lang_assert(out);
	mk_lang_assert(in != out);

	idx = -1;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x1f;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x8b;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x08;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x00;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x00;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x00;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x00;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x00;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x02;
	((mk_lang_types_uchar_pt)(&out->m_buf[0]))[++idx] = 0x06;
	st = mk_lib_zlib_compress2(&in->m_buf[0], in->m_len, 0, &out->m_buf[0 + 10], mk_lang_countof(out->m_buf) - 10, &out_len); mk_lang_check_return(st == 0);
	out->m_len = 10 + out_len;*/
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t get_get(mk_lang_types_pchar_pt const getstr, mk_lang_types_sint_t const getlen, mk_lang_types_pchar_pct const domain, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	#define crlf "\x0d\x0a"
	char const fmt[] = ""
		"GET / HTTP/1.1" crlf
		"Host: %s" crlf
		"User-Agent: MYOB/6.66 (AN/ON)" crlf
		"Connection: close" crlf
		"Pragma: no-cache" crlf
		"Cache-Control: no-cache" crlf
		crlf;

	mk_lang_types_sint_t len;

	mk_lang_assert(getstr);
	mk_lang_assert(getlen);
	mk_lang_assert(domain);
	mk_lang_assert(outlen);

	len = mk_lib_fmt_n_snnprintf(getstr, getlen, fmt, mk_lang_countstr(fmt), domain); mk_lang_check_return(len >= 1);
	*outlen = len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_destination_elgamal_dsa(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_destination_elgamal_dsa_pct const obj) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_log_destination(mk_iip_cp_type_destination_elgamal_dsa_pct const my_destination) mk_lang_noexcept
{
	#define mk_iip_cp_app_log_destination_fmt "Destination: %s.b32.i2p.\n"

	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t buff[4 * 1024];
	mk_iip_cp_message_serialize_errcode_t errcode;
	mk_lang_types_sint_t consumed;
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_block_sha2_256_digest_t digest;
	mk_lang_types_pchar_t b32_str[2 * mk_lib_crypto_hash_block_sha2_base_32bit_c_digest_len + 1];
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str[512];

	err = mk_iip_cp_message_serialize_destination_elgamal_dsa(&buff[0], mk_lang_countof(buff), &errcode, &consumed, my_destination); mk_lang_check_rereturn(err);
	mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
	mk_lib_crypto_hash_stream_sha2_256_append_u8(&hasher, &buff[0], consumed);
	mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
	mk_iip_cp_helper_base32_u8s_to_pchars(&digest.m_uint8s[0], mk_lib_crypto_hash_block_sha2_base_32bit_c_digest_len, &b32_str[0], &len); b32_str[len] = '\0';
	len = mk_lib_fmt_n_snnprintf(&str[0], mk_lang_countof(str), &mk_iip_cp_app_log_destination_fmt[0], mk_lang_countstr(mk_iip_cp_app_log_destination_fmt), &b32_str[0]); mk_lang_assert(len >= 1);
	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&str[0])), len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_use_destination_inner(mk_iip_cp_client_intr_pt const client, mk_iip_cp_type_destination_elgamal_dsa_pct const my_destination) mk_lang_noexcept
{
	mk_iip_cp_connection_intr_pt connection;
	mk_iip_cp_session_intr_pt session;
	mk_iip_cp_type_string_t remote_hostname;
	mk_iip_cp_type_buffer_t remote_destination_a;
	mk_iip_cp_type_destination_with_cert_t remote_destination_b;
	mk_iip_cp_destination_t local_destination;
	mk_iip_cp_socket_tcp_intr_t socket;
	mk_iip_cp_type_buffer_t payload;

	mk_iip_cp_client_data_request_connect_t request_connect;
	mk_iip_cp_client_data_response_connect_t response_connect;
	mk_iip_cp_client_data_request_create_session_t request_create_session;
	mk_iip_cp_client_data_response_create_session_t response_create_session;
	mk_iip_cp_client_data_request_host_lookup_t request_host_lookup;
	mk_iip_cp_client_data_response_host_lookup_t response_host_lookup;
	mk_iip_cp_client_data_request_accept_t request_accept;
	mk_iip_cp_client_data_response_accept_t response_accept;
	mk_iip_cp_client_data_request_read_data_t request_read_data;
	mk_iip_cp_client_data_response_read_data_t response_read_data;

	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(client);
	mk_lang_assert(my_destination);

	mk_lang_clobber(&connection);
	mk_lang_clobber(&session);
	err = mk_iip_cp_socket_tcp_intr_rw_construct(&socket); mk_lang_check_rereturn(err);

	if(!mk_iip_cp_app_g_ctrl_c)
	{
		err = main_log_connect_beg(); mk_lang_check_rereturn(err);
		request_connect.m_ipv4_str_buf = mk_iip_cp_default_ipv4_d;
		request_connect.m_ipv4_str_len = mk_lang_countstr(mk_iip_cp_default_ipv4_d);
		request_connect.m_tcp_port_str_buf = mk_iip_cp_default_port_tcp_str_d;
		request_connect.m_tcp_port_str_len = mk_lang_countstr(mk_iip_cp_default_port_tcp_str_d);
		request_connect.m_username_str_buf = mk_iip_cp_default_username;
		request_connect.m_username_str_len = mk_lang_countstr(mk_iip_cp_default_username);
		request_connect.m_password_str_buf = mk_iip_cp_default_password;
		request_connect.m_password_str_len = mk_lang_countstr(mk_iip_cp_default_password);
		err = mk_iip_cp_client_intr_rw_connect_to_i2cp(client, &request_connect, &response_connect); mk_lang_check_rereturn(err);
		do
		{
			do
			{
				err = mk_iip_cp_client_intr_rw_tick_single2(client, 100); mk_lang_check_rereturn(err);
			}while(mk_iip_cp_client_intr_rw_did_something(client) && !response_connect.m_done && !mk_iip_cp_app_g_ctrl_c);
		}while(!response_connect.m_done && !mk_iip_cp_app_g_ctrl_c);
		if(!mk_iip_cp_app_g_ctrl_c)
		{
			mk_lang_assert(response_connect.m_done);
			mk_lang_check_return(response_connect.m_success && response_connect.m_connection);
			connection = response_connect.m_connection;
		}
		err = main_log_connect_end(); mk_lang_check_rereturn(err);
	}

	if(!mk_iip_cp_app_g_ctrl_c)
	{
		err = main_log_create_session_beg(); mk_lang_check_rereturn(err);
		request_create_session.m_connection = connection;
		request_create_session.m_destination = my_destination;
		request_create_session.m_nickname_str_buf = mk_iip_cp_default_nickname;
		request_create_session.m_nickname_str_len = mk_lang_countstr(mk_iip_cp_default_nickname);
		err = mk_iip_cp_client_intr_rw_create_session(client, &request_create_session, &response_create_session); mk_lang_check_rereturn(err);
		do
		{
			do
			{
				err = mk_iip_cp_client_intr_rw_tick_single2(client, 100); mk_lang_check_rereturn(err);
			}while(mk_iip_cp_client_intr_rw_did_something(client) && !response_create_session.m_done && !mk_iip_cp_app_g_ctrl_c);
		}while(!response_create_session.m_done && !mk_iip_cp_app_g_ctrl_c);
		if(!mk_iip_cp_app_g_ctrl_c)
		{
			mk_lang_assert(response_create_session.m_done);
			mk_lang_check_return(response_create_session.m_success && response_create_session.m_session);
			session = response_create_session.m_session;
		}
		err = main_log_create_session_end(); mk_lang_check_rereturn(err);
	}

	if(mk_lang_check_false)
	{
		if(!mk_iip_cp_app_g_ctrl_c)
		{
			err = main_log_query_beg(); mk_lang_check_rereturn(err);
			remote_hostname.m_len = mk_lang_countstr(mk_iip_cp_default_domain);
			mk_lang_string_memcpy_pc_fn(&remote_hostname.m_buf[0], &mk_iip_cp_default_domain[0], mk_lang_countstr(mk_iip_cp_default_domain));
			request_host_lookup.m_connection = connection;
			request_host_lookup.m_session = session;
			request_host_lookup.m_hostname = &remote_hostname;
			request_host_lookup.m_destination = &remote_destination_a;
			err = mk_iip_cp_client_intr_rw_host_lookup(client, &request_host_lookup, &response_host_lookup); mk_lang_check_rereturn(err);
			do
			{
				do
				{
					err = mk_iip_cp_client_intr_rw_tick_single2(client, 100); mk_lang_check_rereturn(err);
				}while(mk_iip_cp_client_intr_rw_did_something(client) && !response_host_lookup.m_done && !mk_iip_cp_app_g_ctrl_c);
			}while(!response_host_lookup.m_done && !mk_iip_cp_app_g_ctrl_c);
			if(!mk_iip_cp_app_g_ctrl_c)
			{
				mk_lang_assert(response_host_lookup.m_done);
				mk_lang_check_return(response_host_lookup.m_success);
				err = mk_iip_cp_type_destination_with_cert_from_buffer(&remote_destination_b, &remote_destination_a); mk_lang_check_rereturn(err);
			}
			err = main_log_query_end(); mk_lang_check_rereturn(err);
		}
	}

	if(!mk_iip_cp_app_g_ctrl_c)
	{
		err = main_log_accept_beg(); mk_lang_check_rereturn(err);
		local_destination.m_destination = *my_destination;
		tsi = 80; mk_sl_cui_uint16_from_bi_sint(&local_destination.m_port, &tsi);
		err = mk_iip_cp_socket_tcp_intr_rw_bind(&socket, &local_destination); mk_lang_check_rereturn(err);
		request_accept.m_connection = connection;
		request_accept.m_session = session;
		request_accept.m_socket = &socket;
		request_accept.m_remote_destination = &remote_destination_a;
		err = mk_iip_cp_client_intr_rw_accept(client, &request_accept, &response_accept); mk_lang_check_rereturn(err);
		do
		{
			do
			{
				err = mk_iip_cp_client_intr_rw_tick_single2(client, 10 * 1000); mk_lang_check_rereturn(err);
			}while(mk_iip_cp_client_intr_rw_did_something(client) && !response_accept.m_done && !mk_iip_cp_app_g_ctrl_c);
		}while(!response_accept.m_done && !mk_iip_cp_app_g_ctrl_c);
		if(!mk_iip_cp_app_g_ctrl_c)
		{
			mk_lang_assert(response_accept.m_done);
			mk_lang_check_return(response_accept.m_success);
		}
		err = main_log_accept_end(); mk_lang_check_rereturn(err);
	}

	if(!mk_iip_cp_app_g_ctrl_c)
	{
		err = main_log_read_beg(); mk_lang_check_rereturn(err);
		payload.m_len = mk_lang_countof(payload.m_buf);
		request_read_data.m_connection = connection;
		request_read_data.m_session = session;
		request_read_data.m_socket = &socket;
		request_read_data.m_payload = &payload;
		err = mk_iip_cp_client_intr_rw_read_data(client, &request_read_data, &response_read_data); mk_lang_check_rereturn(err);
		do
		{
			do
			{
				err = mk_iip_cp_client_intr_rw_tick_single2(client, 2 * 1000); mk_lang_check_rereturn(err);
			}while(mk_iip_cp_client_intr_rw_did_something(client) && !response_read_data.m_done && !mk_iip_cp_app_g_ctrl_c);
		}while(!response_read_data.m_done && !mk_iip_cp_app_g_ctrl_c);
		if(!mk_iip_cp_app_g_ctrl_c)
		{
			mk_lang_assert(response_read_data.m_done);
			mk_lang_check_return(response_read_data.m_success);
		}
		err = main_log_read_end(); mk_lang_check_rereturn(err);
	}

	while(!mk_iip_cp_app_g_ctrl_c)
	{
		err = mk_iip_cp_client_intr_rw_tick_single2(client, 5 * 1000); mk_lang_check_rereturn(err);
	}

	err = mk_iip_cp_socket_tcp_intr_rw_destruct(&socket); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_use_destination(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	FILE* f;
	mk_lang_types_usize_t sz;
	mk_iip_cp_type_destination_elgamal_dsa_t my_destination;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t err;
	mk_iip_cp_client_intr_t client;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(argc == 3 && mk_lang_strlen_n_fn(argv[1]) == mk_lang_countstr(mk_iip_cp_app_arg_use_destination) && mk_lang_string_memcmp_pc_fn(argv[1], &mk_iip_cp_app_arg_use_destination[0], mk_lang_countstr(mk_iip_cp_app_arg_use_destination)) == 0);

	f = fopen(argv[2], "rb"); mk_lang_check_return(f);
	sz = fread(&my_destination, 1, sizeof(my_destination), f); mk_lang_check_return(sz == sizeof(my_destination));
	st = fclose(f); mk_lang_check_return(st == 0);

	err = mk_iip_cp_app_log_destination(&my_destination); mk_lang_check_rereturn(err);

	err = main_log_starting(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_construct(&client); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_tick_until_idle(&client); mk_lang_check_rereturn(err);

	err_b = mk_iip_cp_app_use_destination_inner(&client, &my_destination);

	err = main_log_ending(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_destruct(&client); mk_lang_check_rereturn(err);

	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_ctrlc_handler_log(mk_lang_types_void_t) mk_lang_noexcept
{
	#define mk_iip_cp_app_ctrlc_handler_log_str "CTRL+C detected.\n"

	mk_lang_types_sint_t err;

	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&mk_iip_cp_app_ctrlc_handler_log_str[0])), mk_lang_countstr(mk_iip_cp_app_ctrlc_handler_log_str)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_base_stdcall mk_iip_cp_app_ctrlc_handler(mk_win_base_dword_t const type) mk_lang_noexcept
{
	mk_lang_types_bool_t handled;
	mk_lang_types_sint_t err;

	switch(type)
	{
		case mk_win_kernel_console_ctrl_event_id_e_c: handled = mk_lang_true; break;
		case mk_win_kernel_console_ctrl_event_id_e_break: handled = mk_lang_true; break;
		case mk_win_kernel_console_ctrl_event_id_e_close: handled = mk_lang_true; break;
		default: handled = mk_lang_false; break;
	}
	if(handled)
	{
		err = mk_iip_cp_app_ctrlc_handler_log(); mk_lang_check_recrash(err);
		mk_iip_cp_app_g_ctrl_c = mk_lang_true;
	}
	return handled ? mk_win_base_true : mk_win_base_false;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_app_install_ctrlc_handler(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_iip_cp_app_g_ctrl_c = mk_lang_false;
	b = mk_win_kernel_console_set_ctrl_handler(&mk_iip_cp_app_ctrlc_handler, mk_win_base_true); mk_lang_check_return(b != 0);
	return 0;
}


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	time_t tm;
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t len;

	tm = time(mk_lang_null); mk_lang_check_return(tm != ((time_t)(-1)));
	srand(((mk_lang_types_uint_t)(tm)));
	mk_lang_cpuid_init();
	err = mk_iip_cp_mallocator_global_init(); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_init(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_app_install_ctrlc_handler(); mk_lang_check_rereturn(err);

	if(argc == 3)
	{
		len = mk_lang_strlen_n_fn(argv[1]);
		if     (len == mk_lang_countstr(mk_iip_cp_app_arg_generate_destination) && mk_lang_string_memcmp_pc_fn(&argv[1][0], &mk_iip_cp_app_arg_generate_destination[0], mk_lang_countstr(mk_iip_cp_app_arg_generate_destination)) == 0){ err = mk_iip_cp_app_generate_destination(argc, argv); mk_lang_check_rereturn(err); }
		else if(len == mk_lang_countstr(mk_iip_cp_app_arg_use_destination     ) && mk_lang_string_memcmp_pc_fn(&argv[1][0], &mk_iip_cp_app_arg_use_destination     [0], mk_lang_countstr(mk_iip_cp_app_arg_use_destination     )) == 0){ err = mk_iip_cp_app_use_destination     (argc, argv); mk_lang_check_rereturn(err); }
	}

	err = mk_sl_net_windows_deinit(); mk_lang_check_rereturn(err);
	err = mk_iip_cp_mallocator_global_deinit(); mk_lang_check_rereturn(err);
	err = main_log_gud(); mk_lang_check_rereturn(err);
	return 0;
}
