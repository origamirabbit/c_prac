/*
 2021-03-13
 求1到100之间所有的能被3整除的数字之和
*/


#include <stdio.h>

int main(void)
{
	int i;
	
	int sum = 0;

	for (i = 3; i <= 100; ++i) // i=3 => first step; i<=100 => second step; ++i => third step
	{
		if (i % 3 == 0)        // if => 4th step
		{
			sum = sum + i;     // => 5th step
		}
		
	}
	
	printf("i = %d\n", i);     // => final step: output  note: final value of i is 101

	printf("sum = %d\n", sum);
	
	return 0;
}