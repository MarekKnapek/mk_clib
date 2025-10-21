#ifndef mk_include_guard_mk_lib_crypto_mode_stream_any2_fuzz_c
#define mk_include_guard_mk_lib_crypto_mode_stream_any2_fuzz_c
#include "mk_lib_crypto_mode_stream_any2_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_mode_stream_any1.h"
#include "mk_lib_crypto_mode_stream_any2.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any2_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_bui_uint_t bui;
	mk_lang_types_sint_t mode_type;
	mk_lib_crypto_mode_stream_any1_id_t mode_id;
	mk_lang_types_sint_t offset;
	mk_sl_cui_uint8_t storage[1 * 1024];
	mk_lang_types_sint_t offset2;
	mk_lang_types_sint_t offset3;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t nblocks;
	mk_lib_crypto_mode_stream_any2_key_t key_any2;
	mk_lib_crypto_mode_stream_any2_iv_t iv_any2;
	mk_sl_cui_uint8_t storage2[mk_lang_countof(storage) + mk_lib_crypto_mode_stream_any2_msg_len_v];
	mk_lib_crypto_mode_stream_any2_t mode_any2;
	mk_lang_types_usize_t output_used;
	mk_sl_cui_uint8_t storage3[mk_lang_countof(storage) + mk_lib_crypto_mode_stream_any2_msg_len_v];
	mk_lang_types_usize_t used;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, d); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	mode_type = ((mk_lang_types_sint_t)(bui));
	mode_type = mk_lang_max(0, mode_type);
	mode_type = mode_type % ((mk_lang_types_sint_t)(mk_lib_crypto_mode_stream_any1_id_e_dummy_end));
	mode_id =((mk_lib_crypto_mode_stream_any1_id_t)(mode_type));

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, d); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	offset = ((mk_lang_types_sint_t)(bui));
	offset = mk_lang_max(0, offset);
	offset = mk_lang_clamp(offset, 0, mk_lang_countof(storage));

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, d); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	offset2 = ((mk_lang_types_sint_t)(bui));
	offset2 = mk_lang_max(0, offset2);
	offset2 = mk_lang_clamp(offset2, 0, mk_lang_countof(storage));

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&bui, d); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	offset3 = ((mk_lang_types_sint_t)(bui));
	offset3 = mk_lang_max(0, offset3);
	offset3 = mk_lang_clamp(offset3, 0, mk_lang_countof(storage));

	rem = mk_lang_countof(storage) - mk_lang_max(mk_lang_max(offset, offset2), offset3);
	nblocks = rem / mk_lib_crypto_mode_stream_any2_msg_len_v;
	if(nblocks == 0)
	{
		return 0;
	}

	if(!(s >= mk_lib_crypto_mode_stream_any2_key_len_v))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&key_any2.m_data.m_uint8s[0], d, mk_lib_crypto_mode_stream_any2_key_len_v);
	d += mk_lib_crypto_mode_stream_any2_key_len_v;
	s -= mk_lib_crypto_mode_stream_any2_key_len_v;

	if(!(s >= mk_lib_crypto_mode_stream_any2_iv_len_v))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&iv_any2.m_data.m_uint8s[0], d, mk_lib_crypto_mode_stream_any2_iv_len_v);
	d += mk_lib_crypto_mode_stream_any2_iv_len_v;
	s -= mk_lib_crypto_mode_stream_any2_iv_len_v;

	if(!(s >= ((mk_lang_types_usize_t)(nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v))))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&storage[offset], d, nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v);
	d += nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v;
	s -= nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v;

	mk_sl_cui_uint8_memclr_fn(&storage2[0], mk_lang_countof(storage2));
	mk_lib_crypto_mode_stream_any2_rw_construct(&mode_any2, mode_id);
	mk_lib_crypto_mode_stream_any2_rw_set_key_enc(&mode_any2, &key_any2);
	mk_lib_crypto_mode_stream_any2_rw_set_iv(&mode_any2, &iv_any2);
	mk_lib_crypto_mode_stream_any2_rw_encrypt(&mode_any2, &storage[offset], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v, &storage2[offset2], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v + mk_lib_crypto_mode_stream_any2_msg_len_v, &output_used);
	mk_lang_test(output_used == ((mk_lang_types_usize_t)(nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v)));
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&storage[offset], &storage2[offset2], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v) != 0);

	mk_sl_cui_uint8_memclr_fn(&storage3[0], mk_lang_countof(storage3));
	mk_lib_crypto_mode_stream_any2_rw_construct(&mode_any2, mode_id);
	mk_lib_crypto_mode_stream_any2_rw_set_key_dec(&mode_any2, &key_any2);
	mk_lib_crypto_mode_stream_any2_rw_set_iv(&mode_any2, &iv_any2);
	mk_lib_crypto_mode_stream_any2_rw_decrypt(&mode_any2, &storage2[offset2], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v, &storage3[offset3], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v + mk_lib_crypto_mode_stream_any2_msg_len_v, &output_used);
	mk_lang_test(output_used == ((mk_lang_types_usize_t)(nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v)));
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&storage3[offset3], &storage[offset], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v) == 0);

	used = 0;
	mk_sl_cui_uint8_memclr_fn(&storage3[0], mk_lang_countof(storage3));
	mk_lib_crypto_mode_stream_any2_rw_construct(&mode_any2, mode_id);
	mk_lib_crypto_mode_stream_any2_rw_set_key_enc(&mode_any2, &key_any2);
	mk_lib_crypto_mode_stream_any2_rw_set_iv(&mode_any2, &iv_any2);
	n = nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_stream_any2_rw_encrypt(&mode_any2, &storage[offset + i], 1, &storage3[offset3 + used], 1 + mk_lib_crypto_mode_stream_any2_msg_len_v, &output_used);
		used += output_used;
	}
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&storage3[offset3], &storage2[offset2], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v) == 0);

	used = 0;
	mk_sl_cui_uint8_memclr_fn(&storage3[0], mk_lang_countof(storage3));
	mk_lib_crypto_mode_stream_any2_rw_construct(&mode_any2, mode_id);
	mk_lib_crypto_mode_stream_any2_rw_set_key_dec(&mode_any2, &key_any2);
	mk_lib_crypto_mode_stream_any2_rw_set_iv(&mode_any2, &iv_any2);
	n = nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_stream_any2_rw_decrypt(&mode_any2, &storage2[offset2 + i], 1, &storage3[offset3 + used], 1 + mk_lib_crypto_mode_stream_any2_msg_len_v, &output_used);
		used += output_used;
	}
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&storage3[offset3], &storage[offset], nblocks * mk_lib_crypto_mode_stream_any2_msg_len_v) == 0);
	return 0;
}


#endif
