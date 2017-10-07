
#	----------------------------------
#	Makefile for FREEFALL data
#	----------------------------------

#	----------------------------------
#	Pathways
#	----------------------------------

ROOT ?= r:\prj\cam
%include $(ROOT)\src\scripts\app.mk

RESSUBDIR = motdata


LCODE ?= eng 


scrdir = .\$(LCODE);$(ROOTSRCDIR)\scripts\$(LCODE)\$(RESSUBDIR);.\;$(ROOTSRCDIR)\scripts\$(RESSUBDIR)
rawdir = ..\..\raw\$(LCODE)\$(RESSUBDIR);$(ROOTSRCDIR)\raw\$(LCODE)\$(RESSUBDIR);..\..\raw\$(RESSUBDIR);$(ROOTSRCDIR)\raw\$(RESSUBDIR)
intdir = ..\..\idata
resdir = ..\..\data
incdir = ..\code\inc
htargdir = ..\..\..\h
hinstdir = $(ROOT)\h

fontdir = ..\..\idata\\


installdir = $(ROOTSRCDIR)\data

VPATH.h   = $(ROOT)\h
VPATH.res = $(resdir)
VPATH.scr = $(scrdir)
VPATH.ims = $(scrdir)
VPATH.ans = $(scrdir)
VPATH.cfg = $(scrdir)
VPATH.txt = $(scrdir)

VPATH.asm = $(rawdir);$(intdir)

VPATH.anm = $(rawdir)
VPATH.fli = $(rawdir)
VPATH.flc = $(rawdir)
VPATH.cel = $(rawdir)
VPATH.pcx = $(rawdir);$(intdir)
VPATH.fon = $(rawdir);$(intdir)
VPATH.voc = $(rawdir)\voc
VPATH.3ds = $(rawdir)
VPATH.ipl = $(rawdir)
VPATH.fsc = $(rawdir)

VPATH.img = $(intdir)
VPATH.bin = $(intdir)
VPATH.pal = $(intdir)

VPATH.obj = $(intdir)

HDRPATH.c = . $(incdir)


#	----------------------------------
#		SOME MACROS
#	----------------------------------

CP = copy
DIFF = diff
RM = del
INUSE = inuse

ANMFLAGS = -P $(intdir)

IMGFLAGS = -AUXI -PATH $(intdir)

STD_SFX_ANIM_FLAGS = $(.SOURCE,F) -B -TRANSP -K -N -C $(ANMFLAGS)

#	----------------------------------
#	All resource files
#	----------------------------------

ALLRES = motdata.res

allres .PHONY: $(ALLRES)

#	----------------------------------
#	Install rule
#	----------------------------------

install .PHONY:
        !foreach TARGET $(ALLRES)
            !if (-e $(resdir)\$(TARGET) && -e $(installdir)\$(TARGET))
                $(INUSE) $(installdir)\$(TARGET) > temp.out
            !endif
            !if (-e $(resdir)\$(TARGET,R).h && -e $(hinstdir)\$(TARGET,R).h)
                $(INUSE) $(hinstdir)\$(TARGET,R).h > temp.out
            !endif
        !end
	!foreach TARGET $(ALLRES)
	    !if (-e $(resdir)\$(TARGET))
		$(CP) $(resdir)\$(TARGET) $(installdir) >temp.out
		@--$(DIFF) $(resdir)\$(TARGET,R).h $(installdir)\$(TARGET,R).h >temp.out
		!if ((! -z temp.out) || (! -e $(htargdir)\$(TARGET,R).h))
		    $(CP) $(htargdir)\$(TARGET,R).h $(installdir)\$(TARGET,R).h >temp.out
		    touch $(htargdir)\$(TARGET,R).h
		!endif
		$(RM) $(resdir)\$(TARGET)
		$(RM) $(resdir)\$(TARGET,R).h
	    !endif
	!end


clean .PHONY:
	!foreach TARGET $(ALLRES)
	    !if (-e $(resdir)\$(TARGET))
		$(RM) $(resdir)\$(TARGET)
		$(RM) $(htargdir)\$(TARGET,R).h
	    !endif
	!end
        rm -fr mktmp
        rm -fr mk??????
              

#	----------------------------------
#	Rules for building a resource file
#	----------------------------------

RESBUILD .PHONY:
	motproc $(MOTFILE).txt $(RESFILE) -b1500 -p$(DPATH)
        mv $(RESFILE).res $(resdir)
        mv $(RESFILE).h $(htargdir)

#	----------------------------------
#		THE RESOURCE FILES
#	----------------------------------

motdata.res: motdata.txt
        %do RESBUILD DPATH=r:\prj\cam\src\raw\motdata RESFILE=motdata MOTFILE=motdata



