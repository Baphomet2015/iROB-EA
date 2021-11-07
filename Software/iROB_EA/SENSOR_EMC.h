// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SNESOR_US.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase SENSOR_EMC
//                 Maneja los sensores de la estacion Climatica:
//                 . Altimetro MPL3115A2
//                 . Presion y Temperatura HTU21D
//                 . Medidor luz ambiente ALS-PT19
//                 . Sensor Melexis 90614 para medición de
//                   temperatura a distancia
//
// Notas:          REVISADO 20/10/2021        
//
// ---------------------------------------------------------


#ifndef SENSOR_EMC_H
#define SENSOR_EMC_H

#include "SparkFunHTU21D.h"
#include "SparkFunMPL3115A2.h"
#include "Adafruit_MLX90614.h"



// ---------------------------------------------------------
//
// Definiciones relacionadas con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_NUM_DEDIDAS_ALS_PT19           25   // Numero de medidas que realiza el sensor de luz

// ---------------------------------------------------------
//
// Definicion de la Clase SENSOR_EMC
// Estacion de Medicion Climatica
//
// ---------------------------------------------------------

class SENSOR_EMC
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
                 SENSOR_EMC                 (int pin_EMC_luz);
          void   begin                      (void);
          int    get_NivelLuminosidad       (void);
          float  get_Temperatura_HTU21D     (void);
          float  get_Temperatura_MPL3115A2  (void);
          double get_Temperatura_MLX90614_A (void);
          double get_Temperatura_MLX90614_O (void);
          float  get_HumedadRelativa        (void);
          float  get_Presion_Pa             (void);
          float  get_Presion_InHg           (void);
          float  get_Altitud                (void);
          byte   get_RegUsuario             (void);
           
  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

    int               pinEMC_Luz;
    byte              reg_Usuario;
    HTU21D            sensor_HTU21D;     
    MPL3115A2         sensor_MPL3115A2;
    Adafruit_MLX90614 sensor_MLX = Adafruit_MLX90614();              // Implementa el sensor de temperatura MELEXIS 90614


    
};









#endif
