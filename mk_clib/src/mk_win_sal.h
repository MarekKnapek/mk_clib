#ifndef include_guard_mk_win_sal
#define include_guard_mk_win_sal


#if defined mk_win_sal_has && mk_win_sal_has == 1 /* todo how to determine? */


#include <sal.h>


#define mk_win_sal_in _In_
#define mk_win_sal_in_opt _In_opt_


#else


#define mk_win_sal_in
#define mk_win_sal_in_opt


#endif


#endif
