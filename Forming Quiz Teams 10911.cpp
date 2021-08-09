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
#define rep(i,s,e) for (int i = s; i < e; ++i)
#define repr(i,s,e) for (int i = s; i > e; --i)


const int N = 1e5 + 10, OO = 0x3f3f3f3f;


int n, x[20] , y[20];
char s[25];

double dp[1 << 17];

double dist(int p1 , int p2) {
    return sqrt((x[p1] - x[p2]) * (x[p1] - x[p2]) + (y[p1] - y[p2]) * (y[p1] - y[p2]));
}


double go(int cur_mask) {

    if (cur_mask == (1 << n) - 1)
        return 0;

    double &ret = dp[cur_mask];
    if (ret != 0)
        return ret;


    int st , ed;
    ret = 1e9;
    for (st = 0 ; st < n ; ++st) {
        if (!((1 << st) & cur_mask)) // this index is not visited
            break;
    }
    for (ed = st + 1 ; ed < n ; ++ed) {
        if (!((1 << ed) & cur_mask)) // this index is not visited
        {
            int newMask = cur_mask;
            newMask = newMask | (1 << st);
            newMask = newMask | (1 << ed);
            ret = min(ret, dist(st, ed) + go(newMask));
        }
    }
    return ret;
}


int main()
{
    int tc = 1;

    while (cin >> n , n) {
        n *= 2;
        rep(i , 0 , n) {
            cin >> s >> x[i] >> y[i];
        }

        memset(dp , 0 , sizeof dp);
        cout << fixed << setprecision(2);
        cout << "Case " << tc++ << ": " << go(0) << "\n";

    }

    return 0;
}




