rmdir asyn

SET A_V=%1%
if "%A_V%"=="" SET A_V=4-28
mklink /D asyn asyn%A_V%
