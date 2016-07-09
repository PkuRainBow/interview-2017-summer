#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

const int MAX_N = 1000;
long long cuboid[MAX_N];

int main_round_2016_a_b() {
	std::ifstream in("B-large-practice.in");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("B-large-practice.out");
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	int T = 0;
	int M = 0, N = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cout << "Case #" << t + 1 << ":" << endl;
		cin >> N >> M;
		for (int n = 0; n < N; n++)
		{
			cin >> cuboid[n];
		}
		for (int m = 0; m < M; m++)
		{
			int start = 0, end = 0;
			long double volume = 1;
			cin >> start >> end;
			for (int i = start; i <= end; i++)
			{
				volume *= cuboid[i];
			}
			long double power_index = 1 / (double)(end - start + 1);
			cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << long double(pow(volume, power_index)) << endl;
		}
	}
	return 1;
}