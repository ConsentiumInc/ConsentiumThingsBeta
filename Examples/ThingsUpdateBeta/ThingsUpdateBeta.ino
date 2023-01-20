/***************************************************
  This is Consentium Inc's IoT library
  ----> http://consentiuminc.online/
  Check out the links above for our tutorials and product diagrams.

  This is Consentium Inc's IoT library works only for 5v tolerant Edge Beta boards. 
 
  Written by Debjyoti Chowdhury for Consentium Inc.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include <ConsentiumThingsBeta.h>

ConsentiumThingsBeta board;   // create ConsentiumThing beta object

const char *ssid = ""; // add WiFi SSID
const char *pass = ""; // add WiFi password
const long interval = 5; // take 5 seconds of delay 
const char *key = "";       // Write api key

void setup(){
  board.begin();   // init. IoT boad
  board.initWiFi(ssid, pass);  // begin WiFi connection
}

void loop(){
  float data_0 = analogRead(A0)*0.488; // Example sensor data read from A0
  
  float sensor_val[] = {data_0};  // sensor data array
  String info_buff[] = {"Temperature"}; // sensor info. array
  
  int sensor_num = sizeof(sensor_val)/sizeof(sensor_val[0]); // number of sensors connected 
  
  board.sendREST(key, sensor_num, info_buff, sensor_val, LOW_PRE); // send over REST with delay

  delay(interval*1000);
}
