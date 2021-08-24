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
        while (1) {
            int req_car;
            stack<int> all_cars;
            int cur_car = 0;
            rep(i, 0, n) {
                cin >> req_car;
                if (req_car == 0) break;
                while (cur_car < n && cur_car != req_car) {
                    if (all_cars.size() > 0 && all_cars.top() == req_car) break;
                    cur_car++;
                    all_cars.push(cur_car);
                }
                if (all_cars.top() == req_car)
                    all_cars.pop();
            }
            if (req_car == 0) break;
            if (SZ(all_cars) == 0) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }


    return 0;
}
