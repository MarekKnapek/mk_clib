#ifndef mk_include_guard_mk_lib_app_cryptor_fuzz_c
#define mk_include_guard_mk_lib_app_cryptor_fuzz_c
#include "mk_lib_app_cryptor_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_app_cryptor_fuzz_pr_get_config(mk_lib_app_cryptor_config_pt const config, mk_lang_types_uchar_pct const data, mk_lang_types_sint_t const size, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_sint_t s;
	mk_lib_app_cryptor_direction_t direction;
	mk_lang_types_uint_t bui;
	mk_lib_app_cryptor_mode_names_id_t mode;
	mk_lib_app_cryptor_alg_names_id_t alg;
	mk_lib_crypto_padding_names_id_t padding;
	mk_lang_types_bool_t kdf;
	mk_lib_crypto_hash_names_id_t hash;
	mk_lang_types_ulong_t cost;
	mk_lang_types_sint_t password_len;
	mk_lang_types_sint_t salt_len;

	mk_lang_assert(config);
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(consumed);

	d = data;
	s = size;
	direction = mk_lib_app_cryptor_direction_e_encrypt;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	mode = ((mk_lib_app_cryptor_mode_names_id_t)(bui % mk_lib_app_cryptor_mode_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	alg = ((mk_lib_app_cryptor_alg_names_id_t)(bui % mk_lib_app_cryptor_alg_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	padding = ((mk_lib_crypto_padding_names_id_t)(bui % mk_lib_crypto_padding_names_id_e_dummy_end));
	kdf = mk_lang_true;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	hash = ((mk_lib_crypto_hash_names_id_t)(bui % mk_lib_crypto_hash_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	cost = (bui % 1000) + 1;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	password_len = ((mk_lang_types_sint_t)(bui % 512)) + 1;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return mk_lang_false;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	salt_len = ((mk_lang_types_sint_t)(bui % 512)) + 1;
	config->m_direction = direction;
	config->m_mode = mode;
	config->m_alg = alg;
	config->m_padding = padding;
	config->m_kdf = kdf;
	config->m_hash = hash;
	config->m_cost = cost;
	config->m_password_len = password_len;
	config->m_salt_len = salt_len;
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_sint_t s;
	mk_lib_app_cryptor_config_t config;
	mk_lang_types_sint_t consumed;
	mk_lang_types_ulong_t bui;
	mk_lang_types_sint_t input_len;
	mk_sl_cui_uint8_t input_buf[512];
	mk_sl_cui_uint8_t password_buf[512];
	mk_sl_cui_uint8_t salt_buf[512];
	mk_lang_types_sint_t encrypted_len_a;
	mk_lang_types_sint_t err;
	mk_lib_app_cryptor_t cryptor;
	mk_sl_cui_uint8_t encrypted_buf_a[mk_lang_countof(input_buf) + 16 + 64];
	mk_lang_types_sint_t input_consumed;
	mk_lang_types_sint_t output_consumed;
	mk_sl_cui_uint8_pct input_ptr;
	mk_lang_types_sint_t input_rem;
	mk_lang_types_sint_t encrypted_len_b;
	mk_sl_cui_uint8_t encrypted_buf_b[mk_lang_countof(input_buf) + 16 + 64];
	mk_lang_types_sint_t chunk_len;
	mk_lang_types_sint_t decrypted_len;
	mk_sl_cui_uint8_t decrypted_buf[mk_lang_countof(input_buf)];

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = ((mk_lang_types_sint_t)(size));
	if(!mk_lib_app_cryptor_fuzz_pr_get_config(&config, d, s, &consumed))
	{
		return 0;
	}
	d += consumed;
	s -= consumed;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	input_len = ((mk_lang_types_sint_t)(bui % mk_lang_countof(input_buf)));
	if(!(s >= config.m_password_len && config.m_password_len <= mk_lang_countof(password_buf)))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&password_buf[0], &d[0], config.m_password_len);
	config.m_password_ptr = &password_buf[0];
	d += config.m_password_len;
	s -= config.m_password_len;
	if(!(s >= config.m_salt_len && config.m_salt_len <= mk_lang_countof(salt_buf)))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&salt_buf[0], &d[0], config.m_salt_len);
	config.m_salt_ptr = &salt_buf[0];
	d += config.m_salt_len;
	s -= config.m_salt_len;
	if(!(s >= input_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&input_buf[0], &d[0], input_len);
	d += input_len;
	s -= input_len;

	mk_sl_cui_uint8_memclr_fn(&encrypted_buf_a[0], mk_lang_countof(encrypted_buf_a));
	encrypted_len_a = 0;
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor, &config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, &input_buf[0], input_len, &encrypted_buf_a[encrypted_len_a], mk_lang_countof(encrypted_buf_a) - encrypted_len_a, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= input_len);
	mk_lang_test(input_consumed == input_len);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(encrypted_buf_a) - encrypted_len_a);
	encrypted_len_a += output_consumed;
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &encrypted_buf_a[encrypted_len_a], mk_lang_countof(encrypted_buf_a) - encrypted_len_a, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(encrypted_buf_a) - encrypted_len_a);
	encrypted_len_a += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_sl_cui_uint8_memclr_fn(&encrypted_buf_b[0], mk_lang_countof(encrypted_buf_b));
	input_ptr = &input_buf[0];
	input_rem = input_len;
	encrypted_len_b = 0;
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor, &config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, mk_lang_null, 0, &encrypted_buf_b[encrypted_len_b], mk_lang_countof(encrypted_buf_b) - encrypted_len_b, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= 0);
	mk_lang_test(input_consumed == 0);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(encrypted_buf_b) - encrypted_len_b);
	input_ptr += input_consumed;
	input_rem -= input_consumed;
	encrypted_len_b += output_consumed;
	for(;;)
	{
		if(input_rem == 0)
		{
			break;
		}
		if(!(s >= mk_lang_bui_ulong_size_bytes_v))
		{
			return 0;
		}
		mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
		d += mk_lang_bui_ulong_size_bytes_v;
		s -= mk_lang_bui_ulong_size_bytes_v;
		chunk_len = ((mk_lang_types_sint_t)(bui));
		chunk_len = mk_lang_clamp(chunk_len, 0, input_rem);
		err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, input_ptr, chunk_len, &encrypted_buf_b[encrypted_len_b], mk_lang_countof(encrypted_buf_b) - encrypted_len_b, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
		mk_lang_test(input_consumed >= 0);
		mk_lang_test(input_consumed <= chunk_len);
		mk_lang_test(input_consumed == chunk_len);
		mk_lang_test(output_consumed >= 0);
		mk_lang_test(output_consumed <= mk_lang_countof(encrypted_buf_b) - encrypted_len_b);
		input_ptr += input_consumed;
		input_rem -= input_consumed;
		encrypted_len_b += output_consumed;
	}
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &encrypted_buf_b[encrypted_len_b], mk_lang_countof(encrypted_buf_b) - encrypted_len_b, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(encrypted_buf_b) - encrypted_len_b);
	encrypted_len_b += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_lang_test(encrypted_len_b == encrypted_len_a);

	mk_sl_cui_uint8_memclr_fn(&decrypted_buf[0], mk_lang_countof(decrypted_buf));
	config.m_direction = mk_lib_app_cryptor_direction_e_decrypt;
	decrypted_len = 0;
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor, &config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, &encrypted_buf_a[0], encrypted_len_a, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= encrypted_len_a);
	mk_lang_test(input_consumed == encrypted_len_a);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	decrypted_len += output_consumed;
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	decrypted_len += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_lang_test(decrypted_len == input_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&decrypted_buf[0], &input_buf[0], input_len) == 0);

	mk_sl_cui_uint8_memclr_fn(&decrypted_buf[0], mk_lang_countof(decrypted_buf));
	config.m_direction = mk_lib_app_cryptor_direction_e_decrypt;
	decrypted_len = 0;
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor, &config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, &encrypted_buf_b[0], encrypted_len_b, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= encrypted_len_b);
	mk_lang_test(input_consumed == encrypted_len_b);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	decrypted_len += output_consumed;
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	decrypted_len += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_lang_test(decrypted_len == input_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&decrypted_buf[0], &input_buf[0], input_len) == 0);

	mk_sl_cui_uint8_memclr_fn(&decrypted_buf[0], mk_lang_countof(decrypted_buf));
	input_ptr = &encrypted_buf_a[0];
	input_rem = encrypted_len_a;
	config.m_direction = mk_lib_app_cryptor_direction_e_decrypt;
	decrypted_len = 0;
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor, &config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, input_ptr, 16, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= 16);
	mk_lang_test(input_consumed == 16);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	input_ptr += input_consumed;
	input_rem -= input_consumed;
	decrypted_len += output_consumed;
	for(;;)
	{
		if(input_rem == 0)
		{
			break;
		}
		if(!(s >= mk_lang_bui_ulong_size_bytes_v))
		{
			return 0;
		}
		mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
		d += mk_lang_bui_ulong_size_bytes_v;
		s -= mk_lang_bui_ulong_size_bytes_v;
		chunk_len = ((mk_lang_types_sint_t)(bui));
		chunk_len = mk_lang_clamp(chunk_len, 0, input_rem);
		err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, input_ptr, chunk_len, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
		mk_lang_test(input_consumed >= 0);
		mk_lang_test(input_consumed <= chunk_len);
		mk_lang_test(input_consumed == chunk_len);
		mk_lang_test(output_consumed >= 0);
		mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
		input_ptr += input_consumed;
		input_rem -= input_consumed;
		decrypted_len += output_consumed;
	}
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &decrypted_buf[decrypted_len], mk_lang_countof(decrypted_buf) - decrypted_len, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf) - decrypted_len);
	decrypted_len += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_lang_test(decrypted_len == input_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&decrypted_buf[0], &input_buf[0], input_len) == 0);
	return 0;
}


#endif
