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


int main()
{

    int q , tc = 1;
    cin >> q;
    while (q--) {
        int a[3];
        for (int i = 0 ; i < 3 ; ++i)
            cin >> a[i];
        sort(a , a + 3);
        cout << "Case " << tc++ << ": " << a[1] << "\n";
    }






    return 0;
}




