// 学生管理系统 动态构造.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>
//#include <string.h>

struct Student
{
	//char name[100]; //数组名
	int age;
	char sex;
	float score;

};

int main(void)
{
	int len;
	struct Student* pArr;
	int i, j;
	struct Student t;//临时变量 和 pArr 变量类型保持一致

	printf("请输出学生个数：\n");
	printf("len = ");
	scanf_s("%d", &len);

	//动态的构造一维数组
	pArr = (struct Student*)malloc(len * sizeof(struct Student)); // len 个元素 × 字节数 

	//输入  有问题！
	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个学生的信息：\n", i + 1);
		
		//printf("name = ");
		//scanf_s("%s", pArr[i].name);//因为name是数组名，本身就已经是数组首元素的地址，所以不能改成 &pArr[i].name

		printf("age = ");
		scanf_s("%d", &pArr[i].age);

		printf("sex = ");
		scanf_s("%c", &pArr[i].sex);

		printf("score = ");
		scanf_s("%f", &pArr[i].score);
	}
	
	//按成绩升序排序学生信息 冒泡排序
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (pArr[j].score > pArr[j + 1].score)
			{
				t = pArr[j];
				pArr[j] = pArr[j + 1];
				pArr[j + 1] = t;

			}
		}
	}
		

	printf("\n\n学生的信息是：\n");
	//输出
	for (i = 0; i < len; ++i)
	{
		printf("第%d个学生的信息是：\n", i + 1);

		//printf("name = %s\n", pArr[i].name);//因为name是数组名，本身就已经是数组首元素的地址，所以不能改成 &pArr[i].name
		printf("age = %d\n", pArr[i].age);
		printf("sex = %c\n", pArr[i].sex);
		printf("score = %f\n", pArr[i].score);

		printf("\n");
	
	}
	
	return 0;
}
