// GaitAnalysis.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "fir.h"
#include <vector>  
#include <fstream>
#include <sstream>
#include<iostream> 
#include <string> 
#include <cstring>
#include <cstdlib>
#include "GaitSegmentation.h"

using namespace std;
#define SAMPLES 100
int main()
{

	fir flter;
	vector<double> rawd;
	vector<vector <string> > Context;    //文件内容
	string line, field;    //line为每行内容，field为每个字段
						   //打开文件
	ifstream in;
	in.open("C:/ALEX/Doc/学习/GaitAnalysis/filtered_gyo.csv");    //以逗号隔开
	ofstream out;
	out.open("C:/ALEX/Doc/学习/GaitAnalysis/signal_filtered.csv");
	//将一行的多个字段取出			   //处理文件内容
	if (in.is_open())
	{
		//循环取出每一行数据
		vector<string> Buffer;
		vector<string> RowContext;
		while (getline(in, line))
		{
			istringstream stream(line);
			//以‘,’读取每个字段
			while (getline(stream, field, ','))
			{
				//存入
				RowContext.push_back(field);
			}
		}
		//cout << RowContext.size();
		for (int i = 0; i < RowContext.size() / SAMPLES; i++)
		{
			for (int j = 0; j < SAMPLES-1; j++)
			{
				Buffer.push_back(RowContext[SAMPLES * i + j]);
			}
			Context.push_back(Buffer);
			
		}
		for (int i = 0; i < RowContext.size(); i++)
		{
			rawd.push_back(atof(RowContext[i].c_str()));
		}
		cout << rawd.size() << "\t\n";
	}
	else
	{
		//文件打开失败
		cout << "打开文件失败！";
	}

	

	vector<double> filterdata;

	int size;
	double* input;
	double output[SAMPLES] = {0};
	double inputBuffer[SAMPLES] = {0};
	for (int i = 0; i<Context.size(); i++)
	{
		for (int j = 0; j < SAMPLES-1; j++)
		{
			inputBuffer[j] = atof(Context[i][j].c_str());
		}
		flter.firFloat(flter.coeffs, inputBuffer, output, SAMPLES, FILTER_LEN);
		for (int i = 0; i < SAMPLES; i++)
		{
			filterdata.push_back(output[i]);
		}
		//cout << filterdata.size()<< "\t\n";
	}

	if (!out.is_open())
	{
		cout << " could not open " << endl;
		return false;
	}

	for (int i = 0; i<filterdata.size(); i++)
	{
		
		//	out << filterdata[i];
		//	out << ",";
			
			//	cout << filterdata[i] << endl;
			

	}
	

	double array[30] = {0,
		-0.021,
		0.062,
		-0.041,
		0.012,
		-0.061,
		0.072,
		-0.053,
		0.0221,
		-0.0612,
		0.0632,
		-0.0123,
		0.0543,
		-0.0212,
		0.0623,
		-0.0443,
		0.0112,
		-0.0614,
		0.0723,
		-0.0545,
		0.0212,
		-0.0634,
		0.06245,
		-0.01235,
		0.052345,
		-0.02112,
		0.06221,
		-0.041134,
		0.011123,
		-0.06432,
		 };

	for (int i=0; i < 30; i++)
	{
		//rawd.push_back(array[i]);
	}
	GaitSegmentation gait;
	
	gait.Extreme(rawd);
	double *node = gait.getMaxNode();
	int *ind = gait.getIndex();
	int length = gait.getCount();
	for (int i = 0; i < length; i++)
	{
		std::cout <<node[i]<<"***"<<ind[i] << std::endl;
	}
	
	getchar();
	
    return 0;
}

