#ifndef mk_include_guard_mk_win_user_todo
#define mk_include_guard_mk_win_user_todo


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


enum mk_win_user_todo_system_parameters_info_id_e
{
	mk_win_user_todo_system_parameters_info_id_e_getbeep                     = 0x0001,
	mk_win_user_todo_system_parameters_info_id_e_setbeep                     = 0x0002,
	mk_win_user_todo_system_parameters_info_id_e_getmouse                    = 0x0003,
	mk_win_user_todo_system_parameters_info_id_e_setmouse                    = 0x0004,
	mk_win_user_todo_system_parameters_info_id_e_getborder                   = 0x0005,
	mk_win_user_todo_system_parameters_info_id_e_setborder                   = 0x0006,
	mk_win_user_todo_system_parameters_info_id_e_getkeyboardspeed            = 0x000a,
	mk_win_user_todo_system_parameters_info_id_e_setkeyboardspeed            = 0x000b,
	mk_win_user_todo_system_parameters_info_id_e_langdriver                  = 0x000c,
	mk_win_user_todo_system_parameters_info_id_e_iconhorizontalspacing       = 0x000d,
	mk_win_user_todo_system_parameters_info_id_e_getscreensavetimeout        = 0x000e,
	mk_win_user_todo_system_parameters_info_id_e_setscreensavetimeout        = 0x000f,
	mk_win_user_todo_system_parameters_info_id_e_getscreensaveactive         = 0x0010,
	mk_win_user_todo_system_parameters_info_id_e_setscreensaveactive         = 0x0011,
	mk_win_user_todo_system_parameters_info_id_e_getgridgranularity          = 0x0012,
	mk_win_user_todo_system_parameters_info_id_e_setgridgranularity          = 0x0013,
	mk_win_user_todo_system_parameters_info_id_e_setdeskwallpaper            = 0x0014,
	mk_win_user_todo_system_parameters_info_id_e_setdeskpattern              = 0x0015,
	mk_win_user_todo_system_parameters_info_id_e_getkeyboarddelay            = 0x0016,
	mk_win_user_todo_system_parameters_info_id_e_setkeyboarddelay            = 0x0017,
	mk_win_user_todo_system_parameters_info_id_e_iconverticalspacing         = 0x0018,
	mk_win_user_todo_system_parameters_info_id_e_geticontitlewrap            = 0x0019,
	mk_win_user_todo_system_parameters_info_id_e_seticontitlewrap            = 0x001a,
	mk_win_user_todo_system_parameters_info_id_e_getmenudropalignment        = 0x001b,
	mk_win_user_todo_system_parameters_info_id_e_setmenudropalignment        = 0x001c,
	mk_win_user_todo_system_parameters_info_id_e_setdoubleclkwidth           = 0x001d,
	mk_win_user_todo_system_parameters_info_id_e_setdoubleclkheight          = 0x001e,
	mk_win_user_todo_system_parameters_info_id_e_geticontitlelogfont         = 0x001f,
	mk_win_user_todo_system_parameters_info_id_e_setdoubleclicktime          = 0x0020,
	mk_win_user_todo_system_parameters_info_id_e_setmousebuttonswap          = 0x0021,
	mk_win_user_todo_system_parameters_info_id_e_seticontitlelogfont         = 0x0022,
	mk_win_user_todo_system_parameters_info_id_e_getfasttaskswitch           = 0x0023,
	mk_win_user_todo_system_parameters_info_id_e_setfasttaskswitch           = 0x0024,
	mk_win_user_todo_system_parameters_info_id_e_setdragfullwindows          = 0x0025, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getdragfullwindows          = 0x0026, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getnonclientmetrics         = 0x0029, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setnonclientmetrics         = 0x002a, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getminimizedmetrics         = 0x002b, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setminimizedmetrics         = 0x002c, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_geticonmetrics              = 0x002d, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_seticonmetrics              = 0x002e, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setworkarea                 = 0x002f, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getworkarea                 = 0x0030, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setpenwindows               = 0x0031, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_gethighcontrast             = 0x0042, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_sethighcontrast             = 0x0043, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getkeyboardpref             = 0x0044, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setkeyboardpref             = 0x0045, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getscreenreader             = 0x0046, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setscreenreader             = 0x0047, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getanimation                = 0x0048, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setanimation                = 0x0049, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getfontsmoothing            = 0x004a, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setfontsmoothing            = 0x004b, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setdragwidth                = 0x004c, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setdragheight               = 0x004d, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_sethandheld                 = 0x004e, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getlowpowertimeout          = 0x004f, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getpowerofftimeout          = 0x0050, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setlowpowertimeout          = 0x0051, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setpowerofftimeout          = 0x0052, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getlowpoweractive           = 0x0053, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getpoweroffactive           = 0x0054, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setlowpoweractive           = 0x0055, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setpoweroffactive           = 0x0056, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setcursors                  = 0x0057, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_seticons                    = 0x0058, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getdefaultinputlang         = 0x0059, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setdefaultinputlang         = 0x005a, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setlangtoggle               = 0x005b, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getwindowsextension         = 0x005c, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setmousetrails              = 0x005d, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmousetrails              = 0x005e, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setscreensaverrunning       = 0x0061, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getfilterkeys               = 0x0032,
	mk_win_user_todo_system_parameters_info_id_e_setfilterkeys               = 0x0033,
	mk_win_user_todo_system_parameters_info_id_e_gettogglekeys               = 0x0034,
	mk_win_user_todo_system_parameters_info_id_e_settogglekeys               = 0x0035,
	mk_win_user_todo_system_parameters_info_id_e_getmousekeys                = 0x0036,
	mk_win_user_todo_system_parameters_info_id_e_setmousekeys                = 0x0037,
	mk_win_user_todo_system_parameters_info_id_e_getshowsounds               = 0x0038,
	mk_win_user_todo_system_parameters_info_id_e_setshowsounds               = 0x0039,
	mk_win_user_todo_system_parameters_info_id_e_getstickykeys               = 0x003a,
	mk_win_user_todo_system_parameters_info_id_e_setstickykeys               = 0x003b,
	mk_win_user_todo_system_parameters_info_id_e_getaccesstimeout            = 0x003c,
	mk_win_user_todo_system_parameters_info_id_e_setaccesstimeout            = 0x003d,
	mk_win_user_todo_system_parameters_info_id_e_getserialkeys               = 0x003e, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setserialkeys               = 0x003f, /* winver >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getsoundsentry              = 0x0040,
	mk_win_user_todo_system_parameters_info_id_e_setsoundsentry              = 0x0041,
	mk_win_user_todo_system_parameters_info_id_e_getsnaptodefbutton          = 0x005f, /* _win32_winnt >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setsnaptodefbutton          = 0x0060, /* _win32_winnt >= 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmousehoverwidth          = 0x0062, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setmousehoverwidth          = 0x0063, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmousehoverheight         = 0x0064, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setmousehoverheight         = 0x0065, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmousehovertime           = 0x0066, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setmousehovertime           = 0x0067, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getwheelscrolllines         = 0x0068, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setwheelscrolllines         = 0x0069, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmenushowdelay            = 0x006a, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setmenushowdelay            = 0x006b, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getwheelscrollchars         = 0x006c, /* _win32_winnt >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_setwheelscrollchars         = 0x006d, /* _win32_winnt >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_getshowimeui                = 0x006e, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_setshowimeui                = 0x006f, /* _win32_winnt >= 0x0400 || _win32_windows > 0x0400 */
	mk_win_user_todo_system_parameters_info_id_e_getmousespeed               = 0x0070, /* winver >= 0x0500 */
	mk_win_user_todo_system_parameters_info_id_e_setmousespeed               = 0x0071, /* winver >= 0x0500 */
	mk_win_user_todo_system_parameters_info_id_e_getscreensaverrunning       = 0x0072, /* winver >= 0x0500 */
	mk_win_user_todo_system_parameters_info_id_e_getdeskwallpaper            = 0x0073, /* winver >= 0x0500 */
	mk_win_user_todo_system_parameters_info_id_e_getaudiodescription         = 0x0074, /* winver >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_setaudiodescription         = 0x0075, /* winver >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_getscreensavesecure         = 0x0076, /* winver >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_setscreensavesecure         = 0x0077, /* winver >= 0x0600 */
	mk_win_user_todo_system_parameters_info_id_e_gethungapptimeout           = 0x0078, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_sethungapptimeout           = 0x0079, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getwaittokilltimeout        = 0x007a, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setwaittokilltimeout        = 0x007b, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getwaittokillservicetimeout = 0x007c, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setwaittokillservicetimeout = 0x007d, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getmousedockthreshold       = 0x007e, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setmousedockthreshold       = 0x007f, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getpendockthreshold         = 0x0080, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setpendockthreshold         = 0x0081, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getwinarranging             = 0x0082, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setwinarranging             = 0x0083, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getmousedragoutthreshold    = 0x0084, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setmousedragoutthreshold    = 0x0085, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getpendragoutthreshold      = 0x0086, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setpendragoutthreshold      = 0x0087, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getmousesidemovethreshold   = 0x0088, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setmousesidemovethreshold   = 0x0089, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getpensidemovethreshold     = 0x008a, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setpensidemovethreshold     = 0x008b, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getdragfrommaximize         = 0x008c, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setdragfrommaximize         = 0x008d, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getsnapsizing               = 0x008e, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setsnapsizing               = 0x008f, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_getdockmoving               = 0x0090, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_setdockmoving               = 0x0091, /* _win32_winnt >= 0x0601 */
	mk_win_user_todo_system_parameters_info_id_e_screensaverrunning          = mk_win_user_todo_system_parameters_info_id_e_setscreensaverrunning,
	mk_win_user_todo_system_parameters_info_id_e_dummy_end
};
typedef enum mk_win_user_todo_system_parameters_info_id_e mk_win_user_todo_system_parameters_info_id_t;

#define mk_win_user_todo_facesize 32

struct mk_win_user_todo_logfont_s
{
	mk_win_base_slong_t m_height;
	mk_win_base_slong_t m_width;
	mk_win_base_slong_t m_escapement;
	mk_win_base_slong_t m_orientation;
	mk_win_base_slong_t m_weight;
	mk_win_base_uchar_t m_italic;
	mk_win_base_uchar_t m_underline;
	mk_win_base_uchar_t m_strike_out;
	mk_win_base_uchar_t m_char_set;
	mk_win_base_uchar_t m_out_precision;
	mk_win_base_uchar_t m_clip_precision;
	mk_win_base_uchar_t m_quality;
	mk_win_base_uchar_t m_pitch_and_family;
	mk_win_base_wchar_t m_face_name[mk_win_user_todo_facesize];
};
typedef struct mk_win_user_todo_logfont_s mk_win_user_todo_logfont_t;
typedef mk_win_user_todo_logfont_t const mk_win_user_todo_logfont_ct;
typedef mk_win_user_todo_logfont_t* mk_win_user_todo_logfont_pt;
typedef mk_win_user_todo_logfont_t const* mk_win_user_todo_logfont_pct;

struct mk_win_user_todo_nonclientmetrics_s
{
	mk_win_base_uint_t m_size;
	mk_win_base_sint_t m_border_width;
	mk_win_base_sint_t m_scroll_width;
	mk_win_base_sint_t m_scroll_height;
	mk_win_base_sint_t m_caption_width;
	mk_win_base_sint_t m_caption_height;
	mk_win_user_todo_logfont_t m_caption_font;
	mk_win_base_sint_t m_sm_caption_width;
	mk_win_base_sint_t m_sm_caption_height;
	mk_win_user_todo_logfont_t m_sm_caption_font;
	mk_win_base_sint_t m_menu_width;
	mk_win_base_sint_t m_menu_height;
	mk_win_user_todo_logfont_t m_menu_font;
	mk_win_user_todo_logfont_t m_status_font;
	mk_win_user_todo_logfont_t m_message_font;
};
typedef struct mk_win_user_todo_nonclientmetrics_s mk_win_user_todo_nonclientmetrics_t;
typedef mk_win_user_todo_nonclientmetrics_t const mk_win_user_todo_nonclientmetrics_ct;
typedef mk_win_user_todo_nonclientmetrics_t* mk_win_user_todo_nonclientmetrics_pt;
typedef mk_win_user_todo_nonclientmetrics_t const* mk_win_user_todo_nonclientmetrics_pct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_todo_w_system_parameters_info(mk_win_base_uint_t const action, mk_win_base_uint_t const param, mk_win_base_void_pt const buf, mk_win_base_uint_t const ini) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_font_t mk_win_user_todo_w_create_font_indirect(mk_win_user_todo_logfont_pct const logfont) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_todo.c"
#endif
#endif
