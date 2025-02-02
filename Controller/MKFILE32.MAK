#
# MAKEFILE 32
# ----------------------------------------------------------------------------
# HOST INFO
MAKEDIR = 
BINDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2\bin
INCDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2\include
LIBDIR =  C:\ProgramData\Danfoss\PLUS1\2024.2\Data\ExtCompiler\ARM\v4.7-2013q2
P1DIR =   C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler
#----------------------------------------------------------------------------
#APP INFO BEFORE SYS INFO
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
NOC_FILES 	  =  "KILLSWITCH.NOC" "MC50_110_LG_T_MC50_112T.NOC"
# ----------------------------------------------------------------------------
# COMPILE LINK COMMAND
UGRAPHP1_1 = "$(P1DIR)\chpargu2.exe" 
UGRAPHP1_2 = 2 $(OS_UGCPAR) $(PROJQ) $(PROJQ)
PRJTOC = "$(P1DIR)\ProjectToC.exe" "PROJECT=KILLSWITCH.P1X,APPLICATION=KILLSWITCH,OPTION=NOCODE"
# ----------------------------------------------------------------------------
# MAKE JOB
# check application
"KILLSWITCH.LOG" : $(NOC_FILES) $(OS_LIB) 
    @"$(P1DIR)\conmsg" Check and Link application $(PROJ)
	@"$(P1DIR)\MergeErrorPass2.exe" "PROJECT=KILLSWITCH.P1X,APPLICATION=KILLSWITCH"
	@"$(P1DIR)\conmsg" MAKEJOB32 END
	@"$(P1DIR)\conmsg"
# PLUS+1 project files
"KILLSWITCH.NOC" : "KILLSWITCH.P1X"
	@"$(P1DIR)\conmsg" MAKEJOB 32 BEGIN
    @"$(P1DIR)\conmsg" Generating dummy file $**
	copy "KILLSWITCH.P1X" "KILLSWITCH.NOC"
# Application									    

"MC50_110_lg_T_MC50_112T.noc" : "MC50_110_lg_T_MC50_112T.nob"
   @$(UGRAPHP1_1) "MC50_110_lg_T_MC50_112T" $(UGRAPHP1_2)

# ClassDef

