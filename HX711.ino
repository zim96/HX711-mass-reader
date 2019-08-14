#include <HX711.h>

#define DOUT 7  // Arduino pin 6 connect to HX711 DOUT
#define CLK 8  //  Arduino pin 5 connect to HX711 CLK

#define CAL_FAC 234
 
HX711 scale;  // Init of library

void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, CLK); // Start scale
  scale.set_scale(CAL_FAC);  // Adjust scale settings
  scale.tare();       // Reset scale to zero
}

void loop() {
  float current_weight = scale.get_units(25);  // get average of 25 scale readings
  String str = String(current_weight) + " g";
  Serial.println(current_weight);  // Print the scale factor to use
}
