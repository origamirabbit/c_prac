#include <stdio.h>
/*
void max1(int i, int j) //max is name of the function and i j 形式参数 void表示函数没有返回值
{
	if (i > j)                     //第一个方法 简单 功能不好
		printf("max: %d\n", i);    //最大值 找到 并 处理
	else
		printf("max: %d\n", j);
}
*/

int max2(int i, int j) //第二个方法 功能好一些 普通函数 有返回值 用int float double....
{ 
	if (i > j)           //只找到 最大值
		return i;
	else
		return j;
}

int main(void)
{
	int a, b, c, d, e, f;

	a = 1; b = 2; c = 3; d = 9; e = -5; f = 100;

	printf("%d\n", max2(a, b));   //第二种方法 更好一些 
	printf("%d\n", max2(c, d));
	printf("%d\n", max2(e, f));

/*
	max1(a, b);
	max1(c, d);
	max1(e, f);
*/
	return 0;
}


