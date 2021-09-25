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

  string s, t;
  while (cin >> s >> t) {

    int cur_idx = 0;
    int sz = SZ(t), sz2 = SZ(s);
    for (int i = 0; i < sz && cur_idx < sz2; ++i) {
      if (t[i] == s[cur_idx])
        cur_idx++;
    }
    if (cur_idx == sz2)
      cout << "Yes\n";
    else
      cout << "No\n";
    cout.flush();
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
