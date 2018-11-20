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
	ll s, x;
	int n;
	cin >> s >> x >> n;
	vector<pair<ll, ll>> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	int begin = 1, index = 0, ans = 0;
	ll ac = 0;
	while(1) {
		//cout << begin << " " << index <<endl;
		if(index < n && ac + (v[index].first - begin) * x < s) {
			ac += (v[index].first - begin) * x;
			ans += v[index].first - begin;
			begin = v[index].first + 1;
		}		
		else {
			s -= ac;
			ans += ceil((double) s / (double) x);
			cout << ans << endl;
			return 0;
		}
		ac += v[index].second;
		ans++;
		if(ac >= s)
			break;
		index++;
	}
	cout << ans << endl;
	return 0;
}