# Microsoft Developer Studio Project File - Name="dstruct" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=dstruct - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dstruct.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dstruct.mak" CFG="dstruct - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dstruct - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "dstruct - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dstruct - Win32 Release"

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
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "." /I "..\..\h" /I "..\lg" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\dstruct" /I "..\config" /I "..\comtools" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I "..\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FR /YX"..\..\types.h" /FI "..\..\h\types.h" /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x816 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

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
# ADD CPP /nologo /Zp1 /ML /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\h" /I "..\actmovie" /I "..\appcore" /I "..\arq" /I "..\compapis" /I "..\dstruct" /I "..\config" /I "..\comtools" /I "..\cpptools" /I "..\darkloop" /I "..\dev2d" /I "..\dispdev" /I "..\dump" /I "..\fix" /I "..\font" /I "..\g2" /I "..\gadget" /I "..\gameshel" /I "..\gfile" /I "..\inputbnd" /I "..\lg" /I "..\lgalloc" /I "..\lgd3d" /I "..\matrix" /I "..\md" /I "..\mm" /I "..\mp" /I "..\mprintf" /I "..\namedres" /I "..\net" /I "..\prof" /I "..\r3d" /I "..\random" /I "..\recorder" /I "..\ref" /I "..\res" /I "..\rnd" /I "..\script" /I "..\sdesc" /I "..\skel" /I ".\sndsrc" /I "..\sndutil" /I "..\sound" /I "..\star" /I "..\tagfile" /I "..\templgen" /I "..\timer" /I "..\ui" /I "..\vec2" /I "..\..\winsrc\input" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_WINDOWS" /YX"..\..\types.h" /FD /FI /GZ "..\..\h\types.h" /c
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

# Name "dstruct - Win32 Release"
# Name "dstruct - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\array.c
DEP_CPP_ARRAY=\
	"..\..\h\lgerror.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\array.h"\
	
NODEP_CPP_ARRAY=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fname.c
DEP_CPP_FNAME=\
	".\fname.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hash.c
DEP_CPP_HASH_=\
	"..\..\h\_dstruct.h"\
	"..\..\h\lgerror.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	"..\mprintf\mprintf.h"\
	".\hash.h"\
	
NODEP_CPP_HASH_=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hheap.c
DEP_CPP_HHEAP=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\hheap.h"\
	".\llist.h"\
	
NODEP_CPP_HHEAP=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\huffde.c
DEP_CPP_HUFFD=\
	"..\lg\dbg.h"\
	".\huff.h"\
	
NODEP_CPP_HUFFD=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\huffen.c
DEP_CPP_HUFFE=\
	"..\lg\dbg.h"\
	".\huff.h"\
	
NODEP_CPP_HUFFE=\
	"..\lg\dbgmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\llist.c
DEP_CPP_LLIST=\
	"..\lgalloc\memall.h"\
	".\llist.h"\
	
NODEP_CPP_LLIST=\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lllist.c
DEP_CPP_LLLIS=\
	".\llist.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\message.c
DEP_CPP_MESSA=\
	"..\..\h\_dstruct.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\lgsprntf.h"\
	"..\lgalloc\memall.h"\
	".\message.h"\
	
NODEP_CPP_MESSA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pqueue.c
DEP_CPP_PQUEU=\
	"..\..\h\lgerror.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\pqueue.h"\
	
NODEP_CPP_PQUEU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rect.c
DEP_CPP_RECT_=\
	".\rect.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\strall.c
DEP_CPP_STRAL=\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\hheap.h"\
	".\llist.h"\
	".\strall.h"\
	
NODEP_CPP_STRAL=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\symdump.c
DEP_CPP_SYMDU=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lgalloc\memall.h"\
	".\hheap.h"\
	".\llist.h"\
	".\slist.h"\
	".\symtab.h"\
	
NODEP_CPP_SYMDU=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\symtab.c
DEP_CPP_SYMTA=\
	"..\fix\fix.h"\
	"..\lg\dbg.h"\
	"..\lg\lg.h"\
	"..\lg\lgalt.h"\
	"..\lg\lgassert.h"\
	"..\lg\lglocmsg.h"\
	"..\lg\lglog.h"\
	"..\lg\lgsprntf.h"\
	"..\lgalloc\memall.h"\
	".\hheap.h"\
	".\llist.h"\
	".\slist.h"\
	".\strall.h"\
	".\symtab.h"\
	
NODEP_CPP_SYMTA=\
	"..\lg\dbgmacro.h"\
	"..\lgalloc\memmacro.h"\
	

!IF  "$(CFG)" == "dstruct - Win32 Release"

!ELSEIF  "$(CFG)" == "dstruct - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\array.h
# End Source File
# Begin Source File

SOURCE=.\fname.h
# End Source File
# Begin Source File

SOURCE=.\hash.h
# End Source File
# Begin Source File

SOURCE=.\hashtest.h
# End Source File
# Begin Source File

SOURCE=.\hheap.h
# End Source File
# Begin Source File

SOURCE=.\huff.h
# End Source File
# Begin Source File

SOURCE=.\huffde.h
# End Source File
# Begin Source File

SOURCE=.\llist.h
# End Source File
# Begin Source File

SOURCE=.\message.h
# End Source File
# Begin Source File

SOURCE=.\pqueue.h
# End Source File
# Begin Source File

SOURCE=.\rect.h
# End Source File
# Begin Source File

SOURCE=.\slist.h
# End Source File
# Begin Source File

SOURCE=.\strall.h
# End Source File
# Begin Source File

SOURCE=.\symtab.h
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
