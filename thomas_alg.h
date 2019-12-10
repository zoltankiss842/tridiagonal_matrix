
/*
	https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm

	The algorithm itself consists of 4 steps.
	
	Step 1: as i = 1
		c1 = c1/b1
		d1 = d1/b1

	Step 2: as i = 2,3, ... n-1
		ci = ci/(bi-(ai*ci-1))
		di = (di-(ai*di-1))/(bi-(ai*ci-1))

	Step 3: as i = n
		dn = (dn-(an*dn-1))/(bn-(an*cn-1))

	Step 4: 
		Back substitution:
			i = n:
				xi = di
			i = n-1, n-2, ... 1:
				xi = di-(ci*xi+1)

	Then the solutions stored in xValues array.

*/


void getValues(double(*myMatrix_p), double(*dnValues_p), double(*ciValues), double(*aiValues), double(*biValues), double(*diValues), int size) {

	/*
		This function filters every value that is needed for the calculation
		It was easier for me to this than calculating every value at its place.
		However it increases memory.

		aiValues -> Lower diagonal values
		ciValues -> Upper diagonal values
		biValues -> Main diagonal values
		diValues -> Solution values
	*/

	//Filtering 'c' values
	double* temp_ptr = myMatrix_p;
	temp_ptr++;
	ciValues[size - 1] = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		ciValues[i] = *temp_ptr;
		temp_ptr += (size + 1);
	}

	//Filtering 'a' values
	temp_ptr = myMatrix_p;
	temp_ptr += size;
	aiValues[0] = 0;
	for (int i = 1; i < size; ++i)
	{
		aiValues[i] = *temp_ptr;
		temp_ptr += size + 1;
	}

	//Filtering 'b' values
	temp_ptr = myMatrix_p;
	for (int i = 0; i < size; ++i)
	{
		biValues[i] = *temp_ptr;
		temp_ptr += size + 1;
	}

	//Filtering 'd' values
	temp_ptr = dnValues_p;
	for (int i = 0; i < size; ++i)
	{
		diValues[i] = *temp_ptr;
		temp_ptr++;
	}
}

void printValues(double(*array_ptr), int size) {

	/*
		Prints out the values of an array, in 2 decimal places
	*/

	for (int i = 0; i < size; i++)
	{
		printf("%2.2lf ", array_ptr[i]);
	}
	printf("\n");
}


void printValuesM(double(*matrix_ptr), int size) {

	/*
		Prints out the values of a matrix, in 2 decimal places
	*/

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%2.2lf ", matrix_ptr[(i * size) + j]);
		}

		printf("\n");
	}
}

void step1(double(*ciValues), double(*diValues), double(*biValues)) {

	/*
		Step 1: as i = 1
			c1 = c1/b1
			d1 = d1/b1
	*/

	ciValues[0] = ciValues[0] / biValues[0];
	diValues[0] = diValues[0] / biValues[0];
}

void step2(double(*ciValues), double(*aiValues), double(*diValues), double(*biValues), int size) {

	/*
	Step 2: as i = 2,3, ... n-1
		ci = ci/(bi-(ai*ci-1))
		di = (di-(ai*di-1))/(bi-(ai*ci-1))
	*/

	for (int i = 1; i < size - 1; i++)
	{
		ciValues[i] = ciValues[i] / (biValues[i] - (aiValues[i] * ciValues[i - 1]));
		diValues[i] = (diValues[i] - (aiValues[i] * diValues[i - 1])) / (biValues[i] - (aiValues[i] * ciValues[i - 1]));
	}
}

void step3(double(*ciValues), double(*aiValues), double(*diValues), double(*biValues), int size) {

	/*
	Step 3: as i = n
		dn = (dn-(an*dn-1))/(bn-(an*cn-1))
	*/

	int flag = size - 1;
	diValues[flag] = (diValues[flag] - (aiValues[flag] * diValues[flag - 1])) / (biValues[flag] - (aiValues[flag] * ciValues[flag - 1]));
}

void back_substitution(double(*xValues), double(*ciValues), double(*diValues), int size) {

	/*
		Back substitution:
			i = n:
				xi = di
			i = n-1, n-2, ... 1:
				xi = di-(ci*xi+1)
	*/

	xValues[size - 1] = diValues[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		xValues[i] = diValues[i] - (ciValues[i] * xValues[i + 1]);
	}
}

