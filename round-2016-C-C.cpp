#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> friends;
int prohibiteed[16][16];
int occupied[5][16];

bool dfs(int num) {
	if (num == (1 << n))
		return true;
	int pos = 0;
	while (pos < (1 << n)) {

	}
}
void solver_gGame(int casenum) {
	
	cout << "Case #" << casenum << ": " << result << endl;
}


int main_gGames() {
	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solver_gGame(i);
	}
	return 0;
}