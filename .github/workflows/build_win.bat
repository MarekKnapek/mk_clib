curl -L -o m4-dep.zip http://downloads.sourceforge.net/gnuwin32/m4-1.4.14-1-dep.zip
curl -L -o m4-1.4.14-1-bin.zip http://downloads.sourceforge.net/gnuwin32/m4-1.4.14-1-bin.zip
7z e m4-dep.zip
7z e m4-1.4.14-1-bin.zip
set path=%path%;%cd%
if "%~1"=="debug" goto debug
if "%~1"=="release" goto release
goto :eof
:debug
if "%~2"=="x86" goto debugx86
if "%~2"=="x64" goto debugx64
goto :eof
:release
if "%~2"=="x86" goto releasex86
if "%~2"=="x64" goto releasex64
goto :eof
:debugx86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|x86" /Project "%~3" /ProjectConfig "Debug|Win32" /Out "%~dp0..\..\%~3-debug-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\Debug\%~3.exe" "%~dp0..\..\%~3-debug-x86.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-x86.pdb"
goto :eof
:debugx64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|x64" /Project "%~3" /ProjectConfig "Debug|x64" /Out "%~dp0..\..\%~3-debug-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Debug\%~3.exe" "%~dp0..\..\%~3-debug-x64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-x64.pdb"
goto :eof
:releasex86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|x86" /Project "%~3" /ProjectConfig "Release|Win32" /Out "%~dp0..\..\%~3-release-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\Release\%~3.exe" "%~dp0..\..\%~3-release-x86.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\Release\%~3.pdb" "%~dp0..\..\%~3-release-x86.pdb"
goto :eof
:releasex64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|x64" /Project "%~3" /ProjectConfig "Release|x64" /Out "%~dp0..\..\%~3-release-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Release\%~3.exe" "%~dp0..\..\%~3-release-x64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Release\%~3.pdb" "%~dp0..\..\%~3-release-x64.pdb"
goto :eof
