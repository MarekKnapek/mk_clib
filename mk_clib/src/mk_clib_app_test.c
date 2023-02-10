#include "mk_clib_app_test.h"

#include "mk_clib_app_fuzz.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_null.h"

#include <stdio.h> /* printf putchar */
#include <stdlib.h> /* srand rand */
#include <time.h> /* time_t time */


mk_lang_jumbo int mk_clib_app_test_void(void)
{
	#if mk_lang_arch == mk_lang_arch_x8616
	static long const s_iterations = 1l * 1l * 1000l;
	#else
	static long const s_iterations = 1l * 1000l * 1000l;
	#endif

	int t;
	time_t tm;
	int progress_last;
	int progress_curr;
	long i;
	int j;
	unsigned char data[64];

	t = printf("Started.\n");
	mk_lang_assert(t >= 0);
	tm = time(mk_lang_null);
	srand(((unsigned int)(tm)));
	progress_last = 0;
	progress_curr = 0;
	for(i = 0; i != s_iterations; ++i)
	{
		progress_curr = ((int)(((i + 1l) * 20l) / s_iterations));
		if(progress_curr != progress_last)
		{
			for(j = 0; j != progress_curr - progress_last; ++j)
			{
				t = putchar('.');
				mk_lang_assert(t == '.');
			}
			t = fflush(mk_lang_null);
			mk_lang_assert(t == 0);
			progress_last = progress_curr;
		}
		for(j = 0; j != ((int)(sizeof(data))); ++j)
		{
			data[j] = ((unsigned char)(rand()));
		}
		t = mk_clib_app_fuzz(data, ((int)(sizeof(data)))); ((void)(t));
	}
	t = printf("\nNot crashed.\n");
	mk_lang_assert(t >= 0);
	return 0;
}