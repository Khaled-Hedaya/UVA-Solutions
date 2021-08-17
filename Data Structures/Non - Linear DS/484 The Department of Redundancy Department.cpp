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

    map<int, int> mp;
    vector<int> v;
    int x;
    while (cin >> x) {
        if (mp.find(x) == mp.end())
            v.push_back(x);
        mp[x]++;
    }
    int sz = SZ(v);
    for (int i = 0; i < sz; ++i) {
        cout << v[i] << " " << mp[v[i]] << "\n";
    }

    return 0;
}
