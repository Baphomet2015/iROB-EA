//! ---------------------------------------------------------
//!
//! @mainpage 
//!                 
//! @brief   Proyecto: iROB-EA
//! @date    Fecha:    Enero 2021
//! @author  AAL
//!
//! @remarks Hardware Arduino MEGA 2560\n
//!
//! @version Versión de SW 1.0
//! @version Versión de IDE Arduino: 1.8.12
//!
//! @brief   <b>Leitmotiv:</b>\n
//!          "Toda Bestia necesita un Cerebro...", Dr. Frankenstein, en su laboratorio\n
//!          "¡Larga y próspera vida!.", Sr. Spock\n
//!
//! ---------------------------------------------------------

//! ---------------------------------------------------------
//!
//! @brief   Funcionalidad:  Modulo principal de la Aplicacion
//!
//! @warning REVISADO --/--/----      
//! ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include <avr/pgmspace.h>
#include <Wire.h>
#include <Servo.h>
#include <EEPROM.h>
#include <LedDisplay.h>
#include "iROB_EA.h"
#include "UF_SYS.h"
#include "MOTOR_FDS5672.h"
#include "SENSOR_USS.h"
#include "SENSOR_GPS.h"
#include "SENSOR_EMC.h"
#include "SENSOR_RAZOR.h"
#include <Gescom_MEGA2560_V3.h>
#include <Gescom_MEGA2560_V3_CMD.h>


// ---------------------------------------------------------
//
//         Definicion de Clases y variables GLOBALES
//
//
// . uf_sys       Objeto de manejo de  funcionalidades basicas
// . mDer         Objeto de manejo del motor derecho
// . mIzq         Objeto de manejo del motor izquierdo
// . myDisplay    Objeto para manejear el display de estado
// . sensor_USS   Objeto para manejo de los sensores de US
// . sensor_EMC   Objeto para manejo de la estacion climatica
// . sensor_GPS   Objeto para manejo del GPS
// . sensor_RAZOR Objeto para manejo del RAZOR
// . sensor_mlx   Objeto para manejar el sensor MLX90614
// . rtc          Objeto para manejar el reloj de tiempo real 
// . gc           Objeto que implementa el gestor de comandos
//
// . GLOBAL_FlgDebug       Flag para control del modo DEBUG
// . GLOBAL_FlgStatusPC    Flag con el estado del PC      
// . GLOBAL_Timer_Ctrl_PC  Timer asociado a los procesos de
//                         encendido/apagado del PC
// ---------------------------------------------------------

UF_SYS            uf_sys    = UF_SYS();                            // Implementa la funcionalidad relacionada con la UF_SYS

MOTOR_FDS5672     mDer      = MOTOR_FDS5672( PIN_HW_MTD_DIR ,      // Implementa el control del motor derecho
                                             PIN_HW_MTD_RST ,
                                             PIN_HW_MTD_PWM 
                                           );                   

MOTOR_FDS5672     mIzq      = MOTOR_FDS5672( PIN_HW_MTI_DIR ,      // Implementa el control del motor izquierdo
                                             PIN_HW_MTI_RST ,
                                             PIN_HW_MTI_PWM 
                                           );                   

LedDisplay        myDisplay = LedDisplay( PIN_HW_HCMS_DATA  ,      // Implementa el control del display
                                          PIN_HW_HCMS_RS    ,
                                          PIN_HW_HCMS_CLK   ,
                                          PIN_HW_HCMS_CE    ,
                                          PIN_HW_HCMS_RESET ,
                                          4
                                        );                     
                                        
SENSOR_USS       sensor_USS = SENSOR_USS( PIN_HW_USR_DER_TRIGGER , // Implementa el control de los sensores de deteccion de objetos
                                          PIN_HW_USR_IZQ_TRIGGER ,
                                          PIN_HW_USR_DER_ECHO    ,
                                          PIN_HW_USR_IZQ_ECHO    ,
                                          PIN_HW_SUPERFICIE
                                        );         
SENSOR_EMC      sensor_EMC = SENSOR_EMC( PIN_HW_SEN_MET_LUZ);      // Implementa el control de los sensores de la estacion climatica                                                    
SENSOR_GPS      sensor_GPS;                                        // Implementa el modulo de GPS                                        
SENSOR_RAZOR    sensor_RAZOR;                                      // Implementa el modulo de sensores AHRS                                        

GESCOM3           gc        = GESCOM3( IDE_SERIAL_0        ,
                                       false               ,
                                       IDE_DISPOSITIVO_R00 ,
                                       IDE_SERIAL_TRX_PC
                                     );                            // Gestor de comandos

byte              GLOBAL_FlgDebug;                                 // Flag global que indica si se deben generar trazas por el puerto de Debug o no
byte              GLOBAL_FlgStatusPC;                              // Flag para control del proceso de encendido/Apagado                   
byte              GLOBAL_FlgModoAvance;                            // Flag que indica el modo de avance, ver defines IDE_MODO_AVANCE_xx                  
byte              GLOBAL_FlgModoAvanceEvento;                      // Flag que indica eventos detectados cuando la variable GLOBAL_FlgModoAvance = IDE_MODO_AVANCE_CON_PROTECCION
unsigned long int GLOBAL_Timer_Ctrl_PC;                            // Timer asociado a los procesos de encendido/apagado del PC
int               GLOBAL_Timer_DispD_PC;                           // Timer asociado a los procesos de encendido/apagado del PC, para mostrar en el display  
int               GLOBAL_Timer_DispF_PC;                           // Timer asociado a los procesos de encendido/apagado del PC, para mostrar en el display  



// ---------------------------------------------------------
//
// void setup()
//      Funcion para  inicializar  todos  los  sistemas  del
//      iROB-EA 
//
// ---------------------------------------------------------

void setup(void)
{
  // ---------------------------------------------------------
  //
  // ATENCIÓN:
  //
  // . Los pines de control de los motores NO se inicializan
  //   aqui porque ya lo hace el constructor de la clase
  //   MOTOR_FDS5672
  //
  // . Los pines de control del display NO se inicializan
  //   aqui porque ya lo hace el constructor de la clase
  //   ledDisplay
  //
  // . Los pines de control de los sensores de ultrasonidos 
  //   NO se inicializan aqui porque ya lo hace el constructor
  //   de la clase SENSOR_US
  //
  // . El pin PIN_HW_OFF_PETICION es la entrada de INT 0, no 
  //   es necesario inicializar este pin con pinMode
  //
  // ---------------------------------------------------------
 
  // ---------------------------------------------------------
  //
  // Inicializacion de los pines I/O (MODO)
  // Los pines que NO se inicializan expresamente aqui es debido
  // a que se inicializan en los objetos definidos para su 
  // utilizacion, sensor_USS, mDer, MIzq etc
  // ---------------------------------------------------------

  pinMode( PIN_HW_MIC_01       ,INPUT);
  pinMode( PIN_HW_SEN_MET_LUZ  ,INPUT);
  pinMode( PIN_HW_MTDI_INFO    ,INPUT);
  pinMode( PIN_HW_ICC_SENSE_12P,INPUT);
  pinMode( PIN_HW_ICC_SENSE_5VP,INPUT);

  pinMode( PIN_HW_INT_OFF_PETICION,INPUT);
  pinMode( PIN_HW_INT_SQW         ,INPUT);

  pinMode( PIN_HW_POW_CNX_A0,OUTPUT);
  pinMode( PIN_HW_POW_CNX_A1,OUTPUT);
  pinMode( PIN_HW_POW_CNX_A2,OUTPUT);

  pinMode( PIN_HW_DTMF_D0,INPUT);
  pinMode( PIN_HW_DTMF_D1,INPUT);
  pinMode( PIN_HW_DTMF_D2,INPUT);
  pinMode( PIN_HW_DTMF_D3,INPUT);
  pinMode( PIN_HW_DTMF_DV,INPUT);

  pinMode( PIN_HW_CNX_DEBUG,INPUT);

  pinMode( PIN_HW_BAT_N25  ,INPUT);
  pinMode( PIN_HW_BAT_N50  ,INPUT);
  pinMode( PIN_HW_BAT_N75  ,INPUT);
  pinMode( PIN_HW_BAT_N100 ,INPUT);

  pinMode( PIN_HW_SERVO_HOR,OUTPUT);
  pinMode( PIN_HW_SERVO_VER,OUTPUT);
  
  pinMode( PIN_HW_FAN,OUTPUT);
  
  pinMode( PIN_HW_LED_POS ,OUTPUT);
  pinMode( PIN_HW_LED_DER ,OUTPUT);
  pinMode( PIN_HW_LED_IZQ ,OUTPUT);
  pinMode( PIN_HW_LED_FOCO,OUTPUT);

  pinMode( PIN_HW_MTI_DIR,OUTPUT);
  pinMode( PIN_HW_MTI_RST,OUTPUT);
  pinMode( PIN_HW_MTI_PWM,OUTPUT);

  pinMode( PIN_HW_MTD_DIR,OUTPUT);
  pinMode( PIN_HW_MTD_RST,OUTPUT);
  pinMode( PIN_HW_MTD_PWM,OUTPUT);

  pinMode( PIN_HW_MTDI_SEL_A,OUTPUT);
  pinMode( PIN_HW_MTDI_SEL_B,OUTPUT);
  pinMode( PIN_HW_MTDI_SEL_C,OUTPUT);

  pinMode( PIN_HW_POW_PC_1,OUTPUT);

  // ---------------------------------------------------------
  //
  //       !!! Estas variables se INICIALIZAN AQUI !!!
  //
  // ---------------------------------------------------------

  GLOBAL_FlgDebug            = false;  
  GLOBAL_FlgStatusPC         = IDE_STATUS_PC_INI_ON;
  GLOBAL_FlgModoAvance       = IDE_MODO_AVANCE_CON_PROTECCION;
  GLOBAL_FlgModoAvanceEvento = IDE_EVENTO_OK;
  GLOBAL_Timer_Ctrl_PC       = 0L;
  GLOBAL_Timer_DispD_PC      = 0;
  GLOBAL_Timer_DispF_PC      = true;

  
  // ---------------------------------------------------------
  //
  // Inicializacion de variables, objetos Globales y elementos
  //
  //
  // ---------------------------------------------------------

  analogReference(DEFAULT);
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
     
  Wire.begin();
  mDer.begin();
  mIzq.begin();
  myDisplay.begin();
  myDisplay.setBrightness(15);
  sensor_USS.begin();
  sensor_GPS.begin();
  sensor_EMC.begin();
  sensor_RAZOR.begin();
   
  gc.begin();

  
  // ---------------------------------------------------------
  // Interrupciones:
  //
  // INT 0:    Boton Power OFF
  // Funcion:  INT_power_OFF()
  // Variable: GLOBAL_FlgPower_OFF
  //           Variable actualizada por esta funcion
  //
  // INT 1:    Señal generada desde el RTC
  // Funcion:  INT_rtc_SQW()
  // 
  // ---------------------------------------------------------
  
  attachInterrupt(0, INT_power_OFF, RISING);
  attachInterrupt(1, INT_rtc_SQW  , RISING);
     
  // ---------------------------------------------------------
  //
  //        Inicializacion de puertos serie
  //
  // . Serial0 Gestor de comandos, se inicializa en gc->begin()
  //           Comunicacion entre Arduino y PC
  // . Serial1 GPS  , se inicializa en sensor_GPS.begin()
  // . Serial2 RAZOR, se inicializa en sensor_RAZOR.begin()
  // . Serial3 9600 , puerto de DEBUG, 9600
  //
  // ---------------------------------------------------------
  
  Serial3.begin(IDE_SERIAL_TRX_DEBUG);   // Puerto de DEBUG, ver comentario de la variable GLOBAL_FlgDebug
    
 

  // ---------------------------------------------------------
  //                        IMPORTANTE
  // !!! NO mover de aqui estas inicializaciones
  // Para  version  Funcional, comentar  todas  las lineas que 
  // puedan aparecer debajo de este comentario y dejar SOLO:
  //
  //       uf_sys.begin();
  //
  // ---------------------------------------------------------  
 
  uf_sys.begin();                                          

  // ---------------------------------------------------------  
  // Utilidad para escanear el bus I2C
  // DESCOMENTAR para probar los sensore conectados por I2C
  // ---------------------------------------------------------  
  
  // UTIL_Scanner_I2C();

  // ---------------------------------------------------------  
  // Atencion:
  // Cuando se instala un  nuevo Arduino MEGA, es  conveniente
  // descomentar  esta  llamada  UNA SOLA  VEZ para iniciar la
  // Variable EEPROM a  un  valor  conocido, despues  se  DEBE 
  // dejar comentada
  // ---------------------------------------------------------  
  
  // uf_sys.set_NUM_RC(1);

     
 }





// ---------------------------------------------------------
//
// void loop()
//      Funcion principal para mantener funcionando iROB-EA
//    
// ---------------------------------------------------------

void loop(void)
{
  
  // ---------------------------------------------------------
  // Actualizacion de Timers etc de uf_sys
  // ---------------------------------------------------------
  
  uf_sys.timers();
  
 
  // -------------------------------------------------------
  //
  //                BLOQUE GENERAL DE PROGRAMA
  //
  // -------------------------------------------------------
                    
  // -------------------------------------------------------
  //
  //                    GESTOR DE COMANDOS
  //
  // La funcion exeGesComando ejecuta el gestor de comandos.
  // Si se ha recibido algo en el puerto serie lo  procesa y
  // envia el resultado obtenido.
  // TODAS las funciones asociadas a comandos se  encuentran 
  // en el fichero iROB-EA_CMD.ino
  //
  // Si no se ha recibido nada retorna inmediatamente.
  //
  // Esta funcion retorna:
  // . IDE_BUFF_RX_OK    Se ha recibdo algo valido ( un 
  //                     comando y se ha ejecutado )
  // . IDE_BUFF_RX_ER    Se ha recibido algo erroneo. 
  // . IDE_BUFF_RX_VACIO NO se ha recibido nada
  //
  // Estos defines se encuentran en Gescom_MEGA2560_V3.h
  //
  // -------------------------------------------------------
       
  gc.exeGesComando();

  // -------------------------------------------------------
  //
  //       Proceso de encendido/apagado/Bucle activo
  //
  // - Si el proceso de encendido finaliza correctamente:
  //   GLOBAL_FlgStatusPC = IDE_STATUS_PC_OK = procesoActivo()
  //
  // - Si el proceso de apagado se solicita  actuando  sobre
  //   el pulsador: 
  //   GLOBAL_FlgStatusPC = IDE_STATUS_PC_INI_OFF
  //
  // -------------------------------------------------------

  switch( GLOBAL_FlgStatusPC )
        {
          case ( IDE_STATUS_PC_INI_ON ):
               { // ----------------------------------------
                 //    El PC esta apagado, se acaba de
                 //          arrancar el Robot
                 //
                 // Se inicia el proceso de encendido.
                 // La funcion pc_ON() inicia el encendido y
                 // cambia el valor de GLOBAL_FlgStatusPC  a
                 // GLOBAL_FlgStatusPC = IDE_STATUS_PC_START
                 // ----------------------------------------
                 FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_WAIT,0);                 
                 pc_ON();
                 break;
               }
          case ( IDE_STATUS_PC_START ):
               { // ----------------------------------------
                 //         El PC esta arrancando
                 // Temporiza esperando respuesta  desde  el
                 // PC.
                 //
                 // . Si el PC  se  inicializa correctamente
                 //   se recibira un comando desde el  PC en
                 // la funcion de comandos cmd_Comando_C_STPC()
                 // con el cnv_Param01 = IDE_PARAM_ACT y esa
                 // funcion cambiara el estado de la 
                 // variable 
                 // GLOBAL_FlgStatusPC =  IDE_STATUS_PC_ON
                 //
                 // . Si se agota el tiempo de espera  se pasa
                 // GLOBAL_FlgStatusPC = IDE_STATUS_PC_ON_ERROR
                 //
                 // ----------------------------------------
                 if ( (unsigned long int)(millis()-GLOBAL_Timer_Ctrl_PC)>=IDE_PC_POWER_ON_TIMEOUT  )
                    { // ------------------------------------------
                      // Superado el tiempo maximo  de  espera para
                      // que el PC comunique que  se  ha encendido,
                      // NO se ha recibido desde  el  PC el comando 
                      // #####1001070000E0001 que indicaria  que ha
                      // arrancado correctamente, se indica error y
                      // se cambia GLOBAL_FlgStatusPC
                      // ------------------------------------------
                      FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_ER_000,0);
                      GLOBAL_FlgStatusPC = IDE_STATUS_PC_ON_ERROR;
                    }
                 else
                    { // ------------------------------------------
                      // Muestra tiempo de espera restante
                      // ------------------------------------------
                      displayTimerInicio_PC();
                    } 
                 break;
               }
     
          case ( IDE_STATUS_PC_ON ):
               { // ----------------------------------------
                 //    Se ha recibido desde el PC la
                 //  confirmacion de encendido correcto.
                 // GLOBAL_FlgStatusPC = IDE_STATUS_PC_OK
                 // ----------------------------------------
                 FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OK ,(IDE_PAUSA_GENERAL*4));
                 FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_CLS,0);
                 GLOBAL_FlgStatusPC = IDE_STATUS_PC_OK;
                 break;
               }
          case ( IDE_STATUS_PC_OK ):
               { // ----------------------------------------
                 // Finalizado  correctamente  el proceso de 
                 // encendido del PC.
                 // Bucle Activo
                 // Aqui  se  deben  incluir todas las cosas
                 // que se deben ejecutar en el modo  normal
                 // de funcionamiento.
                 // ----------------------------------------
                 procesoActivo();
                 break;
               }
          case ( IDE_STATUS_PC_INI_OFF ):
               { // ----------------------------------------
                 //         Se ha pulsado el boton de
                 //             encendido/apagado
                 // Se inicia el proceso de  apagado del  PC
                 // Independientemente  del   resultado  del 
                 // proceso de apagado del PC , se  pasara a
                 // GLOBAL_FlgStatusPC = IDE_STATUS_PC_OFF
                 // ----------------------------------------
                 FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_DOWN,0);
                 pc_OFF();
                 break;
               }          
          case ( IDE_STATUS_PC_DOWN ):
               { // ----------------------------------------
                 // Proceso de apagado del Robot
                 //
                 // ----------------------------------------
                 if ( (unsigned long int)(millis()-GLOBAL_Timer_Ctrl_PC)>=IDE_PC_POWER_OFF_TIMEOUT  )
                    { // ------------------------------------------
                      // Superado el  tiempo  maximo de espera para
                      // detectar el apagado del PC. 
                      // Se indica error y se cambia GLOBAL_FlgStatusPC
                      // para apagar fisicamente el  Robot , aunque 
                      // el PC no se haya apagado correctamente
                      // ------------------------------------------
                      FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_ER_001,(IDE_PAUSA_GENERAL*5));
                      GLOBAL_FlgStatusPC = IDE_STATUS_PC_OFF;
                    }
                 else
                    { // ------------------------------------------
                      // Mide la corriente consumida por el PC para
                      // detectar cuando se apaga
                      // ------------------------------------------
                      if ( getIcc5VP()==false )
                         { // ------------------------------------------
                           // La corriente medida con el sensor asociado
                           // a la alimentacion del PC determina  que se
                           // ha apagado.
                           // Se indica ok y se cambia GLOBAL_FlgStatusPC
                           // para apagar fisicamente el Robot
                           // ------------------------------------------
                           FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OK,(IDE_PAUSA_GENERAL*5));
                           GLOBAL_FlgStatusPC = IDE_STATUS_PC_OFF;
                         }
                    }

                 break;
               }
          case ( IDE_STATUS_PC_OFF ):
               { // ----------------------------------------
                 // Apagado fisico del Robot -)
                 // ----------------------------------------
                 uf_sys.power_OFF();
                 break;
               }
          case ( IDE_STATUS_PC_ON_ERROR ):
               { // ----------------------------------------
                 // El PC no ha  podido  encenderse, se debe
                 // dejar la alimentacion conectada para que
                 // desde el exterior , via teclado/Raton se
                 // pueda determinar el fallo
                 // ----------------------------------------

 
                 break;
               }     
        }
  
}



// ---------------------------------------------------------
//
// void pc_ON(void)
// Efectua las operaciones necesarias para  encender el PC y
// cambia el estado de la variable global GLOBAL_FlgStatusPC
// al valor: 
//    GLOBAL_FlgStatusPC = IDE_STATUS_PC_START
//
// ---------------------------------------------------------

void pc_ON(void)
{
  unsigned long int t;
  
  // ---------------------------------------------------------
  // 1 - Conecta el rele de alimentacion (5VP)
  // 2 - Espera x segundos a que el PC se estabilice.
  // 3 - Activa el pulsador de encendido, durante x seg
  // 4 - Cambia el estado de GLOBAL_FlgStatusPC = IDE_STATUS_PC_START
  // 5 - Inicia la variable de Timer que se actualiza  con  la 
  //     interruptor del RTC
  // 6 - Inicializa los Timers de espera a que el PC comunique 
  //     que ha arrancado, enviado el comando #####1001070000E0001
  //     al Arduino
  // ---------------------------------------------------------
   
  uf_sys.rele(IDE_RELE_5VP,IDE_RELE_ACTIVAR);
 
  t = millis();
  while( (millis()-t)<IDE_PC_POWER_INICIO )
       { // ------------------------------------------
         // Bucle  de  espera para que el HW del PC se
         // inicie correctamente antes de solicitar su
         // encendido con el pulsador
         // ------------------------------------------
        
       }

  uf_sys.pulsador_PC(IDE_PC_POWER_PULSADOR_ON);

  GLOBAL_FlgStatusPC    = IDE_STATUS_PC_START;
  GLOBAL_Timer_DispD_PC = int(IDE_PC_POWER_ON_TIMEOUT / 1000);
  GLOBAL_Timer_DispF_PC = true;
  GLOBAL_Timer_Ctrl_PC  = millis();
    
}



// ---------------------------------------------------------
//
// void pc_OFF(void)
// Efectua las operaciones necesarias para  apagar el PC.
// 1 - Activa el pulsador de encendido/apagado del PC, SOLO 
//     si se determina que el PC esta encendido
// 2 - Cambia el estado de GLOBAL_FlgStatusPC = IDE_STATUS_PC_DOWN
// 3 - Inicializa el Timer de espera a que el PC se apague
// ---------------------------------------------------------

void pc_OFF(void)
{
  if ( getIcc5VP()==true )
     { // ----------------------------------------------------
       // Hay consumo de corriente, luego el PC esta encendido
       // se actua sobre el pulsador del PC para apagarlo pero
       // SOLO se debe actuar sobre  este  pulsador cuando  el
       // PC esta encendido porque sino lo que se consigue  es
       // lo contrario, encenderlo -)
       // Esto se hace asi porque existe la posibilidad de que
       // el PC se pueda apagar directamente por  intervencion
       // del usuario que remotamente esta controlando el Robot
       // actuando desde alguna de las aplicaciones que ejecuta
       // ( web, apps etc)
       // ----------------------------------------------------
       uf_sys.pulsador_PC(IDE_PC_POWER_PULSADOR_OFF);                       
     }

  GLOBAL_FlgStatusPC = IDE_STATUS_PC_DOWN;
  
  GLOBAL_Timer_Ctrl_PC = millis();

}



// ---------------------------------------------------------
//
// void procesoActivo(void)
// 
// Funcion  para  manter  activas  las o peraciones precisas
// durante el funcionamiento del Robot
// 
//
// ---------------------------------------------------------

void procesoActivo(void)
{
  unsigned int sup;
  int          obj;
      
  if ( GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_CON_PROTECCION )
     { // -------------------------------------------------------
       // El modo de proteccion esta activado, esto implica: 
       //
       // 1 - Deteccion de suelo en modo avance
       //     Paro si existe peligro
       //
       // 2 - Deteccion de objetos (ultrasonidos) en modo avance
       //     Paro si existe peligro
       //
       // 2 - Deteccion de obstaculos (por sobreconsumo) en  modo
       //     avance
       //     Paro si existe peligro
       //
       // Al activar este modo, la velocidad esta LIMITADA permanentemente
       // ver el comando cmd_Comando_CM_CTR(GESCOM_DATA* gd), en
       // iROB-EA_CMD.ino
       //
       // ------------------------------------------------------
              
       sup = sensor_USS.get_Superficie();
       if ( sup<IDE_EVENTO_TRIGGER_SUELO )  { bitSet  (GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_SUELO); }
       else                                 { bitClear(GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_SUELO); }

       obj = sensor_USS.get_DER();
       if ( obj<IDE_EVENTO_TRIGGER_OBJETO ) { bitSet  (GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_OBJETO_DERECHA); }
       else                                 { bitClear(GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_OBJETO_DERECHA); }
       
       obj = sensor_USS.get_IZQ();
       if ( obj<IDE_EVENTO_TRIGGER_OBJETO ) { bitSet  (GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_OBJETO_IZQUIERDA); }
       else                                 { bitClear(GLOBAL_FlgModoAvanceEvento, IDE_EVENTO_OBJETO_IZQUIERDA); }

       if ( GLOBAL_FlgModoAvanceEvento!=IDE_EVENTO_OK )
          { // -------------------------------------------------
            // Detectada alguna incidencia, para los motores
            // -------------------------------------------------
            mDer.paro();
            mIzq.paro();
          }
     }




  
}



// ---------------------------------------------------------
//
// byte getIcc5VP(void)
// Mide la corriente  consumida por el PC para determinar si
// esta encendido o no.
// Retrona:
// . true  El PC esta encendido
// . false El PC esta apagado
//
// Notas:
// . Cuando el PC Stick esta APAGADO, su consumo es inferior
//   a  100mA ( 68mA medidos con multimetro),  situacion  de 
//   standby. 
//
// . Cuando el PC Stick esta  funcionando, su  consumo es de 
//   entorno a 500 ... 800mA
//
// ---------------------------------------------------------

byte getIcc5VP(void)
{
  float iccMedida;
  byte  resultado;

  iccMedida = uf_sys.get_Corriente(IDE_ICC_5VP);


  if ( iccMedida<IDE_PC_POWER_ICC_OFF ) { resultado = false; }
  else                                  { resultado = true;  }

  return(resultado ); 
}



// ---------------------------------------------------------
//
// void INT_power_OFF(void)
// Funcion conectada a  la  interrupcion  0 para capturar la 
// pulsacion del pulsador ON/OFF, que se actua para  iniciar
// y apagar el Robot. 
// La interrupcion se conecta al iniciar el arduino para poder
// capturar la pulsacion del pulsador y poder APAGAR el Robot
// cuando el Robot esta apagado el pulsador ENCIENDE el Robot
// via Hardware.
// Hay  que  mantener el pulsador actuado durante unos 10 seg
// para iniciar el apagado del Robot.
// ---------------------------------------------------------

void INT_power_OFF(void)
{
  if ( (GLOBAL_FlgStatusPC!=IDE_STATUS_PC_INI_ON) && (GLOBAL_FlgStatusPC!=IDE_STATUS_PC_START) && (GLOBAL_FlgStatusPC!=IDE_STATUS_PC_ON) )
     { // -------------------------------------------------------
       // solo se permite si NO se esta inicializando el PC Stick
       // -------------------------------------------------------
       GLOBAL_FlgStatusPC = IDE_STATUS_PC_INI_OFF;
     }
}


// ---------------------------------------------------------
//
// void INT_rtc_SQW(void)
// Funcion conectada a  la  interrupcion 1 para  capturar la 
// señal que genera el reloj de tiempo real, modulo 
//
// ---------------------------------------------------------

void INT_rtc_SQW(void)
{
   GLOBAL_Timer_DispF_PC = true;
  
}


// ---------------------------------------------------------
//
// void displayTimerInicio_PC(void)
// Actualiza y visualiza en el dsipaly el valor de la variable
// GLOBAL_Timer_INI_PC
// ---------------------------------------------------------

void displayTimerInicio_PC(void)
{
   char sBuff[IDE_MAX_DISPLAY_CAR+1];
  
   if ( (GLOBAL_Timer_DispF_PC==true) && (GLOBAL_Timer_DispD_PC>0) ) 
      {
        GLOBAL_Timer_DispF_PC = false;
        sprintf(sBuff,"T%3d",GLOBAL_Timer_DispD_PC);
        FNG_DisplayMsg(sBuff,0);
        GLOBAL_Timer_DispD_PC--;
      }
}


// ---------------------------------------------------------
//
// byte FNG_DisplayMsgPROGMEM(const char* msg,unsigned int pausa)
//
// Funcion para mostrar mensajes en  el  display  cuando los 
// mensajes son CONSTANTES de memoria
//
// Ver "https://www.arduino.cc/en/Reference/PROGMEM"
// 
// ---------------------------------------------------------
 
byte FNG_DisplayMsgPROGMEM( const char* msgP,unsigned int pausa)
{
  byte resultado;
  char buff [IDE_MAX_DISPLAY_CAR+1];
  char c;
  byte ind;
  byte max;


  resultado = false;
  max       = strlen_P(msgP); 
  ind       = 0;

  if ( max<=IDE_MAX_DISPLAY_CAR)
     {  

       for ( ;ind<max; )
           {
             c = pgm_read_byte_near(msgP);
             buff[ind++] = c;
             buff[ind  ] = '\0';
             msgP++;
           }

       myDisplay.home();
       myDisplay.print(buff);
       resultado = true;
       
       if ( pausa>0 )
          {
            FNG_Pausa(pausa); 
          }
     }
     
  return (resultado) ;  
}


// ---------------------------------------------------------
//
// byte FNG_DisplayMsg(char* msg,unsigned int pausa)
//
// Funcion para mostrar mensajes en  el  display  cuando los 
// mensajes son creados dinamicamente durante la ejecucion
// 
// ---------------------------------------------------------
 
byte FNG_DisplayMsg(char* msg,unsigned int pausa)
{
  byte  resultado;
  

  resultado = false;

  if ( strlen(msg)<=IDE_MAX_DISPLAY_CAR)
     {    
       myDisplay.home();
       myDisplay.print(msg);
       resultado = true;
       
       if ( pausa>0 )
          {
            FNG_Pausa(pausa); 
          }
     }
     
  return (resultado) ;  
}


// ---------------------------------------------------------
//
// void FNG_Pausa(unsigned int pausa)
// Genera una pausa de los milisegundos indicados
//
// ---------------------------------------------------------

void FNG_Pausa(unsigned int pausa)
{
  unsigned long int tIni;
  
  tIni = millis();
  while ( 1 )
        { 
          if ( (unsigned int)(millis()-tIni)>= pausa )
             {
               break; 
             }

        }
}




// ---------------------------------------------------------
//
// void UTIL_Scanner_I2C (void)
// Utilidad  para  descubrir dispositivos conecatados al bus
// I2C
// ---------------------------------------------------------

void UTIL_Scanner_I2C (void)
{

  byte error;
  byte address;
  int  nDevices;
  
  Serial3.println("Scanning I2C...");
  
  while ( true )
        {
          nDevices = 0;
          for ( address = 1; address < 127; address++ )
              { // Uses the return value of the Write.endTransmisstion to see if
                // a device did acknowledge to the address.
                Wire.beginTransmission(address);
                error = Wire.endTransmission();
   
                if ( error==0 )
                   {
                     Serial3.print("I2C Device found at address 0x");
                     if (address<16) { Serial3.print("0"); }
                     Serial3.println(address,HEX);
                     nDevices++;
                   }
                else if ( error==4 )
                   {
                     Serial3.print("Unknown error at address 0x");
                     if (address<16) { Serial3.print("0"); }
                     Serial3.println(address,HEX);
                   }    
              }
      
          if (nDevices == 0) { Serial3.println("No I2C devices found\n"); }
          else               { Serial3.println("Done\n");                 }
          delay(3000);
        }
 
}
