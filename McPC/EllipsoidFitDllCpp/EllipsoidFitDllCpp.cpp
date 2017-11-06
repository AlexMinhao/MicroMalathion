// EllipsoidFitDllCpp.cpp : Defines the exported functions for the DLL application.
//

#include "EllipsoidFitDllCpp.h"

#undef FUSION
#ifdef FUSION
#include "RTIMUSettings.h"
#include "RTIMUMPU9250.h"
#endif

extern vector<float> ComputeEllipsoidIterateWrapper(int iter, Matrix<float, Dynamic, 3>& m);

vector<float> fnComputeEllipsoidIterate(int iter, Matrix<float, Dynamic, 3>& m)
{
	return ComputeEllipsoidIterateWrapper(iter, m);
}

#ifdef FUSION
vector<RTIMUSettings> g_IMUsettings;
vector<RTIMUMPU9250> g_imuA;

void initIMUalg(unsigned char imuAmount)
{
	g_IMUsettings = vector<RTIMUSettings>(imuAmount);
	g_imuA = vector<RTIMUMPU9250>(imuAmount);

	for (int imuIndex = 0; imuIndex < imuAmount; imuIndex++)
	{
		g_IMUsettings[imuIndex].setDefaults(imuIndex);
		//g_IMUsettings[imuIndex].loadSettings();

		//g_settings[imuIndex].loadSettings();
		g_imuA[imuIndex].Setting(&g_IMUsettings[imuIndex]);

		g_imuA[imuIndex].IMUInit(imuIndex);

		g_imuA[imuIndex].setSlerpPower((float)0.1);
		g_imuA[imuIndex].setGyroEnable(true);
		g_imuA[imuIndex].setAccelEnable(true);
		g_imuA[imuIndex].setCompassEnable(true);
		g_imuA[imuIndex].setCompassCalibrationMode(false);

	}
}

RTQuaternion IMUCalculate(unsigned char imuID,
	RTFLOAT gx, RTFLOAT gy, RTFLOAT gz, 
	RTFLOAT ax, RTFLOAT ay, RTFLOAT az,
	RTFLOAT mx, RTFLOAT my, RTFLOAT mz)
{
	g_imuA[imuID].setIMUData(gx,gy,gz,ax,ay,az,mx,my,mz);
	g_imuA[imuID].IMUCalculate(9);
	return g_imuA[imuID].getIMUData().fusionQPose;
}
#endif