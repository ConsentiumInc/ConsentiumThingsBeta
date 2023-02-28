#ifndef ConsentiumThingsBeta_h
#define ConsentiumThingsBeta_h

#include <Arduino.h>  
       
// internal defs
#define COMM_BAUD 115200
#define INTERVAL_MUL 1000

// io definitions
#define SCALE 0.0048828125

#define IN_4_20_1 A0
#define IN_4_20_2 A1
#define IN_4_20_3 A2 

#define IN_0_10_1 A3
#define IN_0_10_2 A4
#define IN_0_10_3 A5

#define IN_0_5_1 A6
#define IN_0_5_2 A7

// precision value
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
