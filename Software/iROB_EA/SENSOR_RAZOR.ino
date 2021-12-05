
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
//                 IMPORTANTE:
//                 Todos los comandos que se intercambian con
//                 el modulo 9DOF Razor IMU estan definidos y
//                 explicados por los autores del firmware de
//                 dicho modulo en el fichero Razor_AHRS.ino.
//                 Es necesario  ver  esos  comentarios para 
//                 entender como funciona el modulo. 
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
  
  Serial2.begin(IDE_SERIAL_TRX_RAZOR); // Programa la velocidad del puerto para comunicarse con el modulo
  Serial2.write("#oe0");               // Comando del modulo 9DOF Razor IMU que deshabilita los errores de salida
  Serial2.write("#o0");                // Comando del modulo 9DOF Razor IMU que deshabilita la salida continua de informacion desde el modulo
  Serial2.write("#ot");                // Comando del modulo 9DOF Razor IMU que indica salida de datos en formato TEXTO
  Serial2.write("#osct");              // Comando del modulo 9DOF Razor IMU que indica Salida de datos SENSORES CALIBRADOS de los 9 ejes
  Serial2.flush();
    
  sBuffFrame[0]='\0';
  
  
}


// ---------------------------------------------------------
//
// byte SENSOR_RAZOR::getFrameSensor(char* sensorID)
//
// ---------------------------------------------------------

byte SENSOR_RAZOR::getFrameSensor(char* sensorID)
{
 
  byte   nReintentos;
  byte   resultado;
  byte   nCar1;
  byte   nCar2;
  String sAux; 
  
  
  resultado     = true;
  nReintentos   = 0;
  sBuffFrame[0] = '\0';
  
  while ( true )
        {
          if ( Serial2.available()>0 )
             {
               sAux = Serial2.readStringUntil('\n');
               if (sAux.indexOf(sensorID,0)!=-1 )
                  { 
                    nCar1 = strlen(sensorID) + 1;
                    nCar2 = sAux.length();                  
                    strcpy(sBuffFrame,sAux.substring(nCar1,nCar2).c_str());
                    if ( testSFrame()==true )
                       { // --------------------------------
                         // El formato es correcto
                         // --------------------------------
                         break;
                       }
                  }
             }
          else
             {
               Serial2.write("#f");
               delayMicroseconds(IDE_MAX_FRAME_DELAY);
               if ( nReintentos>=IDE_NUM_FRAME_REINTENTOS )
                  {
                    resultado = false;
                    break;
                  }
               else
                  {
                    nReintentos++;        
                  }
             }
        }
        
  Serial2.flush();   
 
  if ( resultado==false )
     { // ------------------------------------
       // No se han podido recuperar los datos
       // ------------------------------------
       sBuffFrame[0] = '\0';
     }
     
  return ( resultado );
}



// ---------------------------------------------------------
//
// byte SENSOR_RAZOR::testSFrame(void)
//
// ---------------------------------------------------------

byte SENSOR_RAZOR::testSFrame(void)
{
  byte resultado;
  byte nComas;
  byte indCar;
  byte numCar;
  

  resultado = true;
  nComas    = 0;
  numCar    = strlen(sBuffFrame);

  for ( indCar=0;indCar<numCar;indCar++ )
      { // ------------------------------------
        // Recorre el string para comprobar que 
        // tiene el  formato correcto, segun la
        // documentacion del sensor es:
        // valores x,y,z
        // ------------------------------------
        if ( sBuffFrame[indCar]==',' )
           {
             nComas++; 
           }
      }

  if ( nComas!=2 )
     { // ----------------------------------
       // El formato no es correcto
       // ----------------------------------
       resultado = false;
     }
  else
     { // ----------------------------------
       // Comprobaciones adicionales
       // ----------------------------------       
       switch( sBuffFrame[numCar-1] )
             {
               case( '\r' ):
                   { sBuffFrame[numCar-1] = '\0';
                     break;
                   }
               case( ',' ):
                   { 
                     resultado = false;
                     break;
                   }
             }
     }
     
  return( resultado );
}



// ---------------------------------------------------------
//
// char* SENSOR_RAZOR::getFrameAcc(void)
//
// ---------------------------------------------------------

char* SENSOR_RAZOR::getFrameAcc(void)
{

  getFrameSensor(IDE_SENSOR_ACC);
  
  if ( GLOBAL_FlgDebug==true )
     {
       Serial3.println(sBuffFrame);
     }
      
  return ( sBuffFrame );
}



// ---------------------------------------------------------
//
// char* SENSOR_RAZOR::getFrameMag(void)
//
// ---------------------------------------------------------

char* SENSOR_RAZOR::getFrameMag(void)
{

  getFrameSensor(IDE_SENSOR_MAG);
  
  if ( GLOBAL_FlgDebug==true )
     {
       Serial3.println(sBuffFrame);
     }
      
  return ( sBuffFrame );
}



// ---------------------------------------------------------
//
// char* SENSOR_RAZOR::getFrameGyr(void)
//
// ---------------------------------------------------------

char* SENSOR_RAZOR::getFrameGyr(void)
{

  getFrameSensor(IDE_SENSOR_GYR);
  
  if ( GLOBAL_FlgDebug==true )
     {
       Serial3.println(sBuffFrame);
     }
  
  return ( sBuffFrame );
}
