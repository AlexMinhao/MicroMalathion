#include "RTIMUMPU9250.h"
#include "stdio.h"

bool RTIMUMPU9250::setSampleRate(int rate)
{
	if ((rate < MPU9250_SAMPLERATE_MIN) || (rate > MPU9250_SAMPLERATE_MAX)) {
		printf("Illegal sample rate %d\r\n", rate);
		return false;
	}

	//  Note: rates interact with the lpf settings

	if ((rate < MPU9250_SAMPLERATE_MAX) && (rate >= 8000))
		rate = 8000;

	if ((rate < 8000) && (rate >= 1000))
		rate = 1000;

	if (rate < 1000) {
		int sampleDiv = (1000 / rate) - 1;
		m_sampleRate = 1000 / (1 + sampleDiv);
	}
	else {
		m_sampleRate = rate;
	}
	m_sampleInterval = (unsigned long)1000 / m_sampleRate;
	if (m_sampleInterval == 0)
		m_sampleInterval = 1;
	return true;
}

bool RTIMUMPU9250::setCompassRate(int rate)
{
	if ((rate < MPU9250_COMPASSRATE_MIN) || (rate > MPU9250_COMPASSRATE_MAX)) {
		printf("Illegal compass rate %d\r\n", rate);
		return false;
	}
	m_compassRate = rate;
	return true;
}

bool RTIMUMPU9250::IMUInit(unsigned char i2cNum)
{
	setSampleRate(m_settings->m_MPU9250GyroAccelSampleRate);
	setCompassRate(m_settings->m_MPU9250CompassSampleRate);
	gyroBiasInit();
	return true;
}
