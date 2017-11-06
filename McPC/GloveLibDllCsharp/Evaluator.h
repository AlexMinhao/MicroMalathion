#pragma once

#include "Helper.h"


class Evaluator
{
public:
	void setMove(Vector3f begin, Vector3f end);
	float CalKneeAngleFromQ(Quaternionf thigh, BoneType thighBone, Quaternionf calf, BoneType calfBone);
	void matchEval(Vector3f sample, float* pAngleDeviation, float* pRate);
	void matchEval(Quaternionf sample, float* pAngleDeviation, float* pRate);

private:
	Vector3f _begin;
	Vector3f _end;
};
