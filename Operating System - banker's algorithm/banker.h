#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

class banker
{
public:

	void init()
	{
		Max.clear();
		Allocation.clear();
		Need.clear();
		Avai.clear();
		work.clear();
		Finish.clear();
		xulie.clear();
		request.clear();
		int sum;
		cout << "请输入资源个数和进程数" << endl;
		cin >> m >> n;
		cout << "请输入各个资源数" << endl;
		for (int i = 0; i < m; i++)
		{
			cin >> sum;
			Avai.push_back(sum);
			
		}
		cout << "请输入各个进程对资源的最大需求" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入进程" << i << ":";
			vector<int> max;
			int sum;
			for (int j = 0; j < m; j++)
			{
				cin >> sum;
				max.push_back(sum);
			}
			Max.push_back(max);
		}
		cout << "请输入各个进程已分配的资源" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入进程" << i << ":";
			vector<int> allo;
			int sum;
			for (int j = 0; j < m; j++)
			{
				cin >> sum;
				allo.push_back(sum);
			}
			Allocation.push_back(allo);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Avai[j] -= Allocation[i][j];
			}
		}
		for (int j = 0; j < m; j++)
		{
			work.push_back(Avai[j]);
		}
		Need.resize(n);
		for (int i = 0; i < n; i++)
		{
			Need[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				Need[i][j] = Max[i][j] - Allocation[i][j];
			}
		}
		Finish.resize(n);
		for (int i = 0; i < n; i++)
		{
			Finish[i] = false;
		}
		xulie.resize(n);
		for (int j = 0; j < m; j++)
		{
			if (Avai[j] < 0)
			{
				cout << "初始化数据有问题" << endl;
				return;
			}
		}
	}
	bool Safety_check()
	{
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			Finish[i] = false;
		}
		int flag = 1;
		int count = 0;
		int returnf = 0;
		while (count != n)
		{
			for (int i = 0; i < n; i++)
			{
				if (!Finish[i])
				{
					for (int j = 0; j < m; j++)
					{

						if (Need[i][j] > work[j])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
					{
						Finish[i] = true;
						for (int j = 0; j < m; j++)
						{
							work[j] += Allocation[i][j];

						}
						xulie[x] = i;
						count++;
						returnf = 1;
						x++;
						break;
					}
					flag = 1;
				}


			}
			if (returnf == 0)
			{
				cout << "不安全" << endl;
				return false;
			}
			returnf = 0;
		}
		cout << "安全" << endl;
		cout << "安全序列" << endl;
		for (int i = 0; i < xulie.size(); i++)
		{
			cout << xulie[i] << ' ';
		}
		return true;
	}
	void Request(int i)
	{


		request.clear();
		int num = 0;
		cout << "请输入请求资源数" << endl;

		for (int j = 0; j < m; j++)
		{
			int sum;

			cin >> sum;
			request.push_back(sum);

		}
		for (int j = 0; j < m; j++)
		{
			if (request[j] == Need[i][j])
			{
				num++;
			}
			if (request[j] > Need[i][j])
			{
				cout << "所需资源已超过所宣布的资源的最大值" << endl;
				return;
			}
		
		}
		for (int j = 0; j < m; j++)
		{
			 if (request[j] > Avai[j])
			{
				cout << "资源不足" << endl;
				return;
			}
		}


	for (int j = 0; j < m; j++)
	{
		Avai[j] -= request[j];
		Allocation[i][j] += request[j];
		Need[i][j] -= request[j];
		work[j] = Avai[j];
	}
	if (Safety_check())
	{
		
		cout << endl;
		cout << "分配成功" << endl;
		if (m == num)
		{
			
				for (int j = 0; j < m; j++)
					Avai[j] += Allocation[i][j];

		}
		return;
	}
	else
	{
		cout << "不安全" << endl;
		for (int j = 0; j < m; j++)
		{
			Avai[j] += request[j];
			Allocation[i][j] -= request[j];
			Need[i][j] += request[j];
		}

	}
}
void ResourceShow()
{
		cout << "进程" <<" "<<"\tMax"<< "\tNeed" << "\tAllocation" << "\tFinish" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "p" << i<<"\t";
			for (int j = 0; j < m; j++)
			{
				cout << " " << Max[i][j];
			}
			for (int j = 0; j < m; j++)
			{
				cout << " " << Need[i][j];
			}
			cout << "\t";
			for (int j = 0; j < m; j++)
			{


				cout << " " << Allocation[i][j];
			}
			cout <<"\t\t"<< Finish[i] << endl;
		}
		cout << "Available" << ":";
		for (int j = 0; j < m; j++)
		{
			cout << " " << Avai[j];
		}
		cout << endl;
}
private:
	vector<vector<int>>Max;
	vector<vector<int>>Allocation;
	vector<vector<int>>Need;
	vector<int>Avai;
	vector<int>work;
	vector<bool>Finish;
	vector<int>xulie;
	vector<int>request;
	int n;
	int m;
};
void progress_bar();
void display();
void menu();
void test();


