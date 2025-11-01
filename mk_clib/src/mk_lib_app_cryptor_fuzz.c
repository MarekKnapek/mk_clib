#ifndef mk_include_guard_mk_lib_app_cryptor_fuzz_c
#define mk_include_guard_mk_lib_app_cryptor_fuzz_c
#include "mk_lib_app_cryptor_fuzz.h"

#include "mk_lang_null.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_sint_t s;
	mk_lib_app_cryptor_direction_t direction;
	mk_lang_types_ulong_t bui;
	mk_lib_app_cryptor_mode_names_id_t mode;
	mk_lib_app_cryptor_alg_names_id_t alg;
	mk_lib_crypto_padding_names_id_t padding;
	mk_lang_types_bool_t kdf;
	mk_lib_crypto_hash_names_id_t hash;
	mk_lang_types_ulong_t cost;
	mk_lang_types_sint_t password_len;
	mk_sl_cui_uint8_t password_buf[512];
	mk_lang_types_sint_t salt_len;
	mk_sl_cui_uint8_t salt_buf[512];
	mk_lang_types_sint_t input_len;
	mk_sl_cui_uint8_t input_buf[512];
	mk_lang_types_sint_t encrypted_len_a;
	mk_lang_types_sint_t err;
	mk_lib_app_cryptor_t cryptor;
	mk_sl_cui_uint8_t encrypted_buf_a[mk_lang_countof(input_buf) + 16 + 64];
	mk_lang_types_sint_t input_consumed;
	mk_lang_types_sint_t output_consumed;
	mk_lang_types_sint_t encrypted_len_b;
	mk_lang_types_sint_t chunk_len;
	mk_lang_types_sint_t input_rem;
	mk_lang_types_sint_t decrypted_len_a;
	//mk_lang_types_sint_t decrypted_len_b;
	mk_sl_cui_uint8_t encrypted_buf_b[mk_lang_countof(input_buf) + 16 + 64];
	mk_sl_cui_uint8_t decrypted_buf_a[mk_lang_countof(input_buf)];
	//mk_sl_cui_uint8_t decrypted_buf_b[mk_lang_countof(input_buf)];
	mk_sl_cui_uint8_pct input_ptr;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = ((mk_lang_types_sint_t)(size));
	direction = mk_lib_app_cryptor_direction_e_encrypt;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	mode = ((mk_lib_app_cryptor_mode_names_id_t)(bui % mk_lib_app_cryptor_mode_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	alg = ((mk_lib_app_cryptor_alg_names_id_t)(bui % mk_lib_app_cryptor_alg_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	padding = ((mk_lib_crypto_padding_names_id_t)(bui % mk_lib_crypto_padding_names_id_e_dummy_end));
	kdf = mk_lang_true;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	hash = ((mk_lib_crypto_hash_names_id_t)(bui % mk_lib_crypto_hash_names_id_e_dummy_end));
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	cost = ((mk_lang_types_ulong_t)(bui)) % 1000u;
	cost = cost == 0 ? 1ul : cost;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	password_len = ((mk_lang_types_sint_t)(bui % mk_lang_countof(password_buf))) + 1;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	salt_len = ((mk_lang_types_sint_t)(bui % mk_lang_countof(salt_buf))) + 1;
	if(!(s >= mk_lang_bui_ulong_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_ulong_from_buis_uchar_le(&bui, &d[0]);
	d += mk_lang_bui_ulong_size_bytes_v;
	s -= mk_lang_bui_ulong_size_bytes_v;
	input_len = ((mk_lang_types_sint_t)(bui % mk_lang_countof(input_buf)));
	if(!(s >= password_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&password_buf[0], &d[0], password_len);
	d += password_len;
	s -= password_len;
	if(!(s >= salt_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&salt_buf[0], &d[0], salt_len);
	d += salt_len;
	s -= salt_len;
	if(!(s >= input_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&input_buf[0], &d[0], input_len);
	d += input_len;
	s -= input_len;

	encrypted_len_a = 0;
	err = mk_lib_app_cryptor_rw_construct_args(&cryptor, direction, mode, alg, padding, kdf, hash, cost, &password_buf[0], password_len, &salt_buf[0], salt_len); mk_lang_check_rereturn(err);
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

	input_ptr = &input_buf[0];
	input_rem = input_len;
	encrypted_len_b = 0;
	err = mk_lib_app_cryptor_rw_construct_args(&cryptor, direction, mode, alg, padding, kdf, hash, cost, &password_buf[0], password_len, &salt_buf[0], salt_len); mk_lang_check_rereturn(err);
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

	direction = mk_lib_app_cryptor_direction_e_decrypt;
	decrypted_len_a = 0;
	err = mk_lib_app_cryptor_rw_construct_args(&cryptor, direction, mode, alg, padding, kdf, hash, cost, &password_buf[0], password_len, &salt_buf[0], salt_len); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_append_chunk(&cryptor, &encrypted_buf_a[0], encrypted_len_a, &decrypted_buf_a[decrypted_len_a], mk_lang_countof(decrypted_buf_a) - decrypted_len_a, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(input_consumed >= 0);
	mk_lang_test(input_consumed <= encrypted_len_a);
	mk_lang_test(input_consumed == encrypted_len_a);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf_a) - decrypted_len_a);
	decrypted_len_a += output_consumed;
	err = mk_lib_app_cryptor_rw_finish(&cryptor, &decrypted_buf_a[decrypted_len_a], mk_lang_countof(decrypted_buf_a) - decrypted_len_a, &output_consumed); mk_lang_check_rereturn(err);
	mk_lang_test(output_consumed >= 0);
	mk_lang_test(output_consumed <= mk_lang_countof(decrypted_buf_a) - decrypted_len_a);
	decrypted_len_a += output_consumed;
	err = mk_lib_app_cryptor_rw_destroy(&cryptor); mk_lang_check_rereturn(err);

	mk_lang_test(decrypted_len_a == input_len);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&decrypted_buf_a[0], &input_buf[0], input_len) == 0);
	return 0;
}


#endif
