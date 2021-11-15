#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;
/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m;

void solve() {
	int t = 1;
	while(scanf("%d %d" , &n , &m) , n || m){
		printf("Case %d:\n" , t++);
		deque < int > dq;
		for(int i = 1 ; i <= min(n , m); ++i)
			dq.push_back(i);
		char c;
		int v;
		for(int i = 0 ; i < m ; ++i){
			scanf(" %c" , &c);
			if(c == 'N'){
				int x = dq.front();
				dq.pop_front();
				dq.push_back(x);
				printf("%d\n" , x);
			}
			else{
				scanf("%d" , &v);
				for(auto it = dq.begin(); it != dq.end() ; ++it){
					if(*it == v){
						dq.erase(it);
						break;
					}
				}
				dq.push_front(v);
			}
		}
	}
}

int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

	solve();


    return 0;
}
