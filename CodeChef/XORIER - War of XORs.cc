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
	int t, n;
	ull sum_even, sum_odd, ans_even, ans_odd;
	map<int, ull> mp;
	vector<int> v;
	cin >> t;
	while(t--) {
		cin >> n;
		v = vector<int>(n);
		mp = map<int, ull>();
		sum_even = sum_odd = ans_even = ans_odd = 0ULL;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
			v[i] & 1? sum_odd++: sum_even++;
		}
		for(auto &item: mp) {
			if(item.first & 1) {
				sum_odd -= item.second;
				ans_odd += sum_odd * item.second;
			}
			else {
				sum_even -= item.second;
				ans_even += sum_even * item.second;
			}				
		}
		sum_even = 0ULL;
		for(auto &item: mp) {
			if(mp.find(item.first ^ (1 << 1)) != mp.end())
				sum_even += item.second * mp[item.first ^ (1 << 1)];
		}
		cout << ans_even + ans_odd - sum_even / 2ULL << "\n";
	}
	return 0;
}