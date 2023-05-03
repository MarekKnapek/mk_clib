#ifndef mk_include_guard_win_color
#define mk_include_guard_win_color


enum mk_win_user_color_id_e
{
	mk_win_user_color_id_e_scrollbar               =  0,
	mk_win_user_color_id_e_background              =  1,
	mk_win_user_color_id_e_activecaption           =  2,
	mk_win_user_color_id_e_inactivecaption         =  3,
	mk_win_user_color_id_e_menu                    =  4,
	mk_win_user_color_id_e_window                  =  5,
	mk_win_user_color_id_e_windowframe             =  6,
	mk_win_user_color_id_e_menutext                =  7,
	mk_win_user_color_id_e_windowtext              =  8,
	mk_win_user_color_id_e_captiontext             =  9,
	mk_win_user_color_id_e_activeborder            = 10,
	mk_win_user_color_id_e_inactiveborder          = 11,
	mk_win_user_color_id_e_appworkspace            = 12,
	mk_win_user_color_id_e_highlight               = 13,
	mk_win_user_color_id_e_highlighttext           = 14,
	mk_win_user_color_id_e_btnface                 = 15,
	mk_win_user_color_id_e_btnshadow               = 16,
	mk_win_user_color_id_e_graytext                = 17,
	mk_win_user_color_id_e_btntext                 = 18,
	mk_win_user_color_id_e_inactivecaptiontext     = 19,
	mk_win_user_color_id_e_btnhighlight            = 20,
	mk_win_user_color_id_e_3ddkshadow              = 21, /* winver >= 0x0400 */
	mk_win_user_color_id_e_3dlight                 = 22, /* winver >= 0x0400 */
	mk_win_user_color_id_e_infotext                = 23, /* winver >= 0x0400 */
	mk_win_user_color_id_e_infobk                  = 24, /* winver >= 0x0400 */
	mk_win_user_color_id_e_hotlight                = 26, /* winver >= 0x0500 */
	mk_win_user_color_id_e_gradientactivecaption   = 27, /* winver >= 0x0500 */
	mk_win_user_color_id_e_gradientinactivecaption = 28, /* winver >= 0x0500 */
	mk_win_user_color_id_e_menuhilight             = 29, /* winver >= 0x0501 */
	mk_win_user_color_id_e_menubar                 = 30, /* winver >= 0x0501 */
	mk_win_user_color_id_e_desktop                 = mk_win_user_color_id_e_background, /* winver >= 0x0400 */
	mk_win_user_color_id_e_3dface                  = mk_win_user_color_id_e_btnface, /* winver >= 0x0400 */
	mk_win_user_color_id_e_3dshadow                = mk_win_user_color_id_e_btnshadow, /* winver >= 0x0400 */
	mk_win_user_color_id_e_3dhighlight             = mk_win_user_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_color_id_e_3dhilight               = mk_win_user_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_color_id_e_btnhilight              = mk_win_user_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_color_id_e_dummy_end               = 0
};
typedef enum mk_win_user_color_id_e mk_win_user_color_id_t;


#endif
