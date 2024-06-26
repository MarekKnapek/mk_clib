#include "mk_lib_crypto_alg_tdes2_fuzz.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_tdes2.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes2_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_sint_t i;
	mk_lib_crypto_alg_tdes2_key_t key;
	mk_lib_crypto_alg_tdes2_msg_t pt1;
	mk_lib_crypto_alg_tdes2_msg_t ct;
	mk_lib_crypto_alg_tdes2_msg_t pt2;
	mk_lang_types_bool_t b;

	d = data;
	s = size;
	if(!(s >= 3 * 64 / 8))
	{
		return;
	}
	for(i = 0; i != 2 * 8; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[i], &d[i]);
	}
	d += 2 * 8;
	s -= 2 * 8;
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&pt1.m_data.m_uint8s[i], &d[i]);
	}
	d += 8;
	s -= 8;
	mk_lib_crypto_alg_tdes2_encrypt(&key, &pt1, &ct);
	b = mk_lang_false; for(i = 0; i != 8; ++i){ b = b | mk_sl_cui_uint8_ne(&ct.m_data.m_uint8s[i], &pt1.m_data.m_uint8s[i]); } mk_lang_test(b);
	mk_lib_crypto_alg_tdes2_decrypt(&key, &ct, &pt2);
	b = mk_lang_true; for(i = 0; i != 8; ++i){ b = b & mk_sl_cui_uint8_eq(&pt2.m_data.m_uint8s[i], &pt1.m_data.m_uint8s[i]); } mk_lang_test(b);
}
