# Microsoft Developer Studio Project File - Name="actmovie" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=actmovie - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "actmovie.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "actmovie.mak" CFG="actmovie - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "actmovie - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "actmovie - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "actmovie - Win32 Release"

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

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

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

# Name "actmovie - Win32 Release"
# Name "actmovie - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\actmovie.cpp
DEP_CPP_ACTMO=\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\compapis\movconst.h"\
	"..\compapis\movieapi.h"\
	"..\compapis\moviguid.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\recapi.h"\
	"..\compapis\recguid.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\aggmemb.h"\
	"..\comtools\comtools.h"\
	"..\comtools\constrid.h"\
	"..\comtools\objcguid.h"\
	"..\dev2d\dev2d.h"\
	"..\dispdev\wdispapi.h"\
	"..\dispdev\wdspguid.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\gadget\util2d.h"\
	"..\gadget\utilcomp.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\namedres\datasrc.h"\
	"..\res\lzw.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\actmovie.h"\
	".\amalloc.h"\
	".\amvideo.h"\
	".\control.h"\
	".\evcode.h"\
	".\getlgvid.h"\
	".\imutil.h"\
	".\lgvdguid.h"\
	".\lgvidapi.h"\
	".\mtype.h"\
	".\strmif.h"\
	".\uuids.h"\
	".\vfwmsgs.h"\
	
NODEP_CPP_ACTMO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\amalloc.cpp
DEP_CPP_AMALL=\
	"..\compapis\movconst.h"\
	"..\compapis\movieapi.h"\
	"..\compapis\moviguid.h"\
	"..\comtools\comtools.h"\
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
	".\actmovie.h"\
	".\amalloc.h"\
	".\amvideo.h"\
	".\control.h"\
	".\evcode.h"\
	".\lgvidapi.h"\
	".\mtype.h"\
	".\strmif.h"\
	".\uuids.h"\
	".\vfwmsgs.h"\
	
NODEP_CPP_AMALL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\amguids.cpp
DEP_CPP_AMGUI=\
	".\uuids.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\getlgvid.cpp
DEP_CPP_GETLG=\
	"..\cpptools\filekind.h"\
	"..\cpptools\filepath.h"\
	"..\cpptools\filespec.h"\
	"..\cpptools\fnamutil.h"\
	"..\cpptools\str.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\getlgvid.h"\
	
NODEP_CPP_GETLG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\imutil.cpp
DEP_CPP_IMUTI=\
	"..\dev2d\astring.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\amvideo.h"\
	".\imutil.h"\
	".\mtype.h"\
	".\strmif.h"\
	".\uuids.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mtype.cpp
DEP_CPP_MTYPE=\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	".\mtype.h"\
	".\strmif.h"\
	

!IF  "$(CFG)" == "actmovie - Win32 Release"

!ELSEIF  "$(CFG)" == "actmovie - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\actmovie.h
# End Source File
# Begin Source File

SOURCE=.\amalloc.h
# End Source File
# Begin Source File

SOURCE=.\amvideo.h
# End Source File
# Begin Source File

SOURCE=.\control.h
# End Source File
# Begin Source File

SOURCE=.\evcode.h
# End Source File
# Begin Source File

SOURCE=.\getlgvid.h
# End Source File
# Begin Source File

SOURCE=.\imutil.h
# End Source File
# Begin Source File

SOURCE=.\lgvdguid.h
# End Source File
# Begin Source File

SOURCE=.\lgvidapi.h
# End Source File
# Begin Source File

SOURCE=.\mtype.h
# End Source File
# Begin Source File

SOURCE=.\strmif.h
# End Source File
# Begin Source File

SOURCE=.\uuids.h
# End Source File
# Begin Source File

SOURCE=.\vfwmsgs.h
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
