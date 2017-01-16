


//! ----------------------------------------------------------
//!
//! @file 
//! @author  AAL
//! 
//! @brief   <b>FUNCIONES DEL PROCESADOR DE COMANDOS</b>\n
//!          Estas funciones son las que implmentan los diferentes   
//!          comandos que ejecuta el iROB-EA\n
//!          Los comandos se definen, modifican etc utilizando la BBDD
//!          <b>Gescom_MEGA2560_V3.mdb</b>, consultar la información asociada
//!          a esta BBDD para más detalles\n
//!  
//! @date    08/04/2016                      
//! @warning Codigo revisado: SI
//! @version 3.0, Junio 2015
//!                 
//! ----------------------------------------------------------
                  
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include "UF_SYS.h"
#include "Gescom_MEGA2560_V3.h"
#include "Gescom_MEGA2560_V3_CMD.h"






//! ---------------------------------------------------------
//!
//! @brief   Uso: Comando Reservado
//! @note    Comando implementado: IDE_CMD_CM_R00
//!           
//! @param   GESCOM_DATA* gd
//!
//! @return  Retorna:
//!
//! @warning Codigo verificado: NO
//!
//! ---------------------------------------------------------

void cmd_Comando_CM_R00(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();





}



//! ---------------------------------------------------------
//!
//! @brief   Uso: Comando Reservado
//! @note    Comando implementado: IDE_CMD_CM_R01
//!           
//! @param   GESCOM_DATA* gd
//!
//! @return  Retorna:
//!
//! @warning Codigo verificado: NO
//!
//! ---------------------------------------------------------

void cmd_Comando_CM_R01(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();





}




//! ---------------------------------------------------------
//!
//! @brief   Comando para debug (no se utiliza)

//! @note    Comando implementado: IDE_CMD_CM_DBG
//!           
//! @param   GESCOM_DATA* gd
//!
//! @return  Retorna:
//!
//! @warning Codigo verificado: NO
//!
//! ---------------------------------------------------------

void cmd_Comando_CM_DBG(GESCOM_DATA* gd)
{
  // ---------------------------------------------------------
  // Generacion  del  pulso de latido, reset del watchDog como 
  // medida    de  seguridad  todas  las  implementaciones  de 
  // comandos lo ejecutan al entrar
  // ---------------------------------------------------------
  uf_sys.watchDog_DONE();





}



//! ---------------------------------------------------------
//!
//! @brief   Uso: Retorna informacion relacionada con la
//!          bateria de LiPo
//! 
//! @note    Comando implementado: IDE_CMD_B_LIPO
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET
//! gd->cnv_Param02: IDE_PARAM_CHG,IDE_PARAM_POW
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = CHG Retorna: gd->buffRespCmd = Icc. consumida en carga
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = POW Retorna: gd->buffRespCmd = "0"  Bateria en carga
//!                                                                gd->buffRespCmd = "1"  Bateria cargada
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = ??? Retorna: gd->buffRespCmd = "2"  Error comando
//! gd->cnv_Param01 = ???                                 Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Retorna informacion relacionada con la
//!          bateria de PowerPack
//! 
//! @note    Comando implementado: IDE_CMD_B_PPAK
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET
//! gd->cnv_Param02: IDE_PARAM_CHG,IDE_PARAM_POW
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = CHG Retorna: gd->buffRespCmd = Icc. consumida en carga
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = POW Retorna: gd->buffRespCmd = "100" ... "25"  %de carga
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = ??? Retorna: gd->buffRespCmd = "2"  Error comando
//! gd->cnv_Param01 = ???                                 Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Retorna valor del flag hardware que indica si
//!          esta conectado el conector de DEBUG
//! 
//! @note    Comando implementado: IDE_CMD_S_DBG
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET
//! gd->cnv_Param02: IDE_PARAM_NOP
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = NOP Retorna: gd->buffRespCmd = "0"  NO esta conectado el conector
//!                                                       Retorna: gd->buffRespCmd = "1"  SI esta conectado el conector
//! gd->cnv_Param01 = ???                                 Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------
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



//! ---------------------------------------------------------
//! @brief   Uso: Retorna valor del flag hardware que indica si
//!          se esta recibiendo tension de recarga
//! 
//! @note    Comando implementado: IDE_CMD_S_VCHG
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET
//! gd->cnv_Param02: IDE_PARAM_NOP
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = NOP Retorna: gd->buffRespCmd = "0"  NO se recibe V. de carga
//!                                                       Retorna: gd->buffRespCmd = "1"  SI se recibe V. de carga
//! gd->cnv_Param01 = ???                                 Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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


//! ---------------------------------------------------------
//! @brief   Uso: Control del reloj de tiempo real
//! 
//! @note    Comando implementado: IDE_CMD_R_TIME
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET,IDE_PARAM_SET,IDE_PARAM_CHK,IDE_PARAM_INI
//! gd->cnv_Param02: IDE_PARAM_NOP, valor
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = NOP   Retorna: gd->buffRespCmd = "AAAAMMDD HHMMSS"
//! gd->cnv_Param01 = IDE_PARAM_SET gd->cnv_Param02 = valor Retorna: gd->buffRespCmd = "0"  Error comando
//!                                                                  gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_CHK gd->cnv_Param02 = NOP   Retorna: gd->buffRespCmd = "0"  Reloj no esta funcionando
//!                                                                  gd->buffRespCmd = "1"  Reloj si esta funcionando
//! gd->cnv_Param01 = IDE_PARAM_INI gd->cnv_Param02 = NOP   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = ???                                   Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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




//! ---------------------------------------------------------
//! @brief   Uso: Retorna informacion relacionada con la
//!          bateria de PowerPack
//! 
//! @note    Comando implementado: IDE_CMD_L_LEDS
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_LD1,IDE_PARAM_LD2,IDE_PARAM_LD3
//! gd->cnv_Param02: IDE_PARAM_OFF,IDE_PARAM__ON,IDE_PARAM_BLK
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_LD1 gd->cnv_Param02 = OFF Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//!                                 gd->cnv_Param02 = _ON Retorna: gd->buffRespCmd = "0"  Error comando
//!                                 gd->cnv_Param02 = BLK  
//!                                 gd->cnv_Param02 = ??? Retorna: gd->buffRespCmd = "2"  Error comando
//!                                 
//! gd->cnv_Param01 = IDE_PARAM_LD2 gd->cnv_Param02 = OFF Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//!                                 gd->cnv_Param02 = _ON Retorna: gd->buffRespCmd = "0"  Error comando
//!                                 gd->cnv_Param02 = BLK  
//!                                 gd->cnv_Param02 = ??? Retorna: gd->buffRespCmd = "2"  Error comando
//!                                                                  
//! gd->cnv_Param01 = IDE_PARAM_LD3 gd->cnv_Param02 = OFF Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//!                                 gd->cnv_Param02 = _ON Retorna: gd->buffRespCmd = "0"  Error comando
//!                                 gd->cnv_Param02 = BLK  
//!                                 gd->cnv_Param02 = ??? Retorna: gd->buffRespCmd = "2"  Error comando
//!                                 
//! gd->cnv_Param01 = ???                                 Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Control del sensor de Temperatura MLX 90614
//! 
//! @note    Comando implementado: IDE_CMD_S_MLX9
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_GET
//! gd->cnv_Param02: IDE_PARAM_SSA,IDE_PARAM_SSB
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_GET gd->cnv_Param02 = IDE_PARAM_SSA Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//!                                 gd->cnv_Param02 = IDE_PARAM_SSB Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//!                                 gd->cnv_Param02 = ???           Retorna: gd->buffRespCmd = "2"  Error comando
//! gd->cnv_Param01 = ???                                           Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Control del motor izquierdo
//! 
//! @note    Comando implementado: IDE_CMD_C_MIZQ
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_INI,IDE_PARAM_AVA,IDE_PARAM_RET,IDE_PARAM_STO,IDE_PARAM_SVE,IDE_PARAM_GCO
//! gd->cnv_Param02: IDE_PARAM_NOP,valor
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_AVA gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_RET gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_STO gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_SVE gd->cnv_Param02 = valor Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_GCO gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "XX"   Corriente medida (Hexaddecinal) 
//!                                 
//! gd->cnv_Param01 = ???                                   Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Control del motor derecho
//! 
//! @note    Comando implementado: IDE_CMD_C_MDER
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_INI,IDE_PARAM_AVA,IDE_PARAM_RET,IDE_PARAM_STO,IDE_PARAM_SVE,IDE_PARAM_GCO
//! gd->cnv_Param02: IDE_PARAM_NOP,valor
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_AVA gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_RET gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_STO gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_SVE gd->cnv_Param02 = valor Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_GCO gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "XX" Corriente medida (Hexaddecinal) 
//!                                 
//! gd->cnv_Param01 = ???                                   Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: SI
//!
//! ---------------------------------------------------------

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



//! ---------------------------------------------------------
//! @brief   Uso: Generacion de movimiento
//! 
//! @note    Comando implementado: IDE_CMD_C_RMOV
//!           
//! @param   GESCOM_DATA* gd
//! @code
//! gd->cnv_Param01: IDE_PARAM_INI,IDE_PARAM_GDE,IDE_PARAM_GIZ,IDE_PARAM_AVA,IDE_PARAM_RET,IDE_PARAM_STO,IDE_PARAM_SVE,
//! gd->cnv_Param02: IDE_PARAM_NOP,valor
//! @endcode
//!
//! @return 
//! @code
//! gd->cnv_Param01 = IDE_PARAM_INI gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_GDE gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_GIZ gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_AVA gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_RET gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_STO gd->cnv_Param02 = ???   Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = IDE_PARAM_SVE gd->cnv_Param02 = valor Retorna: gd->buffRespCmd = "1"  Comando ejecutado
//! gd->cnv_Param01 = ???                                   Retorna: gd->buffRespCmd = "2"  Error comando
//! @endcode
//!
//! @warning Codigo verificado: NO
//!
//! ---------------------------------------------------------
//! 
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
               case (IDE_PARAM_GIZ): { mDer.retroceso(); mIzq.avance();    break; }
               case (IDE_PARAM_AVA): { mDer.avance();    mIzq.avance();    break; }
               case (IDE_PARAM_RET): { mDer.retroceso(); mIzq.retroceso(); break; }
               case (IDE_PARAM_STO): { mDer.paro();      mIzq.paro();      break; }
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

