#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

const int max_size = 21;
int init_state[max_size][max_size];

void move(int n, string op) {
	if (op == "up") {
		for (int col = 0; col < n; col++) {
			int p1 = 0, p2 = 1;
			while (p1 < n && p2 < n) {
				while (p2 < n && init_state[p2][col] == 0) {
					p2++;
				}
				if (p2 >= n) break;
				if (init_state[p1][col] == init_state[p2][col]) {
					init_state[p1][col] *= 2;
					init_state[p2][col] = 0;
					p1 = p2 + 1;
					p2 = p1 + 1;
				}
				else {
					p1 = p2;
					p2 = p2 + 1;
				}
			}
			//skip all the 0
			int start = 0;
			for (int i = 0; i < n; i++) {
				if (init_state[i][col] != 0) {
					init_state[start][col] = init_state[i][col];
					start++;
				}
			}
			for (int i = start; i < n; i++) {
				init_state[i][col] = 0;
			}
		}
	}
	else if (op == "down") {
		for (int col = 0; col < n; col++) {
			int p1 = n-1, p2 = n-2;
			while (p1 >= 0 && p2 >= 0) {
				while (p2 >= 0 && init_state[p2][col] == 0) {
					p2--;
				}
				if (p2 < 0) break;
				if (init_state[p1][col] == init_state[p2][col]) {
					init_state[p1][col] *= 2;
					init_state[p2][col] = 0;
					p1 = p2 - 1;
					p2 = p1 - 1;
				}
				else {
					p1 = p2;
					p2 = p2 - 1;
				}
			}
			//skip all the 0
			int start = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (init_state[i][col] != 0) {
					init_state[start][col] = init_state[i][col];
					start--;
				}
			}
			for (int i = start; i >= 0; i--) {
				init_state[i][col] = 0;
			}
		}
	}
	else if (op == "left") {
		for (int row = 0; row < n; row++) {
			int p1 = 0, p2 = 1;
			while (p1 < n && p2 < n) {
				while (p2 < n && init_state[row][p2] == 0) {
					p2++;
				}
				if (p2 >= n) break;
				if (init_state[row][p1] == init_state[row][p2]) {
					init_state[row][p1] *= 2;
					init_state[row][p2] = 0;
					p1 = p2 + 1;
					p2 = p1 + 1;
				}
				else {
					p1 = p2;
					p2 = p2 + 1;
				}
			}
			//skip all the 0
			int start = 0;
			for (int i = 0; i < n; i++) {
				if (init_state[row][i] != 0) {
					init_state[row][start] = init_state[row][i];
					start++;
				}
			}
			for (int i = start; i < n; i++) {
				init_state[row][i] = 0;
			}
		}
	}
	else {
		for (int row = 0; row < n; row++) {
			int p1 = n-1, p2 = n-2;
			while (p1 >= 0 && p2 >= 0) {
				while (p2 >= 0 && init_state[row][p2] == 0) {
					p2--;
				}
				if (p2 >= 0 && (init_state[row][p1] == init_state[row][p2])) {
					init_state[row][p1] *= 2;
					init_state[row][p2] = 0;
					p1 = p2 - 1;
					p2 = p1 - 1;
				}
				else {
					p1 = p2;
					p2 = p2 - 1;
				}
			}
			//skip all the 0
			int start = n-1;
			for (int i = n-1; i >= 0; i--) {
				if (init_state[row][i] != 0) {
					init_state[row][start] = init_state[row][i];
					start--;
				}
			}
			for (int i = start; i >= 0; i--) {
				init_state[row][i] = 0;
			}
		}
	}
}

void solver_super2048() {
	int n;
	cin >> n;
	string op;
	cin >> op;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> init_state[i][j];
		}
	}
	move(n, op);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cout << init_state[i][j]<< " ";
		}
		cout << init_state[i][n - 1];
		cout << endl;
	}
}




int main_2048() {
	int test_large = 0;
	if (test_large) {
		freopen("D-large.in", "r", stdin);
		freopen("D-large-practice.out", "w", stdout);
	}
	else {
		freopen("B-large-practice.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ":" << endl;
		solver_super2048();
	}
	return 0;
}