@ECHO OFF
@ECHO OFF
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\make.exe" "KILLSWITCH" LONGNAME:ON
if errorlevel 1 goto out1
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\sdm.exe" -r %1 -f MKFILE31.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\errclr" "KILLSWITCH" err
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\sdm.exe" -r %1 -f MKFILE32.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\errclr" "KILLSWITCH" err
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\writescreentime.exe"
ECHO KILLSWITCH successfully compiled
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\RESULT" T "KILLSWITCH successfully Error Checked"
goto end
:out1
ECHO Not able to build Initialization data for KILLSWITCH
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\RESULT" F "Not able to build Initialization data for KILLSWITCH"
goto end
:out2
ECHO Error Checking of KILLSWITCH aborted with errors
"C:\Program Files (x86)\Danfoss\PLUS1\2024.2\GUIDE\P1Compiler\RESULT" F "Error Checking of KILLSWITCH aborted with errors"
:end

