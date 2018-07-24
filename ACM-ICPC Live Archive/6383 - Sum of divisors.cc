#include <bits/stdc++.h>
using namespace std;

vector<char> toBase(int n, int b)
{
	vector<char> s;
	do{
		int d = n % b;
		n /= b;
		s.push_back( (d < 10)? (d + '0') : ('A' + d - 10) );
	}while(n != 0);
	reverse(s.begin(), s.end());
	return s;
}

vector<int> divisors(int n)
{
	vector<int> div;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0)
		{
			div.push_back(i);
			if(i*i!=n)
				div.push_back(n/i);
		}
	//div.push_back(n);
	return div;
}

void solve(int n,int b)
{
	vector<char> ans;
	vector<int> div=divisors(n);
	int sol=0;
	for(int i=0;i<div.size();i++)
	{
		ans=toBase(div[i],b);
		for(int j=0;j<ans.size();j++)
			if(isdigit(ans[j]))
				sol+=pow(ans[j]-'0',2);
			else
				sol+=pow(ans[j]-'A'+10,2);
	}
	ans=toBase(sol,b);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
	cout<<endl;
}
int main() 
{
	int n,b;

	while(cin>>n>>b)
	{
		solve(n,b);
	}
	return 0;
}