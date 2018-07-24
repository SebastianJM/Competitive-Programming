#include <bits/stdc++.h>
using namespace std;
 
#define MAX 100004
int main() 
{
	int t,n;
	vector<pair<int,int> > vp;
	int v[MAX],ans[MAX],con;
	bool visited[MAX];
	cin>>t;
	while(t--)
	{
		cin>>n;
		vp=vector<pair<int,int> >(n);
		con=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			vp[i].first=v[i];
			vp[i].second=i;
		}
		sort(v,v+n);
		sort(vp.begin(),vp.end());
		queue<int> q;
		for(int i=0;i<n;i++)
			q.push(v[i]);
		for(int i=0,z=0;i<n;i++)
		{
			//cout<<vp[i].first<<" "<<q.front()<<endl;
			if(vp[i].first==q.front())
			{
				q.push(q.front());
				q.pop();
				if(vp[i].first==q.front())
				{
					q.push(q.front());
					q.pop();
					if(vp[i].first==q.front())
					{
						ans[vp[i].second]=q.front();
						q.pop();
						continue;
					}
				}
			}
			if(vp[i].first!=q.front())
				con++;
			ans[vp[i].second]=q.front();
			q.pop();
			
		}
		cout<<con<<endl;
		for(int i=0;i<n;i++)
		{
			if(i>0)
				cout<<" ";
			cout<<ans[i];	
		}
			
		cout<<endl;
	}
	return 0;
}