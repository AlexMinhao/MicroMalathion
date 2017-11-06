// GloveLibDllCsharp.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "Definitions.h"
#include "DataWarehouse.h"
#include "MotionCapture.h"
#include "GloveLibDllCsharp.h"

GLOVELIBDLLCSHARP_API MotionCapture* __stdcall mc_newInstance()
{
	MotionCapture* inst = new MotionCapture();
	return inst;
}

GLOVELIBDLLCSHARP_API void __stdcall mc_setModel(MotionCapture* pMC, HWV_T hwVer, SkeletonType m)
{
	pMC->setModel(hwVer, m);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_onDataReceived(MotionCapture* pMC, unsigned char* pbuf, int lbuf)
{
	pMC->onDataReceived(pbuf, lbuf);
}


GLOVELIBDLLCSHARP_API void __stdcall mc_reset(MotionCapture* pMC)
{
	pMC->reset();
}


GLOVELIBDLLCSHARP_API void __stdcall mc_GetCurrentAngle(MotionCapture* pMC, double* outbuf, int buflen)
{
	pMC->GetCurrentAngle(outbuf, buflen);
}


//Gesture mc_GetCurrentGesture(MotionCapture* pMC, ); TODO
GLOVELIBDLLCSHARP_API void __stdcall mc_AddTestData(MotionCapture* pMC)// only for test purpose, stub data
{
	pMC->AddTestData();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_UpdateJoints(MotionCapture* pMC, UnityModelType umType)
{
	pMC->UpdateJoints(umType);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_SetInitQ(MotionCapture* pMC)
{
	pMC->SetInitQ();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_GetQuat(MotionCapture* pMC, BoneType joint, float* floatQ) // float[w,x,y,z]
{
	return pMC->GetQuat(joint, floatQ);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_GetQuatU(MotionCapture* pMC, BoneType joint, float* floatQ) // float[w,x,y,z]
{
	return pMC->GetQuatU(joint, floatQ);
}

GLOVELIBDLLCSHARP_API bool __stdcall mc_jointValid(MotionCapture* pMC, BoneType bone)
{
	return pMC->jointValid(bone);
}


GLOVELIBDLLCSHARP_API void __stdcall mc_GetSensorJointUnion(MotionCapture* pMC, float* sju) //test function, to be deleted
{
	pMC->GetSensorJointUnion(sju);
}


GLOVELIBDLLCSHARP_API void __stdcall mc_AddTestRawData(MotionCapture* pMC, int nodeid, float x, float y, float z)
{
	pMC->AddTestRawData(nodeid, x, y, z);
}


GLOVELIBDLLCSHARP_API void __stdcall mc_TestEllipsoidFit(MotionCapture* pMC, int nodeid)
{
	pMC->TestEllipsoidFit(nodeid);
}


GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeRawQuat(MotionCapture* pMC, int nodeid, float* floatQ)
{
	pMC->GetNodeRawQuat(nodeid, floatQ);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeQuat(MotionCapture* pMC, int nodeid, float* floatQ)
{
	pMC->GetNodeQuat(nodeid, floatQ);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_GetNodeRawData(MotionCapture* pMC, int nodeid, float* pFloat)
{
	pMC->GetNodeRawData(nodeid, pFloat);
}

// register call back functions
GLOVELIBDLLCSHARP_API void __stdcall mc_registerHandShakeCB(MotionCapture* pMC, HandShakeCB_T func)
{
	pMC->registerHandShakeCB(func);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_registerHwSysInfoCB(MotionCapture* pMC, HwSysInfoCB_T func)
{
	pMC->registerHwSysInfoCB(func);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_registerSerialPortWriteCB(MotionCapture* pMC, WriteCB_T func)
{
	pMC->registerWriteCB(func);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_registerRawDataReceivedCB(MotionCapture* pMC, RawDataReceivedCB_T func)
{
	pMC->registerRawDataReceivedCB(func);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_sendHandShake(MotionCapture* pMC)
{
	pMC->sendHandShake();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_sendRaw(MotionCapture* pMC, unsigned int nodeid, bool isSend)
{
	pMC->sendRaw(nodeid, isSend);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_startCali(MotionCapture* pMC)
{
	pMC->startCali();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_stopCali(MotionCapture* pMC)
{
	pMC->stopCali();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_getHwSysInfo(MotionCapture* pMC)
{
	pMC->getHwSysInfo();
}

GLOVELIBDLLCSHARP_API BoneType __stdcall mc_boneByID(MotionCapture* pMC, int id)
{
	return pMC->boneByID(id);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_clearMoveGroup(MotionCapture* pMC)
{
	pMC->clearMoveGroup();
}

GLOVELIBDLLCSHARP_API void __stdcall mc_addSingleBoneMove(MotionCapture* pMC, BoneType bone,
	float beginw, float beginx, float beginy, float beginz, 
	float endw, float endx, float endy, float endz, 
	float interval)
{
	pMC->addSingleBoneMove(bone, 
		beginw, beginx, beginy, beginz, 
		endw, endx, endy, endz,
		interval);
}

GLOVELIBDLLCSHARP_API void __stdcall mc_getMatchScore(MotionCapture* pMC, BoneType bone, float * pCompletionRate, float* pAngleDeviation)
{
	pMC->getMatchScore(bone, pCompletionRate, pAngleDeviation);
}

GLOVELIBDLLCSHARP_API float __stdcall mc_angleBetween2Bones(MotionCapture* pMC, BoneType bone1, BoneType bone2)
{
	return pMC->angleBetween2Bones(bone1, bone2);
}