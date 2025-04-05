include(`mk_lib_crypto_hash_stream_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_crypto_hash_stream_any1_c
#define mk_include_guard_mk_lib_crypto_hash_stream_any1_c
#include "mk_lib_crypto_hash_stream_any1.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_cui_uint8.h"

mk_lib_crypto_hash_stream_any_mm_per_hash(`#include "mk_lib_crypto_hash_stream_$1.h"', `
')


union mk_lib_crypto_hash_stream_any1_digest_data_u
{
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lib_crypto_hash_stream_$1_digest_t m_$1;', `
')
};
typedef union mk_lib_crypto_hash_stream_any1_digest_data_u mk_lib_crypto_hash_stream_any1_digest_data_t;
struct mk_lib_crypto_hash_stream_any1_digest_s
{
	mk_lib_crypto_hash_stream_any1_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_stream_any1_digest_s mk_lib_crypto_hash_stream_any1_digest_t;
mk_lang_typedef(mk_lib_crypto_hash_stream_any1_digest);


#define mk_lib_crypto_hash_stream_any1_strs_def_bufs \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_stringify(mk_lib_crypto_hash_block_$1_name_def) \', `
')

#define mk_lib_crypto_hash_stream_any1_strs_def_lens \
{ \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_countstr(mk_lang_stringify(mk_lib_crypto_hash_block_$1_name_def)), \', `
')
}

#define mk_lib_crypto_hash_stream_any1_strs_def_sum(x) \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_countstr(mk_lang_stringify(mk_lib_crypto_hash_block_$1_name_def)) * (((x) >= $2) ? 1 : 0) + \', `
')
	0

#define mk_lib_crypto_hash_stream_any1_strs_def_sums \
{ \
	mk_lib_crypto_hash_stream_any1_strs_def_sum(-1), \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lib_crypto_hash_stream_any1_strs_def_sum($2), \', `
')
}


#define mk_lib_crypto_hash_stream_any1_keys_def_bufs \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_stringify($1) \', `
')

#define mk_lib_crypto_hash_stream_any1_keys_def_lens \
{ \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_countstr(mk_lang_stringify($1)), \', `
')
}

#define mk_lib_crypto_hash_stream_any1_keys_def_sum(x) \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_countstr(mk_lang_stringify($1)) * (((x) >= $2) ? 1 : 0) + \', `
')
	0

#define mk_lib_crypto_hash_stream_any1_keys_def_sums \
{ \
	mk_lib_crypto_hash_stream_any1_keys_def_sum(-1), \
mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lib_crypto_hash_stream_any1_keys_def_sum($2), \', `
')
}


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_stream_any1_strs_bufs[] = mk_lib_crypto_hash_stream_any1_strs_def_bufs;
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_lib_crypto_hash_stream_any1_strs_lens[] = mk_lib_crypto_hash_stream_any1_strs_def_lens;
mk_lang_constexpr_static_inline mk_lang_types_sint_t  const mk_lib_crypto_hash_stream_any1_strs_sums[] = mk_lib_crypto_hash_stream_any1_strs_def_sums;

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_stream_any1_keys_bufs[] = mk_lib_crypto_hash_stream_any1_keys_def_bufs;
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_lib_crypto_hash_stream_any1_keys_lens[] = mk_lib_crypto_hash_stream_any1_keys_def_lens;
mk_lang_constexpr_static_inline mk_lang_types_sint_t  const mk_lib_crypto_hash_stream_any1_keys_sums[] = mk_lib_crypto_hash_stream_any1_keys_def_sums;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_crypto_hash_stream_any1_get_str_buf(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;
	mk_lang_types_pchar_pct buf mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	off = mk_lib_crypto_hash_stream_any1_strs_sums[id]; mk_lang_assert(off >= 0 && off < mk_lang_countof(mk_lib_crypto_hash_stream_any1_strs_bufs));
	buf = &mk_lib_crypto_hash_stream_any1_strs_bufs[off];
	return buf;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_any1_get_str_len(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	len =
		mk_lib_crypto_hash_stream_any1_strs_sums[id + 1] -
		mk_lib_crypto_hash_stream_any1_strs_sums[id + 0];
	return len;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_crypto_hash_stream_any1_get_key_buf(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;
	mk_lang_types_pchar_pct buf mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	off = mk_lib_crypto_hash_stream_any1_keys_sums[id]; mk_lang_assert(off >= 0 && off < mk_lang_countof(mk_lib_crypto_hash_stream_any1_keys_bufs));
	buf = &mk_lib_crypto_hash_stream_any1_keys_bufs[off];
	return buf;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_any1_get_key_len(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	len =
		mk_lib_crypto_hash_stream_any1_keys_sums[id + 1] -
		mk_lib_crypto_hash_stream_any1_keys_sums[id + 0];
	return len;
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_hash_stream_any1_get_max_digest_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t max mk_lang_constexpr_init;

	max = -1;
mk_lib_crypto_hash_stream_any_mm_per_hash(`	max = mk_lang_max(max, mk_lib_crypto_hash_stream_$1_digest_len_v);', `
')
	return max;
}
#else
#define mk_lib_crypto_hash_stream_any1_get_max_digest_len() mk_lib_crypto_hash_stream_any1_digest_max_len_v
#endif

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_any1_get_digest_len(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

mk_lib_crypto_hash_stream_any_mm_per_hash(`	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_$1_digest_len_v)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_digest_max_len_v)));', `
')
	mk_lang_static_assert(mk_lib_crypto_hash_stream_any1_get_max_digest_len() == mk_lib_crypto_hash_stream_any1_digest_max_len_v);

	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	mk_lang_clobber(&res);
	switch(id)
	{
mk_lib_crypto_hash_stream_any_mm_per_hash(`		case mk_lib_crypto_hash_stream_any1_id_e_$1: res = mk_lib_crypto_hash_stream_$1_digest_len_v; break;', `
')
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return res;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_init(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_crypto_hash_stream_any_mm_per_hash(`		case mk_lib_crypto_hash_stream_any1_id_e_$1: mk_lib_crypto_hash_stream_$1_init(hash_stream_any1_bare->m_data.m_$1); break;', `
')
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_append_u8s(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_crypto_hash_stream_any_mm_per_hash(`		case mk_lib_crypto_hash_stream_any1_id_e_$1: mk_lib_crypto_hash_stream_$1_append_u8s(hash_stream_any1_bare->m_data.m_$1, u8s, count); break;', `
')
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_finish(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_any1_digest_t dgst mk_lang_constexpr_init;

	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_crypto_hash_stream_any_mm_per_hash(`		case mk_lib_crypto_hash_stream_any1_id_e_$1: mk_lib_crypto_hash_stream_$1_finish(hash_stream_any1_bare->m_data.m_$1, &dgst.m_data.m_$1); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_$1.m_data.m_uint8s[0],mk_lib_crypto_hash_stream_$1_digest_len_v); break;', `
')
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_init(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);
	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_hash_stream_any1_id_e_dummy_end);

	hash_stream_any1_ptrid->m_id = id;
	mk_lib_crypto_hash_stream_any1_bare_init(&hash_stream_any1_ptrid->m_ptr, id);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_append_u8s(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_hash_stream_any1_bare_append_u8s(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_finish(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_hash_stream_any1_bare_finish(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, digest);
}


#endif
