# Microsoft Developer Studio Project File - Name="dispdev" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=dispdev - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dispdev.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dispdev.mak" CFG="dispdev - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dispdev - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "dispdev - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dispdev - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\_Libs\Release"
# PROP Intermediate_Dir "..\_Bins\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "SHIP" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\_Libs\Debug"
# PROP Intermediate_Dir "..\_Bins\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
# ADD BASE RSC /l 0x816 /d "_DEBUG"
# ADD RSC /l 0x816 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "dispdev - Win32 Release"
# Name "dispdev - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\aggddraw.cpp
DEP_CPP_AGGDD=\
	"..\..\h\prikind.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\aggddraw.h"\
	
NODEP_CPP_AGGDD=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cbchain.cpp
DEP_CPP_CBCHA=\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	".\cbchain.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dddynf.cpp
DEP_CPP_DDDYN=\
	"..\cpptools\dynfunc.h"\
	".\dddynf.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ddisp.cpp
DEP_CPP_DDISP=\
	"..\..\h\prikind.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	".\ddisp.h"\
	".\dispbase.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dispbase.cpp
DEP_CPP_DISPB=\
	"..\..\h\prikind.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\dispbase.h"\
	
NODEP_CPP_DISPB=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdcreate.cpp
DEP_CPP_WDCRE=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynfunc.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\dbmem.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\dddynf.h"\
	".\dispbase.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdispdd.h"\
	".\wdispgdi.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDCRE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wddmode.cpp
DEP_CPP_WDDMO=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\dispbase.h"\
	".\wdcreate.h"\
	".\wddmode.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdispdd.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDDMO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdisp.cpp
DEP_CPP_WDISP=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\cbchain.h"\
	".\dispbase.h"\
	".\wdcreate.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdispcb.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDISP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdispdd.cpp
DEP_CPP_WDISPD=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\dynfunc.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\dddynf.h"\
	".\dispbase.h"\
	".\wdcreate.h"\
	".\wddmode.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdispdd.h"\
	".\wdisptls.h"\
	".\wdspgshl.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDISPD=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdispgdi.cpp
DEP_CPP_WDISPG=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\dispbase.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdispgdi.h"\
	".\wdisptls.h"\
	".\wdspgshl.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDISPG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdisptls.cpp

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdspgshl.cpp
DEP_CPP_WDSPG=\
	"..\compapis\appagg.h"\
	"..\compapis\gshelapi.h"\
	"..\compapis\gshlguid.h"\
	"..\compapis\pumpenum.h"\
	"..\comtools\comtools.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdspmode.cpp
DEP_CPP_WDSPM=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\dispbase.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdspguid.h"\
	".\wdspmode.h"\
	
NODEP_CPP_WDSPM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wdspprov.cpp
DEP_CPP_WDSPP=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\comtools\objcoll.h"\
	"..\cpptools\relocptr.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\dispbase.h"\
	".\wdisp.h"\
	".\wdispapi.h"\
	".\wdspguid.h"\
	".\wdspprov.h"\
	
NODEP_CPP_WDSPP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dispdev - Win32 Release"

!ELSEIF  "$(CFG)" == "dispdev - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\aggddraw.h
# End Source File
# Begin Source File

SOURCE=.\cbchain.h
# End Source File
# Begin Source File

SOURCE=.\dddynf.h
# End Source File
# Begin Source File

SOURCE=.\ddisp.h
# End Source File
# Begin Source File

SOURCE=.\dispbase.h
# End Source File
# Begin Source File

SOURCE=.\wdcreate.h
# End Source File
# Begin Source File

SOURCE=.\wddmode.h
# End Source File
# Begin Source File

SOURCE=.\wdisp.h
# End Source File
# Begin Source File

SOURCE=.\wdispapi.h
# End Source File
# Begin Source File

SOURCE=.\wdispcb.h
# End Source File
# Begin Source File

SOURCE=.\wdispdd.h
# End Source File
# Begin Source File

SOURCE=.\wdispgdi.h
# End Source File
# Begin Source File

SOURCE=.\wdisptls.h
# End Source File
# Begin Source File

SOURCE=.\wdspgshl.h
# End Source File
# Begin Source File

SOURCE=.\wdspguid.h
# End Source File
# Begin Source File

SOURCE=.\wdspmode.h
# End Source File
# Begin Source File

SOURCE=.\wdspprov.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# End Group
# End Target
# End Project
