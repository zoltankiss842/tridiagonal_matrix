#include <iostream>
#include <stdlib.h>
#include <vector>
#include "checker.h"
#include "thomas_alg.h"

#define NxN 4 //This must be modified according to the size of the input matrix.

int main()
{
	//Do not forget to modify NxN as well
	double myMatrix[][NxN] = { 
		{1,-8,0,0}, 
		{2,-2,-7,0},
		{0,7,3,-6},
		{0,0,8,-7}
	};

	double dnValues[NxN] = { 
		3,5,6,1
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
	printValues(xValues, NxN);

	free(ciValues);
	free(aiValues);
	free(biValues);
	free(diValues);
	free(xValues);

	return 0;
}
