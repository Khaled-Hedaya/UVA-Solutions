#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define FastIO() ios::sync_with_stdio(false), cin.tie(0)
#define F first
#define S second
#define pb push_back
#define ll long long
#define SZ(a) ((int)((a).size()))
#define All(v) v.begin(), v.end()
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define repr(i, s, e) for (int i = s; i > e; --i)

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int t, n;
map<vector<int>, bool> vis;
vector<int> v, ans;

void backtrack(int idx, int sum) {
  if (sum == t) {
    if (vis[ans] == true)
      return;
    vis[ans] = true;
    int sz = SZ(ans);
    rep(i, 0, sz) cout << ans[i] << "+\n"[i == sz - 1];
    return;
  }
  if (sum > t || idx == n)
    return;
  for (int nxt = idx; nxt < n; ++nxt) {
    ans.pb(v[nxt]);
    backtrack(nxt + 1, sum + v[nxt]);
    ans.pop_back();
  }
}

void solve() {

  while (cin >> t >> n, n) {
    vis.clear(), ans.clear();
    v.resize(n);
    rep(i, 0, n) cin >> v[i];

    cout << "Sums of " << t << ":\n";
    backtrack(0, 0);
    if (vis.empty())
      cout << "NONE\n";
  }
}

int main() {

  FastIO();

  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
#ifdef ONPC
    cout << "__________________________" << endl;
#endif
  }

#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

  return 0;
}
