#include <iostream>
#include "SeqList.h"
using namespace std;
int main()
{
	//����һ��˳���
	SqList L;
	
	//��ʼ��˳������ڴ�Ϊ��СΪ2
	InitList(L, 2);

	//�ж��Ƿ��Ǹ��ձ�
	bool b1 = ListEmpty(L);
	if (b1 == true)
		cout << "L��һ���ձ�" << endl;
	else
		cout << "L����һ���ձ�" << endl;
	
	//�鿴˳���ĳ���
	cout << ListLength(L) << endl;

	//����Ԫ��
	for (int i = 1; i <= 5; i++)
		ListInsert(L, 1, i + 1);

	//����˳���
	cout << "˳����Ԫ�أ�";
	DispList(L);
	cout << endl;
	cout << "˳�����ڴ��СΪ��" << L.size << endl;  //�ռ䷭����2 -> 4 -> 8

	//��ֵ����
	int x = 9;
	if (LocateElem(L, x) != false)
		cout << x << "�ڱ��е�" << LocateElem(L, x) << "��λ��" << endl;
	else
		cout << "���в�����" << x << endl;
	cout << endl;

	//��ȡ��i��Ԫ��
	int y;
	GetElem(L, 5, y);
	cout << "���е�5��Ԫ����" << y << endl;

	//�ж��Ƿ��Ǹ��ձ�
	bool b2 = ListEmpty(L);
	if (b2 == true)
		cout << "L��һ���ձ�" << endl;
	else
		cout << "L����һ���ձ�" << endl;

	//ɾ��Ԫ��
	int e;
	cout << "ɾ���Ƿ�ɹ���" << ListDelete(L, 2, e) << endl;
	cout << endl;

	//����Ԫ��
	cout << "ɾ��֮���˳���Ԫ�أ�";
	DispList(L);
	cout << endl;
	cout << "ɾ����Ԫ���ǣ�" << e << endl;

	//���˳���
	//ClearList(L);

	//����˳���
	DestroyList(L);

	//����Ԫ��
	DispList(L);

	return 0;
}