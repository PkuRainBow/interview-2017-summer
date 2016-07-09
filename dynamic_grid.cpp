//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream> 
//#include <map>
//#include <unordered_set>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//const int max_ = 101;
//int t, r, c, n;
//char matrix[max_][max_];
//char base[max_][max_];
//
//void copy() {
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			base[i][j] = matrix[i][j];
//		}
//	}
//}
//
//void dfs(int i, int j) {
//	if (i < 0 || i >= r || j < 0 || j >= c)  return;
//	if (base[i][j] == '1') {
//		base[i][j] = '2';
//		dfs(i - 1, j);
//		dfs(i + 1, j);
//		dfs(i, j - 1);
//		dfs(i, j + 1);
//	}
//}
//
//void solve_dynamic() {
//	char op;
//	cin >> n;
//	while (n--) {
//		cin >> op;
//		if (op == 'M') {
//			int x, y;
//			char z;
//			cin >> x >> y >> z;
//			matrix[x][y] = z;
//		}
//		else {
//			copy();
//			int ans = 0;
//			for (int i = 0; i < r; i++) {
//				for (int j = 0; j < c; j++) {
//					if (base[i][j] == '0' || base[i][j] == '2')
//						continue;
//					ans++;
//					dfs(i, j);
//				}
//			}
//			cout << ans << endl;
//		}
//	}
//}
//
//int main_dynamic() {
//	int test_large = 0;
//	if (test_large) {
//		freopen("D-large.in", "r", stdin);
//		freopen("D-large-practice.out", "w", stdout);
//	}
//	else {
//		freopen("A-large-practice.in", "r", stdin);
//		freopen("test.out", "w", stdout);
//	}
//
//	int T = 0;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cout << "Case #" << i + 1 << ":" << endl;
//		cin >> r >> c;
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				cin >> matrix[i][j];
//				base[i][j] = matrix[i][j];
//			}
//		}
//		solve_dynamic();
//	}
//	return 1;
//}