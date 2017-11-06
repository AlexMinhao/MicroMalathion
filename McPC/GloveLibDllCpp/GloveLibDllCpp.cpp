// GloveLibDllCpp.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Definitions.h"
#include "DataWarehouse.h"
#include "MotionCapture.h"
#include "GloveLibDllCpp.h"
#include "EllipsoidFitDllCpp.h"


GLOVELIBDLLCPP_API MotionCapture* __stdcall mc_newInstance()
{
	MotionCapture* inst = new MotionCapture();
	return inst;
}

GLOVELIBDLLCPP_API void __stdcall mc_setModle(MotionCapture* pMC, HWV_T hwVer, SkeletonType m)
{
	pMC->setModel(hwVer, m);
}

GLOVELIBDLLCPP_API void mc_onDataReceived(MotionCapture* pMC, unsigned char* pbuf, int lbuf)
{
	pMC->onDataReceived(pbuf, lbuf);
}


GLOVELIBDLLCPP_API void mc_reset(MotionCapture* pMC)
{
	pMC->reset();
}


GLOVELIBDLLCPP_API void mc_GetCurrentAngle(MotionCapture* pMC, double* outbuf, int buflen)
{
	pMC->GetCurrentAngle(outbuf, buflen);
}

//Gesture mc_GetCurrentGesture(MotionCapture* pMC, ); TODO
GLOVELIBDLLCPP_API void mc_AddTestData(MotionCapture* pMC)// only for test purpose, stub data
{
	pMC->AddTestData();
}


GLOVELIBDLLCPP_API void mc_UpdateJoints(MotionCapture* pMC, UnityModelType umType)
{
	pMC->UpdateJoints(umType);
}

GLOVELIBDLLCPP_API void mc_GetQuat(MotionCapture* pMC, BoneType joint, float* floatQ) // float[w,x,y,z]
{
	return pMC->GetQuat(joint, floatQ);
}


GLOVELIBDLLCPP_API bool mc_jointValid(MotionCapture* pMC, BoneType bone)
{
	return pMC->jointValid(bone);
}


GLOVELIBDLLCPP_API void mc_GetSensorJointUnion(MotionCapture* pMC, float* sju) //test function, to be deleted
{
	pMC->GetSensorJointUnion(sju);
}


GLOVELIBDLLCPP_API void mc_AddTestRawData(MotionCapture* pMC, int nodeid, float x, float y, float z)
{
	pMC->AddTestRawData(nodeid, x, y, z);
}

GLOVELIBDLLCPP_API void mc_TestEllipsoidFit(MotionCapture* pMC, int nodeid)
{
	pMC->TestEllipsoidFit(nodeid);
}


GLOVELIBDLLCPP_API void mc_GetNodeRawQuat(MotionCapture* pMC, int nodeid, float* floatQ)
{
	pMC->GetNodeRawQuat(nodeid, floatQ);
}

// register call back functions
GLOVELIBDLLCPP_API void  mc_registerHandShakeCB(MotionCapture* pMC, HandShakeCB_T func)
{
	pMC->registerHandShakeCB(func);
}

GLOVELIBDLLCPP_API void  mc_registerSerialPortWriteCB(MotionCapture* pMC, WriteCB_T func)
{
	pMC->registerWriteCB(func);
}

GLOVELIBDLLCPP_API void  mc_registerRawDataReceivedCB(MotionCapture* pMC, RawDataReceivedCB_T func)
{
	pMC->registerRawDataReceivedCB(func);
}
GLOVELIBDLLCPP_API void mc_sendHandShake(MotionCapture* pMC)
{
	pMC->sendHandShake();
}

GLOVELIBDLLCPP_API void mc_sendRaw(MotionCapture* pMC, unsigned int nodeid, bool isSend)
{
	pMC->sendRaw(nodeid, isSend);
}

GLOVELIBDLLCPP_API void mc_startCali(MotionCapture* pMC)
{
	pMC->startCali();
}

GLOVELIBDLLCPP_API void mc_stopCali(MotionCapture* pMC)
{
	pMC->stopCali();
}