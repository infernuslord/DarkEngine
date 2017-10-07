# Microsoft Developer Studio Project File - Name="ui" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ui - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ui.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ui.mak" CFG="ui - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ui - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ui - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ui - Win32 Release"

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

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

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

# Name "ui - Win32 Release"
# Name "ui - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\butarray.c
DEP_CPP_BUTAR=\
	"..\..\h\2dres.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\butarray.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\slider.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngbarry.h"\
	".\tngslidr.h"\
	
NODEP_CPP_BUTAR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\curdrw.c
DEP_CPP_CURDR=\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\curdat.h"\
	".\cursors.h"\
	".\curtyp.h"\
	".\region.h"\
	".\slab.h"\
	
NODEP_CPP_CURDR=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cursors.c
DEP_CPP_CURSO=\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\cursors.h"\
	".\curtyp.h"\
	".\region.h"\
	".\slab.h"\
	".\vmouse.h"\
	
NODEP_CPP_CURSO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\event.c
DEP_CPP_EVENT=\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\joystick.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\..\winsrc\input\mousevel.h"\
	"..\compapis\2d.h"\
	"..\compapis\appagg.h"\
	"..\compapis\dispapi.h"\
	"..\compapis\dispguid.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\cursors.h"\
	".\event.h"\
	".\region.h"\
	".\slab.h"\
	".\vmouse.h"\
	
NODEP_CPP_EVENT=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gadgets.c
DEP_CPP_GADGE=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\lgsprntf.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	
NODEP_CPP_GADGE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hotkey.c
DEP_CPP_HOTKE=\
	"..\..\h\_dstruct.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\dstruct\array.h"\
	"..\dstruct\hash.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\hotkey.h"\
	
NODEP_CPP_HOTKE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\menu.c
DEP_CPP_MENU_=\
	"..\..\h\2dres.h"\
	"..\..\h\_dstruct.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\hash.h"\
	"..\dstruct\llist.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\hotkey.h"\
	".\menu.h"\
	".\region.h"\
	".\slab.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngmenu.h"\
	
NODEP_CPP_MENU_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\plain.c
DEP_CPP_PLAIN=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\plain.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngplain.h"\
	
NODEP_CPP_PLAIN=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pushbutt.c
DEP_CPP_PUSHB=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\pushbutt.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngpushb.h"\
	
NODEP_CPP_PUSHB=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\qboxgadg.c
DEP_CPP_QBOXG=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\qboxgadg.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngqbox.h"\
	
NODEP_CPP_QBOXG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\region.c
DEP_CPP_REGIO=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\dstruct\slist.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	
NODEP_CPP_REGIO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\slab.c
DEP_CPP_SLAB_=\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\cursors.h"\
	".\region.h"\
	".\slab.h"\
	
NODEP_CPP_SLAB_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\slider.c
DEP_CPP_SLIDE=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\slider.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngslidr.h"\
	
NODEP_CPP_SLIDE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\textgadg.c
DEP_CPP_TEXTG=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\fakefont.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\slider.h"\
	".\textgadg.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngslidr.h"\
	".\tngtextg.h"\
	
NODEP_CPP_TEXTG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\texttool.c
DEP_CPP_TEXTT=\
	"..\dstruct\rect.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\fakefont.h"\
	".\texttool.h"\
	".\tngfont.h"\
	
NODEP_CPP_TEXTT=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tng.c
DEP_CPP_TNG_C=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	
NODEP_CPP_TNG_C=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngbarry.c
DEP_CPP_TNGBA=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\barrykey.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngbarry.h"\
	".\tngslidr.h"\
	
NODEP_CPP_TNGBA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngfont.c
DEP_CPP_TNGFO=\
	"..\..\h\2dres.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\fakefont.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngfont.h"\
	
NODEP_CPP_TNGFO=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngmenu.c
DEP_CPP_TNGME=\
	"..\..\h\2dres.h"\
	"..\..\h\_dstruct.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\kb.h"\
	"..\..\winsrc\input\kbcook.h"\
	"..\..\winsrc\input\keydefs.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\hash.h"\
	"..\dstruct\llist.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\barrykey.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\hotkey.h"\
	".\region.h"\
	".\slab.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngfont.h"\
	".\tngmenu.h"\
	
NODEP_CPP_TNGME=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngplain.c
DEP_CPP_TNGPL=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngplain.h"\
	
NODEP_CPP_TNGPL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngpushb.c
DEP_CPP_TNGPU=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngpushb.h"\
	
NODEP_CPP_TNGPU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngqbox.c
DEP_CPP_TNGQB=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngqbox.h"\
	".\tngslidr.h"\
	".\tngtextg.h"\
	
NODEP_CPP_TNGQB=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngslidr.c
DEP_CPP_TNGSL=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngslidr.h"\
	
NODEP_CPP_TNGSL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tngtextg.c
DEP_CPP_TNGTE=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\array.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\event.h"\
	".\fakefont.h"\
	".\gadgets.h"\
	".\region.h"\
	".\slab.h"\
	".\texttool.h"\
	".\tng.h"\
	".\tngapp.h"\
	".\tngfont.h"\
	".\tngslidr.h"\
	".\tngtextg.h"\
	
NODEP_CPP_TNGTE=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uires.c
DEP_CPP_UIRES=\
	"..\..\h\2dres.h"\
	"..\..\h\_ui.h"\
	"..\..\h\lgerror.h"\
	"..\..\h\prikind.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\compapis\2d.h"\
	"..\comtools\comtools.h"\
	"..\dev2d\dev2d.h"\
	"..\dstruct\rect.h"\
	"..\fix\fix.h"\
	"..\font\font.h"\
	"..\g2\g2.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lgdatapath.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\recorder\fdesc.h"\
	"..\res\res.h"\
	"..\res\restypes.h"\
	".\cursors.h"\
	".\region.h"\
	".\uires.h"\
	
NODEP_CPP_UIRES=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vmouse.c
DEP_CPP_VMOUS=\
	"..\..\h\lgerror.h"\
	"..\..\winsrc\input\mouse.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	
NODEP_CPP_VMOUS=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "ui - Win32 Release"

!ELSEIF  "$(CFG)" == "ui - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\barrykey.h
# End Source File
# Begin Source File

SOURCE=.\butarray.h
# End Source File
# Begin Source File

SOURCE=.\curdat.h
# End Source File
# Begin Source File

SOURCE=.\cursors.h
# End Source File
# Begin Source File

SOURCE=.\curtyp.h
# End Source File
# Begin Source File

SOURCE=.\event.h
# End Source File
# Begin Source File

SOURCE=.\fakefont.h
# End Source File
# Begin Source File

SOURCE=.\gadgets.h
# End Source File
# Begin Source File

SOURCE=.\hotkey.h
# End Source File
# Begin Source File

SOURCE=.\libdbg.h
# End Source File
# Begin Source File

SOURCE=.\menu.h
# End Source File
# Begin Source File

SOURCE=.\plain.h
# End Source File
# Begin Source File

SOURCE=.\pushbutt.h
# End Source File
# Begin Source File

SOURCE=.\qboxgadg.h
# End Source File
# Begin Source File

SOURCE=.\region.h
# End Source File
# Begin Source File

SOURCE=.\slab.h
# End Source File
# Begin Source File

SOURCE=.\slider.h
# End Source File
# Begin Source File

SOURCE=.\textgadg.h
# End Source File
# Begin Source File

SOURCE=.\texttool.h
# End Source File
# Begin Source File

SOURCE=.\tng.h
# End Source File
# Begin Source File

SOURCE=.\tngapp.h
# End Source File
# Begin Source File

SOURCE=.\tngbarry.h
# End Source File
# Begin Source File

SOURCE=.\tngfont.h
# End Source File
# Begin Source File

SOURCE=.\tngmenu.h
# End Source File
# Begin Source File

SOURCE=.\tngplain.h
# End Source File
# Begin Source File

SOURCE=.\tngpushb.h
# End Source File
# Begin Source File

SOURCE=.\tngqbox.h
# End Source File
# Begin Source File

SOURCE=.\tngslidr.h
# End Source File
# Begin Source File

SOURCE=.\tngtextg.h
# End Source File
# Begin Source File

SOURCE=.\uires.h
# End Source File
# Begin Source File

SOURCE=.\vmouse.h
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
