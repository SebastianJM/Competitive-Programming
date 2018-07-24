#include <bits/stdc++.h>

using namespace std;

string unir(int a,int b,int can)
{
	string res;
	while(b>0)
	{
		res.push_back(b%10+'0');
		b/=10;
	}
	for(int i=res.length();i<can;i++)
		res.push_back('0');
	while(a>0)
	{
		res.push_back(a%10+'0');
		a/=10;
	}
	for(int i=res.length();i<can*2;i++)
		res.push_back('0');
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<string> val2,val4,val6,val8;
	for(int i=0;i<=9;i++)
		for(int e=0;e<=9;e++)
			if((i+e)*(i+e)==i*10+e)
				val2.push_back(unir(i,e,1));
	for(int i=0;i<=99;i++)
		for(int e=0;e<=99;e++)
			if((i+e)*(i+e)==i*100+e)
				val4.push_back(unir(i,e,2));
	for(int i=0;i<=999;i++)
		for(int e=0;e<=999;e++)
			if((i+e)*(i+e)==i*1000+e)
				val6.push_back(unir(i,e,3));
	for(int i=0;i<=9999;i++)
		for(int e=0;e<=9999;e++)
			if((i+e)*(i+e)==i*10000+e)
				val8.push_back(unir(i,e,4));
	while(cin>>n)
	{
		if(n==2)
			for(int i=0;i<val2.size();i++)
				cout<<val2[i]<<endl;
		else if(n==4)
			for(int i=0;i<val4.size();i++)
				cout<<val4[i]<<endl;
		else if(n==6)
			for(int i=0;i<val6.size();i++)
				cout<<val6[i]<<endl;
		else
			for(int i=0;i<val8.size();i++)
				cout<<val8[i]<<endl;
	}
	return 0;
}