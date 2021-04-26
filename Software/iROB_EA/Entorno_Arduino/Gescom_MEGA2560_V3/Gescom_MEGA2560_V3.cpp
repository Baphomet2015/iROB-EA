// ----------------------------------------------------------
//
//                       GESCOM 
//                 Gestor de comandos
//            Version para Arduino MEGA2560
// 
// Autor:
// Fichero:        gescom_MEGA2560_V3.cpp
// Hardware:       -
// Version:        3.0, Junio 2015
//
// Funcionalidad:  Procesador de Comandos
//
// Notas:          
//                 
//                 
//                 
// ----------------------------------------------------------
                  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include "Gescom_MEGA2560_V3.h"
#include "Gescom_MEGA2560_V3_CMD.h"



  
                   

// ---------------------------------------------------------
//
//
//
//         FUNCIONES DE IMPLEMENTADOR DEL MANEJADOR
//                       DE COMANDOS
//
//
//
//
//
//
//
//
// ---------------------------------------------------------


// ---------------------------------------------------------
//
// GESCOM3::GESCOM3( int      puertoID    ,
//                   int      debug       ,
//                   byte     elementoID  ,
//                   long int velocidadID 
//                 )
//              Constructor: Si se recibe un puertoID no valido
//              deja seleccionado el puerto 0
// Constructor
//
// ---------------------------------------------------------

GESCOM3::GESCOM3(int puertoID,int debug,int elementoID,long int velocidadID)
{
   
       if ( puertoID==IDE_SERIAL_1 )
          { 
            pID          = IDE_SERIAL_1;
            gd.serialPtr = &Serial1;
          }
          
  else if ( puertoID==IDE_SERIAL_2 )
          { 
            pID          = IDE_SERIAL_2;
            gd.serialPtr = &Serial2;
          }
          
  else if ( puertoID==IDE_SERIAL_3 )
          { 
            pID          = IDE_SERIAL_3;
            gd.serialPtr = &Serial3;
          }
          
       else 
          { 
            pID          = IDE_SERIAL_0;
            gd.serialPtr = &Serial;
          }
 
  velocidad = velocidadID;
  opcDebug  = debug;
  miID      = elementoID;
  
  iniBuffer_TX();
}



// ---------------------------------------------------------
//
// PUBLIC
// void GESCOM3::exeGesComando(void)
//
// Procesa  el string recibido por el puerto serie, si se ha 
// recibido algo
//
// ---------------------------------------------------------

void GESCOM3::begin(void)
{

  gd.serialPtr->begin(velocidad);
  
}



// ---------------------------------------------------------
//
// PUBLIC
// int GESCOM3::exeGesComando(void)
//
// Procesa  el string recibido por el puerto serie, si se ha 
// recibido algo
// Retorna:
//        IDE_BUFF_RX_OK    Se ha recibdo  algo valido
//        IDE_BUFF_RX_ER    Se ha recibido algo erroneo 
//        IDE_BUFF_RX_VACIO NO se ha recibido nada
//
// ---------------------------------------------------------

int GESCOM3::exeGesComando(void)
{
  int resultado;


  resultado = scanComandos();
     
  return( resultado );
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3::scanComandos(void)
//
// Lee caracteres del buffer de recepcion (buffer_RX )y busca comandos
//
//
//
// ---------------------------------------------------------

int GESCOM3::scanComandos(void)
{
  int  resultado;
  int  iniSincronismo;
  int  flgComando;
  int  numCarErroneos;
  byte cCar;
  

  resultado      = IDE_BUFF_RX_VACIO;
  iniSincronismo = 0;
  numCarErroneos = 0;
  flgComando     = false;

  while( (gd.serialPtr->available()>0) && (numCarErroneos<IDE_MAX_CAR_ERRONEOS) )
       { // ---------------------------------------------------------
         //
         //
         //
         // ---------------------------------------------------------
         cCar = (byte)gd.serialPtr->read();  
                
         if ( flgComando==false ) 
            { // ---------------------------------------------------------
              // Recuperando cabecera del comando
              // ---------------------------------------------------------
              if ( iniSincronismo==IDE_CAB_MAX_LEN )
                 {
                   iniBuffer_RX();
                   flgComando = true;
                 }
              else
                 {
                   if ( cCar==IDE_CABECERA_CARACTER )
                      { 
                        cmd_Cabecera[iniSincronismo++] = cCar;
                        cmd_Cabecera[iniSincronismo  ] = '\0';
                      }  
                   else 
                      { 
                        numCarErroneos++;
                        iniSincronismo = 0;
                      } 
                 }
            }

         if ( flgComando==true ) 
            { // ---------------------------------------------------------
              // Recuperando el comando
              // ---------------------------------------------------------
              buffer_RX[nBytes_RX++] = cCar; 
              buffer_RX[nBytes_RX  ] = '\0'; 
              
              if ( nBytes_RX==IDE_MAX_COMANDO_SCABECERA ) 
                 {
                   resultado = procesaComando_01();
                   break;
                 }
            }   
            
         delayMicroseconds(IDE_PAUSA_CAR_RX);  
       }              
 
  if ( numCarErroneos>IDE_MAX_CAR_ERRONEOS )
     {
       resultado = IDE_BUFF_RX_ER;
     }
 
  return( resultado );
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3:procesaComando_01(void)
// Procesa el comando recibido
//
// Retorna: IDE_BUFF_RX_OK

//
// ---------------------------------------------------------

int GESCOM3::procesaComando_01(void)
{
  int indBuff;
  int resultado;
    
  
  indBuff   = 0;
  resultado = IDE_BUFF_RX_ER;
  iniBuffer_Parciales();
  

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_DesID[0] = buffer_RX[indBuff++]; 
  cmd_DesID[1] = buffer_RX[indBuff++]; 
  cmd_DesID[2] = '\0';
  gd.cnv_DesID = (unsigned int) strtol(cmd_DesID, NULL, 16);

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_OrgID[0] = buffer_RX[indBuff++]; 
  cmd_OrgID[1] = buffer_RX[indBuff++]; 
  cmd_OrgID[2] = '\0';
  gd.cnv_OrgID = (unsigned int) strtol(cmd_OrgID, NULL, 16);

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_Tipo[0]  = buffer_RX[indBuff++]; 
  cmd_Tipo[1]  = '\0';
  gd.cnv_Tipo  = (unsigned int) strtol(cmd_Tipo, NULL, 16);

  // --------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_ComandoID[0] = buffer_RX[indBuff++];
  cmd_ComandoID[1] = buffer_RX[indBuff++];
  cmd_ComandoID[2] = '\0';
  gd.cnv_ComandoID = (unsigned int) strtol(cmd_ComandoID, NULL, 16);

  // --------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_Param01[0] = buffer_RX[indBuff++];
  cmd_Param01[1] = buffer_RX[indBuff++];
  cmd_Param01[2] = buffer_RX[indBuff++];
  cmd_Param01[3] = buffer_RX[indBuff++];
  cmd_Param01[4] = '\0';
  gd.cnv_Param01 = (unsigned int) strtol(cmd_Param01, NULL, 16);
  
  // --------------------------------------------------------
  //
  // ---------------------------------------------------------
  cmd_Param02[0] = buffer_RX[indBuff++];
  cmd_Param02[1] = buffer_RX[indBuff++];
  cmd_Param02[2] = buffer_RX[indBuff++];
  cmd_Param02[3] = buffer_RX[indBuff];
  cmd_Param02[4] = '\0';
  gd.cnv_Param02 = (unsigned int) strtol(cmd_Param02, NULL, 16);

  gd.buffRespCmd[0] = '\0';

  if ( testGescomID()==IDE_BUFF_RX_OK )
     {
       if ( testTipoComando()==IDE_BUFF_RX_OK )
          {
            if ( opcDebug==IDE_DEBUG_COMANDO ) { resultado = debug_Comando();     }
            else                               { resultado = procesaComando_02(); }
          }
     }
 
  return ( resultado ); 
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3::enviaRespuesta(void)
//
//
//
// ---------------------------------------------------------

int GESCOM3::enviaRespuesta(void)
{
  int          resultado;
  unsigned int maxLen;
  

  resultado = IDE_BUFF_RX_OK;

  maxLen = strlen(gd.buffRespCmd);
  if ( maxLen!=0 )
     {
       sprintf( buffer_TX,"%s%s%s%d%s%04X%04X" ,
                cmd_Cabecera                   ,
                cmd_OrgID                      ,
                cmd_DesID                      ,
                IDE_T_COMANDO_RESPUESTA        ,       
                cmd_ComandoID                  ,
                0                              ,
                maxLen                     
              );

       gd.serialPtr->print(buffer_TX);
       gd.serialPtr->print(gd.buffRespCmd);
       delayMicroseconds(IDE_PAUSA_CAR_TX);  
     }
  else   
     {
       sprintf( buffer_TX,"%s%s%s%d%s%04X%04X" ,
                cmd_Cabecera                   ,
                cmd_OrgID                      ,
                cmd_DesID                      ,
                IDE_T_COMANDO_RESPUESTA        ,       
                cmd_ComandoID                  ,
                0                              ,
                0                     
              );

       gd.serialPtr->print(buffer_TX);
       delayMicroseconds(IDE_PAUSA_CAR_TX);  
     }

  return( resultado );
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3::debug_Comando(void)
//
// Para ver el contendio de un comando como es de depuracion
// NO añade cabecera ni tiene el formato de un comando en si
//
// ---------------------------------------------------------

int GESCOM3::debug_Comando(void)
{
  sprintf( buffer_TX                                                                                        , 
           "[CABECERA: %s] [DESTINO: %s] [ORIGEN: %s] [TIPO: %s] [COMANDO: %s] [PARAM01: %s] [PARAM02: %s]" ,
           cmd_Cabecera  ,
           cmd_DesID     ,
           cmd_OrgID     ,
           cmd_Tipo      ,
           cmd_ComandoID ,
           cmd_Param01   ,
           cmd_Param02
         );

  gd.serialPtr->println(buffer_TX);
  delayMicroseconds(IDE_PAUSA_CAR_TX);  
  
  return ( IDE_BUFF_RX_OK );
}



// ---------------------------------------------------------
//
// PRIVATE
// void GESCOM3::iniBuffer_TX(void)
//
// Inicializa los buffers locales
//
// ---------------------------------------------------------

void GESCOM3::iniBuffer_TX(void)
{
  gd.serialPtr->flush(); 
  buffer_TX[0] = '\0'; 
}


// ---------------------------------------------------------
//
// PRIVATE
// void GESCOM3::iniBuffer_RX(void)
//
// Inicializa los buffers locales
//
// ---------------------------------------------------------

void GESCOM3::iniBuffer_RX(void)
{
  nBytes_RX    = 0;
  buffer_RX[0] = '\0'; 
}



// ---------------------------------------------------------
//
// PRIVATE
// void GESCOM3::iniBuffer_Parciales(void)
//
// Inicializa los buffers locales
//
// ---------------------------------------------------------

void GESCOM3::iniBuffer_Parciales(void)
{
  cmd_DesID    [0] = '\0'; 
  cmd_OrgID    [0] = '\0'; 
  cmd_Tipo     [0] = '\0'; 
  cmd_ComandoID[0] = '\0'; 
  cmd_Param01  [0] = '\0'; 
  cmd_Param02  [0] = '\0'; 
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3::testGescomID(void)
//
//
// ---------------------------------------------------------

int GESCOM3::testGescomID(void)
{
  int resultado;
  
  if ( gd.cnv_DesID==miID ) { resultado = IDE_BUFF_RX_OK;    }  
  else                      { resultado = IDE_BUFF_RX_VACIO; }  
  
  return( resultado );  
}



// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3::testTipoComando(void)
//
//
// ---------------------------------------------------------

int GESCOM3::testTipoComando(void)
{
  int resultado;
  

  if ( gd.cnv_Tipo==IDE_T_COMANDO_ENVIO ) { resultado = IDE_BUFF_RX_OK;    }  
  else                                    { resultado = IDE_BUFF_RX_VACIO; }  
  
  return( resultado );  
}



// ---------------------------------------------------------
//
// PRIVATE
// GESCOM3::getBytes(char* buff, int nBytes)
//
//
// ---------------------------------------------------------

int GESCOM3::getBytes(char* buff, int nBytes)
{
  int resultado;
  

  resultado = gd.serialPtr->readBytes(buff,nBytes);
  if ( resultado==nBytes )
     {
       buff[nBytes] = '\0';
     }
  else
     {
       buff[0]   = '\0';
       resultado = 0;
     }
  
  return( resultado );  
}
