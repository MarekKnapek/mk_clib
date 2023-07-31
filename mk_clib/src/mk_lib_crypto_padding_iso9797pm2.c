#include "mk_lib_crypto_padding_iso9797pm2.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* ISO 9797 */


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_iso9797pm2_pad(mk_sl_cui_uint8_pt const blocks, mk_lang_types_sint_t const content_len, mk_lang_types_sint_t const block_len) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t s_mark = mk_sl_cui_uint8_c(0x80);

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(blocks);
	mk_lang_assert(content_len >= 0x00 && content_len <= block_len);
	mk_lang_assert(block_len >= 0x01 && block_len <= 0xff);

	blocks[content_len] = s_mark;
	n = block_len - content_len; if(n == 0) n = block_len;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_uint8_set_zero(&blocks[content_len + i]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_iso9797pm2_unpad(mk_sl_cui_uint8_pct const block, mk_lang_types_sint_t const block_len, mk_lang_types_sint_pt const content_len) mk_lang_noexcept
{
	#define check(x) if(!(x)){ *content_len = -1; return; } ((void)(0))

	mk_lang_constexpr_static mk_sl_cui_uint8_t s_mark = mk_sl_cui_uint8_c(0x80);

	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(block);
	mk_lang_assert(block_len >= 0x01 && block_len <= 0xff);
	mk_lang_assert(content_len);

	ptr = &block[block_len - 1];
	for(i = 0; i != block_len - 1 && mk_sl_cui_uint8_is_zero(ptr); ++i)
	{
		--ptr;
	}
	check(mk_sl_cui_uint8_eq(ptr, &s_mark));
	*content_len = ((int)(ptr - block));

	#undef check
}
