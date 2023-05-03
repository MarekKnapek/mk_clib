#ifndef mk_include_guard_win_kernel_files
#define mk_include_guard_win_kernel_files


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


enum mk_win_kernel_files_drive_type_e
{
	mk_win_kernel_files_drive_type_e_unknown     = 0,
	mk_win_kernel_files_drive_type_e_no_root_dir = 1,
	mk_win_kernel_files_drive_type_e_removable   = 2,
	mk_win_kernel_files_drive_type_e_fixed       = 3,
	mk_win_kernel_files_drive_type_e_remote      = 4,
	mk_win_kernel_files_drive_type_e_cdrom       = 5,
	mk_win_kernel_files_drive_type_e_ramdisk     = 6,
	mk_win_kernel_files_drive_type_e_dummy_end = 0
};
typedef enum mk_win_kernel_files_drive_type_e mk_win_kernel_files_drive_type_t;

enum mk_win_kernel_files_attribute_e
{
	mk_win_kernel_files_attribute_e_readonly              = 0x00000001ul,
	mk_win_kernel_files_attribute_e_hidden                = 0x00000002ul,
	mk_win_kernel_files_attribute_e_system                = 0x00000004ul,
	mk_win_kernel_files_attribute_e_unknown_3             = 0x00000008ul,
	mk_win_kernel_files_attribute_e_directory             = 0x00000010ul,
	mk_win_kernel_files_attribute_e_archive               = 0x00000020ul,
	mk_win_kernel_files_attribute_e_device                = 0x00000040ul,
	mk_win_kernel_files_attribute_e_normal                = 0x00000080ul,
	mk_win_kernel_files_attribute_e_temporary             = 0x00000100ul,
	mk_win_kernel_files_attribute_e_sparse_file           = 0x00000200ul,
	mk_win_kernel_files_attribute_e_reparse_point         = 0x00000400ul,
	mk_win_kernel_files_attribute_e_compressed            = 0x00000800ul,
	mk_win_kernel_files_attribute_e_offline               = 0x00001000ul,
	mk_win_kernel_files_attribute_e_not_content_indexed   = 0x00002000ul,
	mk_win_kernel_files_attribute_e_encrypted             = 0x00004000ul,
	mk_win_kernel_files_attribute_e_integrity_stream      = 0x00008000ul,
	mk_win_kernel_files_attribute_e_virtual               = 0x00010000ul,
	mk_win_kernel_files_attribute_e_no_scrub_data         = 0x00020000ul,
	mk_win_kernel_files_attribute_e_ea                    = 0x00040000ul,
	mk_win_kernel_files_attribute_e_recall_on_open        = 0x00040000ul, /* again */
	mk_win_kernel_files_attribute_e_pinned                = 0x00080000ul,
	mk_win_kernel_files_attribute_e_unpinned              = 0x00100000ul,
	mk_win_kernel_files_attribute_e_unknown_21            = 0x00200000ul,
	mk_win_kernel_files_attribute_e_recall_on_data_access = 0x00400000ul,
	mk_win_kernel_files_attribute_e_unknown_23            = 0x00800000ul,
	mk_win_kernel_files_attribute_e_unknown_24            = 0x01000000ul,
	mk_win_kernel_files_attribute_e_unknown_25            = 0x02000000ul,
	mk_win_kernel_files_attribute_e_unknown_26            = 0x04000000ul,
	mk_win_kernel_files_attribute_e_unknown_27            = 0x08000000ul,
	mk_win_kernel_files_attribute_e_unknown_28            = 0x10000000ul,
	mk_win_kernel_files_attribute_e_strictly_sequential   = 0x20000000ul,
	mk_win_kernel_files_attribute_e_unknown_30            = 0x40000000ul,
	mk_win_kernel_files_attribute_e_unknown_31            = 0x80000000ul,
	mk_win_kernel_files_attribute_e_dummy_end = 0
};
typedef enum mk_win_kernel_files_attribute_e mk_win_kernel_files_attribute_t;

#define mk_win_kernel_files_attribute_name_e_readonly              "read only"
#define mk_win_kernel_files_attribute_name_e_hidden                "hidden"
#define mk_win_kernel_files_attribute_name_e_system                "system"
#define mk_win_kernel_files_attribute_name_e_unknown_3             "unknown 3"
#define mk_win_kernel_files_attribute_name_e_directory             "directory"
#define mk_win_kernel_files_attribute_name_e_archive               "archive"
#define mk_win_kernel_files_attribute_name_e_device                "device"
#define mk_win_kernel_files_attribute_name_e_normal                "normal"
#define mk_win_kernel_files_attribute_name_e_temporary             "temporary"
#define mk_win_kernel_files_attribute_name_e_sparse_file           "sparse file"
#define mk_win_kernel_files_attribute_name_e_reparse_point         "reparse point"
#define mk_win_kernel_files_attribute_name_e_compressed            "compressed"
#define mk_win_kernel_files_attribute_name_e_offline               "offline"
#define mk_win_kernel_files_attribute_name_e_not_content_indexed   "not content indexed"
#define mk_win_kernel_files_attribute_name_e_encrypted             "encrypted"
#define mk_win_kernel_files_attribute_name_e_integrity_stream      "integrity stream"
#define mk_win_kernel_files_attribute_name_e_virtual               "virtual"
#define mk_win_kernel_files_attribute_name_e_no_scrub_data         "no scrub data"
#define mk_win_kernel_files_attribute_name_e_ea                    "extended attributes"
#define mk_win_kernel_files_attribute_name_e_pinned                "pinned"
#define mk_win_kernel_files_attribute_name_e_unpinned              "unpinned"
#define mk_win_kernel_files_attribute_name_e_unknown_21            "unknown 21"
#define mk_win_kernel_files_attribute_name_e_recall_on_data_access "recall on data access"
#define mk_win_kernel_files_attribute_name_e_unknown_23            "unknown 23"
#define mk_win_kernel_files_attribute_name_e_unknown_24            "unknown 24"
#define mk_win_kernel_files_attribute_name_e_unknown_25            "unknown 25"
#define mk_win_kernel_files_attribute_name_e_unknown_26            "unknown 26"
#define mk_win_kernel_files_attribute_name_e_unknown_27            "unknown 27"
#define mk_win_kernel_files_attribute_name_e_unknown_28            "unknown 28"
#define mk_win_kernel_files_attribute_name_e_strictly_sequential   "strictly sequential"
#define mk_win_kernel_files_attribute_name_e_unknown_30            "unknown 30"
#define mk_win_kernel_files_attribute_name_e_unknown_31            "unknown 31"


#define s_mk_win_kernel_files_max_path 260


struct mk_win_kernel_files_filetime_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_dword_t m_hi;
};
typedef struct mk_win_kernel_files_filetime_s mk_win_kernel_files_filetime_t;

#if defined _MSC_VER && _MSC_VER >= 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_kernel_files_a_find_data_s
{
	mk_win_base_dword_t m_attributes;
	mk_win_kernel_files_filetime_t m_created;
	mk_win_kernel_files_filetime_t m_accessed;
	mk_win_kernel_files_filetime_t m_written;
	mk_win_base_dword_t m_size_hi;
	mk_win_base_dword_t m_size_lo;
	mk_win_base_dword_t m_reserved_1;
	mk_win_base_dword_t m_reserved_2;
	mk_win_base_pchar_t m_name[s_mk_win_kernel_files_max_path];
	mk_win_base_pchar_t m_name_83[14];
};
typedef struct mk_win_kernel_files_a_find_data_s mk_win_kernel_files_a_find_data_t;
typedef mk_win_kernel_files_a_find_data_t const mk_win_kernel_files_a_find_data_ct;
typedef mk_win_kernel_files_a_find_data_t* mk_win_kernel_files_a_find_data_pt;
typedef mk_win_kernel_files_a_find_data_t const mk_win_kernel_files_a_find_data_ct;
typedef mk_win_kernel_files_a_find_data_t* mk_win_kernel_files_a_find_data_pt;
typedef mk_win_kernel_files_a_find_data_t const* mk_win_kernel_files_a_find_data_pct;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_far* mk_win_kernel_files_a_find_data_lpt;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_far const* mk_win_kernel_files_a_find_data_lpct;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_near* mk_win_kernel_files_a_find_data_npt;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_near const* mk_win_kernel_files_a_find_data_npct;
#if defined _MSC_VER && _MSC_VER >= 1935
#pragma warning(pop)
#endif

struct mk_win_kernel_files_w_find_data_s
{
	mk_win_base_dword_t m_attributes;
	mk_win_kernel_files_filetime_t m_created;
	mk_win_kernel_files_filetime_t m_accessed;
	mk_win_kernel_files_filetime_t m_written;
	mk_win_base_dword_t m_size_hi;
	mk_win_base_dword_t m_size_lo;
	mk_win_base_dword_t m_reserved_1;
	mk_win_base_dword_t m_reserved_2;
	mk_win_base_wchar_t m_name[s_mk_win_kernel_files_max_path];
	mk_win_base_wchar_t m_name_83[14];
};
typedef struct mk_win_kernel_files_w_find_data_s mk_win_kernel_files_w_find_data_t;
typedef mk_win_kernel_files_w_find_data_t const mk_win_kernel_files_w_find_data_ct;
typedef mk_win_kernel_files_w_find_data_t* mk_win_kernel_files_w_find_data_pt;
typedef mk_win_kernel_files_w_find_data_t const mk_win_kernel_files_w_find_data_ct;
typedef mk_win_kernel_files_w_find_data_t* mk_win_kernel_files_w_find_data_pt;
typedef mk_win_kernel_files_w_find_data_t const* mk_win_kernel_files_w_find_data_pct;
typedef mk_win_kernel_files_w_find_data_t mk_win_base_far* mk_win_kernel_files_w_find_data_lpt;
typedef mk_win_kernel_files_w_find_data_t mk_win_base_far const* mk_win_kernel_files_w_find_data_lpct;
typedef mk_win_kernel_files_w_find_data_t mk_win_base_near* mk_win_kernel_files_w_find_data_npt;
typedef mk_win_kernel_files_w_find_data_t mk_win_base_near const* mk_win_kernel_files_w_find_data_npct;

#if mk_win_tstring_enc == mk_win_tstring_enc_asci
#define mk_win_kernel_files_t_find_data_t mk_win_kernel_files_a_find_data_t
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
#define mk_win_kernel_files_t_find_data_t mk_win_kernel_files_a_find_data_t
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
#define mk_win_kernel_files_t_find_data_t mk_win_kernel_files_a_find_data_t
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
#define mk_win_kernel_files_t_find_data_t mk_win_kernel_files_w_find_data_t
#endif
typedef mk_win_kernel_files_t_find_data_t const mk_win_kernel_files_t_find_data_ct;
typedef mk_win_kernel_files_t_find_data_t* mk_win_kernel_files_t_find_data_pt;
typedef mk_win_kernel_files_t_find_data_t const mk_win_kernel_files_t_find_data_ct;
typedef mk_win_kernel_files_t_find_data_t* mk_win_kernel_files_t_find_data_pt;
typedef mk_win_kernel_files_t_find_data_t const* mk_win_kernel_files_t_find_data_pct;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_far* mk_win_kernel_files_t_find_data_lpt;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_far const* mk_win_kernel_files_t_find_data_lpct;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_near* mk_win_kernel_files_t_find_data_npt;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_near const* mk_win_kernel_files_t_find_data_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_a_get_drive_type(mk_win_base_pchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_find_first_file(mk_win_base_pchar_lpct const name, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_w_get_drive_type(mk_win_base_wchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_find_first_file(mk_win_base_wchar_lpct const name, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_t_get_drive_type(mk_win_tstring_tchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_t_find_first_file(mk_win_tstring_tchar_lpct const name, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_t_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_logical_drives(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_find_close(mk_win_base_handle_t const handle) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_files.c"
#endif
#endif
