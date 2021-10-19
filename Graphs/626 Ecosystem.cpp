#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n;
int adj[105][105];

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", adj[i] + j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (adj[i][j] && adj[j][k] && adj[k][i] && ((i < j && j < k) || (i > j && j > k))) {
                        cnt++;
                        printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    }
                }
            }
        }
        printf("total:%d\n", cnt);
        puts("");
    }

    return 0;
}
