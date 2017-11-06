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
		3.533055487e-18, 0.001823896193,  0.00355011574, 0.005002109334, 0.006022091955,
		0.006487376522, 0.006324050948, 0.005516560748, 0.004112098832, 0.002219142392,
		-3.61299753e-18,-0.002342191525, -0.00458105281,-0.006487681065,-0.007852693088,
		-0.008507577702,-0.008343312889,-0.007324365899,-0.005496526603,-0.002987526357,
		3.675797082e-18, 0.003202970605, 0.006318811793, 0.009031360038,  0.01103964541,
		0.01208713744,  0.01198887173,  0.01065396611, 0.008101291955, 0.004466596525,
		-3.720989681e-18,-0.004946397152,-0.009940258227, -0.01449873671, -0.01812409982,
		-0.02034259029, -0.02074349858, -0.01901529171, -0.01497579552,-0.008593790233,
		3.748239906e-18,  0.01051372662,  0.02250736952,  0.03541715816,  0.04858991876,
		0.06132492051,  0.07292024791,  0.08272026479,  0.09016061574,  0.09480737895,
		0.09638738632,  0.09480737895,  0.09016061574,  0.08272026479,  0.07292024791,
		0.06132492051,  0.04858991876,  0.03541715816,  0.02250736952,  0.01051372662,
		3.748239906e-18,-0.008593790233, -0.01497579552, -0.01901529171, -0.02074349858,
		-0.02034259029, -0.01812409982, -0.01449873671,-0.009940258227,-0.004946397152,
		-3.720989681e-18, 0.004466596525, 0.008101291955,  0.01065396611,  0.01198887173,
		0.01208713744,  0.01103964541, 0.009031360038, 0.006318811793, 0.003202970605,
		3.675797082e-18,-0.002987526357,-0.005496526603,-0.007324365899,-0.008343312889,
		-0.008507577702,-0.007852693088,-0.006487681065, -0.00458105281,-0.002342191525,
		-3.61299753e-18, 0.002219142392, 0.004112098832, 0.005516560748, 0.006324050948,
		0.006487376522, 0.006022091955, 0.005002109334,  0.00355011574, 0.001823896193,
		3.533055487e-18
	};
};

