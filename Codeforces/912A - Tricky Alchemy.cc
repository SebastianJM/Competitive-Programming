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
	ull a,b,x,y,z,ye,bl;
	ull ans;
	cin>>a>>b>>x>>y>>z;
	ye=bl=0;
	ye+=x*2;
	ye+=y;
	bl+=y;
	bl+=z*3;
	ans=0;
	if(ye>a)
		ans+=ye-a;
	if(bl>b)
		ans+=bl-b;
	cout<<ans<<endl;
	
	return 0;
}