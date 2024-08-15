// 循环队列.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct Queue
{
	int* pBase;
	int front, rear;
}QUEUE;

void init(QUEUE*);
bool enter_queue(QUEUE* pQ, int val);
void traverse_queue(QUEUE*);
bool full_queue(QUEUE*);

bool out_queue(QUEUE* pQ,  int* pVal);
bool empty_queue(QUEUE* qQ);

int main(void)
{
	QUEUE Q;
	int val;

	init(&Q);
	enter_queue(&Q, 1);
	enter_queue(&Q, 2);
	enter_queue(&Q, 3);
	enter_queue(&Q, 4);
	enter_queue(&Q, 5);
	enter_queue(&Q, 6);
	enter_queue(&Q, 7);
	enter_queue(&Q, 8);


	traverse_queue(&Q);

	if (out_queue(&Q, &val))
	{
		printf("出队成功 队列出队的元素是: %d\n", val);
	}
	else
	{
		printf("出队失败! \n");
	}
	
	traverse_queue(&Q);
	
	
	return 0;
}

void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;

}

bool full_queue(QUEUE* pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

bool enter_queue(QUEUE* pQ, int val)
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

void traverse_queue(QUEUE* pQ)
{
	int i = pQ-> front;

	while (i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");

	return;
}

bool empty_queue(QUEUE* pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE* pQ, int* pVal)
{
	if (empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;

		return true;
	}

}