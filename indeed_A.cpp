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

void generate_all(string s, map<string, int>& result) {
	std::sort(s.begin(), s.end());
	do {
		string next = s;
		if (result.find(next) == result.end()) 
			result[s] = 0;
		else
			result[s]++;
	} while (std::next_permutation(s.begin(), s.end()));
}

void help_A(string cur, map<string, int>& result) {
	int len = cur.size();
	if (len == 0)
		return;
	for (int i = 0; i < len; i++) {
		// change one char 
		string next = cur;
		for (char ch = 'a'; ch <= 'd'; ch++) {
			next[i] = ch;
			generate_all(next, result);
		}
	}
	for (map<string, int>::iterator iterator = result.begin(); iterator != result.end(); iterator++) {
		cout << iterator->first << endl;
	}
	return;
}

int main_a(){
	freopen("indeed.in", "r", stdin);
	freopen("indeed.out", "w", stdout);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		map<string, int> result;
		cout << "Case #" << i + 1 << ": ";
		string str;
		cin >> str;
		help_A(str, result);
	}
	return 1;
}