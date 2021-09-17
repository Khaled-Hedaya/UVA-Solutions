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

int n;
bool used[20];
vector<int> ans;
bool isPrime(int rkm) {
  if (rkm < 2)
    return 0;
  if (rkm == 2)
    return 1;
  if (rkm % 2 == 0)
    return 0;
  for (int i = 3; i * i <= rkm; i += 2) {
    if (rkm % i == 0)
      return 0;
  }
  return 1;
}
void go(int cntNums, int prv) {
  // note : i start counting from ZERO, so i must end at n - 1 which is(n
  // elements)
  if (cntNums == n - 1 && isPrime(ans[0] + ans[n - 1])) {
    for (int i = 0; i < n; ++i)
      cout << ans[i] << " \n"[i == n - 1];
    return;
  }

  for (int i = 2; i <= n; ++i) {
    if (!used[i] && isPrime(i + prv)) {
      ans.pb(i);
      used[i] = 1;
      go(cntNums + 1, i);
      ans.pop_back();
      used[i] = 0;
    }
  }
}

void solve() {

  memset(used, 0, sizeof used);
  ans.clear();
  used[1] = 1;
  ans.pb(1);
  go(0, 1);
}

int main() {

  FastIO();
  int tc = 0;
  while (cin >> n) {
    if (tc)
      cout << "\n";
    tc++;
    cout << "Case " << tc << ":\n";
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
