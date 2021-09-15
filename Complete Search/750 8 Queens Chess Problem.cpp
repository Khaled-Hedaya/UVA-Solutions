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

int row[10], x, y, line;

bool tmam(int r, int c) {
  for (int prv = 1; prv < c; ++prv) {
    if (row[prv] == r || abs(row[prv] - r) == abs(c - prv))
      return 0;
  }
  return 1;
}

void backtrack(int cur_col) {
  if (cur_col == 9) {
    if (row[y] == x) {
      printf("%2d      %d", ++line, row[1]);
      for (int i = 2; i <= 8; ++i)
        printf(" %d", row[i]);
      puts("");
    }
    return;
  }
  for (int r = 1; r <= 8; ++r) {
    if (tmam(r, cur_col)) {
      row[cur_col] = r;
      backtrack(cur_col + 1);
    }
  }
}

void solve() {
  memset(row, 0, sizeof row);
  line = 0;
  scanf("%d %d", &x, &y);
  printf("SOLN       COLUMN\n");
  printf(" #      1 2 3 4 5 6 7 8\n\n");
  backtrack(1); // start from column 1

  return;
}

int main() {

  // FastIO()

  int tc = 1;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; i++) {
    solve();
  }

  return 0;
}
