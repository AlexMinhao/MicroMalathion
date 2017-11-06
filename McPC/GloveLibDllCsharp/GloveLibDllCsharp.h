// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the GLOVELIBDLLCSHARP_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// GLOVELIBDLLCSHARP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

/* */

#ifdef GLOVELIBDLLCSHARP_EXPORTS
#define GLOVELIBDLLCSHARP_API extern "C" \
__declspec(dllexport)
#else
#define GLOVELIBDLLCSHARP_API __declspec(dllimport)
#endif

#include "Definitions.h"

GLOVELIBDLLCSHARP_API MotionCapture* __stdcall mc_newInstance();
GLOVELIBDLLCSHARP_API void __stdcall mc_setModel(MotionCapture* pMC, HWV_T hwVer, SkeletonType m);
GLOVELIBDLLCSHARP_API void __stdcall mc_onDataReceived(MotionCapture* pMC, unsigned char* pbuf, int lbuf);
GLOVELIBDLLCSHARP_API void __stdcall mc_reset(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_GetCurrentAngle(MotionCapture* pMC, double* outbuf, int buflen);
//GLOVELIBDLLCSHARP_API Gesture __stdcall mc_GetCurrentGesture(MotionCapture* pMC, ); TODO
GLOVELIBDLLCSHARP_API void __stdcall mc_UpdateJoints(MotionCapture* pMC, UnityModelType umType);
GLOVELIBDLLCSHARP_API void __stdcall mc_SetInitQ(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_AddTestData(MotionCapture* pMC); // only for test purpose, stub data
GLOVELIBDLLCSHARP_API void __stdcall mc_GetQuat(MotionCapture* pMC, BoneType joint, float* floatQ); // float[w,x,y,z]
GLOVELIBDLLCSHARP_API void __stdcall mc_GetQuatU(MotionCapture* pMC, BoneType joint, float* floatQ); // float[w,x,y,z]
GLOVELIBDLLCSHARP_API bool __stdcall mc_jointValid(MotionCapture* pMC, BoneType bone);
GLOVELIBDLLCSHARP_API void __stdcall mc_GetSensorJointUnion(MotionCapture* pMC, float* sju); //test function, to be deleted
GLOVELIBDLLCSHARP_API void __stdcall mc_AddTestRawData(MotionCapture* pMC, int nodeid, float x, float y, float z);
// no need to expose this interface
//GLOVELIBDLLCSHARP_API void mc_GetMagMatrix(MotionCapture* pMC, int id, float** matrix3x3);
GLOVELIBDLLCSHARP_API void __stdcall mc_TestEllipsoidFit(MotionCapture* pMC, int nodeid);
GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeRawQuat(MotionCapture* pMC, int nodeid, float* floatQ);
GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeQuat(MotionCapture* pMC, int nodeid, float* floatQ);
GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeRawData(MotionCapture* pMC, int nodeid, float* pFloat);
GLOVELIBDLLCSHARP_API void __stdcall mc_registerHandShakeCB(MotionCapture* pMC, HandShakeCB_T func);
GLOVELIBDLLCSHARP_API void __stdcall mc_registerHwSysInfoCB(MotionCapture* pMC, HwSysInfoCB_T func);
GLOVELIBDLLCSHARP_API void __stdcall mc_registerSerialPortWriteCB(MotionCapture* pMC, WriteCB_T func);
GLOVELIBDLLCSHARP_API void __stdcall mc_registerRawDataReceivedCB(MotionCapture* pMC, RawDataReceivedCB_T func);
GLOVELIBDLLCSHARP_API void __stdcall mc_sendHandShake(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_sendRaw(MotionCapture* pMC, unsigned int nodeid, bool isSend);
GLOVELIBDLLCSHARP_API void __stdcall mc_startCali(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_stopCali(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_getHwSysInfo(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API BoneType __stdcall mc_boneByID(MotionCapture* pMC, int id);
GLOVELIBDLLCSHARP_API void __stdcall mc_clearMoveGroup(MotionCapture* pMC);
GLOVELIBDLLCSHARP_API void __stdcall mc_addSingleBoneMove(MotionCapture* pMC, BoneType bone, float beginw, float beginx, float beginy, float beginz, float endw, float endx, float endy, float endz, float interval);
GLOVELIBDLLCSHARP_API void __stdcall mc_getMatchScore(MotionCapture* pMC, BoneType bone, float * pCompletionRate, float* pAngleDeviation);
GLOVELIBDLLCSHARP_API float __stdcall mc_angleBetween2Bones(MotionCapture* pMC, BoneType bone1, BoneType bone2);