// ----------------------------------------------------------
//
//                       GESCOM 
//                 Gestor de comandos
//            Version para Arduino MEGA2560
// 
// Autor:
// Fichero:        gescom_MEGA2560_V3.h
// Hardware:       -
// Version:        3.0, Junio 2015
//
// Funcionalidad:  Procesador de Comandos
//
// Notas:          Especialmente dedicado a los constructores
//                 del Lunojod 1 Robot Ruso que en  Noviembre
//                 de 1970 se poso en la luna  y  alli sigue,
//                 prodigio de la tecnologia y el buen hacer.
//                 Esta   version   sustituye   el   include 
//                 <Wprogram.h>  por  el  nuevo <Arduino.h>
//                 Para  utilizar  las  nuevas versiones  del 
//                 entorno Arduino 1.0.0 en adelante. 
//
// ----------------------------------------------------------

#ifndef gescom_MEGA2560_V3_h
#define gescom_MEGA2560_V3_h

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>

  
// ----------------------------------------------------------
//
//
//        DEFINES RELACIONADOS CON EL PROCESADOR
//                     DE COMANDOS
//
// ----------------------------------------------------------

#define IDE_PAUSA_CAR_RX                2000             // Pausa en microsegundos para lectura de caracteres en recepcion
#define IDE_PAUSA_CAR_TX                5000             // Pausa en microsegundos para envio de datos

#define IDE_CAB_MAX_LEN                 5                // Longitud del identificador de inicio de comando (caracteres)
#define IDE_DES_MAX_LEN                 2                // Longitud de un identificador de origen (caracteres)
#define IDE_ORG_MAX_LEN                 2                // Longitud de un identificador de destino (caracteres)
#define IDE_TIP_MAX_LEN                 1                // Longitud de un identificador de tipo de comando (caracteres)
#define IDE_COM_MAX_LEN                 2                // Longitud de un identificador de comando o respuesta (caracteres)
#define IDE_PAR_MAX_LEN                 4                // Longitud de un parametro de un comando (caracteres)


#define IDE_MAX_BUFFER_TX               200              // Buffer de Transmision ( ver funcion  debugComando )
#define IDE_MAX_COMANDO_CCABECERA      (byte)(IDE_CAB_MAX_LEN + IDE_DES_MAX_LEN + IDE_ORG_MAX_LEN + IDE_TIP_MAX_LEN + IDE_COM_MAX_LEN + (IDE_PAR_MAX_LEN*2))
#define IDE_MAX_COMANDO_SCABECERA      (byte)(                  IDE_DES_MAX_LEN + IDE_ORG_MAX_LEN + IDE_TIP_MAX_LEN + IDE_COM_MAX_LEN + (IDE_PAR_MAX_LEN*2))

#define IDE_CABECERA_CARACTER           35               // La cabecera de un comando consta de n caracteres con este ASCII(#) ( IDE_CAB_MAX_LEN )

#define IDE_MAX_CAR_ERRONEOS            50               // Numero maximo de caracteres no validos que se pueden recibir durante la recepcion de comandos
#define IDE_GESCOM_CMD_ERROR            "CMD_ERR"        // Error

#define IDE_MAXL_RESP_CMD               25               // Tamaño del Buffer de respuesta de comando

// ---------------------------------------------------------
//
// Identificadores para depuracion
//
// ---------------------------------------------------------
                                                      
#define IDE_DEBUG_COMANDO  1
#define IDE_DEBUG_NO      -1

// ----------------------------------------------------------
// Seleccionar puerto serie a utilizar 
// DEPENDE de la placa autilizar, por defecto se utiliza el 
// puerto serie 0 que todos los Arduinos tienen
// ----------------------------------------------------------

#define IDE_SERIAL_0               0
#define IDE_SERIAL_1               1
#define IDE_SERIAL_2               2
#define IDE_SERIAL_3               3 

// ---------------------------------------------------------
//
// Variables utilizadas por el procesador de comandos
//
// ---------------------------------------------------------
                                                     // Defines para determinar que se ha recibido en el buffer de RX
#define IDE_BUFF_RX_OK        0                      // Se ha recibido algo valido, que hay que procesar 
#define IDE_BUFF_RX_VACIO     1                      // NO Se ha recibido nada
#define IDE_BUFF_RX_ER        2                      // Se ha recibido algo que no es valido


// ---------------------------------------------------------
//
// ---------------------------------------------------------
struct gescom_data
{
   unsigned int    cnv_DesID;                              // Valor numerico del Identificador de destino
   unsigned int    cnv_OrgID;                              // Valor numerico del Identificador de origen
   unsigned int    cnv_Tipo;                               // Valor numerico del tipo de comando 
   unsigned int    cnv_ComandoID;                          // Valor numerico del ID del comando 
   unsigned int    cnv_Param01;                            // Valor numerico del parametro 1
   unsigned int    cnv_Param02;                            // Valor numerico del parametro 2
   char            buffRespCmd[IDE_MAXL_RESP_CMD+1];       // Buffer de respuesta
   HardwareSerial* serialPtr;                              // Puntero al manejador del puerto serie eutilizado
};

typedef struct gescom_data GESCOM_DATA;



// ---------------------------------------------------------
//
// Definicion de la clase GESCOM
//
// ---------------------------------------------------------

class GESCOM3
{
  public:

         
         GESCOM3        (int puertoID,int debug,int elementoID, long int velocidad);
    int  exeGesComando  (void);
    int  getBytes       (char* buff, int nBytes);
    void begin          (void);
 
  
  private:

   int  getTrama_RX         (void);
   int  scanComandos        (void);
   int  procesaComando_01   (void);
   int  procesaComando_02   (void);
   int  testGescomID        (void);
   int  testTipoComando     (void);
   int  enviaRespuesta      (void);
   int  debug_Comando       (void);
   void iniBuffer_RX        (void);
   void iniBuffer_TX        (void);
   void iniBuffer_Parciales (void);
   


   char buffer_TX[IDE_MAX_BUFFER_TX+1];                 // Buffer de transmision   
   char buffer_RX[IDE_MAX_COMANDO_SCABECERA+1];         // Buffer de recepcion
   int  nBytes_RX;                                      // Numero de caracteres recibidos en el buffer del puerto serie, retornado por Serial.available() 
   int  pID;                                            // Identifica el puerto serie a utilizar, utiliza los defines
                                                        // SERIAL_0
                                                        // SERIAL_1
                                                        // SERIAL_2
                                                        // SERIAL_3
   GESCOM_DATA     gd;                                  // Datos del comando manejado 
   int             opcDebug;                            // Habilitar/Deshabilitar opcion de DEBUG
   int             miID;                                // Variable para almacenar el identificador de este elemento 
   long int        velocidad;                           // Variable para almacenar la velocidad del puerto serie

                                                        // Se inicializa en la llamada al contructor de GESCOM
                                                        
                                                        // ---------------------------------------------------------
                                                        // Bufferes PARCIALES para procesado del comando recibido
                                                        // lo recibido estara en buffer_RX
                                                        // ---------------------------------------------------------

   char         cmd_Cabecera  [IDE_CAB_MAX_LEN+1];      // Buffer para almacenar el ID del comando recibido
   char         cmd_DesID     [IDE_DES_MAX_LEN+1];      // Buffer para almacenar el identificador del destino
   char         cmd_OrgID     [IDE_ORG_MAX_LEN+1];      // Buffer para almacenar el identificador del origen
   char         cmd_Tipo      [IDE_TIP_MAX_LEN+1];      // Buffer para almacenar el identificador del tipo de comando
   char         cmd_ComandoID [IDE_COM_MAX_LEN+1];      // Buffer para almacenar el ID del comando recibido
   char         cmd_Param01   [IDE_PAR_MAX_LEN+1];      // Buffer para almacenar el PRIMER  parametro recibido
   char         cmd_Param02   [IDE_PAR_MAX_LEN+1];      // Buffer para almacenar el SEGUNDO parametro recibido

};






#endif

