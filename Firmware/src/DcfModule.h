#include "Arduino.h"
#include "OpenKNX.h"
#include "DCF77.h"

#define DCF_PIN 15

class DcfModule : public OpenKNX::Module
{
	public:
		DcfModule();
		void loop(bool conf) override;
		void loop1(bool conf) override;
		void setup() override;
		void setup1(bool conf) override;
		//bool processCommand(const std::string cmd, bool diagnoseKo) override;
		//void processInputKo(GroupObject &ko) override;

		const std::string name() override;
		const std::string version() override;

    private:
        DCF77 dcf;
		void printTime();
		unsigned long lastTimeShowed = 0;

};

extern DcfModule openknxDcfModule;