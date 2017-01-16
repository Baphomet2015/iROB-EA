// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        UF_BAT.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Definicion de la clase UF_BAT
//
// Notas:          REVISADO 08/04/2016 
//
// ---------------------------------------------------------


#ifndef UF_BAT_H
#define UF_BAT_H


// ---------------------------------------------------------
//
// Definiciones relacionadas con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_CAPACIDAD_BAT_LIPO           6500  // Capacidad en miliamperios de la Bateria LiPoPack equipada
#define IDE_CAPACIDAD_BAT_PPAK          10400  // Capacidad en miliamperios de la Bateria PowerPack equipada

#define IDE_ICC_PAUSA                     500  // Pausa para medir los sensores de Icc durante su calibracion

#define IDE_ICC_NUN_MEDIDAS                10  // Numero de medidas realizadas para calibrar los sensores de Icc


// ---------------------------------------------------------
//
// Definicion de la Clase UF_BAT
//
// ---------------------------------------------------------

class UF_BAT 
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
                 UF_BAT          (int pin_INBP,int pin_INB0,int pin_INB1,int pin_INB2,int pin_INBS,int pin_CHG_PPAK,int pin_CHG_LIPO);
          void   inicio          (void);
          int    get_LedChgLiPo  (void);
          int    get_LedChgPpak  (void);
          int    get_FlgCarga    (void);
          double get_IccChgLiPo  (void);
          double get_IccChgPpak  (void);
          void   ctrl_Baterias   (void);





  // ---------------------------------------------------------
  //
  //
  // ---------------------------------------------------------
  private:

     int pinINBP;
     int pinINB0;
     int pinINB1;
     int pinINB2;
     int pinINBS;
     int pinCHG_PPAK;
     int pinCHG_LIPO;





     
};









#endif



