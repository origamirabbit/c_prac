// Stack栈.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void initStack(PSTACK pS); //PSTACK 等价于 struct Stack*
void pushStack(PSTACK pS, int val);
void traverseStack(PSTACK pS);
bool popStack(PSTACK pS, int* val);
void clearStack(PSTACK pS);

int main(void)
{
	STACK S; // STACK 等价于struct Stack
	int val;

	initStack(&S); //初始化栈
	pushStack(&S, 1); //压栈
	pushStack(&S, 2); //
	pushStack(&S, 3);
	pushStack(&S, 4);
	pushStack(&S, 5);
	pushStack(&S, 6);

	traverseStack(&S); //遍历栈输出
	
	clearStack(&S);//清空栈

	//traverseStack(&S); //遍历栈输出

	if (popStack(&S, &val)) //出栈
	{
		printf("出栈成功 出栈的元素是: %d\n", val);
	}
	else
	{
		printf("出栈失败！\n");
	}

	traverseStack(&S); //遍历栈输出

	return 0;
}

void initStack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL; //（pS->pBottom）=（创建的空节点）->pNext = NULL;
	}
}

void pushStack(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));

	pNew->data = val;
	pNew->pNext = pS->pTop; //pS->pTop 不能改成pS->pBottom
	pS->pTop = pNew;

	return;
}

void traverseStack(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}


bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;	
	else
		return false;	
}

//把pS所指向的栈出栈一次， 并把出栈的元素纯属pVal形参所指向的变量中 如果出栈失败 返回false 否则返回 true
bool popStack(PSTACK pS, int* pVal)
{
	if (empty(pS))  //pS 本身存放的就是S栈的地址
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

//清空栈
void clearStack(PSTACK pS)
{
	PNODE p = pS->pTop;
	PNODE q = NULL;

	if (empty(pS))
	{
		return;
	}
	else
	{
		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}

		pS->pTop = pS->pBottom; // 如果不添加此句 则 pS->pTop此时指向的是最后一个被释放空间的节点 而不会指向 pS->pBotteom所指向的最后面的首节点
	}
	
}