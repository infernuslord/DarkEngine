pushdir
r:
cd \prj\cam\skup\shock\cam\src
make build FLAV=opt MASTER=shocked SB=R:\prj\cam\skup\shock comp=v50 sys=win32 wdw=wdw
ncopy shockhyb.exe r:\prj\cam\release
popdir