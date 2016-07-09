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
//#define esp 1e-9
//#define inf 0x7fffffff
//#define MOD 1000000007
//
//const int M = 1010;
//const int N = 110;
//int v[M];
//struct ball {
//	int p, h;
//}b[N];
//
//int main_gBallon() {
//	freopen("B-large-practice.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int t;
//	cin >> t;
//	int case_ = 0;
//	while (case_++ < t) {
//		int n, m, q;
//		cin >> n >> m >> q;
//		for (int i = 0; i < m; i++) cin >> v[i];
//		for (int i = 0; i < n; i++) cin >> b[i].p >> b[i].h;
//		/** low & high record the time cost **/
//		int low = -1, high = 10001;
//		while (high - low > 1) {
//			int mid = (low + high) >> 1;
//			int tmp = q;
//			bool yes = 1;
//			/** check all the balloon is ok's cost **/
//			for (int i = 0; i < n; i++) {
//				/** the ballon's current position is ok, no need to move **/
//				if (b[i].p >= 0 && b[i].p + v[b[i].h] * mid <= 0) continue;
//				if (b[i].p <= 0 && b[i].p + v[b[i].h] * mid >= 0) continue;
//				/** find the minimal move cost to satisy the condition **/
//				int mm = 20000;
//				for (int j = b[i].h + 1; j < m; j++) {
//					if (b[i].p >= 0 && b[i].p + v[j] * mid <= 0) {
//						mm = j - b[i].h;
//						break;
//					}
//					if (b[i].p <= 0 && b[i].p + v[j] * mid >= 0) {
//						mm = j - b[i].h;
//						break;
//					}
//				}
//				for (int j = b[i].h - 1; j >= 0; j--) {
//					if (b[i].p >= 0 && b[i].p + v[j] * mid <= 0) {
//						mm = min(mm, b[i].h - j);
//						break;
//					}
//					if (b[i].p <= 0 && b[i].p + v[j] * mid >= 0) {
//						mm = min(mm, b[i].h - j);
//						break;
//					}
//				}
//				tmp -= mm;
//				if (mm == 20000 || tmp < 0) {
//					yes = 0;
//					break;
//				}
//			}
//			if (!yes) low = mid;
//			else high = mid;
//		}
//		cout << "Case #" << case_ << ": ";
//		if (high > 10000)  cout << "IMPOSSIBLE" << endl;
//		else cout << high << endl;
//	}
//	return 0;
//}