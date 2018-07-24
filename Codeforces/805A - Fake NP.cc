#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int l,r,nl,nr,ans=-1,a=-1,con=-1;
	cin>>l>>r;
	for(int i=2;i<=sqrt(r);i++)
	{
		con=0;
		if(l%i!=0)
			nl=l+(i-(l%i));
		else
			nl=l;
		nl/=i;
		if(r%i!=0)
			nr=r-(r%i);
		else
			nr=r;
		nr/=i;
		//cout<<nl<<" "<<nr<<" "<<i<<endl;
		if(nl<=nr)
			con=nr-nl+1;
		if(con>a)
		{
			a=con;
			ans=i;
		}
	}
	con=0;
	nl=l;
	nl/=l;
	if(r%l!=0)
		nr=r-(r%l);
	else
		nr=r;
	nr/=l;
	if(nl<=nr)
		con=nr-nl+1;
	if(con>a)
	{
		a=con;
		ans=l;
	}
	con=1;
	if(con>a)
	{
		a=con;
		ans=r;
	}
	cout<<ans<<"\n";
	return 0;
}