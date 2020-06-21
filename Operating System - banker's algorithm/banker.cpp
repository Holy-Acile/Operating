#define  _CRT_SECURE_NO_WARNINGS 1
#include"banker.h"
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

void display()
{

	cout << "\n\n\n\n\n\n\n\t\t\t\t******************************************************" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                    操作系统                  ****" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                   银行家算法                 ****" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t******************************************************" << endl;
	//progress_bar();
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t欢迎" << endl;
	Sleep(1000);
	system("cls");

}
void menu()
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t******************************************************" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                   1.初始化                   ****" << endl;
	cout << "\t\t\t\t****                   2.请求资源                 ****" << endl;
	cout << "\t\t\t\t****                   3.安全性检测               ****" << endl;
	cout << "\t\t\t\t****                   4.显示资源分配             ****" << endl;
	cout << "\t\t\t\t****                   0.退出                     ****" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t******************************************************" << endl;
}
void test()
{
	banker bank;
	int i = 0;
	int input;
	display();
	do
	{
		menu();
		cout << "请输入你的选择：";
		cin >> input;
		switch (input)
		{
		case 0:
			break;
		case 1:
			system("cls");
			bank.init();
			break;
		case 2:
			system("cls");
			cout << "请输入要请求资源的进程" << endl;
			cin >> i;
			bank.Request(i);
			break;
		case 3:
			system("cls");
			bank.Safety_check();
			break;
		case 4:
			system("cls");
			bank.ResourceShow();
			break;
		default:
			system("cls");
			cout << "输入错误" << endl;
			break;
		}
	} while (input);
	
}