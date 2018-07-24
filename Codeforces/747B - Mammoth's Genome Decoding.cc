#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	map<char,int> mp,re;
	mp['A']=0;
	mp['C']=1;
	mp['G']=2;
	mp['T']=3;
	re[0]='A';
	re[1]='C';
	re[2]='G';
	re[3]='T';
	int v[4];
	memset(v,0,sizeof v);
	string s;
	cin>>s;
	if(s.size()%4!=0)
	{
		cout<<"==="<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++)
		if(s[i]!='?')
			v[mp[s[i]]]++;
	int maxi=s.size()/4;
	for(int i=0;i<4;i++)
	{
		if(v[i]>maxi)
		{
			cout<<"==="<<endl;
			return 0;
		}
		v[i]=maxi-v[i];
		
	}

	for(int i=0;i<s.size();i++)
		if(s[i]=='?')
		{
			//cout<<10<<endl;
			for(int j=0;j<4;j++)
				if(v[j]>0)
				{
					s[i]=re[j];
					v[j]--;
					break;
				}
		}
	cout<<s<<endl;
	return 0;
}