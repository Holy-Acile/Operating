#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 640
enum status { FREE, BUSY };

typedef struct freespace
{
	int num;         //分区号
	int size;        //分区大小
	int address;     //分区首地址
	status state;    //分区状态，FREE和BUSY
};

typedef struct node
{
	freespace data;
	node *head;
	node *next;
}*Linklist;

Linklist first, last;

void initial()
{
	first = new node;
	last = new node;
	first->head = NULL;
	first->next = last;
	last->head = first;
	last->next = NULL;
	last->data.address = 0;
	last->data.size = MAXSIZE;
	last->data.num = 0;
	last->data.state = FREE;
}

void display()
{
	cout << "****************主内存分配情况****************" << endl;
	node *p = first->next;
	while (p)
	{
		cout << "分区号：";
		if (p->data.num == 0)
		{
			cout << "空闲区" << "  " << "起始地址：" << p->data.address << "	" << "终止地址：" << p->data.address + p->data.size <<
				"	" << "分区大小：" <<
				p->data.size << "KB" << "	" << "状态:空闲" << endl;
		}
		else
		{
			cout << p->data.num;
			cout << "	" << "起始地址：" << p->data.address << "	" << "终止地址：" << p->data.address + p->data.size << "	"
				"分区大小：" << p->data.size
				<< "KB" << "	" << "状态:";
			if (p->data.state == FREE)
				cout << "空闲" << endl;
			else if (p->data.state == BUSY)
				cout << "占用" << endl;
		}
		p = p->next;
	}
	cout << "**********************************************" << endl << endl;
}

int firstAlloc()//首次分配
{
	int num, size;
	cout << "请输入作业号和分配的主存大小KB：" << endl;;
	cin >> num >> size;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	while (p)
	{
		if (p->data.state == FREE&&p->data.size == size)//有大小刚好合适的空闲块
		{
			p->data.state = BUSY;
			p->data.num = num;
			display();
			return 1;
		}
		if (p->data.state == FREE&&p->data.size > size)//有大小比他大的空闲块
		{
			list->head = p->head;
			list->next = p;
			list->data.address = p->data.address;
			p->head->next = list;
			p->head = list;
			p->data.address = list->data.address + list->data.size;
			p->data.size -= size;
			display();
			return 1;
		}
		p = p->next;
	}
	display();
	return 0;
}

int bestAlloc()//最佳分配
{
	int num, size;
	cout << "请输入作业号和分配的主存大小KB：" << endl;
	cin >> num >> size;
	int min_space = MAXSIZE;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
·	node *q = NULL;
	while (p)//找到最佳位置
	{
		if ((p->data.size > size || p->data.size == size) && p->data.state == FREE)
		{
			if (p->data.size - size < min_space)
			{
				q = p;
				min_space = p->data.size - size;
			}
		}
		p = p->next;
	}
	if (q == NULL)
	{
		return 0;
	}
	else
	{
		if (min_space == 0)
		{
			q->data.num = num;
			q->data.state = BUSY;
			display();
			return 1;
		}
		else
		{
			list->head = q->head;
			list->next = q;
			list->data.address = q->data.address;
			q->head->next = list;
			q->head = list;
			q->data.address += size;
			q->data.size -= size;
			display();
			return 1;
		}
	}
}
int worstAlloc()//最佳分配
{
	int num, size;
	cout << "请输入作业号和分配的主存大小KB：" << endl;;
	cin >> num >> size;
	int min_space = MAXSIZE;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	node *q = NULL;
	while (p)//找到最佳位置
	{
		if ((p->data.size > size || p->data.size == size) && p->data.state == FREE)
		{
			if (p->data.size - size < min_space)
			{
				q = p;
				min_space = p->data.size - size;
			}
		}
		p = p->next;
	}
	if (q == NULL)
	{
		return 0;
	}
	else
	{
		if (min_space == 0)
		{
			q->data.num = num;
			q->data.state = BUSY;
			display();
			return 1;
		}
		else
		{
			list->head = q->head;
			list->next = q;
			list->data.address = q->data.address;
			q->head->next = list;
			q->head = list;
			q->data.address += size;
			q->data.size -= size;
			display();
			return 1;
		}
	}
}

int recycle()//碎片整理
{
	int num;
	cout << "请输入你要回收内存的作业号：" << endl;
	cin >> num;
	node *p = first;
	while (p)
	{
		if (p->data.num == num)
		{
			p->data.state = FREE;
			p->data.num = 0;
			if (p->head->data.state == FREE)//与前一块空闲区相邻，则合并
			{
				p->head->data.size += p->data.size;
				p->head->next = p->next;
				p->next->head = p->head;
			}
			if (p->next->data.state == FREE)//与后一块空闲区相邻，则合并
			{
				p->data.size += p->next->data.size;
				p->next->next->head = p;
				p->next = p->next->next;
			}
			break;
		}
		p = p->next;
	}
	display();
	return 1;
}

void menu()
{
	cout << "********************内存分配系统********************" << endl;
	cout << "*              1.首次适应算法分配内存              *" << endl;
	cout << "*              2.循环适应算法分配内存              *" << endl;
	cout << "*              3.最佳适应算法分配内存              *" << endl;
	cout << "*              4.最坏适应算法分配内存              *" << endl;
	cout << "*              5.查看主存分配情况                  *" << endl;
	cout << "*              6.回收主存                          *" << endl;
	cout << "*              7.溜了                              *" << endl;
	cout << "****************************************************" << endl;
	cout << "请选择：" << endl;
}

void main()
{
	initial();
	int choose;
	while (1)
	{
		menu();
		cin >> choose;
		switch (choose)
		{
		case 1:
			firstAlloc();
			break;
		case 2:
			bestAlloc();
			break;
		case 3:
			display();
			break;
		case 4:
			recycle();
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "请输入有效数字！" << endl;
			break;
		}
	}
