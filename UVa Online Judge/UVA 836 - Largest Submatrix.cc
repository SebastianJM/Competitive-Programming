#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,pri=1;
	string a;
	int suma[26][26];
	cin>>n;
	
	while(n--)
	{
		if(pri)
			pri=0;
		else
			cout<<endl;
		cin>>a;
		int tam=a.length();
		for(int i=0;i<tam;i++)
			suma[0][i]=a[i]-'0';
		for(int i=1;i<tam;i++)
		{
			cin>>a;
			for(int e=0;e<tam;e++)
				suma[i][e]=a[e]-'0';
		}
		for(int i=0;i<tam;i++)
			for(int j=0;j<tam;j++)
			{
				if(i>0) suma[i][j]+=suma[i-1][j];
				if(j>0) suma[i][j]+=suma[i][j-1];
				if(i>0 && j>0) suma[i][j]-=suma[i-1][j-1];
			}
		int maxSub=-25;
		for(int i=0;i<tam;i++) 
			for(int j=0;j<tam;j++)
				for(int k=i;k<tam;k++)
					for(int l=j;l<tam;l++)
					{
						int subRect=suma[k][l];
						if(i>0) subRect-=suma[i-1][l];
						if(j>0) subRect-=suma[k][j-1];
						if(i>0 && j>0) subRect+=suma[i-1][j-1];
						if((k-i+1)*(l-j+1)==subRect)
							maxSub=max(maxSub,subRect);
					}
		cout<<(maxSub<0?0:maxSub)<<endl;
	}
	return 0;
}