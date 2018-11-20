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

// Program used to generate the most likely permutation, giving a clue to find the "Maximum probability of permutation from bad "shuffle" times n^n" (OEIS A192053)
/*
map<vector<int>, int> mp;
int n;
void rec(vector<int> v, int index) {
	if (index == n) {
		mp[v]++;
		return;
	}	
	for (int i = 0; i < n; i++) {
		vector<int> aux = v;
		swap(aux[index], aux[i]);
		rec(aux, index + 1);
	}
}
int main() {
	fastIO;
	cin >> n;
	mp = map<vector<int>, int>();
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	rec(v, 0);
	int maxi = 0;
	for (auto &x : mp) {
		maxi = max(maxi, x.second);
	}
	for (auto &x : mp) {
		if (x.second == maxi)
		{
			for (int i = 0; i < n; i++)
				cout << x.first[i] << " ";
			cout << ": " << x.second << endl;
		}		
	}
	return 0;
}
*/

int main() {
	fastIO;
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 2; i <= n / 2; i++) {
		ans.pb(i);
	}
	ans.pb(1);
	for (int i = n / 2 + 2; i <= n; i++) {
		ans.pb(i);
	}
	ans.pb(n / 2 + 1);
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	cout << n;
	for (int i = 1; i < n; i++)
		cout << " " << i;
	cout << "\n";
	return 0;
}