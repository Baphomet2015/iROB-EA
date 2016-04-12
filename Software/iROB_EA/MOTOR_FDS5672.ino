
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        MOTOR_FDS5672.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Implmentacion de la clase MOTOR_FDS5672
//
// Notas:          REVISADO 08/04/2016   
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include <EEPROM.h>
#include "iROB_EA.h"
#include "MOTOR_FDS5672.h"






// ---------------------------------------------------------
//
// UF_SYS::MOTOR_FDS5672( int pin_DIR ,
//                        int pin_PWM ,
//                        int pin_RST ,
//                        int pin_FF1 ,
//                        int pin_FF2 ,
//                        int pin_ICC
//                      )
//         Constructor
//
// ---------------------------------------------------------

MOTOR_FDS5672::MOTOR_FDS5672(int pin_DIR,int pin_PWM,int pin_RST,int pin_FF1,int pin_FF2,int pin_ICC)
{
   pinDIR = pin_DIR;        
   pinPWM = pin_PWM;
   pinRST = pin_RST;
   pinFF1 = pin_FF1;
   pinFF2 = pin_FF2;
   pinICC = pin_ICC;

   pinMode(pinDIR,OUTPUT); // Motor derecho, Direccion
   pinMode(pinRST,OUTPUT); // Motor derecho, Reset
   pinMode(pinFF1,INPUT);  // Motor derecho, Flag estado (1)
   pinMode(pinFF2,INPUT);  // Motor derecho, Flag estado (2)
   pinMode(pinICC,INPUT);  // Motor derecho, sensor de corriente (consumo)

   inicio();
   
   
}




// ---------------------------------------------------------
//
// void MOTOR_FDS5672::inicio(void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::inicio (void)
{
   paro();                  
   velocidad(IDE_MOTOR_FDS5672_VELDEFECTO);
}




// ---------------------------------------------------------
//
// void MOTOR_FDS5672::avance (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::avance (void)
{
  digitalWrite(pinDIR,LOW); 
  setValores();
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::retroceso (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::retroceso (void)
{
  digitalWrite(pinDIR,HIGH); 
  setValores();
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::paro (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::paro (void)
{
  digitalWrite(pinRST,LOW); 
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::velocidad(byte valor)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::velocidad(byte valor)
{
  vVelocidad = valor;
  analogWrite(pinPWM,vVelocidad);  
  setValores();
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::setValores(void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::setValores(void)
{
  digitalWrite(pinRST,LOW); 
  delayMicroseconds(IDE_MOTOR_FDS5672_PULSO_VAL);
  digitalWrite(pinRST,HIGH); 
}




// ---------------------------------------------------------
//
// byte MOTOR_FDS5672::getEstado(void)
//         
//
// ---------------------------------------------------------

byte MOTOR_FDS5672::getEstado(void)
{
  byte estado;

  estado = 0;
  if ( digitalRead(pinFF1)==HIGH) { estado  = 2; } 
  if ( digitalRead(pinFF2)==HIGH) { estado += 1; }

  return(estado);  
}
       

