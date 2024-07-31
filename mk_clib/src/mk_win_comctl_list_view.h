#ifndef mk_include_guard_mk_win_comctl_list_view
#define mk_include_guard_mk_win_comctl_list_view


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_comctl_base.h"


#define mk_win_comctl_list_view_class_name_a  "SysListView32"
#define mk_win_comctl_list_view_class_name_w L"SysListView32"

enum mk_win_comctl_list_view_window_style_id_e
{
	mk_win_comctl_list_view_window_style_id_e_aligntop        = 0x0000ul,
	mk_win_comctl_list_view_window_style_id_e_icon            = 0x0000ul,
	mk_win_comctl_list_view_window_style_id_e_report          = 0x0001ul,
	mk_win_comctl_list_view_window_style_id_e_smallicon       = 0x0002ul,
	mk_win_comctl_list_view_window_style_id_e_list            = 0x0003ul,
	mk_win_comctl_list_view_window_style_id_e_typemask        = 0x0003ul,
	mk_win_comctl_list_view_window_style_id_e_singlesel       = 0x0004ul,
	mk_win_comctl_list_view_window_style_id_e_showselalways   = 0x0008ul,
	mk_win_comctl_list_view_window_style_id_e_sortascending   = 0x0010ul,
	mk_win_comctl_list_view_window_style_id_e_sortdescending  = 0x0020ul,
	mk_win_comctl_list_view_window_style_id_e_shareimagelists = 0x0040ul,
	mk_win_comctl_list_view_window_style_id_e_nolabelwrap     = 0x0080ul,
	mk_win_comctl_list_view_window_style_id_e_autoarrange     = 0x0100ul,
	mk_win_comctl_list_view_window_style_id_e_editlabels      = 0x0200ul,
	mk_win_comctl_list_view_window_style_id_e_ownerdrawfixed  = 0x0400ul,
	mk_win_comctl_list_view_window_style_id_e_alignleft       = 0x0800ul,
	mk_win_comctl_list_view_window_style_id_e_alignmask       = 0x0c00ul,
	mk_win_comctl_list_view_window_style_id_e_ownerdata       = 0x1000ul,
	mk_win_comctl_list_view_window_style_id_e_noscroll        = 0x2000ul,
	mk_win_comctl_list_view_window_style_id_e_nocolumnheader  = 0x4000ul,
	mk_win_comctl_list_view_window_style_id_e_nosortheader    = 0x8000ul,
	mk_win_comctl_list_view_window_style_id_e_typestylemask   = 0xfc00ul,
	mk_win_comctl_list_view_window_style_id_e_dummy_end
};
typedef enum mk_win_comctl_list_view_window_style_id_e mk_win_comctl_list_view_window_style_id_t;

enum mk_win_comctl_list_view_window_styleex_id_e
{
	mk_win_comctl_list_view_window_styleex_id_e_gridlines             = 0x00000001ul,
	mk_win_comctl_list_view_window_styleex_id_e_subitemimages         = 0x00000002ul,
	mk_win_comctl_list_view_window_styleex_id_e_checkboxes            = 0x00000004ul,
	mk_win_comctl_list_view_window_styleex_id_e_trackselect           = 0x00000008ul,
	mk_win_comctl_list_view_window_styleex_id_e_headerdragdrop        = 0x00000010ul,
	mk_win_comctl_list_view_window_styleex_id_e_fullrowselect         = 0x00000020ul,
	mk_win_comctl_list_view_window_styleex_id_e_oneclickactivate      = 0x00000040ul,
	mk_win_comctl_list_view_window_styleex_id_e_twoclickactivate      = 0x00000080ul,
	mk_win_comctl_list_view_window_styleex_id_e_flatsb                = 0x00000100ul,
	mk_win_comctl_list_view_window_styleex_id_e_regional              = 0x00000200ul,
	mk_win_comctl_list_view_window_styleex_id_e_infotip               = 0x00000400ul,
	mk_win_comctl_list_view_window_styleex_id_e_underlinehot          = 0x00000800ul,
	mk_win_comctl_list_view_window_styleex_id_e_underlinecold         = 0x00001000ul,
	mk_win_comctl_list_view_window_styleex_id_e_multiworkareas        = 0x00002000ul,
	mk_win_comctl_list_view_window_styleex_id_e_labeltip              = 0x00004000ul,
	mk_win_comctl_list_view_window_styleex_id_e_borderselect          = 0x00008000ul,
	mk_win_comctl_list_view_window_styleex_id_e_doublebuffer          = 0x00010000ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_window_styleex_id_e_hidelabels            = 0x00020000ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_window_styleex_id_e_singlerow             = 0x00040000ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_window_styleex_id_e_snaptogrid            = 0x00080000ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_window_styleex_id_e_simpleselect          = 0x00100000ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_window_styleex_id_e_justifycolumns        = 0x00200000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_transparentbkgnd      = 0x00400000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_transparentshadowtext = 0x00800000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_autoautoarrange       = 0x01000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_headerinallviews      = 0x02000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_autocheckselect       = 0x08000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_autosizecolumns       = 0x10000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_columnsnappoints      = 0x40000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_columnoverflow        = 0x80000000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_window_styleex_id_e_dummy_end
};
typedef enum mk_win_comctl_list_view_window_styleex_id_e mk_win_comctl_list_view_window_styleex_id_t;

enum mk_win_comctl_list_view_msg_id_e
{
	mk_win_comctl_list_view_msg_id_e_first                    = 0x1000ul,
	mk_win_comctl_list_view_msg_id_e_setitemcount             = mk_win_comctl_list_view_msg_id_e_first + 47ul,
	mk_win_comctl_list_view_msg_id_e_setextendedlistviewstyle = mk_win_comctl_list_view_msg_id_e_first + 54ul,
	mk_win_comctl_list_view_msg_id_e_insertcolumnw            = mk_win_comctl_list_view_msg_id_e_first + 97ul,
	mk_win_comctl_list_view_msg_id_e_dummy_end
};
typedef enum mk_win_comctl_list_view_msg_id_e mk_win_comctl_list_view_msg_id_t;

enum mk_win_comctl_list_view_col_mask_e
{
	mk_win_comctl_list_view_col_mask_e_fmt          = 0x0001ul,
	mk_win_comctl_list_view_col_mask_e_width        = 0x0002ul,
	mk_win_comctl_list_view_col_mask_e_text         = 0x0004ul,
	mk_win_comctl_list_view_col_mask_e_subitem      = 0x0008ul,
	mk_win_comctl_list_view_col_mask_e_image        = 0x0010ul,
	mk_win_comctl_list_view_col_mask_e_order        = 0x0020ul,
	mk_win_comctl_list_view_col_mask_e_minwidth     = 0x0040ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_mask_e_defaultwidth = 0x0080ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_mask_e_idealwidth   = 0x0100ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_mask_e_dummy_end
};
typedef enum mk_win_comctl_list_view_col_mask_e mk_win_comctl_list_view_col_mask_t;

enum mk_win_comctl_list_view_col_fmt_e
{
	mk_win_comctl_list_view_col_fmt_e_left           	= 0x00000000,
	mk_win_comctl_list_view_col_fmt_e_right          	= 0x00000001,
	mk_win_comctl_list_view_col_fmt_e_center         	= 0x00000002,
	mk_win_comctl_list_view_col_fmt_e_justifymask    	= 0x00000003,
	mk_win_comctl_list_view_col_fmt_e_image          	= 0x00000800,
	mk_win_comctl_list_view_col_fmt_e_bitmap_on_right	= 0x00001000,
	mk_win_comctl_list_view_col_fmt_e_col_has_images 	= 0x00008000,
	mk_win_comctl_list_view_col_fmt_e_fixed_width    	= 0x00000100, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_no_dpi_scale   	= 0x00040000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_fixed_ratio    	= 0x00080000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_line_break     	= 0x00100000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_fill           	= 0x00200000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_wrap           	= 0x00400000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_no_title       	= 0x00800000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_splitbutton    	= 0x01000000, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_col_fmt_e_tile_placementmask = (mk_win_comctl_list_view_col_fmt_e_line_break | mk_win_comctl_list_view_col_fmt_e_fill),
	mk_win_comctl_list_view_col_fmt_e_dummy_end
};
typedef enum mk_win_comctl_list_view_col_fmt_e mk_win_comctl_list_view_col_fmt_t;

enum mk_win_comctl_list_view_notification_id_e
{
	mk_win_comctl_list_view_notification_id_e_first        = ((mk_win_base_dword_t)(0ul)) - ((mk_win_base_dword_t)(100ul)),
	mk_win_comctl_list_view_notification_id_e_getdispinfow = ((mk_win_base_dword_t)(mk_win_comctl_list_view_notification_id_e_first)) - ((mk_win_base_dword_t)(77ul)),
	mk_win_comctl_list_view_notification_id_e_dummy_end
};
typedef enum mk_win_comctl_list_view_notification_id_e mk_win_comctl_list_view_notification_id_t;

enum mk_win_comctl_list_view_item_mask_e
{
	mk_win_comctl_list_view_item_mask_e_text        = 0x00000001ul,
	mk_win_comctl_list_view_item_mask_e_image       = 0x00000002ul,
	mk_win_comctl_list_view_item_mask_e_param       = 0x00000004ul,
	mk_win_comctl_list_view_item_mask_e_state       = 0x00000008ul,
	mk_win_comctl_list_view_item_mask_e_indent      = 0x00000010ul,
	mk_win_comctl_list_view_item_mask_e_groupid     = 0x00000100ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_item_mask_e_columns     = 0x00000200ul, /* ntddi_version >= ntddi_winxp */
	mk_win_comctl_list_view_item_mask_e_norecompute = 0x00000800ul,
	mk_win_comctl_list_view_item_mask_e_colfmt      = 0x00010000ul, /* ntddi_version >= ntddi_vista */
	mk_win_comctl_list_view_item_mask_e_dummy_end
};
typedef enum mk_win_comctl_list_view_item_mask_e mk_win_comctl_list_view_item_mask_t;

struct mk_win_comctl_list_view_column_descr_w_v1_s
{
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_fmt;
	mk_win_base_sint_t m_cx;
	mk_win_base_wchar_lpt m_text_buf;
	mk_win_base_sint_t m_text_len;
	mk_win_base_sint_t m_sub_item;
	mk_win_base_sint_t m_image;
	mk_win_base_sint_t m_order;
};
typedef struct mk_win_comctl_list_view_column_descr_w_v1_s mk_win_comctl_list_view_column_descr_w_v1_t;

struct mk_win_comctl_list_view_column_descr_w_v2_s
{
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_fmt;
	mk_win_base_sint_t m_cx;
	mk_win_base_wchar_lpt m_text_buf;
	mk_win_base_sint_t m_text_len;
	mk_win_base_sint_t m_sub_item;
	mk_win_base_sint_t m_image;
	mk_win_base_sint_t m_order;
	mk_win_base_sint_t m_snap_min; /* _win32_winnt && _win32_winnt >= 0x0600 */
	mk_win_base_sint_t m_snap_def; /* _win32_winnt && _win32_winnt >= 0x0600 */
	mk_win_base_sint_t m_text_idl; /* _win32_winnt && _win32_winnt >= 0x0600 */
};
typedef struct mk_win_comctl_list_view_column_descr_w_v2_s mk_win_comctl_list_view_column_descr_w_v2_t;

struct mk_win_comctl_list_view_item_w_s
{
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_item;
	mk_win_base_sint_t m_sub_item;
	mk_win_base_uint_t m_state_value;
	mk_win_base_uint_t m_state_mask;
	mk_win_base_wchar_lpt m_text_buf;
	mk_win_base_sint_t m_text_len;
	mk_win_base_sint_t m_image;
	mk_win_user_base_lparam_t m_lparam;
	mk_win_base_sint_t m_indent;
	mk_win_base_sint_t m_group_id; /* ntddi_version >= ntddi_winxp */
	mk_win_base_uint_t m_columns_cnt; /* ntddi_version >= ntddi_winxp */
	mk_win_base_uint_pt m_columns_buf; /* ntddi_version >= ntddi_winxp */
	mk_win_base_sint_pt m_col_fmt; /* ntddi_version >= ntddi_vista */
	mk_win_base_sint_t m_group; /* ntddi_version >= ntddi_vista */
};
typedef struct mk_win_comctl_list_view_item_w_s mk_win_comctl_list_view_item_w_t;

struct mk_win_comctl_list_view_notify_dispinfo_w_s
{
	mk_win_comctl_base_nmhdr_t m_nmhdr;
	mk_win_comctl_list_view_item_w_t m_item;
};
typedef struct mk_win_comctl_list_view_notify_dispinfo_w_s mk_win_comctl_list_view_notify_dispinfo_w_t;
typedef mk_win_comctl_list_view_notify_dispinfo_w_t* mk_win_comctl_list_view_notify_dispinfo_w_pt;


/*mk_lang_jumbo mk_lang_types_void_t mk_win_comctl_list_view_init(mk_lang_types_void_t) mk_lang_noexcept;*/


#if mk_lang_jumbo_want == 1
#include "mk_win_comctl_list_view.c"
#endif
#endif
