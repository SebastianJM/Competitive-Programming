#include <bits/stdc++.h>

using namespace std;

int main() 
{
	long long suma[1003][1003];
	int n,m,pri=1;
	while(cin>>n)
	{
		cin>>m;
		if(!pri)
			cout<<endl;
		pri=0;
		memset(suma,0,sizeof suma);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>suma[i][j];
				if(i>0) suma[i][j]+=suma[i-1][j];
				if(j>0) suma[i][j]+=suma[i][j-1];
				if(i>0 && j>0) suma[i][j]-=suma[i-1][j-1];
			}
		long long s=0;
		m--;
		for(int i=0;i<n-m;i++) 
			for(int j=0;j<n-m;j++)
			{
				//cout<<i<<" "<<j<<endl;
				long long subR=suma[i+m][j+m];
				//cout<<subR<<endl;
				if(i>0) subR-=suma[i-1][j+m];
				//cout<<subR<<endl;
				if(j>0) subR-=suma[i+m][j-1];
				//cout<<subR<<endl;
				if(i>0 && j>0) subR+=suma[i-1][j-1];
				cout<<subR<<endl;
				s+=subR;
			}
		cout<<s<<endl;
	}
	return 0;
}