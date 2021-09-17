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

int spaces, q;
pair<int, int> st, ed, v[16];
map<pair<int, int>, bool> used;
vector<pair<int, int>> ans;

bool go(int idx, pair<int, int> prv) {
  if (idx == spaces)
    return (ed.F == ans[idx - 1].S);

  bool ret = 0;
  for (int i = 0; i < q; ++i) {
    if (!used[v[i]] && (v[i].F == prv.S || v[i].S == prv.S)) {
      used[{v[i].F, v[i].S}] = used[{v[i].S, v[i].F}] = 1;
      if (v[i].F == prv.S) {
        ans.pb({v[i].F, v[i].S});
        ret |= go(idx + 1, {v[i].F, v[i].S});
        ans.pop_back();
      } else {
        ans.pb({v[i].S, v[i].F});
        ret |= go(idx + 1, {v[i].S, v[i].F});
        ans.pop_back();
      }
      used[{v[i].F, v[i].S}] = used[{v[i].S, v[i].F}] = 0;
    }
  }
  return ret;
}

void solve() {
  cin >> q;
  cin >> st.F >> st.S;
  cin >> ed.F >> ed.S;
  rep(i, 0, q) cin >> v[i].F >> v[i].S;
  //
  if (go(0, st))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {

  FastIO();

  while (cin >> spaces, spaces) {
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
