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

typedef struct constraints {
    int a, b, c;
} cond;


int getIndx(int val, vector<int> &tmp) { // at most takes 8 steps only!
    int sz = tmp.size();
    int i = 0;
    for (; i < sz; ++i)
        if (tmp[i] == val)
            break;
    return i;
}


int main() {

    FastIO()
#ifdef CLION
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    while (cin >> n >> m, n || m) {
        vector<int> cur(n);
        rep(i, 0, n)cur[i] = i;
        vector<cond> c(m);
        rep(i, 0, m)cin >> c[i].a >> c[i].b >> c[i].c;
        bool tmam = 1;
        int cnt = 0;
        do {
            tmam = 1;
            rep(i, 0, m) {
                if (!tmam) break;
                int frst_pos = getIndx(c[i].a, cur);
                int sec_pos = getIndx(c[i].b, cur);
                int diff = abs(frst_pos - sec_pos);
                if (c[i].c < 0) { // at least c seats apart
                    tmam &= (diff >= abs(c[i].c));
                } else { // at most c seats apart
                    tmam &= (diff <= c[i].c);
                }
            }
            if (tmam) cnt++;
        } while (next_permutation(All(cur)));

        cout << cnt << "\n";
    }


    return 0;
}
