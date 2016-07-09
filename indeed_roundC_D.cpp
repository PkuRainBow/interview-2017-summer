#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int size_n = 300010;
int cost[size_n];
int left_cost[size_n];
int right_cost[size_n];

int N;
string s;

void init_b(){
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		left_cost[i] = right_cost[i] = cost[i];
	}
		
	int left_min = left_cost[0];
	for (int i = 1; i < N; i++){
		left_min = min(left_min, left_cost[i]);
		left_cost[i] = left_min;
	}
	int right_min = right_cost[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		right_min = min(right_min, right_cost[i]);
		right_cost[i] = right_min;
	}
}

void solver_b() {
	cin >> N;
	cin >> s;
	N++;
	init_b();
	long long result = 0;
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			st.push(i);
		else {
			if (st.empty()) {
				result += left_cost[i];
			}
			else {
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		result += right_cost[cur + 1];
	}
	cout << result;
}

int main_b() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "case " << i << ":" << endl;
		solver_b();
		cout << endl;
	}
	return 0;
}


