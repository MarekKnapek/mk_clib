#ifndef mk_include_guard_mk_lib_iip_http_client_response_c
#define mk_include_guard_mk_lib_iip_http_client_response_c
#include "mk_lib_iip_http_client_response.h"

/* RFC 9110 */
/* https://datatracker.ietf.org/doc/html/rfc9110 */
/* https://www.rfc-editor.org/rfc/rfc9110.txt */
/* RFC 9112 */
/* https://datatracker.ietf.org/doc/html/rfc9112 */
/* https://www.rfc-editor.org/rfc/rfc9112.txt */

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_http_buffer.h"
#include "mk_lib_iip_http_strings.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_construct(mk_lib_iip_http_client_response_header_pt const header) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_construct(&header->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_construct(&header->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_destroy(mk_lib_iip_http_client_response_header_pt const header) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_destroy(&header->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_destroy(&header->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_copy_construct(mk_lib_iip_http_client_response_header_pt const header, mk_lib_iip_http_client_response_header_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_copy_construct(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_copy_construct(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_move_construct(mk_lib_iip_http_client_response_header_pt const header, mk_lib_iip_http_client_response_header_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_move_construct(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_move_construct(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_copy_assign(mk_lib_iip_http_client_response_header_pt const header, mk_lib_iip_http_client_response_header_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_copy_assign(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_copy_assign(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_header_rw_move_assign(mk_lib_iip_http_client_response_header_pt const header, mk_lib_iip_http_client_response_header_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_move_assign(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_move_assign(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_http_client_response_headers
#define mk_sl_vector_t_element_type mk_lib_iip_http_client_response_header_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_http_client_response_header_rw_construct
#define mk_sl_vector_t_element_destruct mk_lib_iip_http_client_response_header_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_http_client_response_header_rw_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_iip_http_client_response_header_rw_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_http_client_response_header_rw_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_iip_http_client_response_header_rw_move_assign
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_construct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	http->m_protocol = mk_lib_iip_http_client_response_protocol_e_dummy_end;
	http->m_status_code = 0;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_reason_phrase); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_headers_rw_construct(&http->m_headers); mk_lang_check_rereturn(err);
	http->m_is_chunked = 0;
	http->m_content_rem = -1;
	http->m_headers_done = mk_lang_false;
	http->m_resource_done = mk_lang_false;
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&http->m_resource); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_destroy(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_reason_phrase); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_headers_rw_destroy(&http->m_headers); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&http->m_resource); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_reconstruct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_client_response_prrw_destroy(http); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_prrw_construct(http); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_protocol_str_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t str_len;

	str_len = mk_lib_iip_http_strings_get_str_len(mk_lib_iip_http_strings_id_e_version_1_1_b); mk_lang_assert(str_len >= 1);
	return str_len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_parse_is_space(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_off) mk_lang_noexcept
{
	mk_lang_types_pchar_t space_pc;
	mk_sl_cui_uint8_t space_u8;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(data_buf);
	mk_lang_assert(data_off);

	space_pc = ' ';
	mk_sl_cui_uint8_from_bi_pchar(&space_u8, &space_pc);
	is = mk_sl_cui_uint8_eq(&data_buf[data_off], &space_u8);
	return is;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_find_crlf(mk_lib_iip_http_client_response_pt const http, mk_lang_types_sint_pt const pos) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u_cr;
	mk_sl_cui_uint8_t u_lf;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_sint_t sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(pos);

	tpc = '\x0d'; mk_sl_cui_uint8_from_bi_pchar(&u_cr, &tpc);
	tpc = '\x0a'; mk_sl_cui_uint8_from_bi_pchar(&u_lf, &tpc);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
	sise = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise_a(&http->m_buffer);
	n = sise;
	for(i = 0; i != n; ++i)
	{
		is =
			(mk_sl_cui_uint8_eq(&u_cr, &data[i])) &&
			((i + 1) < sise) &&
			(mk_sl_cui_uint8_eq(&u_lf, &data[i + 1])) &&
			(mk_lang_true);
		if(is)
		{
			break;
		}
	}
	if(i == n)
	{
		*pos = -1;
	}
	else
	{
		*pos = i;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_find_colon_space(mk_lib_iip_http_client_response_pt const http, mk_lang_types_sint_t const limit, mk_lang_types_sint_pt const pos) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u_colon;
	mk_sl_cui_uint8_t u_space;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(limit >= 0);
	mk_lang_assert(pos);

	tpc = ':'; mk_sl_cui_uint8_from_bi_pchar(&u_colon, &tpc);
	tpc = ' '; mk_sl_cui_uint8_from_bi_pchar(&u_space, &tpc);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
	n = limit;
	for(i = 0; i != n; ++i)
	{
		is =
			(mk_sl_cui_uint8_eq(&u_colon, &data[i])) &&
			((i + 1) < limit) &&
			(mk_sl_cui_uint8_eq(&u_space, &data[i + 1])) &&
			(mk_lang_true);
		if(is)
		{
			break;
		}
	}
	if(i == n)
	{
		*pos = -1;
	}
	else
	{
		*pos = i;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_is_chunked(mk_lib_iip_http_client_response_pt const http, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	mk_lib_iip_http_strings_id_t transfer_encoding_id;
	mk_lang_types_pchar_pct transfer_encoding_buf;
	mk_lang_types_sint_t transfer_encoding_len;
	mk_lib_iip_http_strings_id_t chunked_id;
	mk_lang_types_pchar_pct chunked_buf;
	mk_lang_types_sint_t chunked_len;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_http_client_response_header_pt header;

	mk_lang_assert(http);
	mk_lang_assert(is);

	if
	(
		(http->m_protocol != mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(http->m_status_code != 0) &&
		(!mk_lib_iip_http_buffer_rw_is_empty(&http->m_reason_phrase)) &&
		(http->m_headers_done) &&
		(http->m_is_chunked == 0) &&
		(mk_lang_true)
	)
	{
		transfer_encoding_id = mk_lib_iip_http_strings_id_e_transfer_encoding;
		transfer_encoding_buf = mk_lib_iip_http_strings_get_str_buf(transfer_encoding_id); mk_lang_assert(transfer_encoding_buf); mk_lang_assert(transfer_encoding_buf[0] != '\0');
		transfer_encoding_len = mk_lib_iip_http_strings_get_str_len(transfer_encoding_id); mk_lang_assert(transfer_encoding_len >= 1);
		chunked_id = mk_lib_iip_http_strings_id_e_chunked;
		chunked_buf = mk_lib_iip_http_strings_get_str_buf(chunked_id); mk_lang_assert(chunked_buf); mk_lang_assert(chunked_buf[0] != '\0');
		chunked_len = mk_lib_iip_http_strings_get_str_len(chunked_id); mk_lang_assert(chunked_len >= 1);
		n = mk_lib_iip_http_client_response_headers_rw_size(&http->m_headers);
		for(i = 0; i != n; ++i)
		{
			header = mk_lib_iip_http_client_response_headers_rw_at(&http->m_headers, i); mk_lang_assert(header);
			if
			(
				(mk_lib_iip_http_buffer_rw_sise(&header->m_key) == transfer_encoding_len) &&
				(mk_sl_cui_uint8_eq_pchar_many(mk_lib_iip_http_buffer_rw_data(&header->m_key), transfer_encoding_buf, transfer_encoding_len)) &&
				(mk_lang_true)
			)
			{
				if
				(
					(mk_lib_iip_http_buffer_rw_sise(&header->m_val) == chunked_len) &&
					(mk_sl_cui_uint8_eq_pchar_many(mk_lib_iip_http_buffer_rw_data(&header->m_val), chunked_buf, chunked_len)) &&
					(mk_lang_true)
				)
				{
					http->m_is_chunked = 1;
				}
				else
				{
					http->m_is_chunked = 2;
				}
				break;
			}
		}
		if(i == n)
		{
			http->m_is_chunked = 2;
		}
	}
	*is = http->m_is_chunked == 1;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_parse_protocol(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t protocol_max_len;
	mk_lang_types_sint_t curr_len;
	mk_lang_types_sint_t to_read_want;
	mk_lang_types_sint_t to_read_can;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t u8buf[8];
	mk_sl_cui_uint8_pt data;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if
	(
		(http->m_protocol == mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(mk_lang_true)
	)
	{
		protocol_max_len = mk_lib_iip_http_client_response_prrw_protocol_str_len(); mk_lang_assert(protocol_max_len >= 1);
		curr_len = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise(&http->m_buffer);
		if(curr_len < protocol_max_len + 1)
		{
			to_read_want = protocol_max_len + 1 - curr_len;
			to_read_can = mk_lang_min(to_read_want, rem);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_buffer, ptr, ((mk_lang_types_usize_t)(to_read_can))); mk_lang_check_rereturn(err);
			curr_len += to_read_can;
			ptr += to_read_can;
			rem -= to_read_can;
		}
		if(curr_len >= protocol_max_len + 1)
		{
			str_buf = mk_lib_iip_http_strings_get_str_buf(mk_lib_iip_http_strings_id_e_version_1_1_b);
			str_len = mk_lib_iip_http_strings_get_str_len(mk_lib_iip_http_strings_id_e_version_1_1_b);
			mk_lang_assert(str_len <= protocol_max_len);
			mk_lang_assert(mk_lang_countof(u8buf) == protocol_max_len);
			mk_sl_cui_uint8_from_bi_pchar_many(&u8buf[0], str_buf, ((mk_lang_types_usize_t)(str_len)));
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
			data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
			if(mk_sl_cui_uint8_memcmp_fn(data, &u8buf[0], ((mk_lang_types_usize_t)(str_len))) == 0)
			{
				if(mk_lib_iip_http_client_response_prrw_parse_is_space(http, data, str_len))
				{
					err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(str_len + 1))); mk_lang_check_rereturn(err);
					http->m_protocol = mk_lib_iip_http_client_response_protocol_e_1_1;
				}
				else
				{
					*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_format;
				}
			}
			else
			{
				*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_protocol;
			}
		}
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_parse_status_code(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t max_len;
	mk_lang_types_sint_t curr_len;
	mk_lang_types_sint_t to_read_want;
	mk_lang_types_sint_t to_read_can;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt data;
	mk_lang_types_pchar_t pchar_buf[3];
	mk_lang_types_sint_t len;
	mk_lang_types_uint_t status_code;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if
	(
		(http->m_protocol != mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(http->m_status_code == 0) &&
		(mk_lang_true)
	)
	{
		max_len = 3;
		curr_len = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise(&http->m_buffer);
		if(curr_len < max_len + 1)
		{
			to_read_want = max_len + 1 - curr_len;
			to_read_can = mk_lang_min(to_read_want, rem);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_buffer, ptr, ((mk_lang_types_usize_t)(to_read_can))); mk_lang_check_rereturn(err);
			curr_len += to_read_can;
			ptr += to_read_can;
			rem -= to_read_can;
		}
		if(curr_len >= max_len + 1)
		{
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
			data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
			mk_sl_cui_uint8_to_bi_pchar_many(data, &pchar_buf[0], 3);
			len = mk_lang_bui_uint_from_str_dec_n(&status_code, &pchar_buf[0], mk_lang_countof(pchar_buf));
			if(len == 3 && status_code >= 100 && status_code <= 999)
			{
				if(mk_lib_iip_http_client_response_prrw_parse_is_space(http, data, len))
				{
					err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(len + 1))); mk_lang_check_rereturn(err);
					http->m_status_code = ((mk_lang_types_sint_t)(status_code));
				}
				else
				{
					*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_format;
				}
			}
			else
			{
				*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_status_code;
			}
		}
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_parse_reason_phrase(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if
	(
		(http->m_protocol != mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(http->m_status_code != 0) &&
		(mk_lib_iip_http_buffer_rw_is_empty(&http->m_reason_phrase)) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos); mk_lang_check_rereturn(err);
		if(pos == -1)
		{
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_buffer, ptr, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
			ptr += rem;
			rem -= rem;
			err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos); mk_lang_check_rereturn(err);
		}
		if(pos != -1)
		{
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
			data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
			err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_reason_phrase, data, ((mk_lang_types_usize_t)(pos))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_fancy_string(&http->m_reason_phrase); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos + 2))); mk_lang_check_rereturn(err);
		}
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_parse_headers(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos_a;
	mk_lang_types_sint_t pos_b;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_sint_t tlen;
	mk_lib_iip_http_client_response_header_pt header;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if
	(
		(http->m_protocol != mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(http->m_status_code != 0) &&
		(!mk_lib_iip_http_buffer_rw_is_empty(&http->m_reason_phrase)) &&
		(!http->m_headers_done) &&
		(mk_lang_true)
	)
	{
		for(;;)
		{
			err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos_a); mk_lang_check_rereturn(err);
			if(pos_a == -1)
			{
				err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_buffer, ptr, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
				ptr += rem;
				rem -= rem;
				err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos_a); mk_lang_check_rereturn(err);
			}
			if(pos_a == 0)
			{
				err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, 2); mk_lang_check_rereturn(err);
				http->m_headers_done = mk_lang_true;
				break;
			}
			else if(pos_a != -1)
			{
				err = mk_lib_iip_http_client_response_prrw_find_colon_space(http, pos_a, &pos_b); mk_lang_check_rereturn(err);
				if(pos_b != -1)
				{
					mk_lang_assert(pos_b + 2 <= pos_a);
					err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
					data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
					err = mk_lib_iip_http_client_response_headers_rw_grow_by(&http->m_headers, 1); mk_lang_check_rereturn(err);
					header = mk_lib_iip_http_client_response_headers_rw_back(&http->m_headers); mk_lang_assert(header);
					err = mk_lib_iip_http_buffer_rw_construct(&header->m_key); mk_lang_check_rereturn(err);
					err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&header->m_key, data + 0, ((mk_lang_types_usize_t)(pos_b))); mk_lang_check_rereturn(err);
					err = mk_lib_iip_http_buffer_rw_fancy_string(&header->m_key); mk_lang_check_rereturn(err);
					err = mk_lib_iip_http_buffer_rw_construct(&header->m_val); mk_lang_check_rereturn(err);
					err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&header->m_val, data + pos_b + 2, ((mk_lang_types_usize_t)(pos_a - pos_b - 2))); mk_lang_check_rereturn(err);
					err = mk_lib_iip_http_buffer_rw_fancy_string(&header->m_val); mk_lang_check_rereturn(err);
					err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos_a + 2))); mk_lang_check_rereturn(err);
				}
				else
				{
					*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_header;
				}
			}
		}
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_parse_resource(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_chunked;
	mk_lang_types_sint_t pos_crlf;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_pchar_t hex_buf[mk_sl_cui_uint32_strlen_hex_v];
	mk_lang_types_sint_t len;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t sise;
	mk_lang_types_sint_t to_copy;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if
	(
		(http->m_protocol != mk_lib_iip_http_client_response_protocol_e_dummy_end) &&
		(http->m_status_code != 0) &&
		(!mk_lib_iip_http_buffer_rw_is_empty(&http->m_reason_phrase)) &&
		(http->m_headers_done) &&
		(!http->m_resource_done) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_http_client_response_prrw_is_chunked(http, &is_chunked); mk_lang_check_rereturn(err);
		if(is_chunked && http->m_content_rem == -1)
		{
			err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos_crlf); mk_lang_check_rereturn(err);
			if(pos_crlf == -1)
			{
				err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_buffer, ptr, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
				ptr += rem;
				rem -= rem;
				err = mk_lib_iip_http_client_response_prrw_find_crlf(http, &pos_crlf); mk_lang_check_rereturn(err);
			}
			if(pos_crlf != -1)
			{
				if(pos_crlf <= mk_lang_countof(hex_buf))
				{
					err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
					data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
					mk_sl_cui_uint8_to_bi_pchar_many(data, &hex_buf[0], pos_crlf);
					len = mk_sl_cui_uint32_from_str_hex_n(&tu32, &hex_buf[0], pos_crlf);
					if(len >= 1)
					{
						mk_lang_assert(len <= pos_crlf);
						mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
						if(tul <= ((mk_lang_types_ulong_t)(mk_lang_limits_sint_max)))
						{
							tlen = ((mk_lang_types_sint_t)(tul));
							http->m_content_rem = tlen;
							err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos_crlf + 2))); mk_lang_check_rereturn(err);
						}
						else
						{
							*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_chunk;
						}
					}
					else
					{
						*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_chunk;
					}
				}
				else
				{
					*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_chunk;
				}
			}
		}
		else
		{
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
			data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
			sise = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise_a(&http->m_buffer);
			to_copy = mk_lang_min(http->m_content_rem, sise);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_resource, data, ((mk_lang_types_usize_t)(to_copy))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(to_copy))); mk_lang_check_rereturn(err);
			http->m_content_rem -= to_copy;
			to_copy = mk_lang_min(http->m_content_rem, rem);
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_copy_many(&http->m_resource, ptr, ((mk_lang_types_usize_t)(to_copy))); mk_lang_check_rereturn(err);
			http->m_content_rem -= to_copy;
			ptr += to_copy;
			rem -= to_copy;
		}
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_on_incoming_data(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_http_client_response_prrw_parse_protocol     (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_lib_iip_http_client_response_prrw_parse_status_code  (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_lib_iip_http_client_response_prrw_parse_reason_phrase(http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_lib_iip_http_client_response_prrw_parse_headers      (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_lib_iip_http_client_response_prrw_parse_resource     (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_construct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	return mk_lib_iip_http_client_response_prrw_construct(http);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_destroy(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	return mk_lib_iip_http_client_response_prrw_destroy(http);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_reconstruct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	return mk_lib_iip_http_client_response_prrw_reconstruct(http);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_on_incoming_data(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_http_client_response_prrw_on_incoming_data(http, data_buf, data_len, error_code, consumed);
}


#endif
