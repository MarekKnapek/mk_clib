#ifndef include_guard_mk_win_advapi_base
#define include_guard_mk_win_advapi_base


#include "mk_lang_jumbo.h"
#include "mk_win_base.h"


struct mk_win_advapi_base_security_attributes_s
{
	mk_win_base_dword_t m_size;
	mk_win_base_void_lpt m_security_descriptor;
	mk_win_base_bool_t m_inheritable;
};
typedef struct mk_win_advapi_base_security_attributes_s mk_win_advapi_base_security_attributes_t;
typedef mk_win_advapi_base_security_attributes_t const mk_win_advapi_base_security_attributes_ct;
typedef mk_win_advapi_base_security_attributes_t* mk_win_advapi_base_security_attributes_pt;
typedef mk_win_advapi_base_security_attributes_t const* mk_win_advapi_base_security_attributes_pct;
typedef mk_win_advapi_base_security_attributes_t mk_win_base_far* mk_win_advapi_base_security_attributes_lpt;
typedef mk_win_advapi_base_security_attributes_t mk_win_base_far const* mk_win_advapi_base_security_attributes_lpct;
typedef mk_win_advapi_base_security_attributes_t mk_win_base_near* mk_win_advapi_base_security_attributes_npt;
typedef mk_win_advapi_base_security_attributes_t mk_win_base_near const* mk_win_advapi_base_security_attributes_npct;


enum mk_win_advapi_base_right_specific_file_e
{
	mk_win_advapi_base_right_specific_file_e_read_data        = 0x00000001ul,
	mk_win_advapi_base_right_specific_file_e_write_data       = 0x00000002ul,
	mk_win_advapi_base_right_specific_file_e_append_data      = 0x00000004ul,
	mk_win_advapi_base_right_specific_file_e_read_ea          = 0x00000008ul,
	mk_win_advapi_base_right_specific_file_e_write_ea         = 0x00000010ul,
	mk_win_advapi_base_right_specific_file_e_execute          = 0x00000020ul,
	mk_win_advapi_base_right_specific_file_e_unknown_6        = 0x00000040ul,
	mk_win_advapi_base_right_specific_file_e_read_attributes  = 0x00000080ul,
	mk_win_advapi_base_right_specific_file_e_write_attributes = 0x00000100ul,
	mk_win_advapi_base_right_specific_file_e_unknown_9        = 0x00000200ul,
	mk_win_advapi_base_right_specific_file_e_unknown_10       = 0x00000400ul,
	mk_win_advapi_base_right_specific_file_e_unknown_11       = 0x00000800ul,
	mk_win_advapi_base_right_specific_file_e_unknown_12       = 0x00001000ul,
	mk_win_advapi_base_right_specific_file_e_unknown_13       = 0x00002000ul,
	mk_win_advapi_base_right_specific_file_e_unknown_14       = 0x00004000ul,
	mk_win_advapi_base_right_specific_file_e_unknown_15       = 0x00008000ul,
	mk_win_advapi_base_right_specific_file_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_specific_file_e mk_win_advapi_base_right_specific_file_t;

enum mk_win_advapi_base_right_specific_directory_e
{
	mk_win_advapi_base_right_specific_directory_e_list_directory   = 0x00000001ul,
	mk_win_advapi_base_right_specific_directory_e_add_file         = 0x00000002ul,
	mk_win_advapi_base_right_specific_directory_e_add_subdirectory = 0x00000004ul,
	mk_win_advapi_base_right_specific_directory_e_read_ea          = 0x00000008ul,
	mk_win_advapi_base_right_specific_directory_e_write_ea         = 0x00000010ul,
	mk_win_advapi_base_right_specific_directory_e_traverse         = 0x00000020ul,
	mk_win_advapi_base_right_specific_directory_e_delete_child     = 0x00000040ul,
	mk_win_advapi_base_right_specific_directory_e_read_attributes  = 0x00000080ul,
	mk_win_advapi_base_right_specific_directory_e_write_attributes = 0x00000100ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_9        = 0x00000200ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_10       = 0x00000400ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_11       = 0x00000800ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_12       = 0x00001000ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_13       = 0x00002000ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_14       = 0x00004000ul,
	mk_win_advapi_base_right_specific_directory_e_unknown_15       = 0x00008000ul,
	mk_win_advapi_base_right_specific_directory_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_specific_directory_e mk_win_advapi_base_right_specific_directory_t;

enum mk_win_advapi_base_right_specific_pipe_e
{
	mk_win_advapi_base_right_specific_pipe_e_access_inbound       = 0x00000001ul,
	mk_win_advapi_base_right_specific_pipe_e_access_outbound      = 0x00000002ul,
	mk_win_advapi_base_right_specific_pipe_e_create_pipe_instance = 0x00000004ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_3            = 0x00000008ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_4            = 0x00000010ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_5            = 0x00000020ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_6            = 0x00000040ul,
	mk_win_advapi_base_right_specific_pipe_e_read_attributes      = 0x00000080ul,
	mk_win_advapi_base_right_specific_pipe_e_write_attributes     = 0x00000100ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_9            = 0x00000200ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_10           = 0x00000400ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_11           = 0x00000800ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_12           = 0x00001000ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_13           = 0x00002000ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_14           = 0x00004000ul,
	mk_win_advapi_base_right_specific_pipe_e_unknown_15           = 0x00008000ul,
	mk_win_advapi_base_right_specific_pipe_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_specific_pipe_e mk_win_advapi_base_right_specific_pipe_t;

enum mk_win_advapi_base_right_specific_regkey_e
{
	mk_win_advapi_base_right_specific_regkey_e_query_value        = 0x00000001ul,
	mk_win_advapi_base_right_specific_regkey_e_set_value          = 0x00000002ul,
	mk_win_advapi_base_right_specific_regkey_e_create_sub_key     = 0x00000004ul,
	mk_win_advapi_base_right_specific_regkey_e_enumerate_sub_keys = 0x00000008ul,
	mk_win_advapi_base_right_specific_regkey_e_notify             = 0x00000010ul,
	mk_win_advapi_base_right_specific_regkey_e_create_link        = 0x00000020ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_6          = 0x00000040ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_7          = 0x00000080ul,
	mk_win_advapi_base_right_specific_regkey_e_wow64_64key        = 0x00000100ul,
	mk_win_advapi_base_right_specific_regkey_e_wow64_32key        = 0x00000200ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_10         = 0x00000400ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_11         = 0x00000800ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_12         = 0x00001000ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_13         = 0x00002000ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_14         = 0x00004000ul,
	mk_win_advapi_base_right_specific_regkey_e_unknown_15         = 0x00008000ul,
	mk_win_advapi_base_right_specific_regkey_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_specific_regkey_e mk_win_advapi_base_right_specific_regkey_t;

enum mk_win_advapi_base_right_standard_e
{
	mk_win_advapi_base_right_standard_e_delete       = 0x00010000ul,
	mk_win_advapi_base_right_standard_e_read_control = 0x00020000ul,
	mk_win_advapi_base_right_standard_e_write_dac    = 0x00040000ul,
	mk_win_advapi_base_right_standard_e_write_owner  = 0x00080000ul,
	mk_win_advapi_base_right_standard_e_synchronize  = 0x00100000ul,
	mk_win_advapi_base_right_standard_e_unknown_21   = 0x00200000ul,
	mk_win_advapi_base_right_standard_e_unknown_22   = 0x00400000ul,
	mk_win_advapi_base_right_standard_e_unknown_23   = 0x00800000ul,
	mk_win_advapi_base_right_standard_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_standard_e mk_win_advapi_base_right_standard_t;

enum mk_win_advapi_base_right_generic_e
{
	mk_win_advapi_base_right_generic_e_all     = 0x10000000ul,
	mk_win_advapi_base_right_generic_e_execute = 0x20000000ul,
	mk_win_advapi_base_right_generic_e_write   = 0x40000000ul,
	mk_win_advapi_base_right_generic_e_read    = 0x80000000ul,
	mk_win_advapi_base_right_generic_e_dummy_end = 0
};
typedef enum mk_win_advapi_base_right_generic_e mk_win_advapi_base_right_generic_t;


#define mk_win_advapi_base_right_mask_specific        ((mk_win_base_dword_t)(0x0000fffful))
#define mk_win_advapi_base_right_mask_standard        ((mk_win_base_dword_t)(0x00ff0000ul))
#define mk_win_advapi_base_right_mask_sacl            ((mk_win_base_dword_t)(0x01000000ul))
#define mk_win_advapi_base_right_mask_maximum_allowed ((mk_win_base_dword_t)(0x02000000ul))
#define mk_win_advapi_base_right_mask_reserved_26     ((mk_win_base_dword_t)(0x04000000ul))
#define mk_win_advapi_base_right_mask_reserved_27     ((mk_win_base_dword_t)(0x08000000ul))
#define mk_win_advapi_base_right_mask_generic         ((mk_win_base_dword_t)(0xf0000000ul))


#if mk_lang_jumbo_want == 1
#include "mk_win_advapi_types.c"
#endif
#endif
