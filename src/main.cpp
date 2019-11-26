/*
This is the code for an Logic Analyser.
Before starting to send samples, the Teensy waits to receive 3 bytes sampling rate.
The sampling rate is in Hz.
The maximum sample rate supported is 500ksps.
If you go higher I guarantee for nothing.

Once started, the Teensy sends samples (one byte) of the first 8 Pins at the set rate.
*/

#include <Arduino.h>

IntervalTimer sampleTimer;
void sendSample();

volatile unsigned char buffer;

void setup()
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  Serial.begin(9600); // uses maximum frequency for USB = 12MHz

  int count = 0;
  char buf[3]; // 3 bytes fits 500k

  while (count < 3) // wait for 3 bytes of sample rate
  {
    if (Serial.available()) // next byte available
    {
      buf[count++] = Serial.read(); // receive all 3 bytes into "buf"
    }
  }

  int complete = buf[0] << 16 | buf[1] << 8 | buf[2]; // put buffers together to form one 24bit value
  int period = 1000000 / complete;                    // get time in us between samples

  sampleTimer.begin(sendSample, period);
}

void loop()
{
  // with 600MHz this runs so fast, that all computes between two sends
  buffer |= digitalReadFast(0) << 0;
  buffer |= digitalReadFast(1) << 1;
  buffer |= digitalReadFast(2) << 2;
  buffer |= digitalReadFast(3) << 3;
  buffer |= digitalReadFast(4) << 4;
  buffer |= digitalReadFast(5) << 5;
  buffer |= digitalReadFast(6) << 6;
  buffer |= digitalReadFast(7) << 7;
}

void sendSample()
{
  Serial.write(buffer); // write latest value
  buffer = 0;           // clear buffer
}