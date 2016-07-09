#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll __gcd(ll a, ll b) {
	return (a % b == 0) ? b : __gcd(b, a % b);
}

void solve() {
	int np, ne, nt;
	cin >> np >> ne >> nt;
	vector<ll> gp(np), ge(ne), gt(nt);
	FOR(i, np) cin >> gp[i];
	FOR(i, ne) cin >> ge[i];
	FOR(i, nt) cin >> gt[i];
	set<pll> extra;
	FOR(i, ne) for (int j = i + 1; j < ne; j++) {
		ll g = __gcd(ge[i], ge[j]);
		ll a = ge[i] / g, b = ge[j] / g;
		extra.insert(make_pair(a, b));
		extra.insert(make_pair(b, a));
	}
	set<pll> base;
	FOR(i, np)  FOR(j, nt) {
		ll g = __gcd(gp[i], gt[j]);

	}
}
int main() {
	int TestCase;
	cin >> TestCase;
	FOR(caseID, TestCase) {
		cout << "Case #" << caseID + 1 << ":" << endl;
		solve();
	}
	return 0;
}