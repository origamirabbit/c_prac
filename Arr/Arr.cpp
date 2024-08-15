// Arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>  //���� malloc����
#include <stdlib.h> //���� exit����

//������һ���������� ���������͵����ֽ�struct Arr  �����ݺ����ĸ���Ա
struct Arr
{
	int* pBase; //������������һ��Ԫ�صĵ�ַ
	int len; //�����������ɵ����Ԫ�صĸ���
	int cnt; //��ǰ������ЧԪ�صĸ���
	//int increament; //�Զ���������
};

void init_arr(struct Arr*, int);  //��ʼ��
bool append_arr(struct Arr* pArr, int val); //׷��
bool insert_arr(struct Arr* pArr, int pos, int val); //����      ����λ���β�pos pos��ֵ��1��ʼ
bool delete_arr(struct Arr* pArr, int pos, int* pVal); //ɾ��       ����ָ�����ֵ
int get(); //ȡֵ
bool is_empty(struct Arr* pArr);//��
bool is_full(struct Arr* pArr); //��
void sort_arr(struct Arr*); //����
void show_arr(struct Arr*); //���
void inversion_arr(struct Arr*); //����


int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr); //���� ����Ϊ��!
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
		printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ���ǣ� %d\n", val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
	}

	//if (append_arr(&arr, 8))
	//{
	//	printf("׷�ӳɹ�\n");
	//}
	//else
	//{
	//	printf("׷��ʧ��!\n");

	//}
	show_arr(&arr);
	
	inversion_arr(&arr);
	printf("�����������Ϊ:\n");
	show_arr(&arr);
	
	sort_arr(&arr);
	printf("�����������Ϊ:\n");
	show_arr(&arr);

	//printf("%d\n", arr.len);

	return 0;
}

void init_arr(struct Arr* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1); //��ֹ��������
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
		printf("����Ϊ��!\n");
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
	if (is_full(pArr)) //��ʱ����false
	    return false;

	pArr->pBase[pArr->cnt] = val; //����ʱ ִ�� ׷��  ���� pArr->pBase[0]=val, cnt= 1 ����׷�� pArr->pBase[cnt](׷��Ԫ��λ��) = val(׷�ӵ�ֵ)
	(pArr->cnt)++;
		return true;
	
}

bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr)) //���Ƿ���false
		return false;
	if (pos<1 || pos>pArr->cnt + 1) //posֵ����С��1 �� ���ܴ��� cnt+1��ֵ
		return false;
	for (int i = pArr->cnt - 1; i >= pos - 1; --i) //�ڲ�������ֵ֮ǰ ��posλ��֮�����ֵ �������ݺ���
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val; //��Ӳ�����ֵ
	(pArr->cnt)++;
	return true;
}

bool delete_arr(struct Arr* pArr, int pos, int* pVal)
{
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt) //posֵ����С��1 �� ���ܴ���cntֵ
		return false;
	*pVal = pArr->pBase[pos - 1]; //�Ѻ����ֵ ���ǵ� ǰ��Ԫ�ص�ֵ
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