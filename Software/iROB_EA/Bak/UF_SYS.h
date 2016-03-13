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
// Notas:          
//
// ---------------------------------------------------------


#ifndef IDE_UF_SYS_H
#define IDE_UF_SYS_H



// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------

#define EEPROM_ADDR_NUM_RC                   0   // Direccion en EEPROM (offset) de comienzo de la variable que almacena el numero de Reintentos de arranque 
#define EEPROM_ADDR_MOD_INI                  1   // Direccion en EEPROM (offset) de comienzo de la variable que almacena la clave actual de acceso
#define EEPROM_ADDR_CLV_AE                   2   // Direccion en EEPROM (offset) de comienzo de la variable que almacena 
#define EEPROM_ADDR_WATCHDOG                 6   // Direccion en EEPROM (offset) de comienzo de la variable que almacena 
#define EEPROM_ADDR_RECARGAS                 7   // Direccion en EEPROM (offset) de comienzo de la variable que almacena 
                                                 // Las variables se almacenan en EEPROM en este orden:
                                                 // ADDR 0: variable EEPROM_ADDR_NUM_RC    1 Byte
                                                 // ADDR 1: variable EEPROM_ADDR_MOD_INI   1 Byte
                                                 // ADDR 2: variable EEPROM_ADDR_CLV_AE    4 Bytes
                                                 // ADDR 3: variable EEPROM_ADDR_WATCHDOG  1 Byte
                                                 // ADDR 4: variable EEPROM_ADDR_RECARGAS  2 Bytes
                                                

                                                 

#define IDE_INICIO_POWER_ON                  0   // Inicio de Arduino por power ON ( arranque normal)
#define IDE_INICIO_WATCHDOG                  1   // Inicio de Arduino por watchdog

#define IDE_RELE_SYS_OFF                     0  // Rele de power OFF
#define IDE_RELE_CPU_APL                     1  // Rele para alimentar la CPU APL
#define IDE_RELE_CAMARA                      2  // Rele para alimentar la camara
#define IDE_RELE_MOTORES                     3  // Rele para alimentar los motores

#define IDE_RELE_SYS_PAUSA                 250  // Pausa (ms) para activar/Desactivar los reles RE1, RE2, RE3 y RE4 
#define IDE_RELE_ACTIVAR                     1
#define IDE_RELE_DESACTIVAR                  0

                                            // Usar MEMPROG
#define IDE_STR_INICIO_VERSION               "iROB_EA, version 1.00, Junio 2015" 
#define IDE_STR_INICIO_WATCHDOG              "Arranque por Watchdog"
#define IDE_STR_INICIO_POWER_ON              "Arranque por Power ON"
#define IDE_STR_INICIO_POWER_OFF             "Apagando Sistema (Power OFF)..."
#define IDE_STR_INICIO_POWER_DOWN            "Iniciando Apagado (Power OFF)..."
#define IDE_STR_SINCRO_WATCHDOG_1            "Sincronizando el watchdog..."
#define IDE_STR_SINCRO_WATCHDOG_2            "Watchdog sincronizado"

#define IDE_SYSTEM_OK                    0x00
#define IDE_SYSTEM_OFF                   0xF0
#define IDE_SYSTEM_WATCHDOG              0x0F


#define IDE_DTMF_PAUSA_TONO               300L // DTMF: Tiempo máximo que puede pasar entre tonos cuando se esta introduciendo una clave
#define IDE_OFF_PAUSA                    2000  // Pausa antes de apagar el Robot

#define IDE_MAXBUFF_GENERICO               50  // Tamaño para un buffer temporal generico

#define IDE_CAPACIDAD_BAT_LIPO           6500  // Capacidad en miliamperios de la Bateria LiPoPack equipada
#define IDE_CAPACIDAD_BAT_PPAK          10400  // Capacidad en miliamperios de la Bateria PowerPack equipada




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
  
                   UF_SYS               (void);
     void          inicio               (void);
  
     void          watchDog_DONE        (void);
     void          watchDog_Sincro      (void);
     void          power_OFF            (void);
     void          rele                 (byte releID,byte estado);
     
     byte          secuenciaInicio      (void);
     
     byte          get_NUM_RC           (void);
     void          get_CLV_AE           (char* valor);
     byte          get_MOD_INI          (void);
     byte          get_WATCHDOG         (void);
     int           get_RECARGAS         (void);
     byte          get_DTMF             (void);

     byte          get_CodigoDTMF       (char* buff);
     double        get_Corriente        (byte pinID);
     byte          get_NivelPPbank      (void);
     byte          get_NivelLiPo        (void);
     byte          get_FlgDebug         (void); 
  
     void          set_NUM_RC           (byte  valor);
     void          set_CLV_AE           (char* valor);
     void          set_MOD_INI          (byte  valor);
     void          set_WATCHDOG         (byte  valor);
     void          set_RECARGAS         (int   valor);

     void          calibra_SensoresIcc  (void);
     void          recarga_Bateria      (void);
     
     void          display_Datos_EEPROM (void);
     void          display_Modo         (void);
     unsigned long getTimeExe           (byte modo);
     void          miDelay              (unsigned long int retardo);
     

 
    
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     unsigned long timeExe;      // variable para medir el tiempo de ejecucion del bloque principal del programa
                                 // Reloj de Tiempo Real

     int numRecargas;
     int offsetIcc_CHG_PPAK;     // Offset para la lectura del sensor de corriente de entrada al PowerBank
     int offsetIcc_CHG_LIPO;     // Offset para la lectura del sensor de corriente de entrada a la bateria LiPo
     int offsetIcc_MDER_ICC;     // Offset para la lectura del sensor de corriente del motor derecho
     int offsetIcc_MIZQ_ICC;     // Offset para la lectura del sensor de corriente del motor izquierdo
                                                        
};









#endif



