
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SENSOR_US.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Marzo 2016
//
// Funcionalidad:  Implmentacion de la clase SENSOR_US
//
// Notas:          REVISADO 08/04/2016         
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include "iROB_EA.h"
#include "SENSOR_US.h"




// ---------------------------------------------------------
//
// UF_SYS::SENSOR_US( int pin_USD_S,
//                    int pin_USI_S,
//                    int pin_USD_C,
//                    int pin_USI_C
//                  )
//         Constructor
//
// ---------------------------------------------------------

SENSOR_US::SENSOR_US(int pin_USD_S,int pin_USI_S,int pin_USD_C, int pin_USI_C)
{
   pinUSD_S = pin_USD_S;
   pinUSI_S = pin_USI_S; 
   pinUSD_C = pin_USD_C;
   pinUSI_C = pin_USI_C;

                             // 2Âº Esto
   
                             // 3Âº Esto
   pinMode(pinUSD_S,INPUT);  // 
   pinMode(pinUSI_S,INPUT);  // 
   pinMode(pinUSD_C,OUTPUT); // 
   pinMode(pinUSI_C,OUTPUT); // 

   inicio();                 // 4Âº Esto
   

   
}



// ---------------------------------------------------------
//
// void SENSOR_US::inicio(void)
//         
//
// ---------------------------------------------------------

void SENSOR_US::inicio(void)
{
  
  digitalWrite(pinUSD_C,HIGH); // 
  digitalWrite(pinUSI_C,HIGH); // 
   

}

