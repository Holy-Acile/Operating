#define  _CRT_SECURE_NO_WARNINGS 1
#include"banker.h"
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

void display()
{

	cout << "\n\n\n\n\n\n\n\t\t\t\t******************************************************" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                    ����ϵͳ                  ****" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                   ���м��㷨                 ****" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t******************************************************" << endl;
	//progress_bar();
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t��ӭ" << endl;
	Sleep(1000);
	system("cls");

}
void menu()
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t******************************************************" << endl;
	cout << "\t\t\t\t****                                              ****" << endl;
	cout << "\t\t\t\t****                   1.��ʼ��                   ****" << endl;
	cout << "\t\t\t\t****                   2.������Դ                 ****" << endl;
	cout << "\t\t\t\t****                   3.��ȫ�Լ��               ****" << endl;
	cout << "\t\t\t\t****                   4.��ʾ��Դ����             ****" << endl;
	cout << "\t\t\t\t****                   0.�˳�                     ****" << endl;
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
		cout << "���������ѡ��";
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
			cout << "������Ҫ������Դ�Ľ���" << endl;
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
			cout << "�������" << endl;
			break;
		}
	} while (input);
	
}