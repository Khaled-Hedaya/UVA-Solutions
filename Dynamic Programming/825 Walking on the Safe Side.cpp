#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int tc, n , m;
int blocked[1001][1001];
ll dp[1001][1001];


bool valid(int x,  int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

ll solve(int r , int c) {
	if (!valid(r , c) || blocked[r][c])
		return 0;

	if (r == n - 1 && c == m - 1)
		return 1;

	ll &ret = dp[r][c];
	if (~ret) return ret;
	ret = 0;
	ret += solve(r + 1, c);
	ret += solve(r, c + 1);
	return ret;
}



int main() {
	FastIO()
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> tc;
	while (tc--) {

		memset(blocked, 0, sizeof blocked);
		memset(dp, -1, sizeof dp);

		cin >> n >> m;
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			stringstream ss(s);
			int r, c;
			ss >> r;
			while (ss >> c)
				blocked[r - 1][c - 1] = 1;
		}

		cout << solve(0 , 0) << "\n";
		if (tc)
			cout << "\n";
	}

	return 0;
}
