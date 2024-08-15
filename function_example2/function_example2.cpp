/*
2021-03-18
判断是个数字 是否 是素数 （质数，又称素数，指在一个大于1的自然数中，除了1和此整数自身外，无法被其他自然数整除的数（也可定义为只有1和本身两个因数的数）。 比1大但不是素数的数称为合数。1和0既非素数也非合数。素数在数论中有着很重要的地位。）
*/

#include <stdio.h>

bool isPrime(int val) //bool =》 ture or false
{
	int m;

	for (m = 2; m < val; ++m)  // 从2开始循环到 val-1的值
	{
		if (val % m == 0)      // 如果循环中任意一个i值能被 val的值整除 则终止for循环 说明val所值值不是素数 且i<val 执行else语句
			break;
	}
	if (m == val)          //当i的值+到val的值 说明 val的值是素数 
		return true;
	else
		return false;	
}

int main(void)
{
	int val;
	//int i;

	scanf_s("%d", &val);

	//for (i = 2; i < val; ++i)  // 从2开始循环到 val-1的值
	//{
	//	if (val % i == 0)      // 如果循环中任意一个i值能被 val的值整除 则终止for循环 说明val所值值不是素数 且i<val 执行else语句
	//		break;
	//}
	//if (i == val)          //当i的值+到val的值 说明 val的值是素数 
	//	printf("Yes!\n");  
	//else
	//	printf("No!\n");

	if (isPrime(val))
		printf("Yes!\n");
	else
		printf("No!\n");
		
	return 0;
}