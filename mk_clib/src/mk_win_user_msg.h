#ifndef mk_include_guard_mk_win_user_msg
#define mk_include_guard_mk_win_user_msg


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_menu.h"


enum mk_win_user_msg_id_e
{
	mk_win_user_msg_id_e_null                           = 0x0000ul,
	mk_win_user_msg_id_e_create                         = 0x0001ul,
	mk_win_user_msg_id_e_destroy                        = 0x0002ul,
	mk_win_user_msg_id_e_move                           = 0x0003ul,
	mk_win_user_msg_id_e_size                           = 0x0005ul,
	mk_win_user_msg_id_e_activate                       = 0x0006ul,
	mk_win_user_msg_id_e_setfocus                       = 0x0007ul,
	mk_win_user_msg_id_e_killfocus                      = 0x0008ul,
	mk_win_user_msg_id_e_enable                         = 0x000aul,
	mk_win_user_msg_id_e_setredraw                      = 0x000bul,
	mk_win_user_msg_id_e_settext                        = 0x000cul,
	mk_win_user_msg_id_e_gettext                        = 0x000dul,
	mk_win_user_msg_id_e_gettextlength                  = 0x000eul,
	mk_win_user_msg_id_e_paint                          = 0x000ful,
	mk_win_user_msg_id_e_close                          = 0x0010ul,
	mk_win_user_msg_id_e_queryendsession                = 0x0011ul, /* !_win32_wce */
	mk_win_user_msg_id_e_queryopen                      = 0x0013ul, /* !_win32_wce */
	mk_win_user_msg_id_e_endsession                     = 0x0016ul, /* !_win32_wce */
	mk_win_user_msg_id_e_quit                           = 0x0012ul,
	mk_win_user_msg_id_e_erasebkgnd                     = 0x0014ul,
	mk_win_user_msg_id_e_syscolorchange                 = 0x0015ul,
	mk_win_user_msg_id_e_showwindow                     = 0x0018ul,
	mk_win_user_msg_id_e_wininichange                   = 0x001aul,
	mk_win_user_msg_id_e_devmodechange                  = 0x001bul,
	mk_win_user_msg_id_e_activateapp                    = 0x001cul,
	mk_win_user_msg_id_e_fontchange                     = 0x001dul,
	mk_win_user_msg_id_e_timechange                     = 0x001eul,
	mk_win_user_msg_id_e_cancelmode                     = 0x001ful,
	mk_win_user_msg_id_e_setcursor                      = 0x0020ul,
	mk_win_user_msg_id_e_mouseactivate                  = 0x0021ul,
	mk_win_user_msg_id_e_childactivate                  = 0x0022ul,
	mk_win_user_msg_id_e_queuesync                      = 0x0023ul,
	mk_win_user_msg_id_e_getminmaxinfo                  = 0x0024ul,
	mk_win_user_msg_id_e_painticon                      = 0x0026ul,
	mk_win_user_msg_id_e_iconerasebkgnd                 = 0x0027ul,
	mk_win_user_msg_id_e_nextdlgctl                     = 0x0028ul,
	mk_win_user_msg_id_e_spoolerstatus                  = 0x002aul,
	mk_win_user_msg_id_e_drawitem                       = 0x002bul,
	mk_win_user_msg_id_e_measureitem                    = 0x002cul,
	mk_win_user_msg_id_e_deleteitem                     = 0x002dul,
	mk_win_user_msg_id_e_vkeytoitem                     = 0x002eul,
	mk_win_user_msg_id_e_chartoitem                     = 0x002ful,
	mk_win_user_msg_id_e_setfont                        = 0x0030ul,
	mk_win_user_msg_id_e_getfont                        = 0x0031ul,
	mk_win_user_msg_id_e_sethotkey                      = 0x0032ul,
	mk_win_user_msg_id_e_gethotkey                      = 0x0033ul,
	mk_win_user_msg_id_e_querydragicon                  = 0x0037ul,
	mk_win_user_msg_id_e_compareitem                    = 0x0039ul,
	mk_win_user_msg_id_e_getobject                      = 0x003dul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_compacting                     = 0x0041ul,
	mk_win_user_msg_id_e_commnotify                     = 0x0044ul,  /* no longer suported */
	mk_win_user_msg_id_e_windowposchanging              = 0x0046ul,
	mk_win_user_msg_id_e_windowposchanged               = 0x0047ul,
	mk_win_user_msg_id_e_power                          = 0x0048ul,
	mk_win_user_msg_id_e_copydata                       = 0x004aul,
	mk_win_user_msg_id_e_canceljournal                  = 0x004bul,
	mk_win_user_msg_id_e_notify                         = 0x004eul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_inputlangchangerequest         = 0x0050ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_inputlangchange                = 0x0051ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_tcard                          = 0x0052ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_help                           = 0x0053ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_userchanged                    = 0x0054ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_notifyformat                   = 0x0055ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_contextmenu                    = 0x007bul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_stylechanging                  = 0x007cul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_stylechanged                   = 0x007dul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_displaychange                  = 0x007eul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_geticon                        = 0x007ful, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_seticon                        = 0x0080ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_nccreate                       = 0x0081ul,
	mk_win_user_msg_id_e_ncdestroy                      = 0x0082ul,
	mk_win_user_msg_id_e_nccalcsize                     = 0x0083ul,
	mk_win_user_msg_id_e_nchittest                      = 0x0084ul,
	mk_win_user_msg_id_e_ncpaint                        = 0x0085ul,
	mk_win_user_msg_id_e_ncactivate                     = 0x0086ul,
	mk_win_user_msg_id_e_getdlgcode                     = 0x0087ul,
	mk_win_user_msg_id_e_syncpaint                      = 0x0088ul, /* !_win32_wce */
	mk_win_user_msg_id_e_ncmousemove                    = 0x00a0ul,
	mk_win_user_msg_id_e_nclbuttondown                  = 0x00a1ul,
	mk_win_user_msg_id_e_nclbuttonup                    = 0x00a2ul,
	mk_win_user_msg_id_e_nclbuttondblclk                = 0x00a3ul,
	mk_win_user_msg_id_e_ncrbuttondown                  = 0x00a4ul,
	mk_win_user_msg_id_e_ncrbuttonup                    = 0x00a5ul,
	mk_win_user_msg_id_e_ncrbuttondblclk                = 0x00a6ul,
	mk_win_user_msg_id_e_ncmbuttondown                  = 0x00a7ul,
	mk_win_user_msg_id_e_ncmbuttonup                    = 0x00a8ul,
	mk_win_user_msg_id_e_ncmbuttondblclk                = 0x00a9ul,
	mk_win_user_msg_id_e_ncxbuttondown                  = 0x00abul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_ncxbuttonup                    = 0x00acul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_ncxbuttondblclk                = 0x00adul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_input_device_change            = 0x00feul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_input                          = 0x00fful, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_keydown                        = 0x0100ul,
	mk_win_user_msg_id_e_keyup                          = 0x0101ul,
	mk_win_user_msg_id_e_char                           = 0x0102ul,
	mk_win_user_msg_id_e_deadchar                       = 0x0103ul,
	mk_win_user_msg_id_e_syskeydown                     = 0x0104ul,
	mk_win_user_msg_id_e_syskeyup                       = 0x0105ul,
	mk_win_user_msg_id_e_syschar                        = 0x0106ul,
	mk_win_user_msg_id_e_sysdeadchar                    = 0x0107ul,
	mk_win_user_msg_id_e_unichar                        = 0x0109ul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_ime_startcomposition           = 0x010dul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_endcomposition             = 0x010eul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_composition                = 0x010ful, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_initdialog                     = 0x0110ul,
	mk_win_user_msg_id_e_command                        = 0x0111ul,
	mk_win_user_msg_id_e_syscommand                     = 0x0112ul,
	mk_win_user_msg_id_e_timer                          = 0x0113ul,
	mk_win_user_msg_id_e_hscroll                        = 0x0114ul,
	mk_win_user_msg_id_e_vscroll                        = 0x0115ul,
	mk_win_user_msg_id_e_initmenu                       = 0x0116ul,
	mk_win_user_msg_id_e_initmenupopup                  = 0x0117ul,
	mk_win_user_msg_id_e_gesture                        = 0x0119ul, /* winver >= 0x0601 */
	mk_win_user_msg_id_e_gesturenotify                  = 0x011aul, /* winver >= 0x0601 */
	mk_win_user_msg_id_e_menuselect                     = 0x011ful,
	mk_win_user_msg_id_e_menuchar                       = 0x0120ul,
	mk_win_user_msg_id_e_enteridle                      = 0x0121ul,
	mk_win_user_msg_id_e_menurbuttonup                  = 0x0122ul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_menudrag                       = 0x0123ul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_menugetobject                  = 0x0124ul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_uninitmenupopup                = 0x0125ul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_menucommand                    = 0x0126ul, /* !_win32_wce && winver >= 0x0500 */
	mk_win_user_msg_id_e_changeuistate                  = 0x0127ul, /* !_win32_wce && _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_updateuistate                  = 0x0128ul, /* !_win32_wce && _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_queryuistate                   = 0x0129ul, /* !_win32_wce && _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_ctlcolormsgbox                 = 0x0132ul,
	mk_win_user_msg_id_e_ctlcoloredit                   = 0x0133ul,
	mk_win_user_msg_id_e_ctlcolorlistbox                = 0x0134ul,
	mk_win_user_msg_id_e_ctlcolorbtn                    = 0x0135ul,
	mk_win_user_msg_id_e_ctlcolordlg                    = 0x0136ul,
	mk_win_user_msg_id_e_ctlcolorscrollbar              = 0x0137ul,
	mk_win_user_msg_id_e_ctlcolorstatic                 = 0x0138ul,
	mk_win_user_msg_id_e_mousemove                      = 0x0200ul,
	mk_win_user_msg_id_e_lbuttondown                    = 0x0201ul,
	mk_win_user_msg_id_e_lbuttonup                      = 0x0202ul,
	mk_win_user_msg_id_e_lbuttondblclk                  = 0x0203ul,
	mk_win_user_msg_id_e_rbuttondown                    = 0x0204ul,
	mk_win_user_msg_id_e_rbuttonup                      = 0x0205ul,
	mk_win_user_msg_id_e_rbuttondblclk                  = 0x0206ul,
	mk_win_user_msg_id_e_mbuttondown                    = 0x0207ul,
	mk_win_user_msg_id_e_mbuttonup                      = 0x0208ul,
	mk_win_user_msg_id_e_mbuttondblclk                  = 0x0209ul,
	mk_win_user_msg_id_e_mousewheel                     = 0x020aul, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_msg_id_e_xbuttondown                    = 0x020bul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_xbuttonup                      = 0x020cul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_xbuttondblclk                  = 0x020dul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_mousehwheel                    = 0x020eul, /* _win32_winnt >= 0x0600 */
	mk_win_user_msg_id_e_parentnotify                   = 0x0210ul,
	mk_win_user_msg_id_e_entermenuloop                  = 0x0211ul,
	mk_win_user_msg_id_e_exitmenuloop                   = 0x0212ul,
	mk_win_user_msg_id_e_nextmenu                       = 0x0213ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_sizing                         = 0x0214ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_capturechanged                 = 0x0215ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_moving                         = 0x0216ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_powerbroadcast                 = 0x0218ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_devicechange                   = 0x0219ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_mdicreate                      = 0x0220ul,
	mk_win_user_msg_id_e_mdidestroy                     = 0x0221ul,
	mk_win_user_msg_id_e_mdiactivate                    = 0x0222ul,
	mk_win_user_msg_id_e_mdirestore                     = 0x0223ul,
	mk_win_user_msg_id_e_mdinext                        = 0x0224ul,
	mk_win_user_msg_id_e_mdimaximize                    = 0x0225ul,
	mk_win_user_msg_id_e_mditile                        = 0x0226ul,
	mk_win_user_msg_id_e_mdicascade                     = 0x0227ul,
	mk_win_user_msg_id_e_mdiiconarrange                 = 0x0228ul,
	mk_win_user_msg_id_e_mdigetactive                   = 0x0229ul,
	mk_win_user_msg_id_e_mdisetmenu                     = 0x0230ul,
	mk_win_user_msg_id_e_entersizemove                  = 0x0231ul,
	mk_win_user_msg_id_e_exitsizemove                   = 0x0232ul,
	mk_win_user_msg_id_e_dropfiles                      = 0x0233ul,
	mk_win_user_msg_id_e_mdirefreshmenu                 = 0x0234ul,
	mk_win_user_msg_id_e_pointerdevicechange            = 0x0238ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerdeviceinrange           = 0x0239ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerdeviceoutofrange        = 0x023aul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_touch                          = 0x0240ul, /* winver >= 0x0601 */
	mk_win_user_msg_id_e_ncpointerupdate                = 0x0241ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_ncpointerdown                  = 0x0242ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_ncpointerup                    = 0x0243ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerupdate                  = 0x0245ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerdown                    = 0x0246ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerup                      = 0x0247ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerenter                   = 0x0249ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerleave                   = 0x024aul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointeractivate                = 0x024bul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointercapturechanged          = 0x024cul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_touchhittesting                = 0x024dul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerwheel                   = 0x024eul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerhwheel                  = 0x024ful, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerroutedto                = 0x0251ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerroutedaway              = 0x0252ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_pointerroutedreleased          = 0x0253ul, /* winver >= 0x0602 */
	mk_win_user_msg_id_e_ime_setcontext                 = 0x0281ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_notify                     = 0x0282ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_control                    = 0x0283ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_compositionfull            = 0x0284ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_select                     = 0x0285ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_char                       = 0x0286ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_request                    = 0x0288ul, /* winver >= 0x0500 */
	mk_win_user_msg_id_e_ime_keydown                    = 0x0290ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_ime_keyup                      = 0x0291ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_mousehover                     = 0x02a1ul, /* _win32_winnt >= 0x0400 || winver >= 0x0500 */
	mk_win_user_msg_id_e_mouseleave                     = 0x02a3ul, /* _win32_winnt >= 0x0400 || winver >= 0x0500 */
	mk_win_user_msg_id_e_ncmousehover                   = 0x02a0ul, /* winver >= 0x0500 */
	mk_win_user_msg_id_e_ncmouseleave                   = 0x02a2ul, /* winver >= 0x0500 */
	mk_win_user_msg_id_e_wtssession_change              = 0x02b1ul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_tablet_first                   = 0x02c0ul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_tablet_last                    = 0x02dful, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_dpichanged                     = 0x02e0ul, /* winver >= 0x0601 */
	mk_win_user_msg_id_e_dpichanged_beforeparent        = 0x02e2ul, /* winver >= 0x0605 */
	mk_win_user_msg_id_e_dpichanged_afterparent         = 0x02e3ul, /* winver >= 0x0605 */
	mk_win_user_msg_id_e_getdpiscaledsize               = 0x02e4ul, /* winver >= 0x0605 */
	mk_win_user_msg_id_e_cut                            = 0x0300ul,
	mk_win_user_msg_id_e_copy                           = 0x0301ul,
	mk_win_user_msg_id_e_paste                          = 0x0302ul,
	mk_win_user_msg_id_e_clear                          = 0x0303ul,
	mk_win_user_msg_id_e_undo                           = 0x0304ul,
	mk_win_user_msg_id_e_renderformat                   = 0x0305ul,
	mk_win_user_msg_id_e_renderallformats               = 0x0306ul,
	mk_win_user_msg_id_e_destroyclipboard               = 0x0307ul,
	mk_win_user_msg_id_e_drawclipboard                  = 0x0308ul,
	mk_win_user_msg_id_e_paintclipboard                 = 0x0309ul,
	mk_win_user_msg_id_e_vscrollclipboard               = 0x030aul,
	mk_win_user_msg_id_e_sizeclipboard                  = 0x030bul,
	mk_win_user_msg_id_e_askcbformatname                = 0x030cul,
	mk_win_user_msg_id_e_changecbchain                  = 0x030dul,
	mk_win_user_msg_id_e_hscrollclipboard               = 0x030eul,
	mk_win_user_msg_id_e_querynewpalette                = 0x030ful,
	mk_win_user_msg_id_e_paletteischanging              = 0x0310ul,
	mk_win_user_msg_id_e_palettechanged                 = 0x0311ul,
	mk_win_user_msg_id_e_hotkey                         = 0x0312ul,
	mk_win_user_msg_id_e_print                          = 0x0317ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_printclient                    = 0x0318ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_appcommand                     = 0x0319ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_msg_id_e_themechanged                   = 0x031aul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_clipboardupdate                = 0x031dul, /* _win32_winnt >= 0x0501 */
	mk_win_user_msg_id_e_dwmcompositionchanged          = 0x031eul, /* _win32_winnt >= 0x0600 */
	mk_win_user_msg_id_e_dwmncrenderingchanged          = 0x031ful, /* _win32_winnt >= 0x0600 */
	mk_win_user_msg_id_e_dwmcolorizationcolorchanged    = 0x0320ul, /* _win32_winnt >= 0x0600 */
	mk_win_user_msg_id_e_dwmwindowmaximizedchange       = 0x0321ul, /* _win32_winnt >= 0x0600 */
	mk_win_user_msg_id_e_dwmsendiconicthumbnail         = 0x0323ul, /* _win32_winnt >= 0x0601 */
	mk_win_user_msg_id_e_dwmsendiconiclivepreviewbitmap = 0x0326ul, /* _win32_winnt >= 0x0601 */
	mk_win_user_msg_id_e_gettitlebarinfoex              = 0x033ful, /* winver >= 0x0600 */
	mk_win_user_msg_id_e_handheldfirst                  = 0x0358ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_handheldlast                   = 0x035ful, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_afxfirst                       = 0x0360ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_afxlast                        = 0x037ful, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_penwinfirst                    = 0x0380ul,
	mk_win_user_msg_id_e_penwinlast                     = 0x038ful,
	mk_win_user_msg_id_e_user                           = 0x0400ul,
	mk_win_user_msg_id_e_app                            = 0x8000ul, /* winver >= 0x0400 */
	mk_win_user_msg_id_e_settingchange                  = mk_win_user_msg_id_e_wininichange, /* winver >= 0x0400 */
};
typedef enum mk_win_user_msg_id_e mk_win_user_msg_id_t;

enum mk_win_user_msg_vk_e
{
	mk_win_user_msg_vk_e_back   = 0x08,
	mk_win_user_msg_vk_e_return = 0x0d,
	mk_win_user_msg_vk_e_prior  = 0x21,
	mk_win_user_msg_vk_e_next   = 0x22,
	mk_win_user_msg_vk_e_end    = 0x23,
	mk_win_user_msg_vk_e_home   = 0x24,
	mk_win_user_msg_vk_e_left   = 0x25,
	mk_win_user_msg_vk_e_up     = 0x26,
	mk_win_user_msg_vk_e_right  = 0x27,
	mk_win_user_msg_vk_e_down   = 0x28,
	mk_win_user_msg_vk_e_dummy_end
};
typedef enum mk_win_user_msg_vk_e mk_win_user_msg_vk_t;

enum mk_win_user_msg_sb_e
{
	mk_win_user_msg_sb_e_lineup        = 0,
	mk_win_user_msg_sb_e_lineleft      = 0,
	mk_win_user_msg_sb_e_linedown      = 1,
	mk_win_user_msg_sb_e_lineright     = 1,
	mk_win_user_msg_sb_e_pageup        = 2,
	mk_win_user_msg_sb_e_pageleft      = 2,
	mk_win_user_msg_sb_e_pagedown      = 3,
	mk_win_user_msg_sb_e_pageright     = 3,
	mk_win_user_msg_sb_e_thumbposition = 4,
	mk_win_user_msg_sb_e_thumbtrack    = 5,
	mk_win_user_msg_sb_e_top           = 6,
	mk_win_user_msg_sb_e_left          = 6,
	mk_win_user_msg_sb_e_bottom        = 7,
	mk_win_user_msg_sb_e_right         = 7,
	mk_win_user_msg_sb_e_endscroll     = 8,
	mk_win_user_msg_sb_e_dummy_end
};
typedef enum mk_win_user_msg_sb_e mk_win_user_msg_sb_t;


struct mk_win_user_msg_s
{
	mk_win_user_base_wnd_t m_wnd;
	mk_win_base_uint_t m_msg;
	mk_win_user_base_lparam_t m_wparam;
	mk_win_user_base_lparam_t m_lparam;
	mk_win_base_dword_t m_time;
	mk_win_base_point_t m_pt;
};
typedef struct mk_win_user_msg_s mk_win_user_msg_t;
typedef mk_win_user_msg_t const mk_win_user_msg_ct;
typedef mk_win_user_msg_t* mk_win_user_msg_pt;
typedef mk_win_user_msg_t const* mk_win_user_msg_pct;
typedef mk_win_user_msg_t mk_win_base_far* mk_win_user_msg_lpt;
typedef mk_win_user_msg_t mk_win_base_far const* mk_win_user_msg_lpct;
typedef mk_win_user_msg_t mk_win_base_near* mk_win_user_msg_npt;
typedef mk_win_user_msg_t mk_win_base_near const* mk_win_user_msg_npct;
typedef mk_win_user_msg_t* mk_lang_restrict mk_win_user_msg_prt;
typedef mk_win_user_msg_t const* mk_lang_restrict mk_win_user_msg_prct;
typedef mk_win_user_msg_t mk_win_base_far* mk_lang_restrict mk_win_user_msg_lprt;
typedef mk_win_user_msg_t mk_win_base_far const* mk_lang_restrict mk_win_user_msg_lprct;
typedef mk_win_user_msg_t mk_win_base_near* mk_lang_restrict mk_win_user_msg_nprt;
typedef mk_win_user_msg_t mk_win_base_near const* mk_lang_restrict mk_win_user_msg_nprct;

struct mk_win_user_msg_createa_s
{
	mk_win_base_void_lpt m_param;
	mk_win_base_instance_t m_instance;
	mk_win_user_menu_t m_menu;
	mk_win_user_base_wnd_t m_parent;
	mk_win_base_sint_t m_h;
	mk_win_base_sint_t m_w;
	mk_win_base_sint_t m_y;
	mk_win_base_sint_t m_x;
	mk_win_base_slong_t m_style;
	mk_win_base_pchar_lpct m_name;
	mk_win_base_pchar_lpct m_class;
	mk_win_base_dword_t m_styleex;
};
typedef struct mk_win_user_msg_createa_s mk_win_user_msg_createa_t;
typedef mk_win_user_msg_createa_t const mk_win_user_msg_createa_ct;
typedef mk_win_user_msg_createa_t* mk_win_user_msg_createa_pt;
typedef mk_win_user_msg_createa_t const* mk_win_user_msg_createa_pct;
typedef mk_win_user_msg_createa_t mk_win_base_far* mk_win_user_msg_createa_lpt;
typedef mk_win_user_msg_createa_t mk_win_base_far const* mk_win_user_msg_createa_lpct;
typedef mk_win_user_msg_createa_t mk_win_base_near* mk_win_user_msg_createa_npt;
typedef mk_win_user_msg_createa_t mk_win_base_near const* mk_win_user_msg_createa_npct;
typedef mk_win_user_msg_createa_t* mk_lang_restrict mk_win_user_msg_createa_prt;
typedef mk_win_user_msg_createa_t const* mk_lang_restrict mk_win_user_msg_createa_prct;
typedef mk_win_user_msg_createa_t mk_win_base_far* mk_lang_restrict mk_win_user_msg_createa_lprt;
typedef mk_win_user_msg_createa_t mk_win_base_far const* mk_lang_restrict mk_win_user_msg_createa_lprct;
typedef mk_win_user_msg_createa_t mk_win_base_near* mk_lang_restrict mk_win_user_msg_createa_nprt;
typedef mk_win_user_msg_createa_t mk_win_base_near const* mk_lang_restrict mk_win_user_msg_createa_nprct;

struct mk_win_user_msg_createw_s
{
	mk_win_base_void_lpt m_param;
	mk_win_base_instance_t m_instance;
	mk_win_user_menu_t m_menu;
	mk_win_user_base_wnd_t m_parent;
	mk_win_base_sint_t m_h;
	mk_win_base_sint_t m_w;
	mk_win_base_sint_t m_y;
	mk_win_base_sint_t m_x;
	mk_win_base_slong_t m_style;
	mk_win_base_wchar_lpct m_name;
	mk_win_base_wchar_lpct m_class;
	mk_win_base_dword_t m_styleex;
};
typedef struct mk_win_user_msg_createw_s mk_win_user_msg_createw_t;
typedef mk_win_user_msg_createw_t const mk_win_user_msg_createw_ct;
typedef mk_win_user_msg_createw_t* mk_win_user_msg_createw_pt;
typedef mk_win_user_msg_createw_t const* mk_win_user_msg_createw_pct;
typedef mk_win_user_msg_createw_t mk_win_base_far* mk_win_user_msg_createw_lpt;
typedef mk_win_user_msg_createw_t mk_win_base_far const* mk_win_user_msg_createw_lpct;
typedef mk_win_user_msg_createw_t mk_win_base_near* mk_win_user_msg_createw_npt;
typedef mk_win_user_msg_createw_t mk_win_base_near const* mk_win_user_msg_createw_npct;
typedef mk_win_user_msg_createw_t* mk_lang_restrict mk_win_user_msg_createw_prt;
typedef mk_win_user_msg_createw_t const* mk_lang_restrict mk_win_user_msg_createw_prct;
typedef mk_win_user_msg_createw_t mk_win_base_far* mk_lang_restrict mk_win_user_msg_createw_lprt;
typedef mk_win_user_msg_createw_t mk_win_base_far const* mk_lang_restrict mk_win_user_msg_createw_lprct;
typedef mk_win_user_msg_createw_t mk_win_base_near* mk_lang_restrict mk_win_user_msg_createw_nprt;
typedef mk_win_user_msg_createw_t mk_win_base_near const* mk_lang_restrict mk_win_user_msg_createw_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_msg_w_get(mk_win_user_msg_lpt const msg, mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t fmin, mk_win_base_uint_t const fmax) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_msg_translate(mk_win_user_msg_lpct const msg) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_msg_w_dispatch(mk_win_user_msg_lpct const msg) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_user_msg_post_quit(mk_win_base_sint_t const exit_code) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_msg.c"
#endif
#endif
