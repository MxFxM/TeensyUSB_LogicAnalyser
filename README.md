# TeensyUSB_LogicAnalyser
For use with Teensy 4.0

Logic Analyser using a Teensy and PC as storage and analyser device.


This is the code for an Logic Analyser.
Before starting to send samples, the Teensy waits to receive 3 bytes sampling rate.
The sampling rate is in Hz.
The maximum sample rate supported is 500ksps.
If you go higher I guarantee for nothing.
Once started, the Teensy sends samples (one byte) of the first 8 Pins at the set rate.
