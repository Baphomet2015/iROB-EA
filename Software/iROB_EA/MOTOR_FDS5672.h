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

#define IDE_MOTOR_FDS5672_VEL_DEFECTO    0x7F   // Velocidad por defecto
#define IDE_MOTOR_FDS5672_VEL_LIMITADA   0x1F   // Velocidad limitada

#define IDE_MOTOR_FDS5672_PARO              0   // Estado del motor: Motor parado
#define IDE_MOTOR_FDS5672_AVANCE            1   // Estado del motor: Motor avance
#define IDE_MOTOR_FDS5672_RETROCESO         2   // Estado del motor: Motor retroceso

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
          
            MOTOR_FDS5672    (int pin_DIR,int pin_RST,int pin_PWM);
     void   begin            (void);
     void   avance           (void);
     void   retroceso        (void);
     void   paro             (void);
     void   velocidad        (byte valor);
     void   limitarVelocidad (byte modo);
     byte   getModo          (void)   { return(modo); }
     

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     int  pinDIR;
     int  pinRST;
     int  pinPWM;
     byte vVelocidad;
     byte lVelocidad;
     byte modo;

     void setValores (void);     
     

};









#endif
