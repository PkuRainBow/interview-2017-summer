//#include <iostream>
//#include <string>
//#include <cstdio>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <fstream>
//#include <cmath>
//#include <limits>
//#include <iomanip>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//long long p[200][200], q[200][200];
//
//struct edge {
//	long long u;
//	long long v;
//	long long c;
//};
//
//void solve() {
//	int n, m;
//	cout << endl;
//	vector<int> res;
//	cin >> n >> m;
//	vector<edge> v(m);
//	for (int i = 0; i < m; i ++) {
//		cin >> v[i].u >> v[i].v >> v[i].c;
//	}
//	for (int i = 0; i < n; i ++) {
//		for (int j = 0; j < n; j++) {
//			p[i][j] = LLONG_MAX;
//		}
//	}
//	for (int i = 0; i < n; i++)
//		p[i][i] = 0;
//	for (auto e : v) {
//		p[e.u][e.v] = min(p[e.u][e.v], e.c);
//		p[e.v][e.u] = min(p[e.v][e.u], e.c);
//	}
//	
//	for (int k = 0; k < n; k++)
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
//	int cnt = 0;
//	for (int i = 0; i < m; i++) {
//		if (p[v[i].u][v[i].v] < v[i].c) {
//			cnt++;
//			cout << i << endl;
//		}
//	}
//}
//
//int main_round_2016_a_c(){
//	freopen("C-small-practice.in", "r", stdin);
//	freopen("C-small-practice.out", "w", stdout);
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cout << "Case #" << i + 1 << ": ";
//		solve();
//	}
//	return 1;
//}