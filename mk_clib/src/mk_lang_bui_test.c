#include "mk_lang_bui_test.h"

#include "mk_lang_bui.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_bui_test(void)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	unsigned long ul;

	ul = 0xfful; mk_lang_bui_ulong_set_zero(&ul); test(ul == 0ul);
	ul = 0xfful; mk_lang_bui_ulong_set_max(&ul); test(ul == 0xfffffffful);
	ul = 0xfful; mk_lang_bui_ulong_set_one(&ul); test(ul == 1ul);

	#undef test
}
