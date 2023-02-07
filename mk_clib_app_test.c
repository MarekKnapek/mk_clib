#include "mk_clib_fuzz.h"
#include "mk_lang_bi_info.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* srand */
#include <time.h> /* time_t time */


int main(void)
{
	time_t tm;
	long i;
	int j;
	unsigned char data[32];

	printf("Started.\n");
	mk_lang_bi_info_print_sizes();
	tm = time(0);
	srand(((unsigned int)(tm)));
	for(i = 0; i != 1000l * 1000l; ++i)
	{
		for(j = 0; j != ((int)(sizeof(data))); ++j)
		{
			data[j] = ((unsigned char)(rand()));
		}
		mk_clib_fuzz(data, ((int)(sizeof(data))));
	}
	printf("Not crashed.\n");
	return 0;
}
