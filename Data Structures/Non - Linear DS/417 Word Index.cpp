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

    int id = 1;
    deque<string> v;
    string tmp = "";
    for (char ch = 'a'; ch <= 'z'; ++ch) v.push_back(tmp + ch);
    map<string, int> mp;
    while (SZ(v) > 0) {

        string now = v.front();
        v.pop_front();
        mp[now] = id++;
        if ((int) now.size() < 5) {
            for (char ch = (char) (now[now.size() - 1] + 1); ch <= 'z'; ++ch)
                v.push_back(now + ch);
        }
    }


    string s;
    while (cin >> s) {
        if (mp.find(s) != mp.end())
            cout << mp[s] << "\n";
        else
            cout << "0\n";
    }


    return 0;
}
