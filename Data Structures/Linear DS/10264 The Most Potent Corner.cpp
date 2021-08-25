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

    int n;
    while (cin >> n) { // 000 : 001 , 010 , 100
        vector<int> value(1 << n);
        rep(i, 0, 1 << n) {
            cin >> value[i];
        }
        vector<int> sum_of_point(1 << n, 0);
        rep(i, 0, 1 << n) {
            rep(j, 0, n) {
                sum_of_point[i] += value[i ^ (1 << j)];
            }
        }
        int mx = 0;
        rep(i, 0, 1 << n) {
            rep(j, 0, n) {
                mx = max(mx, sum_of_point[i] + sum_of_point[i ^ (1 << j)]);
            }
        }
        cout << mx << "\n";

    }


    return 0;
}
