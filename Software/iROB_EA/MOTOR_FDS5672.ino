
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
// Notas:          
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

   pinMode(pin_DIR,OUTPUT); // Motor derecho, Direccion
   pinMode(pin_RST,OUTPUT); // Motor derecho, Reset
   pinMode(pin_FF1,INPUT);  // Motor derecho, Flag estado (1)
   pinMode(pin_FF2,INPUT);  // Motor derecho, Flag estado (2)
   pinMode(pin_ICC,INPUT);  // Motor derecho, sensor de corriente (consumo)

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
   vVelocidad  = IDE_MOTOR_FDS5672_VELDEFECTO;         // 1º Esto
   flgInhibir  = false;
  
   inhibir(flgInhibir);                               // 2º Esto
   velocidad(vVelocidad);
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::avance (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::avance (void)
{
  if ( flgInhibir==false )
     {
       digitalWrite(pinDIR,LOW); 
       setValores();
     }
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::retroceso (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::retroceso (void)
{
  if ( flgInhibir==false )
     {
       digitalWrite(pinDIR,HIGH); 
       setValores();
     }
}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::paro (void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::paro (void)
{
  if ( flgInhibir==false )
     {
       digitalWrite(pinRST,HIGH); 
     }
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
// void MOTOR_FDS5672::inhibir(byte modo)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::inhibir(byte modo)
{
 flgInhibir = modo;
 if ( flgInhibir==true ) { digitalWrite(pinRST,HIGH); }
 else                    { digitalWrite(pinRST,LOW);  }

}



// ---------------------------------------------------------
//
// void MOTOR_FDS5672::setValores(void)
//         
//
// ---------------------------------------------------------

void MOTOR_FDS5672::setValores(void)
{
  uf_sys.watchDog_DONE();
  digitalWrite(pinRST,HIGH); 
  uf_sys.miDelay(IDE_MOTOR_FDS5672_PULSO_VAL);
  digitalWrite(pinRST,LOW); 
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
       

