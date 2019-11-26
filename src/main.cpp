#include <Arduino.h>

IntervalTimer sampleTimer;
void sendSample();

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

  sampleTimer.begin(sendSample, 1000);
}

void loop()
{
}

void sendSample()
{
  unsigned char buffer;

  buffer = digitalReadFast(0) << 0;
  buffer |= digitalReadFast(1) << 1;
  buffer |= digitalReadFast(2) << 2;
  buffer |= digitalReadFast(3) << 3;
  buffer |= digitalReadFast(4) << 4;
  buffer |= digitalReadFast(5) << 5;
  buffer |= digitalReadFast(6) << 6;
  buffer |= digitalReadFast(7) << 7;

  Serial.write(buffer);
}