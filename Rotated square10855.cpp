#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, OO = 0x3f3f3f3f;


char big[100][100], small[100][100];

int get_count(int n, int m) {
    int cnt = 0;
    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            int visited = 0;
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (big[i + x][j + y] == small[x][y])
                        visited++;
                }
            }
            if (visited == m * m)
                cnt++;
        }
    }
    return cnt;
}

void rotateGrid(int sz) {
    char tmp[sz][sz];
    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            tmp[i][j] = small[sz - j - 1][i];

    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            small[i][j] = tmp[i][j];
}

int main() {

    int szS, szB;
    while (cin >> szB >> szS, szB && szS) {
        for (int i = 0; i < szB; ++i)
            cin >> big[i];
        for (int i = 0; i < szS; ++i)
            cin >> small[i];

        for (int i = 0; i < 4; ++i) {
            int ans = get_count(szB, szS);
            cout << ans << " \n"[i == 3];
            rotateGrid(szS);
        }

    }


    return 0;
}




