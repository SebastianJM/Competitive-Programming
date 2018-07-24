#include <bits/stdc++.h>
using namespace std;
 
int ar[8]={1,3,9,27,81,243,729,2187};
int n;
string ans;
bool backtrack(int suma,int in)
{
	if(suma==n)
		return true;
	if(in>=8)
		return false;
	if(backtrack(suma+ar[in],in+1))
	{
		ans+="+";
		return true;
	}
	else if(backtrack(suma,in+1))
	{
		ans+="0";
		return true;
	}
	else if(backtrack(suma-ar[in],in+1))
	{
		ans+="-";
		return true;
	}
	
	return false;
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		ans="";
		cin>>n;
		backtrack(0,0);
		cout<<ans<<"\n";
	}
	
	return 0;
} 