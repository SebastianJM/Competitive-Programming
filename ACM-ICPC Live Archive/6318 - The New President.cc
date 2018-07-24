#include <bits/stdc++.h>
using namespace std;

#define MAX 103
bool f(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first>b.first;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,mat[MAX][MAX],c,v,a;
	pair<int,int> p_r[MAX];
	cin>>t;
	while(t--)
	{
		cin>>c>>v;
		for(int i=0;i<c;i++)
		{
			p_r[i].first=0;
			p_r[i].second=i;
		}
		for(int i=0;i<v;i++)
		{
			cin>>a;
			a--;
			mat[i][a]=0;
			p_r[a].first++;
			for(int j=1;j<c;j++)
			{
				cin>>a;
				a--;
				mat[i][a]=j;
			}
		}

		sort(p_r,p_r+c,f);

		if(p_r[0].first>(floor(v/2)))
			cout<<p_r[0].second+1<<" 1\n";
		else
		{
			int x=p_r[0].second;
			int y=p_r[1].second;
			int c_x,c_y;
			c_x=c_y=0;
			for(int i=0;i<v;i++)
			{
				if(mat[i][x]<mat[i][y])
					c_x++;
				else
					c_y++;
			}
			cout<<(c_x>c_y?(x+1):(y+1))<<" 2\n";
		}
	}
	return 0;
}
