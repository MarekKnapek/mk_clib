#include "mk_lib_crypto_xof_stream_shake_256_fuzz.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_stream_shake_256.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_shake_256_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lib_crypto_xof_stream_shake_256_t shake_256_a;
	mk_lang_types_ushort_t len;
	mk_lib_crypto_xof_stream_shake_256_t shake_256_b;
	mk_lang_types_ushort_t digest_len;
	mk_sl_cui_uint8_t digest_a[1024];
	mk_lang_types_ushort_t npieces;
	mk_lang_types_ushort_t ipiece;
	mk_lang_types_ushort_t cursor;
	mk_lang_types_ushort_t rem;
	mk_sl_cui_uint8_t digest_b[sizeof(digest_a)];
	mk_lang_types_ushort_t i;

	d = data;
	s = size;
	mk_lib_crypto_xof_stream_shake_256_init(&shake_256_a);
	if(!(s >= 2)) return;
	len = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << (0 * 8))) | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[1])) << (1 * 8)))));
	d += 2;
	s -= 2;
	if(!(s >= len)) return;
	mk_lib_crypto_xof_stream_shake_256_append(&shake_256_a, ((mk_lang_types_uchar_pct)(d)), len);
	d += len;
	s -= len;
	mk_lib_crypto_xof_stream_shake_256_finish(&shake_256_a);
	shake_256_b = shake_256_a;
	if(!(s >= 2)) return;
	len = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << (0 * 8))) | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[1])) << (1 * 8)))));
	d += 2;
	s -= 2;
	digest_len = len;
	digest_len = mk_lang_min(digest_len, mk_lang_countof(digest_a));
	mk_lib_crypto_xof_stream_shake_256_squeeze(&shake_256_a, digest_len, &digest_a[0]);
	if(!(s >= 2)) return;
	len = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << (0 * 8))) | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[1])) << (1 * 8)))));
	d += 2;
	s -= 2;
	npieces = len;
	cursor = 0;
	for(ipiece = 0; ipiece != npieces; ++ipiece)
	{
		rem = digest_len - cursor;
		if(rem == 0) break;
		if(!(s >= 2)) break;
		len = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << (0 * 8))) | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[1])) << (1 * 8)))));
		d += 2;
		s -= 2;
		len = mk_lang_min(len, rem);
		mk_lib_crypto_xof_stream_shake_256_squeeze(&shake_256_b, len, &digest_b[cursor]);
		cursor += len;
	}
	for(i = 0; i != cursor; ++i)
	{
		mk_lang_test(mk_sl_cui_uint8_eq(&digest_b[i], &digest_a[i]));
	}
}
