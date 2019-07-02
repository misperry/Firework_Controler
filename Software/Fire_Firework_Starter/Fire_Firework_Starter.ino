/*
 *    File Name: Fire_Firework_Starter.ino
 *    Author:  misperry
 *    Date: 06/23/2019
 *    
 *    Description:  This is the main Firmware for the Bluetooth Enabled
 *    Firework system.  The connections will be as follows on the Fire beetle
 *    
 *    Port 1: IO25
 *    Port 2: IO26
 *    Port 3: IO27
 *    Port 4: IO3
 *    Port 5: IO0
 *    Port 6: IO13
 *    Port 7: IO5
 *    Port 8: IO2
 *    
 *    
 *    Also if you send any letter a to f for each character it will increase
 *    the hold-on time of the realy by 500ms.
 *    
 *    i.e. a = 500ms, b = 1000ms, c = 1500ms, etc.
 */

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  //Declair and initialize the pins
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(2, HIGH);
}

void loop() {
  char cmd = 'N';
  int ms_delay = 1500;

  if (SerialBT.available()) {
    cmd = SerialBT.read();
    Serial.write(cmd);
  }

  if (cmd == '1')
  {
    digitalWrite(25, LOW);
    delay(ms_delay);
    digitalWrite(25, HIGH);
    cmd = 'N';
  }
  else if (cmd == '2')
  {
    digitalWrite(26, LOW);
    delay(ms_delay);
    digitalWrite(26, HIGH);
    cmd = 'N';
  }
  else if (cmd == '3')
  {
    digitalWrite(27, LOW);
    delay(ms_delay);
    digitalWrite(27, HIGH);
    cmd = 'N';
  }
  else if (cmd == '4')
  {
    digitalWrite(3, LOW);
    delay(ms_delay);
    digitalWrite(3, HIGH);
    cmd = 'N';
  }
  else if (cmd == '5')
  {
    digitalWrite(0, LOW);
    delay(ms_delay);
    digitalWrite(0, HIGH);
    cmd = 'N';
  }
  else if (cmd == '6')
  {
    digitalWrite(13, LOW);
    delay(ms_delay);
    digitalWrite(13, HIGH);
    cmd = 'N';
  }
  else if (cmd == '7')
  {
    digitalWrite(5, LOW);
    delay(ms_delay);
    digitalWrite(5, HIGH);
    cmd = 'N';
  }
  else if (cmd == '8')
  {
    digitalWrite(2, LOW);
    delay(ms_delay);
    digitalWrite(2, HIGH);
    cmd = 'N';
  }
  else if (cmd = 'a')
  {
    ms_delay = 500;
  }
  else if (cmd = 'b')
  {
    ms_delay = 1000;
  }
  else if (cmd = 'c')
  {
    ms_delay = 1500;
  }
  else if (cmd = 'd')
  {
    ms_delay = 2000;
  }
  else if (cmd = 'e')
  {
    ms_delay = 2500;
  }
  else if (cmd = 'f')
  {
    ms_delay = 3000;
  }
  else
  {
    cmd = 'N';
  }
  
  delay(20);
}
