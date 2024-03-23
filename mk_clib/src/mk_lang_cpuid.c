#include "mk_lang_cpuid.h"

#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


#include <intrin.h>


#pragma intrinsic(__cpuid)


union mk_lang_cpuid_aligned_regs_u
{
	mk_lang_types_sint_t m_sints[4];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lang_cpuid_aligned_regs_u mk_lang_cpuid_aligned_regs_t;
typedef mk_lang_cpuid_aligned_regs_t const mk_lang_cpuid_aligned_regs_ct;
typedef mk_lang_cpuid_aligned_regs_t* mk_lang_cpuid_aligned_regs_pt;
typedef mk_lang_cpuid_aligned_regs_t const* mk_lang_cpuid_aligned_regs_pct;

struct mk_lang_cpuid_regs_s
{
	mk_lang_cpuid_aligned_regs_t m_data;
};
typedef struct mk_lang_cpuid_regs_s mk_lang_cpuid_regs_t;
typedef mk_lang_cpuid_regs_t const mk_lang_cpuid_regs_ct;
typedef mk_lang_cpuid_regs_t* mk_lang_cpuid_regs_pt;
typedef mk_lang_cpuid_regs_t const* mk_lang_cpuid_regs_pct;

union mk_lang_cpuid_aligned_regset_u
{
	mk_lang_cpuid_regs_t m_regset[0xd];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lang_cpuid_aligned_regset_u mk_lang_cpuid_aligned_regset_t;
typedef mk_lang_cpuid_aligned_regset_t const mk_lang_cpuid_aligned_regset_ct;
typedef mk_lang_cpuid_aligned_regset_t* mk_lang_cpuid_aligned_regset_pt;
typedef mk_lang_cpuid_aligned_regset_t const* mk_lang_cpuid_aligned_regset_pct;

struct mk_lang_cpuid_regset_s
{
	mk_lang_types_sint_t m_leafs;
	mk_lang_cpuid_aligned_regset_t m_data;
};
typedef struct mk_lang_cpuid_regset_s mk_lang_cpuid_regset_t;
typedef mk_lang_cpuid_regset_t const mk_lang_cpuid_regset_ct;
typedef mk_lang_cpuid_regset_t* mk_lang_cpuid_regset_pt;
typedef mk_lang_cpuid_regset_t const* mk_lang_cpuid_regset_pct;


static mk_lang_cpuid_regset_t g_mk_lang_cpuid_regset;


mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_cpuid_regs_t regs;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	__cpuid(&regs.m_data.m_sints[0], 0);
	g_mk_lang_cpuid_regset.m_data.m_regset[0] = regs;
	n = regs.m_data.m_sints[0];
	mk_lang_assert(n >= 1);
	n = mk_lang_min(n, ((mk_lang_types_sint_t)(mk_lang_countof(g_mk_lang_cpuid_regset.m_data.m_regset))));
	g_mk_lang_cpuid_regset.m_leafs = n;
	for(i = 1; i != n; ++i)
	{
		__cpuid(regs.m_data.m_sints, i);
		g_mk_lang_cpuid_regset.m_data.m_regset[i] = regs;
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_reset(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	g_mk_lang_cpuid_regset.m_leafs = 0;
	n = ((mk_lang_types_sint_t)(mk_lang_countof(g_mk_lang_cpuid_regset.m_data.m_regset)));
	for(i = 0; i != n; ++i)
	{
		g_mk_lang_cpuid_regset.m_data.m_regset[i].m_data.m_sints[0] = 0;
		g_mk_lang_cpuid_regset.m_data.m_regset[i].m_data.m_sints[1] = 0;
		g_mk_lang_cpuid_regset.m_data.m_regset[i].m_data.m_sints[2] = 0;
		g_mk_lang_cpuid_regset.m_data.m_regset[i].m_data.m_sints[3] = 0;
	}
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[2])) & (1u << 9)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[2])) & (1u << 19)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[2])) & (1u << 23)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[2])) & (1u << 25)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[2])) & (1u << 28)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[3])) & (1u << 25)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x1].m_data.m_sints[3])) & (1u << 26)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (g_mk_lang_cpuid_regset.m_leafs >= 0x7) && ((((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x7].m_data.m_sints[1])) & (1u << 5)) != 0);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (g_mk_lang_cpuid_regset.m_leafs >= 0x7) && ((((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x7].m_data.m_sints[1])) & (1u << 16)) != 0);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = (g_mk_lang_cpuid_regset.m_leafs >= 0x7) && ((((mk_lang_types_uint_t)(g_mk_lang_cpuid_regset.m_data.m_regset[0x7].m_data.m_sints[1])) & (1u << 29)) != 0);
	return has;
}


#elif 0


gcc


#else


#endif
