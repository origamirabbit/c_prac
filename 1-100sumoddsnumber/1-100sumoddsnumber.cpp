/*
2021-03-13
  int cnt or int count => count numbers  ++cnt; or ++count;
*/

#include <stdio.h>

int main(void)
{
	int i;
	int odd_sum = 0;
	int even_sum = 0;
	int odd_cnt = 0;
	int even_cnt = 0;
	float odd_avg;
	float even_avg;


	for (i = 1; i < 101; ++i)           
	{
		if (i % 2 == 1)                 // sum of odds numbers
		{
			odd_sum += i;               //odd_sum = odd_sum + i;
			++odd_cnt;
		}

		if (i % 2 == 0)                 // sum of even numbers
		{
			even_sum += i;              //even_sum = even_sum + i;
			++even_cnt;
	    }
 	}

	odd_avg = 1.0 * odd_sum / odd_cnt;  //1.0 * Ä¬ÈÏÊÇ defaut is double
	even_avg = 1.0 * even_sum / even_cnt;

	printf("odd_sum = %d\n", odd_sum);
	printf("even_sum = %d\n", even_sum);
	printf("odd_cnt = %d\n", odd_cnt);
	printf("even_cnt = %d\n", even_cnt);
	printf("odd_avg = %f\n", odd_avg);
	printf("even_avg = %f\n", even_avg);

	return 0;
}