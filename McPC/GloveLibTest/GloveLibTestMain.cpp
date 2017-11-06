// TestMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#include "GloveLibDllCpp.h"

template<typename M>
M load_csv(const std::string & path) {
	std::ifstream indata;
	indata.open(path);
	std::string line;
	std::vector<float> values;
	int rows = 0;
	while (std::getline(indata, line)) {
		std::stringstream lineStream(line);
		std::string cell;
		while (std::getline(lineStream, cell, ',')) {
			values.push_back(std::stof(cell));
		}
		++rows;
	}
	return Map<const Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, RowMajor>>(values.data(), rows, values.size() / rows);
}

int main()
{
	MotionCapture* pMC = (MotionCapture*)mc_newInstance(HWv3Right, RightHand);
	// part 0, try EllipsoidFit algo
	MatrixXf A = load_csv<MatrixXf>("../TestData/RawMagforEllipsoidFit_1000rows.txt");
	cout << "matrix rows " << A.rows() << ", matrix columns " << A.cols() << endl;
	Matrix<float, Dynamic, 3> m = A;
	for (int i = 0; i < m.rows(); i++) {
		mc_AddTestRawData(pMC, 0, m(i, 0), m(i, 1), m(i, 2));
	}
	mc_TestEllipsoidFit(pMC, 0);

	// part 1, test byte stream to quaternion
	string filepath = "../TestData/btbytes.bin";
	cout << filepath << endl;

	FILE *file = NULL;
	unsigned char buffer[1024 * 8];  // array of bytes, not pointers-to-bytes
	size_t bytesRead = 0;

	fopen_s(&file, filepath.c_str(), "rb");

	if (file != NULL)
	{
		// read up to sizeof(buffer) bytes
		while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
		{
			// process bytesRead worth of data in buffer
			cout << bytesRead << " bytes read" << endl;
			mc_onDataReceived(pMC, buffer, bytesRead);
		}
		float sju[BoneAmount];
		mc_GetSensorJointUnion(pMC, sju);
	}

	// part 2, output test data for Cecilia

	for (int n = 0; n < 102; n++) {
		//mc.AddTestData();
		mc_AddTestData(pMC);
		for (enum BoneType i = Palm; i < BoneAmount; i = (enum BoneType(i+1)) )
		{
			// Right hand only for now!! left hand will return nothing
			// float* qarr = mc.GetQuat(Right, (SensorJointType)i);
			if (mc_jointValid(pMC, i))
			{
				float qarr[4];
				mc_GetQuat(pMC, i, qarr);
				cout << "joint" << i << ", w = " << qarr[0] << ", x = " << qarr[1] << ", y = " << qarr[2] << ", z = " << qarr[3] << endl;
			}
		}
	}
	
	return 0;
}

