#ifndef mk_include_guard_win_user_message
#define mk_include_guard_win_user_message


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_user_window.h"


enum mk_win_user_message_id_e
{
	mk_win_user_message_id_e_null                           = 0x0000, /*     0 */
	mk_win_user_message_id_e_create                         = 0x0001, /*     1 */
	mk_win_user_message_id_e_destroy                        = 0x0002, /*     2 */
	mk_win_user_message_id_e_move                           = 0x0003, /*     3 */
	mk_win_user_message_id_e_size                           = 0x0005, /*     5 */
	mk_win_user_message_id_e_activate                       = 0x0006, /*     6 */
	mk_win_user_message_id_e_setfocus                       = 0x0007, /*     7 */
	mk_win_user_message_id_e_killfocus                      = 0x0008, /*     8 */
	mk_win_user_message_id_e_enable                         = 0x000a, /*    10 */
	mk_win_user_message_id_e_setredraw                      = 0x000b, /*    11 */
	mk_win_user_message_id_e_settext                        = 0x000c, /*    12 */
	mk_win_user_message_id_e_gettext                        = 0x000d, /*    13 */
	mk_win_user_message_id_e_gettextlength                  = 0x000e, /*    14 */
	mk_win_user_message_id_e_paint                          = 0x000f, /*    15 */
	mk_win_user_message_id_e_close                          = 0x0010, /*    16 */
	mk_win_user_message_id_e_queryendsession                = 0x0011, /*    17 */ /* not _win32_wce */
	mk_win_user_message_id_e_queryopen                      = 0x0013, /*    19 */ /* not _win32_wce */
	mk_win_user_message_id_e_endsession                     = 0x0016, /*    22 */ /* not _win32_wce */
	mk_win_user_message_id_e_quit                           = 0x0012, /*    18 */
	mk_win_user_message_id_e_erasebkgnd                     = 0x0014, /*    20 */
	mk_win_user_message_id_e_syscolorchange                 = 0x0015, /*    21 */
	mk_win_user_message_id_e_showwindow                     = 0x0018, /*    24 */
	mk_win_user_message_id_e_wininichange                   = 0x001a, /*    26 */
	mk_win_user_message_id_e_devmodechange                  = 0x001b, /*    27 */
	mk_win_user_message_id_e_activateapp                    = 0x001c, /*    28 */
	mk_win_user_message_id_e_fontchange                     = 0x001d, /*    29 */
	mk_win_user_message_id_e_timechange                     = 0x001e, /*    30 */
	mk_win_user_message_id_e_cancelmode                     = 0x001f, /*    31 */
	mk_win_user_message_id_e_setcursor                      = 0x0020, /*    32 */
	mk_win_user_message_id_e_mouseactivate                  = 0x0021, /*    33 */
	mk_win_user_message_id_e_childactivate                  = 0x0022, /*    34 */
	mk_win_user_message_id_e_queuesync                      = 0x0023, /*    35 */
	mk_win_user_message_id_e_getminmaxinfo                  = 0x0024, /*    36 */
	mk_win_user_message_id_e_painticon                      = 0x0026, /*    38 */
	mk_win_user_message_id_e_iconerasebkgnd                 = 0x0027, /*    39 */
	mk_win_user_message_id_e_nextdlgctl                     = 0x0028, /*    40 */
	mk_win_user_message_id_e_spoolerstatus                  = 0x002a, /*    42 */
	mk_win_user_message_id_e_drawitem                       = 0x002b, /*    43 */
	mk_win_user_message_id_e_measureitem                    = 0x002c, /*    44 */
	mk_win_user_message_id_e_deleteitem                     = 0x002d, /*    45 */
	mk_win_user_message_id_e_vkeytoitem                     = 0x002e, /*    46 */
	mk_win_user_message_id_e_chartoitem                     = 0x002f, /*    47 */
	mk_win_user_message_id_e_setfont                        = 0x0030, /*    48 */
	mk_win_user_message_id_e_getfont                        = 0x0031, /*    49 */
	mk_win_user_message_id_e_sethotkey                      = 0x0032, /*    50 */
	mk_win_user_message_id_e_gethotkey                      = 0x0033, /*    51 */
	mk_win_user_message_id_e_querydragicon                  = 0x0037, /*    55 */
	mk_win_user_message_id_e_compareitem                    = 0x0039, /*    57 */
	mk_win_user_message_id_e_getobject                      = 0x003d, /*    61 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_compacting                     = 0x0041, /*    65 */
	mk_win_user_message_id_e_commnotify                     = 0x0044, /*    68 */  /* no longer suported */
	mk_win_user_message_id_e_windowposchanging              = 0x0046, /*    70 */
	mk_win_user_message_id_e_windowposchanged               = 0x0047, /*    71 */
	mk_win_user_message_id_e_power                          = 0x0048, /*    72 */
	mk_win_user_message_id_e_copydata                       = 0x004a, /*    74 */
	mk_win_user_message_id_e_canceljournal                  = 0x004b, /*    75 */
	mk_win_user_message_id_e_notify                         = 0x004e, /*    78 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_inputlangchangerequest         = 0x0050, /*    80 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_inputlangchange                = 0x0051, /*    81 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_tcard                          = 0x0052, /*    82 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_help                           = 0x0053, /*    83 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_userchanged                    = 0x0054, /*    84 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_notifyformat                   = 0x0055, /*    85 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_contextmenu                    = 0x007b, /*   123 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_stylechanging                  = 0x007c, /*   124 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_stylechanged                   = 0x007d, /*   125 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_displaychange                  = 0x007e, /*   126 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_geticon                        = 0x007f, /*   127 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_seticon                        = 0x0080, /*   128 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_nccreate                       = 0x0081, /*   129 */
	mk_win_user_message_id_e_ncdestroy                      = 0x0082, /*   130 */
	mk_win_user_message_id_e_nccalcsize                     = 0x0083, /*   131 */
	mk_win_user_message_id_e_nchittest                      = 0x0084, /*   132 */
	mk_win_user_message_id_e_ncpaint                        = 0x0085, /*   133 */
	mk_win_user_message_id_e_ncactivate                     = 0x0086, /*   134 */
	mk_win_user_message_id_e_getdlgcode                     = 0x0087, /*   135 */
	mk_win_user_message_id_e_syncpaint                      = 0x0088, /*   136 */ /* not _win32_wce */
	mk_win_user_message_id_e_ncmousemove                    = 0x00a0, /*   160 */
	mk_win_user_message_id_e_nclbuttondown                  = 0x00a1, /*   161 */
	mk_win_user_message_id_e_nclbuttonup                    = 0x00a2, /*   162 */
	mk_win_user_message_id_e_nclbuttondblclk                = 0x00a3, /*   163 */
	mk_win_user_message_id_e_ncrbuttondown                  = 0x00a4, /*   164 */
	mk_win_user_message_id_e_ncrbuttonup                    = 0x00a5, /*   165 */
	mk_win_user_message_id_e_ncrbuttondblclk                = 0x00a6, /*   166 */
	mk_win_user_message_id_e_ncmbuttondown                  = 0x00a7, /*   167 */
	mk_win_user_message_id_e_ncmbuttonup                    = 0x00a8, /*   168 */
	mk_win_user_message_id_e_ncmbuttondblclk                = 0x00a9, /*   169 */
	mk_win_user_message_id_e_ncxbuttondown                  = 0x00ab, /*   171 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_ncxbuttonup                    = 0x00ac, /*   172 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_ncxbuttondblclk                = 0x00ad, /*   173 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_input_device_change            = 0x00fe, /*   254 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_input                          = 0x00ff, /*   255 */ /* _win32_winnt >= 0x0501 */
	/*mk_win_user_message_id_e_keyfirst                       = 0x0100,*/ /*   256 */
	mk_win_user_message_id_e_keydown                        = 0x0100, /*   256 */
	mk_win_user_message_id_e_keyup                          = 0x0101, /*   257 */
	mk_win_user_message_id_e_char                           = 0x0102, /*   258 */
	mk_win_user_message_id_e_deadchar                       = 0x0103, /*   259 */
	mk_win_user_message_id_e_syskeydown                     = 0x0104, /*   260 */
	mk_win_user_message_id_e_syskeyup                       = 0x0105, /*   261 */
	mk_win_user_message_id_e_syschar                        = 0x0106, /*   262 */
	mk_win_user_message_id_e_sysdeadchar                    = 0x0107, /*   263 */
	mk_win_user_message_id_e_unichar                        = 0x0109, /*   265 */ /* _win32_winnt >= 0x0501 */
	/*mk_win_user_message_id_e_keylast                        = 0x0109,*/ /*   265 */ /* _win32_winnt >= 0x0501 */
	/*mk_win_user_message_id_e_keylast                        = 0x0108,*/ /*   264 */ /* _win32_winnt < 0x0501 */
	mk_win_user_message_id_e_ime_startcomposition           = 0x010d, /*   269 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_endcomposition             = 0x010e, /*   270 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_composition                = 0x010f, /*   271 */ /* winver >= 0x0400 */
	/*mk_win_user_message_id_e_ime_keylast                    = 0x010f,*/ /*   271 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_initdialog                     = 0x0110, /*   272 */
	mk_win_user_message_id_e_command                        = 0x0111, /*   273 */
	mk_win_user_message_id_e_syscommand                     = 0x0112, /*   274 */
	mk_win_user_message_id_e_timer                          = 0x0113, /*   275 */
	mk_win_user_message_id_e_hscroll                        = 0x0114, /*   276 */
	mk_win_user_message_id_e_vscroll                        = 0x0115, /*   277 */
	mk_win_user_message_id_e_initmenu                       = 0x0116, /*   278 */
	mk_win_user_message_id_e_initmenupopup                  = 0x0117, /*   279 */
	mk_win_user_message_id_e_gesture                        = 0x0119, /*   281 */ /* winver >= 0x0601 */
	mk_win_user_message_id_e_gesturenotify                  = 0x011a, /*   282 */ /* winver >= 0x0601 */
	mk_win_user_message_id_e_menuselect                     = 0x011f, /*   287 */
	mk_win_user_message_id_e_menuchar                       = 0x0120, /*   288 */
	mk_win_user_message_id_e_enteridle                      = 0x0121, /*   289 */
	mk_win_user_message_id_e_menurbuttonup                  = 0x0122, /*   290 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_menudrag                       = 0x0123, /*   291 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_menugetobject                  = 0x0124, /*   292 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_uninitmenupopup                = 0x0125, /*   293 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_menucommand                    = 0x0126, /*   294 */ /* not _win32_wce && winver >= 0x0500 */
	mk_win_user_message_id_e_changeuistate                  = 0x0127, /*   295 */ /* not _win32_wce && winver >= 0x0500 && _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_updateuistate                  = 0x0128, /*   296 */ /* not _win32_wce && winver >= 0x0500 && _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_queryuistate                   = 0x0129, /*   297 */ /* not _win32_wce && winver >= 0x0500 && _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_ctlcolormsgbox                 = 0x0132, /*   306 */
	mk_win_user_message_id_e_ctlcoloredit                   = 0x0133, /*   307 */
	mk_win_user_message_id_e_ctlcolorlistbox                = 0x0134, /*   308 */
	mk_win_user_message_id_e_ctlcolorbtn                    = 0x0135, /*   309 */
	mk_win_user_message_id_e_ctlcolordlg                    = 0x0136, /*   310 */
	mk_win_user_message_id_e_ctlcolorscrollbar              = 0x0137, /*   311 */
	mk_win_user_message_id_e_ctlcolorstatic                 = 0x0138, /*   312 */
	/*mk_win_user_message_id_e_mousefirst                     = 0x0200,*/ /*   512 */
	mk_win_user_message_id_e_mousemove                      = 0x0200, /*   512 */
	mk_win_user_message_id_e_lbuttondown                    = 0x0201, /*   513 */
	mk_win_user_message_id_e_lbuttonup                      = 0x0202, /*   514 */
	mk_win_user_message_id_e_lbuttondblclk                  = 0x0203, /*   515 */
	mk_win_user_message_id_e_rbuttondown                    = 0x0204, /*   516 */
	mk_win_user_message_id_e_rbuttonup                      = 0x0205, /*   517 */
	mk_win_user_message_id_e_rbuttondblclk                  = 0x0206, /*   518 */
	mk_win_user_message_id_e_mbuttondown                    = 0x0207, /*   519 */
	mk_win_user_message_id_e_mbuttonup                      = 0x0208, /*   520 */
	mk_win_user_message_id_e_mbuttondblclk                  = 0x0209, /*   521 */
	mk_win_user_message_id_e_mousewheel                     = 0x020a, /*   522 */ /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_message_id_e_xbuttondown                    = 0x020b, /*   523 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_xbuttonup                      = 0x020c, /*   524 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_xbuttondblclk                  = 0x020d, /*   525 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_mousehwheel                    = 0x020e, /*   526 */ /* _win32_winnt >= 0x0600 */
	/*mk_win_user_message_id_e_mouselast                      = 0x020e,*/ /*   526 */ /* _win32_winnt >= 0x0600 */
	/*mk_win_user_message_id_e_mouselast                      = 0x020d,*/ /*   525 */ /* _win32_winnt >= 0x0500 */
	/*mk_win_user_message_id_e_mouselast                      = 0x020a,*/ /*   522 */ /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	/*mk_win_user_message_id_e_mouselast                      = 0x0209,*/ /*   521 */
	mk_win_user_message_id_e_parentnotify                   = 0x0210, /*   528 */
	mk_win_user_message_id_e_entermenuloop                  = 0x0211, /*   529 */
	mk_win_user_message_id_e_exitmenuloop                   = 0x0212, /*   530 */
	mk_win_user_message_id_e_nextmenu                       = 0x0213, /*   531 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_sizing                         = 0x0214, /*   532 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_capturechanged                 = 0x0215, /*   533 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_moving                         = 0x0216, /*   534 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_powerbroadcast                 = 0x0218, /*   536 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_devicechange                   = 0x0219, /*   537 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_mdicreate                      = 0x0220, /*   544 */
	mk_win_user_message_id_e_mdidestroy                     = 0x0221, /*   545 */
	mk_win_user_message_id_e_mdiactivate                    = 0x0222, /*   546 */
	mk_win_user_message_id_e_mdirestore                     = 0x0223, /*   547 */
	mk_win_user_message_id_e_mdinext                        = 0x0224, /*   548 */
	mk_win_user_message_id_e_mdimaximize                    = 0x0225, /*   549 */
	mk_win_user_message_id_e_mditile                        = 0x0226, /*   550 */
	mk_win_user_message_id_e_mdicascade                     = 0x0227, /*   551 */
	mk_win_user_message_id_e_mdiiconarrange                 = 0x0228, /*   552 */
	mk_win_user_message_id_e_mdigetactive                   = 0x0229, /*   553 */
	mk_win_user_message_id_e_mdisetmenu                     = 0x0230, /*   560 */
	mk_win_user_message_id_e_entersizemove                  = 0x0231, /*   561 */
	mk_win_user_message_id_e_exitsizemove                   = 0x0232, /*   562 */
	mk_win_user_message_id_e_dropfiles                      = 0x0233, /*   563 */
	mk_win_user_message_id_e_mdirefreshmenu                 = 0x0234, /*   564 */
	mk_win_user_message_id_e_pointerdevicechange            = 0x0238, /*   568 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerdeviceinrange           = 0x0239, /*   569 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerdeviceoutofrange        = 0x023a, /*   570 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_touch                          = 0x0240, /*   576 */ /* winver >= 0x0601 */
	mk_win_user_message_id_e_ncpointerupdate                = 0x0241, /*   577 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_ncpointerdown                  = 0x0242, /*   578 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_ncpointerup                    = 0x0243, /*   579 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerupdate                  = 0x0245, /*   581 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerdown                    = 0x0246, /*   582 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerup                      = 0x0247, /*   583 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerenter                   = 0x0249, /*   585 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerleave                   = 0x024a, /*   586 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointeractivate                = 0x024b, /*   587 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointercapturechanged          = 0x024c, /*   588 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_touchhittesting                = 0x024d, /*   589 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerwheel                   = 0x024e, /*   590 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerhwheel                  = 0x024f, /*   591 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerroutedto                = 0x0251, /*   593 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerroutedaway              = 0x0252, /*   594 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_pointerroutedreleased          = 0x0253, /*   595 */ /* winver >= 0x0602 */
	mk_win_user_message_id_e_ime_setcontext                 = 0x0281, /*   641 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_notify                     = 0x0282, /*   642 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_control                    = 0x0283, /*   643 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_compositionfull            = 0x0284, /*   644 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_select                     = 0x0285, /*   645 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_char                       = 0x0286, /*   646 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_request                    = 0x0288, /*   648 */ /* winver >= 0x0500 */
	mk_win_user_message_id_e_ime_keydown                    = 0x0290, /*   656 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_ime_keyup                      = 0x0291, /*   657 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_mousehover                     = 0x02a1, /*   673 */ /* _win32_winnt >= 0x0400 || winver >= 0x0500 */
	mk_win_user_message_id_e_mouseleave                     = 0x02a3, /*   675 */ /* _win32_winnt >= 0x0400 || winver >= 0x0500 */
	mk_win_user_message_id_e_ncmousehover                   = 0x02a0, /*   672 */ /* winver >= 0x0500 */
	mk_win_user_message_id_e_ncmouseleave                   = 0x02a2, /*   674 */ /* winver >= 0x0500 */
	mk_win_user_message_id_e_wtssession_change              = 0x02b1, /*   689 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_tablet_first                   = 0x02c0, /*   704 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_tablet_last                    = 0x02df, /*   735 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_dpichanged                     = 0x02e0, /*   736 */ /* winver >= 0x0601 */
	mk_win_user_message_id_e_dpichanged_beforeparent        = 0x02e2, /*   738 */ /* winver >= 0x0605 */
	mk_win_user_message_id_e_dpichanged_afterparent         = 0x02e3, /*   739 */ /* winver >= 0x0605 */
	mk_win_user_message_id_e_getdpiscaledsize               = 0x02e4, /*   740 */ /* winver >= 0x0605 */
	mk_win_user_message_id_e_cut                            = 0x0300, /*   768 */
	mk_win_user_message_id_e_copy                           = 0x0301, /*   769 */
	mk_win_user_message_id_e_paste                          = 0x0302, /*   770 */
	mk_win_user_message_id_e_clear                          = 0x0303, /*   771 */
	mk_win_user_message_id_e_undo                           = 0x0304, /*   772 */
	mk_win_user_message_id_e_renderformat                   = 0x0305, /*   773 */
	mk_win_user_message_id_e_renderallformats               = 0x0306, /*   774 */
	mk_win_user_message_id_e_destroyclipboard               = 0x0307, /*   775 */
	mk_win_user_message_id_e_drawclipboard                  = 0x0308, /*   776 */
	mk_win_user_message_id_e_paintclipboard                 = 0x0309, /*   777 */
	mk_win_user_message_id_e_vscrollclipboard               = 0x030a, /*   778 */
	mk_win_user_message_id_e_sizeclipboard                  = 0x030b, /*   779 */
	mk_win_user_message_id_e_askcbformatname                = 0x030c, /*   780 */
	mk_win_user_message_id_e_changecbchain                  = 0x030d, /*   781 */
	mk_win_user_message_id_e_hscrollclipboard               = 0x030e, /*   782 */
	mk_win_user_message_id_e_querynewpalette                = 0x030f, /*   783 */
	mk_win_user_message_id_e_paletteischanging              = 0x0310, /*   784 */
	mk_win_user_message_id_e_palettechanged                 = 0x0311, /*   785 */
	mk_win_user_message_id_e_hotkey                         = 0x0312, /*   786 */
	mk_win_user_message_id_e_print                          = 0x0317, /*   791 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_printclient                    = 0x0318, /*   792 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_appcommand                     = 0x0319, /*   793 */ /* _win32_winnt >= 0x0500 */
	mk_win_user_message_id_e_themechanged                   = 0x031a, /*   794 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_clipboardupdate                = 0x031d, /*   797 */ /* _win32_winnt >= 0x0501 */
	mk_win_user_message_id_e_dwmcompositionchanged          = 0x031e, /*   798 */ /* _win32_winnt >= 0x0600 */
	mk_win_user_message_id_e_dwmncrenderingchanged          = 0x031f, /*   799 */ /* _win32_winnt >= 0x0600 */
	mk_win_user_message_id_e_dwmcolorizationcolorchanged    = 0x0320, /*   800 */ /* _win32_winnt >= 0x0600 */
	mk_win_user_message_id_e_dwmwindowmaximizedchange       = 0x0321, /*   801 */ /* _win32_winnt >= 0x0600 */
	mk_win_user_message_id_e_dwmsendiconicthumbnail         = 0x0323, /*   803 */ /* _win32_winnt >= 0x0601 */
	mk_win_user_message_id_e_dwmsendiconiclivepreviewbitmap = 0x0326, /*   806 */ /* _win32_winnt >= 0x0601 */
	mk_win_user_message_id_e_gettitlebarinfoex              = 0x033f, /*   831 */ /* winver >= 0x0600 */
	mk_win_user_message_id_e_handheldfirst                  = 0x0358, /*   856 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_handheldlast                   = 0x035f, /*   863 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_afxfirst                       = 0x0360, /*   864 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_afxlast                        = 0x037f, /*   895 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_penwinfirst                    = 0x0380, /*   896 */
	mk_win_user_message_id_e_penwinlast                     = 0x038f, /*   911 */
	mk_win_user_message_id_e_user                           = 0x0400, /*  1024 */
	mk_win_user_message_id_e_app                            = 0x8000, /* 32768 */ /* winver >= 0x0400 */
	mk_win_user_message_id_e_settingchange                  = mk_win_user_message_id_e_wininichange, /* winver >= 0x0400 */
	mk_win_user_message_id_e_dummy_end = 0
};
typedef enum mk_win_user_message_id_e mk_win_user_message_id_t;

enum mk_win_user_message_key_e
{
	mk_win_user_message_key_e_lbutton                         = 0x01,
	mk_win_user_message_key_e_rbutton                         = 0x02,
	mk_win_user_message_key_e_cancel                          = 0x03,
	mk_win_user_message_key_e_mbutton                         = 0x04,
	mk_win_user_message_key_e_xbutton1                        = 0x05, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_xbutton2                        = 0x06, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_reserved_07                     = 0x07,
	mk_win_user_message_key_e_back                            = 0x08,
	mk_win_user_message_key_e_tab                             = 0x09,
	mk_win_user_message_key_e_reserved_0a                     = 0x0a,
	mk_win_user_message_key_e_reserved_0b                     = 0x0b,
	mk_win_user_message_key_e_clear                           = 0x0c,
	mk_win_user_message_key_e_return                          = 0x0d,
	mk_win_user_message_key_e_unassigned_0f                   = 0x0f,
	mk_win_user_message_key_e_shift                           = 0x10,
	mk_win_user_message_key_e_control                         = 0x11,
	mk_win_user_message_key_e_menu                            = 0x12,
	mk_win_user_message_key_e_pause                           = 0x13,
	mk_win_user_message_key_e_capital                         = 0x14,
	mk_win_user_message_key_e_hangul                          = 0x15, /* hangeul kana */
	mk_win_user_message_key_e_ime_on                          = 0x16,
	mk_win_user_message_key_e_junja                           = 0x17,
	mk_win_user_message_key_e_final                           = 0x18,
	mk_win_user_message_key_e_hanja                           = 0x19,
	mk_win_user_message_key_e_kanji                           = 0x19,
	mk_win_user_message_key_e_ime_off                         = 0x1a,
	mk_win_user_message_key_e_escape                          = 0x1b,
	mk_win_user_message_key_e_convert                         = 0x1c,
	mk_win_user_message_key_e_nonconvert                      = 0x1d,
	mk_win_user_message_key_e_accept                          = 0x1e,
	mk_win_user_message_key_e_modechange                      = 0x1f,
	mk_win_user_message_key_e_space                           = 0x20,
	mk_win_user_message_key_e_prior                           = 0x21,
	mk_win_user_message_key_e_next                            = 0x22,
	mk_win_user_message_key_e_end                             = 0x23,
	mk_win_user_message_key_e_home                            = 0x24,
	mk_win_user_message_key_e_left                            = 0x25,
	mk_win_user_message_key_e_up                              = 0x26,
	mk_win_user_message_key_e_right                           = 0x27,
	mk_win_user_message_key_e_down                            = 0x28,
	mk_win_user_message_key_e_select                          = 0x29,
	mk_win_user_message_key_e_print                           = 0x2a,
	mk_win_user_message_key_e_execute                         = 0x2b,
	mk_win_user_message_key_e_snapshot                        = 0x2c,
	mk_win_user_message_key_e_insert                          = 0x2d,
	mk_win_user_message_key_e_delete                          = 0x2e,
	mk_win_user_message_key_e_help                            = 0x2f,
	mk_win_user_message_key_e_0                               = 0x30,
	mk_win_user_message_key_e_1                               = 0x31,
	mk_win_user_message_key_e_2                               = 0x32,
	mk_win_user_message_key_e_3                               = 0x33,
	mk_win_user_message_key_e_4                               = 0x34,
	mk_win_user_message_key_e_5                               = 0x35,
	mk_win_user_message_key_e_6                               = 0x36,
	mk_win_user_message_key_e_7                               = 0x37,
	mk_win_user_message_key_e_8                               = 0x38,
	mk_win_user_message_key_e_9                               = 0x39,
	mk_win_user_message_key_e_unassigned_3a                   = 0x3a,
	mk_win_user_message_key_e_unassigned_3b                   = 0x3b,
	mk_win_user_message_key_e_unassigned_3c                   = 0x3c,
	mk_win_user_message_key_e_unassigned_3d                   = 0x3d,
	mk_win_user_message_key_e_unassigned_3e                   = 0x3e,
	mk_win_user_message_key_e_unassigned_3f                   = 0x3f,
	mk_win_user_message_key_e_unassigned_40                   = 0x40,
	mk_win_user_message_key_e_a                               = 0x41,
	mk_win_user_message_key_e_b                               = 0x42,
	mk_win_user_message_key_e_c                               = 0x43,
	mk_win_user_message_key_e_d                               = 0x44,
	mk_win_user_message_key_e_e                               = 0x45,
	mk_win_user_message_key_e_f                               = 0x46,
	mk_win_user_message_key_e_g                               = 0x47,
	mk_win_user_message_key_e_h                               = 0x48,
	mk_win_user_message_key_e_i                               = 0x49,
	mk_win_user_message_key_e_j                               = 0x4a,
	mk_win_user_message_key_e_k                               = 0x4b,
	mk_win_user_message_key_e_l                               = 0x4c,
	mk_win_user_message_key_e_m                               = 0x4d,
	mk_win_user_message_key_e_n                               = 0x4e,
	mk_win_user_message_key_e_o                               = 0x4f,
	mk_win_user_message_key_e_p                               = 0x50,
	mk_win_user_message_key_e_q                               = 0x51,
	mk_win_user_message_key_e_r                               = 0x52,
	mk_win_user_message_key_e_s                               = 0x53,
	mk_win_user_message_key_e_t                               = 0x54,
	mk_win_user_message_key_e_u                               = 0x55,
	mk_win_user_message_key_e_v                               = 0x56,
	mk_win_user_message_key_e_w                               = 0x57,
	mk_win_user_message_key_e_x                               = 0x58,
	mk_win_user_message_key_e_y                               = 0x59,
	mk_win_user_message_key_e_z                               = 0x5a,
	mk_win_user_message_key_e_lwin                            = 0x5b,
	mk_win_user_message_key_e_rwin                            = 0x5c,
	mk_win_user_message_key_e_apps                            = 0x5d,
	mk_win_user_message_key_e_reserved_5e                     = 0x5e,
	mk_win_user_message_key_e_sleep                           = 0x5f,
	mk_win_user_message_key_e_numpad0                         = 0x60,
	mk_win_user_message_key_e_numpad1                         = 0x61,
	mk_win_user_message_key_e_numpad2                         = 0x62,
	mk_win_user_message_key_e_numpad3                         = 0x63,
	mk_win_user_message_key_e_numpad4                         = 0x64,
	mk_win_user_message_key_e_numpad5                         = 0x65,
	mk_win_user_message_key_e_numpad6                         = 0x66,
	mk_win_user_message_key_e_numpad7                         = 0x67,
	mk_win_user_message_key_e_numpad8                         = 0x68,
	mk_win_user_message_key_e_numpad9                         = 0x69,
	mk_win_user_message_key_e_multiply                        = 0x6a,
	mk_win_user_message_key_e_add                             = 0x6b,
	mk_win_user_message_key_e_separator                       = 0x6c,
	mk_win_user_message_key_e_subtract                        = 0x6d,
	mk_win_user_message_key_e_decimal                         = 0x6e,
	mk_win_user_message_key_e_divide                          = 0x6f,
	mk_win_user_message_key_e_f1                              = 0x70,
	mk_win_user_message_key_e_f2                              = 0x71,
	mk_win_user_message_key_e_f3                              = 0x72,
	mk_win_user_message_key_e_f4                              = 0x73,
	mk_win_user_message_key_e_f5                              = 0x74,
	mk_win_user_message_key_e_f6                              = 0x75,
	mk_win_user_message_key_e_f7                              = 0x76,
	mk_win_user_message_key_e_f8                              = 0x77,
	mk_win_user_message_key_e_f9                              = 0x78,
	mk_win_user_message_key_e_f10                             = 0x79,
	mk_win_user_message_key_e_f11                             = 0x7a,
	mk_win_user_message_key_e_f12                             = 0x7b,
	mk_win_user_message_key_e_f13                             = 0x7c,
	mk_win_user_message_key_e_f14                             = 0x7d,
	mk_win_user_message_key_e_f15                             = 0x7e,
	mk_win_user_message_key_e_f16                             = 0x7f,
	mk_win_user_message_key_e_f17                             = 0x80,
	mk_win_user_message_key_e_f18                             = 0x81,
	mk_win_user_message_key_e_f19                             = 0x82,
	mk_win_user_message_key_e_f20                             = 0x83,
	mk_win_user_message_key_e_f21                             = 0x84,
	mk_win_user_message_key_e_f22                             = 0x85,
	mk_win_user_message_key_e_f23                             = 0x86,
	mk_win_user_message_key_e_f24                             = 0x87,
	mk_win_user_message_key_e_navigation_view                 = 0x88, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_menu                 = 0x89, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_up                   = 0x8a, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_down                 = 0x8b, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_left                 = 0x8c, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_right                = 0x8d, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_accept               = 0x8e, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_navigation_cancel               = 0x8f, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_numlock                         = 0x90,
	mk_win_user_message_key_e_scroll                          = 0x91,
	mk_win_user_message_key_e_oem_nec_equal                   = 0x92,
	mk_win_user_message_key_e_oem_fj_jisho                    = 0x92,
	mk_win_user_message_key_e_oem_fj_masshou                  = 0x93,
	mk_win_user_message_key_e_oem_fj_touroku                  = 0x94,
	mk_win_user_message_key_e_oem_fj_loya                     = 0x95,
	mk_win_user_message_key_e_oem_fj_roya                     = 0x96,
	mk_win_user_message_key_e_unassigned_97                   = 0x97,
	mk_win_user_message_key_e_unassigned_98                   = 0x98,
	mk_win_user_message_key_e_unassigned_99                   = 0x99,
	mk_win_user_message_key_e_unassigned_9a                   = 0x9a,
	mk_win_user_message_key_e_unassigned_9b                   = 0x9b,
	mk_win_user_message_key_e_unassigned_9c                   = 0x9c,
	mk_win_user_message_key_e_unassigned_9d                   = 0x9d,
	mk_win_user_message_key_e_unassigned_9e                   = 0x9e,
	mk_win_user_message_key_e_unassigned_9f                   = 0x9f,
	mk_win_user_message_key_e_lshift                          = 0xa0,
	mk_win_user_message_key_e_rshift                          = 0xa1,
	mk_win_user_message_key_e_lcontrol                        = 0xa2,
	mk_win_user_message_key_e_rcontrol                        = 0xa3,
	mk_win_user_message_key_e_lmenu                           = 0xa4,
	mk_win_user_message_key_e_rmenu                           = 0xa5,
	mk_win_user_message_key_e_browser_back                    = 0xa6, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_forward                 = 0xa7, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_refresh                 = 0xa8, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_stop                    = 0xa9, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_search                  = 0xaa, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_favorites               = 0xab, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_browser_home                    = 0xac, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_volume_mute                     = 0xad, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_volume_down                     = 0xae, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_volume_up                       = 0xaf, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_media_next_track                = 0xb0, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_media_prev_track                = 0xb1, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_media_stop                      = 0xb2, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_media_play_pause                = 0xb3, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_launch_mail                     = 0xb4, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_launch_media_select             = 0xb5, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_launch_app1                     = 0xb6, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_launch_app2                     = 0xb7, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_reserved_b8                     = 0xb8,
	mk_win_user_message_key_e_reserved_b9                     = 0xb9,
	mk_win_user_message_key_e_oem_1                           = 0xba,
	mk_win_user_message_key_e_oem_plus                        = 0xbb,
	mk_win_user_message_key_e_oem_comma                       = 0xbc,
	mk_win_user_message_key_e_oem_minus                       = 0xbd,
	mk_win_user_message_key_e_oem_period                      = 0xbe,
	mk_win_user_message_key_e_oem_2                           = 0xbf,
	mk_win_user_message_key_e_oem_3                           = 0xc0,
	mk_win_user_message_key_e_reserved_c1                     = 0xc1,
	mk_win_user_message_key_e_reserved_c2                     = 0xc2,
	mk_win_user_message_key_e_gamepad_a                       = 0xc3, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_b                       = 0xc4, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_x                       = 0xc5, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_y                       = 0xc6, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_shoulder          = 0xc7, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_shoulder           = 0xc8, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_trigger            = 0xc9, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_trigger           = 0xca, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_dpad_up                 = 0xcb, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_dpad_down               = 0xcc, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_dpad_left               = 0xcd, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_dpad_right              = 0xce, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_menu                    = 0xcf, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_view                    = 0xd0, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_thumbstick_button  = 0xd1, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_thumbstick_button = 0xd2, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_thumbstick_up      = 0xd3, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_thumbstick_down    = 0xd4, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_thumbstick_right   = 0xd5, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_left_thumbstick_left    = 0xd6, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_thumbstick_up     = 0xd7, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_thumbstick_down   = 0xd8, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_thumbstick_right  = 0xd9, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_gamepad_right_thumbstick_left   = 0xda, /* _win32_winnt >= 0x0604 */
	mk_win_user_message_key_e_oem_4                           = 0xdb,
	mk_win_user_message_key_e_oem_5                           = 0xdc,
	mk_win_user_message_key_e_oem_6                           = 0xdd,
	mk_win_user_message_key_e_oem_7                           = 0xde,
	mk_win_user_message_key_e_oem_8                           = 0xdf,
	mk_win_user_message_key_e_reserved_e0                     = 0xe0,
	mk_win_user_message_key_e_oem_ax                          = 0xe1,
	mk_win_user_message_key_e_oem_102                         = 0xe2,
	mk_win_user_message_key_e_ico_help                        = 0xe3,
	mk_win_user_message_key_e_ico_00                          = 0xe4,
	mk_win_user_message_key_e_processkey                      = 0xe5, /* winver >= 0x0400 */
	mk_win_user_message_key_e_ico_clear                       = 0xe6,
	mk_win_user_message_key_e_packet                          = 0xe7, /* _win32_winnt >= 0x0500 */
	mk_win_user_message_key_e_unassigned_e8                   = 0xe8,
	mk_win_user_message_key_e_oem_reset                       = 0xe9,
	mk_win_user_message_key_e_oem_jump                        = 0xea,
	mk_win_user_message_key_e_oem_pa1                         = 0xeb,
	mk_win_user_message_key_e_oem_pa2                         = 0xec,
	mk_win_user_message_key_e_oem_pa3                         = 0xed,
	mk_win_user_message_key_e_oem_wsctrl                      = 0xee,
	mk_win_user_message_key_e_oem_cusel                       = 0xef,
	mk_win_user_message_key_e_oem_attn                        = 0xf0,
	mk_win_user_message_key_e_oem_finish                      = 0xf1,
	mk_win_user_message_key_e_oem_copy                        = 0xf2,
	mk_win_user_message_key_e_oem_auto                        = 0xf3,
	mk_win_user_message_key_e_oem_enlw                        = 0xf4,
	mk_win_user_message_key_e_oem_backtab                     = 0xf5,
	mk_win_user_message_key_e_attn                            = 0xf6,
	mk_win_user_message_key_e_crsel                           = 0xf7,
	mk_win_user_message_key_e_exsel                           = 0xf8,
	mk_win_user_message_key_e_ereof                           = 0xf9,
	mk_win_user_message_key_e_play                            = 0xfa,
	mk_win_user_message_key_e_zoom                            = 0xfb,
	mk_win_user_message_key_e_noname                          = 0xfc,
	mk_win_user_message_key_e_pa1                             = 0xfd,
	mk_win_user_message_key_e_oem_clear                       = 0xfe,
	mk_win_user_message_key_e_reserved_ff                     = 0xff,
};
typedef enum mk_win_user_message_key_e mk_win_user_message_key_t;


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_message_s
{
	mk_win_user_window_t m_window;
	mk_win_base_uint_t m_message_id;
	mk_win_user_window_wparam_t m_wparam;
	mk_win_user_window_lparam_t m_lparam;
	mk_win_base_dword_t m_time;
	mk_win_base_point_t m_point;
};
typedef struct mk_win_user_message_s mk_win_user_message_t;
typedef mk_win_user_message_t const mk_win_user_message_ct;
typedef mk_win_user_message_t* mk_win_user_message_pt;
typedef mk_win_user_message_t const* mk_win_user_message_pct;
typedef mk_win_user_message_t mk_win_base_far* mk_win_user_message_lpt;
typedef mk_win_user_message_t mk_win_base_far const* mk_win_user_message_lpct;
typedef mk_win_user_message_t mk_win_base_near* mk_win_user_message_npt;
typedef mk_win_user_message_t mk_win_base_near const* mk_win_user_message_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_a_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_a_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_a_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_w_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_w_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_w_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_t_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_t_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_t_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_translate(mk_win_user_message_lpct const message) mk_lang_noexcept;
mk_lang_jumbo void mk_win_user_message_post_quit(int const exit_code) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_message.c"
#endif
#endif
