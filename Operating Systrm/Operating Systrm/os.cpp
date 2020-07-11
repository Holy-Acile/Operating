#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
#if 0
using namespace std;
struct Node {
	char name;
	int Tarrive;//到达时间
	int Tservice;//服务时间
	int Tsurplus;//剩余时间
	int Tstart;//开始时间
	int Taccomplish;//完成时间
	int prio;//优先级---数字越大优先级越高
	int if_finish;//进程是否完成
	int num;//进程个数
	int Tcycling;
	double AUT;
}job[10], help[10];
//按到达时间排
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
//按服务时间排序
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
//按优先级排序
void Priority_sort(int num)//按优先级减小排序
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
//如果到达时间相等，服务时间按从小到大排序
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
void fcfs(int num)//先来先服务
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
void sjf(int num)//短作业优先
{
	Arrive_Short_sort(num);
	job[0].Tstart = job[0].Tarrive;
	job[0].Taccomplish = job[0].Tservice + job[0].Tarrive;
	job[0].Tcycling = job[0].Taccomplish - job[0].Tarrive;
	job[0].AUT = job[0].Tcycling / (double)job[0].Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
		if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
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
void RR(int num)//RR算法
{
	int count = num;
	int q;
	cout << "请输入时间片长度：" << endl;
	cin >> q;
	int flag = 1;//标志队列中是否还有进程
	int finish_pro = 0;//完成的进程数
	cout << "----------------|---------------|---------------|---------------|---------------|" << endl;
	cout << " " << "进程名称\t" << "|" << "开始时间\t" << "|" << "运行时间\t" << "|" << "剩余服务时间\t" << "|" << "结束时间\t"<<"|" <<" "<< endl;
	for (int i = 0; i < num; i++)
	{
		help[i].name = job[i].name;
		help[i].Tservice = job[i].Tservice;
		help[i].Tarrive = INT_MAX;
	}
	int time;//记录当前时刻时间
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//就绪队列里没进程
		for (int i = c; i < num; i++)
		{
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			if (i - 1 >= 0)
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else if (i-1 >= 0)
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//该进程已完成
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//未完成且少于一个时间片
				{
					flag = 1;
					time += job[i].Tsurplus;
					job[i].if_finish = 1;//该进程完成
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
				if (job[i].if_finish == 1) finish_pro++;//一个进程完成加一
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//没执行完且没进入就绪队列
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
	cout << "进程名" << "\t\t" << "|" << "周转时间" << "\t" << "|" << "带权周转时间" << "\t" << "|"  << endl;
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
	cout << "平均周转时间" << "\t" << "|" << "平均带权周转时间"  << endl;
	cout << "----------------|---------------|" << endl;
	cout << sum1 / (double)count << "\t\t" << "|" << sum2 / (double)count <<"\t"<<"|"<< endl;
	cout << "----------------|---------------|" << endl;
}
//输出
void print(int num)
{
	double sum1 = 0;
	double sum2 = 0;
	cout << "进程名" << "\t" << "开始时间" << "\t" << "服务时间" << "\t" << "完成时间" << "\t" << "周转时间" << "\t";
	cout << "带权周转时间" << "\t" << "平均周转时间" << "\t" << "平均带权周转时间" << endl;

	for (int i = 0; i < num; i++)
	{
		sum1 += job[i].Tcycling;
		sum2 += job[i].AUT;
		cout << job[i].name << "\t" << job[i].Tstart << "\t\t" << job[i].Tservice << "\t\t" << job[i].Taccomplish<<"\t\t";
		cout << job[i].Tcycling << "\t\t" << job[i].AUT << "\t\t" << sum1 / (double)(i + 1) << "\t\t" << sum2 / (double)(i + 1) << endl;
	}
}
void printfend()//结束界面
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
	cout << "\t\t\t\t\t\t| 感谢使用 |" << endl;
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
	cout << "\t\t\t\t|—————————————————————————|" << endl;
	cout << "\t\t\t\t|——————————1、FCFS算法 —————————|" << endl;
	cout << "\t\t\t\t|——————————2、SJF算法——————————|" << endl;
	cout << "\t\t\t\t|——————————3、RR算法 ——————————|" << endl;
	cout << "\t\t\t\t|——————————4、优先级算法 ————————|" << endl;
	cout << "\t\t\t\t|——————————5、退出 ———————————|" << endl;
	cout << "\t\t\t\t|—————————————————————————|" << endl;
	do {
		cout << "请选择你想要的算法：" << endl;
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
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	} while (ch != 5);
}
void progress_bar()//进度条
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
	cout << "\t\t\t\t\t\t| 欢迎使用 |" << endl;
	cout << "\t\t\t\t\t\t|----------|" << endl;
	progress_bar();
	system("cls");
	cout << "请输入进程个数：" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "请输入进程名、到达时间、服务时间、优先级" << endl;
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
