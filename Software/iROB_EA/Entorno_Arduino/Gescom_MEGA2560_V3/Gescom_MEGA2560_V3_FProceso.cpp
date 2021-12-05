
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

// Fecha Generación: 01/12/2021 , 13:43
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



case ( IDE_CMD_CM_R00): {  cmd_Comando_CM_R00(&gd);  break; }


                case ( IDE_CMD_CM_R01): {  cmd_Comando_CM_R01(&gd);  break; }

                case ( IDE_CMD_CM_DBG): {  cmd_Comando_CM_DBG(&gd);  break; }
                case ( IDE_CMD_CM_RTC): {  cmd_Comando_CM_RTC(&gd);  break; }

                case ( IDE_CMD_CM_CTR): {  cmd_Comando_CM_CTR(&gd);  break; }

                case ( IDE_CMD_B_PPAK): {  cmd_Comando_B_PPAK(&gd);  break; }

                case ( IDE_CMD_C_LEDS): {  cmd_Comando_C_LEDS(&gd);  break; }

                case ( IDE_CMD_C_MIZQ): {  cmd_Comando_C_MIZQ(&gd);  break; }

                case ( IDE_CMD_C_MDER): {  cmd_Comando_C_MDER(&gd);  break; }

                case ( IDE_CMD_C_RMOV): {  cmd_Comando_C_RMOV(&gd);  break; }

                case ( IDE_CMD_C_SRVX): {  cmd_Comando_C_SRVX(&gd);  break; }

                case ( IDE_CMD_C_SRVY): {  cmd_Comando_C_SRVY(&gd);  break; }
                case ( IDE_CMD_S_TEMP): {  cmd_Comando_S_TEMP(&gd);  break; }

                case ( IDE_CMD_S_HUMR): {  cmd_Comando_S_HUMR(&gd);  break; }

                case ( IDE_CMD_S_GLUZ): {  cmd_Comando_S_GLUZ(&gd);  break; }

                case ( IDE_CMD_S_SSUP): {  cmd_Comando_S_SSUP(&gd);  break; }

                case ( IDE_CMD_S_RGPS): {  cmd_Comando_S_RGPS(&gd);  break; }

                case ( IDE_CMD_S_SICC): {  cmd_Comando_S_SICC(&gd);  break; }

                case ( IDE_CMD_S_SEUS): {  cmd_Comando_S_SEUS(&gd);  break; }

                case ( IDE_CMD_S_CFAN): {  cmd_Comando_S_CFAN(&gd);  break; }

                case ( IDE_CMD_S_SALT): {  cmd_Comando_S_SALT(&gd);  break; }
                case ( IDE_CMD_S_PRES): {  cmd_Comando_S_PRES(&gd);  break; }

                case ( IDE_CMD_C_RELE): {  cmd_Comando_C_RELE(&gd);  break; }

                case ( IDE_CMD_C_STPC): {  cmd_Comando_C_STPC(&gd);  break; }

                case ( IDE_CMD_S_9DOF): {  cmd_Comando_S_9DOF(&gd);  break; }


         }

   resultado = enviaRespuesta();

   if ( resultado==true ) { resultado = IDE_BUFF_RX_OK; }
   else                   { resultado = IDE_BUFF_RX_ER; }

   return( resultado );
 }






