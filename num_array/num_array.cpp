/*
num_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include <stdio.h>

int main(void)
{
	/*
	int a[5] = { 1, 2, 3, 4, 5 }; //a是数组的名字， 5表示数组元素，并且这5个元素分别用a[0] a[1] a[2] a[3] a[4]表示

	int i;

	for (i = 0; i < 5; ++i)
	{
		printf("%d\n", a[i]);
	}

	return 0;
	*/
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int i, j;
	int t;

	i = 0;
	j = 6;
	
	while (i < j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;

		i++;
		--j;
 	}
	for (i = 0; i < 7; ++i)
		printf("%d\n", a[i]);

	return 0;

}

