#include "Adafruit_FreeTouch.h"
#define SPEAKER 2
Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A6, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A7, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A8, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_4 = Adafruit_FreeTouch(A9, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_5 = Adafruit_FreeTouch(A10, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_6 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_7 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
int BassTab[] = {1911, 1702, 1516, 1431, 1275, 1136, 1012}; //bass 1~7

void setup() {
  Serial.begin(115200);
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW);

  //  while (!Serial);
  Serial.println("FreeTouch test");
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  if (! qt_1.begin())
    Serial.println("Failed to begin qt");
  if (! qt_2.begin())
    Serial.println("Failed to begin qt");
  if (! qt_3.begin())
    Serial.println("Failed to begin qt");
  if (! qt_4.begin())
    Serial.println("Failed to begin qt");
  if (! qt_5.begin())
    Serial.println("Failed to begin qt");
  if (! qt_6.begin())
    Serial.println("Failed to begin qt");
  if (! qt_7.begin())
    Serial.println("Failed to begin qt");

}

int qt_Threshold = 850;

void loop() {
  int qt1 = 0;
  int qt2 = 0;
  int qt3 = 0;
  int qt4 = 0;
  int qt5 = 0;
  int qt6 = 0;
  int qt7 = 0;

  qt1 = qt_1.measure();
  Serial.print(qt1);
  Serial.print(",");

  qt2 = qt_2.measure();
  Serial.print(qt2);
  Serial.print(",");

  qt3 = qt_3.measure();
  Serial.print(qt3);
  Serial.print(",");

  qt4 = qt_4.measure();
  Serial.print(qt4);
  Serial.print(",");

  qt5 = qt_5.measure();
  Serial.print(qt5);
  Serial.println();

  qt6 = qt_6.measure();
  Serial.print(qt6);
  Serial.println();

  qt7 = qt_7.measure();
  Serial.print(qt7);
  Serial.println();

  if (qt1 >= qt_Threshold) {
    sound(1);
  }
  if (qt2 >= qt_Threshold) {
    sound(2);
  }
  if (qt3 >= qt_Threshold) {
    sound(3);
  }
  if (qt4 >= qt_Threshold) {
    sound(4);
  }
  if (qt5 >= qt_Threshold) {
    sound(5);
  }
  if (qt6 >= qt_Threshold) {
    sound(6);
  }
  if (qt7 >= qt_Threshold) {
    sound(7);
  }

}

void sound(uint8_t note_index)
{
  for (int i = 0; i < 50; i++)
  {
    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(BassTab[note_index-1]);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(BassTab[note_index-1]);
  }
}
