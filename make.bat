rem vim:ff=dos
C:
del NHJR.EXE
cd TC
rem TCC.EXE -g3 -j3 -w -N -I. -L. -I..\INCLUDE -e..\NHJR.EXE ..\SRC\WORLD.C ..\SRC\INPUT.C ..\SRC\SCREEN.C ..\SRC\MAIN.C ..\SRC\MONST.C GRAPHICS.LIB
rem TCC.EXE -g3 -j3 -N -I. -L. -I..\INCLUDE -e..\NHJR.EXE ..\SRC\WORLD.C ..\SRC\INPUT.C ..\SRC\SCREEN.C ..\SRC\MAIN.C ..\SRC\MONST.C GRAPHICS.LIB
TCC.EXE -I. -L. -g3 -j3 -N -I..\INCLUDE -e..\NHJR.EXE \SRC\*.C GRAPHICS.LIB

cd ..
rem NHJR.EXE
