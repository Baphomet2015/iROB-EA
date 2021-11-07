
// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        SENSOR_GPS.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Implmentacion de la clase SENSOR_GPS
//
// Notas:          REVISADO 
//
// ---------------------------------------------------------

#include "SENSOR_GPS.h"




// ---------------------------------------------------------
//
// SENSOR_GPS::SENSOR_GPS( void )  
//             Constructor
//
// ---------------------------------------------------------

SENSOR_GPS::SENSOR_GPS(void)
{
  
     
}



// ---------------------------------------------------------
//
// void SENSOR_GPS::begin(void)
//
// ---------------------------------------------------------

void SENSOR_GPS::begin(void)
{
  Serial1.begin(IDE_SERIAL_TRX_GPS);   // Inicializa el puerto serie asignado
  latitud     = 0.0;
  longitud    = 0.0;
  vAnno       = 0;
  vMes        = 0;
  vDia        = 0; 
  vHoras      = 0;
  vMinutos    = 0;
  vSegundos   = 0;
  vHundredths = 0;
  altitud     = 0.0;
  rumbo       = 0.0;
  velocidad   = 0.0;
  satelites   = 0;
  buffCnv[0]  = '\0';
   
}



// ---------------------------------------------------------
//
// int SENSOR_GPS::actualizar(void)
//
// ---------------------------------------------------------

int SENSOR_GPS::actualizar(void)
{
  unsigned long  chars;
  unsigned long  start;
  unsigned short sentences;
  unsigned short failed_checksum;
  int            newData;
  char           c;

  newData = false;
  start   = millis();
  

  for ( ; (millis() - start) < 1000; )
      {
        while( Serial1.available() )
             {
               c = Serial1.read();
               if ( GLOBAL_FlgDebug==true )
                  { // ----------------------------------------
                    // Envia por el puerto de DEBUG lo recibido
                    // ----------------------------------------
                    Serial3.print(c);
                  }
               if (gps.encode(c)) // Nueva secuencia recibida
                   newData = true;
             }
     }

  if ( GLOBAL_FlgDebug==true )
     { // ----------------------------------------
       // Envia por el puerto de DEBUG lo recibido
       // ----------------------------------------
       if ( newData==true ) { Serial3.println("DATOS RECIBIDOS: OK");        }
       else                 { Serial3.println("DATOS RECIBIDOS: INVALIDOS"); }
     }
                  
  if ( newData==true )
     { // ------------------------------------
       // Procesa la secuencia recibida
       // ------------------------------------
       gps.f_get_position(&latitud, &longitud);
       gps.crack_datetime(&vAnno,&vMes,&vDia,&vHoras,&vMinutos,&vSegundos,&vHundredths);
      
       altitud   = gps.f_altitude(); 
       rumbo     = gps.f_course(); 
       velocidad = gps.f_speed_kmph();
       satelites = gps.satellites();
      
       gps.stats(&chars, &sentences, &failed_checksum);  
     }
  else
     {
       begin();
     }

  return(newData);   
}


// ---------------------------------------------------------
//
// void SENSOR_GPS::get_FechaHora(char* sDes)
// Devuelve string en formato:
// AAAAMMDD-HH:MM, 14 caracteres
//
// ---------------------------------------------------------

void SENSOR_GPS::get_FechaHora(char* sDes)
{
  
 sprintf(sDes,"%04d%02d%02d-%02d:%02d",vAnno,vMes,vDia,vHoras,vMinutos);
 
}

// ---------------------------------------------------------
//
// int SENSOR_GPS::get_Posicion(char* sDes)
// Devuelve string en formato: LATITUD,LONGITUD
// NOTA:
// Debido a que esta funcion se utiliza para recuperar las
// coordenadas, llama a ntes a la funcion actualizar()
//
// ---------------------------------------------------------

int SENSOR_GPS::get_Posicion(char* sDes)
{
  int newData;

  newData = actualizar();
  sDes[0] = '\0';
  
  if ( newData==true )
     {
       dtostrf(latitud,10,5,buffCnv);
       strcpy(sDes,buffCnv);
       strcat(sDes, ",");

       dtostrf(longitud,10,5,buffCnv);
       strcat(sDes,buffCnv);
  
       if ( GLOBAL_FlgDebug==true )
          {
            Serial3.print("Latitud , Longitud: "); 
            Serial3.println(sDes); 
          }
     }
     
  return(newData);
}

// ---------------------------------------------------------
//
// float SENSOR_GPS::get_Altitud(void)
// 
//
// ---------------------------------------------------------

float SENSOR_GPS::get_Altitud(void)
{
  return(altitud);
}

// ---------------------------------------------------------
//
// float SENSOR_GPS::get_Rumbo(void)
// 
//
// ---------------------------------------------------------

float SENSOR_GPS::get_Rumbo(void)
{
  return(rumbo);
}

// ---------------------------------------------------------
//
// float SENSOR_GPS::get_Velocidad(void)
// 
//
// ---------------------------------------------------------

float SENSOR_GPS::get_Velocidad(void)
{
  return(velocidad);
}

// ---------------------------------------------------------
//
// float SENSOR_GPS::get_Satelites(void)
// 
//
// ---------------------------------------------------------

unsigned int SENSOR_GPS::get_Satelites(void)
{
  return(satelites);
}
