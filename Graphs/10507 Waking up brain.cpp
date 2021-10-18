#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, finished[26];
char s[4];
vector<int> adj[26];

int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (~scanf("%d", &n)) {
        for (int i = 0; i < 26; ++i) {
            finished[i] = 0;
            adj[i].clear();
        }
        scanf("%d", &m);
        scanf("%s", s);
        queue<int> toProcess;
        for (int i = 0; i < 3; ++i) {
            finished[s[i] - 'A'] = 1;
            toProcess.push(s[i] - 'A');
        }
        int ans = -1; // we want to skip the count of initially waked up vertices
        for (int i = 0; i < m; ++i) {
            char c1, c2;
            scanf(" %c %c", &c1, &c2);
            adj[c1 - 'A'].push_back(c2 - 'A');
            adj[c2 - 'A'].push_back(c1 - 'A');
        }
        int cnt[26] = {};
        while (!toProcess.empty()) {
            ans++;
            int sz = (int) toProcess.size();
            while (sz--) {
                int u = toProcess.front();
                toProcess.pop();
                for (auto v: adj[u]) {
                    if (!finished[v]) {
                        cnt[v]++;
                        if (cnt[v] >= 3)
                            toProcess.push(v), finished[v] = 1;
                    }
                }
            }
        }
        int total = count(finished, finished + 26, 1);
        if (total == n) printf("WAKE UP IN, %d, YEARS\n", ans);
        else puts("THIS BRAIN NEVER WAKES UP");
    }


    return 0;
}
