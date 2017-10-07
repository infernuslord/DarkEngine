# Microsoft Developer Studio Project File - Name="g2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=g2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "g2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "g2.mak" CFG="g2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "g2 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "g2 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "g2 - Win32 Release"

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

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

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

# Name "g2 - Win32 Release"
# Name "g2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\area.c
DEP_CPP_AREA_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\blend.c
DEP_CPP_BLEND=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\blncon.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cc816.c
DEP_CPP_CC816=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\scshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\chkply.c
DEP_CPP_CHKPL=\
	"..\fix\fix.h"\
	".\plytyp.h"\
	".\polyint.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clip.c
DEP_CPP_CLIP_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2clip.h"\
	".\g2spoint.h"\
	".\plytyp.h"\
	
NODEP_CPP_CLIP_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\clplin.c
DEP_CPP_CLPLI=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\lftype.h"\
	".\mathmac.h"\
	".\plytyp.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\co88.c
DEP_CPP_CO88_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cominit.c
DEP_CPP_COMIN=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dlh816.c
DEP_CPP_DLH81=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\drytmap.c
DEP_CPP_DRYTM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8ll.c
DEP_CPP_F16FL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmapf.h"\
	".\tmapfcn.h"\
	".\tmaps.h"\
	
NODEP_CPP_F16FL=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16fl8s.c
DEP_CPP_F16FL8=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\ilfunc.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\scale.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16lm.c
DEP_CPP_F16LM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\tftype.h"\
	
NODEP_CPP_F16LM=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16pm.c
DEP_CPP_F16PM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\f16s.c
DEP_CPP_F16S_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\sftype.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8l.c
DEP_CPP_FL8FL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmapf.h"\
	".\tmapfcn.h"\
	".\tmaps.h"\
	
NODEP_CPP_FL8FL=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8ll.c
DEP_CPP_FL8FL8=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmapf.h"\
	".\tmapfcn.h"\
	".\tmaps.h"\
	
NODEP_CPP_FL8FL8=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8fl8s.c
DEP_CPP_FL8FL8S=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\scshell.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8il.c
DEP_CPP_FL8IL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8l.c
DEP_CPP_FL8L_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\lftype.h"\
	".\plytyp.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lin.c
DEP_CPP_FL8LI=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\fl8lin.h"\
	".\mathmac.h"\
	".\plytyp.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lm.c
DEP_CPP_FL8LM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\tftype.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lo2wc.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8nnic.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2wic.c
DEP_CPP_FL8O2=\
	"..\fix\fix.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8pm.c
DEP_CPP_FL8PM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8s.c
DEP_CPP_FL8S_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\sftype.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8sply.c
DEP_CPP_FL8SP=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2circ.c
DEP_CPP_G2CIR=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\grcurv.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2d.c

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2el.c
DEP_CPP_G2EL_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\plytyp.h"\
	".\rastel.h"\
	".\raster.h"\
	
NODEP_CPP_G2EL_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2makewr.c
DEP_CPP_G2MAK=\
	"..\lg\codewrit.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	
NODEP_CPP_G2MAK=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2ov.c
DEP_CPP_G2OV_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\plytyp.h"\
	".\rastel.h"\
	".\raster.h"\
	
NODEP_CPP_G2OV_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2poly.c
DEP_CPP_G2POL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\grply.h"\
	".\icanvas.h"\
	".\pftype.h"\
	".\plytyp.h"\
	
NODEP_CPP_G2POL=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2ring.c
DEP_CPP_G2RIN=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\plytyp.h"\
	".\rastel.h"\
	".\raster.h"\
	
NODEP_CPP_G2RIN=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2rot.c
DEP_CPP_G2ROT=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\grtm.h"\
	".\plytyp.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g2tm.c
DEP_CPP_G2TM_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2clip.h"\
	".\g2spoint.h"\
	".\grtm.h"\
	".\plytyp.h"\
	
NODEP_CPP_G2TM_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gen16il.c
DEP_CPP_GEN16=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gen8il.c
DEP_CPP_GEN8I=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16l.c
DEP_CPP_GENF1=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genf16s.c
DEP_CPP_GENF16=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\ilfunc.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\scale.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8l.c
DEP_CPP_GENFL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genfl8s.c
DEP_CPP_GENFL8=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\scshell.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genil.c
DEP_CPP_GENIL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genlil.c
DEP_CPP_GENLI=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genline.c
DEP_CPP_GENLIN=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\lftype.h"\
	".\mathmac.h"\
	".\plytyp.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genlm.c
DEP_CPP_GENLM=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\tftype.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genply.c
DEP_CPP_GENPL=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrast.c
DEP_CPP_GENRA=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglog.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\mathmac.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrsds.c
DEP_CPP_GENRS=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\grscale.h"\
	".\icanvas.h"\
	".\sftype.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genrsdtm.c
DEP_CPP_GENRSD=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gens.c
DEP_CPP_GENS_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\sftype.h"\
	
NODEP_CPP_GENS_=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gensil.c
DEP_CPP_GENSI=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gensply.c
DEP_CPP_GENSP=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\golftmap.c
DEP_CPP_GOLFT=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grtm.c
DEP_CPP_GRTM_=\
	"..\..\h\grspoint.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\grtm.h"\
	".\plytyp.h"\
	
NODEP_CPP_GRTM_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grwater.c
DEP_CPP_GRWAT=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\grtm.h"\
	".\plytyp.h"\
	".\water.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\init.c
DEP_CPP_INIT_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2makewr.h"\
	".\setdrv.h"\
	
NODEP_CPP_INIT_=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lh816.c
DEP_CPP_LH816=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lht816.c
DEP_CPP_LHT81=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lmap.c
DEP_CPP_LMAP_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\mprintf\mprintf.h"\
	".\buffer.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\raster.h"\
	".\tmapd.h"\
	".\tmapf.h"\
	".\tmapfcn.h"\
	".\tmaps.h"\
	
NODEP_CPP_LMAP_=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo816.c
DEP_CPP_LO816=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo88.c
DEP_CPP_LO88_=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88.c
DEP_CPP_O88_C=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\permap.c
DEP_CPP_PERMA=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	
NODEP_CPP_PERMA=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\plyshell.c
DEP_CPP_PLYSH=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	
NODEP_CPP_PLYSH=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\point.c
DEP_CPP_POINT=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\point.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_duv.c
DEP_CPP_PT_DU=\
	"..\fix\fix.h"\
	"..\matrix\matrix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	"..\prof\prof.h"\
	"..\timer\timer.h"\
	".\profile.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_grad.c
DEP_CPP_PT_GR=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_main.c
DEP_CPP_PT_MA=\
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
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\pt.h"\
	".\pt_asm.h"\
	".\ptmap.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	
NODEP_CPP_PT_MA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pt_map.c
DEP_CPP_PT_MAP=\
	"..\..\h\grspoint.h"\
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
	"..\mprintf\mprintf.h"\
	"..\prof\prof.h"\
	"..\r3d\r3ds.h"\
	"..\timer\timer.h"\
	".\g2spoint.h"\
	".\profile.h"\
	".\ptmap.h"\
	".\ptmapper.h"\
	".\recip.h"\
	".\scancvt.h"\
	
NODEP_CPP_PT_MAP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\r88.c
DEP_CPP_R88_C=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rastel.c
DEP_CPP_RASTE=\
	"..\..\h\fixreal.h"\
	"..\dev2d\dev2d.h"\
	"..\fix\altfix.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\plytyp.h"\
	".\raster.h"\
	
NODEP_CPP_RASTE=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\raster.c
DEP_CPP_RASTER=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\tmpalloc.h"\
	"..\lgalloc\memall.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\buffer.h"\
	".\plytyp.h"\
	".\raster.h"\
	
NODEP_CPP_RASTER=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scshell.c
DEP_CPP_SCSHE=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	
NODEP_CPP_SCSHE=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\setdrv.c
DEP_CPP_SETDR=\
	".\g2d.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shadhack.c
DEP_CPP_SHADH=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shadtmap.c
DEP_CPP_SHADT=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\svgainit.c
DEP_CPP_SVGAI=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\t816oc.c
DEP_CPP_T816O=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\t88oc.c
DEP_CPP_T88OC=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\genrast.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tf.c
DEP_CPP_TF_C9c=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plyshell.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmapd.c
DEP_CPP_TMAPD=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tmsetup.c
DEP_CPP_TMSET=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2clip.h"\
	".\g2d.h"\
	".\g2spoint.h"\
	".\g2tm.h"\
	".\icanvas.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\plytyp.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trifan.c
DEP_CPP_TRIFA=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	".\plytyp.h"\
	
NODEP_CPP_TRIFA=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trigrad.c
DEP_CPP_TRIGR=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	".\tmapd.h"\
	".\tmaps.h"\
	".\trirast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trirast.c
DEP_CPP_TRIRA=\
	"..\dev2d\dev2d.h"\
	"..\fix\fix.h"\
	"..\matrix\matrixs.h"\
	"..\matrix\mxang.h"\
	".\g2spoint.h"\
	".\plyparam.h"\
	".\plyrast.h"\
	

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\blncon.h
# End Source File
# Begin Source File

SOURCE=.\blnfcn.h
# End Source File
# Begin Source File

SOURCE=.\buffer.h
# End Source File
# Begin Source File

SOURCE=.\f16tf.h
# End Source File
# Begin Source File

SOURCE=.\fl8lf.h
# End Source File
# Begin Source File

SOURCE=.\fl8lin.h
# End Source File
# Begin Source File

SOURCE=.\fl8sf.h
# End Source File
# Begin Source File

SOURCE=.\fl8tf.h
# End Source File
# Begin Source File

SOURCE=.\flat16.h
# End Source File
# Begin Source File

SOURCE=.\flat8.h
# End Source File
# Begin Source File

SOURCE=.\frame.h
# End Source File
# Begin Source File

SOURCE=.\g2.h
# End Source File
# Begin Source File

SOURCE=.\g2clip.h
# End Source File
# Begin Source File

SOURCE=.\g2d.h
# End Source File
# Begin Source File

SOURCE=.\g2makewr.h
# End Source File
# Begin Source File

SOURCE=.\g2pt.h
# End Source File
# Begin Source File

SOURCE=.\g2spoint.h
# End Source File
# Begin Source File

SOURCE=.\g2tm.h
# End Source File
# Begin Source File

SOURCE=.\general.h
# End Source File
# Begin Source File

SOURCE=.\genrast.h
# End Source File
# Begin Source File

SOURCE=.\gensf.h
# End Source File
# Begin Source File

SOURCE=.\gentf.h
# End Source File
# Begin Source File

SOURCE=.\grchkply.h
# End Source File
# Begin Source File

SOURCE=.\grcurv.h
# End Source File
# Begin Source File

SOURCE=.\grlin.h
# End Source File
# Begin Source File

SOURCE=.\grply.h
# End Source File
# Begin Source File

SOURCE=.\grscale.h
# End Source File
# Begin Source File

SOURCE=.\grtm.h
# End Source File
# Begin Source File

SOURCE=.\icanvas.h
# End Source File
# Begin Source File

SOURCE=.\ilfunc.h
# End Source File
# Begin Source File

SOURCE=.\init.h
# End Source File
# Begin Source File

SOURCE=.\lftype.h
# End Source File
# Begin Source File

SOURCE=.\mathmac.h
# End Source File
# Begin Source File

SOURCE=.\permap.h
# End Source File
# Begin Source File

SOURCE=.\pftype.h
# End Source File
# Begin Source File

SOURCE=.\plyparam.h
# End Source File
# Begin Source File

SOURCE=.\plyrast.h
# End Source File
# Begin Source File

SOURCE=.\plyshell.h
# End Source File
# Begin Source File

SOURCE=.\plytyp.h
# End Source File
# Begin Source File

SOURCE=.\point.h
# End Source File
# Begin Source File

SOURCE=.\poly.h
# End Source File
# Begin Source File

SOURCE=.\polyint.h
# End Source File
# Begin Source File

SOURCE=.\profile.h
# End Source File
# Begin Source File

SOURCE=.\pt.h
# End Source File
# Begin Source File

SOURCE=.\pt_asm.h
# End Source File
# Begin Source File

SOURCE=.\ptmap.h
# End Source File
# Begin Source File

SOURCE=.\ptmapper.h
# End Source File
# Begin Source File

SOURCE=.\rastel.h
# End Source File
# Begin Source File

SOURCE=.\raster.h
# End Source File
# Begin Source File

SOURCE=.\recip.h
# End Source File
# Begin Source File

SOURCE=.\scale.h
# End Source File
# Begin Source File

SOURCE=.\scancvt.h
# End Source File
# Begin Source File

SOURCE=.\scshell.h
# End Source File
# Begin Source File

SOURCE=.\setdrv.h
# End Source File
# Begin Source File

SOURCE=.\sftype.h
# End Source File
# Begin Source File

SOURCE=.\swarn.h
# End Source File
# Begin Source File

SOURCE=.\tftype.h
# End Source File
# Begin Source File

SOURCE=.\tmapd.h
# End Source File
# Begin Source File

SOURCE=.\tmapf.h
# End Source File
# Begin Source File

SOURCE=.\tmapfcn.h
# End Source File
# Begin Source File

SOURCE=.\tmaps.h
# End Source File
# Begin Source File

SOURCE=.\trirast.h
# End Source File
# Begin Source File

SOURCE=.\water.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\chkedgeb.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\chkedges.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\co88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8lo2wi.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8nni.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2ni.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fl8o2wi.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo816il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lo88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\n88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o2w88i.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88bil.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\o88il.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptfloat.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptlinear.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap_8.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmap_n.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptmapper.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ptpersp.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uvgrad.asm

!IF  "$(CFG)" == "g2 - Win32 Release"

!ELSEIF  "$(CFG)" == "g2 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# Begin Source File

SOURCE=.\g2spoint.inc
# End Source File
# Begin Source File

SOURCE=.\icanvas.inc
# End Source File
# Begin Source File

SOURCE=.\plyparam.inc
# End Source File
# Begin Source File

SOURCE=.\plyrast.inc
# End Source File
# Begin Source File

SOURCE=.\plytyp.inc
# End Source File
# Begin Source File

SOURCE=.\tmapd.inc
# End Source File
# Begin Source File

SOURCE=.\tmaps.inc
# End Source File
# End Group
# Begin Group "Asm Tbl Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\f16cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\f16llmf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16lmf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16sf.tbl
# End Source File
# Begin Source File

SOURCE=.\f16usf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8cnv.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8llmf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8lmf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8sf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8ulf.tbl
# End Source File
# Begin Source File

SOURCE=.\fl8usf.tbl
# End Source File
# Begin Source File

SOURCE=.\gencnv.tbl
# End Source File
# Begin Source File

SOURCE=.\genllmf.tbl
# End Source File
# Begin Source File

SOURCE=.\genlmf.tbl
# End Source File
# Begin Source File

SOURCE=.\gensf.tbl
# End Source File
# Begin Source File

SOURCE=.\genusf.tbl
# End Source File
# End Group
# End Target
# End Project
