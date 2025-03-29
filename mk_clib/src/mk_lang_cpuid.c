#ifndef mk_include_guard_mk_lang_cpuid_c
#define mk_include_guard_mk_lang_cpuid_c
#include "mk_lang_cpuid.h"

#include "mk_lang_arch.h"
#include "mk_lang_compiler.h"
#include "mk_lang_msvc.h"


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <intrin.h> /* __cpuid __cpuidex */


#pragma intrinsic(__cpuid)
#pragma intrinsic(__cpuidex)


union mk_lang_cpuid_regs_pack_data_u
{
	mk_lang_types_uint_t m_uints[4];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lang_cpuid_regs_pack_data_u mk_lang_cpuid_regs_pack_data_t;

struct mk_lang_cpuid_regs_pack_s
{
	mk_lang_cpuid_regs_pack_data_t m_data;
};
typedef struct mk_lang_cpuid_regs_pack_s mk_lang_cpuid_regs_pack_t;

union mk_lang_cpuid_regs_packs_01_data_u
{
	mk_lang_cpuid_regs_pack_t m_packs[0x1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lang_cpuid_regs_packs_01_data_u mk_lang_cpuid_regs_packs_01_data_t;

struct mk_lang_cpuid_regs_packs_01_s
{
	mk_lang_cpuid_regs_packs_01_data_t m_data;
};
typedef struct mk_lang_cpuid_regs_packs_01_s mk_lang_cpuid_regs_packs_01_t;

union mk_lang_cpuid_regs_packs_0d_data_u
{
	mk_lang_cpuid_regs_pack_t m_packs[0xd];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lang_cpuid_regs_packs_0d_data_u mk_lang_cpuid_regs_packs_0d_data_t;

struct mk_lang_cpuid_regs_packs_0d_s
{
	mk_lang_cpuid_regs_packs_0d_data_t m_data;
};
typedef struct mk_lang_cpuid_regs_packs_0d_s mk_lang_cpuid_regs_packs_0d_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lang_cpuid_s
{
	mk_lang_types_uint_t m_leafs_count;
	mk_lang_cpuid_regs_packs_0d_t m_leafs;
	mk_lang_cpuid_regs_packs_01_t m_leaf_07_sub_leafs;
};
typedef struct mk_lang_cpuid_s mk_lang_cpuid_t;
#include "mk_lang_warning_msvc_pop.h"


static mk_lang_cpuid_t mk_lang_cpuid_g;


enum mk_lang_cpuid_register_id_e
{
	mk_lang_cpuid_register_id_e_eax = 0,
	mk_lang_cpuid_register_id_e_ebx = 1,
	mk_lang_cpuid_register_id_e_ecx = 2,
	mk_lang_cpuid_register_id_e_edx = 3,
	mk_lang_cpuid_register_id_e_dummy_end
};
typedef enum mk_lang_cpuid_register_id_e mk_lang_cpuid_register_id_t;


#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_bit_set(mk_lang_types_sint_t const leaf, mk_lang_cpuid_register_id_t const register_id, mk_lang_types_sint_t const bit) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(leaf >= 0 && leaf < mk_lang_countof(mk_lang_cpuid_g.m_leafs.m_data.m_packs));
	mk_lang_assert(register_id >= 0 && register_id < mk_lang_countof(mk_lang_cpuid_g.m_leafs.m_data.m_packs[0].m_data.m_uints));
	mk_lang_assert(bit >= 0 && bit < 32);

	has = mk_lang_false;
	if(((mk_lang_types_sint_t)(mk_lang_cpuid_g.m_leafs_count)) >= leaf)
	{
		has = (mk_lang_cpuid_g.m_leafs.m_data.m_packs[leaf].m_data.m_uints[register_id] & (1u << bit)) != 0;
	}
	return has;
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_leaf_07_sub_leaf_bit_set(mk_lang_types_sint_t const sub_leaf, mk_lang_cpuid_register_id_t const register_id, mk_lang_types_sint_t const bit) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(sub_leaf >= 1 && sub_leaf <= mk_lang_countof(mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs));
	mk_lang_assert(register_id >= 0 && register_id < mk_lang_countof(mk_lang_cpuid_g.m_leafs.m_data.m_packs[0].m_data.m_uints));
	mk_lang_assert(bit >= 0 && bit < 32);

	has = mk_lang_false;
	if(mk_lang_cpuid_g.m_leafs_count >= 7)
	{
		if(((mk_lang_types_sint_t)(mk_lang_cpuid_g.m_leafs.m_data.m_packs[7].m_data.m_uints[mk_lang_cpuid_register_id_e_eax])) >= sub_leaf)
		{
			has = (mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[sub_leaf - 1].m_data.m_uints[register_id] & (1u << bit)) != 0;
		}
	}
	return has;
}
#include "mk_lang_warning_msvc_pop.h"


mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;

	__cpuid(((mk_lang_types_sint_pt)(&mk_lang_cpuid_g.m_leafs.m_data.m_packs[0].m_data.m_uints[0])), 0);
	n = mk_lang_cpuid_g.m_leafs.m_data.m_packs[0].m_data.m_uints[0];
	mk_lang_assert(n >= 1);
	n = mk_lang_min(n, ((mk_lang_types_uint_t)(mk_lang_countof(mk_lang_cpuid_g.m_leafs.m_data.m_packs))));
	mk_lang_cpuid_g.m_leafs_count = n;
	for(i = 1; i != n; ++i)
	{
		__cpuid(((mk_lang_types_sint_pt)(&mk_lang_cpuid_g.m_leafs.m_data.m_packs[i].m_data.m_uints[0])), ((mk_lang_types_sint_t)(i)));
	}
	n = mk_lang_cpuid_g.m_leafs_count >= 0x7 ? mk_lang_cpuid_g.m_leafs.m_data.m_packs[0x7].m_data.m_uints[0] : 0x0;
	n = mk_lang_min(n, mk_lang_countof(mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs));
	for(i = 0; i != n; ++i)
	{
		__cpuidex(((mk_lang_types_sint_pt)(&mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[i].m_data.m_uints[0])), 0x7, ((mk_lang_types_sint_t)(i + 1)));
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_reset(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;

	mk_lang_cpuid_g.m_leafs_count = 0;
	n = ((mk_lang_types_uint_t)(mk_lang_countof(mk_lang_cpuid_g.m_leafs.m_data.m_packs)));
	for(i = 0; i != n; ++i)
	{
		mk_lang_cpuid_g.m_leafs.m_data.m_packs[i].m_data.m_uints[0] = 0;
		mk_lang_cpuid_g.m_leafs.m_data.m_packs[i].m_data.m_uints[1] = 0;
		mk_lang_cpuid_g.m_leafs.m_data.m_packs[i].m_data.m_uints[2] = 0;
		mk_lang_cpuid_g.m_leafs.m_data.m_packs[i].m_data.m_uints[3] = 0;
	}
	n = ((mk_lang_types_uint_t)(mk_lang_countof(mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs)));
	for(i = 0; i != n; ++i)
	{
		mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[i].m_data.m_uints[0] = 0;
		mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[i].m_data.m_uints[1] = 0;
		mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[i].m_data.m_uints[2] = 0;
		mk_lang_cpuid_g.m_leaf_07_sub_leafs.m_data.m_packs[i].m_data.m_uints[3] = 0;
	}
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_pclmulqdq(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 1);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 9);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 19);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 23);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aesni(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 25);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_ecx, 28);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_edx, 25);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(1, mk_lang_cpuid_register_id_e_edx, 26);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(7, mk_lang_cpuid_register_id_e_ebx, 5);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(7, mk_lang_cpuid_register_id_e_ebx, 16);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(7, mk_lang_cpuid_register_id_e_ebx, 29);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_vl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(7, mk_lang_cpuid_register_id_e_ebx, 31);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_vaes(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_bit_set(7, mk_lang_cpuid_register_id_e_ecx, 9);
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha512(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	has = mk_lang_cpuid_has_leaf_07_sub_leaf_bit_set(1, mk_lang_cpuid_register_id_e_eax, 0);
	return has;
}


#elif mk_lang_compiler_is_at_least_gcc(4, 1) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_init(mk_lang_types_void_t) mk_lang_noexcept
{
	__builtin_cpu_init();
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_reset(mk_lang_types_void_t) mk_lang_noexcept
{
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("ssse3");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("sse4.1");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("popcnt");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aesni(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(6, 1)
	has = __builtin_cpu_supports("aes");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("avx");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("sse");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("sse2");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(4, 8)
	has = __builtin_cpu_supports("avx2");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(5, 1)
	has = __builtin_cpu_supports("avx512f");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(11, 1)
	has = __builtin_cpu_supports("sha");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_vl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(6, 1)
	has = __builtin_cpu_supports("avx512vl");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_vaes(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(11, 1)
	has = __builtin_cpu_supports("vaes");
	#else
	has = mk_lang_false;
	#endif
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha512(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	#if mk_lang_compiler_is_at_least_gcc(14, 0)
	has = __builtin_cpu_supports("sha512");
	#else
	has = mk_lang_false;
	#endif
	return has;
}


#else


#endif


#endif
