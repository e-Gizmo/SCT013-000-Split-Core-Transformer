/*
  e-Gizmo SCT013-000 Non-invasive Split-core
  Current transformer Sample code
  
  To get the value of Irms and Vrms, display on the
  Serial Monitor.
  Using EmonLib.h library for SCT013.
  
  Modified by
  e-Gizmo Mechatronix Central
  http://www.e-gizmo.com
  June 9, 2017

*/
#include "EmonLib.h"           // Include Emon Library
EnergyMonitor emon1;           // Create an instance
void setup() 
 {
 Serial.begin(9600);   
 emon1.voltage(2, 185, 1.7);  // Voltage: input pin, calibration, phase_shift   
 emon1.current(1, 111.1); // Current: input pin, calibration.
 } 
void loop() {   
double Irms = emon1.calcIrms(1480); // Calculate Irms only   
double Vrms = emon1.calcVrms(1480); // Calculate Vrms only   
Serial.print("Irms = "); 
Serial.print(Irms); // Irms   
Serial.print("  , ");  
Serial.print("Vrms = "); 
Serial.println(Vrms*2); // Vrms
}


