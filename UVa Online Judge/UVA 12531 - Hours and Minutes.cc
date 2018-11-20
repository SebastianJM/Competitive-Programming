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
	set<int> s;
	int hour = -1, ans;
	for(int i = 0; i < 1000000; i++) {
		if(i % 12 == 0) {
			hour++;
			hour %= 60;
			ans = (hour * 6) - ((i % 60) * 6);
			if(ans < 0)
				ans *= -1;
			if(ans > 180)
				ans = 360 - ans;
			s.insert(ans);
		}
	}
	while(cin >> ans) {
		if(s.find(ans) != s.end())
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}
