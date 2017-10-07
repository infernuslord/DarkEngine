# Microsoft Developer Studio Project File - Name="sndsrc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sndsrc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sndsrc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sndsrc.mak" CFG="sndsrc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sndsrc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sndsrc - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sndsrc - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\comtools" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /FI"..\..\h\types.h" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /GZ /c
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

# Name "sndsrc - Win32 Release"
# Name "sndsrc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\fileseg.cpp
DEP_CPP_FILES=\
	"..\..\h\prikind.h"\
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
	".\sndseg.h"\
	".\sndsegi.h"\
	
NODEP_CPP_FILES=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\imaadpcm.cpp
DEP_CPP_IMAAD=\
	".\imaadpcm.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\memseg.cpp
DEP_CPP_MEMSE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
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
	".\sndseg.h"\
	".\sndsegi.h"\
	
NODEP_CPP_MEMSE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\playlist.cpp
DEP_CPP_PLAYL=\
	"..\..\h\prikind.h"\
	"..\..\h\resapilg.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\lgplaylist.h"\
	".\sndseg.h"\
	".\sndsegi.h"\
	".\sndsrc.h"\
	".\sndsrci.h"\
	".\sndsrcid.h"\
	
NODEP_CPP_PLAYL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\playsrc.c
DEP_CPP_PLAYS=\
	"..\..\h\prikind.h"\
	"..\..\h\resapilg.h"\
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
	"..\sndutil\sndutil.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\sndfmt.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\lgplaylist.h"\
	".\sndsrc.h"\
	".\sndsrcid.h"\
	".\utilmain.h"\
	
NODEP_CPP_PLAYS=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\refill.cpp
DEP_CPP_REFIL=\
	"..\..\h\prikind.h"\
	"..\..\h\resapilg.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\lgplaylist.h"\
	".\sndseg.h"\
	".\sndsrc.h"\
	".\sndsrci.h"\
	".\sndsrcid.h"\
	
NODEP_CPP_REFIL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rezseg.cpp
DEP_CPP_REZSE=\
	"..\..\h\prikind.h"\
	"..\comtools\comtools.h"\
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
	".\sndseg.h"\
	".\sndsegi.h"\
	
NODEP_CPP_REZSE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndseg.cpp
DEP_CPP_SNDSE=\
	"..\comtools\comtools.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	".\sndseg.h"\
	
NODEP_CPP_SNDSE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndsrc.cpp
DEP_CPP_SNDSR=\
	"..\..\h\prikind.h"\
	"..\..\h\resapilg.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\thrdtool.h"\
	"..\lgalloc\memall.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	"..\sound\lgsndid.h"\
	"..\sound\lgsound.h"\
	"..\sound\timelog.h"\
	"..\timer\timer.h"\
	".\lgplaylist.h"\
	".\sndseg.h"\
	".\sndsrc.h"\
	".\sndsrci.h"\
	".\sndsrcid.h"\
	
NODEP_CPP_SNDSR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sndsrcid.cpp
DEP_CPP_SNDSRC=\
	"..\comtools\comtools.h"\
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

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
	

!IF  "$(CFG)" == "sndsrc - Win32 Release"

!ELSEIF  "$(CFG)" == "sndsrc - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\imaadpcm.h
# End Source File
# Begin Source File

SOURCE=.\lgplaylist.h
# End Source File
# Begin Source File

SOURCE=.\sndseg.h
# End Source File
# Begin Source File

SOURCE=.\sndsegi.h
# End Source File
# Begin Source File

SOURCE=.\sndsrc.h
# End Source File
# Begin Source File

SOURCE=.\sndsrci.h
# End Source File
# Begin Source File

SOURCE=.\sndsrcid.h
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
