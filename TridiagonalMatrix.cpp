#include <iostream>
#include <stdlib.h>
#include <vector>
#include "checker.h"
#include "thomas_alg.h"

#define NxN 9 //This must be modified according to the size of the input matrix.

int main()
{
	//Do not forget to modify NxN as well
	double myMatrix[][NxN] = { 
		{1.6, 7.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{7.1, 14.7, 6.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 6.4, 10.2, 19.3, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 19.3, 14.3, 10.7, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 10.7, 4.3, 18.9, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 18.9, 8.7, 19.1, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 19.1, 1.1, 6.7, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.7, 15.8, 3.9},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.9, 8.3},
	};

	double dnValues[NxN] = { 
		17.9, 6.9, 8.8, 18.2, 9.7, 2.0, 7.1, 8.0, 7.5
	};


	isMatrixCorrect(&myMatrix[0][0], NxN);

	double* ciValues;
	double* aiValues;
	double* biValues;
	double* diValues;
	double* xValues;

	ciValues = (double*)calloc(NxN, sizeof(double));
	aiValues = (double*)calloc(NxN, sizeof(double));
	biValues = (double*)calloc(NxN, sizeof(double));
	diValues = (double*)calloc(NxN, sizeof(double));
	xValues = (double*)calloc(NxN, sizeof(double));

	getValues(&myMatrix[0][0], &dnValues[0], &ciValues[0], &aiValues[0], &biValues[0], &diValues[0], NxN);

	if (NxN == 1) {
		xValues[0] = biValues[0] / diValues[0];
	}
	else if (NxN == 2) {
		xValues[0] = biValues[0] / diValues[0];
		xValues[1] = biValues[1] / diValues[1];
	}
	else {
		step1(ciValues, diValues, biValues);

		step2(ciValues, aiValues, diValues, biValues, NxN);

		step3(ciValues, aiValues, diValues, biValues, NxN);

		back_substitution(xValues, ciValues, diValues, NxN);
	}

	printf("Solution:\n");
	printValuesX(xValues, NxN);

	free(ciValues);
	free(aiValues);
	free(biValues);
	free(diValues);
	free(xValues);

	return 0;
}
