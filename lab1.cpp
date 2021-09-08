// 08.09.2021
// Aleksei Likhachev lab work
/*
The source code of the program is protected by copyright and does not 
belong for copying, distribution and use for personal and other 
purposes without indicating the original authorship and reference to 
the original work.
This program is distributed in the hope that 
it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <stdio.h>
#include <math.h>

#define number_of_solutions 5
#define M_PI 3.14159265358979323846

// Modulus calculation function
int mabs(int a){
	if(a >= 0){
		return a;
	} else {
		return -a;
	}
}

// N4
// Find the arithmetic mean and geometric mean of two numbers.
void n4(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("N4 arithmetic mean=%f\tgeometric mean=%f\n", (float)(a+b)/2, (float)(sqrt(a*b)));
}

// N5
// Find the arithmetic mean and geometric mean of the two moduli of these numbers.
void n5(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("N5 arithmetic mean=%f\tgeometric mean=%f\n", 
			(float)(mabs(a)+mabs(b))/2, (float)(sqrt(mabs(a)*mabs(b))));
}

// N11(a)
// Calculate the value of
void n11(){
	// Let x, y, z - float
	float x, y, z;
	float a, b;
	scanf("%f %f %f", &x, &y, &z);
	a = (sqrt(mabs(x-1)) - pow(mabs(y), 0.33333))/(1 + ((pow(x, 2)/2) + (pow(y, 2)/4)));
	b = x*(atan(z) + exp(x-3));
	printf("N11(a) a = %f\t b = %f\n", a, b);
}

// N17(a)
void n17(){
	int r_inner = 20;
	float r_outer;
	scanf("%f\n", &r_outer);
	if(r_outer > 20.0000){
		printf("N17(a) %f\n", (M_PI*(pow(r_outer, 2) - pow(r_inner, 2))));
	} else{
		printf("N17(a) Incorrect input, outside radius less than 20\n");
	}
}

// N20
// sum of an arithmetic progression
void n20(){
	float a, d;
	int n;
	scanf("%f %f %d", &a, &d, &n);
	printf("N20 sum of an arithmetic progression = %f\n", n*((2*a + (n-1)*d)/(2)));
}

typedef struct Solution{
	void (*solution[number_of_solutions])(void) = {n4, n5, n11, n17, n20};
}Solution;

int main(void){

	// test case 1 = 1 2 -1 2 1 1 1 21 2 3 4
	// test case 2 = 2 4 7 -11 1.2 0.1 129.087 -15 120 7 20
	// test case 3 = 0 0 0 0 0 0 0 0 0 0 0

	Solution test;
	for(int i = 0; i < number_of_solutions; ++i){
		test.solution[i]();
	}
}