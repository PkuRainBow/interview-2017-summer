#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

void solver_gFiles() {
	long long lower = 0, upper = LLONG_MAX;
	int numStatus;
	cin >> numStatus;
	vector<int> percent(numStatus, 0);
	vector<long long> files(numStatus, 0);
	for (int i = 0; i < numStatus; i++) {
		cin >> percent[i] >> files[i];
		if (percent[i] < 100) {
			lower = max(lower, files[i] * 100 / (percent[i] + 1) + 1);
		}
		else {
			lower = max(lower, files[i] * 100 / (percent[i]));
		}
		if (percent[i] > 0) {
			upper = min(upper, files[i] * 100 / (percent[i]));
		}
	}

	cout << (lower == upper ? upper : -1LL) << endl;
	/** how to sovle it **/

}


int main_gFiles() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solver_gFiles();
	}
	return 0;
}