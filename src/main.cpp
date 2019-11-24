#include <Arduino.h>

unsigned char buffer;

void setup()
{
  // input pins = PORT D register
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  Serial.begin(9600); // uses maximum frequency for USB = 12MHz
}

void loop()
{
  //digitalReadFast(0);
  //buffer = 0x00;
  buffer = CORE_PIN2_PORTREG; // geht, pin <-> port muss herausgefunden werden
  // vielleicht muss/sollte CORE_PIN0_PINREG genutzt werden ??????

  // pin  0 = port 1 bit 1 (0-7)
  // pin  1 = port 1 bit 2

  // pin  2 = port 2 bit 4
  // pin  3 = port 2 bit 5
  // pin  4 = port 2 bit 6

  // ...

  // ----------------- anderer versuch

  buffer = digitalReadFast(0) << 0;
  buffer |= digitalReadFast(1) << 1;
  buffer |= digitalReadFast(2) << 2;
  buffer |= digitalReadFast(3) << 3;
  buffer |= digitalReadFast(4) << 4;
  buffer |= digitalReadFast(5) << 5;
  buffer |= digitalReadFast(6) << 6;
  buffer |= digitalReadFast(7) << 7;

  Serial.println(buffer, BIN);
}