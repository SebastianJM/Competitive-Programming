#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

ll nb,ns,nc,pb,ps,pc,xb=0,xs=0,xc=0,ans=0,cost;
ll fun(ll x)
{
	ll b=xb*x,s=xs*x,c=xc*x;
	ll t=(b>nb?(b-nb)*pb:0)+(s>ns?(s-ns)*ps:0)+(c>nc?(c-nc)*pc:0);
	return t;
}
int main() 
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='B')
			xb++;
		else if(s[i]=='S')
			xs++;
		else
			xc++;

	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>cost;
	ll lo=0,hi=2000000000004;
	while(lo<hi)
	{
		ll mid=lo+(hi-lo+1)/2;
		if(fun(mid)>cost)
			hi=mid-1;
		else
			lo=mid;
	}
	cout<<lo<<endl;
	return 0;
}