// Project JBdrum
// Jan 2016, TEAM "DTMR"
// Author : Jisoon Lim (tenihil), Minshik Sohn (surajang)

import arb.soundcipher.*;
import processing.serial.*;

SoundCipher sc = new SoundCipher(this);
Serial myPort;  
int inByte = 0;

void setup() 
{
  frameRate(1000);
  String portName = Serial.list()[2]; // 
  
  println(portName);
  myPort = new Serial(this, portName, 115200); 
}

void draw() 
{
  //background(64);
  while ( myPort.available() > 0)
  {
    inByte = myPort.read();
    
    if ( inByte == '1' )      
    { 
      sc.playNote(0, 9, 0, 36, 127, 0.25, 0.8, 64);
      println("1: Kick"); 
    }
    else if ( inByte == '2' ) 
    { 
      sc.playNote(0, 9, 0, 38, 127, 0.25, 0.8, 64);
      println("2: Snare"); 
    }
    else
    {
      println("Undefined byte", inByte);
    }
  }
}

  // playNote(double startBeat, double channel, double instrument, 
  //   double pitch, double dynamic, double duration,
  //   double articulation, double pan)
  //sc.playNote(0, 9, 0, 36, 100, 0.25, 0.8, 64); // Kick
  //sc.playNote(0, 9, 0, 38, 100, 0.25, 0.8, 64); // SNARE
  //sc.playNote(0, 9, 0, 42, 100, 0.25, 0.8, 64); // Hi-Hat
  //sc.playNote(0, 9, 0, 44, 100, 0.25, 0.8, 64); // PEDAL-HI-HAT
  //sc.playNote(0, 9, 0, 48, 100, 0.25, 0.8, 64); // HI-MID-TOM
  //sc.playNote(0, 9, 0, 45, 100, 0.25, 0.8, 64); // LOW-TOM
  //sc.playNote(0, 9, 0, 51, 100, 0.25, 0.8, 64); // RIDE
  //sc.playNote(0, 9, 0, 55, 100, 0.25, 0.8, 64); // SPLASH_SYMBAL
  //sc.playNote(0, 9, 0, 52, 100, 0.25, 0.8, 64); // CHINESE_SYMBAL
  //sc.playNote(0, 9, 0, 39, 100, 0.25, 0.8, 64); // HAND_CLAP
  //sc.playNote(0, 9, 0, 49, 100, 0.25, 0.8, 64); // CRASH_CYMBAL_1
  //sc.playNote(0, 9, 0, 57, 100, 0.25, 0.8, 64); // CRASH_CYMBAL_2