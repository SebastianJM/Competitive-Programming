#include <bits/stdc++.h>

using namespace std;

int n,c,res;
int x[8]={0,0,1,1,1,-1,-1,-1};
int y[8]={1,-1,-1,0,1,-1,0,1};
vector<string> m,mm;

void filll(int i,int j)
{
	res++;
	mm[i][j]='L';
	for(int e=0;e<8;e++)
		if(i+x[e]>=0 && i+x[e]<n && j+y[e]>=0 && j+y[e]<c && mm[i+x[e]][j+y[e]]=='W')
		{
			mm[i+x[e]][j+y[e]]='L';
			filll(i+x[e],j+y[e]);		
		}
}
int main()
{
	int t=0;
	string a;
	cin>>t;
	getchar();
	getchar();
	while(t--)
	{
		n=0;
		m=vector<string>();
		
		while(1)
		{
			getline(cin,a);
			if(a[0]!='L' && a[0]!='W')
				break;
			m.push_back(a);
			n++;
		}
		c=m[n-1].size();
		int u,v;
		while(1)
		{
			sscanf(&a[0u], "%d %d", &u, &v);
			res=0;
			mm=m;
			if(m[u-1][v-1]=='W')
				filll(u-1,v-1);
			cout<<res<<endl;
			getline(cin,a);
			if(a.size()==0)
				break;
		}
		if(t!=0)
			cout<<endl;
	}
	
	return 0;
}