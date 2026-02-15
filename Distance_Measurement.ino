#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIG_PIN 5      
#define ECHO_PIN 18     
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Khoi dong..."); 
  display.display();
  delay(1000); 
}

void loop() {
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  display.clearDisplay();
  display.setCursor(0, 0);

  if (duration == 0) {
    display.println("Khong thay vat can"); 
  } 
  else {
    distance = (float)duration / 58.0;

    if (distance < 2 || distance > 400) {
      display.println("Sai gia tri"); 
    } 
    else {
      display.print("Khoang cach: ");
      display.print(distance);
      display.println(" cm"); 
      
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  }

  display.display();
  delay(1000); 
}
