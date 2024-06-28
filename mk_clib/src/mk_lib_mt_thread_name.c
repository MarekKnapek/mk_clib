#include "mk_lib_mt_thread_name.h"

#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpp.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lib_text_encoding.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_name_set_not(mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');

	((mk_lang_types_void_t)(name));
	return 0;
}

#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows

#include "mk_win_base.h"
#include "mk_win_kernel_thread.h"
#include "mk_win_kernel_thread_extra.h"

mk_lang_extern_c mk_win_base_dll_import mk_win_base_void_t mk_win_base_stdcall RaiseException(mk_win_base_dword_t const excode, mk_win_base_dword_t const exflags, mk_win_base_dword_t const args_count, mk_win_base_usize_lpct const args) mk_lang_noexcept;

#define mk_lib_mt_thread_name_continue_search      0
#define mk_lib_mt_thread_name_execute_handler      1
#define mk_lib_mt_thread_name_continue_execution (-1)

struct mk_lib_mt_thread_name_info_s
{
	mk_win_base_dword_t m_type;
	mk_win_base_pchar_lpct m_name;
	mk_win_base_dword_t m_tid;
	mk_win_base_dword_t m_flags;
};
typedef struct mk_lib_mt_thread_name_info_s mk_lib_mt_thread_name_info_t;
typedef mk_lib_mt_thread_name_info_t const mk_lib_mt_thread_name_info_ct;
typedef mk_lib_mt_thread_name_info_t* mk_lib_mt_thread_name_info_pt;
typedef mk_lib_mt_thread_name_info_t const* mk_lib_mt_thread_name_info_pct;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_name_set_win_seh(mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	#if mk_lang_msvc_full_ver != 0
	mk_lib_mt_thread_name_info_t info;
	mk_win_base_dword_t excode;

	#if mk_lang_bitness == mk_lang_bitness_32
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_type) == 0);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_name) == 4);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_tid) == 8);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_flags) == 12);
	mk_lang_static_assert(sizeof(mk_lib_mt_thread_name_info_t) % sizeof(mk_win_base_usize_t) == 0);
	#elif mk_lang_bitness == mk_lang_bitness_64
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_type) == 0);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_name) == 8);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_tid) == 16);
	mk_lang_static_assert(mk_lang_offsetof(mk_lib_mt_thread_name_info_t, m_flags) == 20);
	mk_lang_static_assert(sizeof(mk_lib_mt_thread_name_info_t) % sizeof(mk_win_base_usize_t) == 0);
	#else
	#error xxxxxxxxxx
	#endif

	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');

	info.m_type = 0x1000;
	info.m_name = name;
	info.m_tid = ((mk_win_base_dword_t)(-1));
	info.m_flags = 0;
	excode = ((mk_win_base_dword_t)(0x406d1388ul));
	__try
	{
		RaiseException(excode, 0, sizeof(info) / sizeof(mk_win_base_usize_t), ((mk_win_base_usize_lpct)(&info)));
	}
	__except(mk_lib_mt_thread_name_execute_handler)
	{
	}
	return 0;
	#else
	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');

	((mk_lang_types_void_t)(name));
	return 0;
	#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_name_set_win_des(mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_usize_t lenus;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;
	mk_win_base_wchar_t namew[16];
	mk_lang_types_sint_t olen;
	mk_lang_types_bool_t b;
	mk_win_base_hresult_t hr;

	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');

	lenus = mk_lang_strlen_n_fn(&name[0]); mk_lang_assert(lenus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	len = ((mk_lang_types_sint_t)(lenus));
	err = mk_lib_text_encoding_asci_to_wide(&name[0], len, &namew[0], mk_lang_countof(namew) - 1, &olen); mk_lang_assert(err == 0);
	mk_lang_assert(olen <= mk_lang_countof(namew) - 1);
	namew[olen] = L'\0';
	b = mk_win_kernel_thread_extra_description_set(mk_win_kernel_thread_get_current(), &namew[0], &hr); if(b){ mk_lang_check_return(hr >= 0); }
	return 0;
}

#elif mk_lang_platform == mk_lang_platform_linux || mk_lang_platform == mk_lang_platform_portable

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_name_set_win_portable(mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');

	((mk_lang_types_void_t)(name));
	return 0;
}

#else

#error xxxxxxxxxx todo

#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_name_set(mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
#if defined NDEBUG
	return mk_lib_mt_thread_name_set_not(name);
#else
#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
	mk_lang_types_sint_t err;
	err = mk_lib_mt_thread_name_set_win_seh(name); mk_lang_check_rereturn(err);
	err = mk_lib_mt_thread_name_set_win_des(name); mk_lang_check_rereturn(err);
	return 0;
#elif mk_lang_platform == mk_lang_platform_linux || mk_lang_platform == mk_lang_platform_portable
	return mk_lib_mt_thread_name_set_win_portable(name);
#else
	#error xxxxxxxxxx todo
#endif
#endif
}
