#ifndef mk_include_guard_mk_lang_stdout_html_c
#define mk_include_guard_mk_lang_stdout_html_c
#include "mk_lang_stdout_html.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_string.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_io_appender_file.h"





struct mk_lang_stdout_html_lokal_s
{
	mk_sl_io_appender_file_t m_appender;
};
typedef struct mk_lang_stdout_html_lokal_s mk_lang_stdout_html_lokal_t;
mk_lang_typedef(mk_lang_stdout_html_lokal);


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_file_begin[] = "<body style=\"background-color:#0c0c0c\">\x0d\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_file_end[] = "</body >\x0d\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_line_begin[] = "<span style=\"white-space:pre; font-family:monospace; background-color:#0c0c0c; color:#cccccc\">";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_line_end[] = "</span><br>\x0d\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_color_begin_a[] = "<span style=\"color:#";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_color_begin_b[] = "\">";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_stdout_html_lokal_k_color_end[] = "</span>";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_color_id_to_color_str(mk_lang_stdout_html_color_text_t const color_id, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_ulong_t color_ul;
	mk_lang_types_pchar_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint32_t cui;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t tmp_str_buf[mk_sl_cui_uint32_strlen_hex_v];

	mk_lang_assert(color_id >= 0);
	mk_lang_assert(color_id < mk_lang_stdout_html_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	switch(color_id)
	{
		case mk_lang_stdout_html_color_text_e_dark_black   : color_ul = 0x0c0c0cul; break;
		case mk_lang_stdout_html_color_text_e_dark_red     : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_dark_green   : color_ul = 0x13a10eul; break;
		case mk_lang_stdout_html_color_text_e_dark_blue    : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_dark_yellow  : color_ul = 0xc19c00ul; break;
		case mk_lang_stdout_html_color_text_e_dark_magenta : color_ul = 0x881798ul; break;
		case mk_lang_stdout_html_color_text_e_dark_cyan    : color_ul = 0x3a96ddul; break;
		case mk_lang_stdout_html_color_text_e_dark_white   : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_black  : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_red    : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_green  : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_blue   : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_yellow : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_magenta: mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_cyan   : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_light_white  : mk_lang_check_todo(); break;
		case mk_lang_stdout_html_color_text_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&color_ul);
	ptr = str_buf;
	rem = str_len;
	if(!(rem >= 6)){ *out_len = 0; return 0; }
	mk_sl_cui_uint32_from_bi_ulong(&cui, &color_ul);
	len = mk_sl_cui_uint32_to_str_hexf_n(&cui, &tmp_str_buf[0], mk_lang_countof(tmp_str_buf)); mk_lang_assert(len == mk_sl_cui_uint32_strlen_hex_v);
	mk_lang_string_memcpy_pc_fn(ptr, &tmp_str_buf[2], mk_lang_countof(tmp_str_buf) - 2);
	ptr += 6;
	rem -= 6;
	*out_len = str_len - rem;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_output_begin(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(stdout_html_lokal);

	err = mk_sl_io_appender_file_open_n(&stdout_html_lokal->m_appender, "out.html"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_output_end(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(stdout_html_lokal);

	err = mk_sl_io_appender_file_close(&stdout_html_lokal->m_appender); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_file_begin(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);

	err = mk_lang_stdout_html_lokal_pr_output_begin(stdout_html_lokal); mk_lang_check_rereturn(err);
	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_file_begin[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_file_begin);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	err = mk_lang_stdout_html_lokal_pr_output_end(stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_file_end(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);

	err = mk_lang_stdout_html_lokal_pr_output_begin(stdout_html_lokal); mk_lang_check_rereturn(err);
	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_file_end[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_file_end);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	err = mk_lang_stdout_html_lokal_pr_output_end(stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_line_begin(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);

	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_line_begin[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_line_begin);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_line_end(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);

	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_line_end[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_line_end);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_color_begin(mk_lang_stdout_html_lokal_pt const stdout_html_lokal, mk_lang_stdout_html_color_text_t const color_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;
	mk_lang_types_pchar_t color_str[1 + mk_sl_cui_uint32_strlen_hex_v];
	mk_lang_types_sint_t color_len;

	mk_lang_assert(stdout_html_lokal);
	mk_lang_assert(color_id >= 0);
	mk_lang_assert(color_id < mk_lang_stdout_html_color_text_e_dummy_end);

	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_color_begin_a[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_color_begin_a);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);

	err = mk_lang_stdout_html_lokal_pr_color_id_to_color_str(color_id, &color_str[0], mk_lang_countof(color_str), &color_len); mk_lang_check_rereturn(err); mk_lang_assert(color_len >= 1); mk_lang_assert(color_len <= mk_lang_countof(color_str));
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, ((mk_sl_cui_uint8_pct)(&color_str[0])), color_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == color_len);

	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_color_begin_b[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_color_begin_b);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_color_end(mk_lang_stdout_html_lokal_pt const stdout_html_lokal) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);

	data_buf = ((mk_sl_cui_uint8_pct)(&mk_lang_stdout_html_lokal_k_color_end[0]));
	data_len = mk_lang_countstr(mk_lang_stdout_html_lokal_k_color_end);
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, data_buf, data_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_html_lokal_pr_text(mk_lang_stdout_html_lokal_pt const stdout_html_lokal, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t written;

	mk_lang_assert(stdout_html_lokal);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	/* todo html escaping */
	err = mk_sl_io_appender_file_append(&stdout_html_lokal->m_appender, ((mk_sl_cui_uint8_pct)(str_buf)), str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);
	return 0;
}





struct mk_lang_stdout_html_s
{
	mk_lang_stdout_html_lokal_t m_stdout_html_lokal;
};
typedef struct mk_lang_stdout_html_s mk_lang_stdout_html_t;
mk_lang_typedef(mk_lang_stdout_html);


static mk_lang_stdout_html_t mk_lang_stdout_html_g;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_file_begin(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_file_end(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_begin_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_output_begin(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_html_lokal_pr_line_begin(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_end_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_line_end(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_html_lokal_pr_output_end(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_begin_color(mk_lang_stdout_html_color_text_t const color) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_color_begin(&mk_lang_stdout_html_g.m_stdout_html_lokal, color); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_end_color(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_color_end(&mk_lang_stdout_html_g.m_stdout_html_lokal); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_print(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_html_lokal_pr_text(&mk_lang_stdout_html_g.m_stdout_html_lokal, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


#endif
