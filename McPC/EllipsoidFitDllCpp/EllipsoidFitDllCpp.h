// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ELLIPSOIDFITDLLCPP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ELLIPSOIDFITDLLCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ELLIPSOIDFITDLLCPP_EXPORTS
#define ELLIPSOIDFITDLLCPP_API __declspec(dllexport)
#else
#define ELLIPSOIDFITDLLCPP_API __declspec(dllimport)
#endif

#ifdef FUSION
//#include "RTIMULibDefs.h"
#include "RTMath.h"
#endif


#define EIGEN_DONT_ALIGN
#include <Eigen/Dense>
using namespace Eigen;

#include <vector>
using namespace std;

vector<float> fnComputeEllipsoidIterate(int iter, Matrix<float, Dynamic, 3>& m);

#ifdef FUSION
void initIMUalg(unsigned char imuAmount);
RTQuaternion IMUCalculate(unsigned char imuID,
	RTFLOAT gx, RTFLOAT gy, RTFLOAT gz,
	RTFLOAT ax, RTFLOAT ay, RTFLOAT az,
	RTFLOAT mx, RTFLOAT my, RTFLOAT mz);
#endif