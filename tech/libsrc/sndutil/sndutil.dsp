# Microsoft Developer Studio Project File - Name="sndutil" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sndutil - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sndutil.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sndutil.mak" CFG="sndutil - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sndutil - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sndutil - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sndutil - Win32 Release"

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

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

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

# Name "sndutil - Win32 Release"
# Name "sndutil - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\foneshot.c
DEP_CPP_FONES=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\oneshot.h"\
	".\sndutil.h"\
	
NODEP_CPP_FONES=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fsplicer.c
DEP_CPP_FSPLI=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\splicer.h"\
	
NODEP_CPP_FSPLI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fstremer.c
DEP_CPP_FSTRE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\streamer.h"\
	
NODEP_CPP_FSTRE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\imaadpcm.cpp
DEP_CPP_IMAAD=\
	".\imaadpcm.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mstremer.c
DEP_CPP_MSTRE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\streamer.h"\
	
NODEP_CPP_MSTRE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\onemain.c
DEP_CPP_ONEMA=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	".\sndutil.h"\
	".\utilmain.h"\
	
NODEP_CPP_ONEMA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\oneshot.c
DEP_CPP_ONESH=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\oneshot.h"\
	".\sndutil.h"\
	
NODEP_CPP_ONESH=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\roneshot.c
DEP_CPP_RONES=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\oneshot.h"\
	".\sndutil.h"\
	
NODEP_CPP_RONES=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsplicer.c
DEP_CPP_RSPLI=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\splicer.h"\
	
NODEP_CPP_RSPLI=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rstremer.c
DEP_CPP_RSTRE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\streamer.h"\
	
NODEP_CPP_RSTRE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndrezst.c
DEP_CPP_SNDRE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndrezst.h"\
	
NODEP_CPP_SNDRE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\splcmain.c
DEP_CPP_SPLCM=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	".\sndutil.h"\
	".\utilmain.h"\
	
NODEP_CPP_SPLCM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\splicer.c
DEP_CPP_SPLIC=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\splicer.h"\
	
NODEP_CPP_SPLIC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\streamer.c
DEP_CPP_STREA=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\imaadpcm.h"\
	".\sndutil.h"\
	".\streamer.h"\
	
NODEP_CPP_STREA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\strmmain.c
DEP_CPP_STRMM=\
	"..\..\h\prikind.h"\
	"..\compapis\appagg.h"\
	"..\compapis\appapi.h"\
	"..\compapis\pumpenum.h"\
	"..\compapis\wappapi.h"\
	"..\compapis\wappguid.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\sndutil.h"\
	".\utilmain.h"\
	
NODEP_CPP_STRMM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\utilmain.c
DEP_CPP_UTILM=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	".\utilmain.h"\
	
NODEP_CPP_UTILM=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndutil - Win32 Release"

!ELSEIF  "$(CFG)" == "sndutil - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\imaadpcm.h
# End Source File
# Begin Source File

SOURCE=.\oneshot.h
# End Source File
# Begin Source File

SOURCE=.\sndrezst.h
# End Source File
# Begin Source File

SOURCE=.\sndutil.h
# End Source File
# Begin Source File

SOURCE=.\splicer.h
# End Source File
# Begin Source File

SOURCE=.\streamer.h
# End Source File
# Begin Source File

SOURCE=.\utilmain.h
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
