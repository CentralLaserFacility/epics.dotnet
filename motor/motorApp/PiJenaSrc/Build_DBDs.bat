SET TOPLEVEL=%1

if not exist %TOPLEVEL%DBD md %TOPLEVEL%DBD

xcopy /Y /Q *.dbd  %TOPLEVEL%DBD > NUL

echo BatchCompleted: %ERRORLEVEL%