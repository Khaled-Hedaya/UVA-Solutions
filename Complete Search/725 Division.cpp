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

    //  FastIO()
#ifdef CLION
    freopen("input.txt", "r", stdin);
#endif

    int n;
    bool spaceAnswer = 0;
    while (scanf("%d", &n), n) {
        if (!spaceAnswer)
            spaceAnswer = true;
        else
            puts("");
        bool tmam = 0;
        for (int fghij = 1234; fghij <= 98765; ++fghij) {
            int abcde = fghij * n;
            if (abcde > 98765)
                break;
            int msk = (fghij < 10000);
            int now = abcde;
            while (now) {
                msk |= (1 << (now % 10));
                now /= 10;
            }
            now = fghij;
            while (now) {
                msk |= (1 << (now % 10));
                now /= 10;
            }
            if (msk == (1 << 10) - 1)
                printf("%05d / %05d = %d\n", abcde, fghij, n), tmam = 1;
        }
        if (!tmam) printf("There are no solutions for %d.\n", n);
    }


    return 0;
}
