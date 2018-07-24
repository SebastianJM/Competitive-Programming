#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,w,f,c,din,suma[104][104];
	cin>>t;
	w=1;
	while(t--)
	{
		
		cin>>f>>c>>din;

		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				cin>>suma[i][j];
				if(i>0) suma[i][j]+=suma[i-1][j];
				if(j>0) suma[i][j]+=suma[i][j-1];
				if(i>0 && j>0) suma[i][j]-=suma[i-1][j-1];
			}
		int maxSub=2147483640;
		int terreno=-1;
		for(int i=0;i<f;i++) 
			for(int j=0;j<c;j++)
				for(int k=i;k<f;k++)
					for(int l=j;l<c;l++)
					{
						int subRect=suma[k][l];
						if(i>0) subRect-=suma[i-1][l];
						if(j>0) subRect-=suma[k][j-1];
						if(i>0 && j>0) subRect+=suma[i-1][j-1];
						if(subRect<=din)
						{
							if(terreno<(k-i+1)*(l-j+1) || (terreno==(k-i+1)*(l-j+1) && maxSub>subRect))
							{
								terreno=(k-i+1)*(l-j+1);
								maxSub=subRect;
							}						
						}
					}
		cout<<"Case #"<<w++<<": "<<(terreno>0?terreno:0)<<" "<<(terreno>0?maxSub:0)<<endl;
	}
	return 0;
}