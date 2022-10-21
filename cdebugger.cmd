@echo off


:setup
title C Debugger - Setup
cls
set /p exe="Name of the exe: "
choice /c 12345 /n /m "Number of codes [1-5]: "
if %errorlevel%==1 goto read1
if %errorlevel%==2 goto read2
if %errorlevel%==3 goto read3
if %errorlevel%==4 goto read4
if %errorlevel%==5 goto read5


:read1
set /p source1="Code: "
title C Debugger - %exe%.exe (%source1%)
goto compile1

:read2
set /p source1="First code: "
set /p source2="Second code: "
title C Debugger - %exe%.exe (%source1% %source2%)
goto compile2

:read3
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
goto compile3

:read4
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
goto compile4

:read5
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
goto compile5


:compile1
cls
title C Debugger - %exe%.exe (%source1%) - Compiling
gcc -o "%exe%" "%source1%" -lm
title C Debugger - %exe%.exe (%source1%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile1
if %errorlevel%==2 goto rerun1
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:compile2
cls
title C Debugger - %exe%.exe (%source1% %source2%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" -lm
title C Debugger - %exe%.exe (%source1% %source2%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile2
if %errorlevel%==2 goto rerun2
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:compile3
cls
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile3
if %errorlevel%==2 goto rerun3
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:compile4
cls
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile4
if %errorlevel%==2 goto rerun4
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:compile5
cls
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile5
if %errorlevel%==2 goto rerun5
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit


:rerun1
echo.
title C Debugger - %exe%.exe (%source1%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile1
if %errorlevel%==2 goto rerun1
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:rerun2
echo.
title C Debugger - %exe%.exe (%source1% %source2%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile2
if %errorlevel%==2 goto rerun2
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:rerun3
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile3
if %errorlevel%==2 goto rerun3
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:rerun4
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile4
if %errorlevel%==2 goto rerun4
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit

:rerun5
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Running
"%exe%"
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
echo.
echo.
choice /c crsq /n /m "Recompile: c | Rerun: r | Setup: s | Quit: q"
if %errorlevel%==1 goto compile5
if %errorlevel%==2 goto rerun5
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto quit


:quit