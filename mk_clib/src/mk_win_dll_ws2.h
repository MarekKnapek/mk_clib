#ifndef mk_include_guard_mk_win_dll_ws2_h
#define mk_include_guard_mk_win_dll_ws2_h


#include "mk_lang_bitness.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_base.h"


enum mk_win_dll_ws2_address_family_e
{
	mk_win_dll_ws2_address_family_e_unspec     =  0,
	mk_win_dll_ws2_address_family_e_unix       =  1,
	mk_win_dll_ws2_address_family_e_inet       =  2,
	mk_win_dll_ws2_address_family_e_implink    =  3,
	mk_win_dll_ws2_address_family_e_pup        =  4,
	mk_win_dll_ws2_address_family_e_chaos      =  5,
	mk_win_dll_ws2_address_family_e_ns         =  6,
	mk_win_dll_ws2_address_family_e_iso        =  7,
	mk_win_dll_ws2_address_family_e_ecma       =  8,
	mk_win_dll_ws2_address_family_e_datakit    =  9,
	mk_win_dll_ws2_address_family_e_ccitt      = 10,
	mk_win_dll_ws2_address_family_e_sna        = 11,
	mk_win_dll_ws2_address_family_e_decnet     = 12,
	mk_win_dll_ws2_address_family_e_dli        = 13,
	mk_win_dll_ws2_address_family_e_lat        = 14,
	mk_win_dll_ws2_address_family_e_hylink     = 15,
	mk_win_dll_ws2_address_family_e_appletalk  = 16,
	mk_win_dll_ws2_address_family_e_netbios    = 17,
	mk_win_dll_ws2_address_family_e_voiceview  = 18,
	mk_win_dll_ws2_address_family_e_firefox    = 19,
	mk_win_dll_ws2_address_family_e_unknown1   = 20,
	mk_win_dll_ws2_address_family_e_ban        = 21,
	mk_win_dll_ws2_address_family_e_atm        = 22,
	mk_win_dll_ws2_address_family_e_inet6      = 23,
	mk_win_dll_ws2_address_family_e_cluster    = 24,
	mk_win_dll_ws2_address_family_e_12844      = 25,
	mk_win_dll_ws2_address_family_e_irda       = 26,
	mk_win_dll_ws2_address_family_e_netdes     = 28,
	mk_win_dll_ws2_address_family_e_tcnprocess = 29,
	mk_win_dll_ws2_address_family_e_tcnmessage = 30,
	mk_win_dll_ws2_address_family_e_iclfxbm    = 31,
	mk_win_dll_ws2_address_family_e_bth        = 32,
	mk_win_dll_ws2_address_family_e_link       = 33,
	mk_win_dll_ws2_address_family_e_hyperv     = 34,
	/*mk_win_dll_ws2_address_family_e_ipx        = mk_win_dll_ws2_address_family_e_ns,
	mk_win_dll_ws2_address_family_e_osi        = mk_win_dll_ws2_address_family_e_iso,*/
	mk_win_dll_ws2_address_family_e_dummy_end
};
typedef enum mk_win_dll_ws2_address_family_e mk_win_dll_ws2_address_family_t;

enum mk_win_dll_ws2_address_type_e
{
	mk_win_dll_ws2_address_type_e_stream    = 1,
	mk_win_dll_ws2_address_type_e_dgram     = 2,
	mk_win_dll_ws2_address_type_e_raw       = 3,
	mk_win_dll_ws2_address_type_e_rdm       = 4,
	mk_win_dll_ws2_address_type_e_seqpacket = 5,
	mk_win_dll_ws2_address_type_e_dummy_end
};
typedef enum mk_win_dll_ws2_address_type_e mk_win_dll_ws2_address_type_t;

enum mk_win_dll_ws2_address_protocol_e
{
	mk_win_dll_ws2_address_protocol_e_ip   =   0,
	mk_win_dll_ws2_address_protocol_e_icmp =   1,
	mk_win_dll_ws2_address_protocol_e_igmp =   2,
	mk_win_dll_ws2_address_protocol_e_ggp  =   3,
	mk_win_dll_ws2_address_protocol_e_tcp  =   6,
	mk_win_dll_ws2_address_protocol_e_pup  =  12,
	mk_win_dll_ws2_address_protocol_e_udp  =  17,
	mk_win_dll_ws2_address_protocol_e_idp  =  22,
	mk_win_dll_ws2_address_protocol_e_nd   =  77,
	mk_win_dll_ws2_address_protocol_e_raw  = 255,
	mk_win_dll_ws2_address_protocol_e_dummy_end
};
typedef enum mk_win_dll_ws2_address_protocol_e mk_win_dll_ws2_address_protocol_t;

enum mk_win_dll_ws2_address_flags_e
{
	mk_win_dll_ws2_address_flags_e_overlapped             =  0x01,
	mk_win_dll_ws2_address_flags_e_multipoint_c_root      =  0x02,
	mk_win_dll_ws2_address_flags_e_multipoint_c_leaf      =  0x04,
	mk_win_dll_ws2_address_flags_e_multipoint_d_root      =  0x08,
	mk_win_dll_ws2_address_flags_e_multipoint_d_leaf      =  0x10,
	mk_win_dll_ws2_address_flags_e_access_system_security =  0x40,
	mk_win_dll_ws2_address_flags_e_no_handle_inherit      =  0x80,
	mk_win_dll_ws2_address_flags_e_registered_io          = 0x100,
	mk_win_dll_ws2_address_flags_e_dummy_end
};
typedef enum mk_win_dll_ws2_address_flags_e mk_win_dll_ws2_address_flags_t;

enum mk_win_dll_ws2_shutdown_how_e
{
	mk_win_dll_ws2_shutdown_how_e_receive = 0,
	mk_win_dll_ws2_shutdown_how_e_send    = 1,
	mk_win_dll_ws2_shutdown_how_e_both    = 2,
	mk_win_dll_ws2_shutdown_how_e_dummy_end
};
typedef enum mk_win_dll_ws2_shutdown_how_e mk_win_dll_ws2_shutdown_how_t;

enum mk_win_dll_ws2_sck_evt_bit_e
{
	mk_win_dll_ws2_sck_evt_bit_e_read                     = 0,
	mk_win_dll_ws2_sck_evt_bit_e_write                    = 1,
	mk_win_dll_ws2_sck_evt_bit_e_oob                      = 2,
	mk_win_dll_ws2_sck_evt_bit_e_accept                   = 3,
	mk_win_dll_ws2_sck_evt_bit_e_connect                  = 4,
	mk_win_dll_ws2_sck_evt_bit_e_close                    = 5,
	mk_win_dll_ws2_sck_evt_bit_e_qos                      = 6,
	mk_win_dll_ws2_sck_evt_bit_e_group_qos                = 7,
	mk_win_dll_ws2_sck_evt_bit_e_routing_interface_change = 8,
	mk_win_dll_ws2_sck_evt_bit_e_address_list_change      = 9,
	mk_win_dll_ws2_sck_evt_bit_e_dummy_end
};
typedef enum mk_win_dll_ws2_sck_evt_bit_e mk_win_dll_ws2_sck_evt_bit_t;

enum mk_win_dll_ws2_sck_evt_id_e
{
	mk_win_dll_ws2_sck_evt_id_e_fd_read                    	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_read                    ,
	mk_win_dll_ws2_sck_evt_id_e_fd_write                   	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_write                   ,
	mk_win_dll_ws2_sck_evt_id_e_fd_oob                     	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_oob                     ,
	mk_win_dll_ws2_sck_evt_id_e_fd_accept                  	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_accept                  ,
	mk_win_dll_ws2_sck_evt_id_e_fd_connect                 	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_connect                 ,
	mk_win_dll_ws2_sck_evt_id_e_fd_close                   	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_close                   ,
	mk_win_dll_ws2_sck_evt_id_e_fd_qos                     	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_qos                     ,
	mk_win_dll_ws2_sck_evt_id_e_fd_group_qos               	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_group_qos               ,
	mk_win_dll_ws2_sck_evt_id_e_fd_routing_interface_change	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_routing_interface_change,
	mk_win_dll_ws2_sck_evt_id_e_fd_address_list_change     	= 0x1 << mk_win_dll_ws2_sck_evt_bit_e_address_list_change     ,
	mk_win_dll_ws2_sck_evt_id_e_dummy_end = 0
};
typedef enum mk_win_dll_ws2_sck_evt_id_e mk_win_dll_ws2_sck_evt_id_t;

enum mk_win_dll_ws2_sck_level_e
{
	mk_win_dll_ws2_sck_level_tcp  =  6,
	mk_win_dll_ws2_sck_level_ipv6 = 41,
	mk_win_dll_ws2_sck_level_socket = 0xffff,
	mk_win_dll_ws2_sck_level_e_dummy_end
};
typedef enum mk_win_dll_ws2_sck_level_e mk_win_dll_ws2_sck_level_t;

enum mk_win_dll_ws2_sck_opt_tcp_e
{
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_nodelay                    =  1,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_expedited_1122             =  2,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_keepalive                  =  3,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_maxseg                     =  4,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_maxrt                      =  5,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_stdurg                     =  6,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_nourg                      =  7,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_atmark                     =  8,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_nosynretries               =  9,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_timestamps                 = 10,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_offload_preference         = 11,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_congestion_algorithm       = 12,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_delay_fin_ack              = 13,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_maxrtms                    = 14,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_fastopen                   = 15,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_keepcnt                    = 16,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_keepintvl                  = 17,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_fail_connect_on_icmp_error = 18,
	mk_win_dll_ws2_sck_opt_tcp_e_tcp_icmp_error_info            = 19,
	mk_win_dll_ws2_sck_opt_tcp_e_dummy_end
};
typedef enum mk_win_dll_ws2_sck_opt_tcp_e mk_win_dll_ws2_sck_opt_tcp_t;

enum mk_win_dll_ws2_sck_opt_ipv6_e
{
	mk_win_dll_ws2_sck_opt_ipv6_e_hopopts              =  1,
	mk_win_dll_ws2_sck_opt_ipv6_e_hdrincl              =  2,
	mk_win_dll_ws2_sck_opt_ipv6_e_unicast_hops         =  4,
	mk_win_dll_ws2_sck_opt_ipv6_e_multicast_if         =  9,
	mk_win_dll_ws2_sck_opt_ipv6_e_multicast_hops       = 10,
	mk_win_dll_ws2_sck_opt_ipv6_e_multicast_loop       = 11,
	mk_win_dll_ws2_sck_opt_ipv6_e_add_membership       = 12,
	mk_win_dll_ws2_sck_opt_ipv6_e_drop_membership      = 13,
	mk_win_dll_ws2_sck_opt_ipv6_e_dontfrag             = 14,
	mk_win_dll_ws2_sck_opt_ipv6_e_pktinfo              = 19,
	mk_win_dll_ws2_sck_opt_ipv6_e_hoplimit             = 21,
	mk_win_dll_ws2_sck_opt_ipv6_e_protection_level     = 23,
	mk_win_dll_ws2_sck_opt_ipv6_e_recvif               = 24,
	mk_win_dll_ws2_sck_opt_ipv6_e_recvdstaddr          = 25,
	mk_win_dll_ws2_sck_opt_ipv6_e_checksum             = 26,
	mk_win_dll_ws2_sck_opt_ipv6_e_v6only               = 27,
	mk_win_dll_ws2_sck_opt_ipv6_e_iflist               = 28,
	mk_win_dll_ws2_sck_opt_ipv6_e_add_iflist           = 29,
	mk_win_dll_ws2_sck_opt_ipv6_e_del_iflist           = 30,
	mk_win_dll_ws2_sck_opt_ipv6_e_unicast_if           = 31,
	mk_win_dll_ws2_sck_opt_ipv6_e_rthdr                = 32,
	mk_win_dll_ws2_sck_opt_ipv6_e_get_iflist           = 33,
	mk_win_dll_ws2_sck_opt_ipv6_e_recvrthdr            = 38,
	mk_win_dll_ws2_sck_opt_ipv6_e_tclass               = 39,
	mk_win_dll_ws2_sck_opt_ipv6_e_recvtclass           = 40,
	mk_win_dll_ws2_sck_opt_ipv6_e_ecn                  = 50,
	mk_win_dll_ws2_sck_opt_ipv6_e_recvecn              = 50,
	mk_win_dll_ws2_sck_opt_ipv6_e_pktinfo_ex           = 51,
	mk_win_dll_ws2_sck_opt_ipv6_e_wfp_redirect_records = 60,
	mk_win_dll_ws2_sck_opt_ipv6_e_wfp_redirect_context = 70,
	mk_win_dll_ws2_sck_opt_ipv6_e_mtu_discover         = 71,
	mk_win_dll_ws2_sck_opt_ipv6_e_mtu                  = 72,
	mk_win_dll_ws2_sck_opt_ipv6_e_nrt_interface        = 74,
	mk_win_dll_ws2_sck_opt_ipv6_e_recverr              = 75,
	mk_win_dll_ws2_sck_opt_ipv6_e_user_mtu             = 76,
	/*mk_win_dll_ws2_sck_opt_ipv6_e_join_group           = mk_win_dll_ws2_sck_opt_ipv6_e_add_membership,
	mk_win_dll_ws2_sck_opt_ipv6_e_leave_group          = mk_win_dll_ws2_sck_opt_ipv6_e_drop_membership,*/
	mk_win_dll_ws2_sck_opt_ipv6_e_dummy_end
};
typedef enum mk_win_dll_ws2_sck_opt_ipv6_e mk_win_dll_ws2_sck_opt_ipv6_t;

enum mk_win_dll_ws2_sck_opt_socket_e
{
	mk_win_dll_ws2_sck_opt_socket_e_connect_time          = 0x700c,
	mk_win_dll_ws2_sck_opt_socket_e_update_accept_context = 0x700b,
	mk_win_dll_ws2_sck_opt_socket_e_dummy_end
};
typedef enum mk_win_dll_ws2_sck_opt_socket_e mk_win_dll_ws2_sck_opt_socket_t;

#define mk_win_dll_ws2_ioctl_dir_vo (0x20000000ul)
#define mk_win_dll_ws2_ioctl_dir_wo (0x40000000ul)
#define mk_win_dll_ws2_ioctl_dir_ro (0x80000000ul)
#define mk_win_dll_ws2_ioctl_dir_rw (0xc0000000ul)

enum mk_win_dll_ws2_ioctl_control_code_e
{
	mk_win_dll_ws2_ioctl_control_code_e_associate_handle                        = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 |  1)),
	mk_win_dll_ws2_ioctl_control_code_e_enable_circular_queueing                = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_vo | 0x08000000 |  2)),
	mk_win_dll_ws2_ioctl_control_code_e_find_route                              = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_wo | 0x08000000 |  3)),
	mk_win_dll_ws2_ioctl_control_code_e_flush                                   = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_vo | 0x08000000 |  4)),
	mk_win_dll_ws2_ioctl_control_code_e_get_broadcast_address                   = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_wo | 0x08000000 |  5)),
	mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer          = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 |  6)),
	mk_win_dll_ws2_ioctl_control_code_e_get_qos                                 = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 |  7)),
	mk_win_dll_ws2_ioctl_control_code_e_get_group_qos                           = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 |  8)),
	mk_win_dll_ws2_ioctl_control_code_e_multipoint_loopback                     = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 |  9)),
	mk_win_dll_ws2_ioctl_control_code_e_multicast_scope                         = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 10)),
	mk_win_dll_ws2_ioctl_control_code_e_set_qos                                 = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 11)),
	mk_win_dll_ws2_ioctl_control_code_e_set_group_qos                           = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 12)),
	mk_win_dll_ws2_ioctl_control_code_e_translate_handle                        = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 | 13)),
	mk_win_dll_ws2_ioctl_control_code_e_routing_interface_query                 = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 | 20)),
	mk_win_dll_ws2_ioctl_control_code_e_routing_interface_change                = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 21)),
	mk_win_dll_ws2_ioctl_control_code_e_address_list_query                      = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_wo | 0x08000000 | 22)),
	mk_win_dll_ws2_ioctl_control_code_e_address_list_change                     = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_vo | 0x08000000 | 23)),
	mk_win_dll_ws2_ioctl_control_code_e_query_target_pnp_handle                 = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_wo | 0x08000000 | 24)),
	mk_win_dll_ws2_ioctl_control_code_e_address_list_sort                       = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 | 25)), /* _WIN32_WINNT >= 0x0501 */
	mk_win_dll_ws2_ioctl_control_code_e_reserved_1                              = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 26)), /* _WIN32_WINNT >= 0x0600 */
	mk_win_dll_ws2_ioctl_control_code_e_reserved_2                              = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_ro | 0x08000000 | 33)), /* _WIN32_WINNT >= 0x0600 */
	mk_win_dll_ws2_ioctl_control_code_e_get_multiple_extension_function_pointer = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_rw | 0x08000000 | 36)),
	mk_win_dll_ws2_ioctl_control_code_e_query_rss_processor_info                = ((mk_win_base_dword_t)(mk_win_dll_ws2_ioctl_dir_wo | 0x08000000 | 37)),
	mk_win_dll_ws2_ioctl_control_code_e_dummy_end
};
typedef enum mk_win_dll_ws2_ioctl_control_code_e mk_win_dll_ws2_ioctl_control_code_t;


mk_win_base_make_handle(mk_win_dll_ws2_event)


#define mk_win_dll_ws2_data_description_len_d 256
#define mk_win_dll_ws2_data_sys_status_len_d 128
enum mk_win_dll_ws2_data_description_len_e{ mk_win_dll_ws2_data_description_len_v = mk_win_dll_ws2_data_description_len_d }; typedef enum mk_win_dll_ws2_data_description_len_e mk_win_dll_ws2_data_description_len_t;
enum mk_win_dll_ws2_data_sys_status_len_e{ mk_win_dll_ws2_data_sys_status_len_v = mk_win_dll_ws2_data_sys_status_len_d }; typedef enum mk_win_dll_ws2_data_sys_status_len_e mk_win_dll_ws2_data_sys_status_len_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_ws2_data_32_s
{
	mk_win_base_ushort_t m_version_lo;
	mk_win_base_ushort_t m_version_hi;
	mk_win_base_pchar_t m_description[mk_win_dll_ws2_data_description_len_v + 1];
	mk_win_base_pchar_t m_system_status[mk_win_dll_ws2_data_sys_status_len_v + 1];
	mk_win_base_ushort_t m_max_sockets;
	mk_win_base_ushort_t m_max_udp_dg;
	mk_win_base_pchar_pt m_vendor_info;
};
typedef struct mk_win_dll_ws2_data_32_s mk_win_dll_ws2_data_32_t;
mk_lang_typedef(mk_win_dll_ws2_data_32);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_ws2_data_64_s
{
	mk_win_base_ushort_t m_version_lo;
	mk_win_base_ushort_t m_version_hi;
	mk_win_base_ushort_t m_max_sockets;
	mk_win_base_ushort_t m_max_udp_dg;
	mk_win_base_pchar_pt m_vendor_info;
	mk_win_base_pchar_t m_description[mk_win_dll_ws2_data_description_len_v + 1];
	mk_win_base_pchar_t m_system_status[mk_win_dll_ws2_data_sys_status_len_v + 1];
};
typedef struct mk_win_dll_ws2_data_64_s mk_win_dll_ws2_data_64_t;
mk_lang_typedef(mk_win_dll_ws2_data_64);
#include "mk_lang_warning_msvc_pop.h"

struct mk_win_dll_ws2_data_s
{
#if mk_lang_bitness == mk_lang_bitness_32
	mk_win_dll_ws2_data_32_t m_data;
#elif mk_lang_bitness == mk_lang_bitness_64
	mk_win_dll_ws2_data_64_t m_data;
#else
#error xxxxxxxxxx
#endif
};
typedef struct mk_win_dll_ws2_data_s mk_win_dll_ws2_data_t;
mk_lang_typedef(mk_win_dll_ws2_data);

#define mk_win_dll_ws2_data_protocol_chain_len_max_d 7
enum mk_win_dll_ws2_data_protocol_chain_len_max_e{ mk_win_dll_ws2_data_protocol_chain_len_max_v = mk_win_dll_ws2_data_protocol_chain_len_max_d }; typedef enum mk_win_dll_ws2_data_protocol_chain_len_max_e mk_win_dll_ws2_data_protocol_chain_len_max_t;

struct mk_win_dll_ws2_protocol_chain_s
{
	mk_win_base_sint_t m_chain_len;
	mk_win_base_dword_t m_chain_entries[mk_win_dll_ws2_data_protocol_chain_len_max_v];
};
typedef struct mk_win_dll_ws2_protocol_chain_s mk_win_dll_ws2_protocol_chain_t;
mk_lang_typedef(mk_win_dll_ws2_protocol_chain);

#define mk_win_dll_ws2_data_protocol_len_d 256
enum mk_win_dll_ws2_data_protocol_len_e{ mk_win_dll_ws2_data_protocol_len_v = mk_win_dll_ws2_data_protocol_len_d }; typedef enum mk_win_dll_ws2_data_protocol_len_e mk_win_dll_ws2_data_protocol_len_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_ws2_protocol_info_a_s
{
	mk_win_base_dword_t m_service_flags_1;
	mk_win_base_dword_t m_service_flags_2;
	mk_win_base_dword_t m_service_flags_3;
	mk_win_base_dword_t m_service_flags_4;
	mk_win_base_dword_t m_provider_flags;
	mk_win_base_guid_t m_provider_id;
	mk_win_base_dword_t m_catalog_entry_id;
	mk_win_dll_ws2_protocol_chain_t m_protocol_chain;
	mk_win_base_sint_t m_version;
	mk_win_base_sint_t m_address_family;
	mk_win_base_sint_t m_max_sock_addr;
	mk_win_base_sint_t m_min_sock_addr;
	mk_win_base_sint_t m_socket_type;
	mk_win_base_sint_t m_protocol_num;
	mk_win_base_sint_t m_protocol_max_offset;
	mk_win_base_sint_t m_network_byte_order;
	mk_win_base_sint_t m_security_scheme;
	mk_win_base_dword_t m_message_size;
	mk_win_base_dword_t m_provider_reserved;
	mk_win_base_pchar_t m_protocol_str[mk_win_dll_ws2_data_protocol_len_v + 1];
};
typedef struct mk_win_dll_ws2_protocol_info_a_s mk_win_dll_ws2_protocol_info_a_t;
mk_lang_typedef(mk_win_dll_ws2_protocol_info_a);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_ws2_protocol_info_w_s
{
	mk_win_base_dword_t m_service_flags_1;
	mk_win_base_dword_t m_service_flags_2;
	mk_win_base_dword_t m_service_flags_3;
	mk_win_base_dword_t m_service_flags_4;
	mk_win_base_dword_t m_provider_flags;
	mk_win_base_guid_t m_provider_id;
	mk_win_base_dword_t m_catalog_entry_id;
	mk_win_dll_ws2_protocol_chain_t m_protocol_chain;
	mk_win_base_sint_t m_version;
	mk_win_base_sint_t m_address_family;
	mk_win_base_sint_t m_max_sock_addr;
	mk_win_base_sint_t m_min_sock_addr;
	mk_win_base_sint_t m_socket_type;
	mk_win_base_sint_t m_protocol_num;
	mk_win_base_sint_t m_protocol_max_offset;
	mk_win_base_sint_t m_network_byte_order;
	mk_win_base_sint_t m_security_scheme;
	mk_win_base_dword_t m_message_size;
	mk_win_base_dword_t m_provider_reserved;
	mk_win_base_wchar_t m_protocol_str[mk_win_dll_ws2_data_protocol_len_v + 1];
};
typedef struct mk_win_dll_ws2_protocol_info_w_s mk_win_dll_ws2_protocol_info_w_t;
mk_lang_typedef(mk_win_dll_ws2_protocol_info_w);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_win_dll_ws2_user_data_s
{
	mk_win_base_ulong_t m_len;
	mk_win_base_void_pt m_buf;
};
typedef struct mk_win_dll_ws2_user_data_s mk_win_dll_ws2_user_data_t;
mk_lang_typedef(mk_win_dll_ws2_user_data);
#include "mk_lang_warning_msvc_pop.h"

struct mk_win_dll_ws2_flowspec_s
{
	mk_win_base_ulong_t m_token_rate;
	mk_win_base_ulong_t m_token_bucket_size;
	mk_win_base_ulong_t m_peak_bandwidth;
	mk_win_base_ulong_t m_latency;
	mk_win_base_ulong_t m_delay_variation;
	mk_win_base_ulong_t m_service_type;
	mk_win_base_ulong_t m_max_sdu_size;
	mk_win_base_ulong_t m_minimum_policed_size;
};
typedef struct mk_win_dll_ws2_flowspec_s mk_win_dll_ws2_flowspec_t;
mk_lang_typedef(mk_win_dll_ws2_flowspec);

struct mk_win_dll_ws2_qos_s
{
	mk_win_dll_ws2_flowspec_t m_sending;
	mk_win_dll_ws2_flowspec_t m_receiving;
	mk_win_dll_ws2_user_data_t m_provider_specific;
};
typedef struct mk_win_dll_ws2_qos_s mk_win_dll_ws2_qos_t;
mk_lang_typedef(mk_win_dll_ws2_qos);

struct mk_win_dll_ws2_overlapped_s
{
	mk_win_base_uintptr_t m_internal_lo;
	mk_win_base_uintptr_t m_internal_hi;
	mk_win_base_dword_t m_offset_lo;
	mk_win_base_dword_t m_offset_hi;
	mk_win_dll_ws2_event_t m_event;
};
typedef struct mk_win_dll_ws2_overlapped_s mk_win_dll_ws2_overlapped_t;
mk_lang_typedef(mk_win_dll_ws2_overlapped);

union mk_win_dll_ws2_ipv4_addr_data_u
{
	mk_win_base_uchar_t m_ucs[32 / mk_lang_charbit / sizeof(mk_win_base_uchar_t)];
	mk_win_base_ushort_t m_uss[32 / mk_lang_charbit / sizeof(mk_win_base_ushort_t)];
	mk_win_base_uint_t m_uis[32 / mk_lang_charbit / sizeof(mk_win_base_uint_t)];
	mk_win_base_ulong_t m_uls[32 / mk_lang_charbit / sizeof(mk_win_base_ulong_t)];
};
typedef union mk_win_dll_ws2_ipv4_addr_data_u mk_win_dll_ws2_ipv4_addr_data_t;
struct mk_win_dll_ws2_ipv4_addr_s
{
	mk_win_dll_ws2_ipv4_addr_data_t m_data;
};
typedef struct mk_win_dll_ws2_ipv4_addr_s mk_win_dll_ws2_ipv4_addr_t;
mk_lang_typedef(mk_win_dll_ws2_ipv4_addr);

struct mk_win_dll_ws2_sock_addr_ipv4_s
{
	mk_win_base_ushort_t m_family;
	mk_win_base_ushort_t m_port;
	mk_win_dll_ws2_ipv4_addr_t m_address;
	mk_win_base_uchar_t m_zeros[8];
};
typedef struct mk_win_dll_ws2_sock_addr_ipv4_s mk_win_dll_ws2_sock_addr_ipv4_t;
mk_lang_typedef(mk_win_dll_ws2_sock_addr_ipv4);

union mk_win_dll_ws2_ipv6_addr_data_u
{
	mk_win_base_uchar_t m_ucs[128 / mk_lang_charbit / sizeof(mk_win_base_uchar_t)];
	mk_win_base_ushort_t m_uss[128 / mk_lang_charbit / sizeof(mk_win_base_ushort_t)];
	mk_win_base_uint_t m_uis[128 / mk_lang_charbit / sizeof(mk_win_base_uint_t)];
	mk_win_base_ulong_t m_uls[128 / mk_lang_charbit / sizeof(mk_win_base_ulong_t)];
	mk_win_base_ullong_t m_ulls[128 / mk_lang_charbit / sizeof(mk_win_base_ullong_t)];
};
typedef union mk_win_dll_ws2_ipv6_addr_data_u mk_win_dll_ws2_ipv6_addr_data_t;
struct mk_win_dll_ws2_ipv6_addr_s
{
	mk_win_dll_ws2_ipv6_addr_data_t m_data;
};
typedef struct mk_win_dll_ws2_ipv6_addr_s mk_win_dll_ws2_ipv6_addr_t;
mk_lang_typedef(mk_win_dll_ws2_ipv6_addr);

#pragma pack(push, 4)
struct mk_win_dll_ws2_sock_addr_ipv6_s
{
	mk_win_base_ushort_t m_family;
	mk_win_base_ushort_t m_port;
	mk_win_base_ulong_t m_flow_info;
	mk_win_dll_ws2_ipv6_addr_t m_address;
	mk_win_base_ulong_t m_scope_id;
};
typedef struct mk_win_dll_ws2_sock_addr_ipv6_s mk_win_dll_ws2_sock_addr_ipv6_t;
mk_lang_typedef(mk_win_dll_ws2_sock_addr_ipv6);
#pragma pack(pop)

union mk_win_dll_ws2_sock_addr_data_u
{
	mk_win_base_ushort_t m_family;
	mk_win_dll_ws2_sock_addr_ipv4_t m_ipv4;
	mk_win_dll_ws2_sock_addr_ipv6_t m_ipv6;
	mk_win_base_uchar_t m_zeros[2 + 14];
};
typedef union mk_win_dll_ws2_sock_addr_data_u mk_win_dll_ws2_sock_addr_data_t;
struct mk_win_dll_ws2_sock_addr_s
{
	mk_win_dll_ws2_sock_addr_data_t m_data;
};
typedef struct mk_win_dll_ws2_sock_addr_s mk_win_dll_ws2_sock_addr_t;
mk_lang_typedef(mk_win_dll_ws2_sock_addr);

#define mk_win_dll_ws2_fd_max_events (10)
struct mk_win_dll_ws2_network_events_s
{
	mk_lang_types_slong_t m_event_ids;
	mk_lang_types_sint_t m_error_codes[mk_win_dll_ws2_fd_max_events];
};
typedef struct mk_win_dll_ws2_network_events_s mk_win_dll_ws2_network_events_t;
mk_lang_typedef(mk_win_dll_ws2_network_events);

#define mk_sl_cui_t_name mk_win_dll_ws2_socket
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_win_dll_ws2_socket_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_win_dll_ws2_socket_size_bytes_d (mk_lang_bui_uintptr_size_bits_d / mk_lang_charbit)

#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_void_t(mk_win_base_stdcall*mk_win_dll_ws2_completion_routine_t)(mk_win_base_dword_t const error, mk_win_base_dword_t const transfered, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_t const flags) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_void_t mk_win_base_stdcall mk_win_dll_ws2_completion_routine_dummy(mk_win_base_dword_t const error, mk_win_base_dword_t const transfered, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_t const flags) mk_lang_noexcept;
typedef decltype(&mk_win_dll_ws2_completion_routine_dummy) mk_win_dll_ws2_completion_routine_t;
#else
typedef mk_lang_types_void_t(mk_win_base_stdcall*mk_win_dll_ws2_completion_routine_t)(mk_win_base_dword_t const error, mk_win_base_dword_t const transfered, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_t const flags) mk_lang_noexcept;
#endif


#define mk_win_dll_ws2_event_invalid_val mk_win_base_null
#define mk_win_dll_ws2_invalid_socket ((mk_lang_bui_uintptr_t)(~((mk_lang_bui_uintptr_t)(0))))
#define mk_win_dll_ws2_socket_error ((mk_win_base_sint_t)(-1))
#define mk_win_dll_ws2_infinite ((mk_win_base_dword_t)(0xfffffffful))
#define mk_win_dll_ws2_timeout ((mk_win_base_dword_t)(258ul))
#define mk_win_dll_ws2_wait_io_completion ((mk_win_base_dword_t)(0x000000c0ul))
#define mk_win_dll_ws2_wait_failed ((mk_win_base_dword_t)(0xfffffffful))
#define mk_win_dll_ws2_accept_accept 0x0000
#define mk_win_dll_ws2_accept_reject 0x0001
#define mk_win_dll_ws2_accept_defer 0x0002
#define mk_win_dll_ws2_max_conn ((mk_win_base_sint_t)(0x7ffffffful))
#define mk_win_dll_ws2_htons(x) \
	((mk_win_base_ushort_t)( \
		((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(x)) >> (0 * 8))) & ((mk_win_base_ushort_t)(0xff)))) << (1 * 8))) | \
		((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(x)) >> (1 * 8))) & ((mk_win_base_ushort_t)(0xff)))) << (0 * 8))) \
	))
#define mk_win_dll_ws2_ntohs(x) \
	((mk_win_base_ushort_t)( \
		((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(x)) >> (0 * 8))) & ((mk_win_base_ushort_t)(0xff)))) << (1 * 8))) | \
		((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(((mk_win_base_ushort_t)(x)) >> (1 * 8))) & ((mk_win_base_ushort_t)(0xff)))) << (0 * 8))) \
	))
mk_lang_constexpr_static_inline mk_win_dll_ws2_event_t const mk_win_dll_ws2_event_invalid = {mk_win_dll_ws2_event_invalid_val};


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(mk_win_base_stdcall*mk_win_dll_ws2_accept_condition_func_inner_t)(mk_win_dll_ws2_user_data_pt const caller_id, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_qos_pt const sqos, mk_win_dll_ws2_qos_pt const gqos, mk_win_dll_ws2_user_data_pt const callee_id, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_base_uint_pt const group, mk_win_base_uintptr_t const ctx) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_win_base_stdcall mk_win_dll_ws2_accept_condition_func_inner_dummy(mk_win_dll_ws2_user_data_pt const caller_id, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_qos_pt const sqos, mk_win_dll_ws2_qos_pt const gqos, mk_win_dll_ws2_user_data_pt const callee_id, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_base_uint_pt const group, mk_win_base_uintptr_t const ctx) mk_lang_noexcept;
typedef decltype(&mk_win_dll_ws2_accept_condition_func_inner_dummy) mk_win_dll_ws2_accept_condition_func_inner_t;
#else
typedef mk_lang_types_sint_t(mk_win_base_stdcall*mk_win_dll_ws2_accept_condition_func_inner_t)(mk_win_dll_ws2_user_data_pt const caller_id, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_qos_pt const sqos, mk_win_dll_ws2_qos_pt const gqos, mk_win_dll_ws2_user_data_pt const callee_id, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_base_uint_pt const group, mk_win_base_uintptr_t const ctx);
#endif


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_startup(mk_win_base_ushort_t const version_required, mk_win_dll_ws2_data_pt const data) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_cleanup(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_get_last_error(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_event_t mk_win_dll_ws2_create_event(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_close_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_set_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_reset_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socketa(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_a_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socketw(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_w_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_event_select(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_base_ulong_t const evts) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_connect2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_dll_ws2_qos_pt const qos_socket, mk_win_dll_ws2_qos_pt const qos_group) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_accept2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pt const addr_buf, mk_win_base_sint_pt const addr_len, mk_win_dll_ws2_accept_condition_func_inner_t const condition_fnc, mk_win_base_uintptr_t const condition_ctx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_accept_ex(mk_lang_types_void_pct const fn_ptr, mk_win_dll_ws2_socket_t const socket_listen, mk_win_dll_ws2_socket_t const socket_accept, mk_win_base_void_lpt const out_data_buf, mk_win_base_dword_t const out_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_base_dword_lpt const transferred, mk_win_dll_ws2_overlapped_lpt const overlapped) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_dll_ws2_get_accept_ex_sock_addrs(mk_lang_types_void_pct const fn_ptr, mk_win_base_void_lpct const in_data_buf, mk_win_base_dword_t const in_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_dll_ws2_sock_addr_lplpt const local_address_obj, mk_win_base_sint_lpt const local_address_real, mk_win_dll_ws2_sock_addr_lplpt const remote_address_obj, mk_win_base_sint_lpt const remote_address_real) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_ws2_wait_for_multiple_events(mk_win_base_dword_t const count, mk_win_dll_ws2_event_pct const evts, mk_win_base_bool_t const all, mk_win_base_dword_t const timeout, mk_win_base_bool_t const alertable) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_get_overlapped_result(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_lpt const transferred, mk_win_base_bool_t const wait, mk_win_base_dword_lpt const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_send2_ioctl(mk_win_dll_ws2_socket_t const sck, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const in_data_buf, mk_win_base_dword_t const in_data_len, mk_win_base_void_lpt const out_data_buf, mk_win_base_dword_t const out_data_len, mk_win_base_dword_lpt const transferred, mk_win_dll_ws2_overlapped_lpt const overlapped, mk_win_base_void_lpt /* todo */ const callback) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_send2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_pt const sent, mk_win_base_dword_t const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_recv2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_lpt const read, mk_win_base_dword_lpt const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_ulong_t mk_win_dll_ws2_inet_addr(mk_win_base_pchar_pct const address) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socket(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_shutdown(mk_win_dll_ws2_socket_t const sck, mk_lang_types_sint_t const how) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_closesocket(mk_win_dll_ws2_socket_t const sck) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_getsockopt(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const level, mk_win_base_sint_t const opt_name, mk_win_base_void_pt const opt_val_buf, mk_win_base_sint_pt const opt_val_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_setsockopt(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const level, mk_win_base_sint_t const opt_name, mk_win_base_void_pct const opt_val_buf, mk_win_base_sint_t const opt_val_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_getsockname(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pt const addr_buf, mk_win_base_sint_pt const addr_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_getpeername(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pt const addr_buf, mk_win_base_sint_pt const addr_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_connect(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_bind(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_listen(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const backlog) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_send(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_pct const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_recv(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_pt const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_enum_network_events(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_dll_ws2_network_events_pt const network_events) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_win_dll_ws2.c"
#endif
#endif
