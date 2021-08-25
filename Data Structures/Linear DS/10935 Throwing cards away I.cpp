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
    while (cin >> n, n) {
        queue<int> cards;
        vector<int> dis;
        rep(i, 1, n + 1)cards.push(i);
        while ((int) cards.size() >= 2) {
            int cur_front = cards.front();
            cards.pop();
            dis.push_back(cur_front);
            cur_front = cards.front();
            cards.pop();
            cards.push(cur_front);
        }
        cout << "Discarded cards:";
        int sz = SZ(dis);
        rep(i, 0, sz) {
            if (i == sz - 1)
                cout << " " << dis[i];
            else
                cout << " " << dis[i] << ",";
        }
        cout << "\n";
        cout << "Remaining card: " << cards.front() << "\n";
        cards.pop();

    }


    return 0;
}
