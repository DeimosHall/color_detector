// Board to use
#define esp32

#ifdef arduino_nano
  #define sensor A0
  #define rgb_red A1
  #define rbg_green A2
  #define rbg_blue A3
#endif

#ifdef esp32
  #define sensor 33
  #define rbg_red 25
  #define rbg_green 26
  #define rbg_blue 27
#endif

float voltage = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(rbg_red, OUTPUT);
  pinMode(rbg_green, OUTPUT);
  pinMode(rbg_blue, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  delay(1000);

  voltage = analogRead(sensor) * 3.3 / 4095;
  Serial.println("Voltage: " + String(voltage));

  checkColor(&voltage);
}

void checkColor(float *voltage) {
  if (*voltage >= 1.33 && *voltage <= 1.36) {
    setRed();
  } else if (*voltage >= 1.37 && *voltage <= 1.46) {
    setGreen();
  } else if (*voltage >= 1.47 && *voltage <= 1.55) {
    setBlue();
  } else if (*voltage >= 1.10 && *voltage <= 1.20) {
    setYellow();
  } else if (*voltage >= 1.25 && *voltage <= 1.32) {
    setOrange();
  } else if (*voltage >= 1.15 && *voltage <= 1.24) {
    setPurple();
  }
}

void setRed() {
  analogWrite(rbg_red, 255);
  analogWrite(rbg_green, 0);
  analogWrite(rbg_blue, 0);
  Serial.println("Color: red");
}

void setGreen() {
  analogWrite(rbg_red, 0);
  analogWrite(rbg_green, 255);
  analogWrite(rbg_blue, 0);
  Serial.println("Color: green");
}

void setBlue() {
  analogWrite(rbg_red, 0);
  analogWrite(rbg_green, 0);
  analogWrite(rbg_blue, 255);
  Serial.println("Color: blue");
}

void setYellow() {
  analogWrite(rbg_red, 255);
  analogWrite(rbg_green, 195);
  analogWrite(rbg_blue, 0);
  Serial.println("Color: yellow");
}

void setOrange() {
  analogWrite(rbg_red, 255);
  analogWrite(rbg_green, 195);
  analogWrite(rbg_blue, 0);
  Serial.println("Color: orange");
}

void setPurple() {
  analogWrite(rbg_red, 133);
  analogWrite(rbg_green, 0);
  analogWrite(rbg_blue, 255);
  Serial.println("Color: purple");
}

void turnLedOff() {
  analogWrite(rbg_red, 0);
  analogWrite(rbg_green, 0);
  analogWrite(rbg_blue, 0);
}
