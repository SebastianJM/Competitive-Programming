#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define N 100005 
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	fastIO;
	int t, q, a, b;
	int c[3][N], r[3][N];
	string row, col;
	cin >> t;
	while(t--) {
		cin >> col >> row;
		for(int i = 1; i <= col.size(); i++) {
			c[0][i] = col[i-1] - '0';
		}
		for(int i = 1; i <= row.size(); i++) {
			r[0][i] = row[i-1] - '0';
		}
		for(int i = 1; i <= 2; i++) {
			a = r[0][i];
			for(int j = 1; j <= col.size(); j++) {
				if(c[i - 1][j] == 0 || a == 0)
					a = 1;
				else
					a = 0;
				c[i][j] = a;
			}
		}
		for(int i = 1; i <= 2; i++) {
			a = c[0][i];
			for(int j = 1; j <= row.size(); j++) {
				if(r[i - 1][j] == 0 || a == 0)
					a = 1;
				else
					a = 0;
				r[i][j] = a;
			}
		}
		cin >> q;
		while(q--) {
			cin >> a >> b;
			if(a == 1)
				cout << c[1][b];
			else if(b == 1)
				cout << r[1][a];
			else {
				if(a >= b)
					cout << r[2][a - (b - 2)];
				else
					cout << c[2][b - (a - 2)];
			}
		}
		cout << endl;
	}
	return 0;
}