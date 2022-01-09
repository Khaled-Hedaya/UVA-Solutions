#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e4 + 10, OO = 0x3f3f3f3f, M = 1e2 + 10;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int m, n, k, a[N];
int dp[N][M];

int fixMod(int val , int sum) {
    return ((((sum + val) % k) + k) % k);
}

int solve(int idx, int mod) {
    if (idx == n)
        return mod == 0;
    int &ret = dp[idx][mod];
    if (~ret) return ret;
    ret = solve(idx + 1 , fixMod(a[idx] , mod)) || solve(idx + 1, fixMod(-a[idx], mod));
    return ret;
}

int main() {
    FastIO()
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> m;
    while (m--) {
        cin >> n >> k;
        for (int i = 0 ; i < n; ++i)
            cin >> a[i];
        memset(dp, -1, sizeof dp);
        if (solve(0, 0))
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }


    return 0;
}
