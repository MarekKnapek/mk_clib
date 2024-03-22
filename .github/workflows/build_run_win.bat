@echo on
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
if "%~2"=="arm32" goto debugarm32
if "%~2"=="arm64" goto debugarm64
if "%~2"=="arm64ec" goto debugarm64ec
goto :eof
:release
if "%~2"=="x86" goto releasex86
if "%~2"=="x64" goto releasex64
if "%~2"=="arm32" goto releasearm32
if "%~2"=="arm64" goto releasearm64
if "%~2"=="arm64ec" goto releasearm64ec
goto :eof
:debugx86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|x86" /Project "%~3" /ProjectConfig "Debug|Win32" /Out "%~dp0..\..\%~3-debug-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\Debug\%~3.exe" "%~dp0..\..\%~3-debug-x86.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-x86.pdb"
"%~dp0..\..\%~3-debug-x86.exe"
goto :eof
:releasex86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|x86" /Project "%~3" /ProjectConfig "Release|Win32" /Out "%~dp0..\..\%~3-release-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\Release\%~3.exe" "%~dp0..\..\%~3-release-x86.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\Release\%~3.pdb" "%~dp0..\..\%~3-release-x86.pdb"
"%~dp0..\..\%~3-release-x86.exe"
goto :eof
:debugx64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|x64" /Project "%~3" /ProjectConfig "Debug|x64" /Out "%~dp0..\..\%~3-debug-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Debug\%~3.exe" "%~dp0..\..\%~3-debug-x64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-x64.pdb"
"%~dp0..\..\%~3-debug-x64.exe"
goto :eof
:releasex64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|x64" /Project "%~3" /ProjectConfig "Release|x64" /Out "%~dp0..\..\%~3-release-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Release\%~3.exe" "%~dp0..\..\%~3-release-x64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\x64\Release\%~3.pdb" "%~dp0..\..\%~3-release-x64.pdb"
"%~dp0..\..\%~3-release-x64.exe"
goto :eof
:debugarm32
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|ARM" /Project "%~3" /ProjectConfig "Debug|ARM" /Out "%~dp0..\..\%~3-debug-arm32.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM\Debug\%~3.exe" "%~dp0..\..\%~3-debug-arm32.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-arm32.pdb"
"%~dp0..\..\%~3-debug-x86.exe"
goto :eof
:releasearm32
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|ARM" /Project "%~3" /ProjectConfig "Release|ARM" /Out "%~dp0..\..\%~3-release-arm32.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM\Release\%~3.exe" "%~dp0..\..\%~3-release-arm32.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM\Release\%~3.pdb" "%~dp0..\..\%~3-release-arm32.pdb"
"%~dp0..\..\%~3-release-x86.exe"
goto :eof
:debugarm64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|ARM64" /Project "%~3" /ProjectConfig "Debug|ARM64" /Out "%~dp0..\..\%~3-debug-arm64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64\Debug\%~3.exe" "%~dp0..\..\%~3-debug-arm64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-arm64.pdb"
"%~dp0..\..\%~3-debug-x86.exe"
goto :eof
:releasearm64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|ARM64" /Project "%~3" /ProjectConfig "Release|ARM64" /Out "%~dp0..\..\%~3-release-arm64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64\Release\%~3.exe" "%~dp0..\..\%~3-release-arm64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64\Release\%~3.pdb" "%~dp0..\..\%~3-release-arm64.pdb"
"%~dp0..\..\%~3-release-x86.exe"
goto :eof
:debugarm64ec
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Debug|ARM64EC" /Project "%~3" /ProjectConfig "Debug|ARM64EC" /Out "%~dp0..\..\%~3-debug-arm64ec.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64EC\Debug\%~3.exe" "%~dp0..\..\%~3-debug-arm64ec.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64EC\Debug\%~3.pdb" "%~dp0..\..\%~3-debug-arm64ec.pdb"
"%~dp0..\..\%~3-debug-x86.exe"
goto :eof
:releasearm64ec
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "Release|ARM64EC" /Project "%~3" /ProjectConfig "Release|ARM64EC" /Out "%~dp0..\..\%~3-release-arm64ec.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64EC\Release\%~3.exe" "%~dp0..\..\%~3-release-arm64ec.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\ARM64EC\Release\%~3.pdb" "%~dp0..\..\%~3-release-arm64ec.pdb"
"%~dp0..\..\%~3-release-x86.exe"
goto :eof
