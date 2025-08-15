rem set path=c:\path\to\tcc;%path%
tcc -O2 -DNDEBUG ..\..\app\hasher.c -o hasher_i386.exe || goto mk_fail
@goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
