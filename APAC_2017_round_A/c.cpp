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

double rate = 0;
const double precision = 1e-15;

int m;
long long cost[101];

double month_cal(int k) {
	return (cost[k] * 1.0 / cost[0]) * pow((1 + rate), -k);
}

void binary() {
	double left = -1, right = 1; 
	while (left < right && (right - left) >= precision) {
		rate = (left + right) / 2;
		double sum = 0;
		for (int i = 1; i < m; i++) sum += month_cal(i);
		if (sum >= 1 + precision) {
			left = rate;
		}
		else if (sum <= 1 - precision) {
			right = rate;
		}
		else break;
	}
	printf("%.15lf", rate);
	return;
}


void solver_c() {
	cin >> m;
	m++;
	for (int i = 0; i < m; i++) cin >> cost[i];
	binary();
}

int main_c() {
	int file_choice = 2;
	if (file_choice == 0) {
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	else if (file_choice == 1) {
		freopen("C-small-attempt0.in", "r", stdin);
		freopen("C-small-practice.out", "w", stdout);
	}
	else {
		freopen("C-large.in", "r", stdin);
		freopen("C-large-practice.out", "w", stdout);
	}

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solver_c();
		cout << endl;
	}
	return 0;
}










