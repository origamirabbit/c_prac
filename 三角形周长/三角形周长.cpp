// 三角形周长.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <math.h>

double circumference(double a, double b, double c)
{
	return double(a + b + c);
}

double area(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c)); //求三角形面积

}

int main(void)
{
	double a, b, c;
	printf("pls enter a: ");
	scanf_s("%lf", &a);

	printf("pls enter b: ");
	scanf_s("%lf", &b);

	printf("pls enter c: ");
	scanf_s("%lf", &c);


	/*a = 3;
	b = 4;
	c = 5;*/
	
	printf("%lf, %lf\n", circumference(a, b, c), area(a, b, c));

	return 0;
}
