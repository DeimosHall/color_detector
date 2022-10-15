// Board to use
#define esp32

#ifdef arduino_nano
  #define sensor A0
  #define red A1
  #define green A2
  #define blue A3
#endif

#ifdef esp32
  #define sensor 33
  #define red 25
  #define green 26
  #define blue 27
#endif

float voltage = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  delay(1000);

  voltage = analogRead(sensor) * 3.3 / 4095;
  Serial.println("Voltage: " + String(voltage));
}

void setRed() {
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void setGreen() {
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 0);
}

void setBlue() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void setYellow() {
  analogWrite(red, 255);
  analogWrite(green, 195);
  analogWrite(blue, 0);
}

void setPurple() {
  analogWrite(red, 133);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void setWhite() {
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void turnLedOff() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}
