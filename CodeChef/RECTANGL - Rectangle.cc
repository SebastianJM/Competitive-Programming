#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define MAX 1000005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main() 
{
	fastIO;
	int t,v[4];
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++)
			cin>>v[i];
		sort(v,v+4);
		if(v[0]==v[1] && v[2]==v[3])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
} 