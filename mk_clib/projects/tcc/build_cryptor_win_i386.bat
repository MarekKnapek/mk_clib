rem set path=c:\path\to\tcc;%path%
tcc -impdef ntdll.dll || goto mk_fail
tcc -impdef bcrypt.dll || goto mk_fail
tcc -O2 -DNDEBUG ..\..\app\cryptor.c ntdll.def bcrypt.def -o cryptor_i386.exe || goto mk_fail
@goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
