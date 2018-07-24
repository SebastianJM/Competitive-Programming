
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,m,ans=0;
	cin>>n>>m;
	bool danceH[102],danceM[102];
	int resH[10002],resM[10002];
	memset(danceH,0,sizeof danceH);
	memset(danceM,0,sizeof danceM);
	for(int i=0;i<n;i++)
	
			for(int e=0;e<m;e++)
				if(!danceH[i]||!danceM[e])
				{
					danceH[i]=danceM[e]=true;
					resH[ans]=i+1,resM[ans]=e+1;
					ans++;
				}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
		cout<<resH[i]<<" "<<resM[i]<<endl;
	return 0;
}