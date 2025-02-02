#
# MAKEFILE 31
# ----------------------------------------------------------------------------
# HOST INFO
MAKEDIR = 
BINDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2\bin
INCDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2\include
LIBDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2
P1DIR =   C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler
#----------------------------------------------------------------------------
#APP INFO BEFORE SYS INFO
ROP = DISABLE
DUALBOOT = NOFILE
# -------------------------------------------------------------------------
# SOCKETS
# external plugin
!if ("$(DUALBOOT)"!=NOFILE)
DUALBOOTEXR = $(DUALBOOT).exr
DUALBOOTIDL = $(DUALBOOT).idl
!else
DUALBOOTEXR =
DUALBOOTIDL =
!endif
# ----------------------------------------------------------------------------
# SYS INFO
OS_COMPVER = 474
OS_UGCPAR  = ugp1par.txt
OS_LIB     = 70091042v190.XML
OS_EXR     = 70091042v190.EXR
					  
# ----------------------------------------------------------------------------
# APP INFO
PROJ          = KILLSWITCH
PROJQ         = "KILLSWITCH"
OBJ_FILES     =  "KILLSWITCH.OBJ" "MC50_110_LG_T_MC50_112T.OBJ"
C_FILES       =  "KILLSWITCH.C" "MC50_110_LG_T_MC50_112T.C"
CUSTOM_LIB    = 
EXR_FILES     =  "KILLSWITCH.EXR" "MC50_110_LG_T_MC50_112T.EXR"
BMP_FILES     = 
TEXTDBF_FILES = 
REGFILEXT     = NOFILE
REGFIL        = NOFILE
MAINMODULE    = "MC50_110_LG_T_MC50_112T.SCS" 
MAINMODULEEXR = $(MAINMODULE:.SCS=.EXR)
# ----------------------------------------------------------------------------
# COMPILE LINK COMMAND
UGRAPHP1_1 = "$(P1DIR)\chpargu1.exe" 
UGRAPHP1_2 = 2 $(OS_UGCPAR) $(PROJQ) $(PROJQ) 
PRJTOC = "$(P1DIR)\ProjectToC.exe" "PROJECT=KILLSWITCH.P1X,APPLICATION=KILLSWITCH,OPTION=NOCODE"
# ----------------------------------------------------------------------------
# MAKE JOB
# check application
"KILLSWITCH.log" : $(EXR_FILES) $(OS_LIB) $(OS_EXR) $(DUALBOOTEXR)
	@"$(P1DIR)\conmsg" Check and Link application $(PROJ)
	@"$(P1DIR)\glink.exe" "PROJECT=KILLSWITCH.P1X,APPLICATION=KILLSWITCH"
	@"$(P1DIR)\conmsg" MAKEJOB31 END
# OS Exr
$(OS_EXR) :	 MkFile31.mak
	@"$(P1DIR)\conmsg" MAKEJOB31 BEGIN
    @"$(P1DIR)\conmsg" Generating OS exr 
	@"$(P1DIR)\conmsg" CAN and NV symbols 
!if ("$(ROP)"=="ENABLE")
	echo U__PARAM-OPEN >> $(OS_EXR)
!endif
	echo $ >> $(OS_EXR)
# EXR for dual boot
!if ( "$(DUALBOOT)"!=NOFILE ) 
$(DUALBOOTEXR) : $(DUALBOOTIDL)
    @"$(P1DIR)\conmsg" Generate $(DUALBOOTEXR)
    @"$(P1DIR)\RatatoskT3.exe" "input=$(DUALBOOTIDL), silent=yes, exr=yes"   
!endif
# PLUS+1 project files
"KILLSWITCH.EXR" : "KILLSWITCH.P1X"
    @"$(P1DIR)\conmsg" Generating code from p1x $**
	@$(PRJTOC)
"KILLSWITCH.P1X" : "$(MAINMODULEEXR)"
# Application

"MC50_110_lg_T_MC50_112T.exr" : "MC50_110_lg_T_MC50_112T.nob"
   @$(UGRAPHP1_1) "MC50_110_lg_T_MC50_112T" $(UGRAPHP1_2)
"MC50_110_lg_T_MC50_112T.nob" : "MC50_110_lg_T_MC50_112T.scs"
   @"$(P1DIR)\scstonob.exe" "MC50_110_lg_T_MC50_112T"


