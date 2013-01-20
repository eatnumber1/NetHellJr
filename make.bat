rem vim:ft=dos
C:
del NHJR.EXE
cd TC
TCC.EXE -N -I. -L. -I..\INCLUDE -e..\NHJR.EXE ..\SRC\WORLD.C ..\SRC\INPUT.C ..\SRC\MAIN.C ..\SRC\SCREEN.C
cd ..
rem NHJR.EXE
