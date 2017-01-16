// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_US.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Definicion de la clase SENSOR_US
//
// Notas:          REVISADO 08/04/2016        
//
// ---------------------------------------------------------


#ifndef SENSOR_US_H
#define SENSOR_US_H


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------




// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_US
//
// ---------------------------------------------------------

class SENSOR_US 
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
                SENSOR_US (int pin_USD_S,int pin_USI_S,int pin_USD_C,int pin_USI_C);
          void  inicio    (void);

  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

     int pinUSD_S;
     int pinUSI_S;
     int pinUSD_C;
     int pinUSI_C;




     
};









#endif



