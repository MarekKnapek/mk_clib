#ifndef mk_include_guard_mk_lib_crypto_padding_iso9797pm2_c
#define mk_include_guard_mk_lib_crypto_padding_iso9797pm2_c
#include "mk_lib_crypto_padding_iso9797pm2.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_iso9797pm2_pad(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_t const block_len, mk_lang_types_sint_t const free_space) mk_lang_noexcept
{
	mk_lang_types_sint_t padding_len mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= block_len);
	mk_lang_assert(block_len == 8 || block_len == 16);
	mk_lang_assert(free_space >= 0);

	padding_len = ((mk_lang_types_sint_t)(((mk_lang_types_uint_t)(block_len)) - (((mk_lang_types_uint_t)(data_len)) % ((mk_lang_types_uint_t)(block_len)))));
	mk_lang_assert(padding_len >= 1);
	mk_lang_assert(padding_len <= block_len);
	mk_lang_assert(free_space >= padding_len);
	tsi = 0x80; mk_sl_cui_uint8_from_bi_sint(&cui, &tsi);
	data_buf[data_len] = cui;
	n = padding_len;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_uint8_set_zero(&data_buf[data_len + i]);
	}
	return padding_len;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_iso9797pm2_unpad(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const block_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_t cui mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t padding_len mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(block_len == 8 || block_len == 16);

	n = block_len;
	for(i = 0; i != n; ++i)
	{
		if(!mk_sl_cui_uint8_is_zero(&data_buf[(block_len - 1) - i]))
		{
			break;
		}
	}
	tsi = 0x80; mk_sl_cui_uint8_from_bi_sint(&cui, &tsi);
	gud = mk_lang_true;
	gud &= i != n;
	gud &= mk_sl_cui_uint8_eq(&data_buf[(block_len - 1) - i], &cui);
	padding_len = i + 1;
	return gud ? padding_len : -1;
}


#endif
