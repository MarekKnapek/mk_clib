#undef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#include "../src/mk_clib_app_vc.h"


int main(int const argc, char const* const* const argv)
{
	return mk_clib_app_vc_args(argc, argv);
}
