#include "Arduino.h"
#include "OpenKNX.h"

class DcfModule : public OpenKNX::Module
{
	public:

		void loop() override;
		void loop1() override;
		void setup() override;
		void setup1() override;
		bool processCommand(const std::string cmd, bool diagnoseKo) override;
		void processInputKo(GroupObject &ko) override;

		const std::string name() override;
		const std::string version() override;

    private:
        DCF77 dcf(D5, digitalPinToInterrupt(D5));

}

//extern DcfModule openknxDcfModule;