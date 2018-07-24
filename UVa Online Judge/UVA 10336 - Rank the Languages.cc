#include <bits/stdc++.h>
using namespace std;

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
vector<vector<char> > matriz;
vector<pair<int,char> > res;

bool funcion(pair<int,char> a,pair<int,char> b)
{
	if(a.first>b.first)
		return false;
	else if(a.first==b.first)
	{
		if(a.second>b.second)
			return true;
		else
			return false;
	}
	else
		return true;

}
void dfs(int i,int j,char simb)
{
	matriz[i][j]='*';
	for(int e=0;e<4;e++)
		if(matriz[i+x[e]][j+y[e]]==simb)
		{
			matriz[i+x[e]][j+y[e]]='*';
			dfs(i+x[e],j+y[e],simb);
		}
}
int main()
{	
	int t,f,c,q;
	char a;
	cin>>t;
	q=t;
	while(t--)
	{
		cin>>f>>c;
		matriz=vector<vector<char> >(f+1);
		matriz[0]=vector<char>(c+1,'*');
		for(int i=1;i<=f;i++)
		{
			matriz[i].push_back('*');
			for(int e=0;e<c;e++)
			{
				cin>>a;
				matriz[i].push_back(a);
			}
			matriz[i].push_back('*');
		}
		matriz.push_back(vector<char>(c+1,'*'));
		res=vector<pair<int,char> >(26,pair<int,char>(0,'z'));
		for(int i=1;i<f+1;i++)
			for(int e=1;e<c+1;e++)
				if(matriz[i][e]!='*')
				{
					res[matriz[i][e]-'a'].first++;
					res[matriz[i][e]-'a'].second=matriz[i][e];
					dfs(i,e,matriz[i][e]);
				}
		cout<<"World #"<<q-t<<endl;
		sort(res.rbegin(),res.rend(),funcion);
		for(int i=0;i<26;i++)
			if(res[i].first>0)
				cout<<res[i].second<<": "<<res[i].first<<endl;
	}
	return 0;
}