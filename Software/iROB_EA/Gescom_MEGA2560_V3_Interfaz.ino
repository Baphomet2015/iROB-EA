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
// void cmd_Comando_CM_R00(GESCOM_DATA* gd)
//
// Uso:      Comando Reservado
// Sintaxis: comando:    IDE_CMD_CM_R00
//           
//           parametro1: -
//
//           parametro2: -
//
// Retorna:
//
//
// VERIFICADO: NO
//
// ---------------------------------------------------------

void cmd_Comando_CM_R00(GESCOM_DATA* gd)
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
// void cmd_Comando_CM_R01(GESCOM_DATA* gd)
//
// Uso:      Comando Reservado
// Sintaxis: comando:    IDE_CMD_CM_R01
//           
//           parametro1: -
//
//           parametro2: -
//
// Retorna:
//
//
// VERIFICADO: NO
//
// ---------------------------------------------------------

void cmd_Comando_CM_R01(GESCOM_DATA* gd)
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
// void cmd_Comando_CM_DBG(GESCOM_DATA* gd)
//
// Uso:      Comando para debug (no se utiliza)
// Sintaxis: comando:    IDE_CMD_CM_DBG
//           
//           parametro1: -
//
//           parametro2: -
//
// Retorna:
//
//
// VERIFICADO: NO
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
// void cmd_Comando_B_LIPO(GESCOM_DATA* gd)
//
// Uso:      Retorna informacion relacionada con la bateria
//           de LiPo
// Sintaxis: comando:    IDE_CMD_B_LIPO
//           
//           parametro1: IDE_PARAM_GET
//
//           parametro2: IDE_PARAM_CHG
//                       IDE_PARAM_POW
//
// Retorna:
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == CHG   gd->buffRespCmd = Corriente consumida en carga
//           P1 == IDE_PARAM_GET  P2 == POW   gd->buffRespCmd = "0"  Bateria en carga
//                                            gd->buffRespCmd = "1"  Bateria cargada
//           P1 == IDE_PARAM_GET  P2 == ???   gd->buffRespCmd = "2"  Error comando
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
//
// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_B_LIPO(GESCOM_DATA* gd)
{
  double iMedida;
  byte   carga;
  int    flg;


  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida   de  seguridad   todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();

  flg = false;

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
                      flg = true;
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
                      flg = true;
                      break;
                    }

               default:
                    {
                   
                      break;
                    }
             }        
       
    }

  if ( flg==false )
     {
       strcpy(gd->buffRespCmd,"2");      
     }

}



// ---------------------------------------------------------
//
// void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
//
// Uso:      Retorna informacion relacionada con la bateria
//           de PowerPack
// Sintaxis: comando:    IDE_CMD_B_PPAK
//           
//           parametro1: IDE_PARAM_GET
//
//           parametro2: IDE_PARAM_CHG
//                       IDE_PARAM_POW
// Retorna:
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == CHG   gd->buffRespCmd = Corriente consumida en carga
//           P1 == IDE_PARAM_GET  P2 == POW   gd->buffRespCmd = "100" ... "25" nivel de carga
//           P1 == IDE_PARAM_GET  P2 == ???   gd->buffRespCmd = "2"  Error comando
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
// 
// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
{
  double iMedida;
  byte   carga;
  int    flg;
  

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();

  flg = false;

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
                      flg = true;
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
                      flg = true;
                      break;
                    }

               default:
                    {
                   
                      break;
                    }
             }
    }

  if ( flg==false )
     {
       strcpy(gd->buffRespCmd,"2");      
     }

}



// ---------------------------------------------------------
//
// void cmd_Comando_S_CDBG(GESCOM_DATA* gd)
//
// Uso:       Retorna valor del flag hardware que indica si 
//            esta conectado el conector de DEBUG
// Sintaxis: comando:    IDE_CMD_S_DBG
//           
//           parametro1: IDE_PARAM_GET
//
//           parametro2: IDE_PARAM_NOP
//
// Retorna:
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == NOP   gd->buffRespCmd = "0"  NO esta conectado el conector
//                                            gd->buffRespCmd = "1"  SI esta conectado el conector
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
//
// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_S_CDBG(GESCOM_DATA* gd)
{
  int v;
  int flg;

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  
  flg = false;

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       // No espera parametro 2 (recibe NOP)
       //
       // ---------------------------------------------------------
       flg = true;
       if ( uf_sys.get_FlgDebug()==true) { strcpy(gd->buffRespCmd,"1"); }
       else                              { strcpy(gd->buffRespCmd,"0"); }
     }


  if (flg==false)
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
//            se esta recibiendo tension de recarga
// Sintaxis: comando:    IDE_CMD_S_VCHG
//           
//           parametro1: IDE_PARAM_GET
//
//           parametro2: IDE_PARAM_NOP
//
// Retorna:
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == NOP   gd->buffRespCmd = "0"  NO esta conectado el conector
//                                            gd->buffRespCmd = "1"  SI esta conectado el conector
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
//
// VERIFICADO: SI
// 
// 
// ---------------------------------------------------------

void cmd_Comando_S_VCHG(GESCOM_DATA* gd)
{
  int v;
  int flg;

  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();
  
  flg = false;

  if ( (gd->cnv_Tipo==IDE_T_COMANDO_ENVIO) && (gd->cnv_Param01==IDE_PARAM_GET) )
     { // ---------------------------------------------------------
       //
       // No espera parametro 2 (recibe NOP)
       //
       // ---------------------------------------------------------
       flg = true;
       if ( uf_bat.get_FlgCarga()==true) { strcpy(gd->buffRespCmd,"1"); }
       else                              { strcpy(gd->buffRespCmd,"0"); }
     }
 

  if ( flg==false )
     {
       strcpy(gd->buffRespCmd,"2");
     }
      
   //#ifdef APP_MODO_DEBUG
   //Serial1.print(F("CARGA: "));
   //Serial1.println(gd->buffRespCmd);
   //#endif
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
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == NOP   gd->buffRespCmd = "AAAAMMDD HHMMSS"  
//                                           
//           P1 == IDE_PARAM_SET  P2 == valor gd->buffRespCmd = "0"  Error comando
//                                            gd->buffRespCmd = "1"  Comando ejecutado 
//           P1 == IDE_PARAM_CHK  P2 == NOP   gd->buffRespCmd = "0"  Reloj no esta funcionando
//                                            gd->buffRespCmd = "1"  Reloj si esta funcionando
//           P1 == IDE_PARAM_INI  P2 == NOP   gd->buffRespCmd = "1"  Comando ejecutado 
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
//
// VERIFICADO: SI
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
                     // No espera parametro 2 (recibe NOP)
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
                      
                      flg = true;  
                      break;
                    }

               case ( IDE_PARAM_CHK ):
                    { // ---------------------------------------------------------
                      // CHK: Comprobar funcionamiento del RTC
                      // No espera parametro 2 (recibe NOP)
                      // ---------------------------------------------------------
                      if (!rtc.isrunning() )
                         { 
                           resultado = false;
                         }
                      
                      flg = true;  
                      break;
                    }

               case ( IDE_PARAM_INI ):
                    { // ---------------------------------------------------------
                      // INI: Iniciar RTC
                      // No espera parametro 2 (recibe NOP)
                      // ---------------------------------------------------------
                      rtc.begin();
                      flg = true;  
                      break;
                    }
               
               default:
                    {
                      flg = false;  
                      break;
                    }

             }
     }
 
  if ( flg==true )
     {
       if (resultado==false)
          { 
            strcpy(gd->buffRespCmd,"0");
          }   
       else
          { 
            if ( gd->cnv_Param01!=IDE_PARAM_GET )
               {
                 strcpy(gd->buffRespCmd,"1");
               }
          }    
     }
  else 
     {
       strcpy(gd->buffRespCmd,"2");
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
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_LD1  P2 == OFF   gd->buffRespCmd = "1"  Comando ejecutado
//                                P2 == _ON   gd->buffRespCmd = "0"  Error comando
//                                P2 == BLK   
//                                P2 == ???   gd->buffRespCmd = "2"  Error comando
//
//           P1 == IDE_PARAM_LD2  P2 == OFF   gd->buffRespCmd = "1"  Comando ejecutado
//                                P2 == _ON   gd->buffRespCmd = "0"  Error comando
//                                P2 == BLK   
//                                P2 == ???   gd->buffRespCmd = "2"  Error comando
//
//           P1 == IDE_PARAM_LD3  P2 == OFF   gd->buffRespCmd = "1"  Comando ejecutado
//                                P2 == _ON   gd->buffRespCmd = "0"  Error comando
//                                P2 == BLK   
//                                P2 == ???   gd->buffRespCmd = "2"  Error comando
//
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
//
// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_L_LEDS(GESCOM_DATA* gd)
{
  int ledID;
  int resultado;
  int flg;

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

       if (resultado==true)
          {
            switch(gd->cnv_Param01)
                  {
                    case (IDE_PARAM_LD1): { flg = true; ledID = IDE_LED_BDEL; break; }
                    case (IDE_PARAM_LD2): { flg = true; ledID = IDE_LED_BDET; break; }
                    case (IDE_PARAM_LD3): { flg = true; ledID = IDE_LED_RDET; break; }
                    default:              {             resultado = false;    break; }
                  }
          } 

       if (resultado==true)
          {
            switch(gd->cnv_Param02)
                  {
                    case (IDE_PARAM_OFF): { uf_sys.setLed(ledID,IDE_LED_OFF); break; }
                    case (IDE_PARAM__ON): { uf_sys.setLed(ledID,IDE_LED_ON);  break; }
                    case (IDE_PARAM_BLK): { uf_sys.setLed(ledID,IDE_LED_BLK); break; }
                    default:              { flg = false;                      break; }
                  }
          }
     }


  if ( flg==true )
     {
       if (resultado==false) { strcpy(gd->buffRespCmd,"0"); }   
       else                  { strcpy(gd->buffRespCmd,"1"); }    
     }
  else 
     {
       strcpy(gd->buffRespCmd,"2");
     }
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
//           parametro2: IDE_PARAM_SSA
//                       IDE_PARAM_SSB    
//
// Retorna:
//                parametro1      parametro2  retorno
//           -------------------  ----------  -------
//           P1 == IDE_PARAM_GET  P2 == SSA   gd->buffRespCmd = "xxx"  Temperatura leida con el sensor Ambiente
//                                P2 == SSB   gd->buffRespCmd = "xxx"  Temperatura leida con el sensor Infrarrojo
//                                P2 == ???   gd->buffRespCmd = "2"  Error comando
//
//           P1 == ???                        gd->buffRespCmd = "2"  Error comando
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
       // 
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

  if ( resultado==false) { strcpy(gd->buffRespCmd,"2"); }
  
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
//          INI: gd->buffRespCmd = "1"               Comando ejecutado
//          AVA: gd->buffRespCmd = "1"               Comando ejecutado
//          RET: gd->buffRespCmd = "1"               Comando ejecutado
//          STO: gd->buffRespCmd = "1"               Comando ejecutado
//          SVE: gd->buffRespCmd = "0"               Error comando
//               gd->buffRespCmd = "1"               Comando ejecutado
//          GCO: gd->buffRespCmd = "XX"              Corriente medida (Hexaddecinal) 
//
/// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_C_MIZQ(GESCOM_DATA* gd)
{
  
  int    resultado;
  int    v;
  int    velocidad;
  double iMedida;

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

       switch(gd->cnv_Param01)
             {
               case (IDE_PARAM_INI):
                    { 
                      FNG_SetPowerMotores(false);
                      mIzq.paro();
                      break;
                    }

               case (IDE_PARAM_AVA):
                    { 
                      FNG_SetPowerMotores(true);
                      mIzq.avance();
                      break;
                    }
               
               case (IDE_PARAM_RET):
                    { 
                      FNG_SetPowerMotores(true);
                      mIzq.retroceso();
                      break;
                    }
               
               case (IDE_PARAM_STO):
                    { 
                      FNG_SetPowerMotores(false);
                      mIzq.paro();
                      break;
                    }
               
               case (IDE_PARAM_GCO):
                    {

                      iMedida = mIzq.getCorriente();
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     
                      
                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("Mot Izq iMedida: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif

                      break;
                    }
                    
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


  // ---------------------------------------------
  // Resultado a retornar
  // ---------------------------------------------
  if ( resultado==false)
     { 
       strcpy(gd->buffRespCmd,"0");
     }
  else
     {
       if ( gd->cnv_Param01!=IDE_PARAM_GCO) 
          {
            strcpy(gd->buffRespCmd,"1"); 
          }
     }
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
//          INI: gd->buffRespCmd = "1"               Comando ejecutado
//          AVA: gd->buffRespCmd = "1"               Comando ejecutado
//          RET: gd->buffRespCmd = "1"               Comando ejecutado
//          STO: gd->buffRespCmd = "1"               Comando ejecutado
//          SVE: gd->buffRespCmd = "0"               Error comando
//               gd->buffRespCmd = "1"               Comando ejecutado
//          GCO: gd->buffRespCmd = "XX"              Corriente medida (Hexaddecinal) 
//
/// VERIFICADO: SI
// 
// ---------------------------------------------------------

void cmd_Comando_C_MDER(GESCOM_DATA* gd)
{
    
  int    resultado;
  int    v;
  int    velocidad;
  double iMedida;

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
                    { // ---------------------------------------------------------
                      // Iniciar OK
                      // ---------------------------------------------------------
                      FNG_SetPowerMotores(false);
                      mDer.paro();
                      break;
                    }

               case (IDE_PARAM_AVA):
                    {  // ---------------------------------------------------------
                       // Avance OK
                       // ---------------------------------------------------------
                      FNG_SetPowerMotores(true);
                      mDer.avance();
                      break;
                    }
               

               case (IDE_PARAM_RET):
                    { 
                      FNG_SetPowerMotores(true);
                      mDer.retroceso();
                      break;
                    }
               

               case (IDE_PARAM_STO):
                    { 
                      FNG_SetPowerMotores(false);
                      mDer.paro();
                      break;
                    }
               

               case (IDE_PARAM_GCO):
                    {
                      iMedida = mDer.getCorriente();
                      dtostrf(iMedida, 4, 1, gd->buffRespCmd);     
                      
                  //  #ifdef APP_MODO_DEBUG
                  //  Serial1.print(F("Mot Der iMedida: "));
                  //  Serial1.println(gd->buffRespCmd);
                  //  #endif

                      break;
                    }

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

  // ---------------------------------------------
  // Resultado a retornar
  // ---------------------------------------------
  if ( resultado==false)
     { 
       strcpy(gd->buffRespCmd,"0");
     }
  else
     {
       if ( gd->cnv_Param01!=IDE_PARAM_GCO) 
          {
            strcpy(gd->buffRespCmd,"1"); 
          }
     }
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
// VERIFICADO: NO
// 
// ---------------------------------------------------------

void cmd_Comando_C_RMOV(GESCOM_DATA* gd)
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
               case (IDE_PARAM_INI): { mDer.paro();      mIzq.paro();      break; }
               case (IDE_PARAM_GDE): { mDer.avance();    mIzq.retroceso(); break; }
               case (IDE_PARAM_AVA): { mDer.avance();    mIzq.avance();    break; }
               case (IDE_PARAM_RET): { mDer.retroceso(); mIzq.retroceso(); break; }
               case (IDE_PARAM_STO): { mDer.paro();      mIzq.paro();      break; }
               case (IDE_PARAM_GIZ): { mDer.retroceso(); mIzq.avance();    break; }
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
                                mIzq.velocidad(velocidad);
                              }
                           else
                              {
                                resultado = false;
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
  else                   { strcpy(gd->buffRespCmd,"1"); }
}

