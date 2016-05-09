
//! ---------------------------------------------------------
//!
//! @mainpage 
//!                 
//! @brief   Proyecto: iROB-EA
//! @date    Fecha:    Abril 2015
//! @author  AAL
//!
//! @remarks Hardware Arduino MEGA 2560\n
//!
//! @version Versión de SW 1.0
//! @version Versión de IDE Arduino: 1.6.4
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
//! @warning REVISADO 08/04/2016      
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
#include "MOTOR_FDS5672.h"
#include "SENSOR_US.h"
#include "UF_BAT.h"
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
// . sensorUS     Objeto para manejo de los sensores de US
// . uf_bat       Objeto para manejo de funcionalidades bateria
// . mlx          Objeto para manejar el sensor MLX90614
// . rtc          Objeto para manejar el reloj de tiempo real 
// . gc           Objeto que implementa el gestor de comandos
// . flgPower_OFF Flag para control  del  flujo  principal en 
//                la funcion loop.
// . powerMotores Flag para control el estado de la alimentacion
//                de los motores
//
//
// ---------------------------------------------------------

UF_SYS            uf_sys    = UF_SYS();                         // Implementa la funcionalidad relacionada con la UF_SYS

MOTOR_FDS5672     mDer      = MOTOR_FDS5672( PIN_HW_MDER_DIR ,
                                             PIN_HW_MDER_PWM ,
                                             PIN_HW_MDER_RST ,
                                             PIN_HW_MDER_FF1 ,
                                             PIN_HW_MDER_FF2 ,
                                             PIN_HW_MDER_ICC
                                           );                   // Implementa el control del motor derecho
MOTOR_FDS5672     mIzq      = MOTOR_FDS5672( PIN_HW_MIZQ_DIR ,
                                             PIN_HW_MIZQ_PWM ,
                                             PIN_HW_MIZQ_RST ,
                                             PIN_HW_MIZQ_FF1 ,
                                             PIN_HW_MIZQ_FF2 ,
                                             PIN_HW_MIZQ_ICC
                                           );                   // Implementa el control del motor izquierdo

LedDisplay        myDisplay = LedDisplay( PIN_HW_HCMS_DATA  ,
                                          PIN_HW_HCMS_RS    ,
                                          PIN_HW_HCMS_CLK   ,
                                          PIN_HW_HCMS_CE    ,
                                          PIN_HW_HCMS_RESET ,
                                          4
                                        );                     // Implementa el control del display
                                        
SENSOR_US         sensorUS  = SENSOR_US (PIN_HW_USR_DERECHO_S  ,
                                         PIN_HW_USR_IZQUIERDO_S,
                                         PIN_HW_USR_DERECHO_C  ,
                                         PIN_HW_USR_IZQUIERDO_C 
                                        );                      // Implementa el control de los sensores de ultrasonidos

UF_BAT               uf_bat = UF_BAT    (PIN_HW_BAT_INBP    ,
                                         PIN_HW_BAT_INB0    ,
                                         PIN_HW_BAT_INB1    ,
                                         PIN_HW_BAT_INB2    ,
                                         PIN_HW_BAT_INBS    ,
                                         PIN_HW_BAT_CHG_PPAK,
                                         PIN_HW_BAT_CHG_LIPO
                                        );


Adafruit_MLX90614 mlx       = Adafruit_MLX90614();              // Implementa el sensor de temperatura MELEXIS 90614
RTC_DS1307        rtc;                                          // Reloj de tiempo real
GESCOM3           gc        = GESCOM3( IDE_SERIAL_0        ,
                                       false               ,
                                       IDE_DISPOSITIVO_R00 ,
                                       IDE_SERIAL_TRX_9600
                                     );                         // Gestor de comandos
volatile byte     flgPower_OFF;                                 // Flag actualizado desde la funcion asociada a la INT 0 ( Boton de OFF) 
         byte     powerMotores;                                 // True:  La alimentación de los motores    esta conectada  
                                                                // False: La alimentación de los motores NO esta conectada


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
  // . Los pines de control de los sensores de baterias
  //   NO se inicializan aqui porque ya lo hace el constructor
  //   de la clase SENSOR_BAT
  //
  //
  // . El pin PIN_HW_OFF_PETICION es la entrada de INT 0, no 
  //   es necesario inicializar este pin con pinMode
  //
  // ---------------------------------------------------------
 
  // ---------------------------------------------------------
  //
  // Inicializacion de los pines I/O (MODO)
  //
  // ---------------------------------------------------------


  pinMode(PIN_HW_DOG_DONE ,OUTPUT);
  pinMode(PIN_HW_DOG_SFLAG,INPUT);
          
  pinMode(PIN_HW_POW_CNX_A0,OUTPUT);
  pinMode(PIN_HW_POW_CNX_A1,OUTPUT);
  pinMode(PIN_HW_POW_CNX_A2,OUTPUT);

  pinMode(PIN_HW_DTMF_D0,INPUT);
  pinMode(PIN_HW_DTMF_D1,INPUT);
  pinMode(PIN_HW_DTMF_D2,INPUT);
  pinMode(PIN_HW_DTMF_D3,INPUT);
  pinMode(PIN_HW_DTMF_DV,INPUT);

  pinMode(PIN_HW_CNX_DEBUG,INPUT);

  pinMode(PIN_HW_MIC_01,INPUT);

  pinMode(PIN_HW_BAT_CHG_PPAK,INPUT);
  pinMode(PIN_HW_BAT_CHG_LIPO,INPUT);
 
  
  pinMode(PIN_HW_LED_BDEL,OUTPUT);
  pinMode(PIN_HW_LED_BDET,OUTPUT);
  pinMode(PIN_HW_LED_RDET,OUTPUT);

  pinMode(PIN_HW_SEN_MET_LUZ ,INPUT);
  pinMode(PIN_HW_DTR_RAZOR_1 ,OUTPUT);

  
  pinMode(PIN_HW_IR01,INPUT);



  // ---------------------------------------------------------
  //
  // Inicializacion de los pines I/O (ESTADO)
  //
  // ---------------------------------------------------------
 
  digitalWrite(PIN_HW_DOG_DONE,LOW);

  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW); 
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  digitalWrite(A4,LOW);
  digitalWrite(A5,LOW);
  digitalWrite(A6,LOW);
  digitalWrite(A7,LOW);
  digitalWrite(A8,LOW);
  digitalWrite(A9,LOW);

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
  // .  mlx.begin()
  // .  sensorUS.inicio()
  // .  sensorBAT.inicio()
  // .  myDisplay.begin()
  // .  flgPower_OFF
  //
  // ---------------------------------------------------------
     
  Wire.begin();
  
  rtc.begin();
  mlx.begin();  
   gc.begin();
  sensorUS.inicio();
  uf_bat.inicio();
  myDisplay.begin();
  myDisplay.setBrightness(15);

  flgPower_OFF = false;
  FNG_SetPowerMotores(false);

  // ---------------------------------------------------------
  // Interrupciones:
  // INT 0  --> Boton Power OFF
  // ---------------------------------------------------------
  
  attachInterrupt(0, INT_power_OFF, RISING);


  // ---------------------------------------------------------
  // Resto: Desactivar todos los reles
  //
  // ---------------------------------------------------------

  uf_sys.rele(IDE_RELE_CPU_APL,IDE_RELE_DESACTIVAR);
  uf_sys.rele(IDE_RELE_CAMARA ,IDE_RELE_DESACTIVAR);


  
  
  analogReference(DEFAULT); // SIEMPRE se utiliza DEFAULT 

  // ---------------------------------------------------------
  //
  // Inicializacion de puertos serie
  // MENOS Serial0 que está asociado con el gestor de comandos
  // y se inicializa con gc->begin()
  //
  // ---------------------------------------------------------
  
  Serial1.begin(IDE_SERIAL_TRX_9600);   // Puerto de DEBUG
    
 

  // ---------------------------------------------------------
  //                        IMPORTANTE
  //
  // Para  version  Funcional, comentar  todas  las lineas que 
  // puedan aparecer debajo de este comentario y dejar SOLO:
  //
  //       uf_sys.inicio();
  //       uf_sys.watchDog_Sincro();
  //
  // ---------------------------------------------------------  
   
 
  uf_sys.watchDog_Sincro();                 // IMPORTANTE: Esta funcion se DEBE llamar en este orden, no mover  
                                            // Si sale de esta funcion es porque el arranque ha sido correcto
                                            // Si NO sale de esta funcion es porque:
                                            // A) NO se ha introducido la clave correcta
                                            // B) Esta bloqueado y por eso se ha auto-apagado
                                            // C) Se ha pulsado el boton de OFF

  uf_sys.inicio();                                          

  //QUITAR LUEGO DE QUE SE EJECUTE UNA VEZ
  //uf_sys.set_RECARGAS(0);
  


  #ifdef APP_MODO_DEBUG
  t = millis() - t;
  Serial1.print(IDE_STR_DEBUG_EXE);
  Serial1.print(t,DEC);
  Serial1.println(IDE_STR_MSEG);
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
  byte vAux;
  

  // ---------------------------------------------------------
  // A) Generacion del pulso de latido, reset del watchDog
  // B) Actualizacion de Timers etc de uf_sys
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  uf_sys.timers();

  
  if ( flgPower_OFF==false )
     { // ---------------------------------------------------------
       //
       //                BLOQUE GENERAL DE PROGRAMA
       //
       // El  tiempo  maximo de  ejecucion  de este bloque NO puede
       // superar el tiempo maximo del watchdog.
       // - El tiempo de watchdog se fija con unos puentes (TPL5000)
       // - Tiempo fijado ACTUAL: 16 SEGUNDOS
       //
       // IMPORTANTE:
       // Si se añade codigo aqui y el tiempo necesario para ejecutar
       // este bloque es mayor del tiempode watchdog, se debe elegir
       // mediante los puentes un tiempo superior de watchdog
       //
       // ---------------------------------------------------------
   
       // ---------------------------------------------------------
       //
       //                            1
       //
       //                   CONTROL DE LAS BATERIAS
       //
       // ---------------------------------------------------------

       uf_bat.ctrl_Baterias();

       // ---------------------------------------------------------
       //
       //                            2
       //
       //                  CONTROL EXTERNO (DEBUG)
       //
       // ---------------------------------------------------------
       vAux = uf_sys.get_FlgDebug();
       if (vAux==true) 
          {
            // mDer.paro();
            // mIzq.paro();
          }
       else
          { 


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

       //#ifdef APP_MODO_DEBUG
       //uf_sys.getTimeExe(true);
       //#endif
       
       gc.exeGesComando();
       
       //#ifdef APP_MODO_DEBUG
       //uf_sys.getTimeExe(false);
       //#endif
       
     





     

      //uf_sys.get_Corriente(A1); 
      //delay(1000);
       
  
     }
  else
     { // ---------------------------------------------------------    
       //
       //                          POWER OFF
       //
       // ANTES se DEBE hacer  todo  lo que proceda antes de apagar
       // Rsapberry etc
       // ---------------------------------------------------------    
      

       // ---------------------------------------------------------
       //
       // Secuencia de apagado
       //
       // ---------------------------------------------------------

       

       
       // ---------------------------------------------------------
       // Mensaje de sistema --> Down
       // ---------------------------------------------------------
    
       FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_DOWN,0);
       Serial1.println(IDE_STR_INICIO_POWER_DOWN);
       uf_sys.miDelay(IDE_OFF_PAUSA);

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
// evento de pulsador ON/OFF pulsado para apagar
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
// En la pausa genera el pulso de control del watchdog
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
          uf_sys.watchDog_DONE();
        }
}



// ---------------------------------------------------------
//
// void FNG_SetPowerMotores(byte estado)
//
// Controla la activacion/desactivacion de la tension de 
// alimentacion de los motores y actualiza el flag "powerMotores"
// 
// ---------------------------------------------------------
 
void FNG_SetPowerMotores(byte estado)
{
    
  if ( estado==false )
     { 
       uf_sys.rele(IDE_RELE_MOTORES,IDE_RELE_DESACTIVAR);
     }
  else
     { if ( powerMotores==false )
          {
            uf_sys.rele(IDE_RELE_MOTORES,IDE_RELE_ACTIVAR);
            FNG_Pausa(IDE_PAUSA_GENERAL);     
          }
     }

  powerMotores = estado;  // Esto lo ultimo
}


