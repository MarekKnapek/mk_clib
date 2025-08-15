rem set path=c:\path\to\tcc;%path%
tcc -O2 -DNDEBUG ..\..\app\info.c -o info_amd64.exe || goto mk_fail
@goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
