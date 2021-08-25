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

    string s;
    while (getline(cin, s)) {
        int sz = SZ(s);
        deque<string> dq;
        string prv_word = "";
        bool add_right = 1;
        rep(i, 0, sz) {
            if (s[i] == '[') {
                if (add_right) dq.push_back(prv_word);
                else dq.push_front(prv_word);
                add_right = 0;
                prv_word = "";
            } else if (s[i] == ']') {
                if (add_right) dq.push_back(prv_word);
                else dq.push_front(prv_word);
                add_right = 1;
                prv_word = "";
            } else
                prv_word += s[i];

        }

        if (add_right) dq.push_back(prv_word);
        else dq.push_front(prv_word);
        for (auto x : dq)
            cout << x;
        cout << "\n";

    }


    return 0;
}
