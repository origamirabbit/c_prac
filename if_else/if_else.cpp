// if_else.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>

int main(void)
{ 
	int i, j;

	scanf_s("%d %d", &i, &j);

	if (i > j)
		printf("i > j\n");
	else
		printf("i < j\n");

	return 0;
}
