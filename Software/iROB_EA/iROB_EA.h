
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        ROB_EA.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Fichero cabecera ( include ) principal de
//                 la Aplicacion
//
// Notas:          REVISADO 08/04/2016         
//
// ---------------------------------------------------------

#ifndef iROB_EA
#define iROB_EA


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo del HW
//
// ---------------------------------------------------------

#define PIN_HW_OFF_PETICION              2  // Entrada de la solicitud de power OFF

#define PIN_HW_POW_CNX_A2               45  // A2, multiplexor control de reles
#define PIN_HW_POW_CNX_A1               46  // A1, multiplexor control de reles
#define PIN_HW_POW_CNX_A0               47  // A0, multiplexor control de reles

#define PIN_HW_DTMF_D0                  49  // D0, Decodificador DTMF
#define PIN_HW_DTMF_D1                  50  // D1, Decodificador DTMF
#define PIN_HW_DTMF_D2                  51  // D2, Decodificador DTMF
#define PIN_HW_DTMF_D3                  52  // D3, Decodificador DTMF
#define PIN_HW_DTMF_DV                  48  // DV, Decodificador DTMF, dato valido

#define PIN_HW_HCMS_RESET               40  // Display Reset 
#define PIN_HW_HCMS_RS                  41  // Display Seleccion de Registro
#define PIN_HW_HCMS_CE                  42  // Display Enable
#define PIN_HW_HCMS_CLK                 43  // Display Clock
#define PIN_HW_HCMS_DATA                44  // Display Data

#define PIN_HW_CNX_DEBUG                53  // Indicador de conector de DEBUG conectado

#define PIN_HW_USR_DER_TRIGGER          13  // Sensor ultrasonidos derecho   salida
#define PIN_HW_USR_IZQ_TRIGGER          22  // Sensor ultrasonidos izquierdo salida
#define PIN_HW_USR_DER_ECHO             23  // Sensor ultrasonidos derecho   activacion 
#define PIN_HW_USR_IZQ_ECHO             24  // Sensor ultrasonidos izquierdo activacion 

#define PIN_HW_SERVO_HOR                 6  // Servo horizontal
#define PIN_HW_SERVO_VER                 7  // Servo vertical

#define PIN_HW_FAN                       8  // Ventilador del modulo de sensores

#define PIN_HW_LED_POS                  37  // Leds rojos traseros
#define PIN_HW_LED_DER                  38  // Leds blancos derecho
#define PIN_HW_LED_IZQ                  39  // Leds blancos izquierdo
#define PIN_HW_LED_FOCO                  9  // Led foco de la camara

#define PIN_HW_MTI_DIR                  28  // Motor derecho, Direccion
#define PIN_HW_MTI_RST                  29  // Motor derecho, Reset
#define PIN_HW_MTI_PWM                   5  // Motor derecho, PWN, velocidad/paro

#define PIN_HW_MTD_DIR                  30  // Motor izquierdo, Direccion
#define PIN_HW_MTD_RST                  31  // Motor izquierdo, Reset
#define PIN_HW_MTD_PWM                   4  // Motor izquierdo, PWN, velocidad/paro

#define PIN_HW_MTDI_SEL_A               27  // Multiplexor entrada señales de estado de los motores
#define PIN_HW_MTDI_SEL_B               26  // Multiplexor entrada señales de estado de los motores
#define PIN_HW_MTDI_SEL_C               25  // Multiplexor entrada señales de estado de los motores

//#define PIN_HW_DTR_RAZOR_1            --  // 9DOF-Razor-v21, señal DTR

#define PIN_HW_POW_PC_1                 32  // Encendido del PC  

#define PIN_HW_BAT_N25                  33  // control de carga de bateria 
#define PIN_HW_BAT_N50                  34  // control de carga de bateria 
#define PIN_HW_BAT_N75                  35  // control de carga de bateria     
#define PIN_HW_BAT_N100                 36  // control de carga de bateria 

#define PIN_HW_MIC_01                   A0  // Microfono, es la entrada de DTMF del 75T2090
#define PIN_HW_SEN_MET_LUZ              A1  // Estacion metereologica, sensor de luz 
#define PIN_HW_SUPERFICIE               A2  // Sensor de suelo
#define PIN_HW_MTDI_INFO                A3  // Salida multiplexor entrada señales de estado de los motores
#define PIN_HW_ICC_SENSE_12P            A4  // Sensor de corriente 12P
#define PIN_HW_ICC_SENSE_5VP            A5  // Sensor de corriente 5VP

// ---------------------------------------------------------
//
// Definiciones de control generales
//
// ---------------------------------------------------------

#define IDE_SERIAL_TRX_9600          9600      // Velocidad 9600 para el puerto serie DEBUG
#define IDE_PAUSA_GENERAL             500      // Pausa general de 500ms

#define IDE_PC_POWER_INICIO        10000L      // Tiempo en ms que se debe esperar desde que se activa la alimentacion del PC hasta que
                                               // se activa el pulsador de encendido, 10 segundos
                                               
#define IDE_PC_POWER_OFF_TIMEOUT  120000L      // Tiempo maximo de espera en ms para determinar que el PC se ha apagado,   3 minutos
#define IDE_PC_POWER_ON_TIMEOUT   120000L      // Tiempo maximo de espera en ms para determinar que el PC se ha encendido, 3 minutos
#define IDE_PC_POWER_ICC_OFF          100      // Corriente minima medida con el sensor de corriente asociado al PC para determinar que el PC se ha apagado 

#define IDE_PC_POWER_PULSADOR_ON       5       // Tiempo que se mantiene actuado el pulsador del PC para encenderlo, en segundos

#define IDE_PC_POWER_PULSADOR_OFF      1       // Tiempo que se mantiene actuado el pulsador del PC para apagarlo, en segundos
                                               // Nota:
                                               // NO colocar un valor MAYOR de 1 o 2 segundos para este define porque 
                                               // mantener el pulsador accionado por mas de 1 o 2 segundos indica a Windows
                                               // un apagado forzoso y en Windows 10 aparecera una ventana deslizante solicitando
                                               // arrastar para apagar

// ---------------------------------------------------------
//
// Definiciones relcionadas con el estado del PC
//
// ---------------------------------------------------------

#define IDE_STATUS_PC_INI_ON          0         // Inicio encendido del PC
#define IDE_STATUS_PC_START           1         // PC Inicializando, en espera de que arranque
#define IDE_STATUS_PC_ON              2         // PC encendido
#define IDE_STATUS_PC_OK              3         // Finalizado correctamente el proceso de encendido del PC
#define IDE_STATUS_PC_INI_OFF         4         // Solicitado apagado del Robot, inicio del apagado del PC
#define IDE_STATUS_PC_DOWN            5         // PC Apagando, en espera de que se apague
#define IDE_STATUS_PC_OFF             6         // PC Apagado
#define IDE_STATUS_PC_ON_ERROR        7         // Se ha producido un error al encender el PC                                       

// ---------------------------------------------------------
//
// Definiciones relacionadas con el modo general de
// funcionamiento
// Estos defines se relacionan con la variable GLOBAL:
//                  GLOBAL_FlgModoAvance
//
// ---------------------------------------------------------

#define IDE_MODO_AVANCE_CON_PROTECCION      0  // El Robot comprueba si durante el avance aparece algun obstaculo ( deteccion de suelo, objetos etc )
                                               // si aparece algun obstaculo durante el avance, se detiene.
#define IDE_MODO_AVANCE_SIN_PROTECCION      1  // El Robot no comprueba si existe algun obstaculo durante el avance.


// ---------------------------------------------------------
// Definiciones relacionadas con la deteccion de problemas
// detectados en modo avance.
// Estos defines se relacionan con la variable GLOBAL:
//              GLOBAL_FlgModoAvanceEvento
//
// ---------------------------------------------------------

#define IDE_EVENTO_OK                       0b11111111  // NO hay inicencias de avance
#define IDE_EVENTO_DESHABILITADO            0b11111110  // El modo Anvace con proteccion esta deshabilitado
#define IDE_EVENTO_SUELO                    0b00000001  // Bit en GLOBAL_FlgModoAvanceEvento que indica detectado falta de suelo -)
#define IDE_EVENTO_OBJETO_DERECHA           0b00000010  // Bit en GLOBAL_FlgModoAvanceEvento que indica detectado objeto por la derecha que impide el paso
#define IDE_EVENTO_OBJETO_IZQUIERDA         0b00000100  // Bit en GLOBAL_FlgModoAvanceEvento que indica detectado objeto por la izquierda que impide el paso
#define IDE_EVENTO_OBJETO_SOBRECARGA        0b00001000  // Bit en GLOBAL_FlgModoAvanceEvento que indica detectado un sobreconsumo en los motores, posible problema en avance

// ---------------------------------------------------------
//
// Retornos para indicar el resultado de la ejecucion de los
// comandos
// NO cambiar los valores, por Dios
//
// ---------------------------------------------------------

#define IDE_EXE_CMD_OK               1 
#define IDE_EXE_CMD_ER               0 

// ---------------------------------------------------------
//
// Definiciones de control relacionadas con la clave de 
// arranque
//
// ---------------------------------------------------------

                                               // ---------------------------------------------------------
                                               //                   CLAVE DE ARRANQUE
#define IDE_CLV_AP                    "9000"   // Clave de arranque, siempre 4 digitos (IDE_CLV_MAXL)
                                               // Si se produce un bloqueo al agotar el  numero  maximo  de 
                                               // reintentos (IDE_CLV_MAX_INTENTOS) la forma de DESBLOQUEAR
                                               // el Robot es:
                                               // . Cambiar este define, poniendo otro valor de clave DISTINTO
                                               // . Compilar de nuevo el programa
                                               // . Volver a cargar el nuevo programa en el Arduino  
                                               // ---------------------------------------------------------                                              
#define IDE_CLV_MAXL                  4        // Longitud de la clave de arranque
#define IDE_CLV_MAX_INTENTOS          3        // Numero de intentos máximo de introducir clave de arranque  
#define IDE_CLV_MAX_TIEMPO            10000L   // Tiempo maximo para introducir una clave de inicio (ms)

// ---------------------------------------------------------
//
// Definiciones de control relacionadas con el Display
//
// ---------------------------------------------------------

const char IDE_MSG_DISPLAY_OK     [] PROGMEM = " OK ";
const char IDE_MSG_DISPLAY_ER     [] PROGMEM = " ER ";
const char IDE_MSG_DISPLAY_OFF    [] PROGMEM = " OFF";
const char IDE_MSG_DISPLAY_DOWN   [] PROGMEM = "DOWN";
const char IDE_MSG_DISPLAY_PWD    [] PROGMEM = "****";
const char IDE_MSG_DISPLAY_CLS    [] PROGMEM = "    ";
const char IDE_MSG_DISPLAY_BLK    [] PROGMEM = "LOCK";
const char IDE_MSG_DISPLAY_INI_PC [] PROGMEM = ".PC.";

const char IDE_MSG_DISPLAY_ER_000 [] PROGMEM = "E000";  // Error, activando el PC
const char IDE_MSG_DISPLAY_ER_001 [] PROGMEM = "E001";  // Error, el PC no se ha apagado 

#define IDE_MAX_DISPLAY_CAR       4                     // Numero de caracteres del display, NO cambiar, los mensajes IDE_MSG_DISPLAY_xx son de esta longitud


// ---------------------------------------------------------
//
// Declaracion de funciones del modulo iROB_EA.ino
//
// ---------------------------------------------------------

byte FNG_DisplayMsgPROGMEM (const char* msgP,unsigned int pausa);
byte FNG_DisplayMsg        (      char* msg ,unsigned int pausa);
void FNG_Pausa             (unsigned int pausa);
void FNG_SetPowerMotores   (byte estado);









#endif
