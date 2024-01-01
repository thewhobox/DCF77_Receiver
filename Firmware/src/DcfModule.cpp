#include "Arduino.h"
#include "DcfModule.h"


DcfModule::DcfModule() : dcf(DCF_PIN, digitalPinToInterrupt(DCF_PIN))
{
    
}

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

void DcfModule::setup1(bool conf)
{
    dcf.Start();
}

void DcfModule::loop(bool conf)
{
    
}

void DcfModule::loop1(bool conf)
{
    if(millis() - lastTimeShowed > 1000)
    {
        lastTimeShowed = millis();
        time_t DCFtime = dcf.getTime(); // Check if new DCF77 time is available
        if (DCFtime != 0)
        {
            logDebugP("Time is updated");
            //setTime(DCFtime);
            tm *newt = new tm();
            newt->tm_year = year() - 1900;
            newt->tm_mon = month() - 1;
            newt->tm_mday = day();
            newt->tm_hour = hour();
            newt->tm_min = minute();
            newt->tm_sec = second();
            timer.setDateTimeFromBus(newt);
            delete newt;
        }
        printTime();
    }
}

void DcfModule::printTime()
{
    logInfoP("Time: %.2i:%.2i:%.2i %i-%i-%i ", timer.getHour(), timer.getMinute(), timer.getSecond(), timer.getDay(), timer.getMonth(), timer.getYear());
}

DcfModule openknxDcfModule;