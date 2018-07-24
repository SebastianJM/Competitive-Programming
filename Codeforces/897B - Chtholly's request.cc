#include <bits/stdc++.h>
using namespace std;

long long ans,a;
int k,p,con;
string s;
void gen(int x,int pos)
{
	if(pos>(x>>1)||con>=k)
		return;
	for(int i=(pos==1?1:0);i<=9;i++)
	{
		if(con>=k)
				return;
		s[pos-1]=s[x-pos]='0'+i;
		if(pos==(x>>1))
		{
	
			stringstream ss;
			ss<<s;
			ss>>a;
			ans=(ans+a)%p;
			con++;
			if(con>=k)
				return;
		}
		else
			gen(x,pos+1);
	}
	
}

int main() 
{
	cin>>k>>p;
	con=0;
	for(int i=2;i<=14;i+=2)
	{
		s=string(i,' ');

		gen(i,1);
		if(con>=k)
			break;
	}
		
	cout<<ans<<endl;
	return 0;
}