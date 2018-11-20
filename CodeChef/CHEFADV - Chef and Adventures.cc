#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define N 1005 
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	fastIO;
	int t, n, m, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		n--;
		m--;
		if ((n == 0 && m == 0) || (n % x == 0 && m % y == 0)) {
			cout << "Chefirnemo\n";
		}
		else if (n && m && (n - 1) % x == 0 && (m - 1) % y == 0) {
			cout << "Chefirnemo\n";
		}
		else {
			cout << "Pofik\n";
		}
	}
	return 0;
}