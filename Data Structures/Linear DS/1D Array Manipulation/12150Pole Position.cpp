#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
#define F first
#define S second
#define pb push_back
#define ll long long
#define All(v) v.begin() , v.end()
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define repr(i, s, e) for (int i = s; i > e; --i)


const int N = 1e3 + 10, OO = 0x3f3f3f3f;

/*
Don't feel bad about feeling bad.
It's okay to not be okay.
*/
int vis[N];

int main() {
    int n;
    while (cin >> n, n) {
        bool tmam = 1;
        memset(vis, 0, sizeof(vis));
        for (int pos = 0; pos < n; ++pos) {
            int id, val;
            cin >> id >> val;
            if (pos + val < 0 || pos + val >= n || vis[pos + val] != 0)
                tmam = 0;
            if (!tmam)
                continue;
            vis[pos + val] = id;
        }
        if (!tmam) cout << "-1\n";
        else {
            for (int i = 0; i < n; ++i)
                cout << vis[i] << " \n"[i == n - 1];
        }
    }


    return 0;
}
