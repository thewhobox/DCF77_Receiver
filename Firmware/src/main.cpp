#include <Arduino.h>
#include "TimerInterrupt_Generic.h"
#include "OpenKNX.h"
#include "FileTransferModule.h"
#include "DcfModule.h"

void setup()
{
	const uint8_t firmwareRevision = 1;
	openknx.init(firmwareRevision);
	openknx.addModule(1, openknxDcfModule);
	openknx.addModule(3, openknxFileTransferModule);
	openknx.setup();
}

void setup1()
{
	openknx.setup1();
}

void loop()
{
	openknx.loop();
}

void loop1()
{
	openknx.loop1();
}