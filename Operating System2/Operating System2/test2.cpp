#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 640
enum status { FREE, BUSY };

typedef struct freespace
{
	int num;         //������
	int size;        //������С
	int address;     //�����׵�ַ
	status state;    //����״̬��FREE��BUSY
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
	cout << "****************���ڴ�������****************" << endl;
	node *p = first->next;
	while (p)
	{
		cout << "�����ţ�";
		if (p->data.num == 0)
		{
			cout << "������" << "  " << "��ʼ��ַ��" << p->data.address << "	" << "��ֹ��ַ��" << p->data.address + p->data.size <<
				"	" << "������С��" <<
				p->data.size << "KB" << "	" << "״̬:����" << endl;
		}
		else
		{
			cout << p->data.num;
			cout << "	" << "��ʼ��ַ��" << p->data.address << "	" << "��ֹ��ַ��" << p->data.address + p->data.size << "	"
				"������С��" << p->data.size
				<< "KB" << "	" << "״̬:";
			if (p->data.state == FREE)
				cout << "����" << endl;
			else if (p->data.state == BUSY)
				cout << "ռ��" << endl;
		}
		p = p->next;
	}
	cout << "**********************************************" << endl << endl;
}

int firstAlloc()//�״η���
{
	int num, size;
	cout << "��������ҵ�źͷ���������СKB��" << endl;;
	cin >> num >> size;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	while (p)
	{
		if (p->data.state == FREE&&p->data.size == size)//�д�С�պú��ʵĿ��п�
		{
			p->data.state = BUSY;
			p->data.num = num;
			display();
			return 1;
		}
		if (p->data.state == FREE&&p->data.size > size)//�д�С������Ŀ��п�
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

int bestAlloc()//��ѷ���
{
	int num, size;
	cout << "��������ҵ�źͷ���������СKB��" << endl;
	cin >> num >> size;
	int min_space = MAXSIZE;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
��	node *q = NULL;
	while (p)//�ҵ����λ��
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
int worstAlloc()//��ѷ���
{
	int num, size;
	cout << "��������ҵ�źͷ���������СKB��" << endl;;
	cin >> num >> size;
	int min_space = MAXSIZE;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	node *q = NULL;
	while (p)//�ҵ����λ��
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

int recycle()//��Ƭ����
{
	int num;
	cout << "��������Ҫ�����ڴ����ҵ�ţ�" << endl;
	cin >> num;
	node *p = first;
	while (p)
	{
		if (p->data.num == num)
		{
			p->data.state = FREE;
			p->data.num = 0;
			if (p->head->data.state == FREE)//��ǰһ����������ڣ���ϲ�
			{
				p->head->data.size += p->data.size;
				p->head->next = p->next;
				p->next->head = p->head;
			}
			if (p->next->data.state == FREE)//���һ����������ڣ���ϲ�
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
	cout << "********************�ڴ����ϵͳ********************" << endl;
	cout << "*              1.�״���Ӧ�㷨�����ڴ�              *" << endl;
	cout << "*              2.ѭ����Ӧ�㷨�����ڴ�              *" << endl;
	cout << "*              3.�����Ӧ�㷨�����ڴ�              *" << endl;
	cout << "*              4.���Ӧ�㷨�����ڴ�              *" << endl;
	cout << "*              5.�鿴����������                  *" << endl;
	cout << "*              6.��������                          *" << endl;
	cout << "*              7.����                              *" << endl;
	cout << "****************************************************" << endl;
	cout << "��ѡ��" << endl;
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
			cout << "��������Ч���֣�" << endl;
			break;
		}
	}
