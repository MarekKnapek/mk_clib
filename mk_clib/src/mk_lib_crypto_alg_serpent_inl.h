#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_limits.h"
#include "mk_lang_pow2.h"
#include "mk_lang_restrict.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint_strict.h"


#if(!( \
	(defined mk_lib_crypto_alg_serpent_inl_t_name) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_type) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_bits && (mk_lib_crypto_alg_serpent_inl_t_bits) >= 32 && (mk_lib_crypto_alg_serpent_inl_t_bits) <= 512 && (mk_lib_crypto_alg_serpent_inl_t_bits) % 32 == 0 && mk_lang_pow2_is((mk_lib_crypto_alg_serpent_inl_t_bits) / 32)) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_constexpr && ((mk_lib_crypto_alg_serpent_inl_t_constexpr) == 0 || (mk_lib_crypto_alg_serpent_inl_t_constexpr) == 1)) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_uints_t) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_assign) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_and2) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_not1) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_or2) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_rotl2) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_rotr2) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_shl3) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_xor2) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_xor3) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_ui_broadcast) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_load) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_store) && \
	(defined mk_lib_crypto_alg_serpent_inl_t_target) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lib_crypto_alg_serpent_inl_name         mk_lib_crypto_alg_serpent_inl_t_name
#define mk_lib_crypto_alg_serpent_inl_type         mk_lib_crypto_alg_serpent_inl_t_type
#define mk_lib_crypto_alg_serpent_inl_bits         (mk_lib_crypto_alg_serpent_inl_t_bits)
#define mk_lib_crypto_alg_serpent_inl_constexpr    (mk_lib_crypto_alg_serpent_inl_t_constexpr)
#define mk_lib_crypto_alg_serpent_inl_uints_t      mk_lib_crypto_alg_serpent_inl_t_uints_t
#define mk_lib_crypto_alg_serpent_inl_ui_assign    mk_lib_crypto_alg_serpent_inl_t_ui_assign
#define mk_lib_crypto_alg_serpent_inl_ui_and2      mk_lib_crypto_alg_serpent_inl_t_ui_and2
#define mk_lib_crypto_alg_serpent_inl_ui_not1      mk_lib_crypto_alg_serpent_inl_t_ui_not1
#define mk_lib_crypto_alg_serpent_inl_ui_or2       mk_lib_crypto_alg_serpent_inl_t_ui_or2
#define mk_lib_crypto_alg_serpent_inl_ui_rotl2     mk_lib_crypto_alg_serpent_inl_t_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_ui_rotr2     mk_lib_crypto_alg_serpent_inl_t_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_ui_shl3      mk_lib_crypto_alg_serpent_inl_t_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_ui_xor2      mk_lib_crypto_alg_serpent_inl_t_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_ui_xor3      mk_lib_crypto_alg_serpent_inl_t_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_ui_broadcast mk_lib_crypto_alg_serpent_inl_t_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_load         mk_lib_crypto_alg_serpent_inl_t_load
#define mk_lib_crypto_alg_serpent_inl_store        mk_lib_crypto_alg_serpent_inl_t_store
#define mk_lib_crypto_alg_serpent_inl_target       mk_lib_crypto_alg_serpent_inl_t_target


#if mk_lib_crypto_alg_serpent_inl_constexpr
#define mk_lib_crypto_alg_serpent_inl_constexpr_spec mk_lang_constexpr
#define mk_lib_crypto_alg_serpent_inl_constexpr_init mk_lang_constexpr_init
#else
#define mk_lib_crypto_alg_serpent_inl_constexpr_spec
#define mk_lib_crypto_alg_serpent_inl_constexpr_init
#endif


#define mk_lib_crypto_alg_serpent_inl_type_t mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_t)
#define mk_lib_crypto_alg_serpent_inl_type_ct mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_ct)
#define mk_lib_crypto_alg_serpent_inl_type_pt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_pt)
#define mk_lib_crypto_alg_serpent_inl_type_prt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_prt)
#define mk_lib_crypto_alg_serpent_inl_type_pct mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_pct)
#define mk_lib_crypto_alg_serpent_inl_type_prct mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _type_prct)

#define mk_lib_crypto_alg_serpent_inl_cnt (mk_lib_crypto_alg_serpent_inl_bits / 32)
#define mk_lib_crypto_alg_serpent_inl_schedule_encrypt_blocks mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _schedule_encrypt_blocks)
#define mk_lib_crypto_alg_serpent_inl_schedule_decrypt_blocks mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _schedule_decrypt_blocks)
#define mk_lib_crypto_alg_serpent_inl_schedule_encrypt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _schedule_encrypt)
#define mk_lib_crypto_alg_serpent_inl_schedule_decrypt mk_lang_concat(mk_lib_crypto_alg_serpent_inl_name, _schedule_decrypt)


typedef mk_lib_crypto_alg_serpent_inl_type mk_lib_crypto_alg_serpent_inl_type_t;
typedef mk_lib_crypto_alg_serpent_inl_type_t const mk_lib_crypto_alg_serpent_inl_type_ct;
typedef mk_lib_crypto_alg_serpent_inl_type_t* mk_lib_crypto_alg_serpent_inl_type_pt;
typedef mk_lib_crypto_alg_serpent_inl_type_t* mk_lang_restrict mk_lib_crypto_alg_serpent_inl_type_prt;
typedef mk_lib_crypto_alg_serpent_inl_type_t const* mk_lib_crypto_alg_serpent_inl_type_pct;
typedef mk_lib_crypto_alg_serpent_inl_type_t const* mk_lang_restrict mk_lib_crypto_alg_serpent_inl_type_prct;


#define mk_lib_crypto_alg_serpent_inl_xor_rk(ta, tb, tc, td, schedule) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lib_crypto_alg_serpent_msg_pct sch mk_lib_crypto_alg_serpent_inl_constexpr_init;      \
	mk_lib_crypto_alg_serpent_inl_uints_t schs mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lib_crypto_alg_serpent_inl_type_t schb mk_lib_crypto_alg_serpent_inl_constexpr_init;  \
	mk_lang_assert(ta);                                                                      \
	mk_lang_assert(tb);                                                                      \
	mk_lang_assert(tc);                                                                      \
	mk_lang_assert(td);                                                                      \
	mk_lang_assert(ta != tb);                                                                \
	mk_lang_assert(ta != tc);                                                                \
	mk_lang_assert(ta != td);                                                                \
	mk_lang_assert(tb != tc);                                                                \
	mk_lang_assert(tb != td);                                                                \
	mk_lang_assert(tc != td);                                                                \
	sch = schedule;                                                                          \
	mk_sl_uint_strict_32_from_8_le(&schs.m_data.m_uint32s[0], &sch->m_data.m_uint8s[0 * 4]); \
	mk_lib_crypto_alg_serpent_inl_ui_broadcast(&schb, &schs);                                \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(ta, &schb);                                        \
	mk_sl_uint_strict_32_from_8_le(&schs.m_data.m_uint32s[0], &sch->m_data.m_uint8s[1 * 4]); \
	mk_lib_crypto_alg_serpent_inl_ui_broadcast(&schb, &schs);                                \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(tb, &schb);                                        \
	mk_sl_uint_strict_32_from_8_le(&schs.m_data.m_uint32s[0], &sch->m_data.m_uint8s[2 * 4]); \
	mk_lib_crypto_alg_serpent_inl_ui_broadcast(&schb, &schs);                                \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(tc, &schb);                                        \
	mk_sl_uint_strict_32_from_8_le(&schs.m_data.m_uint32s[0], &sch->m_data.m_uint8s[3 * 4]); \
	mk_lib_crypto_alg_serpent_inl_ui_broadcast(&schb, &schs);                                \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(td, &schb);                                        \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_swaparoo(da, db, dc, dd, de, sa, sb, sc, sd, se) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lib_crypto_alg_serpent_inl_type_pt ta mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lib_crypto_alg_serpent_inl_type_pt tb mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lib_crypto_alg_serpent_inl_type_pt tc mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lib_crypto_alg_serpent_inl_type_pt td mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lib_crypto_alg_serpent_inl_type_pt te mk_lib_crypto_alg_serpent_inl_constexpr_init; \
	mk_lang_assert(sa);                                                                    \
	mk_lang_assert(sb);                                                                    \
	mk_lang_assert(sc);                                                                    \
	mk_lang_assert(sd);                                                                    \
	mk_lang_assert(se);                                                                    \
	mk_lang_assert(sa != sb);                                                              \
	mk_lang_assert(sa != sc);                                                              \
	mk_lang_assert(sa != sd);                                                              \
	mk_lang_assert(sa != se);                                                              \
	mk_lang_assert(sb != sc);                                                              \
	mk_lang_assert(sb != sd);                                                              \
	mk_lang_assert(sb != se);                                                              \
	mk_lang_assert(sc != sd);                                                              \
	mk_lang_assert(sc != se);                                                              \
	mk_lang_assert(sd != se);                                                              \
	mk_lang_assert(da);                                                                    \
	mk_lang_assert(db);                                                                    \
	mk_lang_assert(dc);                                                                    \
	mk_lang_assert(dd);                                                                    \
	mk_lang_assert(de);                                                                    \
	mk_lang_assert(da != db);                                                              \
	mk_lang_assert(da != dc);                                                              \
	mk_lang_assert(da != dd);                                                              \
	mk_lang_assert(da != de);                                                              \
	mk_lang_assert(db != dc);                                                              \
	mk_lang_assert(db != dd);                                                              \
	mk_lang_assert(db != de);                                                              \
	mk_lang_assert(dc != dd);                                                              \
	mk_lang_assert(dc != de);                                                              \
	mk_lang_assert(dd != de);                                                              \
	ta = *sa;                                                                              \
	tb = *sb;                                                                              \
	tc = *sc;                                                                              \
	td = *sd;                                                                              \
	te = *se;                                                                              \
	*da = ta;                                                                              \
	*db = tb;                                                                              \
	*dc = tc;                                                                              \
	*dd = td;                                                                              \
	*de = te;                                                                              \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_lt(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                 \
	mk_lang_assert(tb);                                 \
	mk_lang_assert(tc);                                 \
	mk_lang_assert(td);                                 \
	mk_lang_assert(te);                                 \
	mk_lang_assert(ta != tb);                           \
	mk_lang_assert(ta != tc);                           \
	mk_lang_assert(ta != td);                           \
	mk_lang_assert(ta != te);                           \
	mk_lang_assert(tb != tc);                           \
	mk_lang_assert(tb != td);                           \
	mk_lang_assert(tb != te);                           \
	mk_lang_assert(tc != td);                           \
	mk_lang_assert(tc != te);                           \
	mk_lang_assert(td != te);                           \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(ta, 13);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(tc, 3);      \
	mk_lib_crypto_alg_serpent_inl_ui_xor3 (ta, tc, te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (tb, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_shl3 (ta, 3, te);  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (te, tc);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (td, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(tb, 1);      \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(td, 7);      \
	mk_lib_crypto_alg_serpent_inl_ui_xor3 (tb, td, te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (ta, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_shl3 (tb, 7, te);  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (te, td);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (tc, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(ta, 5);      \
	mk_lib_crypto_alg_serpent_inl_ui_rotl2(tc, 22);     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_0(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2   (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *te); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *te); mk_lib_crypto_alg_serpent_inl_ui_not1  (*te    );  \
	mk_lib_crypto_alg_serpent_inl_ui_or2 (*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *te); mk_lib_crypto_alg_serpent_inl_ui_or2   (*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, te, tc, ta, td);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_1(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_ui_not1(*tc     ); \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *te); mk_lib_crypto_alg_serpent_inl_ui_or2 (*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tc, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*tc, *te); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*tb, *tc);                                                  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *te);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tc, ta, td, tb, te);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_2(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_or2 (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_ui_not1(*te     ); \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tc, td, tb, te, ta);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_3(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *te); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *ta);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, tc, td, te, ta);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_4(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_not1(*td     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *te); mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, te, ta, td, tc);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_5(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_not1(*td);      mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *td); mk_lib_crypto_alg_serpent_inl_ui_and2  (*td, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *td); mk_lib_crypto_alg_serpent_inl_ui_not1  (*tc     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *te); mk_lib_crypto_alg_serpent_inl_ui_or2   (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *te);                                                    \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, td, ta, tc, te);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_6(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2   (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_not1  (*td     ); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *te);                                                    \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *td);                                                    \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, ta, tb, te, tc, td);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_enc_7(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_ui_not1(*tc     ); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *ta);                                                  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, te, td, tb, ta, tc);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_dec_lt(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                 \
	mk_lang_assert(tb);                                 \
	mk_lang_assert(tc);                                 \
	mk_lang_assert(td);                                 \
	mk_lang_assert(te);                                 \
	mk_lang_assert(ta != tb);                           \
	mk_lang_assert(ta != tc);                           \
	mk_lang_assert(ta != td);                           \
	mk_lang_assert(ta != te);                           \
	mk_lang_assert(tb != tc);                           \
	mk_lang_assert(tb != td);                           \
	mk_lang_assert(tb != te);                           \
	mk_lang_assert(tc != td);                           \
	mk_lang_assert(tc != te);                           \
	mk_lang_assert(td != te);                           \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(tc, 22);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(ta, 5);      \
	mk_lib_crypto_alg_serpent_inl_ui_shl3 (tb, 7, te);  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (te, td);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (tc, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor3 (tb, td, te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (ta, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(td, 7);      \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(tb, 1);      \
	mk_lib_crypto_alg_serpent_inl_ui_shl3 (ta, 3, te);  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (te, tc);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (td, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_xor3 (ta, tc, te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2 (tb, te);     \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(tc, 3);      \
	mk_lib_crypto_alg_serpent_inl_ui_rotr2(ta, 13);     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_0(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_not1  (*te     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2  (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2   (*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tb);                                                    \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *td);                                                    \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc);                                                    \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, ta, te, tb, td, tc);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_1(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                  \
	mk_lang_assert(tb);                                                                                  \
	mk_lang_assert(tc);                                                                                  \
	mk_lang_assert(td);                                                                                  \
	mk_lang_assert(te);                                                                                  \
	mk_lang_assert(ta != tb);                                                                            \
	mk_lang_assert(ta != tc);                                                                            \
	mk_lang_assert(ta != td);                                                                            \
	mk_lang_assert(ta != te);                                                                            \
	mk_lang_assert(tb != tc);                                                                            \
	mk_lang_assert(tb != td);                                                                            \
	mk_lang_assert(tb != te);                                                                            \
	mk_lang_assert(tc != td);                                                                            \
	mk_lang_assert(tc != te);                                                                            \
	mk_lang_assert(td != te);                                                                            \
	mk_lib_crypto_alg_serpent_inl_ui_assign (*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_and2   (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2   (*td, *ta); mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2   (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_or2    (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2   (*ta, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2   (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_not1(*te     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2   (*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *ta);                                                     \
	mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *te);                                                     \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tb);                                                     \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, te, ta, td, tc, tb);                      \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_2(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *td); mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_ui_and2(*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_and2(*te, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_not1(*td     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*ta, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *ta);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, te, tc, td, ta);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_3(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_and2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_and2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_or2 (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *te);                                                  \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *tb);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tc, tb, td, ta, te);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_4(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2 (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2(*tb, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *te);                                                  \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tc, *tb);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, ta, td, tc, te, tb);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_5(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_not1(*tb     ); mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *tb); mk_lib_crypto_alg_serpent_inl_ui_or2   (*td, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_ui_or2   (*tc, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *te); mk_lib_crypto_alg_serpent_inl_ui_or2   (*te, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2  (*tb, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *te); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *te); mk_lib_crypto_alg_serpent_inl_ui_not1  (*te     ); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *ta);                                                    \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, te, td, tc, ta);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_6(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_and2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *td); mk_lib_crypto_alg_serpent_inl_ui_or2   (*te, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tb); mk_lib_crypto_alg_serpent_inl_ui_and2  (*tb, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_or2 (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2  (*td, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *ta);                                                    \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, tb, tc, te, td, ta);                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_inl_substitute_dec_7(ta, tb, tc, td, te) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(ta);                                                                                 \
	mk_lang_assert(tb);                                                                                 \
	mk_lang_assert(tc);                                                                                 \
	mk_lang_assert(td);                                                                                 \
	mk_lang_assert(te);                                                                                 \
	mk_lang_assert(ta != tb);                                                                           \
	mk_lang_assert(ta != tc);                                                                           \
	mk_lang_assert(ta != td);                                                                           \
	mk_lang_assert(ta != te);                                                                           \
	mk_lang_assert(tb != tc);                                                                           \
	mk_lang_assert(tb != td);                                                                           \
	mk_lang_assert(tb != te);                                                                           \
	mk_lang_assert(tc != td);                                                                           \
	mk_lang_assert(tc != te);                                                                           \
	mk_lang_assert(td != te);                                                                           \
	mk_lib_crypto_alg_serpent_inl_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_ui_or2 (*te, *td); \
	mk_lib_crypto_alg_serpent_inl_ui_not1  (*tc     ); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*tb, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*ta, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_and2  (*tc, *te); mk_lib_crypto_alg_serpent_inl_ui_and2(*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*tc, *ta); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*ta, *tc); mk_lib_crypto_alg_serpent_inl_ui_xor2(*te, *tb); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *te); \
	mk_lib_crypto_alg_serpent_inl_ui_or2   (*te, *ta); mk_lib_crypto_alg_serpent_inl_ui_xor2(*td, *tc); \
	mk_lib_crypto_alg_serpent_inl_ui_xor2  (*te, *tc);                                                  \
	mk_lib_crypto_alg_serpent_inl_swaparoo(ta, tb, tc, td, te, td, ta, tb, te, tc);                     \
}while(mk_lang_false)

mk_lib_crypto_alg_serpent_inl_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_inl_target mk_lib_crypto_alg_serpent_inl_schedule_encrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_msg_ct, input, mk_lib_crypto_alg_serpent_inl_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_msg_t, output, mk_lib_crypto_alg_serpent_inl_cnt)) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lib_crypto_alg_serpent_inl_type_t ta mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t tb mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t tc mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t td mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t te mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt pta mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptb mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptc mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptd mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt pte mk_lib_crypto_alg_serpent_inl_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	pta = &ta;
	ptb = &tb;
	ptc = &tc;
	ptd = &td;
	pte = &te;
	mk_lib_crypto_alg_serpent_inl_load(input, pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 0]); mk_lib_crypto_alg_serpent_inl_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 1]); mk_lib_crypto_alg_serpent_inl_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 2]); mk_lib_crypto_alg_serpent_inl_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 3]); mk_lib_crypto_alg_serpent_inl_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 4]); mk_lib_crypto_alg_serpent_inl_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 5]); mk_lib_crypto_alg_serpent_inl_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 6]); mk_lib_crypto_alg_serpent_inl_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 7]); mk_lib_crypto_alg_serpent_inl_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 8]); mk_lib_crypto_alg_serpent_inl_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 9]); mk_lib_crypto_alg_serpent_inl_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[10]); mk_lib_crypto_alg_serpent_inl_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[11]); mk_lib_crypto_alg_serpent_inl_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[12]); mk_lib_crypto_alg_serpent_inl_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[13]); mk_lib_crypto_alg_serpent_inl_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[14]); mk_lib_crypto_alg_serpent_inl_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[15]); mk_lib_crypto_alg_serpent_inl_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[16]); mk_lib_crypto_alg_serpent_inl_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[17]); mk_lib_crypto_alg_serpent_inl_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[18]); mk_lib_crypto_alg_serpent_inl_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[19]); mk_lib_crypto_alg_serpent_inl_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[20]); mk_lib_crypto_alg_serpent_inl_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[21]); mk_lib_crypto_alg_serpent_inl_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[22]); mk_lib_crypto_alg_serpent_inl_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[23]); mk_lib_crypto_alg_serpent_inl_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[24]); mk_lib_crypto_alg_serpent_inl_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[25]); mk_lib_crypto_alg_serpent_inl_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[26]); mk_lib_crypto_alg_serpent_inl_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[27]); mk_lib_crypto_alg_serpent_inl_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[28]); mk_lib_crypto_alg_serpent_inl_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[29]); mk_lib_crypto_alg_serpent_inl_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[30]); mk_lib_crypto_alg_serpent_inl_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[31]); mk_lib_crypto_alg_serpent_inl_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[32]);
	mk_lib_crypto_alg_serpent_inl_store(output, pta, ptb, ptc, ptd);
}}

mk_lib_crypto_alg_serpent_inl_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_inl_target mk_lib_crypto_alg_serpent_inl_schedule_decrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_msg_ct, input, mk_lib_crypto_alg_serpent_inl_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_msg_t, output, mk_lib_crypto_alg_serpent_inl_cnt)) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lib_crypto_alg_serpent_inl_type_t ta mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t tb mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t tc mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t td mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_t te mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt pta mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptb mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptc mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt ptd mk_lib_crypto_alg_serpent_inl_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_type_pt pte mk_lib_crypto_alg_serpent_inl_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	pta = &ta;
	ptb = &tb;
	ptc = &tc;
	ptd = &td;
	pte = &te;
	mk_lib_crypto_alg_serpent_inl_load(input, pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[32]);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[31]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[30]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[29]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[28]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[27]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[26]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[25]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[24]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[23]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[22]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[21]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[20]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[19]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[18]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[17]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[16]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[15]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[14]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[13]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[12]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[11]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[10]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 9]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 8]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 7]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 6]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 5]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 4]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 3]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 2]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 1]); mk_lib_crypto_alg_serpent_inl_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_substitute_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_xor_rk(pta, ptb, ptc, ptd, &schedule->m_data.m_msgs[ 0]);
	mk_lib_crypto_alg_serpent_inl_store(output, pta, ptb, ptc, ptd);
}}

mk_lib_crypto_alg_serpent_inl_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_inl_schedule_encrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % mk_lib_crypto_alg_serpent_inl_cnt == 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);

	for(iblock = 0; iblock != nblocks; iblock += mk_lib_crypto_alg_serpent_inl_cnt)
	{
		mk_lib_crypto_alg_serpent_inl_schedule_encrypt_blocks(schedule, &input[iblock], &output[iblock]);
	}
}

mk_lib_crypto_alg_serpent_inl_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_inl_schedule_decrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % mk_lib_crypto_alg_serpent_inl_cnt == 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);

	for(iblock = 0; iblock != nblocks; iblock += mk_lib_crypto_alg_serpent_inl_cnt)
	{
		mk_lib_crypto_alg_serpent_inl_schedule_decrypt_blocks(schedule, &input[iblock], &output[iblock]);
	}
}


#if mk_lib_crypto_alg_serpent_inl_bits != 32


#undef mk_lib_crypto_alg_serpent_inl_name
#undef mk_lib_crypto_alg_serpent_inl_type
#undef mk_lib_crypto_alg_serpent_inl_bits
#undef mk_lib_crypto_alg_serpent_inl_constexpr
#undef mk_lib_crypto_alg_serpent_inl_uints_t
#undef mk_lib_crypto_alg_serpent_inl_ui_assign
#undef mk_lib_crypto_alg_serpent_inl_ui_and2
#undef mk_lib_crypto_alg_serpent_inl_ui_not1
#undef mk_lib_crypto_alg_serpent_inl_ui_or2
#undef mk_lib_crypto_alg_serpent_inl_ui_rotl2
#undef mk_lib_crypto_alg_serpent_inl_ui_rotr2
#undef mk_lib_crypto_alg_serpent_inl_ui_shl3
#undef mk_lib_crypto_alg_serpent_inl_ui_xor2
#undef mk_lib_crypto_alg_serpent_inl_ui_xor3
#undef mk_lib_crypto_alg_serpent_inl_ui_broadcast
#undef mk_lib_crypto_alg_serpent_inl_load
#undef mk_lib_crypto_alg_serpent_inl_store
#undef mk_lib_crypto_alg_serpent_inl_target
#undef mk_lib_crypto_alg_serpent_inl_constexpr_spec
#undef mk_lib_crypto_alg_serpent_inl_constexpr_init
#undef mk_lib_crypto_alg_serpent_inl_type_t
#undef mk_lib_crypto_alg_serpent_inl_type_ct
#undef mk_lib_crypto_alg_serpent_inl_type_pt
#undef mk_lib_crypto_alg_serpent_inl_type_prt
#undef mk_lib_crypto_alg_serpent_inl_type_pct
#undef mk_lib_crypto_alg_serpent_inl_type_prct
#undef mk_lib_crypto_alg_serpent_inl_cnt
#undef mk_lib_crypto_alg_serpent_inl_schedule_encrypt_blocks
#undef mk_lib_crypto_alg_serpent_inl_schedule_decrypt_blocks
#undef mk_lib_crypto_alg_serpent_inl_schedule_encrypt
#undef mk_lib_crypto_alg_serpent_inl_schedule_decrypt
#undef mk_lib_crypto_alg_serpent_inl_xor_rk
#undef mk_lib_crypto_alg_serpent_inl_swaparoo
#undef mk_lib_crypto_alg_serpent_inl_enc_lt
#undef mk_lib_crypto_alg_serpent_inl_enc_0
#undef mk_lib_crypto_alg_serpent_inl_enc_1
#undef mk_lib_crypto_alg_serpent_inl_enc_2
#undef mk_lib_crypto_alg_serpent_inl_enc_3
#undef mk_lib_crypto_alg_serpent_inl_enc_4
#undef mk_lib_crypto_alg_serpent_inl_enc_5
#undef mk_lib_crypto_alg_serpent_inl_enc_6
#undef mk_lib_crypto_alg_serpent_inl_enc_7
#undef mk_lib_crypto_alg_serpent_inl_dec_lt
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_0
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_1
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_2
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_3
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_4
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_5
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_6
#undef mk_lib_crypto_alg_serpent_inl_substitute_dec_7


#undef mk_lib_crypto_alg_serpent_inl_t_name
#undef mk_lib_crypto_alg_serpent_inl_t_type
#undef mk_lib_crypto_alg_serpent_inl_t_bits
#undef mk_lib_crypto_alg_serpent_inl_t_constexpr
#undef mk_lib_crypto_alg_serpent_inl_t_uints_t
#undef mk_lib_crypto_alg_serpent_inl_t_ui_assign
#undef mk_lib_crypto_alg_serpent_inl_t_ui_and2
#undef mk_lib_crypto_alg_serpent_inl_t_ui_not1
#undef mk_lib_crypto_alg_serpent_inl_t_ui_or2
#undef mk_lib_crypto_alg_serpent_inl_t_ui_rotl2
#undef mk_lib_crypto_alg_serpent_inl_t_ui_rotr2
#undef mk_lib_crypto_alg_serpent_inl_t_ui_shl3
#undef mk_lib_crypto_alg_serpent_inl_t_ui_xor2
#undef mk_lib_crypto_alg_serpent_inl_t_ui_xor3
#undef mk_lib_crypto_alg_serpent_inl_t_ui_broadcast
#undef mk_lib_crypto_alg_serpent_inl_t_load
#undef mk_lib_crypto_alg_serpent_inl_t_store
#undef mk_lib_crypto_alg_serpent_inl_t_target


#endif
