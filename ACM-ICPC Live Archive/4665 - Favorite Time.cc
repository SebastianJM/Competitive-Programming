#include <bits/stdc++.h>

using namespace std;

string s;
int v[1500];
int conv()
{
	return ((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
}
string conv_i(int n)
{
	
	string ans=to_string(n/600)+to_string((n/60)%10)+":"+to_string((n%60)/10)+to_string((n%60)%10);
	return ans;
}
int main() 
{
	int n,t,a,b,maxi;
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxi=0;
		memset(v,0,sizeof v);
		for(int i=0;i<n;i++)
		{
			cin>>s;
			a=conv();
			cin>>s;
			b=conv();
			
			for(int i=a;i<=b;i++)
			{
				v[i]++;
				maxi=max(maxi,v[i]);
			}
		}
		int con=0,aux,aa,bb;
		for(int i=0;i<1445;i++)
		{
			aux=0;
			while(v[i]==maxi)
			{
				aux++;
				i++;
				con=aux;
				aa=i-aux;
				bb=i-1;
				
			}
			if(con>0)
				break;
			
		}
		cout<<conv_i(aa)<<" "<<conv_i(bb)<<endl;
	}
	
	return 0;
}