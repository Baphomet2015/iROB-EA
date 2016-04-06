
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        UF_BAT.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Marzo 2016
//
// Funcionalidad:  Implmentacion de la clase UF_BAT
//
// Notas:          
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <WString.h> 
#include "iROB_EA.h"
#include "UF_BAT.h"




// ---------------------------------------------------------
//
// UF_SYS::UF_BAT()
//         Constructor
//
// ---------------------------------------------------------

UF_BAT::UF_BAT(int pin_INBP,int pin_INB0,int pin_INB1,int pin_INB2,int pin_INBS,int pin_CHG_PPAK,int pin_CHG_LIPO)
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





   inicio();                 // 4Âº Esto   
   
}



// ---------------------------------------------------------
//
// void UF_BAT::inicio(void)
//         
//
// ---------------------------------------------------------

void UF_BAT::inicio(void)
{
  digitalWrite(pinINBP,LOW);
  digitalWrite(pinINB0,LOW);
  digitalWrite(pinINB1,LOW);
  digitalWrite(pinINB2,LOW);
}



// ---------------------------------------------------------
//
// int UF_BAT::get_LedChgLiPo(void)
//         
// Retorna:
//   1  El led de carga del cargador LiPo esta encendido
//      indica bateria cargada         
//   0  El led de carga del cargador LiPo esta apagado
//      indica bateria en carga
//
// ---------------------------------------------------------

int UF_BAT::get_LedChgLiPo(void)
{
  int valor; 

  // ---------------------------------------------------------  
  // La seÃ±al del sensor que  detecta  el  led  de  carga  del 
  // cargador LiPo se encuentra en el CANAL 5 del MUX 4051
  // ---------------------------------------------------------  
  digitalWrite(pinINB0,HIGH); 
  digitalWrite(pinINB1,LOW);
  digitalWrite(pinINB2,HIGH);

  valor = analogRead(pinINBS);
  
  // ---------------------------------------------------------  
  // Un valor  por encima de 45 (aproximadamente)  indica  que 
  // el  led  de "bateria cargada" del  cargador LiPo NO  esta 
  // encendido, se pone 200 por seguridad
  // ---------------------------------------------------------  
  if ( valor>200 ) { valor = 0; }
  else             { valor = 1; }

  return(valor);
}



// ---------------------------------------------------------
//
// int UF_BAT::get_LedChgPpak(void)
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

int UF_BAT::get_LedChgPpak(void)
{
  int  valor; 
  int  carga;
  byte flgTest;
 

  flgTest = true;
  carga   = 0;

  // ---------------------------------------------------------  
  // Activa el pulsador de lectura de estado del Pbank
  // ---------------------------------------------------------  

 digitalWrite(pinINBP,HIGH);
 uf_sys.miDelay(250);
 digitalWrite(pinINBP,LOW);


  // ---------------------------------------------------------  
  // Comprueba el estado del led que indica 100% de carga 
  // cargador LiPo se encuentra en el CANAL 1 del MUX 4051
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
  // cargador LiPo se encuentra en el CANAL 2 del MUX 4051
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
  // cargador LiPo se encuentra en el CANAL 3 del MUX 4051
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
  // cargador LiPo se encuentra en el CANAL 4 del MUX 4051
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
// double UF_BAT::get_IccChgLiPo(void)
//         
// Retorna:
//
// ---------------------------------------------------------

double UF_BAT::get_IccChgLiPo(void)
{
  double iMedida;
  
  

  iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_LIPO);
  
  return( iMedida);
}



// ---------------------------------------------------------
//
// double UF_BAT::get_IccChgPpak(void)
//         
// Retorna:
//
// ---------------------------------------------------------

double UF_BAT::get_IccChgPpak(void)
{
  double iMedida;
    
  
  iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_PPAK);
  
  return( iMedida);
}




// ---------------------------------------------------------
//
// int UF_BAT::get_FlgCarga(void)
// 
//
// Retorna:
//   1  SI Se esta recibiendo tension de recarga
//   0  NO Se esta recibiendo tension de recarga
//
// ---------------------------------------------------------

int UF_BAT::get_FlgCarga(void)
{
  int valor;

  // ---------------------------------------------------------  
  // La seÃ±al del sensor que  detecta  si se esta recibiendo 
  // tension de recarga se encuentra en el CANAL 6 del MUX 4051
  // ---------------------------------------------------------  
  digitalWrite(pinINB0,LOW); 
  digitalWrite(pinINB1,HIGH);
  digitalWrite(pinINB2,HIGH);
  
  valor = analogRead(pinINBS);

  // ---------------------------------------------------------  
  // Un valor  por encima de 0  indica  que se este recibiendo
  // tension de recarga, se pone 50 por seguridad, para asegurar
  // que se lee un valor bueno, no ruido
  // ---------------------------------------------------------  
  if (valor>50)    { valor = 1; }
  else             { valor = 0; }


  return(valor);
}




// ---------------------------------------------------------
//
// void UF_BAT:ctrl_Baterias(void)
//
//
//
// ---------------------------------------------------------

void UF_BAT::ctrl_Baterias(void)
{
  int nRecargas;

          
  if ( get_FlgCarga()==1 )
     {








       // nRecargas = get_RECARGAS() + 1; // incrementar el contador de recargas (se guarda en EEPROM)
       // set_RECARGAS(nRecargas);



     }

}

