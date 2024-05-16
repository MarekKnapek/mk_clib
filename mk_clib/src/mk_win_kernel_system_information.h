#ifndef mk_include_guard_mk_win_kernel_system_information
#define mk_include_guard_mk_win_kernel_system_information


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


struct mk_win_kernel_system_information_pa_s
{
	mk_win_base_word_t m_processor_architecture;
	mk_win_base_word_t m_reserved;
};
typedef struct mk_win_kernel_system_information_pa_s mk_win_kernel_system_information_pa_t;
typedef mk_win_kernel_system_information_pa_t const mk_win_kernel_system_information_pa_ct;
typedef mk_win_kernel_system_information_pa_t* mk_win_kernel_system_information_pa_pt;
typedef mk_win_kernel_system_information_pa_t const* mk_win_kernel_system_information_pa_pct;

union mk_win_kernel_system_information_oempa_u
{
	mk_win_base_dword_t m_oem_id;
	mk_win_kernel_system_information_pa_t m_pa;
};
typedef union mk_win_kernel_system_information_oempa_u mk_win_kernel_system_information_oempa_t;
typedef mk_win_kernel_system_information_oempa_t const mk_win_kernel_system_information_oempa_ct;
typedef mk_win_kernel_system_information_oempa_t* mk_win_kernel_system_information_oempa_pt;
typedef mk_win_kernel_system_information_oempa_t const* mk_win_kernel_system_information_oempa_pct;

struct mk_win_kernel_system_information_s
{
	mk_win_kernel_system_information_oempa_t m_oempa;
	mk_win_base_dword_t m_page_size;
	mk_win_base_void_lpt m_minimum_application_address;
	mk_win_base_void_lpt m_maximum_application_address;
	mk_win_base_uintptr_t m_active_processor_mask;
	mk_win_base_dword_t m_number_of_processors;
	mk_win_base_dword_t m_processor_type;
	mk_win_base_dword_t m_allocation_granularity;
	mk_win_base_word_t m_processor_level;
	mk_win_base_word_t m_processor_revision;
};
typedef struct mk_win_kernel_system_information_s mk_win_kernel_system_information_t;
typedef mk_win_kernel_system_information_t const mk_win_kernel_system_information_ct;
typedef mk_win_kernel_system_information_t* mk_win_kernel_system_information_pt;
typedef mk_win_kernel_system_information_t const* mk_win_kernel_system_information_pct;

enum mk_win_kernel_system_information_paid_e
{
	mk_win_kernel_system_information_paid_e_intel          = ((mk_win_base_ushort_t)( 0ul)),
	mk_win_kernel_system_information_paid_e_mips           = ((mk_win_base_ushort_t)( 1ul)),
	mk_win_kernel_system_information_paid_e_alpha          = ((mk_win_base_ushort_t)( 2ul)),
	mk_win_kernel_system_information_paid_e_ppc            = ((mk_win_base_ushort_t)( 3ul)),
	mk_win_kernel_system_information_paid_e_shx            = ((mk_win_base_ushort_t)( 4ul)),
	mk_win_kernel_system_information_paid_e_arm            = ((mk_win_base_ushort_t)( 5ul)),
	mk_win_kernel_system_information_paid_e_ia64           = ((mk_win_base_ushort_t)( 6ul)),
	mk_win_kernel_system_information_paid_e_alpha64        = ((mk_win_base_ushort_t)( 7ul)),
	mk_win_kernel_system_information_paid_e_msil           = ((mk_win_base_ushort_t)( 8ul)),
	mk_win_kernel_system_information_paid_e_amd64          = ((mk_win_base_ushort_t)( 9ul)),
	mk_win_kernel_system_information_paid_e_ia32_on_win64  = ((mk_win_base_ushort_t)(10ul)),
	mk_win_kernel_system_information_paid_e_neutral        = ((mk_win_base_ushort_t)(11ul)),
	mk_win_kernel_system_information_paid_e_arm64          = ((mk_win_base_ushort_t)(12ul)),
	mk_win_kernel_system_information_paid_e_arm32_on_win64 = ((mk_win_base_ushort_t)(13ul)),
	mk_win_kernel_system_information_paid_e_ia32_on_arm64  = ((mk_win_base_ushort_t)(14ul)),
	mk_win_kernel_system_information_paid_e_unknown = ((mk_win_base_ushort_t)(0xfffful))
};
typedef enum mk_win_kernel_system_information_paid_e mk_win_kernel_system_information_paid_t;
typedef mk_win_kernel_system_information_paid_t const mk_win_kernel_system_information_paid_ct;
typedef mk_win_kernel_system_information_paid_t* mk_win_kernel_system_information_paid_pt;
typedef mk_win_kernel_system_information_paid_t const* mk_win_kernel_system_information_paid_pct;

enum mk_win_kernel_system_information_ptid_e
{
	mk_win_kernel_system_information_ptid_e_intel_386     = ((mk_win_base_dword_t)(   386ul)),
	mk_win_kernel_system_information_ptid_e_intel_486     = ((mk_win_base_dword_t)(   486ul)),
	mk_win_kernel_system_information_ptid_e_intel_pentium = ((mk_win_base_dword_t)(   586ul)),
	mk_win_kernel_system_information_ptid_e_intel_ia64    = ((mk_win_base_dword_t)(  2200ul)),
	mk_win_kernel_system_information_ptid_e_amd_x8664     = ((mk_win_base_dword_t)(  8664ul)),
	mk_win_kernel_system_information_ptid_e_mips_r4000    = ((mk_win_base_dword_t)(  4000ul)),
	mk_win_kernel_system_information_ptid_e_alpha_21064   = ((mk_win_base_dword_t)( 21064ul)),
	mk_win_kernel_system_information_ptid_e_ppc_601       = ((mk_win_base_dword_t)(   601ul)),
	mk_win_kernel_system_information_ptid_e_ppc_603       = ((mk_win_base_dword_t)(   603ul)),
	mk_win_kernel_system_information_ptid_e_ppc_604       = ((mk_win_base_dword_t)(   604ul)),
	mk_win_kernel_system_information_ptid_e_ppc_620       = ((mk_win_base_dword_t)(   620ul)),
	mk_win_kernel_system_information_ptid_e_hitachi_sh3   = ((mk_win_base_dword_t)( 10003ul)),
	mk_win_kernel_system_information_ptid_e_hitachi_sh3e  = ((mk_win_base_dword_t)( 10004ul)),
	mk_win_kernel_system_information_ptid_e_hitachi_sh4   = ((mk_win_base_dword_t)( 10005ul)),
	mk_win_kernel_system_information_ptid_e_motorola_821  = ((mk_win_base_dword_t)(   821ul)),
	mk_win_kernel_system_information_ptid_e_shx_sh3       = ((mk_win_base_dword_t)(   103ul)),
	mk_win_kernel_system_information_ptid_e_shx_sh4       = ((mk_win_base_dword_t)(   104ul)),
	mk_win_kernel_system_information_ptid_e_strongarm     = ((mk_win_base_dword_t)(  2577ul)),
	mk_win_kernel_system_information_ptid_e_arm720        = ((mk_win_base_dword_t)(  1824ul)),
	mk_win_kernel_system_information_ptid_e_arm820        = ((mk_win_base_dword_t)(  2080ul)),
	mk_win_kernel_system_information_ptid_e_arm920        = ((mk_win_base_dword_t)(  2336ul)),
	mk_win_kernel_system_information_ptid_e_arm_7tdmi     = ((mk_win_base_dword_t)( 70001ul)),
	mk_win_kernel_system_information_ptid_e_optil         = ((mk_win_base_dword_t)(0x494ful)),
	mk_win_kernel_system_information_ptid_e_dummy
};
typedef enum mk_win_kernel_system_information_ptid_e mk_win_kernel_system_information_ptid_t;
typedef mk_win_kernel_system_information_ptid_t const mk_win_kernel_system_information_ptid_ct;
typedef mk_win_kernel_system_information_ptid_t* mk_win_kernel_system_information_ptid_pt;
typedef mk_win_kernel_system_information_ptid_t const* mk_win_kernel_system_information_ptid_pct;


mk_lang_jumbo mk_win_base_void_t mk_win_kernel_system_information_get(mk_win_kernel_system_information_pt const info) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_system_information.c"
#endif
#endif
