echo off
echo ******************************
echo Bulding minhook dependency...
echo ******************************

git clone https://github.com/TsudaKageyu/minhook
cd minhook\build\VC14
msbuild MinHookVC14.sln  /p:Configuration=Release
cd ..\..\..

set TARGET_PLATFORM=amd64
nmake all