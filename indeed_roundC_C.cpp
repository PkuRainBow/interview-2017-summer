#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

char board[50][50];
char tmp_board[50][50];

int r, c;
int empty_cnt;
int cnt;
int x[10];
int y[10];

void init() {
	empty_cnt = 0;
	cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == '?') {
				x[empty_cnt] = i;
				y[empty_cnt] = j;
				empty_cnt++;
			}
		}
	}
	cnt = pow(2, empty_cnt);
}

void copy_board() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp_board[i][j] = board[i][j];
		}
	}
}

void fill_board(int k) {
	copy_board();
	for (int i = 0; i < empty_cnt; i++) {
		int cur = 1 & (k >> i);
		tmp_board[x[i]][y[i]] = ((cur == 1) ? 'R' : 'C');
	}
}

void update(char op, int op_x, int op_y) {
	//if (op_x >= r || op_y >= c)  return;
	tmp_board[op_x][op_y] = '*';
	if (op == 'C') {
		if (op_x + 1 < r)
			update(tmp_board[op_x + 1][op_y], op_x + 1, op_y);
	}
	else if(op == 'R') {
		if (op_y + 1 < c)
			update(tmp_board[op_x][op_y + 1], op_x, op_y + 1);
	}
	return;
}


int dfs() {
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tmp_board[i][j] == '*')
				continue;
			else {
				result++;
				update(tmp_board[i][j], i, j);
			}	
		}
	}
	return result;
}


void solver_a() {
	double result = 0;
	cin >> r >> c;
	init();
	for (int i = 0; i < cnt; i++) {
		fill_board(i);
		int cnt_tmp = dfs();
		result += cnt_tmp;
	}
	result /= cnt;
	cout << result;
}



int main_a() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "case " << i << ":" << endl;
		solver_a();
		cout << endl;
	}
	return 0;
}










