@echo off


:setup
title C Debugger - Setup
cls
set /p exe="Name of the exe: "
title C Debugger - %exe%.exe
choice /c 123456789 /n /m "Number of codes [1-9]: "
if %errorlevel%==1 goto read1
if %errorlevel%==2 goto read2
if %errorlevel%==3 goto read3
if %errorlevel%==4 goto read4
if %errorlevel%==5 goto read5
if %errorlevel%==6 goto read6
if %errorlevel%==7 goto read7
if %errorlevel%==8 goto read8
if %errorlevel%==9 goto read9


:read1
set /p source1="Code: "
title C Debugger - %exe%.exe (%source1%)
cls
goto compile1

:read2
set /p source1="First code: "
set /p source2="Second code: "
title C Debugger - %exe%.exe (%source1% %source2%)
cls
goto compile2

:read3
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
cls
goto compile3

:read4
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
cls
goto compile4

:read5
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
cls
goto compile5

:read6
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
set /p source6="Sixth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%)
cls
goto compile6

:read7
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
set /p source6="Sixth code: "
set /p source7="Seventh code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%)
cls
goto compile7

:read8
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
set /p source6="Sixth code: "
set /p source7="Seventh code: "
set /p source8="Eighth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%)
cls
goto compile8

:read9
set /p source1="First code: "
set /p source2="Second code: "
set /p source3="Third code: "
set /p source4="Fourth code: "
set /p source5="Fifth code: "
set /p source6="Sixth code: "
set /p source7="Seventh code: "
set /p source8="Eighth code: "
set /p source9="Ninth code: "
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%)
cls
goto compile9


:compile1
echo.
title C Debugger - %exe%.exe (%source1%) - Compiling
gcc -o "%exe%" "%source1%" -lm
title C Debugger - %exe%.exe (%source1%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile1
if %errorlevel%==2 goto rerun1
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile2
echo.
title C Debugger - %exe%.exe (%source1% %source2%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" -lm
title C Debugger - %exe%.exe (%source1% %source2%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile2
if %errorlevel%==2 goto rerun2
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile3
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile3
if %errorlevel%==2 goto rerun3
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile4
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile4
if %errorlevel%==2 goto rerun4
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile5
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile5
if %errorlevel%==2 goto rerun5
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile6
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" "%source6%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile6
if %errorlevel%==2 goto rerun6
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile7
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" "%source6%" "%source7%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile7
if %errorlevel%==2 goto rerun7
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile8
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" "%source6%" "%source7%"  "%source8%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile8
if %errorlevel%==2 goto rerun8
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:compile9
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%) - Compiling
gcc -o "%exe%" "%source1%" "%source2%" "%source3%" "%source4%" "%source5%" "%source6%" "%source7%"  "%source8%" "%source9%" -lm
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile9
if %errorlevel%==2 goto rerun9
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit


:rerun1
echo.
title C Debugger - %exe%.exe (%source1%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile1
if %errorlevel%==2 goto rerun1
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun2
echo.
title C Debugger - %exe%.exe (%source1% %source2%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile2
if %errorlevel%==2 goto rerun2
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun3
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile3
if %errorlevel%==2 goto rerun3
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun4
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile4
if %errorlevel%==2 goto rerun4
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun5
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile5
if %errorlevel%==2 goto rerun5
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun6
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile6
if %errorlevel%==2 goto rerun6
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun7
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile7
if %errorlevel%==2 goto rerun7
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun8
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile8
if %errorlevel%==2 goto rerun8
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit

:rerun9
echo.
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%) - Running
echo START
"%exe%"
echo END
title C Debugger - %exe%.exe (%source1% %source2% %source3% %source4% %source5% %source6% %source7% %source8% %source9%)
echo.
choice /c crstq /n /m "Recompile: c | Rerun: r | Setup: s | Terminal: t | Quit: q"
if %errorlevel%==1 goto compile9
if %errorlevel%==2 goto rerun9
if %errorlevel%==3 goto setup
if %errorlevel%==4 goto terminalhelp
if %errorlevel%==5 goto quit


:terminalhelp
echo.
echo (goto help)

:terminal
set command=
set /p command="<%username%>"
%command%
goto terminal

:help
echo.
echo List of valid commands:
echo goto setup
echo goto read1-9 (You can not change the name of the exe here, you can only reassign the codes to compile.)
echo goto compile1-9
echo goto rerun1-9
echo ...or you can run any valid cmd command from here.
echo.
goto terminal


:quit