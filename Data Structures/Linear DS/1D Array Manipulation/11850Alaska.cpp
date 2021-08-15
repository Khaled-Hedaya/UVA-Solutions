#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, OO = 0x3f3f3f3f;

int a[N];

int main() {
    int n;
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a + n);
        bool tmam = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > 200) {
                tmam = 0;
                break;
            }
        }
        if ((1422 - a[n - 1]) * 2 > 200)
            tmam = 0;
        if (tmam) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }


    return 0;
}
