

  // -----------------------------------------------------------------------
  //
  //                       GESCOM
  //                 Gestor de comandos
  //            Version para Arduino MEGA2560
  //
  // Autor:
  // Fichero:        Gescom_MEGA2560_CMD_V3.h
  // Hardware:       -
  // Version:        1.0
  //
  // Funcionalidad:  Procesador de Comandos
  //
  // Notas:          Este fichero se genera automaticamente desde la BBDD
  //                 Gescom_MEGA2560_V3, ejecutando la Macro:
  //                 "Genera_Ficheros_Resultado"
  //
  // ----------------------------------------------------------------------

  #ifndef gescom_MEGA2560_V3_CMD_h
  #define gescom_MEGA2560_V3_CMD_h





 // ----------------------------------------------------------
 // COMANDOS: Identificadores de comandos reconocidos.
 //           Se CORRESPONDEN con  los codigos de los comandos
 //           de   la  tabla   Tbl_Comandos    de    la   BBDD
 //           gescom_MEGA2560_V3.mdb
 // ----------------------------------------------------------

 // ----------------------------------------------------------
 // Fecha Generación: 09/11/2021 , 12:37

 // ----------------------------------------------------------
 #define  IDE_CMD_CM_R00    0x00     // Comando Reservado 0

 #define  IDE_CMD_CM_R01    0x01     // Comando Reservado 1
 #define  IDE_CMD_CM_DBG    0x02     // Comandos DEBUG
 #define  IDE_CMD_CM_RTC    0x03     // Comandos para el RTC de Arduino
 #define  IDE_CMD_B_PPAK    0x10     // Bateria Power Pack

 #define  IDE_CMD_C_LEDS    0x20     // Control de los Leds
 #define  IDE_CMD_C_MIZQ    0x30     // Control motor izquierdo
 #define  IDE_CMD_C_MDER    0x31     // Control motor derecho
 #define  IDE_CMD_C_RMOV    0x32     // Comando de movimiento

 #define  IDE_CMD_C_SRVX    0x40     // Control Servo camara eje X
 #define  IDE_CMD_C_SRVY    0x41     // Control Servo camara eje Y
 #define  IDE_CMD_S_TEMP    0x50     // Sensores de temperatura
 #define  IDE_CMD_S_HUMR    0x51     // Sensores de humedad

 #define  IDE_CMD_S_GLUZ    0x52     // Sensores de luz
 #define  IDE_CMD_S_SSUP    0x53     // Sensores superficie
 #define  IDE_CMD_S_RGPS    0x54     // Sensor GPS

 #define  IDE_CMD_S_SICC    0x55     // Sensores de corriente
 #define  IDE_CMD_S_SEUS    0x56     // Sensores ultrasonidos


 #define  IDE_CMD_S_CFAN    0x57     // Sensores, control del ventilador
 #define  IDE_CMD_S_SALT    0x58     // Sensores de altitud

 #define  IDE_CMD_S_PRES    0x59     // Sensores Presion
 #define  IDE_CMD_C_RELE    0x60     // Control de reles
 #define  IDE_CMD_C_STPC    0x70     // Comando relacionados con el PC de control


  // --------------------------------------------------------------
  // TIPO COMANDOS: Identificadores de tipos de comandos
  //                son los especificados en Gescom_MEGA2560_V3.doc
  // --------------------------------------------------------------

 // --------------------------------------------------------------
 // Fecha Generación: 09/11/2021 , 12:37
 // --------------------------------------------------------------


 #define IDE_T_COMANDO_ENVIO      0x0
 #define IDE_T_COMANDO_RESPUESTA  0x1


 // ----------------------------------------------------------
 // DISPOSITIVOS: Identificadores  de dispositivos reconocidos
 //               Se  CORRESPONDEN con  los  codigos   de  los
 //               dispositivos  de  la tabla  Tbl_Dispositivos
 //               de la BBDD gescom_MEGA2560_V3.mdb
 // ----------------------------------------------------------

 // ----------------------------------------------------------
 // Fecha Generación: 09/11/2021 , 12:37
 // ----------------------------------------------------------

 #define IDE_DISPOSITIVO_RSV    0x00     //RSV, RESERVADO

 #define IDE_DISPOSITIVO_CTR    0x01     //CTR, Sistema de Control
 #define IDE_DISPOSITIVO_R00    0x10     //R00, iROB-EA-00
 #define IDE_DISPOSITIVO_R01    0x11     //R01, iROB-EA-01
 #define IDE_DISPOSITIVO_R02    0x12     //R02, iROB-EA-02

 #define IDE_DISPOSITIVO_R03    0x13     //R03, iROB-EA-03
 #define IDE_DISPOSITIVO_R04    0x14     //R04, iROB-EA-04
 #define IDE_DISPOSITIVO_R05    0x15     //R05, iROB-EA-05


 // ----------------------------------------------------------
 // PARAMETROS: Identificadores de parametros reconocidos.
 //             Se  CORRESPONDEN  con   los  codigos  de   los
 //             parametros de   la  tabla   Tbl_Parametros  de
 //             la BBDD gescom_MEGA2560_V3.mdb
 // ----------------------------------------------------------

 // ----------------------------------------------------------
 // Fecha Generación: 09/11/2021 , 12:37
 // ----------------------------------------------------------

 #define IDE_PARAM_RSV    0x0000     // RSV, RESERVADO
 #define IDE_PARAM_NOP    0x0001     // NOP, Nada
 #define IDE_PARAM_EXE    0x0002     // EXE, Ejecutar

 #define IDE_PARAM_STO    0x0003     // STO, Detener


 #define IDE_PARAM_OFF    0x0004     // OFF, Apagar
 #define IDE_PARAM__ON    0x0005     // _ON, Encender

 #define IDE_PARAM_INI    0x0006     // INI, Inicializar
 #define IDE_PARAM_AVA    0x0007     // AVA, Avanzar
 #define IDE_PARAM_RET    0x0008     // RET, Retroceder
 #define IDE_PARAM_GIZ    0x0009     // GIZ, Girar Izquierda

 #define IDE_PARAM_GDE    0x000A     // GDE, Girar derecha
 #define IDE_PARAM_BLK    0x000B     // BLK, Generar Intermitencia
 #define IDE_PARAM_CHK    0x000C     // CHK, Chequear, comprobar
 #define IDE_PARAM_CAL    0x000D     // CAL, Calibrar

 #define IDE_PARAM_ACT    0x000E     // ACT, Activar
 #define IDE_PARAM_DES    0x000F     // DES, Desactivar
 #define IDE_PARAM_RFS    0x0010     // RFS, Actualizar, refrescar
 #define IDE_PARAM__OK    0x00FD     // _OK, Dispositivo OK

 #define IDE_PARAM__ER    0x00FE     // _ER, Dispositivo ERROR
 #define IDE_PARAM_DAT    0x00FF     // DAT, Paquete de datos
 #define IDE_PARAM_SV1    0x1001     // SV1, Establecer Valor 1
 #define IDE_PARAM_SV2    0x1002     // SV2, Establecer Valor 2

 #define IDE_PARAM_GV1    0x1101     // GV1, Obtener Valor 1
 #define IDE_PARAM_GV2    0x1102     // GV2, Obtener Valor 2
 #define IDE_PARAM_GV3    0x1103     // GV3, Obtener Valor 3
 #define IDE_PARAM_GV4    0x1104     // GV4, Obtener Valor 4

 #define IDE_PARAM_GV5    0x1105     // GV5, Obtener Valor 5
 #define IDE_PARAM_GV6    0x1106     // GV6, Obtener Valor 6
 #define IDE_PARAM_GV7    0x1107     // GV7, Obtener Valor 7
 #define IDE_PARAM_LD1    0x2001     // LD1, Leds Blancos Delanteros

 #define IDE_PARAM_LD2    0x2002     // LD2, Leds Rojos Traseros
 #define IDE_PARAM_LD3    0x2003     // LD3, Foco led de la camara
 #define IDE_PARAM_SSA    0x3000     // SSA, Subsensor A
 #define IDE_PARAM_SSB    0x3001     // SSB, Subsensor B

 #define IDE_PARAM_SSC    0x3002     // SSC, Subsensor C
 #define IDE_PARAM_SSD    0x3003     // SSD, Subsensor D
 #define IDE_PARAM_CHG    0x4000     // CHG, Nivel de carga (baterias)
 #define IDE_PARAM_12P    0x5000     // 12P, Rele Alimentacion Motores

 #define IDE_PARAM_5VP    0x5001     // 5VP, Rele Alimentacion PC

   // ----------------------------------------------------------
   // FUNCIONES: Declaracion  de  funciones para implementar los
   //            comandos.
   //            De  la  tabla   Tbl_Comandos    de    la   BBDD
   //            gescom_MEGA2560_V3.mdb
   // ----------------------------------------------------------

   // ----------------------------------------------------------
   // Fecha Generación: 09/11/2021 , 12:37

   // ----------------------------------------------------------

 extern  void  cmd_Comando_CM_R00  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_CM_R01  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_CM_DBG  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_CM_RTC  (GESCOM_DATA* gd);


 extern  void  cmd_Comando_B_PPAK  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_LEDS  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_C_MIZQ  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_MDER  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_RMOV  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_SRVX  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_C_SRVY  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_TEMP  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_HUMR  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_GLUZ  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_S_SSUP  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_RGPS  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_SICC  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_SEUS  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_S_CFAN  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_SALT  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_PRES  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_RELE  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_C_STPC  (GESCOM_DATA* gd);

#endif

