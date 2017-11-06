#pragma once

#include <stdio.h>
#include <stdint.h>
//////////////////////////////////////////////////////////////
//  Filter Code Definitions
//////////////////////////////////////////////////////////////

// maximum number of inputs that can be handled
// in one function call
#define MAX_INPUT_LEN   100
// maximum length of filter than can be handled
#define MAX_FLT_LEN     101
// buffer to hold all of the input samples
#define FILTER_LEN  101
#define BUFFER_LEN      (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)  //63-1+80  142


class fir
{
public:
	fir();
	~fir();

	void firFloatInit(void);
	void intToFloat(int16_t *input, double *output, int length);
	void floatToInt(double *input, int16_t *output, int length);
	void firFloat(double *coeffs, double *input, double *output,
		int length, int filterLength);

	double insamp[BUFFER_LEN];
	/*
	double coeffs[FILTER_LEN] =
	{
		0.009140502661,-1.465269557e-17,-0.009847287089,-0.006326611154, 0.006584285293,
		0.01110123377,-1.491541144e-17, -0.01210396085,-0.007829490118, 0.008209018037,
		0.01395331882,-1.51321096e-17,  -0.0155011043, -0.01013632864,  0.01075653452,
		0.0185310822,-1.530174615e-17,  -0.0212592613, -0.01417389326,  0.01537940465,
		0.02718619816,-1.542350217e-17, -0.03331179172, -0.02318620495,  0.02652365156,
		0.05010999739,-1.549679202e-17, -0.07525996864, -0.06204502657,  0.09309690446,
		0.3013249338,   0.3981676996,   0.3013249338,  0.09309690446, -0.06204502657,
		-0.07525996864,-1.549679202e-17,  0.05010999739,  0.02652365156, -0.02318620495,
		-0.03331179172,-1.542350217e-17,  0.02718619816,  0.01537940465, -0.01417389326,
		-0.0212592613,-1.530174615e-17,   0.0185310822,  0.01075653452, -0.01013632864,
		-0.0155011043,-1.51321096e-17,  0.01395331882, 0.008209018037,-0.007829490118,
		-0.01210396085,-1.491541144e-17,  0.01110123377, 0.006584285293,-0.006326611154,
		-0.009847287089,-1.465269557e-17, 0.009140502661
	};
	
	
	double coeffs[FILTER_LEN] =
	{
		-0.01983720243785, -0.02037705591269, -0.01880682903705, -0.01490480599156,
		-0.008602371275295,3.771666551045e-18,  0.01062949486552,   0.0228512552029,
		0.03609187623698,  0.04967464392674,  0.06286401160975,  0.07491597786016,
		0.08513046175466,  0.09290153323473,  0.09776147063488,  0.09941507865626,
		0.09776147063488,  0.09290153323473,  0.08513046175466,  0.07491597786016,
		0.06286401160975,  0.04967464392674,  0.03609187623698,   0.0228512552029,
		0.01062949486552,3.771666551045e-18,-0.008602371275295, -0.01490480599156,
		-0.01880682903705, -0.02037705591269, -0.01983720243785
	};
	*/

	double coeffs[FILTER_LEN] =
	{ 
		0.0000,    0.0002,    0.0003 ,   0.0005,    0.0006   , 0.0007 ,   0.0008 ,   0.0007  ,  0.0006 ,   0.0004, -0.0000,
		-0.0005, - 0.0010, - 0.0016, - 0.0021, - 0.0024, -0.0026, - 0.0025, - 0.0020, - 0.0012 ,   0.0000,    0.0014,
		0.0030  ,  0.0046  ,  0.0059 ,   0.0069  ,  0.0072 ,   0.0067 ,   0.0053   , 0.0031 ,- 0.0000, - 0.0037, - 0.0076,
		- 0.0115 ,- 0.0148, - 0.0172 ,- 0.0180, - 0.0169, - 0.0136, - 0.0080 ,   0.0000 ,   0.0101 ,   0.0220 ,   0.0351,
		0.0487  ,  0.0621 ,   0.0744  ,  0.0849 ,   0.0930 ,   0.0980   , 0.0998 ,   0.0980  ,  0.0930  ,  0.0849  ,  0.0744,
		0.0621  ,  0.0487 ,   0.0351 ,   0.0220  ,  0.0101  ,  0.0000 ,- 0.0080, - 0.0136, - 0.0169 ,- 0.0180, - 0.0172,
		- 0.0148, - 0.0115, - 0.0076 ,- 0.0037 ,- 0.0000  ,  0.0031,    0.0053,    0.0067 ,   0.0072 ,   0.0069  ,  0.0059,
		0.0046  ,  0.0030  ,  0.0014 ,   0.0000 ,- 0.0012 ,- 0.0020, - 0.0025 ,- 0.0026 ,- 0.0024 ,- 0.0021 ,- 0.0016,
		- 0.0010, - 0.0005, - 0.0000 ,   0.0004 ,   0.0006   , 0.0007 ,   0.0008 ,   0.0007 ,   0.0006  ,  0.0005 ,   0.0003,
		0.0002,    0.0000
	};
};

