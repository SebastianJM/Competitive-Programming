// DYNAMIC PROGRAMMING 27/04/2016

#include <iostream>
#include <map>

using namespace std;
 
map<long long,long long> dp;
 
long long solve(long long num)
{
	if(!num)
		return 0;
	long long d=dp[num];
	if(d) 
		return d;
	d=max(num,solve(num/2)+solve(num/3)+solve(num/4));
	dp[num]=d;
	return d;
	
}
int main() 
{
	int n;
	while(cin>>n)
	{
		dp.clear();
		cout<<solve(n)<<endl;
	}
	return 0;
} 