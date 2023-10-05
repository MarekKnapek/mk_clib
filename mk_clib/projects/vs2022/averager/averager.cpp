#define mk_lang_jumbo_want 1

#include "mk_lang_bui.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"

#define mk_sl_averager_t_name tst
#define mk_sl_averager_t_count 4
#define mk_sl_averager_t_history 8
#define mk_sl_averager_t_timer_tnb mk_sl_cui_uint64
#define mk_sl_averager_t_counter_tnb mk_sl_cui_uint64
#define mk_sl_averager_t_period_chunk mk_sl_cui_uint64_c(0, 10ul * 1000ul * 1000ul / 4ul)
#include "mk_sl_averager_inl_fileh.h"
#include "mk_sl_averager_inl_filec.h"

#include <stdio.h>

#include <windows.h>
#pragma comment(lib, "winmm.lib")


#define test(x) do{ if(!(x)){ __debugbreak(); } }while(0)


static mk_sl_averager_tst_t g_averager;
static UINT g_timer_id;
static unsigned g_counter;
static DWORD g_main_thread_id;
static mk_sl_cui_uint64_t g_last_time;
static mk_sl_cui_uint64_t g_last_print;
static mk_lang_types_bool_t g_once;

void timer_init(void)
{
	UINT period;
	MMRESULT r;

	period = 1;
	r = timeBeginPeriod(period);
	test(r == TIMERR_NOERROR && r != TIMERR_NOCANDO);
}

void timer_deinit(void)
{
	UINT period;
	MMRESULT r;

	period = 1;
	r = timeEndPeriod(period);
	test(r == TIMERR_NOERROR && r != TIMERR_NOCANDO);
}

void timer_stop(void)
{
	MMRESULT r;

	r = timeKillEvent(g_timer_id);
	test(r == TIMERR_NOERROR && r != MMSYSERR_INVALPARAM);
}

void CALLBACK timer_callback(UINT const timer_id, UINT const msg, DWORD_PTR const user, DWORD_PTR const reserved_a, DWORD_PTR const reserved_b)
{
	BOOL b;
	FILETIME ticks;
	mk_lang_types_ulong_t tuls[2];
	mk_sl_cui_uint64_t curr_time;
	mk_sl_cui_uint64_t time;
	mk_sl_cui_uint64_t time_diff;
	mk_sl_cui_uint64_t count;
	mk_lang_types_pchar_t str[mk_sl_cui_uint64_to_str_dec_len];
	mk_lang_types_sint_t str_len;
	mk_lang_types_sint_t tsi;

	++g_counter;
	if(g_counter == 0xffff)
	{
		timer_stop();
		b = PostThreadMessage(g_main_thread_id, WM_QUIT, 0, 0);
		test(b != 0);
	}
	GetSystemTimeAsFileTime(&ticks);
	tuls[0] = ((mk_lang_types_ulong_t)(ticks.dwLowDateTime));
	tuls[1] = ((mk_lang_types_ulong_t)(ticks.dwHighDateTime));
	mk_sl_cui_uint64_from_buis_ulong_le(&curr_time, &tuls[0]);
	mk_sl_cui_uint64_sub3_wrap_cid_cod(&curr_time, &g_last_time, &time_diff);
	time = curr_time;
	mk_sl_averager_tst_st_round_time(&time);
	if(g_once){ mk_sl_averager_tst_rw_add_one(&g_averager, &time); }
	if(mk_sl_cui_uint64_ne(&time, &g_last_print))
	{
		g_last_print = time;
		mk_sl_averager_tst_ro_compute(&g_averager, &count);
		str_len = mk_sl_cui_uint64_to_str_dec_n(&count, &str[0], mk_sl_cui_uint64_to_str_dec_len);
		mk_lang_assert(str_len != 0 && str_len >= 1);
		tsi = printf("%.*s\n", str_len, &str[0]);
		mk_lang_assert(tsi >= 2);
	}
	g_last_time = curr_time;
	if(g_once == mk_lang_false)
	{
		g_once = mk_lang_true;
	}
}

void timer_start(void)
{
	UINT delay;
	UINT resolution;
	LPTIMECALLBACK callback;
	DWORD_PTR user;
	UINT evnt;
	MMRESULT timer_id;

	delay = 1;
	resolution = 0;
	callback = &timer_callback;
	user = 0;
	evnt = TIME_PERIODIC | TIME_CALLBACK_FUNCTION | TIME_KILL_SYNCHRONOUS;
	timer_id = timeSetEvent(delay, resolution, callback, user, evnt);
	test(timer_id != 0);
	g_timer_id = timer_id;
}

void run(void)
{
	BOOL b;
	MSG msg;
	HWND hwnd;
	UINT msg_id_min;
	UINT msg_id_max;
	LRESULT lr;

	hwnd = NULL;
	msg_id_min = 0;
	msg_id_max = 0;
	for(;;)
	{
		b = GetMessage(&msg, hwnd, msg_id_min, msg_id_max);
		test(b != -1);
		if(b == 0)
		{
			test(msg.message == WM_QUIT);
			break;
		}
		lr = DispatchMessage(&msg);
		((void)(lr));
	}
}

int main()
{
	g_main_thread_id = GetCurrentThreadId();
	mk_sl_averager_tst_rw_construct(&g_averager);
	timer_init();
	timer_start();
	run();
	timer_deinit();
}
