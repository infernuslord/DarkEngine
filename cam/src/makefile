# $Source: r:/t2repos/thief2/src/makefile,v $
# $Revision: 1.630 $
# $Author: adurant $
# $Date: 2000/03/05 16:48:00 $
#

MAKETOP = $(CWD)

PROJECT = thief2

%include $(INIT)\env.rc
%include $(INIT)\init.rc

.path.y = $(.path.c)
.path.lex = $(.path.c)

EXETARGS ?= hybrid

SPEC_EXETARGS ?= dark generic shock deepc # misstrip schtool inctest missdiff

##################################################
# RPG ENGINE APPS

#

cam:
	%echo CAM is no longer a valid target.

#
# DARK-SPECIFIC OBJECTS
#
DARK_GAME_DIR = dark

DARK_GAME_AI_OBJS =     \
        darkai          \
        daielem         \
        daifrog         \
        daicam

DARK_GAME_OBJS =        \
        bowscrpt        \
        camovl          \
        drk_bind        \
        drkamap         \
        drkbook         \
        drkbreth        \
        drkchkcd        \
        drkcmbat        \
	drkcolor	\
        drkcret         \
        drkdebrf        \
	drkfixpr	\
        drkgame         \
        drkgoalr        \
        drkldout        \
        drklinks        \
        drkloop         \
        drkloot         \
        drkmenu         \
        drkmislp        \
        drkmiss         \
        drkmsg          \
        drkinit         \
        drkinv          \
        drkinvsc        \
        drkinvpr        \
        drkinvui        \
	drknetap	\
        drkoptmn        \
        drkplinv        \
        drkpwscr        \
        drkpwups        \
        drkreact        \
        drkrend         \
        drkreprt        \
        drkrloop        \
        drkrutil        \
        drksave         \
        drksavui        \
        drksloop        \
        drkscrpt        \
        drkscrs         \
        drksound        \
        drkstats        \
        drkuiscr        \
        drkvo           \
        drkwbdy         \
        drkwbow         \
        drkwbow_        \
        drkwswd         \
        drkwswd_        \
        eidosafp        \
        lootprop        \
        picklock        \
        pickscrs        \
        plyscrpt        \
        metagame        \
        statbar         \
        vismeter        \
        weapscpt        \
	meshprop	\
        $(DARK_GAME_AI_OBJS)

DARK_TOOL_OBJS = \
        drkdiff         \
        drkpanl         \
        drkuires        \
        filepanl        \
        gadslide


#
# AIR-SPECIFIC OBJECTS
#

#
# DEEPCOVER SPECIFIC OBJECTS
#
# DEEPC SOURCE FILE GROUP DESCRIPTIONS
# DEEPC_ACTREACT_DIR :ActReact changes & enhancements.
# DEEPC_AI_DIR       :AI changes & enhancements.
# DEEPC_EDITOR_DIR   :Editor Feature extensions.
# DEEPC_ENGFEAT_DIR  :Engine Feature extensions.
# DEEPC_GAME_DIR     :Deep Cover-specific code.
# DEEPC_INPUT_DIR    :Input handling and dispatching.
# DEEPC_MOTION_DIR   :Motion capture and locomotion.
# DEEPC_MP_DIR       :Multiplayer enhancements.
# DEEPC_OBJECT_DIR   :General object manipulation.
# DEEPC_PLAYER_DIR   :Player-specific code.
# DEEPC_RENDER_DIR   :Rendering changes & enhancements.
# DEEPC_SCRIPT_DIR   :Scripting language changes & enhancements.
# DEEPC_SOUND_DIR    :Sound enhancements.
# DEEPC_UI_DIR       :UI of fun and goodness.
# DEEPC_WEAPON_DIR   :Weapon changes & enhancements.

DEEPC_ROOT_DIR     = deepc
DEEPC_ACTREACT_DIR = $(DEEPC_ROOT_DIR)\actreact
DEEPC_AI_DIR       = $(DEEPC_ROOT_DIR)\ai
DEEPC_EDITOR_DIR   = $(DEEPC_ROOT_DIR)\editor
DEEPC_ENGFEAT_DIR  = $(DEEPC_ROOT_DIR)\engfeat
DEEPC_GAME_DIR     = $(DEEPC_ROOT_DIR)\game
DEEPC_INPUT_DIR    = $(DEEPC_ROOT_DIR)\input
DEEPC_MOTION_DIR   = $(DEEPC_ROOT_DIR)\motion
DEEPC_MP_DIR       = $(DEEPC_ROOT_DIR)\mp
DEEPC_OBJECT_DIR   = $(DEEPC_ROOT_DIR)\object
DEEPC_PLAYER_DIR   = $(DEEPC_ROOT_DIR)\player
DEEPC_RENDER_DIR   = $(DEEPC_ROOT_DIR)\render
DEEPC_SCRIPT_DIR   = $(DEEPC_ROOT_DIR)\scripts
DEEPC_SOUND_DIR    = $(DEEPC_ROOT_DIR)\sound
DEEPC_UI_DIR       = $(DEEPC_ROOT_DIR)\ui
DEEPC_WEAPON_DIR   = $(DEEPC_ROOT_DIR)\weapon
# All the groups packed into one nice package.
DEEPC_FILE_GROUPS_DIR = $(DEEPC_ACTREACT_DIR) $(DEEPC_AI_DIR) $(DEEPC_EDITOR_DIR) $(DEEPC_ENGFEAT_DIR) $(DEEPC_GAME_DIR) $(DEEPC_INPUT_DIR) $(DEEPC_MOTION_DIR) $(DEEPC_MP_DIR) $(DEEPC_OBJECT_DIR) $(DEEPC_PLAYER_DIR) $(DEEPC_RENDER_DIR) $(DEEPC_SCRIPT_DIR) $(DEEPC_SOUND_DIR) $(DEEPC_UI_DIR) $(DEEPC_WEAPON_DIR)

DEEPC_AI_OBJS = \
    dpcai \
    dpcaibit \
    dpcaiabs \
    dpcaicbr \
    dpcaicbs \
    dpcaicha \
    dpcaicmd \
    dpcaicrb \
    dpcaidmr \
#    dpcaidth \
    dpcaidga \
    dpcaidgb \
    dpcaimbs \
    dpcaimuc \
    dpcaipbs \
    dpcaipr  \
    dpcaipro \
    dpcaipth \
    dpcairbs \
    dpcaircp \
    dpcaireb \
    dpcairnb \
    dpcaisbs \
#    dpcaitbs \
    dpcaiutl \
    dpcaiwnd \
    dpcstnrc

DEEPC_ACTREACT_OBJS = \
    dpcreact               \
    dpcprop                \
    dpcdrprp

DEEPC_EDITOR_OBJS = \
    dpcedit

DEEPC_ENGFEAT_OBJS = \
    dpcfrob          \
    dpcfsys

DEEPC_GAME_OBJS = \
    camovl       \
    drkbreth     \
    dpcalarm     \
    dpcblood     \
#   dpccheck     \
    dpcchkcd     \
    dpccross     \
    dpcdmprp     \
    dpcelev      \
    dpcemail     \
    dpcgame      \
    dpcgoalr     \
    dpcguids     \
    dpchazrd     \
    dpchcomp     \
    dpchplug     \
    dpchrm       \
    dpcinit      \
    dpckeypd     \
    dpcloop      \
    dpcloot      \
    dpcmain      \
    dpcmiss      \
    dpcmlook     \
    dpcmap       \
    dpcpatch     \
    dpcpick      \
    dpcplpup     \
    dpcreprt     \
    dpcscomp     \
    dpcsecur     \
    dpcsloop     \
    dpctluct     \
    dpcver       \
    dpcwsett

DEEPC_INPUT_OBJS = \
    dpcctrl       \
    dpckey        \
    dpc_bind

DEEPC_MOTION_OBJS = \
    dpccret         \
#   dpccrara        \
    dpccrarm        \
#   dpccrbar        \
#   dpccrdrd        \
    dpccrhum        \
#   dpccrmky        \
#   dpccrovr        \
    dpccrdoo        \
    dpccrdog        \
    dpccrdhu

DEEPC_MP_OBJS = \
    dpcnet

DEEPC_OBJECT_OBJS = \
    dpcarmpr        \
    dpcdmg          \
    dpclinks

DEEPC_PLAYER_OBJS = \
    dpcinv          \
    dpcinvpr        \
    dpclooko        \
    dpcmel_         \
    dpcmelab        \
    dpcmelee        \
    dpcparam        \
    dpcplayr        \
    dpcpldmg

DEEPC_RENDER_OBJS = \
    dpcanmsp        \
    dpccam          \
    dpccs           \
    dpccmobj        \
    dpccobpr        \
    dpcrend         \
    dpcrloop	    \
    dpcrndov        \
    dpcutils        \
#    dpcvhot

DEEPC_SCRIPT_OBJS = \
    dpcaisc         \
    dpchome         \
    dpcscrs         \
    dpcscrpt        \
    dpcwepsc

DEEPC_SOUND_OBJS = \
    dpcsndpr       \
    dpcsound

DEEPC_UI_OBJS = \
    vismeter    \
    dpcbooko    \
    dpcchat     \
    dpccont     \
    dpcdlg      \
    dpchud      \
    dpciface    \
    dpciftul    \
    dpclbox     \
    dpclding    \
    dpcmenu     \
    dpcmeter    \
    dpcmulti    \
    dpcnetui    \
    dpcoptmn    \
    dpcovrly    \
    dpcpda      \
    dpcsavui    \
    dpcsvbnd    \
    dpcuitul    \
    dpcyorn

DEEPC_WEAPON_OBJS = \
    dpcammov       \
    dpcganpr       \
    dpcgun         \
#    dpcgunpr       \
#    dpcflash       \
    dpcmelpr       \
    dpcplgun       \
#    dpcprjpr       \
#    dpcproj

DEEPCOBJS = \
    $(DEEPC_AI_OBJS)           \
    $(DEEPC_ACTREACT_OBJS)     \
    $(DEEPC_EDITOR_OBJS)            \
    $(DEEPC_ENGFEAT_OBJS)           \
    $(DEEPC_GAME_OBJS)              \
    $(DEEPC_INPUT_OBJS)             \
    $(DEEPC_MOTION_OBJS)            \
    $(DEEPC_MP_OBJS)                \
    $(DEEPC_OBJECT_OBJS)            \
    $(DEEPC_PLAYER_OBJS)            \
    $(DEEPC_RENDER_OBJS)            \
    $(DEEPC_SCRIPT_OBJS)            \
    $(DEEPC_SOUND_OBJS)             \
    $(DEEPC_UI_OBJS)                \
    $(DEEPC_WEAPON_OBJS)

#
# SHOCK-SPECIFIC OBJECTS
#
SHOCK_GAME_DIR = shock

SHOCK_GAME_AI_OBJS =    \
        shkai           \
	shkaiabs	\
        shkaibit        \
        shkaicha        \
	shkaicbr	\
        shkaicbs        \
        shkaicmd        \
	shkaicrb	\
	shkaidmr	\
	shkaiexp	\
        shkaigra        \
        shkaigrb        \
	shkaimbs	\
	shkaimc		\
	shkaimuc	\
        shkaipbs        \
	shkaipth	\
        shkaipr         \
        shkaiprb        \
        shkaipro        \
	shkairbs	\
	shkaircp	\
	shkairnb	\
        shkaireb        \
	shkaisbs	\
        shkaisc         \
	shkaishb	\
	shkaisho	\
        shkaiswa        \
        shkaiswm        \
	shkaiutl	\
        shkaiwnd

SHOCKOBJS =             \
        drkbreth        \
        shk_bind        \
        shkabyss        \
        shkalarm        \
        shkammov        \
        shkanmsp        \
        shkarmpr        \
        shkbacon        \
	shkblood	\
        shkbooko        \
        shkcam          \
        shkcharg        \
        shkchat         \
	shkchkcd        \
        shkcmobj        \
        shkcobpr        \
        shkcont         \
        shkcrara        \
	shkcrarm	\
        shkcrbar        \
	shkcrhum	\
        shkcrdrd        \
        shkcrmky        \
        shkcrrum        \
        shkcrovr        \
        shkcret         \
        shkcross        \
	shkcrsho	\
        shkcs           \
        shkctrl         \
        shkdebrf        \
        shkdkyhg        \
        shkdlg          \
        shkdmprp        \
        shkdmg          \
        shkdrprp        \
        shkedit         \
        shkelev         \
        shkemail        \
        shkexp		\
        shkfrob         \
        shkfsys         \
        shkgame         \
        shkganpr        \
        shkgolf         \
        shkguids        \
        shkgun          \
        shkhacks	\
        shkhazrd        \
        shkhcomp        \
	shkhogga        \
	shkhome		\
        shkhplug        \
        shkhrm          \
        shkhud          \
        shkiface 	\
        shkiftul        \
        shkinit		\
        shkinv		\
        shkinvpr 	\
        shkkey          \
        shkkeypd 	\
        shklbox 	\
        shklding        \
        shklinks        \
        shklooko        \
        shkloop		\
        shkloot         \
        shkmain         \
        shkmap          \
        shkmel_         \
        shkmelab        \
        shkmelee        \
        shkmelpr        \
        shkmenu         \
        shkmeter        \
        shkminig        \
        shkmlook        \
        shkmmax         \
        shkmulti        \
        shkmusic	\
        shknet		\
	shknetap	\
        shknetui        \
        shkobjsc        \
        shkoptmn        \
        shkovrly	\
        shkovrld        \
        shkowrld        \
        shkparam        \
        shkpatch        \
        shkpda          \
        shkpick         \
        shkping         \
        shkplayr	\
        shkpldmg	\
        shkplgun	\
        shkplpup 	\
        shkprop		\
        shkpsi		\
        shkpsiif        \
        shkpsipr        \
        shkpsipw        \
        shkpsisc        \
	shkracer        \
        shktetr         \
        shkradar        \
        shkrdrov        \
        shkreact        \
        shkrend		\
        shkrep          \
        shkreprt        \
        shkrloop	\
        shkrlup2        \
        shkrndov        \
        shkrndst	\
        shkrsrch        \
        shksavui        \
        shkscomp        \
        shkscrpt        \
        shksecur        \
        shkskill        \
        shksloop        \
        shksound        \
        shksndpr        \
        shkstats        \
        shkstnrc        \
        shkswine	\
        shksvbnd        \
        shktcomp        \
        shktechs        \
        shktluct        \
        shktrait        \
        shktrpsi        \
        shktrain        \
        shkttt          \
        shkutils        \
        shkuitul        \
        shkver          \
        shkweb          \
        shkwepsc        \
        shkwsett        \
        shkyorn         \
        $(SHOCK_GAME_AI_OBJS)

#
# General game systemobjs
#

ACT_REACT_OBJS =        \
        arloop          \
        contag8r        \
        esndreac        \
        frezreac        \
        mediag8r        \
        periog8r        \
        pg8rnull        \
        propag8n        \
        propag8r        \
        propreac        \
        radiag8r        \
        reaction        \
        ssrclife        \
        stimbase        \
        stimguid        \
        stimsens        \
        stimsrc         \
        stimul8r        \
        stimuli

PROPERTY_OBJS =         \
        prcniter        \
        propdb          \
        property        \
        propface        \
        propguid        \
        propstor        \
        propman         \
        propmix         \
        propnull        \
        propobsv        \
        propsave        \
        strprop

LINKMAN_OBJS =          \
        bintrait        \
        dataops         \
        link            \
        linkarry        \
        linkboth        \
        lnkbyobj        \
        linkdb          \
        linkdata        \
        linkguid        \
        linkman         \
        linkset         \
        linkstor        \
        linkqdb         \
        linkprop        \
        osetlnkq        \
        proplink        \
        lnkquery        \
        querynul        \
        relation        \
        relinver        \
        relnull

TRAITMAN_OBJS  =        \
        donorq          \
        nameprop        \
        objquery        \
        traisrch        \
        trait           \
        traitq          \
        traitiid        \
        traitlnk        \
        traitman        \
        traitnul        \
        traitprp        \
        traitqdb        \
        trcache         \
        trcachui

#
# AI
#

AI_DIR = ai

AI_ACTION_OBJS = \
        aiactfol        \
        aiactfrb        \
        aiactinv        \
        aiactjr         \
        aiactjs         \
        aiactjsc        \
        aiactlch        \
        aiactloc        \
        aiactmot        \
        aiactmov        \
        aiactmrk        \
        aiactprx        \
        aiactps         \
        aiactori        \
        aiactrng        \
        aiactseq        \
        aiactsnd        \
        aiactwnd        \
        aiactwt         \
        aiactnet	\
	aigunact

AI_NONCOMBAT_OBJS = \
        aialtrsp        \
        aibdyrsp        \
        aicnvabl        \
        aicbtrsp        \
        aideath         \
        aidefend        \
        aiflee          \
        aifollow        \
        aifreeze        \
        aiidle          \
        aiinvest        \
        ailisten        \
        aincbdmg        \
        ainoncbt        \
        aipatrol        \
	aisusrsp	\
        aithreat        \
        aiwatch

AI_COMBAT_OBJS = \
        aicbhtoh        \
	aicbrbkp	\
	aicbrclo	\
	aicbrfle	\
	aicbridl	\
	aicbrloc	\
	aicbrmod	\
	aicbrmpr	\
	aicbrnew	\
        aicbrngd        \
        aicbrsht        \
	aicbrstl	\
	aicbrstr	\
	aicbrwnd	\
        aicdummy        \
        aicombat        \
        aidev           \
        aimultcb        \
        aisubcb         \
        aiturret        \
        aicamera        \
	aiturbs		\
	aiqdeath

AI_PATHFIND_OBJS = \
        aipath          \
        aipathdb        \
        aipthcst        \
        aipthdbg        \
        aipthedg        \
        aipthfnd        \
        aipthloc        \
        aipthobb        \
        aipthzon        \
        rpathfnd        \
        rpaths

AI_PROP_OBJS = \
        aiprabil        \
        aiprconv        \
        aiprcore        \
        aiprdev         \
        aiprattr        \
        aiprops         \
        aiprrngd        \
        aiprutil

AI_SENSE_OBJS = \
        aiaware         \
        aibassns        \
        aisgtcst        \
        aisnsdev

AI_DEBUG_OBJS = \
        aidbdraw        \
        aidbgcmp        \
        aidebug         \
        aireport

AI_SCRIPT_OBJS = \
        aiscrabl        \
        aiscrpt

AI_OBJS = \
        aitest \
        aimplyr \
        aimttest \
        aie3bhv \
        ai              \
        aiavoid         \
        aibasabl        \
        aibasact        \
        aibasatm        \
        aibasbhv        \
        aibasctm        \
        aibasmrg        \
        aicmds          \
        aicnvman        \
        aicnvrse        \
        aicpinit        \
        aicretsz        \
        aidetect        \
        aidoormr        \
        aigoal          \
        aiground        \
        aiinform        \
        aiman           \
        aimove          \
        aimovmot        \
        aimovsug        \
        ainet           \
        ainetman        \
        aiphycst        \
        aiproxy         \
        aisound         \
        aisubabl        \
	aisuslnk	\
        aistdmrg        \
        aistun          \
        aitagtyp        \
        aiteams         \
        aitrig          \
        aiutils         \
        aiwr            \
        $(AI_COMBAT_OBJS) \
        $(AI_ACTION_OBJS) \
        $(AI_NONCOMBAT_OBJS) \
        $(AI_PATHFIND_OBJS) \
        $(AI_PROP_OBJS) \
        $(AI_SENSE_OBJS) \
        $(AI_DEBUG_OBJS) \
        $(AI_SCRIPT_OBJS)

#
# Physics
#

PHYSICS_DIR = physics
PHYSICS_OBJS =          \
        collide         \
        collprop        \
        objmedia        \
        phclimb         \
        phclsn          \
        phcontct        \
        phcore          \
        phctrl          \
        phdyn           \
        phflist         \
	phlisten	\
        phmedtr         \
        phmod           \
        phmodbsp        \
        phmodobb        \
        phmods          \
        phmodsph        \
        phmodutl        \
        phmsg           \
	phnet		\
        phoprop         \
        phprop          \
        phprops         \
        phmtprop        \
        phmterr         \
        phmtscpt        \
        phppscpt        \
        phref           \
        phreport        \
        phsubmod        \
        phscrpt         \
        phterr          \
        phtxtprp        \
        phutils         \
        physapi         \
        physcast        \
        physloop        \
        phystest        \
        phmotion        \
        phmodata        \
        phmoapi		\
	gunproj		\
	gunvhot		\
	spherchk

ROOM_OBJS =             \
        room            \
        roomcore        \
        roomeax         \
        roomloop        \
        roompa          \
        roomprop        \
        rooms           \
        roomutil        \
        rooscrpt        \
        rportal

SOUNDPROP_OBJS =        \
        psndapi         \
        psnd            \
        psndinst        \
        sndframe


SCRIPT_SERVICE_OBJS =   \
        antxscpt        \
        arscript        \
        bodscrpt        \
	camscrpt	\
        datascrs        \
        dmgscrpt        \
        drscrpt         \
        engscrpt        \
        linkscpt        \
        litscrpt        \
	netscrpt	\
        objscrpt        \
        propscpt        \
        pupscrpt        \
        quesscpt        \
        sdesparm        \
        sndscrpt        \
        mtscrpt

MOTION_DIR = motion
MOTION_OBJS =           \
        cerebllm        \
        mcoord          \
        mvrcmbat        \
        mvrflags        \
        mvrflbow        \
        mvrgact         \
        mvrgloco        \
        mvrplyr         \
        mvrsngle        \
        mvrutils        \
        motdb           \
        motdesc         \
        motdmnge        \
        motmngr         \
        motschem        \
        motset          \
        motprop         \
        mschutil        \
        mskilset

CREATURE_OBJS =         \
        crattach        \
        crwpnlst        \
        crwpnapi        \
        crwpnlup        \
        creature        \
        cretprop        \
        crexp           \
        crjoint

DARK_CREATURE_OBJS =    \
        ccrappa         \
        ccrbug          \
        ccrcray         \
        ccrhuman        \
        crappa          \
        crbowarm        \
        crbugbst        \
        crburrik        \
        crconsta        \
        crcraymn        \
        crcutty         \
        crfrog          \
        crhumand        \
        crplyarm        \
	crrobot		\
        crrope          \
	crsmrbt		\
        crspider        \
        crspidsm        \
        crspirob        \
        crsweel         \
        crzombie

ENGINE_FEATURE_OBJS  =  \
        antxloop        \
        atkscrpt        \
        cdplayer        \
        contain         \
	contprop	\
        contscrs        \
        ctrast		\
        doorphys        \
        doorprop        \
        doorrep         \
        dumbprox        \
        dyntex          \
        engfeat         \
        frobprop        \
        frobctrl        \
        invlimb         \
        inv_rend        \
        invrndpr        \
        keyscpt         \
        keysys          \
	litnet		\
        lockprop        \
        lockscpt        \
        panltool        \
        pick            \
        preldprp        \
        prjctile        \
        quesreac        \
	scrptnet	\
	sndnet		\
        tweqctrl        \
        tweqprop        \
        tweqrep         \
        twqscrpt        \
        vocore          \
        weapcb          \
        weaphalo        \
        weaphit         \
        weapon          \
        weapprop        \
        weapreac        \
	gunflash	\
	gunprop		\
	projprop	\
	projlink
#
# portal files
#

world_rep_objs = wrfunc wrcast bspsphr
world_rep_dbg_objs = wrdbg
portal_support_objs = animlit # oracle
portal_render_objs = portal portdraw ptdrawhw portlit portclip portbg portpick \
                        portwatr porthw portsky
portal_surface_objs = portsurf surfaces ptsurf ptsurf16
portal_mapper_objs = pt_mem pt_clut

PORTAL_OPT_OBJS =       \
        $(world_rep_objs)  \
        $(world_rep_dbg_objs) \
        $(portal_support_objs) \
        $(portal_surface_objs) \
        $(portal_mapper_objs) \
        $(portal_render_objs)

PORTAL_NORM_OBJS =

PORTAL_OBJS =           \
        $(PORTAL_NORM_OBJS) \
        $(PORTAL_OPT_OBJS)

PORTAL_DIR  = portal

#
# Editor-only stuff
#

EDITOR_DIR = editor
CSG_DIR = csg

%if '$(MASTER)'=='editor' || '$(MASTER)'=='editprof' || '$(MASTER)'=='editdbg' || '$(MASTER)'=='shocked' || '$(MASTER)'=='deepc'

EDITRC =  # dialogs  # we don't need this anymore

CSGOBJS = \
        bspdata         \
        csg             \
        csgalloc        \
        csgbbox         \
        csgbuild        \
        csgcheck        \
        csgclip         \
        csgcube         \
        csgemit         \
        csgfind         \
        csgmedia        \
        csgmerge        \
        csgutil         \
        hep
#       csgdecal

EDIT_PROPERTY_OBJS =    \
        brprop          \
        linkedit        \
        objed           \
        otreeed         \
        proped          \
        proptest

MOTION_EDITOR_OBJS =    \
        lgslider        \
        medflbox        \
        mediface        \
        medmenu         \
        medplay         \
        mschlex         \
        mschyacc        \
        motedit

EDITOBJS = \
        alignPnP        \
        arcmd           \
        areaPnP         \
        autovbr         \
        bldstair        \
        brinfo          \
        brlist          \
        brloop          \
        brobjpro        \
        brquery         \
        brrend          \
        brundo          \
        brushgfh        \
        cmdbutts        \
        convpred        \
        cvtbrush        \
        cyclegad        \
        doorblok        \
        dragbox         \
        editapp         \
        editbr          \
        editgeom        \
        editmode        \
        editobj         \
        editsave        \
        edmedmo         \
        famedit         \
        flowpnp         \
        fvaredit        \
        ged_csg         \
        ged_line        \
        ged_rend        \
        ged_rmap        \
        ged_room        \
        ged_undo        \
        gedit           \
        gedmedmo        \
        gfhfrobs        \
        gridPnP         \
        gridsnap        \
        hilight         \
        lightPnP        \
        linkdraw        \
        lnktrait        \
        miscrprt        \
        modalui         \
        namenum         \
        objedit         \
        objhistp        \
        objPnP          \
        phproped        \
        pnpslide        \
        PnPtools        \
        primal          \
        primshap        \
        preload         \
        psdialog        \
        quesedit        \
        rendtest        \
        report          \
        reprthlp        \
        roomPnP         \
        roomtowr        \
        saveload        \
        schfile         \
	schlex		\
	schyacc		\
        scrnedit        \
        scrpted         \
        simpwrap        \
        songlex         \
        songyacc        \
	songedtr	\
        stupidui        \
        strprped        \
        swappnp         \
        swapregs        \
        swaptool        \
        txtPnP          \
        txtrpal         \
        uiedit          \
        undoredo        \
        userpnp         \
        vbrush          \
        vbr_math        \
        viewmgr         \
        vmwincfg        \
        vslider         \
        vumanui         \
        $(MOTION_EDITOR_OBJS) \
        $(EDIT_PROPERTY_OBJS)


INITOBJS = initedit

%else

INITOBJS = initgame gameiid

%endif

#
# Playtest objs
#

%if %defined(PLAYTEST)
PLAYTEST_OBJS = playtest
%else
PLAYTEST_OBJS =
%endif

GHOST_OBJS = \
        ghost           \
        ghosthst        \
        ghostlst        \
	ghostlup        \
        ghostmsg        \
        ghostphy        \
        ghostrcv        \
        ghostshk        \
        ghostsnd        \
        ghostwep

NETOBJS = \
	avatar		\
	ctagnet		\
        $(GHOST_OBJS)   \
	netman          \
	netmsg		\
        netprops	\
	netsim          \
	netsynch	\
	netvoice	\
	objnet

BASEOBJS = \
        rand            \
        2dapp           \
        animlgt         \
        anim_txt        \
        ambient         \
        ambprop         \
        appname         \
        appsfx          \
        auxsnd          \
        backup          \
        basemode        \
        biploop         \
        buftagf         \
        bugterm         \
        buttpanl        \
        camera          \
        camguids        \
        campaign        \
        chainevt        \
        cmdterm         \
        cfgtool         \
        command         \
        corona          \
        ctag            \
        ctagset         \
        ctimer          \
        dappsink        \
        dbfile          \
        diskfree        \
        dispatch        \
        dmgmodel        \
        dmgprop         \
        dmgreact        \
        dxload          \
	dxwrndlg        \
        eosapp          \
        edittool        \
        elitprop        \
        esnd            \
        esndprop        \
        face            \
        family          \
        fas             \
        fasprop         \
        fcytagdb        \
        filetool        \
        filemenu        \
        filevar         \
        flinder         \
        flowarch        \
        fltang          \
        fxdisk          \
        fxspan          \
        gameapp         \
        gameinfo        \
        gamemode        \
        gamescrn        \
        gamestr         \
        gametool        \
        gen_bind        \
	gfxprop		\
        goof            \
        h2ocolor        \
        hchkthrd        \
        hdskprop        \
        headmove        \
        hpprop          \
        trapprop        \
        hud             \
        inc             \
        inclex          \
        inctab          \
        init            \
        imgsrc          \
        isdesced        \
        joypoll         \
        killme          \
        litprop         \
        lresdisk        \
        loopapp         \
        main            \
        medmotn         \
        meshray         \
        meshtex         \
        metasnd         \
        mipmap          \
        missrend        \
        mlight          \
        mnamprop        \
        mnumprop        \
        menus           \
        meshatt         \
        movie           \
        mputil		\
        namemap         \
        objcast         \
        objlight        \
        objloop         \
        objmodel        \
        objpos          \
        objremap        \
        objlpars        \
	objproxy	\
        objshape        \
        objsys          \
        objtool         \
        objtxtrp        \
        ownprop         \
        palette         \
        palmgr          \
        panlmode        \
        particle        \
        partprop        \
        pgroup          \
        pgrpprop        \
        pgrpscpt        \
        pickgame        \
        playtest        \
        plyablty        \
        plycbllm        \
        plyrhdlr        \
        plyrloop        \
        plyrmode        \
        plyrmov         \
        plyrvmot        \
        portapp         \
        porthlpr        \
        prompts         \
        puppet          \
        pupprop         \
        quest           \
        quesloop        \
        questprp        \
        r3app           \
        render          \
        rendloop        \
        skyrend         \
        skyobj          \
        starobj         \
        celstobj        \
        distobj         \
        cloudobj        \
        rendobj         \
        rendphys        \
        rendprop        \
        rendptst        \
        reputil         \
        resapp          \
	resdata		\
        resloop         \
        rndflash        \
        scalprop        \
	schdb		\
	schema		\
	schloop		\
	schmsg		\
	schprop		\
	schsamps	\
        scrnloop        \
        scrndump        \
        scrnman         \
        scrnmode        \
        scrnovls        \
        scrptcmd        \
        scrptprp        \
        scrptst         \
        simloop         \
        simman          \
        simtime         \
        simpdmg         \
        simstate        \
        slitprop        \
	sndgen		\
        sndloop         \
	sndprop		\
        songi           \
        songid          \
        songplri        \
        songutil        \
	songfile	\
	songmiss	\
        spchdom         \
	spchprop	\
        spchvoc         \
	speech		\
        sphrcst         \
        sprkprop        \
	starhack        \
        status          \
        subscrip        \
	susprop		\
        tagdbdat        \
        tagdbin         \
        tagdbkey        \
        tagdbkst        \
        tagdbout        \
        tagpatch        \
        tagremap        \
        tanimprp        \
        testloop        \
        testmode        \
        texmem          \
	texprop         \
        texsave         \
        textarch        \
	uiamov		\
	uianim		\
        uiapp           \
        uigame          \
        uiloop          \
        version         \
        weather         \
        winui           \
        wrbsp           \
        wrcell          \
        wrloop          \
        $(AI_OBJS)      \
        $(ENGINE_FEATURE_OBJS) \
        $(SCRIPT_SERVICE_OBJS) \
        $(ROOM_OBJS)    \
        $(SOUNDPROP_OBJS)\
        $(ACT_REACT_OBJS)\
        $(LINKMAN_OBJS) \
        $(PROPERTY_OBJS)\
        $(TRAITMAN_OBJS)\
        $(PHYSICS_OBJS) \
        $(MOTION_OBJS)  \
        $(CREATURE_OBJS) \
        $(DARK_CREATURE_OBJS) \
        $(DARK_TOOL_OBJS) \
        $(INITOBJS)     \
        $(NETOBJS)      \
        $(PLAYTEST_OBJS)\
        $(PORTAL_OBJS)  \
        $(CSGOBJS)      \
        $(EDITOBJS)



# this is really msvc only--- perhaps a thing for ms would be good?
mipmap.c_CFLAGS=/oaetx

# turn off warnings for lex/yacc generated code which doesn't like MSVC
schlex.c_CFLAGS=/W0 /DYY_STATIC
schyacc.c_CFLAGS=/W0
mschlex.c_CFLAGS=/W0 /DYY_STATIC
mschyacc.c_CFLAGS=/W0
inc.c_CFLAGS=/W0
inclex.c_CFLAGS=/W0 /DYY_STATIC
songyacc.c_CFLAGS=/W0
songlex.c_CFLAGS=/W0 /DYY_STATIC

CORELIBS = $(TECH_LIBS) r3d star skel mp md dump vec2 prof gfile \
           darkloop lgd3d mm script sndsrc ref sdesc arq inputbnd \
           input namedres net random tagfile

COREWINLIBS = dplayx
COREDOSLIBS = entrycon
CORECOMPLIBS = comdlg32 comctl32

# this turns of inc linker, so dont use unless you need it
#MICROSOFT_LDFLAGS=/PROFILE

ENGINE_SUBPROJECTS = $(PORTAL_DIR) $(AI_DIR) $(PHYSICS_DIR) $(MOTION_DIR) $(EDITOR_DIR) $(CSG_DIR) framewrk sim ui ENGFEAT SOUND render SCRIPT object actreact

%if '$(FLAV)'=='dbg'
%if '$(PORTAL_DBG)'==''
ENGINE_OPT_OBJS    = $(PORTAL_OPT_OBJS)
%else
%echo Building dbg flavor portal objs.
%endif
%endif

#
# DARK EXECUTABLE
#
dark_sub_projects = $(ENGINE_SUBPROJECTS) $(DARK_GAME_DIR)
dark_opt_objs = $(ENGINE_OPT_OBJS)
dark_OBJS = $(BASEOBJS) $(DARK_GAME_OBJS) darktabl
dark_LIBS = $(CORELIBS)
%if '$(ADDRES)'
dark_RC = dark
%endif
dark_compiler_libs = $(CORECOMPLIBS)
dark_win32_LIBS = $(COREWINLIBS)
dark_dos4g_LIBS = $(COREDOSLIBS)
dark_STACK = 8192
dev_dark = dbgdark
editor_dark = darked
editprof_dark = dromed
editdbg_dark  = dbgdrom
playtest_dark = thief
ship_dark = thief2
shipprot_dark = thief

#
# DEEPC EXECUTABLE
#
deepc_sub_projects = $(ENGINE_SUBPROJECTS) $(DEEPC_ROOT_DIR) $(DEEPC_FILE_GROUPS_DIR)
deepc_opt_objs = $(ENGINE_OPT_OBJS)
deepc_OBJS = $(BASEOBJS) $(DEEPCOBJS) dpctable
deepc_LIBS = $(CORELIBS)
%if '$(ADDRES)'
deepc_RC = deepc
%endif
deepc_compiler_libs = $(CORECOMPLIBS)
deepc_win32_LIBS = $(COREWINLIBS)
deepc_dos4g_LIBS = $(COREDOSLIBS)
deepc_STACK = 8192
dev_deepc = dbgdeepc
editor_deepc = deepced
editprof_deepc = deepced
editdbg_deepc  = ddeepced
playtest_deepc = deepc
deepced_deepc = deepced
ship_deepc = deepc
shipprot_deepc = deepc

#
# SHOCK EXECUTABLE
#
shock_sub_projects = $(ENGINE_SUBPROJECTS) $(SHOCK_GAME_DIR)
shock_opt_objs = $(ENGINE_OPT_OBJS)
shock_OBJS = $(BASEOBJS) $(SHOCKOBJS) shktable
shock_LIBS = $(CORELIBS)
%if '$(ADDRES)'
shock_RC = shock
%endif
shock_compiler_libs = $(CORECOMPLIBS)
shock_win32_LIBS = $(COREWINLIBS)
shock_dos4g_LIBS = $(COREDOSLIBS)
shock_STACK = 8192
dev_shock = dbgshock
editor_shock = shocked
editprof_shock = shocked
editdbg_shock  = dshocked
playtest_shock = shock2
shocked_shock = shocked
ship_shock = shock2
shipprot_shock = shock2


#
# HYBRID EXECUTABLE
#
hybrid_sub_projects = $(ENGINE_SUBPROJECTS) $(DARK_GAME_DIR) $(SHOCK_GAME_DIR)
hybrid_opt_objs = $(ENGINE_OPT_OBJS)
hybrid_OBJS = $(BASEOBJS) $(DARK_GAME_OBJS) $(SHOCKOBJS) hybtable
hybrid_LIBS = $(CORELIBS)
hybrid_RC   = $(EDITRC)
hybrid_compiler_libs = $(CORECOMPLIBS)
hybrid_win32_LIBS = $(COREWINLIBS)
hybrid_dos4g_LIBS = $(COREDOSLIBS)
hybrid_STACK = 8192
dev_hybrid = rpg
editor_hybrid = dromed
editprof_hybrid = dromed
editdbg_hybrid  = ddromed
shocked_hybrid = shockhyb
deepc_hybrid = deepchyb

#
# GENERIC EXECUTABLE
#
generic_sub_projects = $(ENGINE_SUBPROJECTS)
generic_opt_objs = $(ENGINE_OPT_OBJS)
generic_OBJS = $(BASEOBJS) gentable
generic_LIBS = $(CORELIBS)
generic_RC   = $(EDITRC)
generic_compiler_libs = $(CORECOMPLIBS)
generic_win32_LIBS = $(COREWINLIBS)
generic_dos4g_LIBS = $(COREDOSLIBS)
generic_STACK = 8192
dev_generic = genrpg
editor_generic = gdromed
editprof_generic = gdromed
editdbg_generic  = dgdromed

#
# Lex and yacc for schema text file parsing
#

schtok.h schyacc.c: schema.y
	yacc -l -D schtok.h -o sound\schyacc.c $(.source)

schlex.c: schlex.lex schtok.h
	lex -l -o $(SYS)\$(.target,F) $(.source)

mschtok.h mschyacc.c: mschema.y
	yacc -p msch -l -D mschtok.h -o mschyacc.c $(.source)

mschlex.c: mschlex.lex mschtok.h
	lex -p msch -l -o $(SYS)\$(.target,F) $(.source)

inctok.h inc.c: inc.y
	yacc -p inc -l -D inctok.h -o inc.c $(.source)

inclex.c: inclex.lex inctok.h
	lex -p inc -l -o $(SYS)\$(.target,F) $(.source)

songtok.h songyacc.c: songlang.y
	yacc -p songyy -l -D songtok.h -o songyacc.c $(.source)

songlex.c: songlang.lex songtok.h
	lex -p songyy -l -o $(SYS)\$(.target,F) $(.source)

# schemas parsing test program


dev_schtool = schtool
schtool_OBJS = schtlex schtool inclex inc inctab
schtool_LIBS = lg mprintf cpptools dstruct config mprintf

schttok.h schtool.c: schtool.y
	yacc -l -D schttok.h -o schtool.c $(.source)

schtlex.c: schtlex.lex schttok.h
	lex -l  -o $(.target) $(.source)

# Mission file stripper

dev_misstrip = misstrip
editor_misstrip = misstrip
misstrip_LIBS = $(TECH_LIBS) tagfile
misstrip_objs = misstrip camguids

# Mission file differ

dev_missdiff = missdiff
editor_missdiff = missdiff
missdiff_LIBS = $(TECH_LIBS) tagfile
missdiff_objs = missdiff camguids


# header file parsing test program

dev_inctest = inctest
inctest_OBJS = inclex inctest inctab
inctest_LIBS = cpptools lg dstruct config mprintf

inctest.c: inctest.y
	yacc -p inc -l -o inctest.c $(.source)

# OK, here's my hack to clean the Portal opt objs if requested:
clean_portal_opt_objs .PHONY .NODEFAULT:
        @echo cleaning portal opt objs
        %foreach obj $(PORTAL_OPT_OBJS)
        @del $(OLOC)\$(obj).obj
        %end

%include $(MRC)\make.rc


