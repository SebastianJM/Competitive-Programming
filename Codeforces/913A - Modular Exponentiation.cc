#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1005

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;
ll pot(int n)
{
  ll ans=1;
  while(n)
  {
    ans*=2;
    n--;
  }
  return ans;
}
int main() 
{
	fastIO;
	ll n;
	int k,a;
	 
	cin>>a;
	n=a;
	cin>>k;
	ll con=ceil(log2(k));
	if(con>=n)
	{
	  ll ans=k%(pot(a));
	  cout<<ans<<endl;
	}
	  
	else
	  cout<<k<<endl;

	return 0;
}