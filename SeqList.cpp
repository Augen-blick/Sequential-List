#include <iostream>
#include "SeqList.h"
using namespace std;
int main()
{
	//定义一个顺序表
	SqList L;
	
	//初始化顺序表，令内存为大小为2
	InitList(L, 2);

	//判断是否是个空表
	bool b1 = ListEmpty(L);
	if (b1 == true)
		cout << "L是一个空表" << endl;
	else
		cout << "L不是一个空表" << endl;
	
	//查看顺序表的长度
	cout << ListLength(L) << endl;

	//插入元素
	for (int i = 1; i <= 5; i++)
		ListInsert(L, 1, i + 1);

	//遍历顺序表
	cout << "顺序表的元素：";
	DispList(L);
	cout << endl;
	cout << "顺序表的内存大小为：" << L.size << endl;  //空间翻倍，2 -> 4 -> 8

	//按值查找
	int x = 9;
	if (LocateElem(L, x) != false)
		cout << x << "在表中第" << LocateElem(L, x) << "个位置" << endl;
	else
		cout << "表中不存在" << x << endl;
	cout << endl;

	//获取第i个元素
	int y;
	GetElem(L, 5, y);
	cout << "表中第5个元素是" << y << endl;

	//判断是否是个空表
	bool b2 = ListEmpty(L);
	if (b2 == true)
		cout << "L是一个空表" << endl;
	else
		cout << "L不是一个空表" << endl;

	//删除元素
	int e;
	cout << "删除是否成功：" << ListDelete(L, 2, e) << endl;
	cout << endl;

	//遍历元素
	cout << "删除之后的顺序表元素：";
	DispList(L);
	cout << endl;
	cout << "删除的元素是：" << e << endl;

	//清空顺序表
	//ClearList(L);

	//销毁顺序表
	DestroyList(L);

	//遍历元素
	DispList(L);

	return 0;
}