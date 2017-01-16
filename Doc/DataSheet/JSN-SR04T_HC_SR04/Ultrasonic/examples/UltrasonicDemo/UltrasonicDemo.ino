#include "Ultrasonic.h"

Ultrasonic ultrasonic(12,13);
void setup() {
Serial.begin(9600);
}

void loop()
{
Serial.println(ultrasonic.Ranging(CM));
delay(100);
}




