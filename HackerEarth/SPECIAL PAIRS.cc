#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1048578
#define N 20
int getOnesComplement( int number){
   int ans=0;
   for(int i=0;i<N;i++)
	if(!(number&(1<<i)))
		ans|=(1<<i);
	return ans;
}
int main() 
{
	fastIO;
	int A[MAX],F[MAX],V[MAX],te,n,x;
 
	cin>>te;
	while(te--)
	{
		memset(A,0,sizeof A);
		memset(F,0,sizeof F);
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>V[i];
			A[V[i]]++;
		}
		for(int i = 0; i<(1<<N); i++)
			F[i] = A[i];
		for(int i = 0;i < N; i++) 
			for(int mask = 0; mask < (1<<N); mask++)
			{
				if(mask & (1<<i))
					F[mask] += F[mask^(1<<i)];
			}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			//cout<<F[V[i]]<<" ";
			//cout<<getOnesComplement(V[i])<<endl;
			ans+=F[getOnesComplement(V[i])];
		}
			
				
		cout<<ans<<endl;
	}
	
	return 0;
}