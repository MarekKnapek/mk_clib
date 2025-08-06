#ifndef mk_include_guard_mk_lib_iip_http_client_response_c
#define mk_include_guard_mk_lib_iip_http_client_response_c
#include "mk_lib_iip_http_client_response.h"

/* RFC 9110 */
/* https://datatracker.ietf.org/doc/html/rfc9110 */
/* https://www.rfc-editor.org/rfc/rfc9110.txt */

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


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_http_strings_id_t mk_lib_iip_http_client_response_prrw_method_id_to_string_id(mk_lib_iip_http_client_response_method_id_t const method_id) mk_lang_noexcept
{
	mk_lib_iip_http_strings_id_t string_id;

	mk_lang_assert(method_id >= 0);
	mk_lang_assert(method_id < mk_lib_iip_http_client_response_method_id_e_dummy_end);

	switch(method_id)
	{
		case mk_lib_iip_http_client_response_method_id_e_get: string_id = mk_lib_iip_http_strings_id_e_get; break;
		case mk_lib_iip_http_client_response_method_id_e_head: string_id = mk_lib_iip_http_strings_id_e_head; break;
		case mk_lib_iip_http_client_response_method_id_e_post: string_id = mk_lib_iip_http_strings_id_e_post; break;
		case mk_lib_iip_http_client_response_method_id_e_put: string_id = mk_lib_iip_http_strings_id_e_put; break;
		case mk_lib_iip_http_client_response_method_id_e_delete: string_id = mk_lib_iip_http_strings_id_e_delete; break;
		case mk_lib_iip_http_client_response_method_id_e_connect: string_id = mk_lib_iip_http_strings_id_e_connect; break;
		case mk_lib_iip_http_client_response_method_id_e_options: string_id = mk_lib_iip_http_strings_id_e_options; break;
		case mk_lib_iip_http_client_response_method_id_e_trace: string_id = mk_lib_iip_http_strings_id_e_trace; break;
		case mk_lib_iip_http_client_response_method_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&string_id);
	return string_id;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_fancy_buf(mk_lib_iip_http_buffer_pt const buf) mk_lang_noexcept
{
#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_t zero;
	mk_lang_types_sint_t err;

	mk_lang_assert(buf);

	mk_sl_cui_uint8_set_zero(&zero);
	err = mk_lib_iip_http_buffer_rw_push_back_move_single(buf, &zero); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_pop_back_single(buf); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(buf);

	((mk_lang_types_void_t)(buf));
	return 0;
#endif
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_is_space(mk_lib_iip_http_client_response_pt const http, mk_lang_types_sint_t const pos) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);

	mk_sl_cui_uint8_to_bi_pchar(mk_lib_iip_http_buffer_rw_at(&http->m_buffer, ((mk_lang_types_usize_t)(pos))), &tpc);
	is = tpc == ' ';
	return is;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_is_string(mk_lib_iip_http_client_response_pt const http, mk_lib_iip_http_strings_id_t const str_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct dat_buf;
	mk_lang_types_sint_t dat_sise;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(str_id >= 0);
	mk_lang_assert(str_id < mk_lib_iip_http_strings_id_e_dummy_end);

	dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	str_buf = mk_lib_iip_http_strings_get_str_buf(str_id);
	str_len = mk_lib_iip_http_strings_get_str_len(str_id);
	if(dat_sise >= str_len)
	{
		n = str_len;
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_uint8_from_bi_pchar(&tu8, &str_buf[i]);
			if(!mk_sl_cui_uint8_eq(&dat_buf[i], &tu8))
			{
				break;
			}
		}
		if(i == n)
		{
			is = mk_lang_true;
		}
		else
		{
			is = mk_lang_false;
		}
	}
	else
	{
		is = mk_lang_false;
	}
	return is;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_find_space(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct dat_buf;
	mk_lang_types_sint_t dat_sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_pchar_t tpc;
	mk_lang_types_bool_t is;
	mk_lang_types_sint_t pos;

	mk_lang_assert(http);

	dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	n = dat_sise;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_pchar(&dat_buf[i], &tpc);
		is = tpc == ' ';
		if(is)
		{
			break;
		}
	}
	if(i == n)
	{
		pos = -1;
	}
	else
	{
		pos = i;
	}
	return pos;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_find_colon_space(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct dat_buf;
	mk_lang_types_sint_t dat_sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_pchar_t tpc;
	mk_lang_types_bool_t is;
	mk_lang_types_sint_t pos;

	mk_lang_assert(http);

	dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	n = dat_sise;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_pchar(&dat_buf[i], &tpc);
		is = tpc == ':';
		if(is)
		{
			break;
		}
	}
	if(i == n)
	{
		pos = -1;
	}
	else
	{
		if(dat_sise >= i + 1)
		{
			mk_sl_cui_uint8_to_bi_pchar(&dat_buf[i + 1], &tpc);
			is = tpc == ' ';
		}
		else
		{
			is = mk_lang_false;
		}
		pos = is ? i : -1;
	}
	return pos;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_on_incoming_data_uri_work(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos;
	mk_sl_cui_uint8_pt dat_buf;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(data_len))); mk_lang_check_rereturn(err);
	*consumed = data_len;
	pos = mk_lib_iip_http_client_response_prrw_find_space(http);
	if(pos != -1)
	{
		dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
		err = mk_lib_iip_http_buffer_rw_push_back_move_many(&http->m_uri, dat_buf, ((mk_lang_types_usize_t)(pos))); mk_lang_check_rereturn(err);
		err = mk_lib_iip_http_client_response_prrw_fancy_buf(&http->m_uri); mk_lang_check_rereturn(err);
		err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos + 1))); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_on_incoming_data_version_work(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t max_len;
	mk_lang_types_sint_t dat_sise;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	max_len = mk_lib_iip_http_strings_get_str_len(mk_lib_iip_http_strings_id_e_version_1_1);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	rem = max_len - dat_sise;
	rem = mk_lang_max(rem, 0);
	rem = mk_lang_min(rem, data_len);
	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
	*consumed = rem;
	is = mk_lib_iip_http_client_response_prrw_is_string(http, mk_lib_iip_http_strings_id_e_version_1_1);
	if(is)
	{
		err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(max_len))); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_on_incoming_data_headers_work(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos_crlf;
	mk_lang_types_sint_t pos_sep;
	mk_sl_cui_uint8_pt dat_buf;
	//mk_lang_types_sint_t dat_sise;
	mk_lib_iip_http_client_response_header_t header;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_client_response_parse_error_code_e_ok);

	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(data_len))); mk_lang_check_rereturn(err);
	*consumed = data_len;
	for(;;)
	{
		pos_crlf = mk_lib_iip_http_client_response_prrw_find_crlf(http);
		if(pos_crlf == 0)
		{
			err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, 2); mk_lang_check_rereturn(err);
			http->m_hdrs_done = mk_lang_true;
			break;
		}
		else if(pos_crlf != -1)
		{
			pos_sep = mk_lib_iip_http_client_response_prrw_find_colon_space(http);
			if(!(pos_sep != -1 && pos_sep < pos_crlf))
			{
				*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_header;
				return 0;
			}
			dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
			//dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
			err = mk_lib_iip_http_client_response_header_rw_construct(&header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_push_back_move_many(&header.m_key, dat_buf + 0, ((mk_lang_types_usize_t)(pos_sep))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_push_back_move_many(&header.m_val, dat_buf + pos_sep + 2, ((mk_lang_types_usize_t)(pos_crlf - pos_sep - 2))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_client_response_prrw_fancy_buf(&header.m_key); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_client_response_prrw_fancy_buf(&header.m_val); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_client_response_headers_rw_push_back_move_single(&http->m_headers, &header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_client_response_header_rw_destroy(&header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos_crlf + 2))); mk_lang_check_rereturn(err);
		}
		else
		{
			*error_code = mk_lib_iip_http_client_response_parse_error_code_e_bad_header;
			break;
		}
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_on_incoming_data_method_has(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = http->m_method != mk_lib_iip_http_client_response_method_id_e_dummy_end;
	return has;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_on_incoming_data_uri_has(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = !mk_lib_iip_http_buffer_rw_is_empty(&http->m_uri);
	return has;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_on_incoming_data_version_has(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	//has = http->m_version != mk_lib_iip_http_client_response_version_id_e_dummy_end;
	has = 0;
	return has;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_client_response_prrw_on_incoming_data_headers_has(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = http->m_hdrs_done;
	return has;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_on_incoming_data(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
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
	if(                                                           !mk_lib_iip_http_client_response_prrw_on_incoming_data_method_has (http)){ err = mk_lib_iip_http_client_response_prrw_on_incoming_data_method_work (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(mk_lib_iip_http_client_response_prrw_on_incoming_data_method_has (http) && !mk_lib_iip_http_client_response_prrw_on_incoming_data_uri_has    (http)){ err = mk_lib_iip_http_client_response_prrw_on_incoming_data_uri_work    (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(mk_lib_iip_http_client_response_prrw_on_incoming_data_uri_has    (http) && !mk_lib_iip_http_client_response_prrw_on_incoming_data_version_has(http)){ err = mk_lib_iip_http_client_response_prrw_on_incoming_data_version_work(http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(mk_lib_iip_http_client_response_prrw_on_incoming_data_version_has(http) && !mk_lib_iip_http_client_response_prrw_on_incoming_data_headers_has(http)){ err = mk_lib_iip_http_client_response_prrw_on_incoming_data_headers_work(http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_client_response_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}
*/

/*mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_construct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	http->m_protocol = mk_lib_iip_http_client_response_protocol_e_dummy_end;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_uri); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_headers_rw_construct(&http->m_headers); mk_lang_check_rereturn(err);
	http->m_hdrs_done = mk_lang_false;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_destroy(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_uri); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_headers_rw_destroy(&http->m_headers); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_reconstruct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_client_response_rw_destroy(http); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_client_response_rw_construct(http); mk_lang_check_rereturn(err);
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_client_response_rw_on_incoming_data(mk_lib_iip_http_client_response_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_client_response_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_http_client_response_prrw_on_incoming_data(http, data_buf, data_len, error_code, consumed);
}*/











mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_construct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	http->m_protocol = mk_lib_iip_http_client_response_protocol_e_dummy_end;
	http->m_status_code = 0;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_reason_phrase); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_destroy(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_reason_phrase); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_client_response_prrw_reconstruct(mk_lib_iip_http_client_response_pt const http) mk_lang_noexcept
{
	mk_lang_assert(http);

	/**/
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
	mk_lang_types_pchar_t pchar;
	mk_sl_cui_uint8_t u8;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_sint_t sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);
	mk_lang_assert(pos);

	pchar = '\x0d';
	mk_sl_cui_uint8_from_bi_pchar(&u8, &pchar);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&http->m_buffer); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&http->m_buffer);
	sise = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise_a(&http->m_buffer);
	n = sise;
	for(i = 0; i != n; ++i)
	{
		is = mk_sl_cui_uint8_eq(&u8, &data[i]);
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
		pchar = '\x0a';
		mk_sl_cui_uint8_from_bi_pchar(&u8, &pchar);
		is = (i + 1) < sise && mk_sl_cui_uint8_eq(&u8, &data[i + 1]);
		*pos = is ? i : -1;
	}
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
	if(http->m_protocol == mk_lib_iip_http_client_response_protocol_e_dummy_end)
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
			err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos + 2))); mk_lang_check_rereturn(err);
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
