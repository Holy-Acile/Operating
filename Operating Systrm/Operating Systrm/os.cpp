#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
#if 0
using namespace std;
struct Node {
	char name;
	int Tarrive;//����ʱ��
	int Tservice;//����ʱ��
	int Tsurplus;//ʣ��ʱ��
	int Tstart;//��ʼʱ��
	int Taccomplish;//���ʱ��
	int prio;//���ȼ�---����Խ�����ȼ�Խ��
	int if_finish;//�����Ƿ����
	int num;//���̸���
	int Tcycling;
	double AUT;
}job[10], help[10];
//������ʱ����
void Arrive_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//������ʱ������
void Service_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//�����ȼ�����
void Priority_sort(int num)//�����ȼ���С����
{
	int temp1, temp2, temp3, temp4;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
}
void Priority_sort1(int num)
{
	Priority_sort(num);
	job[0].Tstart = job[0].Tarrive;
	job[0].Taccomplish = job[0].Tservice + job[0].Tarrive;
	job[0].Tcycling = job[0].Taccomplish - job[0].Tarrive;
	job[0].AUT = job[0].Tcycling / (double)job[0].Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
		job[i].Tcycling = job[i].Taccomplish - job[i].Tarrive;
		job[i].AUT = job[i].Tcycling / (double)job[i].Tservice;
	}
}
//�������ʱ����ȣ�����ʱ�䰴��С��������
void Arrive_Short_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive >= job[j].Tarrive)
			{
				if (job[i].Tarrive > job[j].Tarrive)
				{
					temp1 = job[j].name;
					job[j].name = job[i].name;
					job[i].name = temp1;
					temp2 = job[j].Tarrive;
					job[j].Tarrive = job[i].Tarrive;
					job[i].Tarrive = temp2;
					temp3 = job[j].Tservice;
					job[j].Tservice = job[i].Tservice;
					job[i].Tservice = temp3;
				}
				else
				{
					if (job[i].Tservice > job[j].Tservice)
					{
						temp1 = job[j].name;
						job[j].name = job[i].name;
						job[i].name = temp1;
						temp2 = job[j].Tarrive;
						job[j].Tarrive = job[i].Tarrive;
						job[i].Tarrive = temp2;
						temp3 = job[j].Tservice;
						job[j].Tservice = job[i].Tservice;
						job[i].Tservice = temp3;
					}
				}
			}
		}
	}
}
void fcfs(int num)//�����ȷ���
{
	job[0].Tstart = job[0].Tarrive;
	job[0].Taccomplish = job[0].Tservice + job[0].Tarrive;
	job[0].Tcycling = job[0].Taccomplish - job[0].Tarrive;
	job[0].AUT = job[0].Tcycling / (double)job[0].Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
		job[i].Tcycling = job[i].Taccomplish - job[i].Tarrive;
		job[i].AUT = job[i].Tcycling / (double)job[i].Tservice;
	}

}
void sjf(int num)//����ҵ����
{
	Arrive_Short_sort(num);
	job[0].Tstart = job[0].Tarrive;
	job[0].Taccomplish = job[0].Tservice + job[0].Tarrive;
	job[0].Tcycling = job[0].Taccomplish - job[0].Tarrive;
	job[0].AUT = job[0].Tcycling / (double)job[0].Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
		if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
		job[i].Tcycling = job[i].Taccomplish - job[i].Tarrive;
		job[i].AUT = job[i].Tcycling / (double)job[i].Tservice;
	}
}
void RR(int num)//RR�㷨
{
	int count = num;
	int q;
	cout << "������ʱ��Ƭ���ȣ�" << endl;
	cin >> q;
	int flag = 1;//��־�������Ƿ��н���
	int finish_pro = 0;//��ɵĽ�����
	cout << "----------------|---------------|---------------|---------------|---------------|" << endl;
	cout << " " << "��������\t" << "|" << "��ʼʱ��\t" << "|" << "����ʱ��\t" << "|" << "ʣ�����ʱ��\t" << "|" << "����ʱ��\t"<<"|" <<" "<< endl;
	for (int i = 0; i < num; i++)
	{
		help[i].name = job[i].name;
		help[i].Tservice = job[i].Tservice;
		help[i].Tarrive = INT_MAX;
	}
	int time;//��¼��ǰʱ��ʱ��
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//����������û����
		for (int i = c; i < num; i++)
		{
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			if (i - 1 >= 0)
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else if (i-1 >= 0)
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//�ý��������
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//δ���������һ��ʱ��Ƭ
				{
					flag = 1;
					time += job[i].Tsurplus;
					job[i].if_finish = 1;//�ý������
					job[i].Taccomplish = time;
					cout << "----------------|---------------|---------------|---------------|---------------|" << endl;
					cout << job[i].name << "\t\t" << "|" << job[i].Taccomplish - job[i].Tsurplus << "\t\t" << "|" << job[i].Tsurplus << "\t\t" << "|" << 0 << "\t\t" << "|" << job[i].Taccomplish << "\t\t" << "|" << endl;
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					cout << "----------------|---------------|---------------|---------------|---------------|" << endl;
					cout << job[i].name << "\t\t" << "|" << time - q << "\t\t" << "|" << q << "\t\t" << "|" << job[i].Tsurplus << "\t\t" << "|" << job[i].Taccomplish << "\t\t" << "|" << endl;
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//һ��������ɼ�һ
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//ûִ������û�����������
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
	int i = 0;
	int j = 0;
	int x = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (job[i].name == help[j].name)
			{
				if (job[i].Taccomplish > help[j].Taccomplish)
				{
					help[j].Taccomplish = job[i].Taccomplish;
				}
				if (job[i].Tarrive < help[j].Tarrive)
				{
					help[j].Tarrive = job[i].Tarrive;
				}
			}
		}
	}
	double sum1 = 0;
	double sum2 = 0;
	cout << "----------------|---------------|---------------|---------------|---------------|" << endl;
	cout << "������" << "\t\t" << "|" << "��תʱ��" << "\t" << "|" << "��Ȩ��תʱ��" << "\t" << "|"  << endl;
	for (int i = 0; i < count; i++)
	{
		help[i].Tcycling = help[i].Taccomplish - help[i].Tarrive;
		help[i].AUT = help[i].Tcycling / (double)help[i].Tservice;
		sum1 += help[i].Tcycling;
		sum2 += help[i].AUT;
		cout << "----------------|---------------|---------------|" << endl;
		cout << help[i].name << "\t\t" << "|" << help[i].Tcycling << "\t\t" << "|" << help[i].AUT << "\t" << "|" << endl;
	}
	cout << "----------------|---------------|---------------|" << endl;
	cout << "ƽ����תʱ��" << "\t" << "|" << "ƽ����Ȩ��תʱ��"  << endl;
	cout << "----------------|---------------|" << endl;
	cout << sum1 / (double)count << "\t\t" << "|" << sum2 / (double)count <<"\t"<<"|"<< endl;
	cout << "----------------|---------------|" << endl;
}
//���
void print(int num)
{
	double sum1 = 0;
	double sum2 = 0;
	cout << "������" << "\t" << "��ʼʱ��" << "\t" << "����ʱ��" << "\t" << "���ʱ��" << "\t" << "��תʱ��" << "\t";
	cout << "��Ȩ��תʱ��" << "\t" << "ƽ����תʱ��" << "\t" << "ƽ����Ȩ��תʱ��" << endl;

	for (int i = 0; i < num; i++)
	{
		sum1 += job[i].Tcycling;
		sum2 += job[i].AUT;
		cout << job[i].name << "\t" << job[i].Tstart << "\t\t" << job[i].Tservice << "\t\t" << job[i].Taccomplish<<"\t\t";
		cout << job[i].Tcycling << "\t\t" << job[i].AUT << "\t\t" << sum1 / (double)(i + 1) << "\t\t" << sum2 / (double)(i + 1) << endl;
	}
}
void printfend()//��������
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t|----------|" << endl;
	cout << "\t\t\t\t\t\t| ��лʹ�� |" << endl;
	cout << "\t\t\t\t\t\t|----------|" << endl;
	Sleep(1000);
}
void display(int num)
{
	int ch = 0;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t|��������������������������������������������������|" << endl;
	cout << "\t\t\t\t|��������������������1��FCFS�㷨 ������������������|" << endl;
	cout << "\t\t\t\t|��������������������2��SJF�㷨��������������������|" << endl;
	cout << "\t\t\t\t|��������������������3��RR�㷨 ��������������������|" << endl;
	cout << "\t\t\t\t|��������������������4�����ȼ��㷨 ����������������|" << endl;
	cout << "\t\t\t\t|��������������������5���˳� ����������������������|" << endl;
	cout << "\t\t\t\t|��������������������������������������������������|" << endl;
	do {
		cout << "��ѡ������Ҫ���㷨��" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			system("cls");
			Arrive_sort(num);
			fcfs(num);
			print(num);
			break;
		case 2:
			//Arrive_Short_sort(num);
			system("cls");
			sjf(num);
			print(num);
			break;
		case 3:
			system("cls");
			RR(num);
			break;
		case 4:
			system("cls");
			Priority_sort1(num);
			print(num);
			break;
		case 5:
			system("cls");
			printfend();
			exit;
		default:
			system("cls");
			cout << "����������������룡" << endl;
			break;
		}
	} while (ch != 5);
}
void progress_bar()//������
{
	int i = 0;
	char bar[102];
	memset(bar, 0, sizeof(bar));
	const char *lable = "|/-\\";
	while (i <= 100){
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i % 4]);
		fflush(stdout);
		bar[i++] = '#';
		Sleep(100);
	}
	printf("\n");
}
int main()
{
	int num;
	char jname;
	int arrive;
	int service;
	int accomplish;
	int prior;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t|----------|" << endl;
	cout << "\t\t\t\t\t\t| ��ӭʹ�� |" << endl;
	cout << "\t\t\t\t\t\t|----------|" << endl;
	progress_bar();
	system("cls");
	cout << "��������̸�����" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "�����������������ʱ�䡢����ʱ�䡢���ȼ�" << endl;
		cin >> jname;
		job[i].name = jname;
		cin >> arrive;
		job[i].Tarrive = arrive;
		cin >> service;
		job[i].Tservice = service;
		cin >> prior;
		job[i].prio = prior;
	}
	system("cls");
	display(num);
	return 0;
}
#endif
