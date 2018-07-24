#include <bits/stdc++.h>
using namespace std;

#define VAL 1000000007

int mod(int a, int b)
{ 
	return (a%b+b)%b; 
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a,b,n,t,v[1000000],i;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		v[1]=mod(a,VAL),v[2]=mod(b,VAL);
		//cout<<v[1]<<" "<<v[2]<<endl;
		i=3;
		int carry=-1,must;
		while(1)
		{
			v[i]=mod(v[i-1]-v[i-2],VAL);
			//cout<<i<<" "<<v[i]<<endl;
			for(int e=2;e<i;e++)
				if(v[i]==v[e] && v[i-1]==v[e-1])
				{
					carry=e-2;
					must=i-2;
					break;
				}
			if(carry>=0)
				break;
			i++;
		}
		//cout<<"-----"<<carry<<" "<<must<<endl;
		v[0]=v[must];
		if(n<=must)
			cout<<v[n]<<endl;
		else
			cout<<v[n%(must-carry)]<<endl;
	}
	return 0;
}