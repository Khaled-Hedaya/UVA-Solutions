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

    int b, n;
    while (cin >> b >> n, b || n) {
        vector<int> val(b + 1);
        rep(i, 1, b + 1)cin >> val[i];
        rep(i, 0, n) {
            int a, b, k;
            cin >> a >> b >> k;
            val[a] -= k, val[b] += k;
        }
        bool f = 0;
        rep(i, 1, b + 1)if (val[i] < 0) {
                f ^= 1;
                break;
            }
        cout << (f ? 'N' : 'S') << "\n";
    }


    return 0;
}
