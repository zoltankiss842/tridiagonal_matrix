# Tridiagonal matrix algorithm

Solves tridiagonal systems of equations, by using the Thomas algorithm.  
## What is a tridiagonal matrix?

In [linear algebra](https://en.wikipedia.org/wiki/Linear_algebra "Linear algebra"), a _tridiagonal matrix_ is a [band matrix](https://en.wikipedia.org/wiki/Band_matrix "Band matrix") that has nonzero elements on the [main diagonal](https://en.wikipedia.org/wiki/Main_diagonal "Main diagonal"), the first diagonal below this, and the first diagonal above the main diagonal only.  \[[1]([https://en.wikipedia.org/wiki/Tridiagonal_matrix](https://en.wikipedia.org/wiki/Tridiagonal_matrix))\]
For example, the following matrix is tridiagonal:

![{\begin{pmatrix}1&4&0&0\\3&4&1&0\\0&2&3&4\\0&0&1&3\\\end{pmatrix}}.](https://wikimedia.org/api/rest_v1/media/math/render/svg/353a4862130008599653ed68ed0e2ae49cc2c455)  

## Tridiagonal matrix algorithm  

In  [numerical linear algebra](https://en.wikipedia.org/wiki/Numerical_linear_algebra "Numerical linear algebra"), the  **tridiagonal matrix algorithm**, also known as the  **Thomas algorithm**, is a simplified form of  [Gaussian elimination](https://en.wikipedia.org/wiki/Gaussian_elimination "Gaussian elimination")  that can be used to solve  [tridiagonal systems of equations](https://en.wikipedia.org/wiki/Tridiagonal_matrix). A tridiagonal system for  _n_  unknowns may be written as

![a_{i}x_{i-1}+b_{i}x_{i}+c_{i}x_{i+1}=d_{i},\,\!](https://wikimedia.org/api/rest_v1/media/math/render/svg/2960afa763dced3c58f7ebd67c60b7a9efdc1e1d)
where ![a_{1}=0\,](https://wikimedia.org/api/rest_v1/media/math/render/svg/aebbedb9930c85592194b452369f51249f307871)  ,   ![c_{n}=0\,](https://wikimedia.org/api/rest_v1/media/math/render/svg/f65f76a2897d21124e5471dad54b1af0ded54eee) 

![{\begin{bmatrix}{b_{1}}&{c_{1}}&{}&{}&{0}\\{a_{2}}&{b_{2}}&{c_{2}}&{}&{}\\{}&{a_{3}}&{b_{3}}&\ddots &{}\\{}&{}&\ddots &\ddots &{c_{n-1}}\\{0}&{}&{}&{a_{n}}&{b_{n}}\\\end{bmatrix}}{\begin{bmatrix}{x_{1}}\\{x_{2}}\\{x_{3}}\\\vdots \\{x_{n}}\\\end{bmatrix}}={\begin{bmatrix}{d_{1}}\\{d_{2}}\\{d_{3}}\\\vdots \\{d_{n}}\\\end{bmatrix}}.](https://wikimedia.org/api/rest_v1/media/math/render/svg/66abee37b2bc74f82fb79e7e1f0b5475be9f9632)    

Thomas' algorithm is not stable in general, but is so in several special cases, such as when the matrix is [diagonally dominant](https://en.wikipedia.org/wiki/Diagonally_dominant "Diagonally dominant") (either by rows or columns) or [symmetric positive definite.](https://en.wikipedia.org/wiki/Symmetric_positive_definite "Symmetric positive definite")  \[[2]([https://en.wikipedia.org/wiki/Tridiagonal_matrix](https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm))\]

## Thomas algorithm  

Upper diagonal:  ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20c_%7Bi%7D%5C%3B%20where%5C%3B%20i%3D1%2C2%2C...%2C%20n-1)  
Lower diagonal:      ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20a_%7Bi%7D%5C%3B%20where%5C%3B%20i%3D2%2C...%2C%20n)  
Main diagonal:        ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20b_%7Bi%7D%5C%3B%20where%5C%3B%20i%3D1%2C2%2C...%2C%20n)
Solutions: ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20d_%7Bi%7D%5C%3B%20where%5C%3B%20i%3D1%2C2%2C...%2C%20n)  

The algorithm based on 4 steps:
### Step 1  
![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20c_%7B1%7D%3D%5Cfrac%7Bc_%7B1%7D%7D%7Bb_%7B1%7D%7D)  
![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20d_%7B1%7D%3D%5Cfrac%7Bd_%7B1%7D%7D%7Bb_%7B1%7D%7D)  
### Step 2  

![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20c_%7Bi%7D%3D%5Cfrac%7Bc_%7Bi%7D%7D%7Bb_%7Bi%7D-a_%7Bi%7Dc%27_%7Bi-1%7D%7D%5C%3Bwhere%5C%3Bi%3D2%2C3%2C...%2Cn-1)  
![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20d_%7Bi%7D%3D%5Cfrac%7Bd_%7Bi%7D-a_%7Bi%7Dd%27_%7Bi-1%7D%7D%7Bb_%7Bi%7D-a_%7Bi%7Dc%27_%7Bi-1%7D%7D%5C%3Bwhere%5C%3Bi%3D2%2C3%2C...%2Cn-1)  
### Step 3  
![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20d_%7Bn%7D%3D%5Cfrac%7Bd_%7Bn%7D-a_%7Bn%7Dd%27_%7Bn-1%7D%7D%7Bb_%7Bn%7D-a_%7Bn%7Dc%27_%7Bn-1%7D%7D)  
### Step 4
Back substitution:

![x_{n}=d'_{n}\,](https://wikimedia.org/api/rest_v1/media/math/render/svg/84a7e8d826e44338542d03bfa731c9bf577e9932)
![x_{i}=d'_{i}-c'_{i}x_{i+1}\qquad ;\ i=n-1,n-2,\ldots ,1.](https://wikimedia.org/api/rest_v1/media/math/render/svg/da4f4998d57395323d8ea72277cbf64b125be465)  
After these steps we get the  values for the ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20x) variables.  

## Working through the code  
    ...
    
    #define NxN 4
        
    int main()
        {
        	double myMatrix[][NxN] = { 
        		{1,-8,0,0}, 
				{2,-2,-7,0},
				{0,7,3,-6},
				{0,0,8,-7}       	
			};
        
        	double dnValues[NxN] = { 
        		3,5,6,1
        	};
       ...

`NxN` is a constant representing the size of the square matrix.
This is where the program takes the input matrix and the ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20d_%7Bn%7D) values.  

    ...
    
    isMatrixCorrect(&myMatrix[0][0], NxN);
    
    ...

This method checks, if the matrix is stable for the Thomas algorithm. It has to be diagonally dominant or symmetric positive definite. However, a solution will be presented, but probably not correct.

	double* ciValues;
	double* aiValues;
	double* biValues;
	double* diValues;
	double* xValues;

These arrays storing the representative values of the matrix. The output will be stored in the `xValues`.  

## Test cases  

 #### Input 1 
 ![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20%5Cbegin%7Bbmatrix%7D%205x_%7B1%7D%20%5Cend%7Bbmatrix%7D%3D%20%5Cbegin%7Bbmatrix%7D%203%20%5Cend%7Bbmatrix%7D)
   ```
   #define NxN 1;
   
   int main(){
		double myMatrix[][NxN] = { 
			{5}
		};
	
		double dnValues[NxN] = { 
			3
		};
   ```
   #### Output 1:  
	    Matrix looking good.
		Solution:
		X1: 1.67
#### Input 2
![](https://latex.codecogs.com/gif.latex?%5Cdpi%7B120%7D%20%5Cbegin%7Bbmatrix%7D%204x_%7B1%7D%20%26%200x_%7B2%7D%5C%5C%200x_%7B1%7D%20%26%2011x_%7B2%7D%20%5Cend%7Bbmatrix%7D%20%3D%20%5Cbegin%7Bbmatrix%7D%205%5C%5C%203%20%5Cend%7Bbmatrix%7D)
   ```
   #define NxN 2;
   
   int main(){
		double myMatrix[][NxN] = { 
			{4,0},
			{0,11}
		};
	
		double dnValues[NxN] = { 
			5,3
		};
   ```
   #### Output 2:  
	    Matrix looking good.
		Solution:
		X1: 0.80 X2: 3.67
#### Input 3
![](https://www.latex4technics.com/l4ttemp/mntpw1.png?1576060700355)
   ```
   #define NxN 9;
   
   int main(){
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
   ```
   #### Output 3:  
	    Matrix is not diagonally dominant and not symmetric positive definite
		The Thomas algortihm is not stable on such matrices.
		Solution:
		X1: -6.44 X2: 3.97 X3: -0.90 X4: -0.39 X5: 3.84 X6: -0.14 X7: -3.63 X8: 2.06 X9: -0.07

## References  
[1] : https://en.wikipedia.org/wiki/Tridiagonal_matrix  
[2] : https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm  

Huge thanks to:
Ally Learn ([Youtube channel](https://www.youtube.com/channel/UCNweNoqZgtcYmlczDHV36Gw))
