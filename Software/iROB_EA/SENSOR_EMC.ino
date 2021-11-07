
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        MOTOR_FDS5672.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Implmentacion de la clase SENSOR_EMC
//
// Notas:          REVISADO 27/04/2021  
//
// ---------------------------------------------------------

#include "SENSOR_EMC.h"






// ---------------------------------------------------------
//
// SENSOR_EMC::SENSOR_EMC( int pin_EMC_luz  )
//         Constructor
//
// ---------------------------------------------------------

SENSOR_EMC::SENSOR_EMC(int pin_EMC_luz)
{
   pinEMC_Luz = pin_EMC_luz;



   
}



// ---------------------------------------------------------
//
// void SENSOR_EMC::begin(void)
//         
//
// ---------------------------------------------------------

void SENSOR_EMC::begin (void)
{
  
  sensor_HTU21D.begin();
  sensor_MPL3115A2.begin();
  sensor_MLX.begin();

  reg_Usuario = sensor_HTU21D.readUserRegister();
  sensor_MPL3115A2.setModeBarometer();       // Measure pressure in Pascals from 20 to 110 kPa
  sensor_MPL3115A2.setModeAltimeter();       // Measure altitude above sea level in meters
  sensor_MPL3115A2.setOversampleRate(7);     // Set Oversample to the recommended 128
  sensor_MPL3115A2.enableEventFlags();       // Enable all three pressure and temp event flags 


   
}



// ---------------------------------------------------------
//
// byte SENSOR_EMC::get_RegUsuario(void)
//         
//
// ---------------------------------------------------------

byte SENSOR_EMC::get_RegUsuario(void)
{
  return (reg_Usuario);
}



// ---------------------------------------------------------
//
// int SENSOR_EMC::get_NivelLuminosidad(void)
//         
//
// ---------------------------------------------------------

int SENSOR_EMC::get_NivelLuminosidad(void)
{
   long int nivel;
   int      numMedidas;
   
   
   nivel      = 0L;
   numMedidas = 0;
   
   for ( ;numMedidas<IDE_NUM_DEDIDAS_ALS_PT19;numMedidas++ )
       {
         nivel += analogRead(pinEMC_Luz);
       }
   nivel /= IDE_NUM_DEDIDAS_ALS_PT19;
   
   return((int)nivel);
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_Temperatura_HTU21D(void)
//         
//
// ---------------------------------------------------------

float SENSOR_EMC::get_Temperatura_HTU21D(void)
{
 float temperatura;
 
 temperatura = sensor_HTU21D.readTemperature();

 return(temperatura);
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_Temperatura_MPL3115A2(void)
//         
//
// ---------------------------------------------------------

float SENSOR_EMC::get_Temperatura_MPL3115A2(void)
{
  float temperatura;

  temperatura = sensor_MPL3115A2.readTemp();

  return( temperatura );
}


// ---------------------------------------------------------
//
// double SENSOR_EMC::get_Temperatura_MLX90614_A(void)
//
// ---------------------------------------------------------

double SENSOR_EMC::get_Temperatura_MLX90614_A(void)
{
 double temperatura;
 
 temperatura = sensor_MLX.readAmbientTempC();
 if ( GLOBAL_FlgDebug==true )
    {
      Serial3.println("");
      Serial3.print("T. Ambiente: ");
      Serial3.print(temperatura);
    }
 return(temperatura);
}

// ---------------------------------------------------------
//
// double SENSOR_EMC::get_Temperatura_MLX90614_O(void)
//
// ---------------------------------------------------------

double SENSOR_EMC::get_Temperatura_MLX90614_O(void)
{
 double temperatura;
 
 temperatura = sensor_MLX.readObjectTempC();
 if ( GLOBAL_FlgDebug==true )
    {
      Serial3.println("");
      Serial3.print("T. Objeto: ");
      Serial3.print(temperatura);
    }
 
 return(temperatura);
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_HumedadRelativa(void)
//         
//
// ---------------------------------------------------------

float SENSOR_EMC::get_HumedadRelativa(void)
{
  float humedad;
 
  humedad = sensor_HTU21D.readHumidity();

  return(humedad);
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_Presion_Pa(void)
//         
//
// ---------------------------------------------------------

float SENSOR_EMC::get_Presion_Pa(void)
{
  float pressure;

  pressure = sensor_MPL3115A2.readPressure();

  return( pressure );
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_Presion_InHg(void)
// References: 
// Definition of "altimeter setting": http://www.crh.noaa.gov/bou/awebphp/definitions_pressure.php
// Altimeter setting: http://www.srh.noaa.gov/epz/?n=wxcalc_altimetersetting
// Altimeter setting: http://www.srh.noaa.gov/images/epz/wxcalc/altimeterSetting.pdf
// Verified against Boulder, CO readings: http://www.crh.noaa.gov/bou/include/webpres.php?product=webpres.txt
// 1 pascal = 0.01 millibars
//         
// Converts pressure from Pascals to inches of mercury, altimeter setting adjusted.
// ---------------------------------------------------------

float SENSOR_EMC::get_Presion_InHg(void)
{
  float pressure;
  float part1;  
  float part2;  
  float part3;    
  float part4;  
  float part5;
  float part6;
  float baroin;
  float altimeter_setting_pressure_mb;

  const int station_elevation_m = sensor_MPL3115A2.readAltitude(); 
  pressure  = sensor_MPL3115A2.readPressure();
  pressure /= 100;                      // Ppressure is now in millibars
  part1     = pressure - 0.3;           // Part 1 of formula
  part2     = 8.42288 / 100000.0;
  part3     = pow((pressure - 0.3), 0.190284);
  part4     = (float)station_elevation_m / part3;
  part5     = (1.0 + (part2 * part4));
  part6     = pow(part5, (1.0/0.190284));
  altimeter_setting_pressure_mb = part1 * part6; //Output is now in adjusted millibars
  baroin = altimeter_setting_pressure_mb * 0.02953;

  return( baroin );
}



// ---------------------------------------------------------
//
// float SENSOR_EMC::get_Altitud(void)
//         
//
// ---------------------------------------------------------

float SENSOR_EMC::get_Altitud(void)
{
  float altitud;

  altitud = sensor_MPL3115A2.readAltitude();

  return( altitud );
}
