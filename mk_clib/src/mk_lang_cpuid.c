#include "mk_lang_cpuid.h"

#include "mk_lang_arch.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))


#include <intrin.h> /* __cpuid */


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


static mk_lang_cpuid_regs_t g_mk_lang_cpuid_regs;


mk_lang_jumbo void mk_lang_cpuid_init(void) mk_lang_noexcept
{
	mk_lang_cpuid_regs_t regs;

	__cpuid(regs.m_data.m_sints, 1);
	g_mk_lang_cpuid_regs = regs;
}

mk_lang_jumbo void mk_lang_cpuid_reset(void) mk_lang_noexcept
{
	g_mk_lang_cpuid_regs.m_data.m_sints[0] = 0;
	g_mk_lang_cpuid_regs.m_data.m_sints[1] = 0;
	g_mk_lang_cpuid_regs.m_data.m_sints[2] = 0;
	g_mk_lang_cpuid_regs.m_data.m_sints[3] = 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = (g_mk_lang_cpuid_regs.m_data.m_sints[2] & (1u << 23)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = (g_mk_lang_cpuid_regs.m_data.m_sints[2] & (1u << 25)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = (g_mk_lang_cpuid_regs.m_data.m_sints[3] & (1u << 25)) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = (g_mk_lang_cpuid_regs.m_data.m_sints[3] & (1u << 26)) != 0;
	return has;
}


#else


mk_lang_jumbo void mk_lang_cpuid_init(void) mk_lang_noexcept
{
}

mk_lang_jumbo void mk_lang_cpuid_reset(void) mk_lang_noexcept
{
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = mk_lang_false;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = mk_lang_false;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = mk_lang_false;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(void) mk_lang_noexcept
{
	mk_lang_bool_t has;

	has = mk_lang_false;
	return has;
}


#endif
