// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        iROB-EA_CMD.ino
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Implmentacion de comandos
//
// Notas:          REVISADO 
//
// ---------------------------------------------------------

#include <Gescom_MEGA2560_V3.h>
#include <Gescom_MEGA2560_V3_CMD.h>



// ---------------------------------------------------------
//
// cmd_Comando_CM_R00 (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
 
void cmd_Comando_CM_R00(GESCOM_DATA* gd)
{


  sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
}


// ---------------------------------------------------------
//
// cmd_Comando_CM_R01 (GESCOM_DATA* gd)
//
// ---------------------------------------------------------

void cmd_Comando_CM_R01(GESCOM_DATA* gd)
{


  sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
}


// ---------------------------------------------------------
//
// cmd_Comando_CM_DBG (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_CM_DBG(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              { // --------------------------------------------
                // Obtener el valor del  flag  que indica si el
                // conector de DEBUG esta conectado fisicamente
                // al Robot
                // --------------------------------------------
                sprintf(gd->buffRespCmd,"%01d",uf_sys.get_FlgDebug());
                break;
              }
          case(IDE_PARAM_ACT):
              { // --------------------------------------------
                // Activa la generacion  de  datos de DEBUG por 
                // el puerto de DEBUG, cambiando el valor de la
                // variable GLOBAL_Flg_Debug 
                // --------------------------------------------
                GLOBAL_FlgDebug = true;
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_DES):
              { // --------------------------------------------
                // Desactiva la generacion  de  datos de  DEBUG 
                // el puerto de DEBUG, cambiando el valor de la
                // variable GLOBAL_Flg_Debug 
                // --------------------------------------------
                GLOBAL_FlgDebug = false;
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
        }
}


// ---------------------------------------------------------
//
// cmd_Comando_CM_CTR (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_CM_CTR(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_MD1):
              { // --------------------------------------------
                // Activar el modo de avance con proteccion,
                // En este modo la velocidad queda limitada
                // --------------------------------------------
                
                GLOBAL_FlgModoAvance       = IDE_MODO_AVANCE_CON_PROTECCION;
                GLOBAL_FlgModoAvanceEvento = IDE_EVENTO_OK;
                
                mDer.limitarVelocidad(true);
                mIzq.limitarVelocidad(true);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_MD2):
              { // --------------------------------------------
                // Desactivar el modo de avance con proteccion
                // En este modo la velocidad no esta limitada
                // --------------------------------------------
                
                GLOBAL_FlgModoAvance       = IDE_MODO_AVANCE_SIN_PROTECCION;
                GLOBAL_FlgModoAvanceEvento = IDE_EVENTO_OK;
                                
                mDer.limitarVelocidad(false);
                mIzq.limitarVelocidad(false);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_GV1):
              { // --------------------------------------------
                // Obtener   el  valor  de  la  variable global
                // GLOBAL_FlgModoAvanceEvento  que  contiene la
                // informacion   relativa  a  las   incidencias
                // detectadas en modo avance, si 
                // GLOBAL_FlgModoAvance = IDE_MODO_AVANCE_CON_PROTECCION;
                // --------------------------------------------
                sprintf(gd->buffRespCmd,"%d",GLOBAL_FlgModoAvanceEvento);
                break;
              }
           default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }             
        }
}


// ---------------------------------------------------------
//
// cmd_Comando_C_STPC (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_STPC(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_ACT):
              {
                if ( GLOBAL_FlgStatusPC==IDE_STATUS_PC_START )
                   { // ---------------------------------------
                     // Arduino esta en espera a que el PC 
                     // indique que el ha arrancado correctamente
                     // ---------------------------------------
                     GLOBAL_FlgStatusPC = IDE_STATUS_PC_ON;
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {   
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
          case(IDE_PARAM_DES):
              {

                GLOBAL_FlgStatusPC = IDE_STATUS_PC_INI_OFF;
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }             
        }
}


// ---------------------------------------------------------
//
// cmd_Comando_CM_RTC (GESCOM_DATA* gd)
//
// --------------------------------------------------------- 
void cmd_Comando_CM_RTC(GESCOM_DATA* gd)
{
  int v;
  int estado;              

  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_SV1):
              {
                v = gd->cnv_Param02;
                      
                if ( v==0xE )
                   { // ---------------------------------------------
                     // Espera 14 caracteres "AAAAMMDD-HH:MM"
                     // ---------------------------------------------
                     int vAnno;
                     int vMes;
                     int vDia;
                     int vHor;
                     int vMin;
                    
                     if ( gc.getBytes(gd->buffRespCmd,v)==v ) 
                        {
                          sscanf( gd->buffRespCmd          ,
                                  "%04d%02d%02d-%02d:%02d" , 
                                   &vAnno                  ,
                                   &vMes                   ,
                                   &vDia                   ,
                                   &vHor                   ,
                                   &vMin                    
                                );
                           uf_sys.set_RTC_D(&estado,DateTime(vAnno, vMes, vDia, vHor, vMin, 0));
                           sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                        }
                     else
                        {
                           sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);   
                        }
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
         
          case(IDE_PARAM_GV1):
              { // -----------------------------------------------
                // Devuelve en el buffer de respuesta un string:
                // Si estado = True el reloj existe y funciona
                //    buffRespCmd = AAAAMMDD-HH:MM, 14 caracteres
                // Si estado = False el reloj no esta presente
                //    buffRespCmd = ""
                // ----------------------------------------------
                uf_sys.get_RTC_S(&estado,gd->buffRespCmd);
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }

        }
}

// ---------------------------------------------------------
//
// cmd_Comando_B_PPAK (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_B_PPAK(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%03d",uf_sys.get_Bateria()); 
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_C_LEDS (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_LEDS(GESCOM_DATA* gd)
{

  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_LD1):
              {
                if ( gd->cnv_Param02==IDE_PARAM_OFF )
                   {
                     uf_sys.set_Led(IDE_LED_DER,IDE_LED_OFF );
                     uf_sys.set_Led(IDE_LED_IZQ,IDE_LED_OFF );
                   }
                else if ( gd->cnv_Param02==IDE_PARAM__ON )
                   {
                     uf_sys.set_Led(IDE_LED_DER,IDE_LED_ON );
                     uf_sys.set_Led(IDE_LED_IZQ,IDE_LED_ON );
                   }
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
        
         case(IDE_PARAM_LD2):
              {
                if ( gd->cnv_Param02==IDE_PARAM_OFF )
                   {
                     uf_sys.set_Led(IDE_LED_POS,IDE_LED_OFF );            
                   }
                else if ( gd->cnv_Param02==IDE_PARAM__ON )
                   {
                     uf_sys.set_Led(IDE_LED_POS,IDE_LED_ON );
                   }
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);   
                break;
              }

          case(IDE_PARAM_LD3):
              {
                if ( gd->cnv_Param02==IDE_PARAM_OFF )
                   {
                     uf_sys.set_Led(IDE_LED_FOCO,IDE_LED_OFF );            
                   }
                else if ( gd->cnv_Param02==IDE_PARAM__ON )
                   {
                     uf_sys.set_Led(IDE_LED_FOCO,IDE_LED_ON );
                   }
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);   
                break;
              }    

          default:
              {
               sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
               break;
              }
        }
 
}

// ---------------------------------------------------------
//
// cmd_Comando_C_MIZQ (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_MIZQ (GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_INI):
              {
                mIzq.begin(); 
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_AVA):
              {
                if ( GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_SIN_PROTECCION )
                   {
                     mIzq.avance();
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
          case(IDE_PARAM_RET):
              { if ( GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_SIN_PROTECCION )
                   {
                     mIzq.retroceso();
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }  
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
         case(IDE_PARAM_STO):
              {
                mIzq.paro();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%01d",uf_sys.get_MotorEstado(IDE_MOTOR_IZQUIERDO));
                break;
              }
          case(IDE_PARAM_SV1):
              {
                if ( gd->cnv_Param02<=255 )
                   {
                     mIzq.velocidad((byte)gd->cnv_Param02); 
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);  
                   }
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_C_MDER (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_MDER(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_INI):
              {
                mDer.begin(); 
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }            
          case(IDE_PARAM_AVA):
              {
                if ( GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_SIN_PROTECCION )
                   {
                     mDer.avance();
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
          case(IDE_PARAM_RET):
              { if ( GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_SIN_PROTECCION )
                   {
                     mDer.retroceso();
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }  
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }
         case(IDE_PARAM_STO):
              {
                mDer.paro();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%d",uf_sys.get_MotorEstado(IDE_MOTOR_DERECHO));
                break;
              }
          case(IDE_PARAM_SV1):
              {
                if ( gd->cnv_Param02<=255 )
                   {
                     mDer.velocidad((byte)gd->cnv_Param02); 
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);   
                   }
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_CM_RMOV (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_RMOV(GESCOM_DATA* gd)
{
  byte flgMovimiento;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_INI):
              {
                mIzq.begin(); 
                mDer.begin(); 
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_AVA):
              {
                flgMovimiento = true;
                
                if ( (GLOBAL_FlgModoAvance==IDE_MODO_AVANCE_CON_PROTECCION) && (GLOBAL_FlgModoAvanceEvento!=IDE_EVENTO_OK)  )
                   { // -------------------------------------
                     // El modo de avance con proteccion esta
                     // activado y  ademas  se  ha  producido 
                     // alguna incidencia NO se puede avanzar
                     // -------------------------------------
                     flgMovimiento = false;
                   }

                if ( flgMovimiento==true )
                   { // -------------------------------------
                     // Se puede avanzar
                     // -------------------------------------
                     mIzq.avance();
                     mDer.avance();
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   { // -------------------------------------
                     // NO se puede ejecutar el comando
                     // -------------------------------------
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                   }
                break;
              }       
         case(IDE_PARAM_STO):
              {
                mIzq.paro();
                mDer.paro();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
         case(IDE_PARAM_GIZ):
              {
                mIzq.retroceso();
                mDer.avance();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }    
          case(IDE_PARAM_GDE):
              {
                mIzq.avance();
                mDer.retroceso();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_RET):
              {
                mIzq.retroceso();
                mDer.retroceso();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_SV1):
              {
                if ( gd->cnv_Param02<=255 )
                   {
                     mIzq.velocidad((byte)gd->cnv_Param02); 
                     mDer.velocidad((byte)gd->cnv_Param02); 
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                   }
                else
                   {
                     sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);   
                   }
                break;
              }
         default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_C_SRVX (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_SRVX(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_INI):
              {
                uf_sys.posiciona_servo_X(IDE_SERVO_X_POS_DEFECTO);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_SV1):
              { // ----------------------------------------
                // Retorna:
                // . El mismo valor recibido si es correcto       
                // . 255 Si el valor recibido es incorrecto
                // ----------------------------------------
                if ( uf_sys.posiciona_servo_X(gd->cnv_Param02)!=-1 ) { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK); }
                else                                                 { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER); } 
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_C_SRVY (GESCOM_DATA* gd)
//
// --------------------------------------------------------- 
void cmd_Comando_C_SRVY(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_INI):
              {
                uf_sys.posiciona_servo_Y(IDE_SERVO_Y_POS_DEFECTO);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_SV1):
              { // ----------------------------------------
                // Retorna:
                // . El mismo valor recibido si es correcto       
                // . 255 Si el valor recibido es incorrecto
                // ----------------------------------------
                if ( uf_sys.posiciona_servo_Y(gd->cnv_Param02)!=-1 ) { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK); }
                else                                                 { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER); } 
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_S_TEMP (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_TEMP(GESCOM_DATA* gd)
{
  float  fTemp;
  double dTemp;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                if ( gd->cnv_Param02==IDE_PARAM_SSA )
                   { // ------------------------------------------
                     // Sensor del HTU21D
                     // ------------------------------------------
                     fTemp = sensor_EMC.get_Temperatura_HTU21D();
                     dtostrf(fTemp,4,1,gd->buffRespCmd);
                   }
                else if ( gd->cnv_Param02==IDE_PARAM_SSB )
                   { // ------------------------------------------
                     // Sensor del MPL3115A2
                     // ------------------------------------------
                     fTemp = sensor_EMC.get_Temperatura_MPL3115A2();
                     dtostrf(fTemp,4,1,gd->buffRespCmd);
                   }
                else if ( gd->cnv_Param02==IDE_PARAM_SSC )
                   { // ------------------------------------------
                     // Sensor MLX90164, temperatura Ambiente
                     // ------------------------------------------
                     dTemp = sensor_EMC.get_Temperatura_MLX90614_A();
                     dtostrf(dTemp,5,1,gd->buffRespCmd);                    
                   }
                else if ( gd->cnv_Param02==IDE_PARAM_SSD )
                   { // ------------------------------------------
                     // Sensor MLX90164, temperatura del objeto al
                     // que se apunta -)
                     // ------------------------------------------
                     dTemp = sensor_EMC.get_Temperatura_MLX90614_O();
                     dtostrf(dTemp,5,1,gd->buffRespCmd);                    
                   }
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_S_CFAN (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_CFAN(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM__ON):
              {
                uf_sys.set_Fan(true);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          case(IDE_PARAM_OFF):
              {
                uf_sys.set_Fan(false);
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }  
        }
}

// ---------------------------------------------------------
//
// cmd_Comando_S_HUMR (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_HUMR(GESCOM_DATA* gd)
{
  float fTemp;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                fTemp = sensor_EMC.get_HumedadRelativa();
                dtostrf(fTemp,4,1,gd->buffRespCmd);
                break;
              }
        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_SALT (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_SALT(GESCOM_DATA* gd)
{
  float fTemp;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                fTemp = sensor_EMC.get_Altitud();
                dtostrf(fTemp,5,1,gd->buffRespCmd);
                break;
              }
        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_PRES (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_PRES(GESCOM_DATA* gd)
{
  float fTemp;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                if ( gd->cnv_Param02==IDE_PARAM_SSA )
                   { // ------------------------------------------
                     // Sensor del HTU21D
                     // ------------------------------------------
                     fTemp = sensor_EMC.get_Presion_Pa();
                     dtostrf(fTemp,5,2,gd->buffRespCmd);
                   }
                else if ( gd->cnv_Param02==IDE_PARAM_SSB )
                   { // ------------------------------------------
                     // Sensor del MPL3115A2
                     // ------------------------------------------
                     fTemp = sensor_EMC.get_Presion_InHg();
                     dtostrf(fTemp,5,2,gd->buffRespCmd);
                   }
                break;
              }
        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_GLUZ (GESCOM_DATA* gd)
//
// --------------------------------------------------------- 
void cmd_Comando_S_GLUZ(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%04d",sensor_EMC.get_NivelLuminosidad());
                break;
              }
        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_SSUP (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_SSUP(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%02d",sensor_USS.get_Superficie());
                break;
              }
        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_RGPS (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_RGPS(GESCOM_DATA* gd)
{
  float fTemp;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_RFS):
              {
                if ( sensor_GPS.actualizar()==true ) { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK); }
                else                                 { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER); }
                break;
              }
          case(IDE_PARAM_GV1):
              {
                sensor_GPS.get_FechaHora(gd->buffRespCmd);
                break;
              }
          case(IDE_PARAM_GV2):
              {
                if ( sensor_GPS.get_Posicion(gd->buffRespCmd)==true ) {                                               }
                else                                                  { sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER); }
                break;
              }
          case(IDE_PARAM_GV3):
              {
                fTemp = sensor_GPS.get_Altitud();
                dtostrf(fTemp,5,2,gd->buffRespCmd);
                break;
              }
          case(IDE_PARAM_GV4):
              {
                fTemp = sensor_GPS.get_Rumbo();
                dtostrf(fTemp,5,2,gd->buffRespCmd);
                break;
              }
          case(IDE_PARAM_GV5):
              {
                fTemp = sensor_GPS.get_Velocidad();
                dtostrf(fTemp,5,2,gd->buffRespCmd);
                break;
              }
         case(IDE_PARAM_GV6):
              {
                sprintf(gd->buffRespCmd,"%02d",sensor_GPS.get_Satelites());
                break;
              }

        }
} 

// ---------------------------------------------------------
//
// cmd_Comando_S_SICC (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_SICC(GESCOM_DATA* gd)
{
  float fIcc;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                if ( gd->cnv_Param02==IDE_PARAM_SSA )
                   {
                     fIcc = uf_sys.get_Corriente(IDE_ICC_5VP);
                     dtostrf(fIcc,5,3,gd->buffRespCmd);
                   }
                else if ( gd->cnv_Param02==IDE_PARAM_SSB )
                   {
                     fIcc = uf_sys.get_Corriente(IDE_ICC_12P);
                     dtostrf(fIcc,5,3,gd->buffRespCmd);
                   }
                break;
              }
          
          case(IDE_PARAM_CAL):
              {
                uf_sys.calibra_ACS723();
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
        }
 
} 


 
// ---------------------------------------------------------
//
// cmd_Comando_S_SEUS (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_SEUS(GESCOM_DATA* gd)
{
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                     if ( gd->cnv_Param02==IDE_PARAM_SSA ) { sprintf(gd->buffRespCmd,"%02d",sensor_USS.get_IZQ()); }
                else if ( gd->cnv_Param02==IDE_PARAM_SSB ) { sprintf(gd->buffRespCmd,"%02d",sensor_USS.get_DER()); }
                break;
              }
        }
} 


// ---------------------------------------------------------
//
// cmd_Comando_C_RELE (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_C_RELE(GESCOM_DATA* gd)
{

 switch( gd->cnv_Param01 )
       {
          case(IDE_PARAM_12P):
              {
                if      ( gd->cnv_Param02==IDE_PARAM__ON ) { uf_sys.rele(IDE_RELE_12P,IDE_RELE_ACTIVAR);    }
                else if ( gd->cnv_Param02==IDE_PARAM_OFF ) { uf_sys.rele(IDE_RELE_12P,IDE_RELE_DESACTIVAR); }
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
         
          case(IDE_PARAM_5VP):
              {
                if      ( gd->cnv_Param02==IDE_PARAM__ON ) { uf_sys.rele(IDE_RELE_5VP,IDE_RELE_ACTIVAR);    }
                else if ( gd->cnv_Param02==IDE_PARAM_OFF ) { uf_sys.rele(IDE_RELE_5VP,IDE_RELE_DESACTIVAR); }
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_OK);
                break;
              }
       }

}


// ---------------------------------------------------------
//
// cmd_Comando_S_9DOF (GESCOM_DATA* gd)
//
// ---------------------------------------------------------
void cmd_Comando_S_9DOF(GESCOM_DATA* gd)
{
  float fIcc;
  
  switch( gd->cnv_Param01 )
        {
          case(IDE_PARAM_GV1):
              {
                sprintf(gd->buffRespCmd,"%s",sensor_RAZOR.getFrameAcc());
                break;
              }
          case(IDE_PARAM_GV2):
              {
                sprintf(gd->buffRespCmd,"%s",sensor_RAZOR.getFrameMag());
                break;
              }
          case(IDE_PARAM_GV3):
              {
                sprintf(gd->buffRespCmd,"%s",sensor_RAZOR.getFrameGyr());
                break;
              }
          case(IDE_PARAM_GV4):
              {

                
                break;
              }
          default:
              {
                sprintf(gd->buffRespCmd,"%d",IDE_EXE_CMD_ER);
                break;
              }  
        }
}  
