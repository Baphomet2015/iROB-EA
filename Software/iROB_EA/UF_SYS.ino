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
// Notas:          REVISADO 08/04/2016     
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
   

  // ---------------------------------------------------------
  //
  // Inicio de componentes e interfaces Arduino
  //
  // ---------------------------------------------------------
  
  // ---------------------------------------------------------
  // Inicio del sistema de encendido/intermitencias de los leds
  // ---------------------------------------------------------
  led_Timer = IDE_LED_TIMER;
  led_Blk   = LOW;
  led_DER   = IDE_LED_OFF;     // Led apagado
  led_IZQ   = IDE_LED_OFF;     // Led apagado
  led_POS   = IDE_LED_OFF;     // Led apagado

  digitalWrite(PIN_HW_LED_DER,LOW);
  digitalWrite(PIN_HW_LED_IZQ,LOW);
  digitalWrite(PIN_HW_LED_POS,LOW);

  // ---------------------------------------------------------
  // Inicio del sistema de medida de corriente ACS714
  // ---------------------------------------------------------
 
  calibra_ACS714();

 
  // ---------------------------------------------------------
  //
  //
  //
  // ---------------------------------------------------------
       
  switch( secuenciaInicio() )
        {
           case ( IDE_SEC_INICIO_OK ):
                { // ---------------------------------------------------------
                  // Operaciones de inicializacion
                  // ---------------------------------------------------------
                  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_WAIT,(IDE_PAUSA_GENERAL*4));




   
            
                  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_CLS,0);
                  break;
                }
                
           case ( IDE_SEC_INICIO_ER_CLV ):   
                { // ---------------------------------------------------------
                  // Clave introducida erroena en max numero de intentos --> Power OFF
                  // ---------------------------------------------------------
                  Serial3.println(IDE_STR_INICIO_POWER_OFF);
                  FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OFF,(IDE_PAUSA_GENERAL*4));                
                  power_OFF();        
                  break;
                }      
                
           case ( IDE_SEC_INICIO_ER_BLK ):   
                { // ---------------------------------------------------------
                  // NO se puede arrancar bloqueado, queda en un bulcle 
                  // indefinido para que se pueda recargar el programa
                  // ---------------------------------------------------------
                  while( 1 );
                  break;
                }          
        }
}



// ---------------------------------------------------------
//
// byte UF_SYS::timers(void)
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
    
 switch (led_DER)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_DER,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_DER,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_DER,led_Blk); break; }
        }

 switch (led_IZQ)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_IZQ,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_IZQ,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_IZQ,led_Blk); break; }
        }

 switch (led_POS)
        { 
          case(IDE_LED_OFF): { digitalWrite(PIN_HW_LED_POS,LOW);     break; }
          case(IDE_LED_ON):  { digitalWrite(PIN_HW_LED_POS,HIGH);    break; }
          case(IDE_LED_BLK): { digitalWrite(PIN_HW_LED_POS,led_Blk); break; }
        }

}



// ---------------------------------------------------------
//
// byte UF_SYS::secuenciaInicio(void)
// Retorna:
// . IDE_SEC_INICIO_OK:     Correcto
// . IDE_SEC_INICIO_ER_CLV: NO se ha introducido clave
// . IDE_SEC_INICIO_ER_BLK: Bloqueado por clave incorrecta
//                          agotados intentos 
// . Si arranque OK en este caso las variables EEPROM:
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


  resultado  = IDE_SEC_INICIO_ER_CLV;
  flgProceso = false;
  
  while( flgProceso==false )  
       { // ---------------------------------------------------------
         // Bucle de captura de clave
         // ---------------------------------------------------------

         nIntentos = get_NUM_RC();
         display_Clave(nIntentos);
                          
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
                        resultado  = IDE_SEC_INICIO_OK;             
                        flgProceso = true;
                        set_NUM_RC(0);
                        FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_OK ,(IDE_PAUSA_GENERAL*4));
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
                   resultado  = IDE_SEC_INICIO_ER_BLK;
                   flgProceso = true;
                   FNG_DisplayMsgPROGMEM(IDE_MSG_DISPLAY_BLK,(IDE_PAUSA_GENERAL*8));
                   Serial3.println(IDE_STR_LOCK);
                 }
            }
       }
  
  return( resultado );
}



// ---------------------------------------------------------
//
// byte UF_SYS::get_CodigoDTMF(char* buff)
// Permite  introducir  via  DTMF  un  codigo  de  password,
// retorna:
// . True  codigo introducido    buff --> Codigo
// . False codigo no introducido buff --> "    "
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
  // Como medida de  seguridad  se desactivan los reles antes  
  // del power OFF
  // ---------------------------------------------------------
  
  rele(IDE_RELE_PC ,IDE_RELE_DESACTIVAR);
  rele(IDE_RELE_12P,IDE_RELE_DESACTIVAR);

  // ---------------------------------------------------------
  // Apagado fisico
  // ---------------------------------------------------------

  rele(IDE_RELE_SYS_OFF ,IDE_RELE_ACTIVAR);
  
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
          case (IDE_RELE_PC):
               {
                 if ( estado==IDE_RELE_ACTIVAR )
                    {
                      digitalWrite(PIN_HW_POW_CNX_A0,HIGH);                        
                      digitalWrite(PIN_HW_POW_CNX_A1,LOW);                        
                      digitalWrite(PIN_HW_POW_CNX_A2,LOW);                        
                    }
                 else
                    {
                      digitalWrite(PIN_HW_POW_CNX_A0,LOW);                        
                      digitalWrite(PIN_HW_POW_CNX_A1,HIGH);                        
                      digitalWrite(PIN_HW_POW_CNX_A2,LOW);                        
                    }
                 break;
               }
               
          case (IDE_RELE_12P):
               {
                 if ( estado==IDE_RELE_ACTIVAR )
                    {
                      digitalWrite(PIN_HW_POW_CNX_A0,HIGH);                        
                      digitalWrite(PIN_HW_POW_CNX_A1,HIGH);                        
                      digitalWrite(PIN_HW_POW_CNX_A2,LOW);                        
                    }
                 else
                    {
                      digitalWrite(PIN_HW_POW_CNX_A0,LOW);                        
                      digitalWrite(PIN_HW_POW_CNX_A1,LOW);                        
                      digitalWrite(PIN_HW_POW_CNX_A2,HIGH);                        
                    }
                 break;
               }
               
          case (IDE_RELE_SYS_OFF):
               {
                if ( estado==IDE_RELE_ACTIVAR )
                   {
                     digitalWrite(PIN_HW_POW_CNX_A0,HIGH);                        
                     digitalWrite(PIN_HW_POW_CNX_A1,LOW);                        
                     digitalWrite(PIN_HW_POW_CNX_A2,HIGH);                 
                   }
                 break;
               }
        }

  // ---------------------------------------------------------
  // Al salir,  por  defecto  se  queda  en  la salida  Q0 del
  // multiplexor (74HC238) que  no  esta  conectada  a  nada ,
  // salvo que se haya llamado para activar el rele  de  power
  // OFF, porque en ese caso apaga fisicamente el Robot.
  // ---------------------------------------------------------
  FNG_Pausa(IDE_RELE_SYS_PAUSA);
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
// float UF_SYS::get_Corriente(int sensorID)
// Retorna:
//
// Codigo obtenido de:
// . http://playground.arduino.cc/Main/CurrentSensing
//
//
//
// ---------------------------------------------------------

float UF_SYS::get_Corriente(int sensorID)
{
  int      nMedidas;
  int      pinID;
  long int vMedida;
  float    sensedVoltage;
  float    sensedCurrent;
  float    offset;

  nMedidas      = 0;
  vMedida       = 0L;
  sensedCurrent = 0.0;
  sensedVoltage = 0.0;

  if ( sensorID==IDE_ICC_5VP )
     { 
       offset = offset_5VP;
       pinID  = PIN_HW_ICC_SENSE_5VP;
     }
  else
     {
       offset = offset_12P;
       pinID  = PIN_HW_ICC_SENSE_12P;
     }
    
  for (;nMedidas<IDE_ICC_NUM_MEDIDAS_OBTENER;nMedidas++ )
      { // ---------------------------------------------------------
        //
        // ---------------------------------------------------------
        vMedida += analogRead(pinID);
      }
  vMedida       /= IDE_ICC_NUM_MEDIDAS_OBTENER;
  sensedVoltage  = vMedida * adc_vConversion;
  sensedCurrent = (sensedVoltage - offset) / IDE_ICC_SENSIBILIDAD;

  #ifdef APP_MODO_DEBUG
  Serial3.print("offset: ");
  Serial3.print(offset);
  Serial3.print("V, voltaje medido: ");
  Serial3.print(sensedVoltage,2);
  Serial3.print("V, corriente medida: ");
  Serial3.print(sensedCurrent,2);
  Serial3.println("A");
  #endif

  return(sensedCurrent);
}



// ---------------------------------------------------------
//
// void UF_SYS::calibra_ACS714(void)
//
// Desconecta los dos reles (12P y 5VP) y mide la tension de
// salida de los dos sensores de corriente para determinar la
// tension de offset real de ambos sensores.
// Actualiza los offsets medidos en dos variables de la clase
// . offset_12P
// . offset_5VP
//
// ---------------------------------------------------------

void UF_SYS::calibra_ACS714(void)
{
  int      nMedidas;
  long int vMedida;

  
  rele(IDE_RELE_PC ,IDE_RELE_DESACTIVAR);
  rele(IDE_RELE_12P,IDE_RELE_DESACTIVAR);

  adc_vConversion = ((float)5.0) / ((float)1024.0);   // Tension equivalente por paso de conversion, voltios
  
  nMedidas = 0;
  vMedida  = 0L; 
  for (;nMedidas<IDE_ICC_NUM_MEDIDAS_CALIBRAR;nMedidas++ )
      { // ---------------------------------------------------------
        //
        // ---------------------------------------------------------
        vMedida += analogRead(PIN_HW_ICC_SENSE_12P);
      }
  vMedida    /= IDE_ICC_NUM_MEDIDAS_CALIBRAR;
  offset_12P  = vMedida * adc_vConversion;

  nMedidas = 0;
  vMedida  = 0L; 
  for (;nMedidas<IDE_ICC_NUM_MEDIDAS_CALIBRAR;nMedidas++ )
      { // ---------------------------------------------------------
        //
        // ---------------------------------------------------------
        vMedida += analogRead(PIN_HW_ICC_SENSE_5VP);
      }
  vMedida    /= IDE_ICC_NUM_MEDIDAS_CALIBRAR;
  offset_5VP  = vMedida * adc_vConversion;
   
}



// ---------------------------------------------------------
//
// byte UF_SYS::set_Led(byte ledID,byte modo)
//         
//
// ---------------------------------------------------------

byte UF_SYS::set_Led(byte ledID,byte modo)
{
  switch(ledID)
        { 
          case(IDE_LED_DER): { led_DER = modo; break; }
          case(IDE_LED_IZQ): { led_IZQ = modo; break; } 
          case(IDE_LED_POS): { led_POS = modo; break; } 
        }

  return(modo);
}



// ---------------------------------------------------------
//
// int UF_SYS:get_Bateria(void)
//         
//
// ---------------------------------------------------------

int UF_SYS::get_Bateria(void)
{
  int carga = IDE_BAT_MIN;

       if ( digitalRead(PIN_HW_BAT_N100)==LOW ) { carga = IDE_BAT_N100; }
  else if ( digitalRead(PIN_HW_BAT_N75) ==LOW ) { carga = IDE_BAT_N75;  }
  else if ( digitalRead(PIN_HW_BAT_N50) ==LOW ) { carga = IDE_BAT_N50;  }
  else if ( digitalRead(PIN_HW_BAT_N25) ==LOW ) { carga = IDE_BAT_N25;  }
  
  return( carga );
}



// ---------------------------------------------------------
//
// void UF_SYS::display_Clave(byte nIntentos)
//         
//
// ---------------------------------------------------------

void UF_SYS::display_Clave(byte nIntentos)
{

 Serial3.print("Reintentos: ");
 Serial3.println(nIntentos,DEC);
 Serial3.print("Clave: ");
 Serial3.println(IDE_CLV_AP);
 Serial3.flush();
  
}
