@echo off

setlocal

set para=x64\Debug

if "%1" NEQ "" set para=%1

set Dir=%~dp0%para%\

@ping -n 1 127.0.0.1>nul
start "cloud_platform" /D %Dir% %Dir%cloud_platform.exe ..\..\cloud_platform.cfg  ..\..\log

REM pause
