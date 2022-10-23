# CleanC-library
"cleanc.h" library for C

Easy debug under windows (MinGW required):
Use the cdebugger.cmd for debugging: open vs code, in terminal type in ./cdebugger
than give the name of exe file you want to generate (without the .exe extension), than
choose the quantity of codes (in the current case you should choose 2), in the end
enter the name of the c files with their .c extension (currently: test.c and cleanc.c).
The order doesn't matter.
(cdebugger.cmd can work standalone, vs code isn't requred)

Compile without cdebugger.cmd: gcc -o test test.c cleanc.c -lm
Than open with: ./test
