#define _CRT_SECURE_NO_WARNINGS
#define mk_lang_jumbo_want 1

#include "../../../src/mk_lib_vc.h"
#include "../../../src/mk_lang_min.h"

#include <stdio.h>
#include <stdlib.h>


#define check(x) do{ if(!(x)){ return EXIT_FAILURE; } }while(0)


int main()
{
	FILE* ifile;
	FILE* ofile;
	void* mem;
	mk_lib_vc_t vc;
	size_t read;
	mk_sl_cui_uint8_pt buff;
	mk_lang_types_usize_t buff_len;
	mk_lib_vc_result_t r;
	size_t written;

	ifile = fopen("c:\\dev\\tmp\\smol.vc", "rb"); check(ifile);
	ofile = fopen("c:\\dev\\tmp\\smol.dat", "wb"); check(ofile);
	mem = malloc(128 * 1024); check(mem);
	mk_lib_vc_init(&vc, ((mk_sl_cui_uint8_pt)(mem)), 128 * 1024, ((mk_sl_cui_uint8_pt)("abc")), 3, 0);
	for(;;)
	{
		mk_lib_vc_get_write_buff(&vc, &buff, &buff_len); check(buff); check(buff_len != 0);
		buff_len = mk_lang_min(4 * 1024, buff_len);
		read = fread(buff, 1, buff_len, ifile); check(read <= buff_len);
		mk_lib_vc_push(&vc, read);
		for(;;)
		{
			r = mk_lib_vc_step(&vc); check(r == mk_lib_vc_result_e_ok || r == mk_lib_vc_result_e_not_enough_input_data || r == mk_lib_vc_result_e_done);
			if(r == mk_lib_vc_result_e_not_enough_input_data || r == mk_lib_vc_result_e_done)
			{
				break;
			}
		}
		for(;;)
		{
			mk_lib_vc_get_read_buff(&vc, &buff, &buff_len);
			if(buff_len != 0)
			{
				check(buff);
				buff_len = mk_lang_min(4 * 1024, buff_len);
				written = fwrite(buff, 1, buff_len, ofile); check(written == buff_len);
				mk_lib_vc_pop(&vc, buff_len);
			}
			else
			{
				break;
			}
		}
		if(read == 0 || r == mk_lib_vc_result_e_done)
		{
			break;
		}
	}
	free(mem);
	fclose(ofile);
	fclose(ifile);
	return EXIT_SUCCESS;
}
