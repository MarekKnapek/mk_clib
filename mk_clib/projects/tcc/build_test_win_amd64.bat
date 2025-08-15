rem set path=c:\path\to\tcc;%path%
tcc -impdef ntdll.dll || goto mk_fail
tcc -impdef bcrypt.dll || goto mk_fail
tcc ^
-O0 ^
-Dmk_lang_jumbo_want=1 ^
-Dmk_lang_assert_want=1 ^
-Dmk_lang_crash_detail_want=1 ^
..\..\app\test.c  ^
-o test_amd64.exe ^
ntdll.def ^
bcrypt.def || goto mk_fail
@goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
