// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_US.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase SENSOR_US
//                 Maneja los sensores:
//                 . Ultrasonidos
//                 . Deteccion de superficie (suelo)
//
// Notas:          REVISADO 08/04/2016        
//
// ---------------------------------------------------------


#ifndef SENSOR_USS_H
#define SENSOR_USS_H


// ---------------------------------------------------------
//
// Definiciones relacionadas con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_MAX_US_DELAY                     10   // Microsegundos
#define IDE_MAX_SUPERFICIE_DELAY             100  // Microsegundos

#define IDE_NUM_DEDIDAS_SUPERFICIE           10   // Numero de medidas que realiza el sensor de superficie

// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_USS
//
// ---------------------------------------------------------

class SENSOR_USS 
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
                SENSOR_USS     (int pin_USD_T,int pin_USI_T,int pin_USD_E,int pin_USI_E,int pin_Superficie);
          void  begin          (void);
           int  get_IZQ        (void);
           int  get_DER        (void);
  unsigned int  get_Superficie (void);
           
  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

     int pinUSD_T;        // Pin utilizado para Trigger para sensor Derecho
     int pinUSI_T;        // Pin utilizado para Trigger para sensor Izquierdo
     int pinUSD_E;        // Pin utilizado para Echo    para sensor Derecho
     int pinUSI_E;        // Pin utilizado para Echo    para sensor Izquierdo
     int pinSuperficie;   // Pin analogico utilizado por el sensor de superficie (SHARP GP2D12)



     
};









#endif
