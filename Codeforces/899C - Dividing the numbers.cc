#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000105


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
int main() 
{
	fastIO;
	
	ull c=0,d=0,n;
	cin>>n;
	ull cont=n*(n+1ULL)/4ULL;
	vull nums;
	for(ull i=n;i>=1ULL;i--)
	{
		if(i+c<=cont)
		{
			c+=i;
			nums.push_back(i);
		}
		else
			d+=i;
	}
	cout<<(d!=c?1:0)<<"\n";
	cout<<nums.size();
	for(int i=0;i<nums.size();i++)
	{
		cout<<" "<<nums[i];
	}
	cout<<"\n";
	return 0;
} 