// review_function.cpp : 求输入一个数值 并输出所有2到输出值的所有素数
#include <stdio.h>

//int f(int i) //如果有调回函数用int bool等并使用return （调回函数值）；     如果没有调回函数使用void return；(无表达式)
//{
//	return i;   //函数内的变量 i 与主函数main的变量 i 不冲突 只在本函数内定义使用
//}

//int main(void)
//{
//	int val;
//	int i;
//	int j;
//
//	scanf_s("%d", &val);
//	for (i = 2; i < val; ++i)  // 2 到 i-1
//	{
//		for (j = 2; j < i; ++j) //判断i 是否是素数， 是=输出，不是=不输出
//		{
//			if (0 == i % j)
//				break;
//		}
//		if (j == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//用两个函数来实现求1到某个数字所有的素数，并将其输出 本程序代码量较少 可重复性更高

bool isPrime(int val) //本函数的功能是：判断val 是否是素数， 是=返回true 不是=返回false
{
	int i;

	for (i = 2; i < val; ++i)
	{
		if (0 == val % i)
			break;
	}
	if (i == val)
		return true;
	else
		return false;
}

void TraverseVal(int val) //本函数的功能是吧1到n之间多有的素数在显示器上输出
{
	int i;

	for (i = 2; i <= val; ++i)
	{
		if (isPrime(i))
			printf("%d\n", i);
	}
	if (val == 1)  //输入值为1的情况
	{
		printf("%d\n", val);
	}	
	else
	{
		printf("invalid number！", val); //输入值不合法 //不是特别好 再想想！！！
	}		
}

int main(void)
{
	int val;

	scanf_s("%d", &val);

	TraverseVal(val);

	return 0;
}