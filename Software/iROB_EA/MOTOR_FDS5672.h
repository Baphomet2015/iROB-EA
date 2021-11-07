// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        MOTOR_FDS5672.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Enero 2021
//
// Funcionalidad:  Definicion de la clase UF_MOT
//
// Notas:          REVISADO 27/04/2021
//
// ---------------------------------------------------------


#ifndef MOTOR_FDS5672_H
#define MOTOR_FDS5672_H


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_MOTOR_FDS5672_PULSO_VAL      2000   // Pulso para validar datos en el FDS672 microsegundos

#define IDE_MOTOR_FDS5672_VELDEFECTO     0x7F   // Velocidad por defecto


// ---------------------------------------------------------
//
// Definicion de la Clase MOTOR_FDS5672
//
// ---------------------------------------------------------

class MOTOR_FDS5672
{
  
  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  public:
          
            MOTOR_FDS5672   (int pin_DIR,int pin_RST,int pin_PWM);
     void   begin           (void);
     void   avance          (void);
     void   retroceso       (void);
     void   paro            (void);
     void   velocidad       (byte valor);
     

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     int  pinDIR;
     int  pinRST;
     int  pinPWM;
     byte vVelocidad;

     void setValores (void);     
     

};









#endif
