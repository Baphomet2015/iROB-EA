
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SENSOR_RAZOR.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Implmentacion de la clase SENSOR_RAZOR
//
// Notas:          REVISADO 
//
// ---------------------------------------------------------

#include "SENSOR_RAZOR.h"




// ---------------------------------------------------------
//
// SENSOR_RAZOR::SENSOR_RAZOR( void )  
//             Constructor
//
// ---------------------------------------------------------

SENSOR_RAZOR::SENSOR_RAZOR(void)
{
  
     
}



// ---------------------------------------------------------
//
// void SENSOR_RAZOR::begin(void)
//
// ---------------------------------------------------------

void SENSOR_RAZOR::begin(void)
{
  Serial2.begin(IDE_SERIAL_TRX_RAZOR);   // Inicializa el puerto serie asignado

   
}
