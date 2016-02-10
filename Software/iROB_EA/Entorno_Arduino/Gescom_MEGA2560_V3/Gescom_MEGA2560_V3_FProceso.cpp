
// --------------------------------------------------------------------
//
//                       GESCOM
//                 Gestor de comandos
//            Version para Arduino MEGA2560
//
// Autor:
// Fichero:        Gescom_MEGA2560_V3_FProceso.cpp
// Hardware:       -
// Version:        1.0
//
// Funcionalidad:  Procesador de Comandos
//
// Notas:          Este fichero se genera automaticamente desde la BBDD
//                 Gescom_MEGA2560_V3, ejecutando la Macro:
//                 "Genera_Ficheros_Resultado"
//
//
// -------------------------------------------------------------------


// -------------------------------------------------------------------

// Fecha Generación: 21/09/2015 , 12:21
// -------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include "Gescom_MEGA2560_V3.h"
#include "Gescom_MEGA2560_V3_CMD.h"






// ---------------------------------------------------------
//
// PRIVATE
// int GESCOM3:procesaComando_02(void)
// Procesa el comando recibido
//
// Retorna:
// . IDE_BUFF_RX_OK Comando correcto, procesado
// . IDE_BUFF_RX_ER Comando erroneo
//
// ---------------------------------------------------------

int GESCOM3::procesaComando_02(void)
{
  int resultado;


  gd.buffRespCmd[0] = '\0';


  switch ( gd.cnv_ComandoID )
         {



case ( IDE_CMD_CM_RSV): {  cmd_Comando_CM_RSV(&gd);  break; }


                case ( IDE_CMD_CM_RET): {  cmd_Comando_CM_RET(&gd);  break; }

                case ( IDE_CMD_CM_DBG): {  cmd_Comando_CM_DBG(&gd);  break; }
                case ( IDE_CMD_S_MDER): {  cmd_Comando_S_MDER(&gd);  break; }

                case ( IDE_CMD_S_MIZQ): {  cmd_Comando_S_MIZQ(&gd);  break; }

                case ( IDE_CMD_B_LIPO): {  cmd_Comando_B_LIPO(&gd);  break; }

                case ( IDE_CMD_B_PPAK): {  cmd_Comando_B_PPAK(&gd);  break; }

                case ( IDE_CMD_S_CDBG): {  cmd_Comando_S_CDBG(&gd);  break; }

                case ( IDE_CMD_S_MLX9): {  cmd_Comando_S_MLX9(&gd);  break; }

                case ( IDE_CMD_R_TIME): {  cmd_Comando_R_TIME(&gd);  break; }

                case ( IDE_CMD_L_LEDS): {  cmd_Comando_L_LEDS(&gd);  break; }

                case ( IDE_CMD_C_MIZQ): {  cmd_Comando_C_MIZQ(&gd);  break; }
                case ( IDE_CMD_C_MDER): {  cmd_Comando_C_MDER(&gd);  break; }

                case ( IDE_CMD_C_RMOV): {  cmd_Comando_C_RMOV(&gd);  break; }


         }

   resultado = enviaRespuesta();

   if ( resultado==true ) { resultado = IDE_BUFF_RX_OK; }
   else                   { resultado = IDE_BUFF_RX_ER; }

   return( resultado );
 }






