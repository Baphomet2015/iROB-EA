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
// Notas:          REVISADO 08/04/2016                      
//                 
//                 
// ----------------------------------------------------------
                  
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include "UF_SYS.h"
#include "Gescom_MEGA2560_V3.h"
#include "Gescom_MEGA2560_V3_CMD.h"
  







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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
  // medida   de  seguridad   todas  las  implementaciones  de 
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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
  byte   carga;


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
                    { // ---------------------------------------------------------
                      // Corriente que esta consumiendo la bateria cuando esta EN
                      // CARGA.
                      // ---------------------------------------------------------
                      
                      iMedida = uf_bat.get_IccChgLiPo();
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     
                      
                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("LiPo iMedida: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif


                      
                      break;
                    }

               case (IDE_PARAM_POW):
                    { // ---------------------------------------------------------
                      // Estado del led de carga de la bateria de LiPo
                      // carga = 1 --> Bateria cargada
                      // carga = 0 --> Bateria en carga
                      // ---------------------------------------------------------
                      carga = uf_bat.get_LedChgLiPo();
                      sprintf(gd->buffRespCmd,"%d",carga); 

                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("LiPo Carga: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif


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
// . Valor  solicitado
// 
// ---------------------------------------------------------

void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
{
  double iMedida;
  byte   carga;
  

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
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
                    { // ---------------------------------------------------------
                      // Corriente que esta consumiendo la bateria cuando esta EN
                      // CARGA.
                      // ---------------------------------------------------------
                      iMedida = uf_bat.get_IccChgPpak();
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     

                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("Power Bank iMedida: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif

                      break;
                    }

               case (IDE_PARAM_POW):
                    { // ---------------------------------------------------------
                      // Estado de los leds de carga del PPAK
                      // carga = 100 --> 100% de carga.
                      // carga =  75 -->  75% de carga.
                      // carga =  50 -->  50% de carga.
                      // carga =  25 -->  25% de carga.
                      // carga =   0 -->   0% de carga ????.
                      // ---------------------------------------------------------
                     
                      carga = uf_bat.get_LedChgPpak();
                      sprintf(gd->buffRespCmd,"%d",carga); 

                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("Power Bank Carga: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif

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
//          "0" NO esta conectado
//          "1" SI esta conectado
//          "2" Error de comando
// 
// ---------------------------------------------------------

void cmd_Comando_S_CDBG(GESCOM_DATA* gd)
{
  int v;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------
       if ( uf_sys.get_FlgDebug()==true) { strcpy(gd->buffRespCmd,"1"); }
       else                              { strcpy(gd->buffRespCmd,"0"); }
     }
  else
     {
       strcpy(gd->buffRespCmd,"2");
     }
      
  // #ifdef APP_MODO_DEBUG
  // Serial1.print(F("CDBG: "));
  // Serial1.println(gd->buffRespCmd);
  // #endif
}



// ---------------------------------------------------------
//
// void cmd_Comando_S_VCHG(GESCOM_DATA* gd)
//
// Uso:       Retorna valor del flag hardware que indica si 
//            se esta recibiendo tension de recaarga
// Sintaxis: 
//           comando:    IDE_CMD_S_VCHG
//           parametro1: IDE_PARAM_GET
//           parametro2: IDE_PARAM_NOP
//
// Retorna:
//          "0" NO esta recibiendo
//          "1" SI esta recibiendo
//          "2" Error de comando
// 
// ---------------------------------------------------------

void cmd_Comando_S_VCHG(GESCOM_DATA* gd)
{
  int v;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       //
       //
       // ---------------------------------------------------------
       if ( uf_bat.get_FlgCarga()==true) { strcpy(gd->buffRespCmd,"1"); }
       else                              { strcpy(gd->buffRespCmd,"0"); }
     }
  else
     {
       strcpy(gd->buffRespCmd,"2");
     }
      
  // #ifdef APP_MODO_DEBUG
  // Serial1.print(F("CARGA: "));
  // Serial1.println(gd->buffRespCmd);
  // #endif
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
//          "0"               Error de comando
//          "1"               Comando ejecutado
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
  

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
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

                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("RTC: "));
                  //  Serial1.println(gd->buffRespCmd );
                  //  #endif

                      break;
                    }

               case ( IDE_PARAM_SET ):
                    { // ---------------------------------------------------------
                      // SET: Establecer Fecha y Hora del RTC
                      //      Espera un string en la forma: "AAAAMMDD HHMMSS"
                      //      Retorna  "00" Error
                      //               "01" Ok se ha establecido los nueva fecha/hora
                      // ---------------------------------------------------------

                      v = gd->cnv_Param02;
                      
                      if ( v==0xF )
                         { // ---------------------------------------------
                           // Espera 15 caracteres "AAAAMMDD HHMMSS"
                           // ---------------------------------------------
                     
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
                      //               "01" Si se esta ejecutando   
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
                      //      Retorna IDE_CMD_RETORNO_1
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
       if (resultado==false) { strcpy(gd->buffRespCmd,"0"); }   
       else                  { strcpy(gd->buffRespCmd,"1"); }    
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
//          "0" Error de comando
//          "1" Comando ejecutado
//
// 
// ---------------------------------------------------------

void cmd_Comando_L_LEDS(GESCOM_DATA* gd)
{
  int ledID;
  int resultado;
 

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
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

  if ( resultado==false) { strcpy(gd->buffRespCmd,"0"); }
  else                   { strcpy(gd->buffRespCmd,"1"); }

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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
                              default:
                                   { resultado = false;
                                     break;
                                   }
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

  if ( resultado==false) { strcpy(gd->buffRespCmd,"0"); }
  
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
//                       IDE_PARAM_AVA
//                       IDE_PARAM_RET
//                       IDE_PARAM_STO
//                       IDE_PARAM_SVE
//                       IDE_PARAM_GCO
//
//           parametro2: IDE_PARAM_NOP
//                       valor
//
// Retorna:
//     0: Error de comando
//     1: Ejecucion correcta
// ---------------------------------------------------------

void cmd_Comando_C_MIZQ(GESCOM_DATA* gd)
{
  
  int resultado;
  int v;
  int velocidad;
  
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
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
               case (IDE_PARAM_GCO): {                    break; }
               case (IDE_PARAM_SVE):
                    {
                      v = gd->cnv_Param02;
                      if ( v==0x2 )
                         { // ---------------------------------------------
                           // Espera dos caracteres ( valores de 0...FF)
                           // ---------------------------------------------
                           if ( gc.getBytes(gd->buffRespCmd,v)==v ) 
                              {
                                sscanf( gd->buffRespCmd,"%02x",&velocidad);
                                mIzq.velocidad(velocidad);
                              }
                           else
                              {
                                resultado = false;
                              }
                         }
                      else
                         {
                           resultado = false;
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

  if ( resultado==false) { strcpy(gd->buffRespCmd,"0"); }
  else                   { strcpy(gd->buffRespCmd,"1"); }
}




// ---------------------------------------------------------
//
// void cmd_Comando_C_MDER(GESCOM_DATA* gd)
//
// Uso: Control del motor derecho
// Sintaxis: 
//           comando:    IDE_CMD_C_MDER    
//
//           parametro1: IDE_PARAM_INI*
//                       IDE_PARAM_AVA*
//                       IDE_PARAM_RET
//                       IDE_PARAM_STO*
//                       IDE_PARAM_SVE*
//                       IDE_PARAM_GCO*
//
//           parametro2: IDE_PARAM_NOP
//                       valor
//
//
// Retorna:
//     0: Error de comando
//     1: Ejecucion correcta
// ---------------------------------------------------------

void cmd_Comando_C_MDER(GESCOM_DATA* gd)
{
    
  int resultado;
  int v;
  int velocidad;

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
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
               case (IDE_PARAM_INI):
                    { 
                      uf_sys.rele(IDE_RELE_MOTORES,IDE_RELE_DESACTIVAR);
                      mDer.paro();
                      break;
                    }

               case (IDE_PARAM_AVA):
                    { 
                      uf_sys.rele(IDE_RELE_MOTORES,IDE_RELE_ACTIVAR);
                      mDer.avance();
                      break;
                    }
               

               case (IDE_PARAM_RET): { mDer.retroceso();  break; }
               

               case (IDE_PARAM_STO): { mDer.paro();       break; }
               

               case (IDE_PARAM_GCO): {                    break; }
               

               case (IDE_PARAM_SVE):
                    {
                      v = gd->cnv_Param02;
                      if ( v==0x2 )
                         { // ---------------------------------------------
                           // Espera tres caracteres ( valores de 0...FF)
                           // ---------------------------------------------
                           if ( gc.getBytes(gd->buffRespCmd,v)==v ) 
                              {
                                sscanf( gd->buffRespCmd,"%2x",&velocidad);
                                mDer.velocidad(velocidad);
                              }
                           else
                              {
                                resultado = false;
                              }
                         }
                      else
                         {
                           resultado = false;
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

  if ( resultado==false) { strcpy(gd->buffRespCmd,"0"); }
  else                   { strcpy(gd->buffRespCmd,"1"); }
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
  // medida    de  seguridad  todas  las  implementaciones  de 
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
               case (IDE_PARAM_GDE): { mDer.avance();    mIzq.retroceso(); break; }
               case (IDE_PARAM_AVA): { mDer.avance();    mIzq.avance();    break; }
               case (IDE_PARAM_RET): { mDer.retroceso(); mIzq.retroceso(); break; }
               case (IDE_PARAM_STO): { mDer.paro();      mIzq.paro();      break; }
               case (IDE_PARAM_SVE): {                                     break; }
               case (IDE_PARAM_GIZ): { mDer.retroceso(); mIzq.avance();    break; }
               default:              { resultado = false;                  break; }
             }

     }
  else
     {
       resultado = false;
     }

  if ( resultado==false) { strcpy(gd->buffRespCmd,"0"); }
  else                   { strcpy(gd->buffRespCmd,"1"); }
}

