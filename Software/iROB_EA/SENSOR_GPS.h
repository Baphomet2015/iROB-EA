// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_GPS.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase SENSOR_GPS
//                 Maneja el modulo de GPS
//
// Notas:          REVISADO 
//
// ---------------------------------------------------------


#ifndef SENSOR_GPS_H
#define SENSOR_GPS_H

#include <TinyGPS.h>

// ---------------------------------------------------------
//
// Definiciones relacionadas con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_SERIAL_TRX_GPS  9600

#define IDE_MAX_AUX_BUFFER  25   // Tamaño de buffer auxiliar para realizar conversiones de valores



// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_GPS
//
// ---------------------------------------------------------

class SENSOR_GPS 
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
                  SENSOR_GPS    (void);
     void         begin         (void);
     int          actualizar    (void);
     void         get_FechaHora (char* sDes);
     int          get_Posicion  (char* sDes);
     float        get_Altitud   (void);
     float        get_Rumbo     (void); 
     float        get_Velocidad (void);
     unsigned int get_Satelites (void);

           
  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

     TinyGPS      gps;
     float        latitud;
     float        longitud;
     int          vAnno;
     byte         vMes;
     byte         vDia; 
     byte         vHoras;
     byte         vMinutos;
     byte         vSegundos;
     byte         vHundredths;
     float        altitud;
     float        rumbo;
     float        velocidad;
     unsigned int satelites;
     char         buffCnv[IDE_MAX_AUX_BUFFER+1];

     
};









#endif
