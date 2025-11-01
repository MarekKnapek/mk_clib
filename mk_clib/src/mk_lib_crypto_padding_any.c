#ifndef mk_include_guard_mk_lib_crypto_padding_any_c
#define mk_include_guard_mk_lib_crypto_padding_any_c
#include "mk_lib_crypto_padding_any.h"

#include "mk_lang_assert.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_padding_iso9797pm2.h"
#include "mk_lib_crypto_padding_pkcs7.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_any_pad(mk_lib_crypto_padding_any_id_t const id, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_t const block_len, mk_lang_types_sint_t const free_space) mk_lang_noexcept
{
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_padding_any_id_e_dummy_end);
	mk_lang_assert(data_buf);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= block_len);
	mk_lang_assert(block_len == 1 || block_len == 8 || block_len == 16);
	mk_lang_assert(free_space >= 0);

	switch(id)
	{
		case mk_lib_crypto_padding_any_id_e_iso9797pm2: r = mk_lib_crypto_padding_iso9797pm2_pad(data_buf, data_len, block_len, free_space); break;
		case mk_lib_crypto_padding_any_id_e_pkcs7: r = mk_lib_crypto_padding_pkcs7_pad(data_buf, data_len, block_len, free_space); break;
		case mk_lib_crypto_padding_any_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&r);
	return r;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_any_unpad(mk_lib_crypto_padding_any_id_t const id, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const block_len) mk_lang_noexcept
{
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_padding_any_id_e_dummy_end);
	mk_lang_assert(data_buf);
	mk_lang_assert(block_len == 1 || block_len == 8 || block_len == 16);

	switch(id)
	{
		case mk_lib_crypto_padding_any_id_e_iso9797pm2: r = mk_lib_crypto_padding_iso9797pm2_unpad(data_buf, block_len); break;
		case mk_lib_crypto_padding_any_id_e_pkcs7: r = mk_lib_crypto_padding_pkcs7_unpad(data_buf, block_len); break;
		case mk_lib_crypto_padding_any_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&r);
	return r;
}


#endif
