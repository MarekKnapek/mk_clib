#include "mk_lib_vc.h"

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_lib_crypto_alg_twofish_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_streebog_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_whirlpool.h"
#include "mk_lib_hash_crc32.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_vc_memcpyu8
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memset_t_name mk_lib_vc_memsetu8
#define mk_lang_memset_t_base mk_sl_cui_uint8
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_strlen_t_name mk_lib_vc_strlenpc
#define mk_lang_strlen_t_type mk_lang_types_pchar_t
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"

#define mk_lang_strlen_t_name mk_lib_vc_strlenwc
#define mk_lang_strlen_t_type mk_lang_types_wchar_t
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_vc_mode
#define mk_lib_crypto_mode_base_t_len mk_lib_vc_msg_len
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_tweak_next(mk_lib_vc_tweak_pct const curr, mk_lib_vc_tweak_pt const next) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_sl_cui_uint128_t tu128 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;

	mk_lang_assert(curr);
	mk_lang_assert(next);

	mk_sl_cui_uint8_shr3(&curr->m_data.m_uint8s[mk_lib_vc_msg_len - 1], mk_lang_charbit - 1, &tu8);
	mk_sl_uint_128_from_8_le(&tu128, &curr->m_data.m_uint8s[0]);
	mk_sl_cui_uint128_shl2(&tu128, 1);
	mk_sl_uint_128_to_8_le(&tu128, &next->m_data.m_uint8s[0]);
	if(!mk_sl_cui_uint8_is_zero(&tu8))
	{
		tsi = 0x87;
		mk_sl_cui_uint8_from_bi_sint(&tu8, &tsi);
		mk_sl_cui_uint8_xor2(&next->m_data.m_uint8s[0], &tu8);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_alg_encrypt_tweak(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule, mk_lib_vc_tweak_pct const in, mk_lib_vc_tweak_pt const out) mk_lang_noexcept
{
	mk_lang_assert(algid >= 0 && algid < mk_lib_vc_algid_e_dummy);
	mk_lang_assert(in);
	mk_lang_assert(out);

	switch(algid)
	{
		case mk_lib_vc_algid_e_aes:     mk_lang_assert(schedule.m_data.m_aes);     mk_lib_crypto_alg_aes_256_schedule_encrypt    (schedule.m_data.m_aes,     &in->m_data.m_aes,     &out->m_data.m_aes,     1); break;
		case mk_lib_vc_algid_e_serpent: mk_lang_assert(schedule.m_data.m_serpent); mk_lib_crypto_alg_serpent_schedule_encrypt    (schedule.m_data.m_serpent, &in->m_data.m_serpent, &out->m_data.m_serpent, 1); break;
		case mk_lib_vc_algid_e_twofish: mk_lang_assert(schedule.m_data.m_twofish); mk_lib_crypto_alg_twofish_256_schedule_encrypt(schedule.m_data.m_twofish, &in->m_data.m_twofish, &out->m_data.m_twofish, 1); break;
		case mk_lib_vc_algid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_alg_decrypt_block(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_vc_msg_len == mk_lib_crypto_alg_aes_256_msg_len_v);
	mk_lang_static_assert(mk_lib_vc_msg_len == mk_lib_crypto_alg_serpent_msg_len_v);

	mk_lang_assert(algid >= 0 && algid < mk_lib_vc_algid_e_dummy);
	mk_lang_assert(in);
	mk_lang_assert(out);

	switch(algid)
	{
		case mk_lib_vc_algid_e_aes:     mk_lang_assert(schedule.m_data.m_aes);     mk_lib_crypto_alg_aes_256_schedule_decrypt    (schedule.m_data.m_aes,     &in->m_data.m_aess[0],     &out->m_data.m_aess[0],     mk_lib_vc_msgs_per_block); break;
		case mk_lib_vc_algid_e_serpent: mk_lang_assert(schedule.m_data.m_serpent); mk_lib_crypto_alg_serpent_schedule_decrypt    (schedule.m_data.m_serpent, &in->m_data.m_serpents[0], &out->m_data.m_serpents[0], mk_lib_vc_msgs_per_block); break;
		case mk_lib_vc_algid_e_twofish: mk_lang_assert(schedule.m_data.m_twofish); mk_lib_crypto_alg_twofish_256_schedule_decrypt(schedule.m_data.m_twofish, &in->m_data.m_twofishs[0], &out->m_data.m_twofishs[0], mk_lib_vc_msgs_per_block); break;
		case mk_lib_vc_algid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_xts_decrypt_block(mk_lib_vc_algid_t const algid, mk_lib_vc_alg_schedule_t const schedule_pri, mk_lib_vc_alg_schedule_t const schedule_sec, mk_sl_cui_uint64_pct const block_id, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept
{
	mk_lib_vc_block_pt tweaks mk_lang_constexpr_init;
	mk_lib_vc_block_oversized_t tweaks_oversized mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64 mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_aes_256_msg_len_v     == mk_lib_vc_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_serpent_msg_len_v     == mk_lib_vc_msg_len);
	mk_lang_static_assert(mk_lib_crypto_alg_twofish_256_msg_len_v == mk_lib_vc_msg_len);

	mk_lang_assert(algid >= 0 && algid < mk_lib_vc_algid_e_dummy);
	mk_lang_assert(block_id);
	mk_lang_assert(in);
	mk_lang_assert(out);

	tweaks = ((mk_lib_vc_block_pt)(mk_lang_roundup_align_ptr(&tweaks_oversized, sizeof(*tweaks))));
	mk_sl_uint_64_to_8_le(block_id, &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[0 * 8]);
	mk_sl_cui_uint64_set_zero(&tu64);
	mk_sl_uint_64_to_8_le(&tu64, &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[1 * 8]);
	mk_lib_vc_alg_encrypt_tweak(algid, schedule_sec, &tweaks->m_data.m_tweaks[0], &tweaks->m_data.m_tweaks[0]);
	mk_lib_vc_mode_xor3(&in->m_data.m_tweaks[0].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[0].m_data.m_uint8s[0], &out->m_data.m_tweaks[0].m_data.m_uint8s[0]);
	for(i = 1; i != mk_lib_vc_msgs_per_block; ++i)
	{
		mk_lib_vc_tweak_next(&tweaks->m_data.m_tweaks[i - 1], &tweaks->m_data.m_tweaks[i]);
		mk_lib_vc_mode_xor3(&in->m_data.m_tweaks[i].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[i].m_data.m_uint8s[0], &out->m_data.m_tweaks[i].m_data.m_uint8s[0]);
	}
	mk_lib_vc_alg_decrypt_block(algid, schedule_pri, out, out);
	for(i = 0; i != mk_lib_vc_msgs_per_block; ++i)
	{
		mk_lib_vc_mode_xor2(&out->m_data.m_tweaks[i].m_data.m_uint8s[0], &tweaks->m_data.m_tweaks[i].m_data.m_uint8s[0]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_seq_decrypt_block(mk_lib_vc_seqid_t const seqid, mk_lib_vc_seq_schedules_pct const schedules, mk_sl_cui_uint64_pct const block_id, mk_lib_vc_block_pct const in, mk_lib_vc_block_pt const out) mk_lang_noexcept
{
	mk_lib_vc_algid_t first_alg mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t first_sch_pri mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t first_sch_sec mk_lang_constexpr_init;
	mk_lib_vc_algid_t second_alg mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t second_sch_pri mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t second_sch_sec mk_lang_constexpr_init;
	mk_lib_vc_algid_t third_alg mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t third_sch_pri mk_lang_constexpr_init;
	mk_lib_vc_alg_schedule_t third_sch_sec mk_lang_constexpr_init;

	mk_lang_assert(seqid >= 0 && seqid < mk_lib_vc_seqid_e_dummy);
	mk_lang_assert(schedules);
	mk_lang_assert(block_id);
	mk_lang_assert(in);
	mk_lang_assert(out);

	switch(seqid)
	{
		case mk_lib_vc_seqid_e_aes:
			first_alg = mk_lib_vc_algid_e_aes;
			first_sch_pri.m_data.m_aes = &schedules->m_data.m_aes.m_pri;
			first_sch_sec.m_data.m_aes = &schedules->m_data.m_aes.m_sec;
			mk_lib_vc_xts_decrypt_block(first_alg, first_sch_pri, first_sch_sec, block_id, in, out);
		break;
		case mk_lib_vc_seqid_e_serpent:
			first_alg = mk_lib_vc_algid_e_serpent;
			first_sch_pri.m_data.m_serpent = &schedules->m_data.m_serpent.m_pri;
			first_sch_sec.m_data.m_serpent = &schedules->m_data.m_serpent.m_sec;
			mk_lib_vc_xts_decrypt_block(first_alg, first_sch_pri, first_sch_sec, block_id, in, out);
		break;
		case mk_lib_vc_seqid_e_twofish:
			first_alg = mk_lib_vc_algid_e_twofish;
			first_sch_pri.m_data.m_twofish = &schedules->m_data.m_twofish.m_pri;
			first_sch_sec.m_data.m_twofish = &schedules->m_data.m_twofish.m_sec;
			mk_lib_vc_xts_decrypt_block(first_alg, first_sch_pri, first_sch_sec, block_id, in, out);
		break;
		case mk_lib_vc_seqid_e_aes_twofish:
			first_alg = mk_lib_vc_algid_e_aes;
			first_sch_pri.m_data.m_aes = &schedules->m_data.m_aes_twofish.m_aes_pri;
			first_sch_sec.m_data.m_aes = &schedules->m_data.m_aes_twofish.m_aes_sec;
			second_alg = mk_lib_vc_algid_e_twofish;
			second_sch_pri.m_data.m_twofish = &schedules->m_data.m_aes_twofish.m_twofish_pri;
			second_sch_sec.m_data.m_twofish = &schedules->m_data.m_aes_twofish.m_twofish_sec;
			mk_lib_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_lib_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
		break;
		case mk_lib_vc_seqid_e_aes_twofish_serpent:
			first_alg = mk_lib_vc_algid_e_aes;
			first_sch_pri.m_data.m_aes = &schedules->m_data.m_aes_twofish_serpent.m_aes_pri;
			first_sch_sec.m_data.m_aes = &schedules->m_data.m_aes_twofish_serpent.m_aes_sec;
			second_alg = mk_lib_vc_algid_e_twofish;
			second_sch_pri.m_data.m_twofish = &schedules->m_data.m_aes_twofish_serpent.m_twofish_pri;
			second_sch_sec.m_data.m_twofish = &schedules->m_data.m_aes_twofish_serpent.m_twofish_sec;
			third_alg = mk_lib_vc_algid_e_serpent;
			third_sch_pri.m_data.m_serpent = &schedules->m_data.m_aes_twofish_serpent.m_serpent_pri;
			third_sch_sec.m_data.m_serpent = &schedules->m_data.m_aes_twofish_serpent.m_serpent_sec;
			mk_lib_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_lib_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
			mk_lib_vc_xts_decrypt_block(third_alg,  third_sch_pri,  third_sch_sec,  block_id, out, out);
		break;
		case mk_lib_vc_seqid_e_serpent_aes:
			first_alg = mk_lib_vc_algid_e_serpent;
			first_sch_pri.m_data.m_serpent = &schedules->m_data.m_serpent_aes.m_serpent_pri;
			first_sch_sec.m_data.m_serpent = &schedules->m_data.m_serpent_aes.m_serpent_sec;
			second_alg = mk_lib_vc_algid_e_aes;
			second_sch_pri.m_data.m_aes = &schedules->m_data.m_serpent_aes.m_aes_pri;
			second_sch_sec.m_data.m_aes = &schedules->m_data.m_serpent_aes.m_aes_sec;
			mk_lib_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_lib_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
		break;
		case mk_lib_vc_seqid_e_serpent_twofish_aes:
			first_alg = mk_lib_vc_algid_e_serpent;
			first_sch_pri.m_data.m_serpent = &schedules->m_data.m_serpent_twofish_aes.m_serpent_pri;
			first_sch_sec.m_data.m_serpent = &schedules->m_data.m_serpent_twofish_aes.m_serpent_sec;
			second_alg = mk_lib_vc_algid_e_twofish;
			second_sch_pri.m_data.m_twofish = &schedules->m_data.m_serpent_twofish_aes.m_twofish_pri;
			second_sch_sec.m_data.m_twofish = &schedules->m_data.m_serpent_twofish_aes.m_twofish_sec;
			third_alg = mk_lib_vc_algid_e_aes;
			third_sch_pri.m_data.m_aes = &schedules->m_data.m_serpent_twofish_aes.m_aes_pri;
			third_sch_sec.m_data.m_aes = &schedules->m_data.m_serpent_twofish_aes.m_aes_sec;
			mk_lib_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_lib_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
			mk_lib_vc_xts_decrypt_block(third_alg,  third_sch_pri,  third_sch_sec,  block_id, out, out);
		break;
		case mk_lib_vc_seqid_e_twofish_serpent:
			first_alg = mk_lib_vc_algid_e_twofish;
			first_sch_pri.m_data.m_twofish = &schedules->m_data.m_twofish_serpent.m_twofish_pri;
			first_sch_sec.m_data.m_twofish = &schedules->m_data.m_twofish_serpent.m_twofish_sec;
			second_alg = mk_lib_vc_algid_e_serpent;
			second_sch_pri.m_data.m_serpent = &schedules->m_data.m_twofish_serpent.m_serpent_pri;
			second_sch_sec.m_data.m_serpent = &schedules->m_data.m_twofish_serpent.m_serpent_sec;
			mk_lib_vc_xts_decrypt_block(first_alg,  first_sch_pri,  first_sch_sec,  block_id, in,  out);
			mk_lib_vc_xts_decrypt_block(second_alg, second_sch_pri, second_sch_sec, block_id, out, out);
		break;
		case mk_lib_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_seq_expand_dec(mk_lib_vc_seqid_t const seqid, mk_lib_vc_seq_keys_pct const keys, mk_lib_vc_seq_schedules_pt const schedules) mk_lang_noexcept
{
	mk_lang_assert(seqid >= 0 && seqid < mk_lib_vc_seqid_e_dummy);
	mk_lang_assert(keys);
	mk_lang_assert(schedules);

	switch(seqid)
	{
		case mk_lib_vc_seqid_e_aes:
			mk_lib_crypto_alg_aes_256_expand_dec(&keys->m_data.m_aes.m_pri, &schedules->m_data.m_aes.m_pri);
			mk_lib_crypto_alg_aes_256_expand_enc(&keys->m_data.m_aes.m_sec, &schedules->m_data.m_aes.m_sec);
		break;
		case mk_lib_vc_seqid_e_serpent:
			mk_lib_crypto_alg_serpent_expand_dec(&keys->m_data.m_serpent.m_pri, &schedules->m_data.m_serpent.m_pri);
			mk_lib_crypto_alg_serpent_expand_enc(&keys->m_data.m_serpent.m_sec, &schedules->m_data.m_serpent.m_sec);
		break;
		case mk_lib_vc_seqid_e_twofish:
			mk_lib_crypto_alg_twofish_256_expand_dec(&keys->m_data.m_twofish.m_pri, &schedules->m_data.m_twofish.m_pri);
			mk_lib_crypto_alg_twofish_256_expand_enc(&keys->m_data.m_twofish.m_sec, &schedules->m_data.m_twofish.m_sec);
		break;
		case mk_lib_vc_seqid_e_aes_twofish:
			mk_lib_crypto_alg_twofish_256_expand_dec(&keys->m_data.m_aes_twofish.m_twofish_pri, &schedules->m_data.m_aes_twofish.m_twofish_pri);
			mk_lib_crypto_alg_aes_256_expand_dec    (&keys->m_data.m_aes_twofish.m_aes_pri,     &schedules->m_data.m_aes_twofish.m_aes_pri    );
			mk_lib_crypto_alg_twofish_256_expand_enc(&keys->m_data.m_aes_twofish.m_twofish_sec, &schedules->m_data.m_aes_twofish.m_twofish_sec);
			mk_lib_crypto_alg_aes_256_expand_enc    (&keys->m_data.m_aes_twofish.m_aes_sec,     &schedules->m_data.m_aes_twofish.m_aes_sec    );
		break;
		case mk_lib_vc_seqid_e_aes_twofish_serpent:
			mk_lib_crypto_alg_serpent_expand_dec    (&keys->m_data.m_aes_twofish_serpent.m_serpent_pri, &schedules->m_data.m_aes_twofish_serpent.m_serpent_pri);
			mk_lib_crypto_alg_twofish_256_expand_dec(&keys->m_data.m_aes_twofish_serpent.m_twofish_pri, &schedules->m_data.m_aes_twofish_serpent.m_twofish_pri);
			mk_lib_crypto_alg_aes_256_expand_dec    (&keys->m_data.m_aes_twofish_serpent.m_aes_pri,     &schedules->m_data.m_aes_twofish_serpent.m_aes_pri    );
			mk_lib_crypto_alg_serpent_expand_enc    (&keys->m_data.m_aes_twofish_serpent.m_serpent_sec, &schedules->m_data.m_aes_twofish_serpent.m_serpent_sec);
			mk_lib_crypto_alg_twofish_256_expand_enc(&keys->m_data.m_aes_twofish_serpent.m_twofish_sec, &schedules->m_data.m_aes_twofish_serpent.m_twofish_sec);
			mk_lib_crypto_alg_aes_256_expand_enc    (&keys->m_data.m_aes_twofish_serpent.m_aes_sec,     &schedules->m_data.m_aes_twofish_serpent.m_aes_sec    );
		break;
		case mk_lib_vc_seqid_e_serpent_aes:
			mk_lib_crypto_alg_aes_256_expand_dec(&keys->m_data.m_serpent_aes.m_aes_pri,     &schedules->m_data.m_serpent_aes.m_aes_pri    );
			mk_lib_crypto_alg_serpent_expand_dec(&keys->m_data.m_serpent_aes.m_serpent_pri, &schedules->m_data.m_serpent_aes.m_serpent_pri);
			mk_lib_crypto_alg_aes_256_expand_enc(&keys->m_data.m_serpent_aes.m_aes_sec,     &schedules->m_data.m_serpent_aes.m_aes_sec    );
			mk_lib_crypto_alg_serpent_expand_enc(&keys->m_data.m_serpent_aes.m_serpent_sec, &schedules->m_data.m_serpent_aes.m_serpent_sec);
		break;
		case mk_lib_vc_seqid_e_serpent_twofish_aes:
			mk_lib_crypto_alg_aes_256_expand_dec    (&keys->m_data.m_serpent_twofish_aes.m_aes_pri,     &schedules->m_data.m_serpent_twofish_aes.m_aes_pri    );
			mk_lib_crypto_alg_twofish_256_expand_dec(&keys->m_data.m_serpent_twofish_aes.m_twofish_pri, &schedules->m_data.m_serpent_twofish_aes.m_twofish_pri);
			mk_lib_crypto_alg_serpent_expand_dec    (&keys->m_data.m_serpent_twofish_aes.m_serpent_pri, &schedules->m_data.m_serpent_twofish_aes.m_serpent_pri);
			mk_lib_crypto_alg_aes_256_expand_enc    (&keys->m_data.m_serpent_twofish_aes.m_aes_sec,     &schedules->m_data.m_serpent_twofish_aes.m_aes_sec    );
			mk_lib_crypto_alg_twofish_256_expand_enc(&keys->m_data.m_serpent_twofish_aes.m_twofish_sec, &schedules->m_data.m_serpent_twofish_aes.m_twofish_sec);
			mk_lib_crypto_alg_serpent_expand_enc    (&keys->m_data.m_serpent_twofish_aes.m_serpent_sec, &schedules->m_data.m_serpent_twofish_aes.m_serpent_sec);
		break;
		case mk_lib_vc_seqid_e_twofish_serpent:
			mk_lib_crypto_alg_serpent_expand_dec    (&keys->m_data.m_twofish_serpent.m_serpent_pri, &schedules->m_data.m_twofish_serpent.m_serpent_pri);
			mk_lib_crypto_alg_twofish_256_expand_dec(&keys->m_data.m_twofish_serpent.m_twofish_pri, &schedules->m_data.m_twofish_serpent.m_twofish_pri);
			mk_lib_crypto_alg_serpent_expand_enc    (&keys->m_data.m_twofish_serpent.m_serpent_sec, &schedules->m_data.m_twofish_serpent.m_serpent_sec);
			mk_lib_crypto_alg_twofish_256_expand_enc(&keys->m_data.m_twofish_serpent.m_twofish_sec, &schedules->m_data.m_twofish_serpent.m_twofish_sec);
		break;
		case mk_lib_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_keys_init(mk_lib_vc_seqid_t const seqid, mk_lib_vc_keys_material_pct const key_material, mk_lib_vc_seq_keys_pt const keys) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_keys_t, m_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_keys_t, m_sec) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_keys_t, m_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_keys_t, m_sec) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_keys_t, m_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_keys_t, m_sec) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_keys_t, m_twofish_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_keys_t, m_aes_pri    ) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_keys_t, m_twofish_sec) == 2 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_keys_t, m_aes_sec    ) == 3 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_serpent_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_twofish_pri) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_aes_pri    ) == 2 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_serpent_sec) == 3 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_twofish_sec) == 4 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_aes_twofish_serpent_keys_t, m_aes_sec    ) == 5 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_aes_keys_t, m_aes_pri    ) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_aes_keys_t, m_serpent_pri) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_aes_keys_t, m_aes_sec    ) == 2 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_aes_keys_t, m_serpent_sec) == 3 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_aes_pri    ) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_twofish_pri) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_serpent_pri) == 2 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_aes_sec    ) == 3 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_twofish_sec) == 4 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_serpent_twofish_aes_keys_t, m_serpent_sec) == 5 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_serpent_keys_t, m_serpent_pri) == 0 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_serpent_keys_t, m_twofish_pri) == 1 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_serpent_keys_t, m_serpent_sec) == 2 * 32);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_vc_seq_twofish_serpent_keys_t, m_twofish_sec) == 3 * 32);

	mk_lang_assert(seqid >= 0 && seqid < mk_lib_vc_seqid_e_dummy);
	mk_lang_assert(key_material);
	mk_lang_assert(keys);

	switch(seqid)
	{
		case mk_lib_vc_seqid_e_aes:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes.m_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[0 * mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes.m_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[1 * mk_lib_crypto_alg_aes_256_key_len_v], mk_lib_crypto_alg_aes_256_key_len_v);
		break;
		case mk_lib_vc_seqid_e_serpent:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent.m_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[0 * mk_lib_crypto_alg_serpent_key_len_v], mk_lib_crypto_alg_serpent_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent.m_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[1 * mk_lib_crypto_alg_serpent_key_len_v], mk_lib_crypto_alg_serpent_key_len_v);
		break;
		case mk_lib_vc_seqid_e_twofish:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish.m_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[0 * mk_lib_crypto_alg_twofish_256_key_len_v], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish.m_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[1 * mk_lib_crypto_alg_twofish_256_key_len_v], mk_lib_crypto_alg_twofish_256_key_len_v);
		break;
		case mk_lib_vc_seqid_e_aes_twofish:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish.m_twofish_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish.m_aes_pri    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish.m_twofish_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish.m_aes_sec    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
		break;
		case mk_lib_vc_seqid_e_aes_twofish_serpent:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_serpent_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (0 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_twofish_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_aes_pri    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_serpent_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (0 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_twofish_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_aes_twofish_serpent.m_aes_sec    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_aes_256_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
		break;
		case mk_lib_vc_seqid_e_serpent_aes:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_aes.m_aes_pri    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_aes.m_serpent_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_aes.m_aes_sec    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_aes.m_serpent_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v);
		break;
		case mk_lib_vc_seqid_e_serpent_twofish_aes:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_aes_pri    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_twofish_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_serpent_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_aes_sec    .m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (0 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_aes_256_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_twofish_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (0 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_serpent_twofish_aes.m_serpent_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_aes_256_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v + mk_lib_crypto_alg_serpent_key_len_v)) + (1 * mk_lib_crypto_alg_twofish_256_key_len_v) + (1 * mk_lib_crypto_alg_aes_256_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
		break;
		case mk_lib_vc_seqid_e_twofish_serpent:
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish_serpent.m_serpent_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (0 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish_serpent.m_twofish_pri.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(0 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish_serpent.m_serpent_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (0 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_serpent_key_len_v    );
			mk_lib_vc_memcpyu8_fn(&keys->m_data.m_twofish_serpent.m_twofish_sec.m_data.m_uint8s[0], &key_material->m_data.m_uint8s[(1 * (mk_lib_crypto_alg_serpent_key_len_v + mk_lib_crypto_alg_twofish_256_key_len_v)) + (1 * mk_lib_crypto_alg_serpent_key_len_v)], mk_lib_crypto_alg_twofish_256_key_len_v);
		break;
		case mk_lib_vc_seqid_e_dummy:
			mk_lang_assert(mk_lang_false);
		break;
		default:
			mk_lang_assert(mk_lang_false);
		break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_vc_derive_keys(mk_lib_vc_kdfid_t const kdfid, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_keys_material_pt const key_material) mk_lang_noexcept
{
	mk_lang_assert(kdfid >= 0 && kdfid < mk_lib_vc_kdfid_e_dummy);
	mk_lang_assert(password);
	mk_lang_assert(password_len >= 1);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_material);

	switch(kdfid)
	{
		case mk_lib_vc_kdfid_e_sha512:     mk_lib_crypto_kdf_pbkdf2_sha2_512    (password, password_len, salt, mk_lib_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_lib_vc_kdfid_e_whirlpool:  mk_lib_crypto_kdf_pbkdf2_whirlpool   (password, password_len, salt, mk_lib_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_lib_vc_kdfid_e_sha256:     mk_lib_crypto_kdf_pbkdf2_sha2_256    (password, password_len, salt, mk_lib_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_lib_vc_kdfid_e_blake2s256: mk_lib_crypto_kdf_pbkdf2_blake2s_256 (password, password_len, salt, mk_lib_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_lib_vc_kdfid_e_streebog:   mk_lib_crypto_kdf_pbkdf2_streebog_512(password, password_len, salt, mk_lib_vc_salt_len, cost, mk_lang_countof(key_material->m_data.m_uint8s), &key_material->m_data.m_uint8s[0]); break;
		case mk_lib_vc_kdfid_e_dummy: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_parse_cost(mk_lang_types_bool_t const wide, mk_lang_types_pchar_pct const str_pim, mk_lang_types_ulong_pt const cost) mk_lang_noexcept
{
	mk_lang_types_sint_t str_pim_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_sl_cui_uint32_t pim32[2] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t pim64 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64 mk_lang_constexpr_init;

	mk_lang_assert(str_pim);
	mk_lang_assert(cost);
	mk_lang_assert
	(
		(!wide && mk_lib_vc_strlenpc_fn(str_pim) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))) ||
		(wide && mk_lib_vc_strlenwc_fn(((mk_lang_types_wchar_pct)(str_pim))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))
	);

	str_pim_len = wide ? ((mk_lang_types_sint_t)(mk_lib_vc_strlenwc_fn(((mk_lang_types_wchar_pct)(str_pim))))) : ((mk_lang_types_sint_t)(mk_lib_vc_strlenpc_fn(str_pim)));
	err = wide ? mk_sl_cui_uint32_from_str_dec_w(&pim32[0], ((mk_lang_types_wchar_pct)(str_pim)), str_pim_len) : mk_sl_cui_uint32_from_str_dec_n(&pim32[0], str_pim, str_pim_len);
	mk_lang_check_return(err == str_pim_len);
	if(mk_sl_cui_uint32_is_zero(&pim32[0]))
	{
		*cost = 500ul * 1000ul;
	}
	else
	{
		mk_sl_cui_uint32_set_zero(&pim32[1]);
		mk_sl_uint_64_from_32_le(&pim64, &pim32[0]);
		tsi = 1 * 1000;
		mk_sl_cui_uint64_from_bi_sint(&tu64, &tsi);
		mk_sl_cui_uint64_mul2_wrap_lo(&pim64, &tu64);
		tsi = 15 * 1000;
		mk_sl_cui_uint64_from_bi_sint(&tu64, &tsi);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&pim64, &tu64);
		mk_sl_uint_64_to_32_le(&pim64, &pim32[0]);
		mk_lang_check_return(mk_sl_cui_uint32_is_zero(&pim32[1]));
		mk_sl_cui_uint32_to_bi_ulong(&pim32[0], cost);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header_seq(mk_lib_vc_seqid_t const seqid, mk_lib_vc_keys_material_pct const key_material, mk_lib_vc_block_pct const block, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_lib_vc_block_pt decrypted mk_lang_constexpr_init;
	mk_lib_vc_block_oversized_t decrypted_oversized mk_lang_constexpr_init;
	mk_sl_cui_uint64_t block_idx mk_lang_constexpr_init;
	mk_lib_vc_seq_keys_t keys mk_lang_constexpr_init;
	mk_lang_types_pchar_t tpc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_ushort_t tus mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32b mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64b mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lib_vc_keys_material_t master_keys_material mk_lang_constexpr_init;
	mk_lib_vc_seq_keys_t master_keys mk_lang_constexpr_init;

	mk_lang_assert(seqid >= 0 && seqid < mk_lib_vc_seqid_e_dummy);
	mk_lang_assert(key_material);
	mk_lang_assert(block);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	decrypted = ((mk_lib_vc_block_pt)(mk_lang_roundup_align_ptr(&decrypted_oversized, sizeof(*decrypted))));
	mk_sl_cui_uint64_set_zero(&block_idx);
	mk_lib_vc_keys_init(seqid, key_material, &keys);
	mk_lib_vc_seq_expand_dec(seqid, &keys, schedules);
	mk_lib_vc_seq_decrypt_block(seqid, schedules, &block_idx, block, decrypted);
	tpc = 'V'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_magic + 0], &tu8)){ return 1; }
	tpc = 'E'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_magic + 1], &tu8)){ return 1; }
	tpc = 'R'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_magic + 2], &tu8)){ return 1; }
	tpc = 'A'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); if(mk_sl_cui_uint8_ne(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_magic + 3], &tu8)){ return 1; }
	mk_sl_uint_16_from_8_be(&tu16, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_volume_header_format_version]); mk_sl_cui_uint16_to_bi_ushort(&tu16, &tus); mk_lang_check_return(tus == 5);
	mk_sl_uint_16_from_8_be(&tu16, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_minimum_program_version]); mk_sl_cui_uint16_to_bi_ushort(&tu16, &tus); mk_lang_check_return(tus == 0x10b);
	mk_lib_hash_crc32_fn(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_keys], mk_lib_vc_lens_keys, &tu32a);
	mk_sl_uint_32_from_8_be(&tu32b, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_crc_a]); mk_lang_check_return(mk_sl_cui_uint32_eq(&tu32a, &tu32b));
	n = mk_lib_vc_lens_reserved_a; for(i = 0; i != n; ++i){ mk_lang_check_return(mk_sl_cui_uint8_is_zero(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_reserved_a + i])); }
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_hidden_volume_size]); mk_lang_check_return(mk_sl_cui_uint64_is_zero(&tu64a)); /* todo hidden volumes not supported */
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_normal_volume_size]); mk_sl_cui_uint64_shl2(&tu64a, 64 - 9); mk_lang_check_return(mk_sl_cui_uint64_is_zero(&tu64a));
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_master_key_scope_start]); tul = mk_lib_vc_offsets_volume; mk_sl_cui_uint64_from_bi_ulong(&tu64b, &tul); mk_lang_check_return(mk_sl_cui_uint64_eq(&tu64a, &tu64b));
	mk_sl_uint_64_from_8_be(&tu64a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_master_key_scope_len]); mk_sl_uint_64_from_8_be(&tu64b, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_normal_volume_size]); mk_lang_check_return(mk_sl_cui_uint64_eq(&tu64a, &tu64b)); *volume_len = tu64a;
	mk_sl_uint_32_from_8_be(&tu32a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_flags]); mk_lang_check_return(mk_sl_cui_uint32_is_zero(&tu32a)); /* todo only non-system encryption supported */
	mk_sl_uint_32_from_8_be(&tu32a, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_block_len]); mk_sl_cui_uint32_to_bi_ulong(&tu32a, &tul); mk_lang_check_return(tul == mk_lib_vc_block_len); /* todo other block lens not supported */
	n = mk_lib_vc_lens_reserved_b; for(i = 0; i != n; ++i){ mk_lang_check_return(mk_sl_cui_uint8_is_zero(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_reserved_b + i])); }
	mk_lib_hash_crc32_fn(&decrypted->m_data.m_uint8s[mk_lib_vc_offsets_magic], mk_lib_vc_offsets_crc_b - mk_lib_vc_offsets_magic, &tu32a);
	mk_sl_uint_32_from_8_be(&tu32b, &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_crc_b]); mk_lang_check_return(mk_sl_cui_uint32_eq(&tu32a, &tu32b));
	mk_lib_vc_memcpyu8_fn(&master_keys_material.m_data.m_uint8s[0], &decrypted->m_data.m_uint8s[mk_lib_vc_offsets_keys], mk_lang_countof(master_keys_material.m_data.m_uint8s));
	mk_lib_vc_keys_init(seqid, &master_keys_material, &master_keys);
	mk_lib_vc_seq_expand_dec(seqid, &master_keys, schedules);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header_kdf(mk_lib_vc_kdfid_t const kdfid, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lib_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_block_pct const block, mk_lib_vc_seqid_pt const seqid_out, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_lib_vc_keys_material_t key_material mk_lang_constexpr_init;
	mk_lib_vc_seqid_t seqid mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(kdfid >= 0 && kdfid < mk_lib_vc_kdfid_e_dummy);
	mk_lang_assert(password);
	mk_lang_assert(password_len >= 1 && password_len <= 4 * 1024);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(block);
	mk_lang_assert(seqid_out);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	mk_lib_vc_derive_keys(kdfid, password, password_len, &salt->m_data.m_uint8s[0], cost, &key_material);
	for(seqid = ((mk_lib_vc_seqid_t)(0)); seqid != mk_lib_vc_seqid_e_dummy; seqid = ((mk_lib_vc_seqid_t)(((mk_lang_types_sint_t)(seqid)) + 1)))
	{
		err = mk_lib_vc_try_decrypt_header_seq(seqid, &key_material, block, schedules, volume_len);
		if(err == 0)
		{
			*seqid_out = seqid;
			break;
		}
	}
	mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_try_decrypt_header(mk_lib_vc_kdfid_t const kdf_hint, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lib_vc_salt_pct const salt, mk_lang_types_ulong_t const cost, mk_lib_vc_block_pct const block, mk_lib_vc_seqid_pt const seqid_out, mk_lib_vc_seq_schedules_pt const schedules, mk_sl_cui_uint64_pt const volume_len) mk_lang_noexcept
{
	mk_lib_vc_kdfid_t kdfid mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(kdf_hint >= 0 && kdf_hint <= mk_lib_vc_kdfid_e_dummy);
	mk_lang_assert(password);
	mk_lang_assert(password_len >= 1 && password_len <= 4 * 1024);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(block);
	mk_lang_assert(seqid_out);
	mk_lang_assert(schedules);
	mk_lang_assert(volume_len);

	if(kdf_hint == mk_lib_vc_kdfid_e_dummy)
	{
		for(kdfid = ((mk_lib_vc_kdfid_t)(0)); kdfid != mk_lib_vc_kdfid_e_dummy; kdfid = ((mk_lib_vc_kdfid_t)(((mk_lang_types_sint_t)(kdfid)) + 1)))
		{
			err = mk_lib_vc_try_decrypt_header_kdf(kdfid, password, password_len, salt, cost, block, seqid_out, schedules, volume_len);
			if(err == 0)
			{
				break;
			}
		}
	}
	else
	{
		err = mk_lib_vc_try_decrypt_header_kdf(kdf_hint, password, password_len, salt, cost, block, seqid_out, schedules, volume_len); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err);
	return 0;
}
