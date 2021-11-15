
// Problem Link: https://codeforces.com/gym/102766/problem/B

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;
/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int freq[26];


void solve() {
	
	memset(freq , 0 , sizeof freq);
	
	string s;
	cin >> s;
    int n = (int)s.size();
 
	for(auto c : s)
		freq[c - 'a']++;
		
    sort(freq, freq + 26);
    reverse(freq , freq + 26);

    int ans = n;
	// numDistinctChars * freqOfEachGroup = length of string;
    for (int numDistinct = 1; numDistinct <= 26 && numDistinct <= n; numDistinct++) {
        if (n % numDistinct == 0) {
            int frqEach = n / numDistinct;
            int have = 0;
            for (int j = 0; j < numDistinct; j++) {
                have += min(freq[j], frqEach);
            }
            ans = min(ans, n - have);
        }
    }
    cout << ans << "\n";

}

int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
	
	int tc = 1;
	cin >> tc;
	while(tc--){
		solve();
	}

    return 0;
}
