#ifndef ConsentiumThingsBeta_h
#define ConsentiumThingsBeta_h

#include <Arduino.h>  
       

#define COMM_BAUD 115200
#define INTERVAL_MUL 1000

#define LOW_PRE 2
#define MID_PRE 4
#define HIGH_PRE 6

bool sendAT(String, char[]);

class ConsentiumThingsBeta{
    public:
        ConsentiumThingsBeta();
        void begin();
        void initWiFi(const char*, const char*);
        void sendREST(const char*, int, String[], float[], int);
};

#endif