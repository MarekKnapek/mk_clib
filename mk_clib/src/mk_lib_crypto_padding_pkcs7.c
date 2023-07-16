#include "mk_lib_crypto_padding_pkcs7.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* RFC 2315 */
/* PKCS #7 */


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_pkcs7_pad(mk_sl_cui_uint8_pt const blocks, mk_lang_types_sint_t const content_len, mk_lang_types_sint_t const block_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_sl_cui_uint8_t u8 mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(blocks);
	mk_lang_assert(content_len >= 0x00 && content_len <= block_len);
	mk_lang_assert(block_len >= 0x01 && block_len <= 0xff);

	n = block_len - content_len; if(n == 0) n = block_len;
	mk_sl_cui_uint8_from_bi_sint(&u8, &n);
	for(i = 0; i != n; ++i)
	{
		blocks[content_len + i] = u8;
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_pkcs7_unpad(mk_sl_cui_uint8_pct const block, mk_lang_types_sint_t const block_len, mk_lang_types_sint_pt const content_len) mk_lang_noexcept
{
	#define check(x) if(!(x)){ *content_len = -1; return; } ((void)(0))

	mk_sl_cui_uint8_t u8 mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(block);
	mk_lang_assert(block_len >= 0x01 && block_len <= 0xff);
	mk_lang_assert(content_len);

	u8 = block[block_len - 1];
	mk_sl_cui_uint8_to_bi_sint(&u8, &n);
	check(n >= 0x01 && n <= block_len);
	for(i = 1; i != n; ++i)
	{
		check(mk_sl_cui_uint8_eq(&block[block_len - 1 - i], &u8));
	}
	*content_len = block_len - n;

	#undef check
}
