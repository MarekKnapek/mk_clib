echo on

mkdir m4
cd m4
git clone https://github.com/MarekKnapek/bin.git
cd bin
git checkout main
git reset --hard origin/main
7z e m4-dep.zip
7z e m4-1.4.14-1-bin.zip
set path=%path%;%cd%
cd ..\..

if "%~1"=="DebugMSVC" goto mk_DebugMSVC
if "%~1"=="ReleaseMSVC" goto mk_ReleaseMSVC
goto :eof
:mk_DebugMSVC
if "%~2"=="x86" goto mk_DebugMSVC_x86
if "%~2"=="x64" goto mk_DebugMSVC_x64
goto :eof
:mk_ReleaseMSVC
if "%~2"=="x86" goto mk_ReleaseMSVC_x86
if "%~2"=="x64" goto mk_ReleaseMSVC_x64
goto :eof

:mk_DebugMSVC_x86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "DebugMSVC|Win32" /Project "%~3" /ProjectConfig "DebugMSVC|Win32" /Out "%~dp0..\..\%~3-debug-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\Win32\DebugMSVC\%~3.exe" "%~dp0..\..\%~3-DebugMSVC-x86.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\Win32\DebugMSVC\%~3.pdb" "%~dp0..\..\%~3-DebugMSVC-x86.pdb"
"%~dp0..\..\%~3-DebugMSVC-x86.exe"
goto :eof
:mk_ReleaseMSVC_x86
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "ReleaseMSVC|Win32" /Project "%~3" /ProjectConfig "ReleaseMSVC|Win32" /Out "%~dp0..\..\%~3-release-x86.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\Win32\ReleaseMSVC\%~3.exe" "%~dp0..\..\%~3-ReleaseMSVC-x86.exe"
"%~dp0..\..\%~3-ReleaseMSVC-x86.exe"
goto :eof
:mk_DebugMSVC_x64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "DebugMSVC|x64" /Project "%~3" /ProjectConfig "DebugMSVC|x64" /Out "%~dp0..\..\%~3-debug-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\x64\DebugMSVC\%~3.exe" "%~dp0..\..\%~3-DebugMSVC-x64.exe"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\x64\DebugMSVC\%~3.pdb" "%~dp0..\..\%~3-DebugMSVC-x64.pdb"
"%~dp0..\..\%~3-DebugMSVC-x64.exe"
goto :eof
:mk_ReleaseMSVC_x64
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" "%~dp0..\..\mk_clib\projects\vs2022\mk_clib.sln" /Build "ReleaseMSVC|x64" /Project "%~3" /ProjectConfig "ReleaseMSVC|x64" /Out "%~dp0..\..\%~3-release-x64.txt"
copy "%~dp0..\..\mk_clib\projects\vs2022\build\out\x64\ReleaseMSVC\%~3.exe" "%~dp0..\..\%~3-ReleaseMSVC-x64.exe"
"%~dp0..\..\%~3-ReleaseMSVC-x64.exe"
goto :eof
