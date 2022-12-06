@echo off
CLS
rem This is a small helper script that automatically downloads the 
rem latest binary image for TMP006 BoosterPack User Experience code.
rem
rem William Goh, MSP430 Applications, Texas Instruments, Inc.
rem Last modified: 03/22/2012
set device=MSP430G2553
set firmware=IO_Expander.txt
goto program

:program
@echo Programing %firmware% into %device% ......
MSP430Flasher.exe -n %device% -w %firmware% -v -g -z [VCC]

pause