# Microsoft Developer Studio Project File - Name="dev2d" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=dev2d - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dev2d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dev2d.mak" CFG="dev2d - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dev2d - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "dev2d - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dev2d - Win32 Release"

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

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

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

# Name "dev2d - Win32 Release"
# Name "dev2d - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\astring.c
DEP_CPP_ASTRI=\
	".\astring.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bank.c

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bitmap.c
DEP_CPP_BITMA=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grd.h"\
	".\grmalloc.h"\
	".\grs.h"\
	".\rgb.h"\
	".\valloc.h"\
	
NODEP_CPP_BITMA=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8bm.c
DEP_CPP_BK8BM=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\emode.h"\
	".\fill.h"\
	".\grd.h"\
	".\grs.h"\
	".\indexmac.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8fl8.c
DEP_CPP_BK8FL=\
	"..\fix\fix.h"\
	".\bank.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8hlin.c
DEP_CPP_BK8HL=\
	"..\fix\fix.h"\
	".\bank.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8lin.c
DEP_CPP_BK8LI=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\linftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8pix.c
DEP_CPP_BK8PI=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8pix8.c
DEP_CPP_BK8PIX=\
	"..\fix\fix.h"\
	".\bank.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bk8vlin.c
DEP_CPP_BK8VL=\
	"..\fix\fix.h"\
	".\bank.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\blend.c
DEP_CPP_BLEND=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\alpha.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grs.h"\
	
NODEP_CPP_BLEND=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\canvas.c
DEP_CPP_CANVA=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\fill.h"\
	".\grd.h"\
	".\grmalloc.h"\
	".\grs.h"\
	".\rgb.h"\
	".\valloc.h"\
	
NODEP_CPP_CANVA=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clpfl8.c
DEP_CPP_CLPFL=\
	"..\fix\fix.h"\
	".\clip.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clut16.c
DEP_CPP_CLUT1=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\alpha.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grs.h"\
	
NODEP_CPP_CLUT1=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cominit.c
DEP_CPP_COMIN=\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	".\comdfcn.h"\
	".\devtab.h"\
	".\dftctab.h"\
	".\emode.h"\
	".\grc.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cpal.c
DEP_CPP_CPAL_=\
	".\cpal.h"\
	".\pal_.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ddevblt.c
DEP_CPP_DDEVB=\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\canvas.h"\
	".\comdfcn.h"\
	".\emode.h"\
	".\fill.h"\
	".\gdbm.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\indexmac.h"\
	".\rgb.h"\
	
NODEP_CPP_DDEVB=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\devstubs.c
DEP_CPP_DEVST=\
	".\grnull.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16bm.c
DEP_CPP_F16BM=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\emode.h"\
	".\fill.h"\
	".\grd.h"\
	".\grs.h"\
	".\indexmac.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16f16.c
DEP_CPP_F16F1=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\astring.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\f16il.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	
NODEP_CPP_F16F1=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8.c
DEP_CPP_F16FL=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pal16.h"\
	".\rgb.h"\
	
NODEP_CPP_F16FL=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16hlin.c
DEP_CPP_F16HL=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\f16il.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16lin.c
DEP_CPP_F16LI=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\linftype.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16mono.c
DEP_CPP_F16MO=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16pix.c
DEP_CPP_F16PI=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16pix16.c
DEP_CPP_F16PIX=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16pix8.c
DEP_CPP_F16PIX8=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16rsd8.c
DEP_CPP_F16RS=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\f16il.h"\
	".\grd.h"\
	".\grs.h"\
	".\pal16.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16vlin.c
DEP_CPP_F16VL=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\f16il.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fcolor.c
DEP_CPP_FCOLO=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\emode.h"\
	".\fcolor.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grs.h"\
	".\idevice.h"\
	".\mode.h"\
	".\pal16.h"\
	".\rgb.h"\
	".\state.h"\
	
NODEP_CPP_FCOLO=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8bk8.c
DEP_CPP_FL8BK=\
	"..\fix\fix.h"\
	".\bank.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8bm.c
DEP_CPP_FL8BM=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\emode.h"\
	".\fill.h"\
	".\grd.h"\
	".\grs.h"\
	".\indexmac.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8.c
DEP_CPP_FL8FL=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\astring.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	
NODEP_CPP_FL8FL=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8hlin.c
DEP_CPP_FL8HL=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lin.c
DEP_CPP_FL8LI=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\linftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8mono.c
DEP_CPP_FL8MO=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8mx.c
DEP_CPP_FL8MX=\
	"..\..\h\nameconv.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mxlatch.h"\
	".\rgb.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8pix.c
DEP_CPP_FL8PI=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8pix8.c
DEP_CPP_FL8PIX=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8rsd8.c
DEP_CPP_FL8RS=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8vlin.c
DEP_CPP_FL8VL=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdbm.c
DEP_CPP_GDBM_=\
	"..\fix\fix.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\gdbm.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdgbm.c
DEP_CPP_GDGBM=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\canvas.h"\
	".\emode.h"\
	".\gdbm.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdlin.c
DEP_CPP_GDLIN=\
	"..\fix\fix.h"\
	".\clip.h"\
	".\emode.h"\
	".\gdlin.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\linftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdpix.c
DEP_CPP_GDPIX=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\clip.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdrect.c
DEP_CPP_GDREC=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\clip.h"\
	".\context.h"\
	".\emode.h"\
	".\gdlin.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\linftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gdtest.c
DEP_CPP_GDTES=\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\dev2d.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genbm.c
DEP_CPP_GENBM=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdrect.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16.c
DEP_CPP_GENF1=\
	"..\fix\fix.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16u.c
DEP_CPP_GENF16=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8.c
DEP_CPP_GENFL=\
	"..\fix\fix.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8u.c
DEP_CPP_GENFL8=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\pal16.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genlin.c
DEP_CPP_GENLI=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genmono.c
DEP_CPP_GENMO=\
	"..\fix\fix.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genmonou.c
DEP_CPP_GENMON=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\context.h"\
	".\emode.h"\
	".\gdpix.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genmx.c
DEP_CPP_GENMX=\
	"..\fix\fix.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrsd8.c
DEP_CPP_GENRS=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\clip.h"\
	".\emode.h"\
	".\gdbm.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\rgb.h"\
	".\rsd.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gpal.c
DEP_CPP_GPAL_=\
	"..\fix\fix.h"\
	".\gpal.h"\
	".\pal_.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gpix.c
DEP_CPP_GPIX_=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grnull.h"\
	".\grs.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gr.c

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grd.c
DEP_CPP_GRD_C=\
	"..\..\h\dpmi.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grs.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grmalloc.c

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grnull.c
DEP_CPP_GRNUL=\
	"..\lg\dbg.h"\
	
NODEP_CPP_GRNUL=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hflip.c
DEP_CPP_HFLIP=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grs.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\init.c
DEP_CPP_INIT_=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	".\detect.h"\
	".\emode.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grs.h"\
	".\idevice.h"\
	".\init.h"\
	".\rgb.h"\
	".\state.h"\
	
NODEP_CPP_INIT_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ipal.c
DEP_CPP_IPAL_=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grmalloc.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lpix.c
DEP_CPP_LPIX_=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ltab.c
DEP_CPP_LTAB_=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\emode.h"\
	".\grs.h"\
	".\pal16.h"\
	
NODEP_CPP_LTAB_=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mode.c
DEP_CPP_MODE_=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxbm.c
DEP_CPP_MXBM_=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\emode.h"\
	".\fill.h"\
	".\grd.h"\
	".\grs.h"\
	".\indexmac.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxfl8.c
DEP_CPP_MXFL8=\
	"..\..\h\nameconv.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mxlatch.h"\
	".\rgb.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxhlin.c
DEP_CPP_MXHLI=\
	"..\..\h\nameconv.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mxlatch.h"\
	".\rgb.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxlatch.c

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxlin.c
DEP_CPP_MXLIN=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\linftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxpix.c
DEP_CPP_MXPIX=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\pixftype.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxpix8.c
DEP_CPP_MXPIX8=\
	"..\..\h\nameconv.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mxlatch.h"\
	".\rgb.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mxvlin.c
DEP_CPP_MXVLI=\
	"..\..\h\nameconv.h"\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mxlatch.h"\
	".\rgb.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\novinit.c
DEP_CPP_NOVIN=\
	"..\fix\fix.h"\
	".\devtab.h"\
	".\dftctab.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\nulcnv.c
DEP_CPP_NULCN=\
	".\grnull.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\nulldfcn.c
DEP_CPP_NULLD=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	".\state.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pal.c
DEP_CPP_PAL_C=\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	".\buffer.h"\
	".\emode.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grs.h"\
	".\idevice.h"\
	".\mode.h"\
	".\pal.h"\
	".\pal16.h"\
	".\pal_.h"\
	".\rgb.h"\
	".\state.h"\
	
NODEP_CPP_PAL_C=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pal16.c
DEP_CPP_PAL16=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grmalloc.h"\
	".\grs.h"\
	".\pal16.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsdcvt.c
DEP_CPP_RSDCV=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\bitmap.h"\
	".\bmftype.h"\
	".\emode.h"\
	".\gdbm.h"\
	".\grd.h"\
	".\grs.h"\
	".\icanvas.h"\
	".\rgb.h"\
	".\rsd.h"\
	".\rsdcfg.h"\
	
NODEP_CPP_RSDCV=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\screen.c
DEP_CPP_SCREE=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\bitmap.h"\
	".\canvas.h"\
	".\context.h"\
	".\emode.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grmalloc.h"\
	".\grs.h"\
	".\idevice.h"\
	".\mode.h"\
	".\rgb.h"\
	".\state.h"\
	".\valloc.h"\
	
NODEP_CPP_SCREE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sfoc.c
DEP_CPP_SFOC_=\
	"..\fix\fix.h"\
	".\bitmap.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\smode.c
DEP_CPP_SMODE=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grs.h"\
	".\idevice.h"\
	".\mode.h"\
	".\rgb.h"\
	".\state.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\stastk.c
DEP_CPP_STAST=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grdev.h"\
	".\grs.h"\
	".\idevice.h"\
	".\rgb.h"\
	".\state.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\svgainit.c
DEP_CPP_SVGAI=\
	"..\fix\fix.h"\
	".\devtab.h"\
	".\dftctab.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	".\vesa.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tluctab.c
DEP_CPP_TLUCT=\
	"..\fix\fix.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\valloc.c
DEP_CPP_VALLO=\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\fix\fix.h"\
	".\comdfcn.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\rgb.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vesac.c
DEP_CPP_VESAC=\
	"..\..\h\dpmi.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lgalloc\memall.h"\
	".\bitmap.h"\
	".\devtab.h"\
	".\dpmidat.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\idevice.h"\
	".\mode.h"\
	".\rgb.h"\
	".\valloc.h"\
	".\vesa.h"\
	".\vga.h"\
	".\vgareg.h"\
	
NODEP_CPP_VESAC=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vgastate.c
DEP_CPP_VGAST=\
	"..\..\h\dpmi.h"\
	"..\fix\fix.h"\
	".\dpmidat.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	".\state.h"\
	".\vga.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vsastate.c
DEP_CPP_VSAST=\
	"..\..\h\dpmi.h"\
	"..\fix\fix.h"\
	".\dpmidat.h"\
	".\emode.h"\
	".\grd.h"\
	".\grs.h"\
	".\mode.h"\
	".\rgb.h"\
	".\state.h"\
	".\vesa.h"\
	".\vga.h"\
	".\vgareg.h"\
	

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\alpha.h
# End Source File
# Begin Source File

SOURCE=.\astring.h
# End Source File
# Begin Source File

SOURCE=.\bank.h
# End Source File
# Begin Source File

SOURCE=.\bank8.h
# End Source File
# Begin Source File

SOURCE=.\bitmap.h
# End Source File
# Begin Source File

SOURCE=.\bk8bm.h
# End Source File
# Begin Source File

SOURCE=.\bk8lin.h
# End Source File
# Begin Source File

SOURCE=.\bk8pix.h
# End Source File
# Begin Source File

SOURCE=.\blnfcn.h
# End Source File
# Begin Source File

SOURCE=.\bmftype.h
# End Source File
# Begin Source File

SOURCE=.\buffer.h
# End Source File
# Begin Source File

SOURCE=.\canvas.h
# End Source File
# Begin Source File

SOURCE=.\clip.h
# End Source File
# Begin Source File

SOURCE=.\comdfcn.h
# End Source File
# Begin Source File

SOURCE=.\context.h
# End Source File
# Begin Source File

SOURCE=.\cpal.h
# End Source File
# Begin Source File

SOURCE=.\cppify.h
# End Source File
# Begin Source File

SOURCE=.\ddevblt.h
# End Source File
# Begin Source File

SOURCE=.\detect.h
# End Source File
# Begin Source File

SOURCE=.\dev2d.h
# End Source File
# Begin Source File

SOURCE=.\devtab.h
# End Source File
# Begin Source File

SOURCE=.\dftctab.h
# End Source File
# Begin Source File

SOURCE=.\dpmidat.h
# End Source File
# Begin Source File

SOURCE=.\dtabfcn.h
# End Source File
# Begin Source File

SOURCE=.\emode.h
# End Source File
# Begin Source File

SOURCE=.\f16bm.h
# End Source File
# Begin Source File

SOURCE=.\f16il.h
# End Source File
# Begin Source File

SOURCE=.\f16lin.h
# End Source File
# Begin Source File

SOURCE=.\f16pix.h
# End Source File
# Begin Source File

SOURCE=.\fcolor.h
# End Source File
# Begin Source File

SOURCE=.\fill.h
# End Source File
# Begin Source File

SOURCE=.\fl8bm.h
# End Source File
# Begin Source File

SOURCE=.\fl8lin.h
# End Source File
# Begin Source File

SOURCE=.\fl8pix.h
# End Source File
# Begin Source File

SOURCE=.\flat16.h
# End Source File
# Begin Source File

SOURCE=.\flat8.h
# End Source File
# Begin Source File

SOURCE=.\gdbm.h
# End Source File
# Begin Source File

SOURCE=.\gdlin.h
# End Source File
# Begin Source File

SOURCE=.\gdpix.h
# End Source File
# Begin Source File

SOURCE=.\gdrect.h
# End Source File
# Begin Source File

SOURCE=.\gdulin.h
# End Source File
# Begin Source File

SOURCE=.\genbm.h
# End Source File
# Begin Source File

SOURCE=.\general.h
# End Source File
# Begin Source File

SOURCE=.\genlin.h
# End Source File
# Begin Source File

SOURCE=.\gpal.h
# End Source File
# Begin Source File

SOURCE=.\gr.h
# End Source File
# Begin Source File

SOURCE=.\grc.h
# End Source File
# Begin Source File

SOURCE=.\grd.h
# End Source File
# Begin Source File

SOURCE=.\grdev.h
# End Source File
# Begin Source File

SOURCE=.\grmalloc.h
# End Source File
# Begin Source File

SOURCE=.\grnull.h
# End Source File
# Begin Source File

SOURCE=.\grs.h
# End Source File
# Begin Source File

SOURCE=.\icanvas.h
# End Source File
# Begin Source File

SOURCE=.\idevice.h
# End Source File
# Begin Source File

SOURCE=.\indexmac.h
# End Source File
# Begin Source File

SOURCE=.\init.h
# End Source File
# Begin Source File

SOURCE=.\linftype.h
# End Source File
# Begin Source File

SOURCE=.\mode.h
# End Source File
# Begin Source File

SOURCE=.\modex.h
# End Source File
# Begin Source File

SOURCE=.\mxbm.h
# End Source File
# Begin Source File

SOURCE=.\mxlatch.h
# End Source File
# Begin Source File

SOURCE=.\mxlin.h
# End Source File
# Begin Source File

SOURCE=.\mxpix.h
# End Source File
# Begin Source File

SOURCE=.\pal.h
# End Source File
# Begin Source File

SOURCE=.\pal16.h
# End Source File
# Begin Source File

SOURCE=.\pal_.h
# End Source File
# Begin Source File

SOURCE=.\pixftype.h
# End Source File
# Begin Source File

SOURCE=.\rgb.h
# End Source File
# Begin Source File

SOURCE=.\rsd.h
# End Source File
# Begin Source File

SOURCE=.\rsdcfg.h
# End Source File
# Begin Source File

SOURCE=.\screen.h
# End Source File
# Begin Source File

SOURCE=.\state.h
# End Source File
# Begin Source File

SOURCE=.\tluctab.h
# End Source File
# Begin Source File

SOURCE=.\valloc.h
# End Source File
# Begin Source File

SOURCE=.\vesa.h
# End Source File
# Begin Source File

SOURCE=.\vga.h
# End Source File
# Begin Source File

SOURCE=.\vgareg.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\cstring.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16f16c.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16f16l.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8il.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16il.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16set.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\light.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsdblt.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsdblt16.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsdblt8.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rsdunpck.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vesaasm.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vgaasm.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vgasmod.asm

!IF  "$(CFG)" == "dev2d - Win32 Release"

!ELSEIF  "$(CFG)" == "dev2d - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\bitmap.inc
# End Source File
# Begin Source File

SOURCE=.\cseg.inc
# End Source File
# Begin Source File

SOURCE=.\dseg.inc
# End Source File
# Begin Source File

SOURCE=.\gdican.inc
# End Source File
# Begin Source File

SOURCE=.\grd.inc
# End Source File
# Begin Source File

SOURCE=.\grs.inc
# End Source File
# Begin Source File

SOURCE=.\lightd.inc
# End Source File
# Begin Source File

SOURCE=.\mode.inc
# End Source File
# Begin Source File

SOURCE=.\rsdblt.inc
# End Source File
# Begin Source File

SOURCE=.\rsdunpck.inc
# End Source File
# Begin Source File

SOURCE=.\valloc.inc
# End Source File
# Begin Source File

SOURCE=.\vesa.inc
# End Source File
# Begin Source File

SOURCE=.\vgabios.inc
# End Source File
# Begin Source File

SOURCE=.\vgaregs.inc
# End Source File
# End Group
# Begin Group "Asm Tbl Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bk8cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\bk8hlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\bk8p8f.tbl
# End Source File
# Begin Source File

SOURCE=.\bk8ubmf.tbl
# End Source File
# Begin Source File

SOURCE=.\bk8vlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\comdfcn.cc
# End Source File
# Begin Source File

SOURCE=.\comdtab.tbl
# End Source File
# Begin Source File

SOURCE=.\ddevcnv.tbl
# End Source File
# Begin Source File

SOURCE=.\f16cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\f16hlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16p16f.tbl
# End Source File
# Begin Source File

SOURCE=.\f16p8f.tbl
# End Source File
# Begin Source File

SOURCE=.\f16ubmf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16vlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8dtab.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8hlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8p16f.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8p8f.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8ubmf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8vlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\genbmf.tbl
# End Source File
# Begin Source File

SOURCE=.\mxcnv.tbl
# End Source File
# Begin Source File

SOURCE=.\mxhlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\mxp8f.tbl
# End Source File
# Begin Source File

SOURCE=.\mxubmf.tbl
# End Source File
# Begin Source File

SOURCE=.\mxvlinf.tbl
# End Source File
# Begin Source File

SOURCE=.\novdtab.tbl
# End Source File
# Begin Source File

SOURCE=.\vesa.h.new
# End Source File
# Begin Source File

SOURCE=.\vgadtab.tbl
# End Source File
# Begin Source File

SOURCE=.\vsadtab.tbl
# End Source File
# Begin Source File

SOURCE=.\w32dtab.tbl
# End Source File
# End Group
# End Target
# End Project
