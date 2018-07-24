#include <bits/stdc++.h>

using namespace std;

int n,c,res;
int x[8]={0,0,1,1,1,-1,-1,-1};
int y[8]={1,-1,-1,0,1,-1,0,1};
vector<string> m;

void filll(int i,int j)
{
	res++;
	m[i][j]='0';
	for(int e=0;e<8;e++)
		if(i+x[e]>=0 && i+x[e]<n && j+y[e]>=0 && j+y[e]<c && m[i+x[e]][j+y[e]]=='1')
		{
			m[i+x[e]][j+y[e]]='0';
			filll(i+x[e],j+y[e]);		
		}
}
int main()
{
	int t;
	cin>>t;
	getchar();
	getchar();
	while(t--)
	{
		n=0;
		m=vector<string>(26);
		
		while(1)
		{
			getline(cin,m[n]);
			if(m[n].size()==0)
				break;
			n++;
		}
		c=m[n-1].size();
		int maxi=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<c;j++)
				if(m[i][j]=='1')
				{
					res=0;
					filll(i,j);
					if(res>maxi)
						maxi=res;
				}
		cout<<maxi<<endl;
		if(t!=0)
			cout<<endl;
	}
	
	return 0;
}