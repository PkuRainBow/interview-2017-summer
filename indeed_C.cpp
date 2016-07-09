#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fstream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;


void help_C(vector<vector<long long>>& p) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		p[i][i] = 0;
	for (int i = 0; i < n-1; i++) {
		p[i][i + 1] = 1;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);

	// process all the m cases
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		start--;
		end--;
		if (p[start][end] < INT_MAX)
			cout << p[start][end] << endl;
		else
			cout << -1 << endl;
		p[start][end] = 1;
		for (int k = 0; k < n; k++)
			for (int s = 0; s < n; s++)
				for (int t = 0; t < n; t++)
					p[s][t] = min(p[s][t], p[s][k] + p[k][t]);
	}
}

int main_c(){
	//freopen("indeed.in", "r", stdin);
	//freopen("indeed.out", "w", stdout);
	//int T;
	//cin >> T;
	//for (int i = 0; i < T; i++) {
	//	cout << "Case #" << i + 1 << ": ";
	//	vector<vector<long long>> p(200, vector<long long>(200, INT_MAX));
	//	help_C(p);
	//}
	vector<vector<long long>> p(200, vector<long long>(200, INT_MAX));
	help_C(p);
	return 0;
}