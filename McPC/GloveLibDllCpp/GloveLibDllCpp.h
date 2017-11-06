// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the GLOVELIBDLLCPP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// GLOVELIBDLLCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GLOVELIBDLLCPP_EXPORTS
#define GLOVELIBDLLCPP_API __declspec(dllexport)
#else
#define GLOVELIBDLLCPP_API __declspec(dllimport)
#endif

#include "Definitions.h"
#include "MotionCapture.h"

GLOVELIBDLLCPP_API MotionCapture* __stdcall mc_newInstance();
GLOVELIBDLLCPP_API void __stdcall mc_setModle(MotionCapture* pMC, HWV_T hwVer, SkeletonType m);
GLOVELIBDLLCPP_API void mc_onDataReceived(MotionCapture* pMC, unsigned char* pbuf, int lbuf);
GLOVELIBDLLCPP_API void mc_reset(MotionCapture* pMC);
GLOVELIBDLLCPP_API void mc_GetCurrentAngle(MotionCapture* pMC, double* outbuf, int buflen);
//GLOVELIBDLLCPP_API Gesture mc_GetCurrentGesture(MotionCapture* pMC, ); TODO
GLOVELIBDLLCPP_API void mc_UpdateJoints(MotionCapture* pMC, UnityModelType umType);
GLOVELIBDLLCPP_API void mc_AddTestData(MotionCapture* pMC); // only for test purpose, stub data
GLOVELIBDLLCPP_API void mc_GetQuat(MotionCapture* pMC, BoneType joint, float* floatQ); // float[w,x,y,z]
GLOVELIBDLLCPP_API bool mc_jointValid(MotionCapture* pMC, BoneType bone);
GLOVELIBDLLCPP_API void mc_GetSensorJointUnion(MotionCapture* pMC, float* sju); //test function, to be deleted
GLOVELIBDLLCPP_API void mc_AddTestRawData(MotionCapture* pMC, int nodeid, float x, float y, float z);
// no need to expose this interface
//GLOVELIBDLLCPP_API void mc_GetMagMatrix(MotionCapture* pMC, int id, float** matrix3x3);
GLOVELIBDLLCPP_API void mc_TestEllipsoidFit(MotionCapture* pMC, int nodeid);
GLOVELIBDLLCPP_API void mc_GetNodeRawQuat(MotionCapture* pMC, int nodeid, float* floatQ);
GLOVELIBDLLCPP_API void mc_registerHandShakeCB(MotionCapture* pMC, HandShakeCB_T func);
GLOVELIBDLLCPP_API void mc_registerSerialPortWriteCB(MotionCapture* pMC, WriteCB_T func);
GLOVELIBDLLCPP_API void mc_registerRawDataReceivedCB(MotionCapture* pMC, RawDataReceivedCB_T func);
GLOVELIBDLLCPP_API void mc_sendHandShake(MotionCapture* pMC);
GLOVELIBDLLCPP_API void mc_sendRaw(MotionCapture* pMC, unsigned int nodeid, bool isSend);
GLOVELIBDLLCPP_API void mc_startCali(MotionCapture* pMC);
GLOVELIBDLLCPP_API void mc_stopCali(MotionCapture* pMC);