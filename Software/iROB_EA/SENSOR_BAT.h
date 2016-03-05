// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_BAT.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Definicion de la clase SENSOR_BAT
//
// Notas:          
//
// ---------------------------------------------------------


#ifndef SENSOR_BAT_H
#define SENSOR_BAT_H


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------




// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_BAT
//
// ---------------------------------------------------------

class SENSOR_BAT 
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
          SENSOR_BAT    ();
          void         inicio (void);

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



