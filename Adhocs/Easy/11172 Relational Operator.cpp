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

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        if (a < b) cout << '<' << "\n";
        else if (a > b) cout << '>' << "\n";
        else cout << '=' << "\n";
    }






    return 0;
}




