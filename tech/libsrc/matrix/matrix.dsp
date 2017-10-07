# Microsoft Developer Studio Project File - Name="matrix" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=matrix - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "matrix.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "matrix.mak" CFG="matrix - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "matrix - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "matrix - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "matrix - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\matrix" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "SHIP" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\matrix" /I "..\config" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dstruct" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
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

# Name "matrix - Win32 Release"
# Name "matrix - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\dmat.c
DEP_CPP_DMAT_=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\dmat.h"\
	".\dmats.h"\
	
NODEP_CPP_DMAT_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matang.c
DEP_CPP_MATAN=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	".\mxsym.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matangd.c
DEP_CPP_MATANG=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	".\mxsymd.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matmat.c
DEP_CPP_MATMA=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matmatd.c
DEP_CPP_MATMAT=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matvec.c
DEP_CPP_MATVE=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\matvecd.c
DEP_CPP_MATVEC=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trans.c
DEP_CPP_TRANS=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\transd.c
DEP_CPP_TRANSD=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vec2.c
DEP_CPP_VEC2_=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vec2d.c
DEP_CPP_VEC2D=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vecang.c
DEP_CPP_VECAN=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\_test.h"\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	".\mxsym.h"\
	
NODEP_CPP_VECAN=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vecangd.c
DEP_CPP_VECANG=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\_test.h"\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	".\mxsymd.h"\
	
NODEP_CPP_VECANG=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vecvec.c
DEP_CPP_VECVE=\
	".\matrix.h"\
	".\matrixs.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vecvecd.c
DEP_CPP_VECVEC=\
	".\matrixd.h"\
	".\matrixds.h"\
	".\mxang.h"\
	

!IF  "$(CFG)" == "matrix - Win32 Release"

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_test.h
# End Source File
# Begin Source File

SOURCE=.\dmat.h
# End Source File
# Begin Source File

SOURCE=.\dmats.h
# End Source File
# Begin Source File

SOURCE=.\matrix.h
# End Source File
# Begin Source File

SOURCE=.\matrixd.h
# End Source File
# Begin Source File

SOURCE=.\matrixds.h
# End Source File
# Begin Source File

SOURCE=.\matrixs.h
# End Source File
# Begin Source File

SOURCE=.\mxang.h
# End Source File
# Begin Source File

SOURCE=.\mxangs.h
# End Source File
# Begin Source File

SOURCE=.\mxcvrt.h
# End Source File
# Begin Source File

SOURCE=.\mxdmats.h
# End Source File
# Begin Source File

SOURCE=.\mxmat.h
# End Source File
# Begin Source File

SOURCE=.\mxmats.h
# End Source File
# Begin Source File

SOURCE=.\mxsym.h
# End Source File
# Begin Source File

SOURCE=.\mxsymd.h
# End Source File
# End Group
# Begin Group "Asm Source Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\transasm.asm

!IF  "$(CFG)" == "matrix - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "matrix - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Asm Inc Files"

# PROP Default_Filter "inc"
# End Group
# End Target
# End Project
