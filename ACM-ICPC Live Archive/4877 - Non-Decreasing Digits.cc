#include <bits/stdc++.h>

using namespace std;

long long dp[66][11];
int n;

long long recur(int pos, int dig)
{
    if(pos==n) 
		return 1;
    long long &res = dp[pos][dig];
    if(res!=-1) 
		return res;
    res = 0;
    for(int i=dig; i<10; i++) 
		res+=recur(pos+1,i);
    return res;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int a, t;
    cin>>a;
    while(a--)
    {
        cin>>t>>n;
        memset(dp,-1,sizeof dp);
        cout<<t<<" "<<recur(0,0)<<endl;
    }
    return 0;
}