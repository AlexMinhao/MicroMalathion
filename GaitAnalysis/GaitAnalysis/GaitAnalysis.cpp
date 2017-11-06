// GaitAnalysis.cpp : �������̨Ӧ�ó������ڵ㡣
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
	vector<vector <string> > Context;    //�ļ�����
	string line, field;    //lineΪÿ�����ݣ�fieldΪÿ���ֶ�
						   //���ļ�
	ifstream in;
	in.open("D:/Working/MicroMa/MicroMalathion/GaitAnalysis/raw_gyo.csv");    //�Զ��Ÿ���
	ofstream out;
	out.open("D:/Working/MicroMa/MicroMalathion/GaitAnalysis/signal_filtered.csv");
	//��һ�еĶ���ֶ�ȡ��			   //�����ļ�����
	if (in.is_open())
	{
		//ѭ��ȡ��ÿһ������
		vector<string> Buffer;
		vector<string> RowContext;
		while (getline(in, line))
		{
			istringstream stream(line);
			//�ԡ�,����ȡÿ���ֶ�
			while (getline(stream, field, ','))
			{
				//����
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
		//�ļ���ʧ��
		cout << "���ļ�ʧ�ܣ�";
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
		
			out << filterdata[i];
			out << ",";
			
			cout << filterdata[i] << endl;
			

	}
	

	/*
	GaitSegmentation gait;
	
	gait.Extreme(rawd);
	double *node = gait.getMaxNode();
	int *ind = gait.getIndex();
	int length = gait.getCount();
	for (int i = 0; i < length; i++)
	{
		std::cout <<node[i]<<"***"<<ind[i] << std::endl;
	}
	
	
	*/

	
	getchar();
	
    return 0;
}

