#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<Windows.h>
#if 0
using namespace std;
#define minsize 5
int flag = 0;
struct Zone
{
	int num;
	int size;
	int Starting_address;
	bool empty = 0;
};
void scanner(list<Zone>& mylist)
{
	mylist.clear();
	int n = 0;
	cout << "�����������" << endl;
	cin >> n;
	Zone a1;
	while (n--)
	{
		Zone a;
		cout << "��������š�������С������ʼַ" << endl;
		cin >> a.num >> a.size >> a.Starting_address;
		mylist.push_back(a);
	}
}
void display_mylist(list<Zone>& mylist)
{
	std::list<Zone>::iterator it1;
	cout << "������" << "\t������С" << "\t������ʼ��ַ" << "\t��������״̬" << endl;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		cout << (*it1).num << "\t\t" << (*it1).size << "\t\t" << (*it1).Starting_address;
		if ((*it1).empty == 0)
		{
			cout << "\t����" << endl;
		}
		else
		{
			cout << "\t�ѷ���" << endl;
		}
	}
}
void FF(list<Zone>& mylist, int size)
{
	std::list<Zone>::iterator it1,it2;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		if ((*it1).size >= size && (*it1).empty == 0)
		{
			(*it1).empty = 1;
			if ((*it1).size - size > minsize)
			{
				Zone p;
				p.empty = 0;
				p.num = (*it1).num;
				p.size = (*it1).size - size;
				p.Starting_address = (*it1).Starting_address + size;
				(*it1).size = size;
				it1++;
				mylist.insert(it1,p);
				display_mylist(mylist);
				cout << "�ɹ������ڴ�ռ�" << endl;
				
				return;
			}
		}
	}
	cout << "�ڴ�ռ��������޷�����ռ�" << endl;
}

void NF(list<Zone>& mylist, int size)
{
	int size1 = mylist.size();
	int num2 = flag;
	std::list<Zone>::iterator it1, it2;
	it1 = mylist.begin();
	num2 %= size1;
	while (num2--)
	{
		it1++;
	}
	for (int i = 0; i < size1;i++)
	{
		if (it1 != mylist.end()&& (*it1).size >= size && (*it1).empty == 0)
		{
			(*it1).empty = 1;
			if ((*it1).size - size > minsize)
			{
				Zone p;
				p.num = (*it1).num;
				p.empty = 0;
				p.size = (*it1).size - size;
				p.Starting_address = (*it1).Starting_address + size;
				(*it1).size = size;
			    it1++;
				mylist.insert(it1, p);
				display_mylist(mylist);
				cout << "�ɹ������ڴ�ռ�" << endl;
				flag += 2;
				return;
			}
		}
		it1++;
	}
	cout << "�ڴ�ռ��������޷�����ռ�" << endl;
}
void sizesort(list<Zone>& mylist)
{
	std::list<Zone>::iterator it1, it2;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		it1++;
		it2 = it1;
		it1--;
		for (; it2 != mylist.end(); it2++)
		{
			if ((*it1).size > (*it2).size)
			{
				swap(*it1, *it2);
			}
		}
		
	}
}

void BF(list<Zone>& mylist, int size)
{
	sizesort(mylist);
	std::list<Zone>::iterator it1, it2;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		if ((*it1).size >= size && (*it1).empty == 0)
		{
			(*it1).empty = 1;
			if ((*it1).size - size > minsize)
			{
				Zone p;
				p.num = (*it1).num;
				p.empty = 0;
				p.size = (*it1).size - size;
				p.Starting_address = (*it1).Starting_address + size;
				(*it1).size = size;
				it1++;
				mylist.insert(it1, p);
				display_mylist(mylist);
				cout << "�ɹ������ڴ�ռ�" << endl;
				(*it1).size = size;
				return;
			}
		}
	}
	cout << "�ڴ�ռ��������޷�����ռ�" << endl;
}
void sizecsort(list<Zone>& mylist)
{
	std::list<Zone>::iterator it1, it2,it3;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		it1++;
		it2 = it1;
		it1--;
		for (; it2 != mylist.end(); it2++)
		{
			if ((*it1).size < (*it2).size)
			{
				swap(*it1, *it2);
			}
		}
		
	}
}
void WF(list<Zone>& mylist, int size)
{
	sizecsort(mylist);
	std::list<Zone>::iterator it1, it2;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		if ((*it1).size >= size && (*it1).empty == 0)
		{
			(*it1).empty = 1;
			if ((*it1).size - size > minsize)
			{
				Zone p;
				p.num = (*it1).num;
				p.empty = 0;
				p.size = (*it1).size - size;
				p.Starting_address = (*it1).Starting_address + size;
				(*it1).size = size;
				it1++;
				mylist.insert(it1, p);
				display_mylist(mylist);
				cout << "�ɹ������ڴ�ռ�" << endl;
				return;
			}
		}
	}
	cout << "�ڴ�ռ��������޷�����ռ�" << endl;
}
void RecycleZone(list<Zone>& mylist, int S_address)
{
	std::list<Zone>::iterator it1, it2,it3;
	for (it1 = mylist.begin(); it1 != mylist.end(); it1++)
	{
		if ((*it1).Starting_address == S_address)
		{
			it2 = it1;
			it3 = it1;
			it2--;
			it3++;
			while ((*it2).empty != 0)
			{
				it2--;
			}
			while ((*it3).empty != 0)
			{
				it3++;
			}
			if ((*it2).Starting_address + (*it2).size >= (*it1).Starting_address
				&& (*it1).Starting_address >= (*it2).Starting_address
				&& (*it1).Starting_address + (*it1).size >= (*it3).Starting_address
				&& (*it3).Starting_address >= (*it1).Starting_address)
			{
				(*it2).size += (*it1).size + (*it2).size;
				mylist.erase(it1);
				mylist.erase(it3);
			}
			else
			{
				if ((*it2).Starting_address + (*it2).size >= (*it1).Starting_address
					&& (*it1).Starting_address >= (*it2).Starting_address)
				{
					(*it2).size += (*it1).size;
					mylist.erase(it1);
				}
				else if ((*it1).Starting_address + (*it1).size >= (*it3).Starting_address
					&& (*it3).Starting_address >= (*it1).Starting_address)
				{
					(*it1).size += (*it3).size;
					mylist.erase(it3);
				}
				else
				{
					(*it1).empty = 0;
				}
			}
		}
	}
	display_mylist(mylist);
}

void Algorithmcall(list<Zone>& mylist)
{
	int input;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t----------1.BF--------------------" << endl;
	cout << "\t\t\t----------2.FF--------------------" << endl;
	cout << "\t\t\t----------3.NF--------------------" << endl;
	cout << "\t\t\t----------4.WF--------------------" << endl;
	cout << "\t\t\t----------5.����-------------------" << endl;
	cout << "\t\t\t----------0.�˳�------------------" << endl;
	cout << "\t\t\t----------------------------------" << endl;
	do
	{
		cout << "\t\t\t���������ѡ��";
		cin >> input;
		int size = 0;
		switch (input)
		{
		case 0:
			break;
		case 1:
			cout << "��������̴�С" << endl;
			cin >> size;
			BF(mylist, size);
			break;
		case 2:
			cout << "��������̴�С" << endl;
			cin >> size;
			FF(mylist, size);
			break;
		case 3:
			cout << "��������̴�С" << endl;
			cin >> size;
			NF(mylist, size);
			break;
		case 4:
			cout << "��������̴�С" << endl;
			cin >> size;
			WF(mylist, size);
			break;
		case 5:
			cout << "������Ҫ���յĽ����׵�ַ" << endl;
			cin >> size;
			RecycleZone(mylist, size);
			break;
		default:
			cout << "�������" << endl;
		}
	} while (input);
}
void display(list<Zone>&mylist)
{
	int input;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t----------------------------------" << endl;
	cout << "\t\t\t----------1.������ز���----------" << endl;
	cout << "\t\t\t----------2.�㷨����--------------" << endl;
	cout << "\t\t\t----------0.�˳�------------------" << endl;
	cout << "\t\t\t----------------------------------" << endl;
	do
	{
		cout << "\t\t\t���������ѡ��";
		cin >> input;
		switch (input)
		{
		case 0:
			break;
		case 1:
			scanner(mylist);
			break;
		case 2:
			Algorithmcall(mylist);
			break;
		default:
			cout << "�������" << endl;
			break;
		}
	} while (input);
	
}

int main()
{
	list<Zone>mylist;
	display(mylist);
	system("pause");
	return 0;
}
#endif