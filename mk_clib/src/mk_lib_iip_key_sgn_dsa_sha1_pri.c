#ifndef mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_pri_c
#define mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_pri_c
#include "mk_lib_iip_key_sgn_dsa_sha1_pri.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_pub.h"
#include "mk_lib_iip_random.h"
#include "mk_sl_uint_more.h"


#define mk_sl_cui_t_name mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((20 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((20 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v];
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_align;
};
typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_data_t;
struct mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_s
{
	mk_lang_alignas(32) mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_data_t m_data;
};
typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_s mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_t;
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_pri_uchars_t const mk_lib_iip_key_sgn_dsa_sha1_pri_k_q =
{{{
	0xa5, 0xdf, 0xc2, 0x8f, 0xef, 0x4c, 0xa1, 0xe2, 0x86, 0x74, 0x4c, 0xd8, 0xee, 0xd9, 0xd2, 0x9d, 0x68, 0x40, 0x46, 0xb7,
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_pri_single;
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t m_pri_double;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_s mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_t;

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)));
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_pri_single;
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t m_pri_double;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_s mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_t;

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_pri_single;
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_pub_single;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_s mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_t;

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)));
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_load_q(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_buis_uchar_be(x, &mk_lib_iip_key_sgn_dsa_sha1_pri_k_q.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v];
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_s mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_t;

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar_many(&b[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_negative(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pct const x) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_shr3(x, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bits_v - 1, &ta);
	ret = !mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_zero(&ta);
	return ret;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_flip_sign_1(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_not1(x);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_inc1(x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_add2_wrap_cid_cod(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const m, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(m, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(a, &aa);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(b, &bb);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_add2_wrap_cid_cod(&aa, &bb);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_mul3_wrap_lo(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const m, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const b, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t bb mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t cc mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(m != c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(m, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(a, &aa);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(b, &bb);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_mul3_wrap_lo(&aa, &bb, &cc);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_mod2_wrap(&cc, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single(&cc, c);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_mul2_wrap_lo(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const m, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(m, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(a, &aa);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pri_double(b, &bb);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_mul2_wrap_lo(&aa, &bb);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_double_to_pri_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_gcd(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const b, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t tc mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt pa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt pb mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt pc mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt qa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt qb mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt qc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	pa = &ta;
	pb = &tb;
	pc = &tc;
	while(!mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_zero(pb))
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod3_wrap(pa, pb, pc);
		qa = pa; qb = pb; qc = pc;
		pa = qb; pb = qc; pc = qa;
	}
	*c = *pa;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mul3_signed(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const b, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t tc mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	ba = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_negative(&ta);
	bb = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_negative(&tb);
	if(ba){ mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_flip_sign_1(&ta); }
	if(bb){ mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_flip_sign_1(&tb); }
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mul3_wrap_lo(&ta, &tb, &tc);
	if((ba && !bb) || (!ba && bb)){ mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_flip_sign_1(&tc); }
	*c = tc;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_inv(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pct const modulus, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const res_out) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t mz mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t y mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t x mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t one mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t t mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(modulus);
	mk_lang_assert(res_out);
	mk_lang_assert((mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_gcd(a, modulus, &aa), mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_one(&aa)));

	mz = *modulus;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_set_zero(&y);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_set_one(&x);
	if(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_one(&mz))
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_set_zero(res_out);
	}
	else
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_set_one(&one);
		aa = *a;
		mm = *modulus;
		while(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_gt(&aa, &one))
		{
			mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_div3_wrap(&aa, &mm, &q);
			mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod3_wrap(&aa, &mm, &ta);
			aa = mm;
			mm = ta;
			t = y;
			mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mul3_signed(&q, &y, &ta);
			mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_sub3_wrap_cid_cod(&x, &ta, &y);
			x = t;
		}
		if(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_negative(&x))
		{
			mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_add2_wrap_cid_cod(&x, &mz);
		}
		*res_out = x;
	}
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_pr_generate_k(mk_lib_iip_key_sgn_dsa_sha1_pri_pt const k) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t q;
	mk_lang_types_sint_t err;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t gcd;

	mk_lang_assert(k);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_load_q(&q);
	do
	{
		err = mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random(k); mk_lang_check_rereturn(err);
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_gcd(&q, &k->m_data.m_integer, &gcd);
	}while(!mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_one(&gcd));
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_key_sgn_dsa_sha1_pri_is_valid(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t q mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_load_q(&q);
	ret = !mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_zero(&pri->m_data.m_integer) && mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_lt(&pri->m_data.m_integer, &q);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random(mk_lib_iip_key_sgn_dsa_sha1_pri_pt const pri) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v];
		mk_lib_iip_key_sgn_dsa_sha1_pri_t m_elgamal_key_pri;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_data_u mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_s mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random_t storage;

	mk_lang_assert(pri);

	err = mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_buis_uchar_le(&pri->m_data.m_integer, &storage.m_data.m_uchars[0]);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pri_sign_k(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const k, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_dsa_sha1_pri_signature_pt const signature) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t g mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t p mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t r mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t ki mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t s mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(k);
	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(signature);
	mk_lang_assert(pri != k);
	mk_lang_assert(&pri->m_data.m_integer != &signature->m_r);
	mk_lang_assert(&pri->m_data.m_integer != &signature->m_s);
	mk_lang_assert(&k->m_data.m_integer != &signature->m_r);
	mk_lang_assert(&k->m_data.m_integer != &signature->m_s);
	mk_lang_assert(&signature->m_r != &signature->m_s);

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, data_buf, ((mk_lang_types_usize_t)(data_len)));
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_u8s_be(&m, &digest.m_data.m_uint8s[0]);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_load_q(&q);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_load_g(&g);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_load_p(&p);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_mod_pow_b(&g, &k->m_data.m_integer, &p, &q, &r);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_inv(&k->m_data.m_integer, &q, &ki);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_mul3_wrap_lo(&q, &pri->m_data.m_integer, &r, &s);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_add2_wrap_cid_cod(&q, &s, &m);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_mod_mul2_wrap_lo(&q, &s, &ki);
	signature->m_r = r;
	signature->m_s = s;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_sign_data(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_dsa_sha1_pri_signature_pt const signature) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_key_sgn_dsa_sha1_pri_t k;

	mk_lang_assert(pri);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature);

	err = mk_lib_iip_key_sgn_dsa_sha1_pri_pr_generate_k(&k); mk_lang_check_rereturn(err);
	mk_lib_iip_key_sgn_dsa_sha1_pri_sign_k(pri, &k, data_buf, data_len, signature);
	return 0;
}


#endif
