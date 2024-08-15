#include <stdio.h>

int main(void)
{
	int i;
	
	int sum = 0;

	for (i = 1; i < 100; i += 2) // final value of i is 101 because when i = 101 try "for" loop not working then stop 
	{
		sum = sum + i;
	}

	printf("i = %d\n", i);
	printf("sum = %d\n", sum);

	return 0;
}