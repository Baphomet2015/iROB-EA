
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
#include "SENSOR_USS.h"




// ---------------------------------------------------------
//
// SENSOR_USS::SENSOR_USS( int pin_USD_T,
//                         int pin_USI_T,
//                         int pin_USD_E,
//                         int pin_USI_E,
//                         int pin_Superficie  
//                       )
//         Constructor
//
// ---------------------------------------------------------

SENSOR_USS::SENSOR_USS(int pin_USD_T,int pin_USI_T,int pin_USD_E,int pin_USI_E,int pin_Superficie)
{
   pinUSD_T      = pin_USD_T;
   pinUSI_T      = pin_USI_T; 
   pinUSD_E      = pin_USD_E;
   pinUSI_E      = pin_USI_E;
   pinSuperficie = pin_Superficie;
  
     
}



// ---------------------------------------------------------
//
// void SENSOR_USS::begin(void)
//
// ---------------------------------------------------------

void SENSOR_USS::begin(void)
{
        
  pinMode(pinUSD_T     ,OUTPUT);
  pinMode(pinUSI_T     ,OUTPUT);
  pinMode(pinUSD_E     ,INPUT); 
  pinMode(pinUSI_E     ,INPUT); 
  pinMode(pinSuperficie,INPUT);

  digitalWrite(pinUSD_T,LOW);
  digitalWrite(pinUSI_T,LOW);
  delayMicroseconds(IDE_MAX_US_DELAY);
   
}



// ---------------------------------------------------------
//
// int SENSOR_USS::get_DER(void)
//                 Retorna distancia a un objeto detectado
//                 por la derecha, en centimetros
//     Velocidad del sonido: (340M / s)) / 2
//
// ---------------------------------------------------------

int SENSOR_USS::get_DER(void)
{
  long int duracion;
  int      distancia;
      
  digitalWrite(pinUSD_T, HIGH);         // Trigger
  delayMicroseconds(IDE_MAX_US_DELAY);
  digitalWrite(pinUSD_T, LOW);
    
  duracion  = pulseIn(pinUSD_E, HIGH);  // Recupera longitud del pulso en microsegundos
  distancia = (duracion * 0.034) / 2;   // Calcula distancia, en centimetros

  return(distancia);
}



// ---------------------------------------------------------
//
// int SENSOR_USS::get_IZQ(void)
//                 Retorna distancia a un objeto detectado
//                 por la izquierda, en centimetros
//
//     Velocidad del sonido: (340M / s)) / 2
//
// ---------------------------------------------------------

int SENSOR_USS::get_IZQ(void)
{
  long int duracion;
  int      distancia;
      
  digitalWrite(pinUSI_T, HIGH);         // Trigger
  delayMicroseconds(IDE_MAX_US_DELAY);
  digitalWrite(pinUSI_T, LOW);
    
  duracion  = pulseIn(pinUSI_E, HIGH);  // Recupera longitud del pulso en microsegundos
  distancia = (duracion * 0.034) / 2;   // Calcula distancia, en centimetros

  return(distancia);
}



// ---------------------------------------------------------
//
// int SENSOR_USS::get_Superficie(void)
//                 Retorna distancia a la superficie por la 
//                 que desplaza, en centimetros
//
// ---------------------------------------------------------

unsigned int SENSOR_USS::get_Superficie(void)
{
  unsigned int medida;
  int i;

  i      = 0;
  medida = 0;
  
  for (;i<IDE_NUM_DEDIDAS_SUPERFICIE;i++ )
      {
        medida += analogRead(pinSuperficie);
        delayMicroseconds(IDE_MAX_SUPERFICIE_DELAY);
      }
  medida /= IDE_MAX_SUPERFICIE_DELAY;
  
  return(medida);
}
