pushdir
r:
cd \prj\cam\skup\shock\cam
deltree /Y src
mkdir src
cd src
ncopy r:\prj\cam\skup\cam\src\*.* . /s
cd ..
deltree /Y h
mkdir h
cd h
ncopy r:\prj\cam\skup\cam\h\*.* /s
cd ..
deltree /Y inc
mkdir inc
cd inc
ncopy r:\prj\cam\skup\cam\inc\*.* /s
cd ..
deltree /Y lib
mkdir lib
cd lib
ncopy r:\prj\cam\skup\cam\lib\*.* /s
cd ..
deltree /Y obj
mkdir obj
cd obj
ncopy r:\prj\cam\skup\cam\obj\*.* /s
popdir