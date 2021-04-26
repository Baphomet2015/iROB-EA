
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
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_MLX90614.h>
#include <EEPROM.h>
#include <LedDisplay.h>
#include "iROB_EA.h"
#include "UF_SYS.h"
//#include "MOTOR_FDS5672.h"
#include "SENSOR_USS.h"
#include <Gescom_MEGA2560_V3.h>
#include <Gescom_MEGA2560_V3_CMD.h>




// ---------------------------------------------------------
//
//         Definicion de Clases y variable GLOBALES
//
//
// . uf_sys       Objeto de manejo de  funcionalidades basicas
// . mDer         Objeto de manejo del motor derecho
// . mIzq         Objeto de manejo del motor izquierdo
// . myDisplay    Objeto para manejear el display de estado
// . sensor_US    Objeto para manejo de los sensores de US
// . sensor_mlx   Objeto para manejar el sensor MLX90614
// . rtc          Objeto para manejar el reloj de tiempo real 
// . gc           Objeto que implementa el gestor de comandos
//
// . flgPower_OFF Flag para control  del  flujo  principal en 
//                la funcion loop.
//
//
// ---------------------------------------------------------

UF_SYS            uf_sys    = UF_SYS();                         // Implementa la funcionalidad relacionada con la UF_SYS

//MOTOR_FDS5672     mDer      = MOTOR_FDS5672( PIN_HW_MDER_DIR , // Implementa el control del motor derecho
//                                             PIN_HW_MDER_PWM ,
//                                             PIN_HW_MDER_RST ,
//                                             PIN_HW_MDER_FF1 ,
//                                             PIN_HW_MDER_FF2 ,
//                                             PIN_HW_MDER_ICC
//                                           );                   
//MOTOR_FDS5672     mIzq      = MOTOR_FDS5672( PIN_HW_MIZQ_DIR ,  // Implementa el control del motor izquierdo
//                                             PIN_HW_MIZQ_PWM ,
//                                             PIN_HW_MIZQ_RST ,
//                                             PIN_HW_MIZQ_FF1 ,
//                                             PIN_HW_MIZQ_FF2 ,
//                                             PIN_HW_MIZQ_ICC
//                                           );                   

LedDisplay        myDisplay = LedDisplay( PIN_HW_HCMS_DATA  ,     // Implementa el control del display
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

//Adafruit_MLX90614 sensor_MLX = Adafruit_MLX90614();             // Implementa el sensor de temperatura MELEXIS 90614
//RTC_DS1307        rtc;                                          // Reloj de tiempo real
//GESCOM3           gc        = GESCOM3( IDE_SERIAL_0        ,
//                                       false               ,
//                                       IDE_DISPOSITIVO_R00 ,
//                                       IDE_SERIAL_TRX_9600
//                                     );                         // Gestor de comandos
volatile byte     flgPower_OFF;                                 // Flag actualizado desde la funcion asociada a la INT 0 (peticion de OFF), ver funcion void INT_power_OFF(void)



// ---------------------------------------------------------
//
// void setup()
//      Funcion para  inicializar  todos  los  sistemas  del
//      iROB-EA 
//
// ---------------------------------------------------------

void setup(void)
{
  #ifdef APP_MODO_DEBUG
  unsigned long int t;
  t = millis();
  #endif

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

  pinMode( PIN_HW_OFF_PETICION,INPUT);

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

  pinMode( PIN_HW_LED_POS,OUTPUT);
  pinMode( PIN_HW_LED_DER,OUTPUT);
  pinMode( PIN_HW_LED_IZQ,OUTPUT);

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
  // Inicializacion de variables, objetos Globales y elementos
  //
  //
  // ---------------------------------------------------------


  // ---------------------------------------------------------
  // Inicio:
  // .  Wire.begin()
  // .  rtc.begin()
  // .   gc.begin()
  // .  sensor_MLX.begin()
  // .  sensor_US.begin()
  // .  myDisplay.begin()
  // .  flgPower_OFF
  //
  // ---------------------------------------------------------
     
  Wire.begin();
  
 // rtc.begin();
 // sensor_MLX.begin();  
 //   gc.begin();
  sensor_USS.begin();
  myDisplay.begin();
  myDisplay.setBrightness(15);

  flgPower_OFF = false;

  // ---------------------------------------------------------
  // Interrupciones:
  // INT 0  --> Boton Power OFF
  // ---------------------------------------------------------
  
  attachInterrupt(0, INT_power_OFF, RISING);

  // ---------------------------------------------------------
  // Resto: 
  //
  // ---------------------------------------------------------


  // ---------------------------------------------------------
  //
  // Inicializacion de puertos serie:
  //
  // . Serial0 ESTÁ asociado con el gestor de comandos y se
  //           inicializa con gc->begin()
  // . Serial1
  // . Serial2
  // . Serial3 9600, Puerto DEBUG
  //
  // ---------------------------------------------------------
  
  Serial3.begin(IDE_SERIAL_TRX_9600);   // Puerto de DEBUG
    
 

  // ---------------------------------------------------------
  //                        IMPORTANTE
  //
  // Para  version  Funcional, comentar  todas  las lineas que 
  // puedan aparecer debajo de este comentario y dejar SOLO:
  //
  //       uf_sys.inicio();
  //
  // ---------------------------------------------------------  

  uf_sys.inicio();                                          

  // ---------------------------------------------------------  
  // QUITAR LUEGO DE QUE SE EJECUTE UNA VEZ
  //uf_sys.set_RECARGAS(0);
  // ---------------------------------------------------------  



  #ifdef APP_MODO_DEBUG
  t = millis() - t;
  Serial3.print(IDE_STR_DEBUG_EXE);
  Serial3.print(t,DEC);
  Serial3.println(IDE_STR_MSEG);
  #endif
       
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
  // A) Actualizacion de Timers etc de uf_sys
  // ---------------------------------------------------------
  
  uf_sys.timers();
  
  if ( flgPower_OFF==false )
     { // ---------------------------------------------------------
       //
       //                BLOQUE GENERAL DE PROGRAMA
       //
       //
       // ---------------------------------------------------------
       
       if (uf_sys.get_FlgDebug()==true) 
          { // ---------------------------------------------------------
            // Conectado conector EXTERNO de depuracion
            // ---------------------------------------------------------
             
          }

       // -------------------------------------------------------
       //
       //                            3
       //
       //                    GESTOR DE COMANDOS
       //
       // La funcion exeGesComando ejecuta el gestor de comandos.
       // Si se ha recibido algo en el puerto serie lo procesa y
       // envia el resultado obtenido.
       // Si no se ha recibido nada retorna inmediatamente.
       //
       // Esta funcion retorna:
       // . IDE_BUFF_RX_OK    Se ha recibdo algo valido ( un 
       //                     comando y se ha ejecutado )
       // . IDE_BUFF_RX_ER    Se ha recibido algo erroneo. 
       // . IDE_BUFF_RX_VACIO NO se ha recibido nada
       //
       // Estos defines se encuentran en gescom.h
       //
       // -------------------------------------------------------

       
       //gc.exeGesComando();
       
      
     





     

       
  
     }
  else
     { // ---------------------------------------------------------    
       //
       //                          POWER OFF
       //
       // ANTES del power OFF se DEBE hacer  todo  lo que proceda
       // Secuencia de apagado
       //
       // ---------------------------------------------------------    
                   
       // ---------------------------------------------------------
       // Mensaje de sistema --> Down
       // ---------------------------------------------------------
       Serial3.println(IDE_STR_INICIO_POWER_DOWN);
       FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_DOWN,(IDE_PAUSA_GENERAL*4));






       // ---------------------------------------------------------
       // Apagado físico (power OFF)
       // ---------------------------------------------------------
       uf_sys.power_OFF();
     }
  
}



// ---------------------------------------------------------
//
// void INT_power_OFF(void)
// Funcion conectada a  la  interrupcion 0 para  capturar el 
// evento de pulsador ON/OFF, que se pulsa para iniciar el 
// apagado del Robot, hay que mantenerlo pulsado unos 10 seg
//
// ---------------------------------------------------------

void INT_power_OFF(void)
{
  
  flgPower_OFF = true;
  
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
