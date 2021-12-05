// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_RAZOR.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase SENSOR_RAZOR
//                 Maneja los sensores:
//                 . 
//                 . 
//
// Notas:          REVISADO        
//
// ---------------------------------------------------------


#ifndef SENSOR_RAZOR_H
#define SENSOR_RAZOR_H


// ---------------------------------------------------------
//
// Definiciones relacionadas con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_SERIAL_TRX_RAZOR      57600      // Velociad a la que se debe programar el puerto serie que comunica con el modulo
#define IDE_MAX_FRAME_RAZOR       50         // AJUSTAR Longitud de un buffer generico utilizado por las funciones de la clase SENSOR_RAZOR                                         // por el modulo
#define IDE_NUM_FRAME_REINTENTOS  3          // Numero de reintentos que realiza la funcion getFrameSensor
#define IDE_MAX_FRAME_DELAY       15000      // Tiempo de espera despues de ejecutar el comando "#f" 

#define IDE_SENSOR_ACC            "#A-C"     // Identificador de una trama con datos del sensor acelerometro
#define IDE_SENSOR_MAG            "#M-C"     // Identificador de una trama con datos del sensor magnetometro
#define IDE_SENSOR_GYR            "#G-C"     // Identificador de una trama con datos del sensor giroscopio


// ---------------------------------------------------------
//
// Definiciones de datos 
//
// ---------------------------------------------------------



// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_RAZOR
//
// ---------------------------------------------------------

class SENSOR_RAZOR
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
    SENSOR_RAZOR             ();
    void         begin       (void);
    char*        getFrameAcc (void);
    char*        getFrameMag (void);
    char*        getFrameGyr (void);
          
           
  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

    char sBuffFrame[IDE_MAX_FRAME_RAZOR+1];

    byte getFrameSensor  (char* sensorID);
    byte testSFrame      (void);  
  


  
};









#endif
