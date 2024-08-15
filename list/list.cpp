// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data; //数据域
	struct Node* pNext; //指针域

}NODE, * PNODE; //NODE等价于 struct Node  PNODE 等价于 struct Node*

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
int length_list(PNODE pHead);
bool is_empty(PNODE pHead);
bool is_full(PNODE pHead);
bool insert_list(PNODE, int, int);  //在pHead所指向的链表的第pos个节点的前面插入一个新的节点， 该节点的值是val 并且pos的值从1开始
bool delete_list(PNODE, int, int*);  //在pHead所指向的链表的第pos个节点， 该节点的值是val 并且pos的值从1开始
void sort_list(PNODE);
void Delete_List(PNODE pHead); //删除整个链表


int main(void)
{
	PNODE pHead = NULL; //等价于 struct Node * pHead = NULL
	int val;

	pHead = create_list(); //create_list() 功能： 创建一个非循环单链表 并将该链表的头节点地址赋给pHead
	printf("生成链表如下:\n");
	traverse_list(pHead); //遍历
	printf("\n");

	/*insert_list(pHead, 2, 55);
	printf("添加节点后 链表如下:\n");
	traverse_list(pHead);
	printf("\n");*/

	if (delete_list(pHead, 2, &val))
	{
		printf("删除成功，您删除的元素是: %d\n", val);
	}
	else
	{
		printf("删除失败！\n");
	}
	printf("\n");
	printf("删除节点后 链表如下:\n");
	traverse_list(pHead);
	printf("\n");

	/*int len = length_list(pHead);
	printf("链表的长度为: %d\n", len);
	printf("\n");

	sort_list(pHead);
	printf("链表的升序如下:\n");
	traverse_list(pHead);
	printf("\n");*/

	return 0;
}

PNODE create_list(void)  //返回值是 PNODE类型 不需要参数
{
	int len; //存放有效节点的个数
	int i;
	int val; //临时存放用户输入的节点的值

	//分配了一个不存放有效数据的头节点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败 程序终止！\n");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL; //清空指针域
	

	printf("情书输入您需要生成的链表节点的个数: len = ");
	scanf_s("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入地%d个节点的值: ", i + 1);
		scanf_s("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //创建一个新的节点 
		if (NULL == pNew)
		{
			printf("分配失败 程序终止！\n");
			exit(-1);
		}
		pNew->data = val; //临时存放用户输入的pNew节点的值
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	printf("\n");

	return pHead;
}

void traverse_list(PNODE pHead) //遍历
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;

	for (i=0, p = pHead->pNext; i<len-1;++i, p=p->pNext)
		for (j = i+1, q = p->pNext; j < len; ++j,q=q->pNext)
		{
			if (p->data > q->data) //(a[i] > a[j])
			{
				t = p->data; //== t = a[i];
				p->data = q->data;//== a[i] = a[j];
				q->data = t;//== a[j] = t;
			}		
		}
	
	return;
}

//在pHead所指向的链表的第pos个节点的前面插入一个新的节点， 该节点的值是val 并且pos的值从1开始
bool insert_list(PNODE pHead, int pos, int val)
{
	PNODE p = pHead; //等价于 struct Node* pHead = NULL;
	int i = 0;

	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i >= pos - 1 || NULL == p) // 举例 当有3个元素时 
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}

	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(PNODE pHead, int pos, int* pVal)
{
	PNODE p = pHead; //等价于 struct Node* pHead = NULL;
	int i = 0;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext) //删除 和 插入 的区别 即 对第pos-1个节点的操作处理 > 和 >= 的区别
	{
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->data;

	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}

//补充老师未讲到的"单链表整表删除代码"（已在VS2015上跑通）

void Delete_List(PNODE pHead)
{
	PNODE p = pHead->pNext;
	PNODE q;
	while (p != NULL)
	{
		q = p->pNext;
		free(p);
		p = q;
	}
	pHead->pNext = NULL;

}
