#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct
{
	ElemType* data;
	int size;
	int length;
} SqList;
bool InitList(SqList& L, int s);         //��ʼ��˳���
int ListLength(const SqList& L);              //�����Ա���
int LocateElem(const SqList& L, const ElemType& e); //��ֵ����
bool GetElem(const SqList& L, int i, ElemType& e);  //��õ�i��Ԫ��
bool ListInsert(SqList& L, int i, const ElemType e);//�ڵ�i��Ԫ��ǰ����һ��Ԫ��e
bool ListDelete(SqList& L, int i, ElemType& e);     //ɾ����i��Ԫ��
void DestroyList(SqList& L);                        //����˳���
void ClearList(SqList& L);                          //���˳���
bool ListEmpty(const SqList& L);                    //�жϱ��Ƿ�Ϊ�ձ�
void DispList(const SqList& L);                     //����˳���

bool InitList(SqList& L, int s)         //��ʼ��˳���
{
	if (s <= 0)
		s = 10;
	L.data = new ElemType[s];
	if (L.data == NULL)
		return false;
	L.size = s;
	L.length = 0;
}
int ListLength(const SqList& L)              //�����Ա���
{
	return L.length;
}
int LocateElem(const SqList& L, const ElemType& e) //��ֵ����
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i + 1;
	}
	return false;
}
bool GetElem(const SqList& L, int i, ElemType& e)  //��õ�i��Ԫ��
{ 
	if (i >= 1 && i <= L.length)
	{
		e = L.data[i - 1];
		return true;
	}
	return false;
}
bool ListInsert(SqList& L, int i, const ElemType e)//�ڵ�i��Ԫ��ǰ����һ��Ԫ��e
{
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.size == L.length)    //���˳����Ѿ�����
	{
		ElemType* temp = new ElemType[2 * L.size];  //�Ͱѿռ���������
		if (temp == NULL)                           //���ʧ��
			return false;
		for (int i = 0; i < L.length; i++)          //��L��Ԫ�ظ�ֵ��temp��
			temp[i] = L.data[i];
		delete[] L.data;                            //ɾ��L
		L.data = temp;								//��temp���¸���L
		L.size = L.size * 2;						//��L���ڴ��Ϊ����
	}
	for (int k = L.length; k >= i; k--)
		L.data[k] = L.data[k - 1];
	L.data[i - 1] = e;
	L.length++;

	return true;
}
bool ListDelete(SqList& L, int i, ElemType& e)     //ɾ����i��Ԫ��
{
	if (i < 0 || i > L.length)
		return false;
	else
	{
		e = L.data[i - 1];
		for (int j = i - 1; j < L.length - 1; j++)
			L.data[j] = L.data[j + 1];
		L.length--;
		return true;
	}
}
void DestroyList(SqList& L)                        //����˳���
{
	delete[] L.data;
	L.data = NULL;
	L.size = 0;
	L.length = 0;
}
void ClearList(SqList& L)                          //���˳���
{
	L.length = 0;
}
bool ListEmpty(const SqList& L)                    //�жϱ��Ƿ�Ϊ�ձ�
{
	if (L.length == 0)
		return true;
	else
		return false;
}
void DispList(const SqList& L)                     //����˳���
{
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
}