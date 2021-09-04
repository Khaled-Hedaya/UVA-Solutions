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

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool tmam = 0;
        rep(x, -100, 101) {
            if (tmam) break;
            rep(y, -100, 101) {
                if (tmam) break;
                rep(z, -100, 101) {
                    if (tmam) break;
                    if (x != y && x != z && y != z && x + y + z == a && (x * y * z) == b && x * x + y * y + z * z == c)
                        cout << x << " " << y << " " << z << "\n", tmam = 1;
                }
            }
        }
        if (!tmam) cout << "No solution.\n";
    }


    return 0;
}
