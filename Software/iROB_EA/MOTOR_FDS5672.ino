
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        MOTOR_FDS5672.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Implmentacion de la clase MOTOR_FDS5672
//
// Notas:          REVISADO 27/04/2021  
//
// ---------------------------------------------------------

#include "MOTOR_FDS5672.h"




// ---------------------------------------------------------
//
// MOTOR_FDS5672::MOTOR_FDS5672( int pin_DIR ,
//                               int pin_RST ,
//                               int pin_PWM 
//                             )
//         Constructor
//
// ---------------------------------------------------------

MOTOR_FDS5672::MOTOR_FDS5672(int pin_DIR,int pin_RST,int pin_PWM)
{
   pinDIR = pin_DIR;        
   pinRST = pin_RST;
   pinPWM = pin_PWM;
}




// ---------------------------------------------------------
//
// void MOTOR_FDS5672::begin(void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::begin (void)
{
  
   pinMode(pinDIR,OUTPUT); // Motor derecho, Direccion
   pinMode(pinRST,OUTPUT); // Motor derecho, Reset

   lVelocidad = false;
   velocidad(IDE_MOTOR_FDS5672_VEL_DEFECTO);
   paro();
}




// ---------------------------------------------------------
//
// void MOTOR_FDS5672::avance (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::avance (void)
{
  modo = IDE_MOTOR_FDS5672_AVANCE;
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
  modo = IDE_MOTOR_FDS5672_RETROCESO;
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
  modo = IDE_MOTOR_FDS5672_PARO;
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
    
  if ( lVelocidad==false )
     { // ------------------------------------
       // La velocidad NO esta limitada
       // ------------------------------------
       vVelocidad = valor;
     }
  else
     { // ------------------------------------
       // La velocidad limitada
       // ------------------------------------
       vVelocidad = IDE_MOTOR_FDS5672_VEL_LIMITADA;
     }

  analogWrite(pinPWM,vVelocidad);  
  setValores();

}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::limitarVelocidad(byte modo)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::limitarVelocidad(byte modo)
{
  lVelocidad = modo;
  if ( lVelocidad==true )
     { // -----------------------------------------------------
       // Se limita la velocidad, actualiza la velocidad en los 
       // motores
       // -----------------------------------------------------
       velocidad(IDE_MOTOR_FDS5672_VEL_LIMITADA);
     }
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
