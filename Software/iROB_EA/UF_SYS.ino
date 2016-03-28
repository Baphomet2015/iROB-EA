// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        UF_SYS.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Implmentacion de la clase UF_SYS
//
// Notas:          
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include <EEPROM.h>
#include "iROB_EA.h"
#include "UF_SYS.h"





// ---------------------------------------------------------
//
// UF_SYS::UF_SYS(void)
//         Constructor
//
// ---------------------------------------------------------

UF_SYS::UF_SYS(void)
{
   





}



// ---------------------------------------------------------
//
// void UF_SYS::inicio(void)
// 
//
// ---------------------------------------------------------

void UF_SYS::inicio(void)
{
  byte nIntentos;
  byte modo;
  

  // ---------------------------------------------------------
  //
  // Inicio de componentes e interfaces Arduino
  //
  // ---------------------------------------------------------
  
  // ---------------------------------------------------------
  // Inicio del sistema de encendido/intermitencias de los leds
  // ---------------------------------------------------------
  led_Timer    = IDE_LED_TIMER;
  led_Blk      = LOW;
  led_LED_BDEL = IDE_LED_OFF;     // Led apagado
  led_LED_BDET = IDE_LED_OFF;     // Led apagado
  led_LED_RDET = IDE_LED_OFF;     // Led apagado
  

 
  // ---------------------------------------------------------
  //
  //
  //
  // ---------------------------------------------------------
  
  if ( digitalRead(PIN_HW_DOG_SFLAG)==HIGH )
     { // ---------------------------------------------------------
       //
       //                 ARRANQUE POR WATCHDOG
       //
       // . Reset del watchdog
       // . Modo inicio = IDE_INICIO_WATCHDOG
       // .
       // .
       // .       
       // ---------------------------------------------------------
       modo = IDE_INICIO_WATCHDOG;
       set_MOD_INI(modo);
       display_Datos_EEPROM();
       display_Modo();
       
       watchDog_DONE();
       
       
       
       

     }
  else
     { // ---------------------------------------------------------
       //
       //                    ARRANQUE NORMAL
       //
       // . Se pide codigo de aranque:
       //   A) Correcto -> Modo inicio = IDE_INICIO_POWER ON
       //   B) Fallo    -> Power OFF
       // ---------------------------------------------------------
       modo = IDE_INICIO_POWER_ON;       
       set_MOD_INI(modo);
       display_Datos_EEPROM();
       display_Modo();
       
       if ( secuenciaInicio()==false )
          { // ---------------------------------------------------------
            // NO se puede arrancar --> Power OFF
            // ---------------------------------------------------------
            power_OFF();            
          }
       else          
          { // ---------------------------------------------------------
            // Operaciones de inicializacion
            // ---------------------------------------------------------
            calibra_SensoresIcc();


          }
     }
  
  
}



// ---------------------------------------------------------
//
// byte UF_SYS::secuenciaInicio(void)
// Mantiene actualizados los diferentes timers implementados
// en el objeto
// ---------------------------------------------------------

void UF_SYS::timers(void)
{

 // ---------------------------------------------------------
 //
 // Control de los leds
 //
 // ---------------------------------------------------------

 led_Timer--;
 
 if ( led_Timer<=0L )
    {
      led_Timer = IDE_LED_TIMER;
      if ( led_Blk==LOW ) { led_Blk = HIGH;}
      else                { led_Blk = LOW;}
    } 

 switch (led_LED_BDEL)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_BDEL,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_BDEL,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_BDEL,led_Blk); break; }
        }

 switch (led_LED_BDET)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_BDET,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_BDET,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_BDET,led_Blk); break; }
        }

 switch (led_LED_RDET)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_RDET,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_RDET,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_RDET,led_Blk); break; }
        }


 // ---------------------------------------------------------
 //
 // 
 //
 // ---------------------------------------------------------






}



// ---------------------------------------------------------
//
// byte UF_SYS::secuenciaInicio(void)
// Retorna:
// . false NO se ha podido iniciar:
//         - Falta codigo de arranque
//         - Numero maximo de reintentos
//         - Etc
//         En este caso desde la funcion que la llamó se 
//         debe ir a power OFF.
// . true  Arranque OK en este caso las variables EEPROM:
//         Numero reintentos (EPROM_ADDR_NUM_RC)  = 0
//         Clave actual      (EEPROM_ADDR_CLV_AE) = Clave introducida 
//         Quedan al salir con esos valores
//
// ---------------------------------------------------------

byte UF_SYS::secuenciaInicio(void)
{
  byte resultado;
  byte flgProceso;  
  byte nIntentos;
  char buff[IDE_CLV_MAXL+1];


  resultado  = false;
  flgProceso = false;
  
  while( flgProceso==false )  
       { // ---------------------------------------------------------
         // Bucle de captura de clave
         // ---------------------------------------------------------

         nIntentos  = get_NUM_RC();

         if ( nIntentos<IDE_CLV_MAX_INTENTOS )
            { // ---------------------------------------------------------
              // No se ha alcanzado el numero maximo de reintentos,
              // visualiza en el display nº de intentos
              // ---------------------------------------------------------

              buff[0] = 32;
              buff[1] = 48 + (IDE_CLV_MAX_INTENTOS - nIntentos);
              buff[2] = 43;
              buff[3] = 32;
              buff[4] = 0;
              FNG_DisplayMsg(buff,(IDE_PAUSA_GENERAL*4));
           
              if ( get_CodigoDTMF(buff)==true )         
                 { // ---------------------------------------------------------
                   //
                   // ---------------------------------------------------------

                   set_CLV_AE(buff);
                
                   if ( strcmp(buff,IDE_CLV_AP)==0 ) 
                      { // ---------------------------------------------------------
                        // Clave correcta
                        // ---------------------------------------------------------     
                        resultado  = true;             
                        flgProceso = true;
                        set_NUM_RC(0);
                        FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OK,(IDE_PAUSA_GENERAL*4));
                        FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_ON,(IDE_PAUSA_GENERAL*2));
                      }
                   else
                      { // ---------------------------------------------------------
                        //
                        // ---------------------------------------------------------
                        nIntentos++;
                        set_NUM_RC(nIntentos);
                        if ( nIntentos==IDE_CLV_MAX_INTENTOS ) 
                           {
                             set_CLV_AE(IDE_CLV_AP);
                           }
                        else
                           {   
                             FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_ER,(IDE_PAUSA_GENERAL*4));                
                           }
                      }   
                 }
             else
                {
                  // ---------------------------------------------------------
                  //
                  // ---------------------------------------------------------
                  flgProceso = true; 
                  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OFF,(IDE_PAUSA_GENERAL*4));
                }
            }
         else
            { // ---------------------------------------------------------
              // Mas de tres intentos:
              // Si el define IDE_CLV_AP tien un valor DISTINTO del que 
              // tiene la variable EEPROM EEPROM_ADDR_CLV_AE se trata de 
              // un arranque para desbloquear la clave que se existe
              // Actualmente en la EEPROM y que es incorrecta, la buena 
              // ahora es la que tiene el define IDE_CLV_AP
              // ---------------------------------------------------------
              get_CLV_AE(buff);
              if ( strcmp(IDE_CLV_AP,buff)!=0 ) 
                 { // ---------------------------------------------------------
                   //
                   // Se DESBLOQUEA con una clave nueva
                   //
                   // ---------------------------------------------------------
                   set_NUM_RC(0);
                 }
              else
                 { // ---------------------------------------------------------
                   // La misma clave, se mantiene el bloqueo
                   // ---------------------------------------------------------
                   resultado  = false;
                   flgProceso = true;
                   FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_BLK,(IDE_PAUSA_GENERAL*6));
                 }
            }
       }
 
  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_CLS,0);
  return( resultado );
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_CodigoDTMF(char* buff)
// Permite  introducir  via  DTMF  un  codigo  de  password,
// retorna:
// . True codigo intorducido,   buff --> Codigo
// . False Codigo no intorucido buff --> "    "
//
// ---------------------------------------------------------

byte UF_SYS::get_CodigoDTMF(char* buff)
{
  byte          resultado;
  byte          ind;
  byte          codigo;
  unsigned long tIni;
  
  
  buff[0]   = 42;
  buff[1]   = 42;
  buff[2]   = 42;
  buff[3]   = 42;
  buff[4]   = 0;
  ind       = 0;
  resultado = false;
  tIni      = millis();
  FNG_DisplayMsg(buff,0);
  
  while( 1 )
       {
         codigo = get_DTMF();
                    
         if ( codigo!=32 ) 
            {
              tIni = millis();
              if ( codigo==35 )
                 { // ---------------------------------------------------------
                   // 
                   // ---------------------------------------------------------
                   if ( ind>0 ) 
                      {
                        ind--; 
                      }
                   buff[ind] = 42;                         
                 }
              else
                 { // ---------------------------------------------------------
                   // 
                   // ---------------------------------------------------------
                   buff[ind] = codigo;   
                   ind++;
                 }

              FNG_DisplayMsg(buff,0);
              if ( ind==4 ) 
                 {
                   resultado = true;
                   break; 
                 }
            }

         if ( (unsigned long)(millis()-tIni)>=IDE_CLV_MAX_TIEMPO )
            {
              break; 
            }
            
         watchDog_DONE();
       }
        
  if ( resultado==false )
     {
       buff[0] = 32;
       buff[1] = 32;
       buff[2] = 32;
       buff[3] = 32;
     }
     
  return(resultado);
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_DTMF(void)
// 
//
// ---------------------------------------------------------

byte UF_SYS::get_DTMF(void)
{
  byte          codigo;
  byte          captura;
  unsigned long tIni;
  
  codigo  = 32;
  captura = false;
  tIni    = millis();
        
  while ( 1 )
        {
          if ( digitalRead(PIN_HW_DTMF_DV)==HIGH )
             { // ---------------------------------------------------------
               // Lee el digito introducido
               // ---------------------------------------------------------
               codigo = 0;
               if ( digitalRead(PIN_HW_DTMF_D0)==HIGH ) { bitSet(codigo,0); }
               if ( digitalRead(PIN_HW_DTMF_D1)==HIGH ) { bitSet(codigo,1); }
               if ( digitalRead(PIN_HW_DTMF_D2)==HIGH ) { bitSet(codigo,2); }
               if ( digitalRead(PIN_HW_DTMF_D3)==HIGH ) { bitSet(codigo,3); }
               
               switch( codigo )
                     {
                       case(10): { codigo  = 48; break; } 
                       case(11): { codigo  = 42; break; } 
                       case(12): { codigo  = 35; break; } 
                       case(13): { codigo  = 65; break; } 
                       case(14): { codigo  = 66; break; } 
                       case(15): { codigo  = 67; break; } 
                       case(0):  { codigo  = 68; break; } 
                       default:  { codigo += 48; break; }
                     }

               captura  = true;
             }
          else
             { // ---------------------------------------------------------
               // ---------------------------------------------------------
               if ( captura==true )
                  {
                    break; 
                  }
             }
         
          if ( (unsigned long)(millis()-tIni)>=1000 )
             {
               codigo = 32;
               break; 
             }
        }
  
  return( codigo );
}




//---------------------------------------------------------
//
// void UF_SYS::watchDog_DONE(void)
//      Funcion para generar la señal de latido ( reset) del
//      watchDog, pulso de 1ms
//
// ---------------------------------------------------------

void UF_SYS::watchDog_DONE(void)
{
  digitalWrite(PIN_HW_DOG_DONE,HIGH);
  miDelay(2);
  digitalWrite(PIN_HW_DOG_DONE,LOW);  
}




//---------------------------------------------------------
//
// UF_SYS::watchDog_Sincro(void)
//      SOLO se llama al principio, en la funcion setup()
//      para "saltarse" la primera reentrada por watchdog
//
// ---------------------------------------------------------

void UF_SYS::watchDog_Sincro(void)
{

  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_CLS,0);

  if ( digitalRead(PIN_HW_DOG_SFLAG)==LOW )
     {
       // ---------------------------------------------------------
       //  Arranque normal, espera a sincronizar el watchdog
       // ---------------------------------------------------------
       set_WATCHDOG(IDE_SYSTEM_WATCHDOG);
       FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_INI,0);
       Serial1.println("");
       Serial1.println("");
       Serial1.println("");
       Serial1.println(IDE_STR_INICIO_VERSION);
       Serial1.println(IDE_STR_SINCRO_WATCHDOG_1);
       while ( 1 )
             {
               miDelay(500);
               Serial1.print(".");
             } 
     }          
  else
     {
       // ---------------------------------------------------------
       //  Arranque por Watchdog
       // ---------------------------------------------------------

       watchDog_DONE();

       switch (get_WATCHDOG())
              {
                
                case(IDE_SYSTEM_WATCHDOG): 
                    {
                      set_WATCHDOG(IDE_SYSTEM_OK);
                      Serial1.println(IDE_STR_SINCRO_WATCHDOG_2);
                      break;
                    }
              }
     }  
  
}




// ---------------------------------------------------------
//
// void UF_SYS::power_OFF(void)
// Llamar a esta funcion hace que el iROB-EA
//                 SE APAGUE DE INMEDIATO
//
// ---------------------------------------------------------

void UF_SYS::power_OFF(void)
{

   
  // ---------------------------------------------------------
  // Mensaje de sistema --> OFF
  // ---------------------------------------------------------
  
  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OFF,0);
  Serial1.println(IDE_STR_INICIO_POWER_OFF);
  miDelay(IDE_OFF_PAUSA);

  // ---------------------------------------------------------
  // Como  medida  de  seguridad  se  desactiva  el   rele  de 
  // alimentacion de los motores antes del power OFF
  // ---------------------------------------------------------
  uf_sys.rele(IDE_RELE_MOTORES,IDE_RELE_DESACTIVAR);

  // ---------------------------------------------------------
  // Apagado fisico
  // ---------------------------------------------------------
  
  rele(IDE_RELE_SYS_OFF,true);      
}



// ---------------------------------------------------------
//
// void UF_SYS::rele (byte releID,byte estado)
//      Funcion para activar/desactivar los reles: 
//      RE1, RE2, RE3 y RE4
//
// ---------------------------------------------------------

void UF_SYS::rele (byte releID,byte estado)
{
  
  switch( releID )
        {
          case(IDE_RELE_SYS_OFF):
              { // ---------------------------------------------------------
                // Rele de powerOFF
                // ---------------------------------------------------------
                digitalWrite(PIN_HW_POW_CNX_A0,HIGH);
                digitalWrite(PIN_HW_POW_CNX_A1,LOW);
                digitalWrite(PIN_HW_POW_CNX_A2,LOW);
                break; 
              }
          
          case(IDE_RELE_CPU_APL):
              { // ---------------------------------------------------------
                // Rele de alimentacion de la CPU APL
                // ---------------------------------------------------------
                if ( estado==IDE_RELE_ACTIVAR)
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,LOW);
                     digitalWrite(PIN_HW_POW_CNX_A1,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A2,LOW);
                   }
                else 
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A1,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A2,LOW);
                   }
                break; 
              }

          case(IDE_RELE_CAMARA):
              { // ---------------------------------------------------------
                // Rele de alimentacion de la camara
                // ---------------------------------------------------------
                if ( estado==IDE_RELE_ACTIVAR)
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,LOW);
                     digitalWrite(PIN_HW_POW_CNX_A1,LOW);
                     digitalWrite(PIN_HW_POW_CNX_A2,HIGH);
                   }
                else 
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A1,LOW);
                     digitalWrite(PIN_HW_POW_CNX_A2,HIGH);
                   }
                break; 
              }

          case(IDE_RELE_MOTORES):
              { // ---------------------------------------------------------
                // Rele de alimentacion de los motores
                // ---------------------------------------------------------
                if ( estado==IDE_RELE_ACTIVAR)
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,LOW);
                     digitalWrite(PIN_HW_POW_CNX_A1,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A2,HIGH);
                   }
                else 
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A1,HIGH);
                     digitalWrite(PIN_HW_POW_CNX_A2,HIGH);
                   }
                break; 
              }
        }
        
  // ---------------------------------------------------------
  // Al salir,  por  defecto  se  queda  en  la salida  Q0 del
  // multiplexor que no esta conectada a nada
  // ---------------------------------------------------------
  miDelay(IDE_RELE_SYS_PAUSA);
  digitalWrite(PIN_HW_POW_CNX_A0,LOW);
  digitalWrite(PIN_HW_POW_CNX_A1,LOW);
  digitalWrite(PIN_HW_POW_CNX_A2,LOW);
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_NUM_RC(void)
// 
//
// ---------------------------------------------------------

byte UF_SYS::get_NUM_RC(void)
{
  byte valor;
  valor = EEPROM.read(EEPROM_ADDR_NUM_RC);
  return(valor);
}



// ---------------------------------------------------------
//
// void UF_SYS::get_CLV_AE(char* valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::get_CLV_AE(char* valor)
{
  valor[0] = EEPROM.read(EEPROM_ADDR_CLV_AE    );
  valor[1] = EEPROM.read(EEPROM_ADDR_CLV_AE + 1);
  valor[2] = EEPROM.read(EEPROM_ADDR_CLV_AE + 2);
  valor[3] = EEPROM.read(EEPROM_ADDR_CLV_AE + 3);
  valor[4] = '\0';
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_MOD_INI(void)
// 
//
// ---------------------------------------------------------

byte UF_SYS::get_MOD_INI(void)
{
  byte valor;
  valor = EEPROM.read(EEPROM_ADDR_MOD_INI);
  return(valor);
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_WATCHDOG(void)
// 
//
// ---------------------------------------------------------

byte UF_SYS::get_WATCHDOG(void)
{
  byte valor;
  valor = EEPROM.read(EEPROM_ADDR_WATCHDOG);
  return(valor);
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_FlgDebug(void)
// 
//
// ---------------------------------------------------------

byte UF_SYS::get_FlgDebug(void)
{
  if ( digitalRead(PIN_HW_CNX_DEBUG)==HIGH) { return (true);  }
  else                                      { return (false); } 
}



// ---------------------------------------------------------
//
// int UF_SYS::get_RECARGAS(void)
// 
//
// ---------------------------------------------------------

int UF_SYS::get_RECARGAS(void)
{
  int valor;
  valor   = EEPROM.read(EEPROM_ADDR_RECARGAS);
  valor <<= 8;
  valor  += EEPROM.read(EEPROM_ADDR_RECARGAS+1);
  return(valor);
}



// ---------------------------------------------------------
//
// void UF_SYS::set_NUM_RC(byte valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::set_NUM_RC(byte valor)
{
  EEPROM.write(EEPROM_ADDR_NUM_RC,valor);
}



// ---------------------------------------------------------
//
// void UF_SYS::set_CLV_AE(char* valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::set_CLV_AE(char* valor)
{
  EEPROM.write(EEPROM_ADDR_CLV_AE     ,valor[0]);
  EEPROM.write(EEPROM_ADDR_CLV_AE + 1 ,valor[1]);
  EEPROM.write(EEPROM_ADDR_CLV_AE + 2 ,valor[2]);
  EEPROM.write(EEPROM_ADDR_CLV_AE + 3 ,valor[3]);
}



// ---------------------------------------------------------
//
// void UF_SYS::set_MOD_INI(byte valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::set_MOD_INI(byte valor)
{
  EEPROM.write(EEPROM_ADDR_MOD_INI,valor);
}



// ---------------------------------------------------------
//
// void UF_SYS::set_WATCHDOG(byte valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::set_WATCHDOG(byte valor)
{
  EEPROM.write(EEPROM_ADDR_WATCHDOG,valor);
}



// ---------------------------------------------------------
//
// void UF_SYS::set_RECARGAS(int valor)
// 
//
// ---------------------------------------------------------

void UF_SYS::set_RECARGAS(int valor)
{
  EEPROM.write(EEPROM_ADDR_RECARGAS  ,highByte(valor));
  EEPROM.write(EEPROM_ADDR_RECARGAS+1, lowByte(valor));
}





// ---------------------------------------------------------
//
// void UF_SYS::void display_Datos_EEPROM(void)
// 
//
// ---------------------------------------------------------

void UF_SYS::display_Datos_EEPROM(void)
{
  char buff[IDE_CLV_MAXL+1];
  
  Serial1.print("Reintentos: ");
  Serial1.println(get_NUM_RC(),DEC);
  Serial1.print("Clave EEPROM: ");
  get_CLV_AE(buff);
  Serial1.println(buff);
  //Serial1.print("Modo inicio: ");
  //Serial1.println(get_MOD_INI());
  Serial1.flush();
}



// ---------------------------------------------------------
//
// void UF_SYS::void display_Modo(void)
// 
//
// ---------------------------------------------------------

void UF_SYS::display_Modo(void)
{
  byte modo;
  
  modo = get_MOD_INI();
  
  Serial1.print("Modo inicio: ");
  if ( modo==IDE_INICIO_WATCHDOG ){ Serial1.println(IDE_STR_INICIO_WATCHDOG); }
  else                            { Serial1.println(IDE_STR_INICIO_POWER_ON); }
  Serial1.flush();
}



// ---------------------------------------------------------
//
// void UF_SYS::getTimeExe_0(void)
// 
//
// ---------------------------------------------------------

unsigned long UF_SYS::getTimeExe(byte modo)
{
  unsigned long mTime;


  mTime = 0L;
  if (modo==true) 
     {
       timeExe = millis();
     }
  else
     {
       mTime = millis() - timeExe;  
       Serial1.println(mTime);
       Serial1.print(" ms");
     }

   return( mTime);
}



// ---------------------------------------------------------
//
// void UF_SYS::miDelay(unsigned long int retardo)
// 
//
// ---------------------------------------------------------
void UF_SYS::miDelay(unsigned long int retardo)
{
  unsigned long int mTime;


  mTime = millis();
  

  while ( (millis()-mTime)<retardo ) 
        {
       //watchDog_DONE();
        }
}



// ---------------------------------------------------------
//
// double UF_SYS::get_Corriente(byte pinID)
// Retorna:
//
// ASUME que el pin
//
//
// Codigo obtenido de:
// . http://playground.arduino.cc/Main/CurrentSensing
//
//
//
// ---------------------------------------------------------

double UF_SYS::get_Corriente(byte pinID)
{

  int    vConversor;
  double vRango;
  double vMedida;
  double iMedida;
  char   tmpBuff[IDE_MAXBUFF_GENERICO+1];


  analogReference(DEFAULT);             // Fija referencia interna ADC = 5V, comentado ya se fija en el setup()
       
  vConversor = analogRead(pinID) - 10;  // Lee sensor
                                        // ATENCION:  
                                        // En vez de usar "2500" utilizar lo que de de hacer:
                                        // offsetIcc_CHG_PPAK * 4.9;
                                        // offsetIcc_CHG_LIPO * 4.9;
                                        // offsetIcc_MDER_ICC * 4.9;
                                        // offsetIcc_MIZQ_ICC * 4.9; 

  vMedida = vConversor * (double)4.88;  // Calcula tension medida ( Referencia ADC:5V --> 5000mV/1024 = 4.9mV por paso)
  vRango  = vMedida - 2500;             // Mapea tension medida al rango del sensor ( 5000mV/2 = 2500mV )
  iMedida = vRango / 66;                // Calcula Corriente medida (A) 
  
  Serial1.println("");
  Serial1.println("");
       
  Serial1.print("ADC: ");
  Serial1.println(vConversor);

  Serial1.print("vMedida: ");
  dtostrf(vMedida, 4, 1, tmpBuff);
  Serial1.print(tmpBuff);
  Serial1.println("mV");

  Serial1.print("vRango: ");
  dtostrf(vRango, 4, 1, tmpBuff);
  Serial1.print(tmpBuff);
  Serial1.println("mV");

  //Serial1.print("iMedida: ");
  //Serial1.print(iMedida);
  //dtostrf(iMedida, 4, 1, tmpBuff);
  //Serial1.println("Amp");

  return (iMedida);
}




// ---------------------------------------------------------
//
// void UF_SYS::calibra_SensoresIcc(void)
//
// Permite fijar el offset de los sensores de corriente
//
//
// Nota:
// Esta funcion DEBE llamarse con el Robot parado y sin que
// se esten recargando las baterias, ya que  de  lo  que se
// trata es de obtener el valor retornado por  los sensores
// de corriente SIN ningun consumo.
// Estos  offsets  se  utilizaran luego en las funciones de 
// medida de corriente
//
// ---------------------------------------------------------

void UF_SYS::calibra_SensoresIcc(void)
{
  int vConversor;

    
  vConversor = analogRead(PIN_HW_BAT_CHG_PPAK);
  offsetIcc_CHG_PPAK = vConversor;                // Offset para la lectura del sensor de corriente de entrada al PowerBank
  
  vConversor = analogRead(PIN_HW_BAT_CHG_LIPO);
  offsetIcc_CHG_LIPO = vConversor;                // Offset para la lectura del sensor de corriente de entrada a la bateria LiPo
  
  vConversor = analogRead(PIN_HW_MDER_ICC);
  offsetIcc_MDER_ICC = vConversor;                // Offset para la lectura del sensor de corriente del motor derecho
  
  vConversor = analogRead(PIN_HW_MIZQ_ICC);
  offsetIcc_MIZQ_ICC = vConversor;                // Offset para la lectura del sensor de corriente del motor izquierdo
  
  
  #ifdef APP_MODO_
  Serial1.print("DEBUG Offset Icc PowerBank: ");DEBUG
  Serial1.println(offsetIcc_CHG_PPAK,DEC);
  Serial1.print("DEBUG Offset Icc LiPo: ");
  Serial1.println(offsetIcc_CHG_LIPO,DEC);
  Serial1.print("DEBUG Offset Icc Motor Der: ");
  Serial1.println(offsetIcc_MDER_ICC,DEC);
  Serial1.print("DEBUG Offset Icc Motor Izq: ");
  Serial1.println(offsetIcc_MIZQ_ICC,DEC);
  #endif
}



// ---------------------------------------------------------
//
// void UF_SYS::recarga_Bateria(void)
//
//
//
// ---------------------------------------------------------

void UF_SYS::recarga_Bateria(void)
{
  int nRecargas;

               // incrementar el contador de recargas (se guarda en EEPROM)


 nRecargas = get_RECARGAS() + 1;
 set_RECARGAS(nRecargas);

}



// ---------------------------------------------------------
//
// byte UF_SYS::setLed(byte ledID,byte modo)
//         
//
// ---------------------------------------------------------

byte UF_SYS::setLed(byte ledID,byte modo)
{
  switch(ledID)
        { 
          case(IDE_LED_BDEL): { led_LED_BDEL = modo; break; }
          case(IDE_LED_BDET): { led_LED_BDET = modo; break; } 
          case(IDE_LED_RDET): { led_LED_RDET = modo; break; } 
        }

  return(modo);
}


