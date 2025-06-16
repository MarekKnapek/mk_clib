#ifndef mk_include_guard_mk_lib_iip_base32_fuzz_c
#define mk_include_guard_mk_lib_iip_base32_fuzz_c
#include "mk_lib_iip_base32_fuzz.h"

#include "mk_lang_bui.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_base32_decoder.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_base32_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_bui_uchar_t tuc;
	mk_lang_types_pchar_t fill_pc;
	mk_sl_cui_uint8_t fill_u8;
	mk_lang_bui_ushort_t tus;
	mk_lang_types_sint_t input_u8s_len;
	mk_sl_cui_uint8_t input_u8s_buf[256];
	mk_lang_types_pchar_t output_pcs_buf[mk_lang_roundup_div(mk_lang_countof(input_u8s_buf) * 8, 5)];
	mk_lang_types_sint_t output_pcs_len;
	mk_sl_cui_uint8_t output_u8s_buf[mk_lang_countof(input_u8s_buf)];
	mk_lang_types_sint_t output_u8s_len;
	mk_lang_types_bool_t success;
	mk_lang_types_pchar_t input_pcs_buf[mk_lang_countof(input_u8s_buf)];

	d = data;
	s = size;

	if(!(s <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))) return 0;

	if(!(s >= mk_lang_bui_uchar_size_bytes_v)) return 0;
	mk_lang_bui_uchar_from_buis_uchar_le(&tuc, &d[0]); /* todo ne */
	d += mk_lang_bui_uchar_size_bytes_v;
	s -= mk_lang_bui_uchar_size_bytes_v;
	fill_pc = ((mk_lang_types_pchar_t)(tuc));
	mk_sl_cui_uint8_from_bi_uchar(&fill_u8, &tuc);

	if(!(s >= mk_lang_bui_ushort_size_bytes_v)) return 0;
	mk_lang_bui_ushort_from_buis_uchar_le(&tus, &d[0]); /* todo ne */
	d += mk_lang_bui_ushort_size_bytes_v;
	s -= mk_lang_bui_ushort_size_bytes_v;
	input_u8s_len = ((mk_lang_types_sint_t)(tus));
	input_u8s_len = mk_lang_max(input_u8s_len, 0);
	input_u8s_len = mk_lang_min(input_u8s_len, mk_lang_countof(input_u8s_buf));
	input_u8s_len = mk_lang_min(input_u8s_len, ((mk_lang_types_sint_t)(s)));

	mk_sl_cui_uint8_memset_fn(&input_u8s_buf[0], &fill_u8, mk_lang_countof(input_u8s_buf));
	mk_sl_cui_uint8_from_bi_uchar_many(&input_u8s_buf[0], d, input_u8s_len);
	d += input_u8s_len;
	s -= input_u8s_len;

	mk_lang_string_memset_pc_fn(&output_pcs_buf[0], &fill_pc, mk_lang_countof(output_pcs_buf));
	mk_lib_iip_base32_encoder_fn(&input_u8s_buf[0], input_u8s_len, &output_pcs_buf[0], mk_lang_countof(output_pcs_buf), &output_pcs_len);
	mk_lang_test(output_pcs_len >= 0);
	mk_lang_test(output_pcs_len <= mk_lang_countof(output_pcs_buf));

	mk_sl_cui_uint8_memset_fn(&output_u8s_buf[0], &fill_u8, mk_lang_countof(output_u8s_buf));
	mk_lib_iip_base32_decoder_no_check(&output_pcs_buf[0], output_pcs_len, &output_u8s_buf[0], mk_lang_countof(output_u8s_buf), &output_u8s_len);
	mk_lang_test(output_u8s_len >= 0);
	mk_lang_test(output_u8s_len <= mk_lang_countof(output_u8s_buf));

	mk_lang_test(output_u8s_len == input_u8s_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&output_u8s_buf[0], &input_u8s_buf[0], input_u8s_len) == 0);

	mk_sl_cui_uint8_memset_fn(&output_u8s_buf[0], &fill_u8, mk_lang_countof(output_u8s_buf));
	mk_lib_iip_base32_decoder_do_check(&output_pcs_buf[0], output_pcs_len, &output_u8s_buf[0], mk_lang_countof(output_u8s_buf), &output_u8s_len, &success);
	mk_lang_test(output_u8s_len >= 0);
	mk_lang_test(output_u8s_len <= mk_lang_countof(output_u8s_buf));
	mk_lang_test(success);

	mk_lang_test(output_u8s_len == input_u8s_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&output_u8s_buf[0], &input_u8s_buf[0], input_u8s_len) == 0);

	mk_lang_string_memset_pc_fn(&input_pcs_buf[0], &fill_pc, mk_lang_countof(input_pcs_buf));
	mk_sl_cui_uint8_to_bi_pchar_many(&input_u8s_buf[0], &input_pcs_buf[0], input_u8s_len);
	mk_lib_iip_base32_decoder_do_check(&input_pcs_buf[0], input_u8s_len, &output_u8s_buf[0], mk_lang_countof(output_u8s_buf), &output_u8s_len, &success);
	if(success)
	{
		mk_lang_test(output_u8s_len >= 0);
		mk_lang_test(output_u8s_len <= mk_lang_countof(output_u8s_buf));
	}

	return 0;
}


#endif
