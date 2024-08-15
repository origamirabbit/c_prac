/*
2021-03-14
switch 用法
*/

#include <stdio.h>

int main(void)
{
	int val;

	printf("please enter the level: ");
	scanf_s("%d", &val);

	switch (val)
	{
	case 1:                                  //case 和 default 是程序的入口 找到某一入口后 所有的入口失效
		printf("arrived level 1\n");
		break;
	case 2:
		printf("arrived level 2\n");
		break;
	case 3:
		printf("arrived level 3\n");
		break;
	case 4:
		printf("arrived level 4\n");
		break;
	default:
		printf("level unable to reach\n");
		break;
	}

	return 0;
}