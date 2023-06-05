#include <iostream>

using namespace std;

void control_work2(int N, int K, int y_Petya, int x_Petya)
{
	int pos_Petya = (y_Petya - 1) * 2 + x_Petya;
	//cout << "pos_Petya: " << pos_Petya << endl;
	//int var_Petya = pos_Petya % K;

	int pos_Vasya_1 = pos_Petya + K; //cout << pos_Vasya_1 << endl;
	int pos_Vasya_2 = pos_Petya - K; //cout << pos_Vasya_2 << endl;

	if (pos_Vasya_1 <= N)
	{
		int y_Vasya_1 = (pos_Vasya_1 + 1) / 2;
		int x_Vasya_1 = (pos_Vasya_1 % 2) ? 1 : 2;
		cout << y_Vasya_1 << ' ' << x_Vasya_1 << endl;
	}
	else if (pos_Vasya_2 > 0)
	{
		int y_Vasya_2 = (pos_Vasya_2 + 1) / 2;
		int x_Vasya_2 = (pos_Vasya_2 % 2) ? 1 : 2;
		cout << y_Vasya_2 << ' ' << x_Vasya_2 << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

void control_work(int N, int K, int y_Petya, int x_Petya)
{
	int pos_Petya = (y_Petya - 1) * 2 + x_Petya;
	cerr << "pos_Petya: " << pos_Petya << endl;

	int pos_Vasya_1 = pos_Petya + K; cerr << "pos_Vasya_1: " << pos_Vasya_1 << endl;
	int pos_Vasya_2 = pos_Petya - K; cerr << "pos_Vasya_2: " << pos_Vasya_2 << endl;

	if (pos_Vasya_1 <= N || pos_Vasya_2 > 0)
	{
		int count_of_table = (N - 1) / 2 + 1;
		int y_Vasya = -1;
		int x_Vasya = -1;

		if (pos_Vasya_1 <= N)
		{
			y_Vasya = (pos_Vasya_1 + 1) / 2;
			x_Vasya = (pos_Vasya_1 + 1) % 2 + 1;
			cerr << y_Vasya << ' ' << x_Vasya << " count_of_table: " << y_Vasya - y_Petya << endl;
			count_of_table = y_Vasya - y_Petya;
		}
		if (pos_Vasya_2 > 0)
		{
			int y_Vasya_2 = (pos_Vasya_2 + 1) / 2;
			int x_Vasya_2 = (pos_Vasya_2 + 1) % 2 + 1;
			cerr << y_Vasya_2 << ' ' << x_Vasya_2 << " count_of_table: " << y_Petya - y_Vasya_2 << endl;
			if (count_of_table > y_Petya - y_Vasya_2)
			{
				y_Vasya = y_Vasya_2;
				x_Vasya = x_Vasya_2;
			}
		}
		cout << y_Vasya << ' ' << x_Vasya << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}


int test_control_work()
{
	/*//Test 0
	int N; cin >> N;
	int K; cin >> K;
	int y, x;
	cin >> y; cin >> x;
	//*/

	/*//Test 1
	int N = 25;
	int K = 2;
	int y = 1, x = 2;
	// expected 2 2
	//*/ 

	//Test 2
	int N = 25;
	int K = 13;
	int y = 7, x = 1;
	// expected -1
	//*/

	/*//Test 4
	int N = 11;
	int K = 5;
	int y = 3, x = 2;
	// expected -1
	//*/



	control_work(N, K, y, x);

	return 0;
}