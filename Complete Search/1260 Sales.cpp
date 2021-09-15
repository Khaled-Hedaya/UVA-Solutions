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

void solve() {

  int n;
  cin >> n;
  vector<int> v;
  int sum = 0;
  rep(i, 0, n) {
    int x;
    cin >> x;
    v.pb(x);
    if (!i)
      continue;
    int cnt = 0;
    rep(j, 0, i) cnt += (v[j] <= x);
    sum += cnt;
  }
  cout << sum << "\n";

  return;
}

int main() {

  FastIO();

  int tc = 1;
  cin >> tc;
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
