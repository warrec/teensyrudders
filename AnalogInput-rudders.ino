float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup () {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  Serial.begin(9600);
  
}

void loop () {
  Joystick.Z(analogRead(A0));
  Joystick.X(analogRead(A1));
 
  int analogValue = analogRead(A0);

  float voltage = floatMap (analogValue, 0, 1023, 0, 5);

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  delay(10);
  
}
