EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Baphomet_Libreria
LIBS:switches
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "UF_PC"
Date ""
Rev "1.0"
Comp "iROB-EA_VS_2021_UF_PC"
Comment1 "Subsistema PC"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 6150 2000 0    60   Output ~ 0
PC-TX
Text GLabel 6150 2650 0    60   Input ~ 0
PC-RX
$Comp
L CP2102_USB_TO_TTL U?
U 1 1 619BE658
P 8100 1500
F 0 "U?" H 8250 1550 60  0000 C CNN
F 1 "CP2102_USB_TO_TTL" H 8650 1650 60  0000 C CNN
F 2 "" H 8100 1500 60  0001 C CNN
F 3 "" H 8100 1500 60  0001 C CNN
	1    8100 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1900 8000 1900
Wire Wire Line
	7350 2050 8000 2050
$Comp
L GND #PWR?
U 1 1 619BE6C6
P 7800 2550
F 0 "#PWR?" H 7800 2300 50  0001 C CNN
F 1 "GND" H 7800 2400 50  0001 C CNN
F 2 "" H 7800 2550 50  0000 C CNN
F 3 "" H 7800 2550 50  0000 C CNN
	1    7800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2200 7800 2200
Wire Wire Line
	7800 2200 7800 2550
$Comp
L SW_SPDT SW?
U 1 1 619BE7AA
P 6600 2000
F 0 "SW?" H 6600 2170 50  0000 C CNN
F 1 "SW_SPDT" H 6600 1800 50  0001 C CNN
F 2 "" H 6600 2000 50  0000 C CNN
F 3 "" H 6600 2000 50  0000 C CNN
	1    6600 2000
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW?
U 1 1 619BE819
P 6550 2650
F 0 "SW?" H 6550 2820 50  0001 C CNN
F 1 "SW_SPDT" H 6550 2450 50  0001 C CNN
F 2 "" H 6550 2650 50  0000 C CNN
F 3 "" H 6550 2650 50  0000 C CNN
	1    6550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2050 7350 2550
Wire Wire Line
	7350 2550 6750 2550
Wire Wire Line
	6150 2000 6400 2000
Wire Wire Line
	6150 2650 6350 2650
Wire Notes Line
	6600 2000 6600 2500
Text GLabel 7150 900  2    60   Output ~ 0
DBG_TX
Wire Wire Line
	7150 900  6950 900 
Wire Wire Line
	6950 900  6950 2100
Wire Wire Line
	6950 2100 6800 2100
Text GLabel 7150 1150 2    60   Input ~ 0
DBG_RX
Wire Wire Line
	7150 1150 7100 1150
Wire Wire Line
	7100 1150 7100 2750
Wire Wire Line
	7100 2750 6750 2750
Text Notes 9500 2050 0    60   ~ 0
CONECTADO A UNA ENTRADA USB\nDEL PC STICK
Text Notes 6400 2950 0    60   ~ 0
MODO NORMAL / PROGRAMACION ARDUINO
$EndSCHEMATC