#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	vector<int>::iterator it;
	int t,n;
	for(int i=1;(i+2)*(i+1)/2<=50000000;i++)
		v.push_back((i+2)*(i+1)/2);
	cin>>t;
	while(t--)
	{
		cin>>n;
		it=lower_bound(v.begin(),v.end(),n);
		if(*it!=n)
			cout<<"No solution\n";
		else
			cout<<(it-v.begin())+1<<"\n";
	}
	
	return 0;
}