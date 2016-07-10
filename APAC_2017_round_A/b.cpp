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

int matrix[51][51];
int row, col;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

struct shot {
	int x, y;
	int h;
	shot() {}
	shot(int x_, int y_, int h_) :x(x_), y(y_), h(h_) {}
};

struct compare {
	bool operator() (const shot & a, const shot& b) {
		return a.h > b.h;
	}
};

void init_b() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}
}

void solver_b() {
	init_b();
	vector<vector<bool>> visit(row, vector<bool>(col, false));
	priority_queue<shot, vector<shot>, compare> heap;
	//push the top and down row 
	for (int i = 0; i < row; i++) {
		heap.emplace(i, 0, matrix[i][0]);
		heap.emplace(i, col - 1, matrix[i][col - 1]);
		visit[i][0] = visit[i][col - 1] = true;
	}
	//push the left and right col 
	for (int i = 0; i < col; i++) {
		heap.emplace(0, i, matrix[0][i]);
		heap.emplace(row-1, i, matrix[row-1][i]);
		visit[0][i] = visit[row-1][i] = true;
	}
	long long result = 0;
	while (!heap.empty()) {
		auto cur = heap.top();
		heap.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur.x + dx[i], next_y = cur.y + dy[i];
			if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col && !visit[next_x][next_y]) {
				result += max(0, cur.h - matrix[next_x][next_y]);
				heap.emplace(next_x, next_y, max(cur.h, matrix[next_x][next_y]));
				visit[next_x][next_y] = true;
			}
		}
	}
	cout << result;
	return;
}

int main_b() {
	int file_choice = 2;
	if (file_choice == 0) {
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	else if (file_choice == 1) {
		freopen("B-small-attempt0.in", "r", stdin);
		freopen("B-small-practice.out", "w", stdout);
	}
	else {
		freopen("B-large.in", "r", stdin);
		freopen("B-large-practice.out", "w", stdout);
	}

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solver_b();
		cout << endl;
	}
	return 0;
}










