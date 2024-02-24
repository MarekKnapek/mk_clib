#ifndef mk_include_guard_mk_win_kernel_communication
#define mk_include_guard_mk_win_kernel_communication


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


#define mk_win_kernel_communication_ioctl_generate(device_type, function, method, access) \
	((mk_win_base_dword_t)( \
		((mk_win_base_dword_t)(((mk_win_base_dword_t((mk_win_base_dword_t)(device_type)) & ((mk_win_base_dword_t)(((((((mk_win_base_dword_t)(mk_win_base_dword_t)(mk_win_base_dword_t)(1)) << ((mk_lang_types_sint_t)(16)))) - ((mk_win_base_dword_t)(1)))))))) << ((mk_lang_types_sint_t)(16)))) | \
		((mk_win_base_dword_t)(((mk_win_base_dword_t((mk_win_base_dword_t)(access     )) & ((mk_win_base_dword_t)(((((((mk_win_base_dword_t)(mk_win_base_dword_t)(mk_win_base_dword_t)(1)) << ((mk_lang_types_sint_t)( 2)))) - ((mk_win_base_dword_t)(1)))))))) << ((mk_lang_types_sint_t)(14)))) | \
		((mk_win_base_dword_t)(((mk_win_base_dword_t((mk_win_base_dword_t)(function   )) & ((mk_win_base_dword_t)(((((((mk_win_base_dword_t)(mk_win_base_dword_t)(mk_win_base_dword_t)(1)) << ((mk_lang_types_sint_t)(12)))) - ((mk_win_base_dword_t)(1)))))))) << ((mk_lang_types_sint_t)( 2)))) | \
		((mk_win_base_dword_t)(((mk_win_base_dword_t((mk_win_base_dword_t)(method     )) & ((mk_win_base_dword_t)(((((((mk_win_base_dword_t)(mk_win_base_dword_t)(mk_win_base_dword_t)(1)) << ((mk_lang_types_sint_t)( 2)))) - ((mk_win_base_dword_t)(1)))))))) << ((mk_lang_types_sint_t)( 0)))) | \
		((mk_win_base_dword_t)(0)) \
	))


enum mk_win_kernel_communication_device_id_e
{
	mk_win_kernel_communication_device_id_e_beep                = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_communication_device_id_e_cd_rom              = ((mk_win_base_dword_t)(0x00000002ul)),
	mk_win_kernel_communication_device_id_e_cd_rom_file_system  = ((mk_win_base_dword_t)(0x00000003ul)),
	mk_win_kernel_communication_device_id_e_controller          = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_communication_device_id_e_datalink            = ((mk_win_base_dword_t)(0x00000005ul)),
	mk_win_kernel_communication_device_id_e_dfs                 = ((mk_win_base_dword_t)(0x00000006ul)),
	mk_win_kernel_communication_device_id_e_disk                = ((mk_win_base_dword_t)(0x00000007ul)),
	mk_win_kernel_communication_device_id_e_disk_file_system    = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_communication_device_id_e_file_system         = ((mk_win_base_dword_t)(0x00000009ul)),
	mk_win_kernel_communication_device_id_e_inport_port         = ((mk_win_base_dword_t)(0x0000000aul)),
	mk_win_kernel_communication_device_id_e_keyboard            = ((mk_win_base_dword_t)(0x0000000bul)),
	mk_win_kernel_communication_device_id_e_mailslot            = ((mk_win_base_dword_t)(0x0000000cul)),
	mk_win_kernel_communication_device_id_e_midi_in             = ((mk_win_base_dword_t)(0x0000000dul)),
	mk_win_kernel_communication_device_id_e_midi_out            = ((mk_win_base_dword_t)(0x0000000eul)),
	mk_win_kernel_communication_device_id_e_mouse               = ((mk_win_base_dword_t)(0x0000000ful)),
	mk_win_kernel_communication_device_id_e_multi_unc_provider  = ((mk_win_base_dword_t)(0x00000010ul)),
	mk_win_kernel_communication_device_id_e_named_pipe          = ((mk_win_base_dword_t)(0x00000011ul)),
	mk_win_kernel_communication_device_id_e_network             = ((mk_win_base_dword_t)(0x00000012ul)),
	mk_win_kernel_communication_device_id_e_network_browser     = ((mk_win_base_dword_t)(0x00000013ul)),
	mk_win_kernel_communication_device_id_e_network_file_system = ((mk_win_base_dword_t)(0x00000014ul)),
	mk_win_kernel_communication_device_id_e_null                = ((mk_win_base_dword_t)(0x00000015ul)),
	mk_win_kernel_communication_device_id_e_parallel_port       = ((mk_win_base_dword_t)(0x00000016ul)),
	mk_win_kernel_communication_device_id_e_physical_netcard    = ((mk_win_base_dword_t)(0x00000017ul)),
	mk_win_kernel_communication_device_id_e_printer             = ((mk_win_base_dword_t)(0x00000018ul)),
	mk_win_kernel_communication_device_id_e_scanner             = ((mk_win_base_dword_t)(0x00000019ul)),
	mk_win_kernel_communication_device_id_e_serial_mouse_port   = ((mk_win_base_dword_t)(0x0000001aul)),
	mk_win_kernel_communication_device_id_e_serial_port         = ((mk_win_base_dword_t)(0x0000001bul)),
	mk_win_kernel_communication_device_id_e_screen              = ((mk_win_base_dword_t)(0x0000001cul)),
	mk_win_kernel_communication_device_id_e_sound               = ((mk_win_base_dword_t)(0x0000001dul)),
	mk_win_kernel_communication_device_id_e_streams             = ((mk_win_base_dword_t)(0x0000001eul)),
	mk_win_kernel_communication_device_id_e_tape                = ((mk_win_base_dword_t)(0x0000001ful)),
	mk_win_kernel_communication_device_id_e_tape_file_system    = ((mk_win_base_dword_t)(0x00000020ul)),
	mk_win_kernel_communication_device_id_e_transport           = ((mk_win_base_dword_t)(0x00000021ul)),
	mk_win_kernel_communication_device_id_e_unknown             = ((mk_win_base_dword_t)(0x00000022ul)),
	mk_win_kernel_communication_device_id_e_video               = ((mk_win_base_dword_t)(0x00000023ul)),
	mk_win_kernel_communication_device_id_e_virtual_disk        = ((mk_win_base_dword_t)(0x00000024ul)),
	mk_win_kernel_communication_device_id_e_wave_in             = ((mk_win_base_dword_t)(0x00000025ul)),
	mk_win_kernel_communication_device_id_e_wave_out            = ((mk_win_base_dword_t)(0x00000026ul)),
	mk_win_kernel_communication_device_id_e_8042_port           = ((mk_win_base_dword_t)(0x00000027ul)),
	mk_win_kernel_communication_device_id_e_network_redirector  = ((mk_win_base_dword_t)(0x00000028ul)),
	mk_win_kernel_communication_device_id_e_battery             = ((mk_win_base_dword_t)(0x00000029ul)),
	mk_win_kernel_communication_device_id_e_bus_extender        = ((mk_win_base_dword_t)(0x0000002aul)),
	mk_win_kernel_communication_device_id_e_modem               = ((mk_win_base_dword_t)(0x0000002bul)),
	mk_win_kernel_communication_device_id_e_vdm                 = ((mk_win_base_dword_t)(0x0000002cul)),
	mk_win_kernel_communication_device_id_e_mass_storage        = ((mk_win_base_dword_t)(0x0000002dul)),
	mk_win_kernel_communication_device_id_e_smb                 = ((mk_win_base_dword_t)(0x0000002eul)),
	mk_win_kernel_communication_device_id_e_ks                  = ((mk_win_base_dword_t)(0x0000002ful)),
	mk_win_kernel_communication_device_id_e_changer             = ((mk_win_base_dword_t)(0x00000030ul)),
	mk_win_kernel_communication_device_id_e_smartcard           = ((mk_win_base_dword_t)(0x00000031ul)),
	mk_win_kernel_communication_device_id_e_acpi                = ((mk_win_base_dword_t)(0x00000032ul)),
	mk_win_kernel_communication_device_id_e_dvd                 = ((mk_win_base_dword_t)(0x00000033ul)),
	mk_win_kernel_communication_device_id_e_fullscreen_video    = ((mk_win_base_dword_t)(0x00000034ul)),
	mk_win_kernel_communication_device_id_e_dfs_file_system     = ((mk_win_base_dword_t)(0x00000035ul)),
	mk_win_kernel_communication_device_id_e_dfs_volume          = ((mk_win_base_dword_t)(0x00000036ul)),
	mk_win_kernel_communication_device_id_e_serenum             = ((mk_win_base_dword_t)(0x00000037ul)),
	mk_win_kernel_communication_device_id_e_termsrv             = ((mk_win_base_dword_t)(0x00000038ul)),
	mk_win_kernel_communication_device_id_e_ksec                = ((mk_win_base_dword_t)(0x00000039ul)),
	mk_win_kernel_communication_device_id_e_fips                = ((mk_win_base_dword_t)(0x0000003aul)),
	mk_win_kernel_communication_device_id_e_infiniband          = ((mk_win_base_dword_t)(0x0000003bul)),
	mk_win_kernel_communication_device_id_e_vmbus               = ((mk_win_base_dword_t)(0x0000003eul)),
	mk_win_kernel_communication_device_id_e_crypt_provider      = ((mk_win_base_dword_t)(0x0000003ful)),
	mk_win_kernel_communication_device_id_e_wpd                 = ((mk_win_base_dword_t)(0x00000040ul)),
	mk_win_kernel_communication_device_id_e_bluetooth           = ((mk_win_base_dword_t)(0x00000041ul)),
	mk_win_kernel_communication_device_id_e_mt_composite        = ((mk_win_base_dword_t)(0x00000042ul)),
	mk_win_kernel_communication_device_id_e_mt_transport        = ((mk_win_base_dword_t)(0x00000043ul)),
	mk_win_kernel_communication_device_id_e_biometric           = ((mk_win_base_dword_t)(0x00000044ul)),
	mk_win_kernel_communication_device_id_e_pmi                 = ((mk_win_base_dword_t)(0x00000045ul)),
	mk_win_kernel_communication_device_id_e_ehstor              = ((mk_win_base_dword_t)(0x00000046ul)),
	mk_win_kernel_communication_device_id_e_devapi              = ((mk_win_base_dword_t)(0x00000047ul)),
	mk_win_kernel_communication_device_id_e_gpio                = ((mk_win_base_dword_t)(0x00000048ul)),
	mk_win_kernel_communication_device_id_e_usbex               = ((mk_win_base_dword_t)(0x00000049ul)),
	mk_win_kernel_communication_device_id_e_console             = ((mk_win_base_dword_t)(0x00000050ul)),
	mk_win_kernel_communication_device_id_e_nfp                 = ((mk_win_base_dword_t)(0x00000051ul)),
	mk_win_kernel_communication_device_id_e_sysenv              = ((mk_win_base_dword_t)(0x00000052ul)),
	mk_win_kernel_communication_device_id_e_virtual_block       = ((mk_win_base_dword_t)(0x00000053ul)),
	mk_win_kernel_communication_device_id_e_point_of_service    = ((mk_win_base_dword_t)(0x00000054ul)),
	mk_win_kernel_communication_device_id_e_storage_replication = ((mk_win_base_dword_t)(0x00000055ul)),
	mk_win_kernel_communication_device_id_e_trust_env           = ((mk_win_base_dword_t)(0x00000056ul)),
	mk_win_kernel_communication_device_id_e_ucm                 = ((mk_win_base_dword_t)(0x00000057ul)),
	mk_win_kernel_communication_device_id_e_ucmtcpci            = ((mk_win_base_dword_t)(0x00000058ul)),
	mk_win_kernel_communication_device_id_e_persistent_memory   = ((mk_win_base_dword_t)(0x00000059ul)),
	mk_win_kernel_communication_device_id_e_nvdimm              = ((mk_win_base_dword_t)(0x0000005aul)),
	mk_win_kernel_communication_device_id_e_holographic         = ((mk_win_base_dword_t)(0x0000005bul)),
	mk_win_kernel_communication_device_id_e_sdfxhci             = ((mk_win_base_dword_t)(0x0000005cul)),
	mk_win_kernel_communication_device_id_e_ucmucsi             = ((mk_win_base_dword_t)(0x0000005dul)),
	mk_win_kernel_communication_device_id_e_prm                 = ((mk_win_base_dword_t)(0x0000005eul)),
	mk_win_kernel_communication_device_id_e_event_collector     = ((mk_win_base_dword_t)(0x0000005ful)),
	mk_win_kernel_communication_device_id_e_usb4                = ((mk_win_base_dword_t)(0x00000060ul)),
	mk_win_kernel_communication_device_id_e_soundwire           = ((mk_win_base_dword_t)(0x00000061ul)),
	mk_win_kernel_communication_device_id_e_dummy_end = 0
};
typedef enum mk_win_kernel_communication_device_id_e mk_win_kernel_communication_device_id_t;

enum mk_win_kernel_communication_method_id_e
{
	mk_win_kernel_communication_method_id_e_buffered   = ((mk_win_base_dword_t)(0)),
	mk_win_kernel_communication_method_id_e_in_direct  = ((mk_win_base_dword_t)(1)),
	mk_win_kernel_communication_method_id_e_out_direct = ((mk_win_base_dword_t)(2)),
	mk_win_kernel_communication_method_id_e_neither    = ((mk_win_base_dword_t)(3)),
	mk_win_kernel_communication_method_id_e_dummy_end
};
typedef enum mk_win_kernel_communication_method_id_e mk_win_kernel_communication_method_id_t;

enum mk_win_kernel_communication_access_id_e
{
	mk_win_kernel_communication_access_id_e_any   = ((mk_win_base_dword_t)(0)),
	mk_win_kernel_communication_access_id_e_read  = ((mk_win_base_dword_t)(1)),
	mk_win_kernel_communication_access_id_e_write = ((mk_win_base_dword_t)(2)),
	mk_win_kernel_communication_access_id_e_dummy_end
};
typedef enum mk_win_kernel_communication_access_id_e mk_win_kernel_communication_access_id_t;

enum mk_win_kernel_communication_ioctl_id_e
{
	mk_win_kernel_communication_ioctl_id_e_fsctl_get_volume_bitmap      = mk_win_kernel_communication_ioctl_generate(mk_win_kernel_communication_device_id_e_file_system, 27, mk_win_kernel_communication_method_id_e_neither, mk_win_kernel_communication_access_id_e_any),
	mk_win_kernel_communication_ioctl_id_e_fsctl_get_retrieval_pointers = mk_win_kernel_communication_ioctl_generate(mk_win_kernel_communication_device_id_e_file_system, 28, mk_win_kernel_communication_method_id_e_neither, mk_win_kernel_communication_access_id_e_any),
	mk_win_kernel_communication_ioctl_id_e_fsctl_move_file              = mk_win_kernel_communication_ioctl_generate(mk_win_kernel_communication_device_id_e_file_system, 29, mk_win_kernel_communication_method_id_e_buffered, mk_win_kernel_communication_access_id_e_any),
	mk_win_kernel_communication_ioctl_id_e_fsctl_mark_handle            = mk_win_kernel_communication_ioctl_generate(mk_win_kernel_communication_device_id_e_file_system, 63, mk_win_kernel_communication_method_id_e_buffered, mk_win_kernel_communication_access_id_e_any),
	mk_win_kernel_communication_ioctl_id_e_dummy_end = 0
};
typedef enum mk_win_kernel_communication_ioctl_id_e mk_win_kernel_communication_ioctl_id_t;

enum mk_win_kernel_communication_usn_source_id_e
{
	mk_win_kernel_communication_usn_source_id_e_data_management               = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_communication_usn_source_id_e_auxiliary_data                = ((mk_win_base_dword_t)(0x00000002ul)),
	mk_win_kernel_communication_usn_source_id_e_replication_management        = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_communication_usn_source_id_e_client_replication_management = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_communication_usn_source_id_e_dummy_end = 0
};
typedef enum mk_win_kernel_communication_usn_source_id_e mk_win_kernel_communication_usn_source_id_t;

enum mk_win_kernel_communication_mark_handle_id_e
{
	mk_win_kernel_communication_mark_handle_id_e_protect_clusters                    = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_communication_mark_handle_id_e_txf_system_log                      = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_communication_mark_handle_id_e_not_txf_system_log                  = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_communication_mark_handle_id_e_realtime                            = ((mk_win_base_dword_t)(0x00000020ul)), /* ntddi_version >= ntddi_win7 */
	mk_win_kernel_communication_mark_handle_id_e_not_realtime                        = ((mk_win_base_dword_t)(0x00000040ul)), /* ntddi_version >= ntddi_win7 */
	mk_win_kernel_communication_mark_handle_id_e_read_copy                           = ((mk_win_base_dword_t)(0x00000080ul)), /* ntddi_version >= ntddi_win8 */
	mk_win_kernel_communication_mark_handle_id_e_not_read_copy                       = ((mk_win_base_dword_t)(0x00000100ul)), /* ntddi_version >= ntddi_win8 */
	mk_win_kernel_communication_mark_handle_id_e_filter_metadata                     = ((mk_win_base_dword_t)(0x00000200ul)), /* (ntddi_version >= ntddi_winblue) || (ntddi_version >= ntddi_win7) 8.1 and newer */
	mk_win_kernel_communication_mark_handle_id_e_return_purge_failure                = ((mk_win_base_dword_t)(0x00000400ul)), /* (ntddi_version >= ntddi_winblue) || (ntddi_version >= ntddi_win7) 8.1 and newer */
	mk_win_kernel_communication_mark_handle_id_e_cloud_sync                          = ((mk_win_base_dword_t)(0x00000800ul)), /* ntddi_version >= ntddi_win7 deprecated */
	mk_win_kernel_communication_mark_handle_id_e_disable_file_metadata_optimization  = ((mk_win_base_dword_t)(0x00001000ul)), /* ntddi_version >= ntddi_winthreshold */
	mk_win_kernel_communication_mark_handle_id_e_enable_usn_source_on_paging_io      = ((mk_win_base_dword_t)(0x00002000ul)), /* ntddi_version >= ntddi_winthreshold */
	mk_win_kernel_communication_mark_handle_id_e_skip_coherency_sync_disallow_writes = ((mk_win_base_dword_t)(0x00004000ul)), /* ntddi_version >= ntddi_winthreshold */
	mk_win_kernel_communication_mark_handle_id_e_suppress_volume_open_flush          = ((mk_win_base_dword_t)(0x00008000ul)), /* ntddi_version >= ntddi_win10_co */
	mk_win_kernel_communication_mark_handle_id_e_enable_cpu_cache                    = ((mk_win_base_dword_t)(0x10000000ul)), /* ntddi_version >= ntddi_win10_rs4 */
	mk_win_kernel_communication_mark_handle_id_e_dummy_end = 0
};
typedef enum mk_win_kernel_communication_mark_handle_id_e mk_win_kernel_communication_mark_handle_id_t;


struct mk_win_kernel_communication_starting_vcn_input_buffer_s
{
	mk_win_base_ullong_t m_starting_vcn;
};
typedef struct mk_win_kernel_communication_starting_vcn_input_buffer_s mk_win_kernel_communication_starting_vcn_input_buffer_t;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t const mk_win_kernel_communication_starting_vcn_input_buffer_ct;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t* mk_win_kernel_communication_starting_vcn_input_buffer_pt;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t const* mk_win_kernel_communication_starting_vcn_input_buffer_pct;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t mk_win_base_far* mk_win_kernel_communication_starting_vcn_input_buffer_lpt;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t mk_win_base_far const* mk_win_kernel_communication_starting_vcn_input_buffer_lpct;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t mk_win_base_near* mk_win_kernel_communication_starting_vcn_input_buffer_npt;
typedef mk_win_kernel_communication_starting_vcn_input_buffer_t mk_win_base_near const* mk_win_kernel_communication_starting_vcn_input_buffer_npct;

struct mk_win_kernel_communication_starting_lcn_input_buffer_s
{
	mk_win_base_ullong_t m_starting_lcn;
};
typedef struct mk_win_kernel_communication_starting_lcn_input_buffer_s mk_win_kernel_communication_starting_lcn_input_buffer_t;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t const mk_win_kernel_communication_starting_lcn_input_buffer_ct;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t* mk_win_kernel_communication_starting_lcn_input_buffer_pt;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t const* mk_win_kernel_communication_starting_lcn_input_buffer_pct;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t mk_win_base_far* mk_win_kernel_communication_starting_lcn_input_buffer_lpt;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t mk_win_base_far const* mk_win_kernel_communication_starting_lcn_input_buffer_lpct;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t mk_win_base_near* mk_win_kernel_communication_starting_lcn_input_buffer_npt;
typedef mk_win_kernel_communication_starting_lcn_input_buffer_t mk_win_base_near const* mk_win_kernel_communication_starting_lcn_input_buffer_npct;

struct mk_win_kernel_communication_retrieval_pointers_element_s
{
	mk_win_base_ullong_t m_next_vcn;
	mk_win_base_ullong_t m_lcn;
};
typedef struct mk_win_kernel_communication_retrieval_pointers_element_s mk_win_kernel_communication_retrieval_pointers_element_t;
typedef mk_win_kernel_communication_retrieval_pointers_element_t const mk_win_kernel_communication_retrieval_pointers_element_ct;
typedef mk_win_kernel_communication_retrieval_pointers_element_t* mk_win_kernel_communication_retrieval_pointers_element_pt;
typedef mk_win_kernel_communication_retrieval_pointers_element_t const* mk_win_kernel_communication_retrieval_pointers_element_pct;
typedef mk_win_kernel_communication_retrieval_pointers_element_t mk_win_base_far* mk_win_kernel_communication_retrieval_pointers_element_lpt;
typedef mk_win_kernel_communication_retrieval_pointers_element_t mk_win_base_far const* mk_win_kernel_communication_retrieval_pointers_element_lpct;
typedef mk_win_kernel_communication_retrieval_pointers_element_t mk_win_base_near* mk_win_kernel_communication_retrieval_pointers_element_npt;
typedef mk_win_kernel_communication_retrieval_pointers_element_t mk_win_base_near const* mk_win_kernel_communication_retrieval_pointers_element_npct;

struct mk_win_kernel_communication_retrieval_pointers_buffer_s
{
	mk_win_base_dword_t m_extents_count;
	mk_win_base_ullong_t m_starting_vcn;
	mk_win_kernel_communication_retrieval_pointers_element_t m_extents_arr[mk_win_base_anysize_array];
};
typedef struct mk_win_kernel_communication_retrieval_pointers_buffer_s mk_win_kernel_communication_retrieval_pointers_buffer_t;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t const mk_win_kernel_communication_retrieval_pointers_buffer_ct;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t* mk_win_kernel_communication_retrieval_pointers_buffer_pt;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t const* mk_win_kernel_communication_retrieval_pointers_buffer_pct;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t mk_win_base_far* mk_win_kernel_communication_retrieval_pointers_buffer_lpt;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t mk_win_base_far const* mk_win_kernel_communication_retrieval_pointers_buffer_lpct;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t mk_win_base_near* mk_win_kernel_communication_retrieval_pointers_buffer_npt;
typedef mk_win_kernel_communication_retrieval_pointers_buffer_t mk_win_base_near const* mk_win_kernel_communication_retrieval_pointers_buffer_npct;

struct mk_win_kernel_communication_volume_bitmap_buffer_s
{
	mk_win_base_ullong_t m_starting_lcn;
	mk_win_base_ullong_t m_bitmap_size;
	mk_win_base_uchar_t m_bitmap_arr[mk_win_base_anysize_array];
};
typedef struct mk_win_kernel_communication_volume_bitmap_buffer_s mk_win_kernel_communication_volume_bitmap_buffer_t;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t const mk_win_kernel_communication_volume_bitmap_buffer_ct;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t* mk_win_kernel_communication_volume_bitmap_buffer_pt;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t const* mk_win_kernel_communication_volume_bitmap_buffer_pct;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t mk_win_base_far* mk_win_kernel_communication_volume_bitmap_buffer_lpt;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t mk_win_base_far const* mk_win_kernel_communication_volume_bitmap_buffer_lpct;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t mk_win_base_near* mk_win_kernel_communication_volume_bitmap_buffer_npt;
typedef mk_win_kernel_communication_volume_bitmap_buffer_t mk_win_base_near const* mk_win_kernel_communication_volume_bitmap_buffer_npct;

struct mk_win_kernel_communication_move_file_data_s
{
	mk_win_base_handle_t m_file;
	mk_win_base_ullong_t m_starting_vcn;
	mk_win_base_ullong_t m_starting_lcn;
	mk_win_base_dword_t m_clusters_count;
};
typedef struct mk_win_kernel_communication_move_file_data_s mk_win_kernel_communication_move_file_data_t;
typedef mk_win_kernel_communication_move_file_data_t const mk_win_kernel_communication_move_file_data_ct;
typedef mk_win_kernel_communication_move_file_data_t* mk_win_kernel_communication_move_file_data_pt;
typedef mk_win_kernel_communication_move_file_data_t const* mk_win_kernel_communication_move_file_data_pct;
typedef mk_win_kernel_communication_move_file_data_t mk_win_base_far* mk_win_kernel_communication_move_file_data_lpt;
typedef mk_win_kernel_communication_move_file_data_t mk_win_base_far const* mk_win_kernel_communication_move_file_data_lpct;
typedef mk_win_kernel_communication_move_file_data_t mk_win_base_near* mk_win_kernel_communication_move_file_data_npt;
typedef mk_win_kernel_communication_move_file_data_t mk_win_base_near const* mk_win_kernel_communication_move_file_data_npct;

struct mk_win_kernel_communication_overlapped_s
{
	mk_win_base_uintptr_t m_internal_lo;
	mk_win_base_uintptr_t m_internal_hi;
	mk_win_base_dword_t m_offset_lo;
	mk_win_base_dword_t m_offset_hi;
	mk_win_base_handle_t m_event;
};
typedef struct mk_win_kernel_communication_overlapped_s mk_win_kernel_communication_overlapped_t;
typedef mk_win_kernel_communication_overlapped_t const mk_win_kernel_communication_overlapped_ct;
typedef mk_win_kernel_communication_overlapped_t* mk_win_kernel_communication_overlapped_pt;
typedef mk_win_kernel_communication_overlapped_t const* mk_win_kernel_communication_overlapped_pct;
typedef mk_win_kernel_communication_overlapped_t mk_win_base_far* mk_win_kernel_communication_overlapped_lpt;
typedef mk_win_kernel_communication_overlapped_t mk_win_base_far const* mk_win_kernel_communication_overlapped_lpct;
typedef mk_win_kernel_communication_overlapped_t mk_win_base_near* mk_win_kernel_communication_overlapped_npt;
typedef mk_win_kernel_communication_overlapped_t mk_win_base_near const* mk_win_kernel_communication_overlapped_npct;

struct mk_win_kernel_communication_mark_handle_info_data_s
{
	mk_win_base_dword_t m_usn_source_info_or_copy_number;
	mk_win_base_handle_t m_volume;
	mk_win_base_dword_t m_handle_info;
};
typedef struct mk_win_kernel_communication_mark_handle_info_data_s mk_win_kernel_communication_mark_handle_info_data_t;
typedef mk_win_kernel_communication_mark_handle_info_data_t const mk_win_kernel_communication_mark_handle_info_data_ct;
typedef mk_win_kernel_communication_mark_handle_info_data_t* mk_win_kernel_communication_mark_handle_info_data_pt;
typedef mk_win_kernel_communication_mark_handle_info_data_t const* mk_win_kernel_communication_mark_handle_info_data_pct;
typedef mk_win_kernel_communication_mark_handle_info_data_t mk_win_base_far* mk_win_kernel_communication_mark_handle_info_data_lpt;
typedef mk_win_kernel_communication_mark_handle_info_data_t mk_win_base_far const* mk_win_kernel_communication_mark_handle_info_data_lpct;
typedef mk_win_kernel_communication_mark_handle_info_data_t mk_win_base_near* mk_win_kernel_communication_mark_handle_info_data_npt;
typedef mk_win_kernel_communication_mark_handle_info_data_t mk_win_base_near const* mk_win_kernel_communication_mark_handle_info_data_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_communication_device_io_control(mk_win_base_handle_t const handle, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const in_buf, mk_win_base_dword_t const in_len, mk_win_base_void_lpt const out_buf, mk_win_base_dword_t const out_len, mk_win_base_dword_lpt const nwritten, mk_win_kernel_communication_overlapped_lpt const overlapped) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_communication.c"
#endif
#endif
