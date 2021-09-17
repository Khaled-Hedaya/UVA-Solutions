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

int v[5];

bool canGo(int idx, int cur) {
  // cout << idx << " " << cur << "\n";
  if (idx == 5) {
    return (cur == 23);
  }
  bool ret = 0;
  ret |= canGo(idx + 1, cur * v[idx]);
  ret |= canGo(idx + 1, cur + v[idx]);
  ret |= canGo(idx + 1, cur - v[idx]);
  return ret;
}

void solve() {
  int a, b, c, d, e;
  while (cin >> a >> b >> c >> d >> e) {
    if (a + b + c + d + e == 0)
      break;
    v[0] = a, v[1] = b, v[2] = c, v[3] = d, v[4] = e;
    sort(v, v + 5);
    bool ok = 0;
    do {
      ok = canGo(1, v[0]);
      if (ok)
        break;
    } while (next_permutation(v, v + 5));
    if (ok)
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }

  //
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
