/* feibolaqiexulie.cpp : This file contains the 'main' function. Program execution begins and ends there.

   1 2 3 5 8 13 21 34 ........
*/
#include <stdio.h>

int main(void)
{
	int n, i;
	int f1, f2, f3;
	
	f1 = 1;
	f2 = 2;

	printf("pls enter your wanted number: ");
	scanf_s("%d", &n);

	if (1 == n)
	{
		f3 = 1;
	}
	else if (2 == n)
	{
		f3 = 2;
	}
	else
	{
		for (i = 3; i <= n; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}

	printf("%d\n", f3);

	return 0;
}