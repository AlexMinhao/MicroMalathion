#include "stdafx.h"
#include "fir.h"


fir::fir()
{
}


fir::~fir()
{
}

void fir::firFloatInit(void)
{
	memset(insamp, 0, sizeof(insamp));
}
void fir::intToFloat(int16_t *input, double *output, int length)
{
	int i;

	for (i = 0; i < length; i++) {
		output[i] = (double)input[i];
	}
}
void fir::floatToInt(double *input, int16_t *output, int length)
{
	int i;

	for (i = 0; i < length; i++) {
		if (input[i]>32767.0) {

			input[i] = 32767.0;
		}
		else if (input[i] < -32768.0) {
			input[i] = -32768.0;
		}
		// convert
		output[i] = (int16_t)input[i];
	}
}
void fir::firFloat(double *coeffs, double *input, double *output,
	int length, int filterLength)   //80  63
{
	double acc;     // accumulator for MACs
	double *coeffp; // pointer to coefficients
	double *inputp; // pointer to input samples
	int n;
	int k;

	// put the new samples at the high end of the buffer
	memcpy(&insamp[filterLength - 1], input,
		length * sizeof(double));

	// apply the filter to each input sample
	for (n = 0; n < length/*80*/; n++) {
		// calculate output n
		coeffp = coeffs;
		inputp = &insamp[filterLength - 1 + n];
		acc = 0;
		for (k = 0; k < filterLength; k++) {
			acc += (*coeffp++) * (*inputp--);
		}
		output[n] = acc;
	}
	// shift input samples back in time for next time
	memmove(&insamp[0], &insamp[length],
		(filterLength - 1) * sizeof(double));// copy the rest 62 old samples from 80th to the new begin

}
