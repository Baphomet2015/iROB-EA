
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
// Notas:          
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
//                    int pin_USC_S,
//                    int pin_USI_S,
//                    int pin_USD_C,
//                    int pin_USC_C, 
//                    int pin_USI_C
//                  )
//         Constructor
//
// ---------------------------------------------------------

SENSOR_US::SENSOR_US(int pin_USD_S,int pin_USC_S, int pin_USI_S,int pin_USD_C,int pin_USC_C, int pin_USI_C)
{
   pinUSD_S = pin_USD_S;
   pinUSC_S = pin_USC_S;
   pinUSI_S = pin_USI_S;
   pinUSD_C = pin_USD_C;
   pinUSC_C = pin_USC_C;
   pinUSI_C = pin_USI_C;

                             // 2º Esto
   
                             // 3º Esto
   pinMode(pinUSD_S,INPUT);  // 
   pinMode(pinUSC_S,INPUT);  // 
   pinMode(pinUSI_S,INPUT);  // 
   pinMode(pinUSD_C,OUTPUT); // 
   pinMode(pinUSC_C,OUTPUT); // 
   pinMode(pinUSI_C,OUTPUT); // 

   inicio();                 // 4º Esto
   

   
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
  digitalWrite(pinUSC_C,HIGH); // 
  digitalWrite(pinUSI_C,HIGH); // 
   

}
