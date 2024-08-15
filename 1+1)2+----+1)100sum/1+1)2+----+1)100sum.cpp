/*
2021-03-13

1+1)2+----+1)100sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include <stdio.h>

int main(void)
{
	int i;                            // float i;  is not correct.浮点数存储问题， 浮点数的存错所带来的问题，float和double都不能保证可以精确的存储一个小数 
	float sum = 0;                    // if (|x-0.000001| < 0.000001)  

	for (i = 1; i <= 100; ++i)        //循环中更新的变量不能定义成浮点型float
	{
		sum = sum +  1/(float)(i);    // 1.0 / i or 1 / (float)(i) force to change to float.
	}                                 // example: (int)(4.5+2.2) == 6 (数据类型)（表达式）

	printf("i = %d\n", i);
	printf("sum = %f\n", sum);        // use %f output float value  

	return 0;
}