echo off
set PCE_INCLUDE=C:\huc-3.21-win\include\pce
set path=%PATH%;C:\huc-3.21-win\bin
set SRCFILE=test.c

huc %SRCFILE%

pause > nul