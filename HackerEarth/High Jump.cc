#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x) 
#define N 100003
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
 
 
int main() {
	int n, m, l, a;
	double x, y;
	vector<pair<double, int>> obs;
	cin >> n >> m >> l >> a;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		obs.pb(make_pair(x - (y / a), i));
		obs.pb(make_pair(x + (y / a), i));
	}
	sort(obs.begin(), obs.end());
	double min_x = DBL_MAX, max_x = 0.0;
	set<int> in;
	for(int i = 0; i < obs.size(); i++) {
		int index = obs[i].second;
		min_x = min(min_x, obs[i].first);
		max_x = max(max_x, obs[i].first);
		if(in.find(index) != in.end()) {
			in.erase(index);
			if(max_x > l || min_x < 0.0) {
				cout << "No\n";
				return 0;
			}
			if(in.size() == 0) {
				
				x = (max_x + min_x) / 2.0;
				y = (max_x - x) * a;
				//cout << min_x << " " << max_x << " " << y << endl;
				if(m < y) {
					cout << "No\n";
					return 0;
				}
				min_x = DBL_MAX; 
				max_x = 0.0;
			}
		}
		else {
			in.insert(index);			
		}
	}
	cout << "Yes\n";
	return 0;
}