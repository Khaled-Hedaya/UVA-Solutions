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

int n, d;

bool canGo(int a, int b) {
  return (a >= 1 && a <= 1025 && b >= 1 && b <= 1025);
}

int sum[1026][1026];

void solve() {

  // backward thinking: pick each point of population,
  // and start make it say to all rectangular grid of length (d) that it can
  // reach them the point that has max population, this our answer optimal
  // postion

  memset(sum, 0, sizeof sum);

  cin >> d >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, cnt;
    cin >> x >> y >> cnt;
    for (int a = -d; a <= d; ++a) {
      for (int b = -d; b <= d; ++b) {
        int nx = x + a;
        int ny = y + b;
        if (canGo(nx, ny))
          sum[nx][ny] += cnt;
      }
    }
  }
  int mx = 0, ansX, ansY;
  ansX = ansY = -1;
  for (int i = 1; i <= 1025; ++i) {
    for (int j = 1; j <= 1025; ++j)
      if (sum[i][j] > mx)
        mx = sum[ansX = i][ansY = j];
  }
  cout << ansX << " " << ansY << " " << mx << "\n";
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
