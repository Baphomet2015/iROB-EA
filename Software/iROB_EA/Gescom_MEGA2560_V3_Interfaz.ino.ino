// ----------------------------------------------------------
//
//                       GESCOM 
//                 Gestor de comandos
//            Version para Arduino MEGA2560
// 
// Autor:
// Fichero:        gescom_MEGA2560_Fn_V3.cpp
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
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include "UF_SYS.h"
#include <Gescom_MEGA2560_V3.h>
#include <Gescom_MEGA2560_V3_CMD.h>


  






// ---------------------------------------------------------
//
//
//
//         FUNCIONES DE IMPLEMENTACION DE COMANDOS
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
// void cmd_Comando_CM_DBG(GESCOM_DATA* gd)
//
// Uso:      
// Sintaxis: 
//           comando:    IDE_CMD_DBG
//           parametro1: -
//           parametro2: -
//
// Retorna:
// 
// ---------------------------------------------------------

void cmd_Comando_CM_DBG(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();








}



// ---------------------------------------------------------
//
// void cmd_Comando_CM_RET(GESCOM_DATA* gd)
//
// Uso:      
// Sintaxis: 
//           comando:    IDE_CMD_RET
//           parametro1: -
//           parametro2: -
//
// Retorna:
// 
// ---------------------------------------------------------

void cmd_Comando_CM_RET(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE(); 







}



// ---------------------------------------------------------
//
// void cmd_Comando_CM_RSV(GESCOM_DATA* gd)
//
// Uso:      
// Sintaxis: 
//           comando:    IDE_CMD_S_RSV
//           parametro1: -
//           parametro2: -
//
// Retorna:
// 
// ---------------------------------------------------------

void cmd_Comando_CM_RSV(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE(); 






}




// ---------------------------------------------------------
//
// void cmd_Comando_S_MDER(GESCOM_DATA* gd)
//
// Uso:      
// Sintaxis: 
//           comando:    IDE_CMD_S_MDER
//           parametro1: -
//           parametro2: -
//
// Retorna:
// . True  Todo correcto
// . False Error en la ejecucion
// 
// ---------------------------------------------------------

void cmd_Comando_S_MDER(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();





}



// ---------------------------------------------------------
//
// void cmd_Comando_S_MIZQ( unsigned int tComando,
//
// Uso:      
// Sintaxis: 
//           comando:    IDE_CMD_S_MIZQ
//           parametro1: -
//           parametro2: -
//
// Retorna:
//
// 
// ---------------------------------------------------------

void cmd_Comando_S_MIZQ(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();






}



// ---------------------------------------------------------
//
// void cmd_Comando_B_LIPO(GESCOM_DATA* gd)
//
// Uso:      Retorna informacion relacionada con la bateria
//           de LiPo
// Sintaxis: 
//           comando:    IDE_CMD_B_LIPO
//           parametro1: IDE_PARAM_GET
//           parametro2: IDE_PARAM_CHG
//                       IDE_PARAM_POW
// Retorna:
// . Valor en hexadecimal solicitado
// 
// ---------------------------------------------------------

void cmd_Comando_B_LIPO(GESCOM_DATA* gd)
{
  double iMedida;
  double tiempo;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida   de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       //
       // ---------------------------------------------------------
       switch(gd->cnv_Param02)
             {
               case (IDE_PARAM_CHG):
                    {
                      iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_LIPO);
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     
                      break;
                    }

               case (IDE_PARAM_POW):
                    { // ---------------------------------------------------------
                      // El consumo de la bateria se obtiene de  la  suma  de  los
                      // consumos de cada motor por eso NO hay un sensor específico
                      // para medir este consumo.
                      // ---------------------------------------------------------




                      break;
                    }

               default:
                    {
                   
                      break;
                    }
             }        
       
    }
}



// ---------------------------------------------------------
//
// void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
//
// Uso:      Retorna informacion relacionada con la bateria
//           de PowerPack
// Sintaxis: 
//           comando:    IDE_CMD_B_PPAK
//           parametro1: IDE_PARAM_GET
//           parametro2: IDE_PARAM_CHG
//                       IDE_PARAM_POW
// Retorna:
// . Valor en hexadecimal solicitado
// 
// ---------------------------------------------------------

void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
{
  double iMedida;
  double tiempo;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();

  
  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------
       switch(gd->cnv_Param02)
             { 
               case (IDE_PARAM_CHG):
                    {
                      iMedida = uf_sys.get_Corriente(PIN_HW_BAT_CHG_PPAK);
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     
                      break;
                    }

               case (IDE_PARAM_POW):
                    {  
                      iMedida  = uf_sys.get_Corriente(PIN_HW_BAT_CHG_PPAK);
                      tiempo   = (IDE_CAPACIDAD_BAT_PPAK/iMedida) * 0.7;
                      dtostrf(tiempo, 4, 1, gd->buffRespCmd);     
                      break;
                    }

               default:
                    {
                   
                      break;
                    }
             }
    }
}



// ---------------------------------------------------------
//
// void cmd_Comando_S_CDBG(GESCOM_DATA* gd)
//
// Uso:       Retorna valor del flag hardware que indica si 
//            esta conectado el conector de DEBUG
// Sintaxis: 
//           comando:    IDE_CMD_S_DBG
//           parametro1: IDE_PARAM_GET
//           parametro2: IDE_PARAM_NOP
//
// Retorna:
//          "00" NO esta conectado
//          "01" SI esta conectado
//          "02" Error de comando
// 
// ---------------------------------------------------------

void cmd_Comando_S_CDBG(GESCOM_DATA* gd)
{
  int v;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------
       if ( uf_sys.get_FlgDebug()==true) { sprintf(gd->buffRespCmd,"01"); }
       else                              { sprintf(gd->buffRespCmd,"00"); }
     }
  else
     {
       sprintf(gd->buffRespCmd,"02");
     }
      
}



// ---------------------------------------------------------
//
// void cmd_Comando_R_TIME( GESCOM_DATA* gd )
//
// Uso:  Control del reloj de tiempo real 
// Sintaxis: comando:    IDE_CMD_R_TIME
//
//           parametro1: IDE_PARAM_GET 
//                       IDE_PARAM_SET  
//                       IDE_PARAM_CHK
//                       IDE_PARAM_INI
//
//           parametro2: IE_PARAM_NOP
//                       valor
//
// Retorna:
//          "00"              Error de comando
//          "01"              Comando ejecutado
//          "AAAAMMDD HHMMSS" La fecha/hora actual
// 
// ---------------------------------------------------------

void cmd_Comando_R_TIME(GESCOM_DATA* gd)
{
  int  v;
  int  vAnno;
  int  vMes;
  int  vDia;
  int  vHor;
  int  vMin;
  int  vSeg;
  int  resultado;
  int  flg;
  char buff[IDE_MAXBUFF_GENERICO+1];


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;
  flg       = false;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------
       switch(gd->cnv_Param01)
             {
               case ( IDE_PARAM_GET ):
                    { // ---------------------------------------------------------
                      // GET: Retonar Fecha y Hora del RTC
                      //      Retorna: "AAAAMMDD HHMMSS"
                      // ---------------------------------------------------------
                     
                      DateTime now = rtc.now();

                      sprintf( gd->buffRespCmd              ,
                               "%04d%02d%02d %02d%02d%02d"  ,
                                now.year()                  ,
                                now.month()                 ,   
                                now.day()                   ,       
                                now.hour()                  ,
                                now.minute()                ,
                                now.second()
                             );
                      flg = true;  
                      break;
                    }

               case ( IDE_PARAM_SET ):
                    { // ---------------------------------------------------------
                      // SET: Establecer Fecha y Hora del RTC
                      //      Espera un string en la forma: "AAAAMMDD HHMMSS"
                      //      Retorna  "00" Error
                      //                "01" Ok se ha establecido los nueva fecha/hora
                      // ---------------------------------------------------------

                      v = gd->cnv_Param02;
                      
                      if ( gc.getBytes(gd->buffRespCmd,v)==v ) 
                         {
                           sscanf( gd->buffRespCmd             ,
                                   "%04d%02d%02d %02d%02d%02d" , 
                                   &vAnno                      ,
                                   &vMes                       ,
                                   &vDia                       ,
                                   &vHor                       ,
                                   &vMin                       ,
                                   &vSeg 
                                 );
                           rtc.adjust(DateTime(vAnno, vMes, vDia, vHor, vMin, vSeg));
                         }
                      else
                         {
                           resultado = false;
                         }

                      break;
                    }

               case ( IDE_PARAM_CHK ):
                    { // ---------------------------------------------------------
                      // CHK: Comprobar funcionamiento del RTC
                      //      Retorna  "00" No se esta ejecutando
                      //               "01" si se esta ejecutando   
                      // ---------------------------------------------------------
                      
                      if (!rtc.isrunning() )
                         { 
                           resultado = false;
                         }
                      
                      break;
                    }

               case ( IDE_PARAM_INI ):
                    { // ---------------------------------------------------------
                      // INI: Iniciar RTC
                      //      Retorna "01"
                      // ---------------------------------------------------------
                      rtc.begin();
                      break;
                    }
               
               default:
                    {
                      resultado = false;
                      break;
                    }

             }
     }
 else
     {
       resultado = false;
     }

  if (flg==false)
     {
       if (resultado==false) { sprintf(gd->buffRespCmd,"00"); }   
       else                  { sprintf(gd->buffRespCmd,"01"); }    
     }
  
}



// ---------------------------------------------------------
//
// void cmd_Comando_L_LEDS( GESCOM_DATA* gd )
//
// Uso: Control de los leds      
// Sintaxis: 
//           comando:    IDE_CMD_L_LEDS    
//
//           parametro1: IDE_PARAM_LD1
//                       IDE_PARAM_LD2 
//                       IDE_PARAM_LD3 
//
//           parametro2: IDE_PARAM_OFF
//                       IDE_PARAM__ON
//                       IDE_PARAM_BLK
//
// Retorna:
//          "00" Error de comando
//          "01" Comando ejecutado
//
// 
// ---------------------------------------------------------

void cmd_Comando_L_LEDS(GESCOM_DATA* gd)
{
  int ledID;
  int resultado;
 

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------

       if (resultado==true)
          {
            switch(gd->cnv_Param01)
                  {
                    case (IDE_PARAM_LD1): { ledID = IDE_LED_BDEL; break; }
                    case (IDE_PARAM_LD2): { ledID = IDE_LED_BDET; break; }
                    case (IDE_PARAM_LD3): { ledID = IDE_LED_RDET; break; }
                    default:              { resultado = false;    break; }
                  }
          } 

       if (resultado==true)
          {
            switch(gd->cnv_Param02)
                  {
                    case (IDE_PARAM_OFF): { uf_sys.setLed(ledID,IDE_LED_OFF); break; }
                    case (IDE_PARAM__ON): { uf_sys.setLed(ledID,IDE_LED_ON);  break; }
                    case (IDE_PARAM_BLK): { uf_sys.setLed(ledID,IDE_LED_BLK); break; }
                    default:              { resultado = false;                break; }
                  }
          }
     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { sprintf(gd->buffRespCmd,"00"); }
  else                   { sprintf(gd->buffRespCmd,"01"); }

}



// ---------------------------------------------------------
//
// void cmd_Comando_S_MLX9( GESCOM_DATA* gd )
//
// Uso: Control del sensor de Temperatura MLX 90614
// Sintaxis: 
//           comando:    IDE_CMD_S_MLX9    
//
//           parametro1: IDE_PARAM_GET
//
//           parametro2: IDE_PARAM_SMA
//                       IDE_PARAM_SMB    
//
// Retorna:
//
// 
// ---------------------------------------------------------

void cmd_Comando_S_MLX9(GESCOM_DATA* gd)
{
  
  int resultado;
 

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       // !!! Comprobar qu el sensor sea la version de 5 voltios 
       //
       // ---------------------------------------------------------

       switch(gd->cnv_Param01)
             {
               case ( IDE_PARAM_GET ):
                    { // ---------------------------------------------------------
                      // GET: Retonar Medicion
                      // ---------------------------------------------------------
                      switch(gd->cnv_Param02)
                            {
                              case (IDE_PARAM_SSA):
                                   { sprintf( gd->buffRespCmd,"%03d",mlx.readAmbientTempC());
                                     break;
                                   }
                              case (IDE_PARAM_SSB):
                                   { 
                                     sprintf( gd->buffRespCmd,"%03d",mlx.readObjectTempC());
                                     break;
                                   }
                              default:              { resultado = false;                                       break; }
                            }
                      break;
                    }
               default:
                    { 
                      resultado = false;
                      break;
                    }
             }

     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { sprintf(gd->buffRespCmd,"000"); }
  
}



// ---------------------------------------------------------
//
// void cmd_Comando_C_MIZQ(GESCOM_DATA* gd)
//
// Uso: Control del motor izquierdo
// Sintaxis: 
//           comando:    IDE_CMD_C_MIZQ    
//
//           parametro1: IDE_PARAM_INI
//                       IDE_PARAM_GDE
//                       IDE_PARAM_AVA
//                       IDE_PARAM_SVE
//                       IDE_PARAM_STO
//                       IDE_PARAM_GIZ
//
//           parametro2: IDE_PARAM_NOP
//                       valor
//
// Retorna:
//
// 
// ---------------------------------------------------------

void cmd_Comando_C_MIZQ(GESCOM_DATA* gd)
{
  
  int resultado;

// ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       // !!! Comprobar qu el sensor sea la version de 5 voltios 
       //
       // ---------------------------------------------------------

       switch(gd->cnv_Param01)
             {
               case (IDE_PARAM_INI): { mIzq.paro();       break; }
               case (IDE_PARAM_AVA): { mIzq.avance();     break; }
               case (IDE_PARAM_RET): { mIzq.retroceso();  break; }
               case (IDE_PARAM_STO): { mIzq.paro();       break; }
               case (IDE_PARAM_SVE): {                    break; }
               default:              { resultado = false; break; }
             }




     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { sprintf(gd->buffRespCmd,"000"); }

}




// ---------------------------------------------------------
//
// void cmd_Comando_C_MDER(GESCOM_DATA* gd)
//
// Uso: Control del motor derecho
// Sintaxis: 
//           comando:    IDE_CMD_C_MDER    
//
//           parametro1: IDE_PARAM_INI
//                       IDE_PARAM_GDE
//                       IDE_PARAM_AVA
//                       IDE_PARAM_SVE
//                       IDE_PARAM_STO
//                       IDE_PARAM_GIZ
//
//           parametro2: IDE_PARAM_NOP
//                       valor
//
//
// Retorna:
//
// 
// ---------------------------------------------------------

void cmd_Comando_C_MDER(GESCOM_DATA* gd)
{
    
  int resultado;

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       // !!! Comprobar qu el sensor sea la version de 5 voltios 
       //
       // ---------------------------------------------------------

       switch(gd->cnv_Param01)
             {
               case (IDE_PARAM_INI): { mDer.paro();       break; }
               case (IDE_PARAM_AVA): { mDer.avance();     break; }
               case (IDE_PARAM_RET): { mDer.retroceso();  break; }
               case (IDE_PARAM_STO): { mDer.paro();       break; }
               case (IDE_PARAM_SVE): {                    break; }
               default:              { resultado = false; break; }
             }




     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { sprintf(gd->buffRespCmd,"000"); }

}



// ---------------------------------------------------------
//
// void cmd_Comando_C_RMOV(GESCOM_DATA* gd)
//
// Uso: Generación de movimiento
// Sintaxis: 
//           comando:    IDE_CMD_C_RMOV    
//
//           parametro1: IDE_PARAM_INI
//                       IDE_PARAM_GDE
//                       IDE_PARAM_AVA
//                       IDE_PARAM_SVE
//                       IDE_PARAM_STO
//                       IDE_PARAM_GIZ
//
//           parametro2: IDE_PARAM_NOP
//                       valor
//
//
// Retorna:
//
// 
// ---------------------------------------------------------

void cmd_Comando_C_RMOV(GESCOM_DATA* gd)
{
    
  int resultado;

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medidad  de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();


  resultado = true;

  if ( gd->cnv_Tipo==IDE_T_COMANDO_ENVIO )
     { // ---------------------------------------------------------
       //
       // !!! Comprobar qu el sensor sea la version de 5 voltios 
       //
       // ---------------------------------------------------------

       switch(gd->cnv_Param01)
             {
               case (IDE_PARAM_INI): { mDer.paro();      mIzq.paro();      break; }
               case (IDE_PARAM_AVA): { mDer.avance();    mIzq.avance();    break; }
               case (IDE_PARAM_RET): { mDer.retroceso(); mIzq.retroceso(); break; }
               case (IDE_PARAM_STO): { mDer.paro();      mIzq.paro();      break; }
               case (IDE_PARAM_SVE): {                                     break; }
               default:              { resultado = false;                  break; }
             }

     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { sprintf(gd->buffRespCmd,"000"); }

}

