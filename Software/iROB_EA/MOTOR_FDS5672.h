// ---------------------------------------------------------
//
// Proyecto:       iROB-EA
// Version:        1.0
// Fichero:        MOTOR_FDS5672.h
// Autor:
// Hardware:       Arduino MEGA 2560
// Fecha:          Abril 2015
//
// Funcionalidad:  Definicion de la clase UF_MOT
//
// Notas:          REVISADO 08/04/2016
//
// ---------------------------------------------------------


#ifndef MOTOR_FDS5672_H
#define MOTOR_FDS5672_H


// ---------------------------------------------------------
//
// Definicion de Pines relacionados con el manejo de esta clase
//
// ---------------------------------------------------------

#define IDE_MOTOR_FDS5672_PULSO_VAL      500    // Pulso de validacion

                                                // NO CAMBIAR estos defines, el valor es la representacion real de FF1 y FF2
#define IDE_MOTOR_FDS5672_OK             0      // Motor sin fallos
#define IDE_MOTOR_FDS5672_CORTOCIRCUITO  1      // Cortocircuito
#define IDE_MOTOR_FDS5672_TEMPERATURA    2      // Sobre calentamiento
#define IDE_MOTOR_FDS5672_TENSION        3      // Voltaje demasiado bajo


#define IDE_MOTOR_FDS5672_VELDEFECTO    50      // Velocidad por defecto


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
          
          MOTOR_FDS5672    (int pin_DIR,int pin_PWM,int pin_RST,int pin_FF1,int pin_FF2,int pin_ICC);
     void inicio           (void);
     void avance           (void);
     void retroceso        (void);
     void paro             (void);
     void velocidad        (byte valor);
     void inhibir          (byte modo);
     byte getEstado        (void);   

  // ---------------------------------------------------------
  //
  // ---------------------------------------------------------
  private:

     void setValores (void);     

     int  pinDIR;
     int  pinPWM;
     int  pinRST;
     int  pinFF1;
     int  pinFF2;
     int  pinICC;

     byte vVelocidad;
     byte flgInhibir;
};









#endif




