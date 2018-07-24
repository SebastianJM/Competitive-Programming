#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int v[4];
	int t;
	cin>>t;
	while(t--)
	{
		
		for(int i=0;i<4;i++)
			cin>>v[i];
		for(int i=1;i<(1<<4);i++)
		{
			int ans=0;
			for(int j=0;j<4;j++)
				if((1<<j)&i)
					ans+=v[j];
			
			if(!ans)
			{
				
				cout<<"Yes"<<endl;
				break;
			}
			else if(i==(1<<4)-1)
				cout<<"No"<<endl;
		}
		
	}
	return 0;
} 