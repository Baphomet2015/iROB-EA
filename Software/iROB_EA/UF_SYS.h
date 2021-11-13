

// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        UF_SYS.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase UF_SYS
//
// Notas:          REVISADO 08/04/2016         
//
// ---------------------------------------------------------


#ifndef IDE_UF_SYS_H
#define IDE_UF_SYS_H

#include <RTClib.h>


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------

#define EEPROM_ADDR_NUM_RC                   0  // Direccion en EEPROM (offset) de comienzo de la variable que almacena el numero de Reintentos de arranque, 1 byte 
#define EEPROM_ADDR_CLV_AE                   1  // Direccion en EEPROM (offset) de comienzo de la variable que almacena la clave detectada, 4 bytes
                                                // Las variables se almacenan en EEPROM en este orden:
                                                // ADDR 0: variable EEPROM_ADDR_NUM_RC   1 Byte
                                                // ADDR 1: variable EEPROM_ADDR_CLV_AE   4 Bytes
                                                
 
#define IDE_RELE_SYS_OFF                     0  // Señal para activar la funcion de power OFF
#define IDE_RELE_5VP                         1  // Señal (rele) para activar/desactivar alimentar el PC +5VP
#define IDE_RELE_12P                         2  // Señal (rele) para activar/desactivar la alimentacion de 12 voltios +12P

#define IDE_RELE_SYS_PAUSA                 250  // Funcion UF_SYS::rele(), pausa (ms) para activar/Desactivar reles 
#define IDE_RELE_ACTIVAR                     1  // Funcion UF_SYS::rele(), activar rele
#define IDE_RELE_DESACTIVAR                  0  // Funcion UF_SYS::rele(), desactivar rele
 
#define IDE_LED_DER                          0  // Leds blancos, derecho
#define IDE_LED_IZQ                          1  // Leds blancos, izquierdo
#define IDE_LED_POS                          2  // Leds traseros
#define IDE_LED_FOCO                         3  // Led  foco camara

#define IDE_LED_OFF                         10  // Led apagado
#define IDE_LED_ON                          11  // Led encendido
#define IDE_LED_BLK                         12  // Led blinking

#define IDE_LED_TIMER                   10000L  // Contador para generar intermitencias con los leds

#define IDE_SEC_INICIO_OK                    0  // Retornos de la funcion UF_SYS::secuenciaInicio()
#define IDE_SEC_INICIO_ER_BLK                1
#define IDE_SEC_INICIO_ER_CLV                2

#define IDE_ICC_5VP                          0
#define IDE_ICC_12P                          1

                                                // Retornos de la funcion UF_SYS::get_Bateria() 
#define IDE_BAT_MIN                          0  // Bateria cargada al 0% 
#define IDE_BAT_N25                         25  // Bateria cargada al 25%
#define IDE_BAT_N50                         50  // Bateria cargada al 50%
#define IDE_BAT_N75                         75  // Bateria cargada al 75%     
#define IDE_BAT_N100                       100  // Bateria cargada al 100% 

#define IDE_MOTOR_DERECHO                    0  // Identificacion motor derecho
#define IDE_MOTOR_IZQUIERDO                  1  // Identificacion motor izquierdo

                                                // ---------------------------------------------
                                                // Retorno de la funcion que determina el estado
                                                // de los motores, UF_SYS:get_MotorEstado()
                                                // FF1  FF2  , ver documentacion POLOLU
#define IDE_MOTOR_OK                         0  //  L    L Motor correcto
#define IDE_MOTOR_CORTOCIRCUITO              1  //  L    H Cortocircuito
#define IDE_MOTOR_TEMPERATURA                2  //  H    L Sobre temperatura
#define IDE_MOTOR_TENSION                    3  //  H    H Tension de alimentacion baja
#define IDE_MOTOR_ER                         4  //  -    - Error en la llamada a la funcion

#define IDE_MOTOR_ESTADO_0                   50 // Valor leido desde PIN_HW_MTDI_INFO (entrada analogica) para reconocer un 0 logico enviado desde las señales FF1 o FF2
#define IDE_MOTOR_ESTADO_1                  255 // Valor leido desde PIN_HW_MTDI_INFO (entrada analogica) para reconocer un 1 logico enviado desde las señales FF1 o FF2
#define IDE_MOTOR_FF1FF2_DELAY             1000 // Pausa microsegundos para leer las señales FF1 y FF2 de los motores

#define IDE_STR_INICIO_VERSION               F("iROB_EA, version 1.00, Junio 2015")
#define IDE_STR_INICIO_POWER_OFF             F("Apagando Sistema (Power OFF)...")
#define IDE_STR_INICIO_POWER_DOWN            F("Iniciando Apagado (Power OFF)...")
#define IDE_STR_CALIBRAR_SENS_ICC            F("Calibrando Sensores Icc")
#define IDE_STR_PUNTO                        F(".")
#define IDE_STR_MSEG                         F(" ms")
#define IDE_STR_DEBUG_EXE                    F("Tiempo de ejecucion setup: ")
#define IDE_STR_LOCK                         F("Sistema Bloqueado, cambiar clave en programa fuente y recargar programa")
#define IDE_STR_MTD                          F("Motor derecho: ")
#define IDE_STR_MTI                          F("Motor izquierdo: ")

#define IDE_DTMF_PAUSA_TONO               300L  // DTMF: Tiempo máximo que puede pasar entre tonos cuando se esta introduciendo una clave
#define IDE_OFF_PAUSA                     4000  // Pausa antes de apagar el Robot

#define IDE_MAXBUFF_GENERICO                50  // Tamaño para un buffer temporal generico

#define IDE_SERVO_X_POS_DEFECTO             90  // Posicion por defecto del servo que mueve la camara en el eje X 
#define IDE_SERVO_X_MAX_IZQUIERDA          180       
#define IDE_SERVO_X_MAX_DERECHA              0

#define IDE_SERVO_Y_POS_DEFECTO             90  // Posicion por defecto del servo que mueve la camara en el eje Y 
#define IDE_SERVO_Y_MAX_ABAJO               55       
#define IDE_SERVO_Y_MAX_ARRIBA             125


#define IDE_ICC_NUM_MEDIDAS_CALIBRAR       500  // Numero de medidas que realiza la funcion calibra_ACS714(), ACS741
#define IDE_ICC_NUM_MEDIDAS_OBTENER        200  // Numero de medidas que realiza la funcion get_Corriente(),  ACS741
#define IDE_ICC_SENSIBILIDAD               0.4  // Sensibilidad del ACS723, version 5A --> 400mV/A

#define IE_PC_POWER_OFF                      0  //  Define relacionado con el encendido del PC, desde el pin PIN_HW_POW_PC_1, UF_SYS::power_PC()
#define IE_PC_POWER_ON                       1  //  Define relacionado con el apagado   del PC, desde el pin PIN_HW_POW_PC_1, UF_SYS::power_PC()

#define IDE_INT_POWER_OFF_NO_PERMITIDO       0 
#define IDE_INT_POWER_OFF_SI_PERMITIDO       1
#define IDE_INT_POWER_OFF_SOLICITADO         2

#define IDE_DEBUG_ON                         1 // Conector de DEBUG conectado
#define IDE_DEBUG_OFF                        0 // Conector de DEBUG no presente



// ---------------------------------------------------------
//
// Definicion de la Clase UF_SYS
//
// ---------------------------------------------------------

class UF_SYS
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
  
                   UF_SYS               (void);                             // REVISADA
     void          begin                (void);                             // REVISADA
     void          timers               (void);                             // REVISADA
  
     void          power_OFF            (void);                             // REVISADA
     void          power_PC             (byte modo);                        // REVISADA  
     void          rele                 (byte releID,byte estado);          // REVISADA
  
     byte          secuenciaInicio      (void);                             // REVISADA
                                                               
     byte          get_NUM_RC           (void);                             // REVISADA
     void          get_CLV_AE           (char* valor);                      // REVISADA

     byte          get_DTMF             (void);                             // REVISADA
     byte          get_CodigoDTMF       (char* buff);                       // REVISADA
     byte          get_FlgDebug         (void);                             // REVISADA
  
     void          set_NUM_RC           (byte  valor);                      // REVISADA
     void          set_CLV_AE           (char* valor);                      // REVISADA

     byte          set_Led              (byte ledID,byte modo);             // REVISADA
     byte          set_Fan              (byte modo);                        // REVISADA

     int           get_Bateria          (void);                             // REVISADA  
     
     float         get_Corriente        (int sensorID);                     // REVISADA 
     void          calibra_ACS714       (void);                             // REVISADA  
     
     int           get_MotorEstado      (int motorID);                      // REVISADA
     
     int           posiciona_servo_X    (unsigned int pos);                 // REVISADA
     int           posiciona_servo_Y    (unsigned int pos);                 // REVISADA 
                
     void          get_RTC_S  (int* estado,char* sBuffer);
     DateTime      get_RTC_D  (int* estado);
     void          set_RTC_D  (int* estado,DateTime dt);
     
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     float         offset_12P;       // Offset real del sensor asociado a la medida de corriente 12P
     float         offset_5VP;       // Offset real del sensor asociado a la medida de corriente 5VP

     unsigned long led_Timer;        // Para generar intermitencia en los leds 
     byte          led_Blk;          // Para generar intermitencia en los leds

     byte          led_DER;          // Modo de funcionamiento de los leds balncos delanteros
     byte          led_IZQ;          // Modo de funcionamiento de los leds blancos traseros
     byte          led_POS;          // Modo de funcionamiento de los leds rojos traseros
     byte          led_FOCO;         // Modo de funcionamiento del foco led de la camara

     RTC_DS3231    rtc;              // Reloj de tiempo real
     int           rtc_Flg;          // true:  RTC existe
                                     // false: RTC NO presente
     
     Servo         servo_X;          // Servo para mover la camara en el eje X
     Servo         servo_Y;          // Servo para mover la camara en el eje Y  

     
    
};









#endif
