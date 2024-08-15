// 汉诺塔.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
	//如果是1个盘子   直接将A柱 上的板子从A移动到C

	//否则 现将A柱 上的n-1个盘子借助C 移动到B
	//直接将A柱 上的盘子从A移动到 C
	//最后将B柱 上的n-1个盘子借助A移动到C

	if (1 == n)
	{
		printf("将编号为%d的盘子直接从 %c柱 移动到 %c柱\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从 %c柱 移动到 %c柱\n", n, A, C);
		hannuota(n - 1, B, A, C);

	}
}

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';

	int n;

	printf("请输入要移动盘子的个数: ");
	scanf_s("%d", &n);

	hannuota(n, 'A', 'B', 'C');

	return 0;
}
