#include <bits/stdc++.h>

using namespace std;

int x[8]={0,0,1,-1,-1,-1,1,1};
int y[8]={1,-1,0,0,1,-1,1,-1};
int main() 
{
	int ans[104][104],f,c,p=1;
	bool first=true;
	char m[104][104];
	while(1)
	{
		cin>>f>>c;
		if(!f && !c)
			break;
		if(!first)
			cout<<"\n";
		first=false;
		memset(ans,0,sizeof ans);
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				cin>>m[i][j];
				if(m[i][j]=='*')
					for(int k=0;k<8;k++)
						if(i+y[k]>=0 && i+y[k]<f && j+x[k]>=0 && j+x[k]<c)
							ans[i+y[k]][j+x[k]]++;
			}
		cout<<"Field #"<<p++<<":\n";
		for(int i=0;i<f;i++)
		{
			for(int j=0;j<c;j++)
				if(m[i][j]=='*')
					cout<<"*";
				else
					cout<<ans[i][j];
			cout<<"\n";
		}
				
	}
	return 0;
}