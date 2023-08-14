#include "mk_lib_crypto_alg_serpent.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_alg_serpent
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_alg_serpent_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"

#define mk_lang_memmove_obj_tn mk_lib_crypto_alg_serpent_u8
#define mk_lang_memmove_obj_t mk_sl_cui_uint8_t
#include "mk_lang_memmove_obj_inl_fileh.h"
#include "mk_lang_memmove_obj_inl_filec.h"

#define mk_lang_memcpy_obj_tn mk_lib_crypto_alg_serpent_u8
#define mk_lang_memcpy_obj_t mk_sl_cui_uint8_t
#include "mk_lang_memcpy_obj_inl_fileh.h"
#include "mk_lang_memcpy_obj_inl_filec.h"


#define mk_lib_crypto_alg_serpent_word_bits 32
#define mk_lib_crypto_alg_serpent_word_bytes (32 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_msg_words (mk_lib_crypto_alg_serpent_msg_len_m / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_key_words (mk_lib_crypto_alg_serpent_key_len_m / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_sbox_count 8


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_load(mk_lib_crypto_alg_serpent_msg_pct const msg, mk_sl_cui_uint32_pt const ta, mk_sl_cui_uint32_pt const tb, mk_sl_cui_uint32_pt const tc, mk_sl_cui_uint32_pt const td) mk_lang_noexcept
{
	mk_lang_assert(msg);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);

	mk_sl_uint_32_from_8_le(ta, &msg->m_data.m_uint8s[ 0]);
	mk_sl_uint_32_from_8_le(tb, &msg->m_data.m_uint8s[ 4]);
	mk_sl_uint_32_from_8_le(tc, &msg->m_data.m_uint8s[ 8]);
	mk_sl_uint_32_from_8_le(td, &msg->m_data.m_uint8s[12]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_store(mk_lib_crypto_alg_serpent_msg_pt const msg, mk_sl_cui_uint32_pct const ta, mk_sl_cui_uint32_pct const tb, mk_sl_cui_uint32_pct const tc, mk_sl_cui_uint32_pct const td) mk_lang_noexcept
{
	mk_lang_assert(msg);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);

	mk_sl_uint_32_to_8_le(ta, &msg->m_data.m_uint8s[ 0]);
	mk_sl_uint_32_to_8_le(tb, &msg->m_data.m_uint8s[ 4]);
	mk_sl_uint_32_to_8_le(tc, &msg->m_data.m_uint8s[ 8]);
	mk_sl_uint_32_to_8_le(td, &msg->m_data.m_uint8s[12]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_0(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&td, &ta); te = tb;
	mk_sl_cui_uint32_and2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&tc, &te); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_or2(&te, &tb);  mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_or2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &te, &tc, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_1(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_not1(&tc);
	te = ta;                         mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_or2(&tc, &ta);
	mk_sl_cui_uint32_and2(&tc, &te); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_and2(&ta, &tc);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_store(msg, &tc, &ta, &td, &tb);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_2(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = ta;                         mk_sl_cui_uint32_and2(&ta, &tc);
	mk_sl_cui_uint32_xor2(&ta, &td); mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_xor2(&te, &tc);
	tb = td;                         mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_not1(&te);
	mk_lib_crypto_alg_serpent_store(msg, &tc, &td, &tb, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_3(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = ta;                         mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_and2(&tb, &te);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_xor2(&tc, &td);
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&td, &te); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&te, &ta); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_or2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&ta, &td);
	tc = tb;                         mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &tc, &td, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_4(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	te = tb;                         mk_sl_cui_uint32_and2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_and2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &te, &ta, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_5(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&ta, &tb); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_not1(&td);      te = tb;
	mk_sl_cui_uint32_and2(&tb, &ta); mk_sl_cui_uint32_xor2(&tc, &td);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&te, &td); mk_sl_cui_uint32_and2(&td, &tb);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_and2(&ta, &td); mk_sl_cui_uint32_not1(&tc);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_or2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &td, &ta, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_6(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tc);      te = td;
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_or2(&ta, &tb);  mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_and2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_store(msg, &ta, &tb, &te, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc_7(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = tb;                         mk_sl_cui_uint32_or2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_or2(&tb, &te);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_or2(&ta, &te);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_and2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_not1(&tc);
	mk_sl_cui_uint32_or2(&tc, &ta);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_store(msg, &te, &td, &tb, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_enc(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msg);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_substitute_enc_0(msg); break;
		case 1: mk_lib_crypto_alg_serpent_substitute_enc_1(msg); break;
		case 2: mk_lib_crypto_alg_serpent_substitute_enc_2(msg); break;
		case 3: mk_lib_crypto_alg_serpent_substitute_enc_3(msg); break;
		case 4: mk_lib_crypto_alg_serpent_substitute_enc_4(msg); break;
		case 5: mk_lib_crypto_alg_serpent_substitute_enc_5(msg); break;
		case 6: mk_lib_crypto_alg_serpent_substitute_enc_6(msg); break;
		case 7: mk_lib_crypto_alg_serpent_substitute_enc_7(msg); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_0(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tc);      te = tb;
	mk_sl_cui_uint32_or2(&tb, &ta);  mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_and2(&ta, &td);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_store(msg, &ta, &te, &tb, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_1(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = tb;                         mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_and2(&td, &tb); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_or2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&ta, &tb); mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_or2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_or2(&tb, &te);
	mk_sl_cui_uint32_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_store(msg, &te, &ta, &td, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_2(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	te = td;                         mk_sl_cui_uint32_and2(&td, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_or2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_and2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_and2(&te, &ta);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_and2(&tc, &tb);
	mk_sl_cui_uint32_or2(&tc, &ta);  mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_and2(&ta, &tb); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &ta);
mk_lib_crypto_alg_serpent_store(msg, &tb, &te, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_3(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_and2(&te, &tc);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_and2(&td, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_or2(&tb, &tc);  mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_store(msg, &tc, &tb, &td, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_4(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_and2(&tb, &ta); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_and2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_or2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_store(msg, &ta, &td, &tc, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_5(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tb);      te = td;
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &tb);
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te); mk_sl_cui_uint32_or2(&te, &ta);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_and2(&td, &te); mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&td, &te); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &te, &td, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_6(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); te = tc;
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_not1(&tc);      mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_or2(&te, &ta);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta);
	mk_lib_crypto_alg_serpent_store(msg, &tb, &tc, &te, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec_7(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_and2(&ta, &td); mk_sl_cui_uint32_or2(&te, &td);
	mk_sl_cui_uint32_not1(&tc);      mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_or2(&tb, &ta);  mk_sl_cui_uint32_xor2(&ta, &tc);
	mk_sl_cui_uint32_and2(&tc, &te); mk_sl_cui_uint32_and2(&td, &te);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&ta, &td); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_or2(&te, &ta);  mk_sl_cui_uint32_xor2(&td, &tc);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_store(msg, &td, &ta, &tb, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_substitute_dec(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msg);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_substitute_dec_0(msg); break;
		case 1: mk_lib_crypto_alg_serpent_substitute_dec_1(msg); break;
		case 2: mk_lib_crypto_alg_serpent_substitute_dec_2(msg); break;
		case 3: mk_lib_crypto_alg_serpent_substitute_dec_3(msg); break;
		case 4: mk_lib_crypto_alg_serpent_substitute_dec_4(msg); break;
		case 5: mk_lib_crypto_alg_serpent_substitute_dec_5(msg); break;
		case 6: mk_lib_crypto_alg_serpent_substitute_dec_6(msg); break;
		case 7: mk_lib_crypto_alg_serpent_substitute_dec_7(msg); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_lt_enc(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_rotl2(&ta, 13);
	mk_sl_cui_uint32_rotl2(&tc, 3);
	mk_sl_cui_uint32_xor3(&ta, &tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_shl3(&ta, 3, &te);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_rotl2(&tb, 1);
	mk_sl_cui_uint32_rotl2(&td, 7);
	mk_sl_cui_uint32_xor3(&tb, &td, &te);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_shl3(&tb, 7, &te);
	mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_rotl2(&ta, 5);
	mk_sl_cui_uint32_rotl2(&tc, 22);
	mk_lib_crypto_alg_serpent_store(msg, &ta, &tb, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_lt_dec(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_rotr2(&tc, 22);
	mk_sl_cui_uint32_rotr2(&ta, 5);
	mk_sl_cui_uint32_shl3(&tb, 7, &te);
	mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_xor3(&tb, &td, &te);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_rotr2(&td, 7);
	mk_sl_cui_uint32_rotr2(&tb, 1);
	mk_sl_cui_uint32_shl3(&ta, 3, &te);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor3(&ta, &tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_rotr2(&tc, 3);
	mk_sl_cui_uint32_rotr2(&ta, 13);
	mk_lib_crypto_alg_serpent_store(msg, &ta, &tb, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_round_middle_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msg);

	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[rnd_idx].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_substitute_enc(rnd_idx % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_alg_serpent_lt_enc(msg);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_round_last_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msg);

	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 1].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_substitute_enc((mk_lib_crypto_alg_serpent_nr - 1) % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0].m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_round_first_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msg);

	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0].m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_round_middle_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_substitute_dec(((mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx) % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[((mk_lib_crypto_alg_serpent_nr - 1)) - rnd_idx].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_lt_dec(msg);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_round_last_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_substitute_dec(0 % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_mode_base_mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[0].m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_expand_w(mk_lib_crypto_alg_serpent_key_pct const k, int const idx, mk_sl_cui_uint32_pt const w) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint32_t const s_phi = mk_sl_cui_uint32_c(0x9e3779b9ul);

	mk_sl_cui_uint32_t ti mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;

	mk_lang_assert(k);
	mk_lang_assert(idx >= 0 && idx < (mk_lib_crypto_alg_serpent_nr + 1) * mk_lib_crypto_alg_serpent_msg_words);
	mk_lang_assert(w);

	mk_sl_cui_uint32_from_bi_sint(&ti, &idx);
	mk_sl_uint_32_from_8_le(&ta, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 8) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&tb, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 5) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&tc, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 3) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&td, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 1) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &s_phi);
	mk_sl_cui_uint32_xor2(&tc, &ti);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc);
	mk_sl_cui_uint32_rotl3(&ta, 11, w);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_expand(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_key_t k mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t w mk_lang_constexpr_init;
	int sbox_idx mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	k = *key;
	for(i = 0; i != mk_lib_crypto_alg_serpent_nr + 1; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_serpent_msg_words; ++j)
		{
			mk_lib_crypto_alg_serpent_expand_w(&k, i * mk_lib_crypto_alg_serpent_msg_words + j, &w);
			mk_lang_memmove_obj_mk_lib_crypto_alg_serpent_u8(&k.m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_word_bytes], mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_word_bytes);
			mk_sl_uint_32_to_8_le(&w, &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_word_bytes]);
		}
		mk_lang_memcpy_obj_mk_lib_crypto_alg_serpent_u8(&schedule->m_data.m_msgs[i].m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_msg_len_m], mk_lib_crypto_alg_serpent_msg_len_m);
		sbox_idx = (((mk_lib_crypto_alg_serpent_nr * mk_lib_crypto_alg_serpent_sbox_count) + 3) - i) % mk_lib_crypto_alg_serpent_sbox_count;
		mk_lib_crypto_alg_serpent_substitute_enc(sbox_idx, &schedule->m_data.m_msgs[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_schedule_encrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	*output = *input;
	for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
	{
		mk_lib_crypto_alg_serpent_round_middle_enc(schedule, i, output);
	}
	mk_lib_crypto_alg_serpent_round_last_enc(schedule, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_schedule_decrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	*output = *input;
	mk_lib_crypto_alg_serpent_round_first_dec(schedule, output);
	for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
	{
		mk_lib_crypto_alg_serpent_round_middle_dec(schedule, i, output);
	}
	mk_lib_crypto_alg_serpent_round_last_dec(schedule, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_expand_enc(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_expand_dec(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_encrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_enc(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_decrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_dec(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, input, output);
}
