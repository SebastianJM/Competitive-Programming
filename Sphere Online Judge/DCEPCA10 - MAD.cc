#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
 
using namespace std;
 
int main()
{
	int T,N,tmp,tam,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		map<int,int>M;
		tam=(N/2)+1;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&tmp);
			M[tmp]++;
			
		}	
		vector<pair<int,int> >v(M.begin(),M.end());
		ans=0;
		for(int i=0;i<v.size();i++){
			ans=max(ans,v[i].second);
		}
		ans=max(0,tam-ans);
		printf("%d\n",ans);
	}	
	return 0;
} 