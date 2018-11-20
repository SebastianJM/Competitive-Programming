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
	int t;
	ll n, sq, ans;
	vector<ll> divs;
	vector<pair<ll, pair<ll, ll>>> sets;
	cin >> t;
	while(t--) {
		cin >> n;
		divs = vector<ll>();
		sq = sqrt(n);
		for(ll i = 1; i <= sq; i++)
			if(n % i == 0) {
				divs.pb(i);
				divs.pb(n / i);
			}
		sets = vector<pair<ll, pair<ll, ll>>>();
		for(int i = 0; i < divs.size(); i++)
			for(int j = i; j < divs.size(); j++) {
				if(divs[i] + divs[j] < n)
					sets.pb(make_pair(divs[i] + divs[j], make_pair(divs[i], divs[j])));
			}
		sort(sets.begin(), sets.end());
		ans = -1;
		for(int i = 0; i < sets.size(); i++) {
			//cout << sets[i].first << " " <<sets[i].second.first << " " << sets[i].second.second << endl;
			ll goal = n - sets[i].first;
			int lo = 0, hi = sets.size() ;
			while(lo < hi) {
				int mid = lo + (hi - lo) / 2; // Find middle element (ROUNDED DOWN)
				if(sets[mid].first >= goal) // If mid satisfies the property..
					hi = mid; // Search in: [lo, mid], we are minimizing the value
				else // Else if mid does not satisfy the property..
					lo = mid + 1; // Search in: [mid+1, hi], we want a value that satisfies
			}
			while(lo < sets.size() && sets[lo].first == goal) {
				ans = max(ans, sets[i].second.first * sets[i].second.second * sets[lo].second.first * sets[lo].second.second);
				lo++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}