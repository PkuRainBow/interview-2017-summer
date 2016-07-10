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

int t, n;
string name[110];
string result;

int get_num(string str) {
	int cnt = 0;
	set<char> ss;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') continue;
		ss.insert(str[i]);
	}
	return ss.size();
}

void init() {
	cin >> n;
	int max_cnt = -1;
	getchar();
	for (int i = 0; i < n; i++){
		getline(cin, name[i]);
		bool letter[26] = { 0 };
		int letter_cnt = 0;
		for (auto it : name[i]) {
			if (it >= 'A' && it <= 'Z') {
				if (!letter[it - 'A']) {
					letter[it - 'A'] = true;
					letter_cnt++;
				}
			}
		}
		if (letter_cnt > max_cnt) {
			result = name[i];
			max_cnt = letter_cnt;
		}
		else if (max_cnt == letter_cnt) {
			result = min(result, name[i]);
		}
	}
	cout << result;
}


void solver_a() {
	init();
}

int main_a() {
	int file_choice = 2;
	if (file_choice == 0) {
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	else if (file_choice == 1) {
		freopen("A-small-attempt4.in", "r", stdin);
		freopen("A-small-practice.out", "w", stdout);
	}
	else {
		freopen("A-large.in", "r", stdin);
		freopen("A-large-practice.out", "w", stdout);
	}

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solver_a();
		cout << endl;
	}
	return 0;
}










