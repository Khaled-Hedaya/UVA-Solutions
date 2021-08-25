#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define FastIO() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define pb push_back
#define ll long long
#define SZ(v) (int)v.size()
#define All(v) v.begin() , v.end()
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define repr(i, s, e) for (int i = s; i > e; --i)


const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*

"Maybe they aren't stars.. Maybe they are a map to get out of here"

*/

int main() {

    FastIO()
#ifdef CLION
    freopen("input.txt", "r", stdin);
#endif

    int r, c, n;
    while (cin >> r >> c >> n) {
        if (r == 0 && c == 0 && n == 0)
            break;
        vector<vector<int>> vis(r + 1, vector<int>(c + 1, 0));
        int x1, x2, y1, y2;
        int ans = 0;
        for (int k = 0; k < n; ++k) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    vis[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                ans += (vis[i][j] == 0);
            }
        }
        if (ans == 0) cout << "There is no empty spots.\n";
        else if (ans == 1) cout << "There is one empty spot.\n";
        else cout << "There are " << ans << " empty spots.\n";
    }


    return 0;
}
