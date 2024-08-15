// Arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>  //包含 malloc函数
#include <stdlib.h> //包含 exit函数

//定义了一个数据类型 该数据类型的名字叫struct Arr  该数据含有四个成员
struct Arr
{
	int* pBase; //储存的是数组第一个元素的地址
	int len; //数组所能容纳的最大元素的个数
	int cnt; //当前数组有效元素的个数
	//int increament; //自动增长因子
};

void init_arr(struct Arr*, int);  //初始化
bool append_arr(struct Arr* pArr, int val); //追加
bool insert_arr(struct Arr* pArr, int pos, int val); //插入      加入位置形参pos pos的值从1开始
bool delete_arr(struct Arr* pArr, int pos, int* pVal); //删除       利用指针接收值
int get(); //取值
bool is_empty(struct Arr* pArr);//空
bool is_full(struct Arr* pArr); //满
void sort_arr(struct Arr*); //排序
void show_arr(struct Arr*); //输出
void inversion_arr(struct Arr*); //倒置


int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr); //返回 数组为空!
	append_arr(&arr, 1);
	//delete_arr(&arr, 1, &val);
	append_arr(&arr, 10);
	append_arr(&arr, -3);
	append_arr(&arr, 6);
	append_arr(&arr, 88);
	
	//insert_arr(&arr, 5, 99);

	append_arr(&arr, 11);
	//append_arr(&arr, 7);

	if (delete_arr(&arr, 4, &val))
	{
		printf("删除成功！\n");
		printf("您删除的元素是： %d\n", val);
	}
	else
	{
		printf("删除失败！\n");
	}

	//if (append_arr(&arr, 8))
	//{
	//	printf("追加成功\n");
	//}
	//else
	//{
	//	printf("追加失败!\n");

	//}
	show_arr(&arr);
	
	inversion_arr(&arr);
	printf("倒置数组输出为:\n");
	show_arr(&arr);
	
	sort_arr(&arr);
	printf("排列数组输出为:\n");
	show_arr(&arr);

	//printf("%d\n", arr.len);

	return 0;
}

void init_arr(struct Arr* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败");
		exit(-1); //终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr* pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr* pArr)
{
	if (is_empty(pArr))
	{
		printf("数组为空!\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
			printf("%d ", pArr->pBase[i]); //int*
		printf("\n");
	}
}

bool append_arr(struct Arr* pArr, int val)
{
	if (is_full(pArr)) //满时返回false
	    return false;

	pArr->pBase[pArr->cnt] = val; //不满时 执行 追加  例如 pArr->pBase[0]=val, cnt= 1 所以追加 pArr->pBase[cnt](追加元素位置) = val(追加的值)
	(pArr->cnt)++;
		return true;
	
}

bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr)) //满是返回false
		return false;
	if (pos<1 || pos>pArr->cnt + 1) //pos值不能小于1 且 不能大于 cnt+1的值
		return false;
	for (int i = pArr->cnt - 1; i >= pos - 1; --i) //在插入新数值之前 对pos位置之后的数值 进行数据后移
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val; //添加插入数值
	(pArr->cnt)++;
	return true;
}

bool delete_arr(struct Arr* pArr, int pos, int* pVal)
{
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt) //pos值不能小于1 且 不能大于cnt值
		return false;
	*pVal = pArr->pBase[pos - 1]; //把后面的值 覆盖到 前面元素的值
	for (int i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	(pArr->cnt)--;
	return true;
}

void inversion_arr(struct Arr* pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;

	while (i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr* pArr)
{
	for (int i = 0; i < pArr->cnt; ++i)
		for (int j = 0; j < pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				int t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	return;
}