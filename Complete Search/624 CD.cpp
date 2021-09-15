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

vector<int> v, ans, best;
int req, n, mxSum;

void backtrack(int idx, int sum) {
  if (idx == n) {
    if (sum <= req) {
      int cur = 0;
      for (auto x : ans)
        cur += x;
      if (cur > mxSum) {
        mxSum = cur;
        best = ans;
      }
    }
    return;
  }
  if (sum > req)
    return;
  // do - recurse - undo
  ans.pb(v[idx]);
  backtrack(idx + 1, sum + v[idx]);
  ans.pop_back();
  backtrack(idx + 1, sum);
}

void solve() {

  while (cin >> req >> n) {
    mxSum = 0;
    best.clear();
    v.resize(n);
    rep(i, 0, n) { cin >> v[i]; }
    backtrack(0, 0);
    for (auto rkm : best)
      cout << rkm << " ";
    cout << "sum:" << mxSum << "\n";
  }

  return;
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
