#pragma once

#include "RTIMU.h"


#define MPU9250_SAMPLERATE_MIN      5                       // 5 samples per second is the lowest
#define MPU9250_SAMPLERATE_MAX      32000                   // 32000 samples per second is the absolute maximum

//  compass rate defines

#define MPU9250_COMPASSRATE_MIN     1                       // 1 samples per second is the lowest
#define MPU9250_COMPASSRATE_MAX     100                     // 100 samples per second is maximum

class RTIMUMPU9250 : public RTIMU
{
public:
	RTIMUMPU9250() {};
	virtual ~RTIMUMPU9250() {};

	bool setSampleRate(int rate);
	bool setCompassRate(int rate);

	virtual const char *IMUName() { return "MPU-9250"; }
	virtual int IMUType() { return 7; }
	virtual bool IMUInit(unsigned char i2cNum);
	virtual bool IMURead() { return false;  };
	virtual int IMUGetPollInterval() { return 0; };

	int m_compassRate;                                      // compass sample rate in Hz
};

