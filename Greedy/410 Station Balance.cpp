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

int cham, items, mass[11];

void solve() {

  int sum = 0;
  for (int i = 0; i < items; ++i) {
    cin >> mass[i];
    sum += mass[i];
  }
  int add = 2 * cham - items;
  int idx = items;
  for (int i = 0; i < add; ++i) {
    mass[idx++] = 0;
  }
  items += add;
  sort(mass, mass + items);
  int lo = 0, hi = items - 1;
  double avg = (1.0 * sum) / cham;
  double ans = 0;
  idx = 0;
  while (lo < hi) {
    cout << " " << idx++ << ":";
    if (mass[hi])
      cout << " " << mass[hi];
    if (mass[lo])
      cout << " " << mass[lo];
    cout << "\n";
    int val = mass[lo++] + mass[hi--];

    ans += fabs(avg - val);
  }
  cout << fixed << setprecision(5);
  cout << "IMBALANCE = " << ans << "\n\n";
}

int main() {

  FastIO();
  int tc = 0;
  while (cin >> cham >> items) {
    tc++;
    cout << "Set #" << tc << "\n";
    solve();
  }

  return 0;
}
