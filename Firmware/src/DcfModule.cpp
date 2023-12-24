#include "Arduino.h"
#include "DcfModule.h"



const std::string DcfModule::name()
{
    return "DCF";
}

//You can also give it a version
//will be displayed in Command Infos 
const std::string DcfModule::version()
{
    return "";
}


void DcfModule::setup()
{
    
}

void DcfModule::setup1()
{
    dcf.Start();
}

void DcfModule::loop()
{
    
}

void DcfModule::loop1()
{
    delay(1000);
    time_t DCFtime = dcf.getTime(); // Check if new DCF77 time is available
    if (DCFtime != 0)
    {
        logDebugP("Time is updated");
        setTime(DCFtime);
    }
    digitalClockDisplay();
}

DcfModule openknxDcfModule;


/*
#include <Arduino.h>
#include <DCF77.h>

DCF77 dcf(D5, digitalPinToInterrupt(D5));

void setup()
{
    Serial.begin(115200);
}

void printDigits(int digits)
{
    // utility function for digital clock display: prints preceding colon and leading 0
    Serial.print(":");
    if (digits < 10)
        Serial.print('0');
    Serial.print(digits);
}

void digitalClockDisplay()
{
    // digital clock display of the time
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(" ");
    Serial.print(day());
    Serial.print(" ");
    Serial.print(month());
    Serial.print(" ");
    Serial.print(year());
    Serial.println();
}
*/