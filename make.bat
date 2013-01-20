rem vim:ft=dos
C:
del NHJR.EXE
cd TC
TCC.EXE -N -I. -L. -I..\INCLUDE -e..\NHJR.EXE ..\TEST\SCREEN.C ..\SRC\WORLD.C ..\SRC\INPUT.C ..\SRC\MAIN.C
cd ..
rem NHJR.EXE
