#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct bomb
{
	ll dist,x,y;
	bomb(){}
	bomb(ll d,ll a,ll b):dist(d),x(a),y(b){}
	bool operator<(const bomb& z) const { return dist < z.dist; }
};

int main() 
{
	fastIO;
	ll x,y;
	int n,ans=0;
	cin>>n;
	vector<bomb> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		v[i]=bomb(labs(x)+labs(y),x,y);
		ans+=2;
		if(x!=0LL)
			ans+=2;
		if(y!=0LL)
			ans+=2;
	}

	sort(v.begin(),v.end());
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		if(v[i].x>0LL)
			cout<<"1 "<<v[i].x<<" R\n";
		else if(v[i].x<0LL)
			cout<<"1 "<<labs(v[i].x)<<" L\n";
		if(v[i].y>0LL)
			cout<<"1 "<<v[i].y<<" U\n";
		else if(v[i].y<0LL)
			cout<<"1 "<<labs(v[i].y)<<" D\n";
		cout<<"2\n";
		if(v[i].x>0LL)
			cout<<"1 "<<v[i].x<<" L\n";
		else if(v[i].x<0LL)
			cout<<"1 "<<labs(v[i].x)<<" R\n";
		if(v[i].y>0LL)
			cout<<"1 "<<v[i].y<<" D\n";
		else if(v[i].y<0LL)
			cout<<"1 "<<labs(v[i].y)<<" U\n";
		cout<<"3\n";
	}
	return 0;
}