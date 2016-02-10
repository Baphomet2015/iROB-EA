

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
 // Fecha Generación: 21/09/2015 , 12:21

 // ----------------------------------------------------------
 #define  IDE_CMD_CM_RSV    0x00     // Comando Reservado

 #define  IDE_CMD_CM_RET    0x01     // Comando Respuesta
 #define  IDE_CMD_CM_DBG    0x02     // Comando DEBUG
 #define  IDE_CMD_S_MDER    0x10     // Sensor Corriente motor derecho
 #define  IDE_CMD_S_MIZQ    0x11     // Sensor Corriente motor izquierdo

 #define  IDE_CMD_B_LIPO    0x12     // Bateria LiPo
 #define  IDE_CMD_B_PPAK    0x13     // Bateria Power Pack
 #define  IDE_CMD_S_CDBG    0x14     // Sensor Indicador de conector DEBUG conectado
 #define  IDE_CMD_S_MLX9    0x15     // Sensor de Temperatura Melexis 90614

 #define  IDE_CMD_R_TIME    0x20     // Reloj de Tiempo Real
 #define  IDE_CMD_L_LEDS    0x21     // Control de los Leds
 #define  IDE_CMD_C_MIZQ    0x30     // Control motor izquierdo
 #define  IDE_CMD_C_MDER    0x31     // Control motor derecho

 #define  IDE_CMD_C_RMOV    0x32     // Comando de movimiento








  // --------------------------------------------------------------
  // TIPO COMANDOS: Identificadores de tipos de comandos
  //                son los especificados en Gescom_MEGA2560_V3.doc
  // --------------------------------------------------------------

 // --------------------------------------------------------------
 // Fecha Generación: 21/09/2015 , 12:21
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
 // Fecha Generación: 21/09/2015 , 12:21

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
 // Fecha Generación: 21/09/2015 , 12:21
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
 #define IDE_PARAM_ERR    0x00FE     // ERR, Error
 #define IDE_PARAM_DAT    0x00FF     // DAT, Paquete de datos
 #define IDE_PARAM_SVE    0x1000     // SVE, Establecer Velocidad

 #define IDE_PARAM_SET    0x1001     // SET, Establecer Valor, generico
 #define IDE_PARAM_SMO    0x1002     // SMO, Establecer Movimiento
 #define IDE_PARAM_GCO    0x1100     // GCO, Obtener Consumo
 #define IDE_PARAM_GET    0x1101     // GET, Obtener Valor (generico)

 #define IDE_PARAM_GMO    0x1102     // GMO, Obtener Movimiento
 #define IDE_PARAM_LD1    0x2001     // LD1, Leds Blancos Delanteros
 #define IDE_PARAM_LD2    0x2002     // LD2, Leds Blancos Traseros
 #define IDE_PARAM_LD3    0x2003     // LD3, Leds Rojos Traseros

 #define IDE_PARAM_SSA    0x3000     // SSA, Subsensor A
 #define IDE_PARAM_SSB    0x3001     // SSB, Subsensor B
 #define IDE_PARAM_CHG    0x4000     // CHG, Nivel de carga ( baterias)
 #define IDE_PARAM_POW    0x4001     // POW, Capacidad disponible ( baterias)


   // ----------------------------------------------------------
   // FUNCIONES: Declaracion  de  funciones para implementar los
   //            comandos.
   //            De  la  tabla   Tbl_Comandos    de    la   BBDD
   //            gescom_MEGA2560_V3.mdb
   // ----------------------------------------------------------

   // ----------------------------------------------------------
   // Fecha Generación: 21/09/2015 , 12:21
   // ----------------------------------------------------------

 extern  void  cmd_Comando_CM_RSV  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_CM_RET  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_CM_DBG  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_MDER  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_MIZQ  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_B_LIPO  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_B_PPAK  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_CDBG  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_S_MLX9  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_R_TIME  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_L_LEDS  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_MIZQ  (GESCOM_DATA* gd);
 extern  void  cmd_Comando_C_MDER  (GESCOM_DATA* gd);

 extern  void  cmd_Comando_C_RMOV  (GESCOM_DATA* gd);

#endif

