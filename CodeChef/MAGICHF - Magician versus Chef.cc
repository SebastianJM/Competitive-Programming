#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x) 
#define N 1003
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	fastIO;
	int t, n, x, s, a, b;
	cin >> t;
	while(t--) {
		cin >> n >> x >> s;
		for(int i = 0; i < s; i++) {
			cin>> a >> b;
			if(a == x)
				x = b;
			else if(b == x)
				x = a;
		}
		cout << x <<endl;
	}
	return 0;
}