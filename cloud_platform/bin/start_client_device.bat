@echo off

setlocal

set para=x64\Debug

if "%1" NEQ "" set para=%1

set Dir=%~dp0%para%\

@ping -n 1 127.0.0.1>nul
start "client_device" /D %Dir% %Dir%client_device.exe ..\..\client_device.cfg  ..\..\log

REM pause
