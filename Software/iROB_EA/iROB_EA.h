
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        ROB_EA.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Fichero cabecera ( include ) principal de
//                 la Aplicacion
//
// Notas:          REVISADO 08/04/2016         
//
// ---------------------------------------------------------

#ifndef iROB_EA
#define iROB_EA

#include <avr/pgmspace.h>

// ---------------------------------------------------------
//
// DESCOMENTAR este define para compilar trazas de depuracion
//
// ---------------------------------------------------------

#define APP_MODO_DEBUG                   1   // MODO DEBUG: Descomentar este define
                                             // MODO REAL:  Comentar este define



// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo del HW
//
// ---------------------------------------------------------

#define PIN_HW_DOG_DONE                  53  // Señal para latido del watchdog            
#define PIN_HW_DOG_SFLAG                 12  // Flag asociado al Watchdog, 1: Se ha disparado el Watchdog    (inicio por Watchdog)          
                                             //                            0: NO se ha disparado el Watchdog (inicio por power ON)    
#define PIN_HW_OFF_PETICION               2  // Boton de power OFF

#define PIN_HW_POW_CNX_A0                47  // A0, multiplexor control de reles
#define PIN_HW_POW_CNX_A1                46  // A1, multiplexor control de reles
#define PIN_HW_POW_CNX_A2                45  // A2, multiplexor control de reles

#define PIN_HW_DTMF_D0                   49  // D0, Decodificador DTMF
#define PIN_HW_DTMF_D1                   50  // D1, Decodificador DTMF
#define PIN_HW_DTMF_D2                   51  // D2, Decodificador DTMF
#define PIN_HW_DTMF_D3                   52  // D3, Decodificador DTMF
#define PIN_HW_DTMF_DV                   48  // DV, Decodificador DTMF, dato valido


#define PIN_HW_HCMS_RESET                40  // the display's reset pin
#define PIN_HW_HCMS_RS                   41  // the display's register select pin 
#define PIN_HW_HCMS_CE                   42  // the display's chip enable pin
#define PIN_HW_HCMS_CLK                  43  // the display's clock pin
#define PIN_HW_HCMS_DATA                 44  // connects to the display's data in


#define PIN_HW_CNX_DEBUG                 26  // Indicador de conector de DEBUG conectado

#define PIN_HW_MIC_01                    A0  // Microfono

#define PIN_HW_USR_DERECHO_S             A5  // Sensor ultrasonidos derecho   salida
#define PIN_HW_USR_IZQUIERDO_S           A7  // Sensor ultrasonidos izquierdo salida
#define PIN_HW_USR_DERECHO_C             11  // Sensor ultrasonidos derecho   activacion 
#define PIN_HW_USR_IZQUIERDO_C            9  // Sensor ultrasonidos izquierdo activacion 


#define PIN_HW_SERVO_HOR                 13  // Servo horizontal
#define PIN_HW_SERVO_VER                 10  // Servo vertical

#define PIN_HW_LED_BDET                  39  // Leds blancos delanteros
#define PIN_HW_LED_BDEL                  38  // Leds blancos traseros
#define PIN_HW_LED_RDET                  37  // Leds rojos traseros

#define PIN_HW_MDER_DIR                  36  // Motor derecho, Direccion
#define PIN_HW_MDER_RST                  35  // Motor derecho, Reset
#define PIN_HW_MDER_PWM                   3  // Motor derecho, PWN, velocidad/paro
#define PIN_HW_MDER_FF1                  33  // Motor derecho, Flag estado (1)
#define PIN_HW_MDER_FF2                  34  // Motor derecho, Flag estado (2)
#define PIN_HW_MDER_ICC                  A3  // Motor derecho, sensor de corriente (consumo)

#define PIN_HW_MIZQ_DIR                  32  // Motor izquierdo, Direccion
#define PIN_HW_MIZQ_RST                  31  // Motor izquierdo, Reset
#define PIN_HW_MIZQ_PWM                   4  // Motor izquierdo, PWN, velocidad/paro
#define PIN_HW_MIZQ_FF1                  28  // Motor izquierdo, Flag estado (1)
#define PIN_HW_MIZQ_FF2                  30  // Motor izquierdo, Flag estado (2)
#define PIN_HW_MIZQ_ICC                  A4  // Motor izquierdo, sensor de corriente (consumo)

#define PIN_HW_SEN_MET_LUZ               A9  // Estacion metereologica, sensor de luz 
#define PIN_HW_DTR_RAZOR_1               24  // 9DOF-Razor-v21, señal DTR

#define PIN_HW_BAT_INBP                   8  // control de carga de bateria 
#define PIN_HW_BAT_INB0                   5  // control de carga de bateria 
#define PIN_HW_BAT_INB1                   6  // control de carga de bateria     
#define PIN_HW_BAT_INB2                   7  // control de carga de bateria 
#define PIN_HW_BAT_INBS                  A8  // control de carga de bateria 
#define PIN_HW_BAT_CHG_PPAK              A1  // Sensor de carga    de la Bateria PowerBank
#define PIN_HW_BAT_CHG_LIPO              A2  // Sensor de carga    de la Bateria LiPo

#define PIN_HW_IR01                      22  // Sensor infrarojos


// ---------------------------------------------------------
//
// Definiciones de control generales
//
// ---------------------------------------------------------


#define IDE_SERIAL_TRX_9600           9600    // Velocidad 9600 para puertos serie

#define IDE_CLV_AP                    "9000"  // Clave de arranque, siempre 4 digitos (IDE_CLV_MAXL)
#define IDE_CLV_MAXL                  4       // Longitud de la clave de arranque
#define IDE_CLV_MAX_INTENTOS          3       // Numero de intentos máximo de introducir clave de arranque  
#define IDE_CLV_MAX_TIEMPO            10000   // Tiempo maximo para introducir una clave de inicio (ms)

#define IDE_PAUSA_GENERAL             500     // Pausa general de 500ms

// ---------------------------------------------------------
//
// Definiciones de control relacionadas con el Display
//
// ---------------------------------------------------------

const char IDE_MSG_DISPLAY_OK     [] PROGMEM = " OK ";
const char IDE_MSG_DISPLAY_ER     [] PROGMEM = " ER ";
const char IDE_MSG_DISPLAY_ON     [] PROGMEM = " ON ";
const char IDE_MSG_DISPLAY_OFF    [] PROGMEM = " OFF";
const char IDE_MSG_DISPLAY_DOWN   [] PROGMEM = "DOWN";
const char IDE_MSG_DISPLAY_PWD    [] PROGMEM = "****";
const char IDE_MSG_DISPLAY_CLS    [] PROGMEM = "    ";
const char IDE_MSG_DISPLAY_BLK    [] PROGMEM = "LOCK";
const char IDE_MSG_DISPLAY_INI    [] PROGMEM = ".ON.";
const char IDE_MSG_DISPLAY_WAIT   [] PROGMEM = "WAIT";

const char IDE_MSG_DISPLAY_ER_000 [] PROGMEM = "E000";  // NO se utiliza 
const char IDE_MSG_DISPLAY_ER_001 [] PROGMEM = "E001";  // NO se utiliza 
const char IDE_MSG_DISPLAY_ER_002 [] PROGMEM = "E002";  // NO se utiliza 
const char IDE_MSG_DISPLAY_ER_003 [] PROGMEM = "E003";  // NO se utiliza 
const char IDE_MSG_DISPLAY_ER_004 [] PROGMEM = "E004";  // NO se utiliza 

#define IDE_MAX_DISPLAY_CAR       4                     // Numero de caracteres del display


// ---------------------------------------------------------
//
// Declaracion de funciones del modulo iROB_EA.ino
//
// ---------------------------------------------------------


byte FNG_DisplayMsgPROGMEM (const char* msgP,unsigned int pausa);
byte FNG_DisplayMsg        (      char* msg ,unsigned int pausa);
void FNG_Pausa             (unsigned int pausa);









#endif



