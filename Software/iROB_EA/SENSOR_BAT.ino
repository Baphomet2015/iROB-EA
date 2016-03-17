
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
// byte SENSOR_BAT::getLedCargaLiPo(void)
//         
// Retorna:
// True  El led de carga del cargador LiPo esta encendido
//       indica bateria cargada         
// False El led de carga del cargador LiPo esta apagado
//       indica bateria  en carga
//
// ---------------------------------------------------------

byte SENSOR_BAT::getLedCargaLiPo(void)
{
  byte valor; 

  // ---------------------------------------------------------  
  // La señal del sensor que  detecta  el  led  de  carga  del 
  // cargador LiPo se encuentra en el canal 5 del MUX 4015
  // ---------------------------------------------------------  
  digitalWrite(pinINB0,HIGH); 
  digitalWrite(pinINB1,LOW);
  digitalWrite(pinINB2,HIGH);

  valor = analogRead(pinINBS);
  if ( valor>0 ) { valor = true;  }
  else           { valor = false; }

  return(valor);
}

