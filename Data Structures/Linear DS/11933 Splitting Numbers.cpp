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

    int n;
    while (cin >> n, n) {
        int idx = 1, pos = 0;

        int a = 0, b = 0;

        while (n) {
            int d = n % 2;
            if (d == 1) {
                if (idx % 2 == 0) {
                    b = b | (1 << pos); // 1 << pos
                } else {
                    a = a | (1 << pos); // 1 << pos
                }
                idx++;
            }
            n >>= 1;
            pos++;
        }

        cout << a << " " << b << "\n";
    }

    return 0;
}
