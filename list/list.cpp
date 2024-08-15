// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data; //������
	struct Node* pNext; //ָ����

}NODE, * PNODE; //NODE�ȼ��� struct Node  PNODE �ȼ��� struct Node*

//��������
PNODE create_list(void);
void traverse_list(PNODE pHead);
int length_list(PNODE pHead);
bool is_empty(PNODE pHead);
bool is_full(PNODE pHead);
bool insert_list(PNODE, int, int);  //��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬 �ýڵ��ֵ��val ����pos��ֵ��1��ʼ
bool delete_list(PNODE, int, int*);  //��pHead��ָ�������ĵ�pos���ڵ㣬 �ýڵ��ֵ��val ����pos��ֵ��1��ʼ
void sort_list(PNODE);
void Delete_List(PNODE pHead); //ɾ����������


int main(void)
{
	PNODE pHead = NULL; //�ȼ��� struct Node * pHead = NULL
	int val;

	pHead = create_list(); //create_list() ���ܣ� ����һ����ѭ�������� �����������ͷ�ڵ��ַ����pHead
	printf("������������:\n");
	traverse_list(pHead); //����
	printf("\n");

	/*insert_list(pHead, 2, 55);
	printf("��ӽڵ�� ��������:\n");
	traverse_list(pHead);
	printf("\n");*/

	if (delete_list(pHead, 2, &val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ����: %d\n", val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
	}
	printf("\n");
	printf("ɾ���ڵ�� ��������:\n");
	traverse_list(pHead);
	printf("\n");

	/*int len = length_list(pHead);
	printf("����ĳ���Ϊ: %d\n", len);
	printf("\n");

	sort_list(pHead);
	printf("�������������:\n");
	traverse_list(pHead);
	printf("\n");*/

	return 0;
}

PNODE create_list(void)  //����ֵ�� PNODE���� ����Ҫ����
{
	int len; //�����Ч�ڵ�ĸ���
	int i;
	int val; //��ʱ����û�����Ľڵ��ֵ

	//������һ���������Ч���ݵ�ͷ�ڵ�
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ�� ������ֹ��\n");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL; //���ָ����
	

	printf("������������Ҫ���ɵ�����ڵ�ĸ���: len = ");
	scanf_s("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ: ", i + 1);
		scanf_s("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //����һ���µĽڵ� 
		if (NULL == pNew)
		{
			printf("����ʧ�� ������ֹ��\n");
			exit(-1);
		}
		pNew->data = val; //��ʱ����û������pNew�ڵ��ֵ
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	printf("\n");

	return pHead;
}

void traverse_list(PNODE pHead) //����
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

//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬 �ýڵ��ֵ��val ����pos��ֵ��1��ʼ
bool insert_list(PNODE pHead, int pos, int val)
{
	PNODE p = pHead; //�ȼ��� struct Node* pHead = NULL;
	int i = 0;

	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i >= pos - 1 || NULL == p) // ���� ����3��Ԫ��ʱ 
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
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
	PNODE p = pHead; //�ȼ��� struct Node* pHead = NULL;
	int i = 0;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext) //ɾ�� �� ���� ������ �� �Ե�pos-1���ڵ�Ĳ������� > �� >= ������
	{
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->data;

	//ɾ��p�ڵ����Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}

//������ʦδ������"����������ɾ������"������VS2015����ͨ��

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
