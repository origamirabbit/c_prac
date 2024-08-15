// 快速排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>
//升序快速排序
void QuickSort(int* a, int low, int high);

int FindPos(int* a, int low, int high);

int main(void)
{
	int a[7] = {-5, 2, 6, -8, 4, 3, -7};

	int i;
	
	//显示未排序数组
	for (i = 0; i < 7; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	QuickSort(a, 0, 6); //第二个参数表示第一个元素的下标 第三个参数表示最后一个元素的下标
	
	//显示快速排序后的数组
	printf("显示升序快速排序后的数组:\n");
	for (i = 0; i < 7; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

//递归思想 快速排序
void QuickSort(int* a, int low, int high)
{
	int pos;

	if (low < high)
	{
		pos = FindPos(a, low, high);

		QuickSort(a, low, pos - 1); //左边递归
		QuickSort(a, pos + 1, high); //右边递归
	}
}

int FindPos(int* a, int low, int high)
{
	int val = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= val) //如果 high对应的数值 大于等于val的值
			--high; //high所指向的位置向左移一位 然后继续循环
		a[low] = a[high]; //否则 low对应的数值 取high对应的数值

		while (low < high && a[low] <= val)//如果 low对应的数值 小于等于val的值
			++low; ////low所指向的位置向右移一位 然后继续循环
		a[high] = a[low]; //否则 high对应的数值 取low对应的数值
	
	}//终止while循环之后 low和high的位置 是相等的
	if (low = high)
	{
		a[low] = val;
	}
	
	return low; // high 和 low 都可以返回 但不能改为 val a[low] a[high]
}