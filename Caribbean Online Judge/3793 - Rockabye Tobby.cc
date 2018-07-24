#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef pair<pair<int,int>,string> pis;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pis, vector<pis>, greater<pis>> heap;
	map<string,int> mp;
	int t,n,k,a,b;
	string s;
	cin>>t;
	while(t--)
	{
		while(!heap.empty())
			heap.pop();
		mp.clear();
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>s>>a;
			mp[s]=a;
			heap.push(make_pair(make_pair(a,i),s));
		}
		while(k--)
		{
			a=heap.top().first.first;
			b=heap.top().first.second;
			s=heap.top().second;
			heap.pop();
			cout<<a<<" "<<s<<"\n";
			heap.push(make_pair(make_pair(a+mp[s],b),s));
		}
	}
	return 0;
}