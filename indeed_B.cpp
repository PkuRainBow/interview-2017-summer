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
#include <map>

using namespace std;

string move_next(string str) {
	string next = str;
	int steps = (str[0] - '0') - 1;
	for (int i = 0; i < steps; i++) {
		next[i] = next[i + 1];
	}
	next[steps] = '1' + steps;
	return next;
}

void help_B() {
	string str;
	long long m;
	long long pre_index, move_steps, next_index, index;
	map<string, long> dict;

	cin >> str >> m;
	if (str[0] == '1') {
		cout << str << endl;
		return;
	}
	if (m == 0) {
		cout << str << endl;
		return;
	}
	string cur = str;
	vector<string> pre_list;
	pre_list.push_back(cur);

	dict[cur] = 0;
	for (long long i = 1; i <= m; i++) {
		cur = move_next(cur);
		if (dict.find(cur) != dict.end()) {
			pre_index = dict[cur];
			move_steps = i - pre_index;
			next_index = m - i;
			index = next_index % move_steps;
			cout << pre_list[pre_index + index] << endl;
			return;
		}
		dict[cur] = i;
		pre_list.push_back(cur);
		if (cur[0] == '1') {
			cout << cur << endl;
			return;
		}
	}
	cout << cur << endl;
}

int main_b(){
	//freopen("indeed.in", "r", stdin);
	//freopen("indeed.out", "w", stdout);
	//int T;
	//cin >> T;
	//for (int i = 0; i < T; i++) {
	//	cout << "Case #" << i + 1 << ": ";
	//	help_B();
	//}
	help_B();
	return 0;
}
