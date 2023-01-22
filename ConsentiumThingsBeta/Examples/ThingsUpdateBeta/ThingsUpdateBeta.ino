/***************************************************
  This is Consentium Inc's IoT library
  ----> http://consentiuminc.online/
  Check out the links above for our tutorials and product diagrams.

  This Consentium Inc's IoT library works only for 5v tolerant Edge Beta boards. 
 
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
  float data_0 = analogRead(IN_4_20_1)*SCALE; // Read 4-20mA sensor data form J1 port 1
  float data_1 = analogRead(IN_0_10_1)*SCALE; // Read 0-10V sensor data form J2 port 1

  float sensor_val[] = {data_0, data_1};  // sensor data array
  String info_buff[] = {"Temperature", "Pressure"}; // sensor info. array
  
  int sensor_num = sizeof(sensor_val)/sizeof(sensor_val[0]); // number of sensors connected 
  
  board.sendREST(key, sensor_num, info_buff, sensor_val, LOW_PRE); // send over REST with delay

  delay(interval*1000);
}
