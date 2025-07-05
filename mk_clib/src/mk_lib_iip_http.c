#ifndef mk_include_guard_mk_lib_iip_http_c
#define mk_include_guard_mk_lib_iip_http_c
#include "mk_lib_iip_http.h"

/* RFC 9110 */
/* https://datatracker.ietf.org/doc/html/rfc9110 */
/* https://www.rfc-editor.org/rfc/rfc9110.txt */

#include "mk_lang_string.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_clobber.h"
#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_http_buffer.h"
#include "mk_lib_iip_http_strings.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_construct(mk_lib_iip_http_header_pt const header) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_construct(&header->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_construct(&header->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_destroy(mk_lib_iip_http_header_pt const header) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_destroy(&header->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_destroy(&header->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_copy_construct(mk_lib_iip_http_header_pt const header, mk_lib_iip_http_header_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_copy_construct(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_copy_construct(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_move_construct(mk_lib_iip_http_header_pt const header, mk_lib_iip_http_header_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_move_construct(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_move_construct(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_copy_assign(mk_lib_iip_http_header_pt const header, mk_lib_iip_http_header_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_copy_assign(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_copy_assign(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_header_rw_move_assign(mk_lib_iip_http_header_pt const header, mk_lib_iip_http_header_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(header);

	err = mk_lib_iip_http_buffer_rw_move_assign(&header->m_key, &src->m_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_move_assign(&header->m_val, &src->m_val); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_http_headers
#define mk_sl_vector_t_element_type mk_lib_iip_http_header_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_http_header_rw_construct
#define mk_sl_vector_t_element_destruct mk_lib_iip_http_header_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_http_header_rw_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_iip_http_header_rw_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_http_header_rw_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_iip_http_header_rw_move_assign
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_http_strings_id_t mk_lib_iip_http_prrw_method_id_to_string_id(mk_lib_iip_http_method_id_t const method_id) mk_lang_noexcept
{
	mk_lib_iip_http_strings_id_t string_id;

	mk_lang_assert(method_id >= 0);
	mk_lang_assert(method_id < mk_lib_iip_http_method_id_e_dummy_end);

	switch(method_id)
	{
		case mk_lib_iip_http_method_id_e_get: string_id = mk_lib_iip_http_strings_id_e_get; break;
		case mk_lib_iip_http_method_id_e_head: string_id = mk_lib_iip_http_strings_id_e_head; break;
		case mk_lib_iip_http_method_id_e_post: string_id = mk_lib_iip_http_strings_id_e_post; break;
		case mk_lib_iip_http_method_id_e_put: string_id = mk_lib_iip_http_strings_id_e_put; break;
		case mk_lib_iip_http_method_id_e_delete: string_id = mk_lib_iip_http_strings_id_e_delete; break;
		case mk_lib_iip_http_method_id_e_connect: string_id = mk_lib_iip_http_strings_id_e_connect; break;
		case mk_lib_iip_http_method_id_e_options: string_id = mk_lib_iip_http_strings_id_e_options; break;
		case mk_lib_iip_http_method_id_e_trace: string_id = mk_lib_iip_http_strings_id_e_trace; break;
		case mk_lib_iip_http_method_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&string_id);
	return string_id;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_method_string_max_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t method_str_max;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_iip_http_method_id_t method_id;
	mk_lib_iip_http_strings_id_t method_str_id;
	mk_lang_types_sint_t method_str_len;

	method_str_max = 0;
	n = mk_lib_iip_http_method_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		method_id = ((mk_lib_iip_http_method_id_t)(i));
		method_str_id = mk_lib_iip_http_prrw_method_id_to_string_id(method_id); mk_lang_assert(method_str_id >= 0); mk_lang_assert(method_str_id < mk_lib_iip_http_strings_id_e_dummy_end);
		method_str_len = mk_lib_iip_http_strings_get_str_len(method_str_id); mk_lang_assert(method_str_len >= 1);
		method_str_max = mk_lang_max(method_str_max, method_str_len);
	}
	return method_str_max;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_fancy_buf(mk_lib_iip_http_buffer_pt const buf) mk_lang_noexcept
{
#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_t zero;
	mk_lang_types_bool_t err;

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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_is_space(mk_lib_iip_http_pt const http, mk_lang_types_sint_t const pos) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_bool_t is;

	mk_lang_assert(http);

	mk_sl_cui_uint8_to_bi_pchar(mk_lib_iip_http_buffer_rw_at(&http->m_buffer, ((mk_lang_types_usize_t)(pos))), &tpc);
	is = tpc == ' ';
	return is;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_is_string(mk_lib_iip_http_pt const http, mk_lib_iip_http_strings_id_t const str_id) mk_lang_noexcept
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_find_space(mk_lib_iip_http_pt const http) mk_lang_noexcept
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_find_colon_space(mk_lib_iip_http_pt const http) mk_lang_noexcept
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_find_crlf(mk_lib_iip_http_pt const http) mk_lang_noexcept
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
		is = tpc == '\x0d';
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
			is = tpc == '\x0a';
		}
		else
		{
			is = mk_lang_false;
		}
		pos = is ? i : -1;
	}
	return pos;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_on_incoming_data_method_work(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t method_str_max;
	mk_lang_types_sint_t dat_sise;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct dat_buf;
	mk_lang_types_pchar_t dat_str[7];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_iip_http_method_id_t method_id;
	mk_lib_iip_http_strings_id_t method_str_id;
	mk_lang_types_pchar_pct method_str_buf;
	mk_lang_types_sint_t method_str_len;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_parse_error_code_e_ok);

	method_str_max = mk_lib_iip_http_prrw_method_string_max_len();
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	rem = method_str_max - dat_sise + 1;
	rem = mk_lang_max(rem, 0);
	rem = mk_lang_min(rem, data_len);
	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
	*consumed = rem;
	dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	mk_sl_cui_uint8_to_bi_pchar_many(dat_buf, &dat_str[0], ((mk_lang_types_usize_t)(mk_lang_min(dat_sise, mk_lang_countof(dat_str)))));
	n = mk_lib_iip_http_method_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		method_id = ((mk_lib_iip_http_method_id_t)(i));
		method_str_id = mk_lib_iip_http_prrw_method_id_to_string_id(method_id); mk_lang_assert(method_str_id >= 0); mk_lang_assert(method_str_id < mk_lib_iip_http_strings_id_e_dummy_end);
		method_str_buf = mk_lib_iip_http_strings_get_str_buf(method_str_id); mk_lang_assert(method_str_buf); mk_lang_assert(method_str_buf[0] != '\0');
		method_str_len = mk_lib_iip_http_strings_get_str_len(method_str_id); mk_lang_assert(method_str_len >= 1);
		mk_lang_assert(method_str_len <= mk_lang_countof(dat_str));
		if(dat_sise >= method_str_len && mk_lang_string_memcmp_pc_fn(&dat_str[0], method_str_buf, ((mk_lang_types_usize_t)(method_str_len))) == 0)
		{
			break;
		}
	}
	if(i == n)
	{
		if(method_str_len >= method_str_max)
		{
			*error_code = mk_lib_iip_http_parse_error_code_e_bad_method;
		}
	}
	else
	{
		if(mk_lib_iip_http_prrw_is_space(http, method_str_len))
		{
			err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(method_str_len + 1))); mk_lang_check_rereturn(err);
			http->m_method = method_id;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_on_incoming_data_uri_work(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos;
	mk_sl_cui_uint8_pt dat_buf;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_parse_error_code_e_ok);

	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(data_len))); mk_lang_check_rereturn(err);
	*consumed = data_len;
	pos = mk_lib_iip_http_prrw_find_space(http);
	if(pos != -1)
	{
		dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
		err = mk_lib_iip_http_buffer_rw_push_back_move_many(&http->m_uri, dat_buf, ((mk_lang_types_usize_t)(pos))); mk_lang_check_rereturn(err);
		err = mk_lib_iip_http_prrw_fancy_buf(&http->m_uri); mk_lang_check_rereturn(err);
		err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos + 1))); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_on_incoming_data_version_work(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
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
	mk_lang_assert(*error_code == mk_lib_iip_http_parse_error_code_e_ok);

	max_len = mk_lib_iip_http_strings_get_str_len(mk_lib_iip_http_strings_id_e_version_1_1);
	dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
	rem = max_len - dat_sise;
	rem = mk_lang_max(rem, 0);
	rem = mk_lang_min(rem, data_len);
	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(rem))); mk_lang_check_rereturn(err);
	*consumed = rem;
	is = mk_lib_iip_http_prrw_is_string(http, mk_lib_iip_http_strings_id_e_version_1_1);
	if(is)
	{
		err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(max_len))); mk_lang_check_rereturn(err);
		http->m_version = mk_lib_iip_http_version_id_e_1_1;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_on_incoming_data_headers_work(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t pos_crlf;
	mk_lang_types_sint_t pos_sep;
	mk_sl_cui_uint8_pt dat_buf;
	mk_lang_types_sint_t dat_sise;
	mk_lib_iip_http_header_t header;

	mk_lang_assert(http);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(consumed);
	mk_lang_assert(*error_code == mk_lib_iip_http_parse_error_code_e_ok);

	err = mk_lib_iip_http_buffer_rw_push_back_copy_many(&http->m_buffer, data_buf, ((mk_lang_types_usize_t)(data_len))); mk_lang_check_rereturn(err);
	*consumed = data_len;
	for(;;)
	{
		pos_crlf = mk_lib_iip_http_prrw_find_crlf(http);
		if(pos_crlf == 0)
		{
			err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, 2); mk_lang_check_rereturn(err);
			http->m_hdrs_done = mk_lang_true;
			break;
		}
		else if(pos_crlf != -1)
		{
			pos_sep = mk_lib_iip_http_prrw_find_colon_space(http);
			if(!(pos_sep != -1 && pos_sep < pos_crlf))
			{
				*error_code = mk_lib_iip_http_parse_error_code_e_bad_header;
				return 0;
			}
			dat_buf = mk_lib_iip_http_buffer_rw_data(&http->m_buffer);
			dat_sise = mk_lib_iip_http_buffer_rw_sise(&http->m_buffer);
			err = mk_lib_iip_http_header_rw_construct(&header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_push_back_move_many(&header.m_key, dat_buf + 0, ((mk_lang_types_usize_t)(pos_sep))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_push_back_move_many(&header.m_val, dat_buf + pos_sep + 2, ((mk_lang_types_usize_t)(pos_crlf - pos_sep - 2))); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_prrw_fancy_buf(&header.m_key); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_prrw_fancy_buf(&header.m_val); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_headers_rw_push_back_move_single(&http->m_headers, &header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_header_rw_destroy(&header); mk_lang_check_rereturn(err);
			err = mk_lib_iip_http_buffer_rw_pop_front_many(&http->m_buffer, ((mk_lang_types_usize_t)(pos_crlf + 2))); mk_lang_check_rereturn(err);
		}
		else
		{
			*error_code = mk_lib_iip_http_parse_error_code_e_bad_header;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_on_incoming_data_method_has(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = http->m_method != mk_lib_iip_http_method_id_e_dummy_end;
	return has;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_on_incoming_data_uri_has(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = !mk_lib_iip_http_buffer_rw_is_empty(&http->m_uri);
	return has;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_on_incoming_data_version_has(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = http->m_version != mk_lib_iip_http_version_id_e_dummy_end;
	return has;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_http_prrw_on_incoming_data_headers_has(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(http);

	has = http->m_hdrs_done;
	return has;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_http_prrw_on_incoming_data(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
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
	mk_lang_assert(*error_code == mk_lib_iip_http_parse_error_code_e_ok);

	ptr = data_buf;
	rem = data_len;
	if(!mk_lib_iip_http_prrw_on_incoming_data_method_has (http)){ err = mk_lib_iip_http_prrw_on_incoming_data_method_work (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(!mk_lib_iip_http_prrw_on_incoming_data_uri_has    (http)){ err = mk_lib_iip_http_prrw_on_incoming_data_uri_work    (http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(!mk_lib_iip_http_prrw_on_incoming_data_version_has(http)){ err = mk_lib_iip_http_prrw_on_incoming_data_version_work(http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	if(!mk_lib_iip_http_prrw_on_incoming_data_headers_has(http)){ err = mk_lib_iip_http_prrw_on_incoming_data_headers_work(http, ptr, rem, error_code, &tlen); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_http_parse_error_code_e_ok){ return 0;} mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; }
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_rw_construct(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	http->m_method = mk_lib_iip_http_method_id_e_dummy_end;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_uri); mk_lang_check_rereturn(err);
	http->m_version = mk_lib_iip_http_version_id_e_dummy_end;
	err = mk_lib_iip_http_headers_rw_construct(&http->m_headers); mk_lang_check_rereturn(err);
	http->m_hdrs_done = mk_lang_false;
	err = mk_lib_iip_http_buffer_rw_construct(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_rw_destroy(mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(http);

	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_uri); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_headers_rw_destroy(&http->m_headers); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_destroy(&http->m_buffer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_rw_on_incoming_data(mk_lib_iip_http_pt const http, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_http_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_http_prrw_on_incoming_data(http, data_buf, data_len, error_code, consumed);
}


#endif
