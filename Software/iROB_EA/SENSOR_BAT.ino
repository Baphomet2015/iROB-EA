
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SENSOR_BAT.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Marzo 2016
//
// Funcionalidad:  Implmentacion de la clase SENSOR_BAT
//
// Notas:          
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include "iROB_EA.h"
#include "SENSOR_BAT.h"




// ---------------------------------------------------------
//
// UF_SYS::SENSOR_BAT()
//         Constructor
//
// ---------------------------------------------------------

SENSOR_BAT::SENSOR_BAT(int pin_INBP,int pin_INB0,int pin_INB1,int pin_INB2,int pin_INBS,int pin_CHG_PPAK,int pin_CHG_LIPO)
{
   pinINBP     = pin_INBP;
   pinINB0     = pin_INB0;
   pinINB1     = pin_INB1;
   pinINB2     = pin_INB2;
   pinINBS     = pin_INBS;
   pinCHG_PPAK = pin_CHG_PPAK;
   pinCHG_LIPO = pin_CHG_LIPO;

   pinMode(pinINBP    ,OUTPUT);
   pinMode(pinINB0    ,OUTPUT);
   pinMode(pinINB1    ,OUTPUT);
   pinMode(pinINB2    ,OUTPUT);
   pinMode(pinINBS    ,INPUT);
   pinMode(pinCHG_PPAK,INPUT);
   pinMode(pinCHG_LIPO,INPUT);





   inicio();                 // 4º Esto   
   
}



// ---------------------------------------------------------
//
// void SENSOR_BAT::inicio(void)
//         
//
// ---------------------------------------------------------

void SENSOR_BAT::inicio(void)
{
  digitalWrite(pinINBP,LOW);
  digitalWrite(pinINB0,LOW);
  digitalWrite(pinINB1,LOW);
  digitalWrite(pinINB2,LOW);
}



// ---------------------------------------------------------
//
// byte SENSOR_BAT::getLedChgLiPo(void)
//         
// Retorna:
//   1  El led de carga del cargador LiPo esta encendido
//      indica bateria cargada         
//   0  El led de carga del cargador LiPo esta apagado
//      indica bateria en carga
//
// ---------------------------------------------------------

byte SENSOR_BAT::getLedChgLiPo(void)
{
  byte valor; 

  // ---------------------------------------------------------  
  // La señal del sensor que  detecta  el  led  de  carga  del 
  // cargador LiPo se encuentra en el canal 5 del MUX 4051
  // ---------------------------------------------------------  
  digitalWrite(pinINB0,HIGH); 
  digitalWrite(pinINB1,LOW);
  digitalWrite(pinINB2,HIGH);

  valor = analogRead(pinINBS);
  if ( valor>0 ) { valor = 1; }
  else           { valor = 0; }

  return(valor);
}



// ---------------------------------------------------------
//
// byte SENSOR_BAT::getLedChgPpak(void)
//         
// Retorna:
// Un valor que indica el % de carga de la bateria PPAK
//   0  PPAK al   0% Jaaaaa, esta muerto
//  25  PPAK al  25% de carga
//  50  PPAK al  50% de carga
//  75  PPAK al  75% de carga
//  100 PPAK al 100% de carga
//
// ---------------------------------------------------------

byte SENSOR_BAT::getLedChgPpak(void)
{
  byte valor; 
  byte carga;
  byte flgTest;
 

  flgTest = true;
  carga   = 0;

  // ---------------------------------------------------------  
  // Compruebe el estado del led que indica 100% de carga 
  // cargador LiPo se encuentra en el canal 1 del MUX 4051
  // ---------------------------------------------------------  
  if ( flgTest==true)
     {
       digitalWrite(pinINB0,HIGH); 
       digitalWrite(pinINB1,LOW);
       digitalWrite(pinINB2,LOW);
  
       valor = analogRead(pinINBS);

       if (valor>0)
          {
            carga   = 100;
            flgTest = false;
          }
     }

  // ---------------------------------------------------------  
  // Compruebe el estado del led que indica 75% de carga 
  // cargador LiPo se encuentra en el canal 2 del MUX 4051
  // ---------------------------------------------------------  
  if ( flgTest==true)
     {
       digitalWrite(pinINB0,LOW); 
       digitalWrite(pinINB1,HIGH);
       digitalWrite(pinINB2,LOW);
  
       valor = analogRead(pinINBS);

       if (valor>0)
          {
            carga   = 75;
            flgTest = false;
          }
     }

  // ---------------------------------------------------------  
  // Compruebe el estado del led que indica 50% de carga 
  // cargador LiPo se encuentra en el canal 3 del MUX 4051
  // ---------------------------------------------------------  
  if ( flgTest==true)
     {
       digitalWrite(pinINB0,HIGH); 
       digitalWrite(pinINB1,HIGH);
       digitalWrite(pinINB2,LOW);
  
       valor = analogRead(pinINBS);

       if (valor>0)
          {
            carga   = 50;
            flgTest = false;
          }
     }

  // ---------------------------------------------------------  
  // Compruebe el estado del led que indica 25% de carga 
  // cargador LiPo se encuentra en el canal 4 del MUX 4051
  // ---------------------------------------------------------  
  if ( flgTest==true)
     {
       digitalWrite(pinINB0,LOW); 
       digitalWrite(pinINB1,LOW);
       digitalWrite(pinINB2,HIGH);
  
       valor = analogRead(pinINBS);

       if (valor>0)
          {
            carga   = 25;
            flgTest = false;
          }
     }


  return(carga);
}



// ---------------------------------------------------------
//
// double SENSOR_BAT::getIccChgLiPo(void)
//         
// Retorna:
//
// ---------------------------------------------------------

double SENSOR_BAT::getIccChgLiPo(void)
{
  double iMedida;
  double tiempo;
  

  iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_LIPO);
  tiempo  = (IDE_CAPACIDAD_BAT_LIPO/iMedida) * 0.7;

  return( iMedida);
}



// ---------------------------------------------------------
//
// double SENSOR_BAT::getIccChgPpak(void)
//         
// Retorna:
//
// ---------------------------------------------------------

double SENSOR_BAT::getIccChgPpak(void)
{
  double iMedida;
  double tiempo;
  
  
  iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_PPAK);
  tiempo  = (IDE_CAPACIDAD_BAT_PPAK/iMedida) * 0.7;

  return( iMedida);
}