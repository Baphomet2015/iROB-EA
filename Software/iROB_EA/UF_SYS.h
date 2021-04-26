// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        UF_SYS.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Definicion de la clase UF_SYS
//
// Notas:          REVISADO 08/04/2016         
//
// ---------------------------------------------------------


#ifndef IDE_UF_SYS_H
#define IDE_UF_SYS_H



// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------

#define EEPROM_ADDR_NUM_RC                   0  // Direccion en EEPROM (offset) de comienzo de la variable que almacena el numero de Reintentos de arranque 
#define EEPROM_ADDR_CLV_AE                   1  // Direccion en EEPROM (offset) de comienzo de la variable que almacena 
#define EEPROM_ADDR_RECARGAS                 5  // Direccion en EEPROM (offset) de comienzo de la variable que almacena 
                                                // Las variables se almacenan en EEPROM en este orden:
                                                // ADDR 0: variable EEPROM_ADDR_NUM_RC   1 Byte
                                                // ADDR 1: variable EEPROM_ADDR_CLV_AE   4 Bytes
                                                // ADDR 5: variable EEPROM_ADDR_RECARGAS 2 Bytes
 
#define IDE_RELE_SYS_OFF                     0  // Rele de power OFF
#define IDE_RELE_PC                          1  // Rele para alimentar el PC
#define IDE_RELE_12P                         2  // Rele para activar la alimentacion de 12 voltios

#define IDE_RELE_SYS_PAUSA                 250  // Pausa (ms) para activar/Desactivar los reles de alimentacion del PC y 12V 
#define IDE_RELE_ACTIVAR                     1
#define IDE_RELE_DESACTIVAR                  0

#define IDE_LED_DER                          0  // Leds blancos, derecho
#define IDE_LED_IZQ                          1  // Leds blancos, izquierdo
#define IDE_LED_POS                          2  // Leds traseros

#define IDE_LED_OFF                         10  // Led apagado
#define IDE_LED_ON                          11  // Led encendido
#define IDE_LED_BLK                         12  // Led blinking

#define IDE_LED_TIMER                   10000L  // Contador para generar intermitencias con los leds

#define IDE_SEC_INICIO_OK                    0
#define IDE_SEC_INICIO_ER_BLK                1
#define IDE_SEC_INICIO_ER_CLV                2

#define IDE_ICC_5VP                          0
#define IDE_ICC_12P                          1

#define IDE_BAT_MIN                          0  // Bateria cargada al 0% 
#define IDE_BAT_N25                         25  // Bateria cargada al 25%
#define IDE_BAT_N50                         50  // Bateria cargada al 50%
#define IDE_BAT_N75                         75  // Bateria cargada al 75%     
#define IDE_BAT_N100                       100  // Bateria cargada al 100% 

#define IDE_STR_INICIO_VERSION               F("iROB_EA, version 1.00, Junio 2015")
#define IDE_STR_INICIO_POWER_OFF             F("Apagando Sistema (Power OFF)...")
#define IDE_STR_INICIO_POWER_DOWN            F("Iniciando Apagado (Power OFF)...")
#define IDE_STR_CALIBRAR_SENS_ICC            F("Calibrando Sensores Icc")
#define IDE_STR_PUNTO                        F(".")
#define IDE_STR_MSEG                         F(" ms")
#define IDE_STR_DEBUG_EXE                    F("Tiempo de ejecucion setup: ")
#define IDE_STR_LOCK                         F("Sistema Bloqueado, cambiar clave en programa fuente y recargar programa")

#define IDE_DTMF_PAUSA_TONO               300L  // DTMF: Tiempo máximo que puede pasar entre tonos cuando se esta introduciendo una clave
#define IDE_OFF_PAUSA                     4000  // Pausa antes de apagar el Robot


#define IDE_MAXBUFF_GENERICO                50  // Tamaño para un buffer temporal generico

#define IDE_ICC_NUM_MEDIDAS_CALIBRAR       500  // Numero de medidas que realiza la funcion get_Corriente() para obtener la corriente medida con los ACS741
#define IDE_ICC_NUM_MEDIDAS_OBTENER        200  // Numero de medidas que realiza la funcion get_Corriente() para obtener la corriente medida con los ACS741
#define IDE_ICC_SENSIBILIDAD                66  // Sensibilidad del ACS741 66mV/A


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
     void          inicio               (void);                             // REVISADA
     void          timers               (void);                             // REVISADA
  
     void          power_OFF            (void);                             // REVISADA
     void          rele                 (byte releID,byte estado);          // REVISADA
     
     byte          secuenciaInicio      (void);                
                                                               
     byte          get_NUM_RC           (void);                             // REVISADA
     void          get_CLV_AE           (char* valor);                      // REVISADA

     byte          get_DTMF             (void);                             // REVISADA
     byte          get_CodigoDTMF       (char* buff);                       // REVISADA
     byte          get_FlgDebug         (void);                             // REVISADA
  
     void          set_NUM_RC           (byte  valor);                      // REVISADA
     void          set_CLV_AE           (char* valor);                      // REVISADA

     byte          set_Led              (byte ledID,byte modo);
     void          set_RECARGAS         (int   valor);                      // REVISADA
       
      int          get_Bateria          (void);
      float        get_Corriente        (int sensorID);
      
    
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     float         adc_vConversion;  // Variable relacionada con el conversor ADC del Arduino 
     float         offset_12P;       // Offset real del sensor asociado a la medida de corriente 12P
     float         offset_5VP;       // Offset real del sensor asociado a la medida de corriente 5VP

     unsigned long led_Timer;        // Para generar intermitencia en los leds 
     byte          led_Blk;          // Para generar intermitencia en los leds

     byte          led_DER;          // Modo de funcionamiento de los leds balncos delanteros
     byte          led_IZQ;          // Modo de funcionamiento de los leds blancos traseros
     byte          led_POS;          // Modo de funcionamiento de los leds rojos traseros

     void          display_Clave  (byte n);                              // REVISADA
     void          calibra_ACS714 (void);                                // REVISADA

};









#endif
