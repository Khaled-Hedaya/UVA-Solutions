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
char g[105][105];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool tmam(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < n); }

void solve() {

  cin >> n;
  rep(i, 0, n) cin >> g[i];

  int d = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (g[i][j] == '.') {
        for (char c = 'A'; c <= 'Z'; ++c) {
          g[i][j] = c;
          for (d = 0; d < 4; ++d) {
            int nr = i + dx[d];
            int nc = j + dy[d];
            if (!tmam(nr, nc))
              continue;
            if (g[i][j] == g[nr][nc])
              break;
          }
          if (d == 4)
            break;
        }
      }
    }
  }
  rep(i, 0, n) cout << g[i] << "\n";
}

int main() {

  FastIO();

  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case " << i << ":\n";
    solve();
  }

  return 0;
}
