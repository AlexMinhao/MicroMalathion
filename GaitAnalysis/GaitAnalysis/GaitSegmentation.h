#pragma once
#include "stdafx.h"
#include<stdio.h>  
#include <vector>
#include <map>
#include <string> 
#include <cstring>
#include <iostream>
using namespace std;


#define Size 30;
class GaitSegmentation
{
public:
	GaitSegmentation();
	~GaitSegmentation();
public:
	
	void Extreme(vector<double> &raw);
	double* getMaxNode()
	{
		return MaxNode;
	}
	int* getIndex()
	{
		return Index;
	}
	int getCount()
	{
		return count;
	}
private:
	double *MaxNode;
	int *Index;
	int count;
};

