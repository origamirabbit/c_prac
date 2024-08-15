// 链表.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2021-03-24 00:12

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


struct Node  //定义一个链表节点的结构体
{
	int data; //数据域
	struct Node* pNext; //指针域
};

struct Node* create_list(void);
void traverse_list(struct Node*);

int main(void)
{
	struct Node* pHead = NULL; //pHead用来存放量表头结点的地址 

	pHead = create_list(); //创建一个肺循环单链表 并且把链表的头结点地址 付给主函数的 pHead
	traverse_list(pHead); //遍历输出


	return 0;
}

struct Node* create_list(void)
{
	int len; //用来存放有效节点的个数
	int i; 
	int val; //用来临时存放用户输入的节点的值

	//分配了一个不存放有效数据的头结点
	struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
	if (NULL == pHead)
	{
		printf("分配失败，程序终止!\n");
		exit(-1);
	}
	struct Node* pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表节点的个数: len = ");
	scanf("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个链表节点的个数: ", i+1);
		scanf("%d", &val);

		struct Node* pNew = (struct Node*)malloc(sizeof(struct Node));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止!\n");
			exit(-1);
		}
		pNew->data = val; //需要理解！！！
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;

}

bool empty_list(struct Node* pHead)
{
	if (pHead->pNext) //pHead->pNext == (*pHead).pNext
		return true;
	else
		return false;
}

void traverse_list(struct Node* pHead)
{
	struct Node* pNew = pHead->pNext;

	while (NULL != pNew)
	{
		printf("%d\n", pNew->data);
		pNew = pNew->pNext;
	}
	return;
}