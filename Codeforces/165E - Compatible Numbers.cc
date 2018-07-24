#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 4194307
#define N 22
int getOnesComplement( int number)
{
	int ans=0;
	for(int i=0;i<N;i++)
		if(!(number&(1<<i)))
			ans|=(1<<i);
	return ans;
}
int main() 
{
	fastIO;
	int A[MAX],F[MAX],V[MAX],ans[MAX],te,n,x;


	memset(A,0,sizeof A);
	memset(F,0,sizeof F);
	memset(ans,0,sizeof ans);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>V[i];
		F[V[i]]++;
		ans[V[i]]=V[i];
	}

	for(int i = 0;i < N; i++) 
		for(int mask = 0; mask < (1<<N); mask++)
			if(mask & (1<<i))
			{
				F[mask] += F[mask^(1<<i)];
				if(ans[mask^(1<<i)])
					ans[mask]=ans[mask^(1<<i)];
			}
				
	for(int i=0;i<n;i++)
	{
		if(i)
			cout<<" ";
		int xd=getOnesComplement(V[i]);
		if(ans[xd])
			cout<<ans[xd];
		else
			cout<<-1;
	}
		
	
	
	return 0;
}