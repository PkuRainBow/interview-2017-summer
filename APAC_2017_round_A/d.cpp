#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <set>
#include <map> 
using namespace std;

int coin_cnt, card_cnt;
int attack[12][11];
int level[12][11];
int cost[12][11];
int acc_cost[12][11][11];
int cur_level[12];
int max_level[12];

int value[350];
int price[350];
int cnt = 0;
int max_val = 0;
long long dp[500][1000];

void init_d(){
	cnt = 0;
	memset(acc_cost, 0, 12 * 11 * 11);
	memset(cost, 0, 12 * 11);
	memset(cur_level, 0, 12);
	memset(max_level, 0, 12);
	memset(level, 0, 12 * 11);
	memset(attack, 0, 12 * 11);

	cin >> coin_cnt >> card_cnt;
	for (int i = 1; i <= card_cnt; i++) {
		cin >> max_level[i] >> cur_level[i];
		for (int j = 1; j < max_level[i]; j++) {
			cin >> attack[i][j];
		}
		for (int j = 1; j <= max_level[i] - 1; j++) {
			cin >> cost[i][j];
			acc_cost[i][j][j + 1] = cost[j][i];
			acc_cost[i][j][j] = 0;
		}
		for (int ii = 1; ii < max_level[i]; ii++) {
			for (int jj = ii; jj <= max_level[i]; jj++) {
				acc_cost[i][ii][jj] = acc_cost[i][ii][jj - 1] + acc_cost[i][jj - 1][jj];
				value[cnt] = attack[i][jj] - attack[i][ii];
				price[cnt] = acc_cost[i][ii][jj];
				max_val = max(max_val, value[cnt]);
				cnt++;
			}
		}
	}
}


void solver_d() {
	init_d();
	fill(dp[0], dp[0] + cnt * max_val + 1, LONG_MAX);
	dp[0][0] = 0; 
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j <= cnt * max_val; j++) {
			if (j < value[i]) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = min(dp[i][j], dp[i][j - value[i]] + price[i]);
			}
		}
	}
	long long result = 0;
	for (int i = 0; i < cnt * max_val; i++) if (dp[cnt][i] <= coin_cnt) result = i;
	cout << result;
}

int main() {
	int file_choice = 0;
	if (file_choice == 0) {
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	else if (file_choice == 1) {
		freopen("D-small-attempt0.in", "r", stdin);
		freopen("D-small-practice.out", "w", stdout);
	}
	else {
		freopen("D-large.in", "r", stdin);
		freopen("D-large-practice.out", "w", stdout);
	}

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solver_d();
		cout << endl;
	}
	return 0;
}

