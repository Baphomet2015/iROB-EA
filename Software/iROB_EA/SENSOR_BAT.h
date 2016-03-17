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
          
                SENSOR_BAT       (int pin_INBP,int pin_INB0,int pin_INB1,int pin_INB2,int pin_INBS,int pin_CHG_PPAK,int pin_CHG_LIPO);
          void  inicio           (void);
          byte  getLedCargaLiPo  (void);

  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

     int pinINBP;
     int pinINB0;
     int pinINB1;
     int pinINB2;
     int pinINBS;
     int pinCHG_PPAK;
     int pinCHG_LIPO;





     
};









#endif



