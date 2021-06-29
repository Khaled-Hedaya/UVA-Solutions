#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

int a[105][105];

int main() {
    int n;
    while (cin >> n, n) {
        int cntR = 0 , cntC = 0, r, c, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = 0; j < n; ++j)
                cin >> a[i][j], sum += a[i][j];
            if (sum & 1) cntR++, r = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = 0; j < n; ++j)
                sum += a[j][i];
            if (sum & 1) cntC++, c = i + 1;
        }
        if (cntR + cntC == 0) cout << "OK\n";
        else if (cntR == 1 && cntC == 1) cout << "Change bit " << '(' << r << ',' << c << ')' << "\n";
        else cout << "Corrupt\n";
    }


    return 0;
}




