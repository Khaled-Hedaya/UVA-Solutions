#include <bits/stdc++.h>

using namespace std;


const int N = 1e6+ 10, OO = 0x3f3f3f3f;

int pref[N];

int main() {
    string s;
    int tc = 1;
    while (cin >> s) {
        int sz = (int) s.size();
        pref[0] = (s[0] == '1');
        for (int i = 1; i < sz; ++i)
            pref[i] = pref[i - 1] + (s[i] - '0');

        cout << "Case " << tc << ":\n";
        tc++;
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);
            int cnt = pref[r] - (l == 0 ? 0 : pref[l - 1]);
            if (cnt == (r - l + 1) || cnt == 0) cout << "Yes\n";
            else cout << "No\n";
        }

    }


    return 0;
}
