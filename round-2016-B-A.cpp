#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

const int INF = (int)1e9;
struct Point {
	int city;
	int cost[24];
};

vector<Point> E[510];
int T;
int n, m, q;
int d[510][24], inque[510][24], ans[24][510];

deque<pair<int, int>> que;

void solver_spfs(int t) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 24; j++) {
			d[i][j] = INF;
		}
	}

	que.push_back(make_pair(1, t));
	inque[1][t] = 1;
	d[1][t] = 0;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop_back();
		int u = cur.first, t = cur.second;
		inque[u][t] = false;

		for (int i = 0; i < (int)E[u].size(); i++) {
			int v = E[u][i].city, val = E[u][i].cost[t];
			int nxtT = (t + val) % 24;
			if (d[u][t] + val < d[v][nxtT]) {
				d[v][nxtT] = d[u][t] + val;
				if (!inque[v][nxtT]) {
					inque[v][nxtT] = true;
					que.push_back(make_pair(v, nxtT));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[t][i] = INF;
		for (int j = 0; j < 24; j++) {
			ans[t][i] = min(ans[t][i], d[i][j]);
		}
	}
}


int main_gTravel() {
	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solver_spfs(i);
	}
	return 0;
}