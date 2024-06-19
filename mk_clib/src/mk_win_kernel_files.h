#ifndef mk_include_guard_mk_win_kernel_files
#define mk_include_guard_mk_win_kernel_files


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_time.h"
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
	mk_win_kernel_files_drive_type_e_dummy_end
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
	mk_win_kernel_files_attribute_e_dummy_end
};
typedef enum mk_win_kernel_files_attribute_e mk_win_kernel_files_attribute_t;

#define mk_win_kernel_files_attribute_namea_e_readonly              "read only"
#define mk_win_kernel_files_attribute_namea_e_hidden                "hidden"
#define mk_win_kernel_files_attribute_namea_e_system                "system"
#define mk_win_kernel_files_attribute_namea_e_unknown_3             "unknown 3"
#define mk_win_kernel_files_attribute_namea_e_directory             "directory"
#define mk_win_kernel_files_attribute_namea_e_archive               "archive"
#define mk_win_kernel_files_attribute_namea_e_device                "device"
#define mk_win_kernel_files_attribute_namea_e_normal                "normal"
#define mk_win_kernel_files_attribute_namea_e_temporary             "temporary"
#define mk_win_kernel_files_attribute_namea_e_sparse_file           "sparse file"
#define mk_win_kernel_files_attribute_namea_e_reparse_point         "reparse point"
#define mk_win_kernel_files_attribute_namea_e_compressed            "compressed"
#define mk_win_kernel_files_attribute_namea_e_offline               "offline"
#define mk_win_kernel_files_attribute_namea_e_not_content_indexed   "not content indexed"
#define mk_win_kernel_files_attribute_namea_e_encrypted             "encrypted"
#define mk_win_kernel_files_attribute_namea_e_integrity_stream      "integrity stream"
#define mk_win_kernel_files_attribute_namea_e_virtual               "virtual"
#define mk_win_kernel_files_attribute_namea_e_no_scrub_data         "no scrub data"
#define mk_win_kernel_files_attribute_namea_e_ea                    "extended attributes"
#define mk_win_kernel_files_attribute_namea_e_pinned                "pinned"
#define mk_win_kernel_files_attribute_namea_e_unpinned              "unpinned"
#define mk_win_kernel_files_attribute_namea_e_unknown_21            "unknown 21"
#define mk_win_kernel_files_attribute_namea_e_recall_on_data_access "recall on data access"
#define mk_win_kernel_files_attribute_namea_e_unknown_23            "unknown 23"
#define mk_win_kernel_files_attribute_namea_e_unknown_24            "unknown 24"
#define mk_win_kernel_files_attribute_namea_e_unknown_25            "unknown 25"
#define mk_win_kernel_files_attribute_namea_e_unknown_26            "unknown 26"
#define mk_win_kernel_files_attribute_namea_e_unknown_27            "unknown 27"
#define mk_win_kernel_files_attribute_namea_e_unknown_28            "unknown 28"
#define mk_win_kernel_files_attribute_namea_e_strictly_sequential   "strictly sequential"
#define mk_win_kernel_files_attribute_namea_e_unknown_30            "unknown 30"
#define mk_win_kernel_files_attribute_namea_e_unknown_31            "unknown 31"

#define mk_win_kernel_files_attribute_namew_e_readonly              L"read only"
#define mk_win_kernel_files_attribute_namew_e_hidden                L"hidden"
#define mk_win_kernel_files_attribute_namew_e_system                L"system"
#define mk_win_kernel_files_attribute_namew_e_unknown_3             L"unknown 3"
#define mk_win_kernel_files_attribute_namew_e_directory             L"directory"
#define mk_win_kernel_files_attribute_namew_e_archive               L"archive"
#define mk_win_kernel_files_attribute_namew_e_device                L"device"
#define mk_win_kernel_files_attribute_namew_e_normal                L"normal"
#define mk_win_kernel_files_attribute_namew_e_temporary             L"temporary"
#define mk_win_kernel_files_attribute_namew_e_sparse_file           L"sparse file"
#define mk_win_kernel_files_attribute_namew_e_reparse_point         L"reparse point"
#define mk_win_kernel_files_attribute_namew_e_compressed            L"compressed"
#define mk_win_kernel_files_attribute_namew_e_offline               L"offline"
#define mk_win_kernel_files_attribute_namew_e_not_content_indexed   L"not content indexed"
#define mk_win_kernel_files_attribute_namew_e_encrypted             L"encrypted"
#define mk_win_kernel_files_attribute_namew_e_integrity_stream      L"integrity stream"
#define mk_win_kernel_files_attribute_namew_e_virtual               L"virtual"
#define mk_win_kernel_files_attribute_namew_e_no_scrub_data         L"no scrub data"
#define mk_win_kernel_files_attribute_namew_e_ea                    L"extended attributes"
#define mk_win_kernel_files_attribute_namew_e_pinned                L"pinned"
#define mk_win_kernel_files_attribute_namew_e_unpinned              L"unpinned"
#define mk_win_kernel_files_attribute_namew_e_unknown_21            L"unknown 21"
#define mk_win_kernel_files_attribute_namew_e_recall_on_data_access L"recall on data access"
#define mk_win_kernel_files_attribute_namew_e_unknown_23            L"unknown 23"
#define mk_win_kernel_files_attribute_namew_e_unknown_24            L"unknown 24"
#define mk_win_kernel_files_attribute_namew_e_unknown_25            L"unknown 25"
#define mk_win_kernel_files_attribute_namew_e_unknown_26            L"unknown 26"
#define mk_win_kernel_files_attribute_namew_e_unknown_27            L"unknown 27"
#define mk_win_kernel_files_attribute_namew_e_unknown_28            L"unknown 28"
#define mk_win_kernel_files_attribute_namew_e_strictly_sequential   L"strictly sequential"
#define mk_win_kernel_files_attribute_namew_e_unknown_30            L"unknown 30"
#define mk_win_kernel_files_attribute_namew_e_unknown_31            L"unknown 31"

#if mk_win_tstring_enc == mk_win_tstring_enc_wide
#define mk_win_kernel_files_attribute_namet_e_readonly              mk_win_kernel_files_attribute_namew_e_readonly
#define mk_win_kernel_files_attribute_namet_e_hidden                mk_win_kernel_files_attribute_namew_e_hidden
#define mk_win_kernel_files_attribute_namet_e_system                mk_win_kernel_files_attribute_namew_e_system
#define mk_win_kernel_files_attribute_namet_e_unknown_3             mk_win_kernel_files_attribute_namew_e_unknown_3
#define mk_win_kernel_files_attribute_namet_e_directory             mk_win_kernel_files_attribute_namew_e_directory
#define mk_win_kernel_files_attribute_namet_e_archive               mk_win_kernel_files_attribute_namew_e_archive
#define mk_win_kernel_files_attribute_namet_e_device                mk_win_kernel_files_attribute_namew_e_device
#define mk_win_kernel_files_attribute_namet_e_normal                mk_win_kernel_files_attribute_namew_e_normal
#define mk_win_kernel_files_attribute_namet_e_temporary             mk_win_kernel_files_attribute_namew_e_temporary
#define mk_win_kernel_files_attribute_namet_e_sparse_file           mk_win_kernel_files_attribute_namew_e_sparse_file
#define mk_win_kernel_files_attribute_namet_e_reparse_point         mk_win_kernel_files_attribute_namew_e_reparse_point
#define mk_win_kernel_files_attribute_namet_e_compressed            mk_win_kernel_files_attribute_namew_e_compressed
#define mk_win_kernel_files_attribute_namet_e_offline               mk_win_kernel_files_attribute_namew_e_offline
#define mk_win_kernel_files_attribute_namet_e_not_content_indexed   mk_win_kernel_files_attribute_namew_e_not_content_indexed
#define mk_win_kernel_files_attribute_namet_e_encrypted             mk_win_kernel_files_attribute_namew_e_encrypted
#define mk_win_kernel_files_attribute_namet_e_integrity_stream      mk_win_kernel_files_attribute_namew_e_integrity_stream
#define mk_win_kernel_files_attribute_namet_e_virtual               mk_win_kernel_files_attribute_namew_e_virtual
#define mk_win_kernel_files_attribute_namet_e_no_scrub_data         mk_win_kernel_files_attribute_namew_e_no_scrub_data
#define mk_win_kernel_files_attribute_namet_e_ea                    mk_win_kernel_files_attribute_namew_e_ea
#define mk_win_kernel_files_attribute_namet_e_pinned                mk_win_kernel_files_attribute_namew_e_pinned
#define mk_win_kernel_files_attribute_namet_e_unpinned              mk_win_kernel_files_attribute_namew_e_unpinned
#define mk_win_kernel_files_attribute_namet_e_unknown_21            mk_win_kernel_files_attribute_namew_e_unknown_21
#define mk_win_kernel_files_attribute_namet_e_recall_on_data_access mk_win_kernel_files_attribute_namew_e_recall_on_data_access
#define mk_win_kernel_files_attribute_namet_e_unknown_23            mk_win_kernel_files_attribute_namew_e_unknown_23
#define mk_win_kernel_files_attribute_namet_e_unknown_24            mk_win_kernel_files_attribute_namew_e_unknown_24
#define mk_win_kernel_files_attribute_namet_e_unknown_25            mk_win_kernel_files_attribute_namew_e_unknown_25
#define mk_win_kernel_files_attribute_namet_e_unknown_26            mk_win_kernel_files_attribute_namew_e_unknown_26
#define mk_win_kernel_files_attribute_namet_e_unknown_27            mk_win_kernel_files_attribute_namew_e_unknown_27
#define mk_win_kernel_files_attribute_namet_e_unknown_28            mk_win_kernel_files_attribute_namew_e_unknown_28
#define mk_win_kernel_files_attribute_namet_e_strictly_sequential   mk_win_kernel_files_attribute_namew_e_strictly_sequential
#define mk_win_kernel_files_attribute_namet_e_unknown_30            mk_win_kernel_files_attribute_namew_e_unknown_30
#define mk_win_kernel_files_attribute_namet_e_unknown_31            mk_win_kernel_files_attribute_namew_e_unknown_31
#else
#define mk_win_kernel_files_attribute_namet_e_readonly              mk_win_kernel_files_attribute_namea_e_readonly
#define mk_win_kernel_files_attribute_namet_e_hidden                mk_win_kernel_files_attribute_namea_e_hidden
#define mk_win_kernel_files_attribute_namet_e_system                mk_win_kernel_files_attribute_namea_e_system
#define mk_win_kernel_files_attribute_namet_e_unknown_3             mk_win_kernel_files_attribute_namea_e_unknown_3
#define mk_win_kernel_files_attribute_namet_e_directory             mk_win_kernel_files_attribute_namea_e_directory
#define mk_win_kernel_files_attribute_namet_e_archive               mk_win_kernel_files_attribute_namea_e_archive
#define mk_win_kernel_files_attribute_namet_e_device                mk_win_kernel_files_attribute_namea_e_device
#define mk_win_kernel_files_attribute_namet_e_normal                mk_win_kernel_files_attribute_namea_e_normal
#define mk_win_kernel_files_attribute_namet_e_temporary             mk_win_kernel_files_attribute_namea_e_temporary
#define mk_win_kernel_files_attribute_namet_e_sparse_file           mk_win_kernel_files_attribute_namea_e_sparse_file
#define mk_win_kernel_files_attribute_namet_e_reparse_point         mk_win_kernel_files_attribute_namea_e_reparse_point
#define mk_win_kernel_files_attribute_namet_e_compressed            mk_win_kernel_files_attribute_namea_e_compressed
#define mk_win_kernel_files_attribute_namet_e_offline               mk_win_kernel_files_attribute_namea_e_offline
#define mk_win_kernel_files_attribute_namet_e_not_content_indexed   mk_win_kernel_files_attribute_namea_e_not_content_indexed
#define mk_win_kernel_files_attribute_namet_e_encrypted             mk_win_kernel_files_attribute_namea_e_encrypted
#define mk_win_kernel_files_attribute_namet_e_integrity_stream      mk_win_kernel_files_attribute_namea_e_integrity_stream
#define mk_win_kernel_files_attribute_namet_e_virtual               mk_win_kernel_files_attribute_namea_e_virtual
#define mk_win_kernel_files_attribute_namet_e_no_scrub_data         mk_win_kernel_files_attribute_namea_e_no_scrub_data
#define mk_win_kernel_files_attribute_namet_e_ea                    mk_win_kernel_files_attribute_namea_e_ea
#define mk_win_kernel_files_attribute_namet_e_pinned                mk_win_kernel_files_attribute_namea_e_pinned
#define mk_win_kernel_files_attribute_namet_e_unpinned              mk_win_kernel_files_attribute_namea_e_unpinned
#define mk_win_kernel_files_attribute_namet_e_unknown_21            mk_win_kernel_files_attribute_namea_e_unknown_21
#define mk_win_kernel_files_attribute_namet_e_recall_on_data_access mk_win_kernel_files_attribute_namea_e_recall_on_data_access
#define mk_win_kernel_files_attribute_namet_e_unknown_23            mk_win_kernel_files_attribute_namea_e_unknown_23
#define mk_win_kernel_files_attribute_namet_e_unknown_24            mk_win_kernel_files_attribute_namea_e_unknown_24
#define mk_win_kernel_files_attribute_namet_e_unknown_25            mk_win_kernel_files_attribute_namea_e_unknown_25
#define mk_win_kernel_files_attribute_namet_e_unknown_26            mk_win_kernel_files_attribute_namea_e_unknown_26
#define mk_win_kernel_files_attribute_namet_e_unknown_27            mk_win_kernel_files_attribute_namea_e_unknown_27
#define mk_win_kernel_files_attribute_namet_e_unknown_28            mk_win_kernel_files_attribute_namea_e_unknown_28
#define mk_win_kernel_files_attribute_namet_e_strictly_sequential   mk_win_kernel_files_attribute_namea_e_strictly_sequential
#define mk_win_kernel_files_attribute_namet_e_unknown_30            mk_win_kernel_files_attribute_namea_e_unknown_30
#define mk_win_kernel_files_attribute_namet_e_unknown_31            mk_win_kernel_files_attribute_namea_e_unknown_31
#endif

enum mk_win_kernel_files_create_e
{
	mk_win_kernel_files_create_e_create_new        = 1,
	mk_win_kernel_files_create_e_create_always     = 2,
	mk_win_kernel_files_create_e_open_existing     = 3,
	mk_win_kernel_files_create_e_open_always       = 4,
	mk_win_kernel_files_create_e_truncate_existing = 5,
	mk_win_kernel_files_create_e_dummy_end
};
typedef enum mk_win_kernel_files_create_e mk_win_kernel_files_create_t;

enum mk_win_kernel_files_flag_e
{
	mk_win_kernel_files_flag_e_none                  = 0x00000000ul,
	mk_win_kernel_files_flag_e_open_requiring_oplock = 0x00040000ul,
	mk_win_kernel_files_flag_e_first_pipe_instance   = 0x00080000ul,
	mk_win_kernel_files_flag_e_open_no_recall        = 0x00100000ul,
	mk_win_kernel_files_flag_e_open_reparse_point    = 0x00200000ul,
	mk_win_kernel_files_flag_e_session_aware         = 0x00800000ul,
	mk_win_kernel_files_flag_e_posix_semantics       = 0x01000000ul,
	mk_win_kernel_files_flag_e_backup_semantics      = 0x02000000ul,
	mk_win_kernel_files_flag_e_delete_on_close       = 0x04000000ul,
	mk_win_kernel_files_flag_e_sequential_scan       = 0x08000000ul,
	mk_win_kernel_files_flag_e_random_access         = 0x10000000ul,
	mk_win_kernel_files_flag_e_no_buffering          = 0x20000000ul,
	mk_win_kernel_files_flag_e_overlapped            = 0x40000000ul,
	mk_win_kernel_files_flag_e_write_through         = 0x80000000ul,
	mk_win_kernel_files_flag_e_dummy_end
};
typedef enum mk_win_kernel_files_flag_e mk_win_kernel_files_flag_t;

enum mk_win_kernel_files_share_e
{
	mk_win_kernel_files_share_e_read   = 0x00000001ul,
	mk_win_kernel_files_share_e_write  = 0x00000002ul,
	mk_win_kernel_files_share_e_delete = 0x00000004ul,
	mk_win_kernel_files_share_e_dummy_end
};
typedef enum mk_win_kernel_files_share_e mk_win_kernel_files_share_t;

enum mk_win_kernel_files_sqos_e
{
	mk_win_kernel_files_sqos_e_anonymous        = 0x00000000ul,
	mk_win_kernel_files_sqos_e_identification   = 0x00010000ul,
	mk_win_kernel_files_sqos_e_impersonation    = 0x00020000ul,
	mk_win_kernel_files_sqos_e_delegation       = 0x00030000ul,
	mk_win_kernel_files_sqos_e_context_tracking = 0x00040000ul,
	mk_win_kernel_files_sqos_e_effective_only   = 0x00080000ul,
	mk_win_kernel_files_sqos_e_sqos_present     = 0x00100000ul,
	mk_win_kernel_files_sqos_e_dummy_end
};
typedef enum mk_win_kernel_files_sqos_e mk_win_kernel_files_sqos_t;

enum mk_win_kernel_files_move_method_e
{
	mk_win_kernel_files_move_method_e_begin   = 0,
	mk_win_kernel_files_move_method_e_current = 1,
	mk_win_kernel_files_move_method_e_end     = 2,
	mk_win_kernel_files_move_method_e_dummy_end
};
typedef enum mk_win_kernel_files_move_method_e mk_win_kernel_files_move_method_t;

enum mk_win_kernel_files_file_type_e
{
	mk_win_kernel_files_file_type_e_unknown = 0x0000ul,
	mk_win_kernel_files_file_type_e_disk    = 0x0001ul,
	mk_win_kernel_files_file_type_e_char    = 0x0002ul,
	mk_win_kernel_files_file_type_e_pipe    = 0x0003ul,
	mk_win_kernel_files_file_type_e_remote  = 0x8000ul,
	mk_win_kernel_files_file_type_e_dummy_end
};
typedef enum mk_win_kernel_files_file_type_e mk_win_kernel_files_file_type_t;


#define s_mk_win_kernel_files_max_path 260
#define s_mk_win_kernel_files_invalid_file_size ((mk_win_base_dword_t)(0xfffffffful))
#define s_mk_win_kernel_files_invalid_set_file_pointer ((mk_win_base_dword_t)(0xfffffffful))


struct mk_win_kernel_files_a_find_data_s
{
	mk_win_base_dword_t m_attributes;
	mk_win_kernel_time_file_time_t m_created;
	mk_win_kernel_time_file_time_t m_accessed;
	mk_win_kernel_time_file_time_t m_written;
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
typedef mk_win_kernel_files_a_find_data_t const* mk_win_kernel_files_a_find_data_pct;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_far* mk_win_kernel_files_a_find_data_lpt;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_far const* mk_win_kernel_files_a_find_data_lpct;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_near* mk_win_kernel_files_a_find_data_npt;
typedef mk_win_kernel_files_a_find_data_t mk_win_base_near const* mk_win_kernel_files_a_find_data_npct;

struct mk_win_kernel_files_w_find_data_s
{
	mk_win_base_dword_t m_attributes;
	mk_win_kernel_time_file_time_t m_created;
	mk_win_kernel_time_file_time_t m_accessed;
	mk_win_kernel_time_file_time_t m_written;
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
typedef mk_win_kernel_files_t_find_data_t const* mk_win_kernel_files_t_find_data_pct;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_far* mk_win_kernel_files_t_find_data_lpt;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_far const* mk_win_kernel_files_t_find_data_lpct;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_near* mk_win_kernel_files_t_find_data_npt;
typedef mk_win_kernel_files_t_find_data_t mk_win_base_near const* mk_win_kernel_files_t_find_data_npct;

struct mk_win_kernel_files_overlapped_s
{
	mk_win_base_uintptr_t m_internal_lo;
	mk_win_base_uintptr_t m_internal_hi;
	mk_win_base_dword_t m_offset_lo;
	mk_win_base_dword_t m_offset_hi;
	mk_win_base_handle_t m_event;
};
typedef struct mk_win_kernel_files_overlapped_s mk_win_kernel_files_overlapped_t;
typedef mk_win_kernel_files_overlapped_t const mk_win_kernel_files_overlapped_ct;
typedef mk_win_kernel_files_overlapped_t* mk_win_kernel_files_overlapped_pt;
typedef mk_win_kernel_files_overlapped_t const* mk_win_kernel_files_overlapped_pct;
typedef mk_win_kernel_files_overlapped_t mk_win_base_far* mk_win_kernel_files_overlapped_lpt;
typedef mk_win_kernel_files_overlapped_t mk_win_base_far const* mk_win_kernel_files_overlapped_lpct;
typedef mk_win_kernel_files_overlapped_t mk_win_base_near* mk_win_kernel_files_overlapped_npt;
typedef mk_win_kernel_files_overlapped_t mk_win_base_near const* mk_win_kernel_files_overlapped_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_a_get_current_directory(mk_win_base_dword_t const len, mk_win_base_pchar_pt const buf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_a_get_drive_type(mk_win_base_pchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_find_first_file(mk_win_base_pchar_lpct const name, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_create_file(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_get_disk_free_space(mk_win_base_pchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_w_get_current_directory(mk_win_base_dword_t const len, mk_win_base_wchar_pt const buf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_w_get_drive_type(mk_win_base_wchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_find_first_file(mk_win_base_wchar_lpct const name, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_create_file(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_get_disk_free_space(mk_win_base_wchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_t_get_drive_type(mk_win_tstring_tchar_lpct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_t_find_first_file(mk_win_tstring_tchar_lpct const name, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_t_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_t_create_file(mk_win_tstring_tchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_t_get_disk_free_space(mk_win_tstring_tchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_logical_drives(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_find_close(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_read_file(mk_win_base_handle_t const handle, mk_win_base_void_lpt const buffer, mk_win_base_dword_t const bytes_requested, mk_win_base_dword_lpt const bytes_read, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_write_file(mk_win_base_handle_t const handle, mk_win_base_void_lpct const buffer, mk_win_base_dword_t const bytes_to_write, mk_win_base_dword_lpt const bytes_written, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_file_size(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const file_size_hi) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_set_file_pointer(mk_win_base_handle_t const handle, mk_win_base_slong_t const distance_lo, mk_win_base_slong_lpt const distance_hi, mk_win_base_dword_t const move_method) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_set_end_of_file(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_file_type(mk_win_base_handle_t const handle) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_files.c"
#endif
#endif
