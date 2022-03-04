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
bool InitList(SqList& L, int s);         //初始化顺序表
int ListLength(const SqList& L);              //求线性表长度
int LocateElem(const SqList& L, const ElemType& e); //按值查找
bool GetElem(const SqList& L, int i, ElemType& e);  //获得第i个元素
bool ListInsert(SqList& L, int i, const ElemType e);//在第i个元素前插入一个元素e
bool ListDelete(SqList& L, int i, ElemType& e);     //删除第i个元素
void DestroyList(SqList& L);                        //销毁顺序表
void ClearList(SqList& L);                          //清空顺序表
bool ListEmpty(const SqList& L);                    //判断表是否为空表
void DispList(const SqList& L);                     //遍历顺序表

bool InitList(SqList& L, int s)         //初始化顺序表
{
	if (s <= 0)
		s = 10;
	L.data = new ElemType[s];
	if (L.data == NULL)
		return false;
	L.size = s;
	L.length = 0;
}
int ListLength(const SqList& L)              //求线性表长度
{
	return L.length;
}
int LocateElem(const SqList& L, const ElemType& e) //按值查找
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i + 1;
	}
	return false;
}
bool GetElem(const SqList& L, int i, ElemType& e)  //获得第i个元素
{ 
	if (i >= 1 && i <= L.length)
	{
		e = L.data[i - 1];
		return true;
	}
	return false;
}
bool ListInsert(SqList& L, int i, const ElemType e)//在第i个元素前插入一个元素e
{
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.size == L.length)    //如果顺序表已经满了
	{
		ElemType* temp = new ElemType[2 * L.size];  //就把空间扩大两倍
		if (temp == NULL)                           //如果失败
			return false;
		for (int i = 0; i < L.length; i++)          //把L的元素赋值到temp中
			temp[i] = L.data[i];
		delete[] L.data;                            //删除L
		L.data = temp;								//将temp重新赋给L
		L.size = L.size * 2;						//将L的内存改为两倍
	}
	for (int k = L.length; k >= i; k--)
		L.data[k] = L.data[k - 1];
	L.data[i - 1] = e;
	L.length++;

	return true;
}
bool ListDelete(SqList& L, int i, ElemType& e)     //删除第i个元素
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
void DestroyList(SqList& L)                        //销毁顺序表
{
	delete[] L.data;
	L.data = NULL;
	L.size = 0;
	L.length = 0;
}
void ClearList(SqList& L)                          //清空顺序表
{
	L.length = 0;
}
bool ListEmpty(const SqList& L)                    //判断表是否为空表
{
	if (L.length == 0)
		return true;
	else
		return false;
}
void DispList(const SqList& L)                     //遍历顺序表
{
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
}