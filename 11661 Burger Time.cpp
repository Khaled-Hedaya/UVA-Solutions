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

    int l;
    while (cin >> l, l) {
        string s;
        cin >> s;
        int lstR, lstD, ans = l - 1;
        lstR = lstD = -l;
        for (int i = 0; i < l; ++i) {
            if (s[i] == 'Z') {
                ans = 0;
                break;
            }
            if (s[i] == 'R') {
                ans = min(ans, i - lstD);
                lstR = i;
                continue;
            }
            if (s[i] == 'D') {
                ans = min(ans, i - lstR);
                lstD = i;
                continue;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
