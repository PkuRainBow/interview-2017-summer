#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

const int MAX_N = 3009;

long long A[MAX_N], B[MAX_N], M[MAX_N][MAX_N], UP[MAX_N][MAX_N];

void solver_gMatrix(int casenum) {
	int n, m;
	long long C, X;
	cin >> n >> m >> C >> X;
	for (int row = 1; row <= n; ++row)
		cin >> A[row];
	for (int col = 1; col <= n; ++col)
		cin >> B[col];
	for (int row = 1; row <= n; ++row)
		for (int col = 1; col <= n; ++col)
			M[row][col] = (A[row] * row + B[col] * col + C) % X;

	/** firstly, we construct the sliding max-value array along the column each m element **/
	for (int col = 1; col <= n; col++) {
		deque<int> q;
		for (int row = 1; row <= n; row++) {
			if (!q.empty() && q.front() == row - m) q.pop_front();
			while (!q.empty() && M[q.back()][col] <= M[row][col])
				q.pop_back();
			q.push_back(row);
			if (row >= m)
				UP[row][col] = M[q.front()][col];
		}
	}

	long long result = 0;
	for (int row = m; row <= n; row++) {
		deque<int> q;
		for (int col = 1; col <= n; col++) {
			if (!q.empty() && q.front() == col - m) q.pop_front();
			while (!q.empty() && UP[row][q.back()] < UP[row][col]) q.pop_back();
			q.push_back(col);
			if (col >= m)
				result += UP[row][q.front()];
		}
	}
	cout << "Case #" << casenum << ": " << result << endl;
}


int main() {
	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solver_gMatrix(i);
	}
	return 0;
}