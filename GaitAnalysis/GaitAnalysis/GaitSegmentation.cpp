#include "stdafx.h"
#include "GaitSegmentation.h"


GaitSegmentation::GaitSegmentation()
{
}


GaitSegmentation::~GaitSegmentation()
{
}

/*
* ����:  findPeaks
* ����:  *src        Դ��������
*          src_lenth   Դ�������鳤��
*          distance    �����,����ȵ��������
*          *indMax     �ҵ��ķ��index����
*          *indMax_len ���鳤��
*          *indMin     �ҵ��Ĺȵ�index����
*          *indMin_len ���鳤��
*/
void GaitSegmentation::Extreme(vector<double> &raw)
{
	double length = raw.size();
	int *sign = (int*)malloc(length * sizeof(int));  // store the diff sign
	int max_index = 0,
		min_index = 0;
	int *indMax = (int*)malloc(length * sizeof(int));
	int *indMax_len = (int*)malloc(length * sizeof(int));
	int *indMin = (int*)malloc(length * sizeof(int));
	int *indMin_len = (int*)malloc(length * sizeof(int));
	MaxNode = new double[length]; Index = new int[length];
	
	for (int i = 1; i<length; i++)                  //��������-1�� ������ +1
	{
		double diff = raw[i] - raw[i - 1];
		if (diff>0)          sign[i - 1] = 1;
		else if (diff<0) sign[i - 1] = -1;
		else                sign[i - 1] = 0;  
	}
	for (int j = 1; j<length - 1; j++)            //��ֵ
	{        
		double diff = sign[j] - sign[j - 1];
		if (diff<0)      indMax[max_index++] = j;   //index of ����ֵ
		else if (diff>0) indMin[min_index++] = j;    //index of ��Сֵ
	}

	vector<double> Max(length,0),Min(length,0),vmax,vmin;   //location
	for (int j=0; j < max_index; j++)
	{
		if (int i = indMax[j]) {
			Max[i] = 1;
		}
	}
	//for (int j = 0; j < max_index; j++)
//	{

	//	if (int i = indMin[j]) {
	//		Min[i] = -1;
	//	}
	//}
	//for (int i=0; i < max_index; i++)
//	{
	//	vmax.push_back(raw[indMax[i]]);
	//}

	//for (int i = 0; i < 30; i++)
	//{
	//	std::cout << Max[i] << std::endl;
	//}
	std::cout << "stop" << std::endl;
	
	//vector<double> Vmax(30,0);

	//map<double, int> Vmax; map<double,int>::iterator l_it;;
	//for (int i = 0; i < max_index; i++)
	//{
	//	std::cout << vmax[i]<<"***"<<indMax[i] << std::endl;
		//Vmax[indMax[i]] = vmax[i];
		//Vmax.insert(pair<double, int>(vmax[i],indMax[i]));
		//std::cout << Vmax.size() << std::endl;
	//}
	
		
	/***************second sign******************/

	
	int *sign2 = (int*)malloc(vmax.size() * sizeof(int));
	

	for (int i = 1; i<max_index; i++)            //��ֵ
	{
		
		double diff = raw[indMax[i]] - raw[indMax[i-1]];
		if (diff>0)          sign2[i - 1] = 1;
		else if (diff < 0)
		{
			sign2[i - 1] = -1;
			//Vmax.insert(pair<double, int>(raw[indMax[i-1]], indMax[i-1]));
			MaxNode[count] = raw[indMax[i - 1]];
			Index[count] = indMax[i-1]+1;
			count++;
		}

		else                 sign2[i - 1] = 0;
		
	}

	

	
	/*
	free(sign);
	free(flag_max_index);
	free(temp_max_index);
	free(idelete);
	*/
};