#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> Pii;
typedef vector<int> Vii;
typedef vector<Pii> VPii;
typedef vector<VPii> VVPii;

class LonglongestPathTree
{
	public:
	bool visit[2003];
	VVPii g;
	Pii furthest(int x)
	{
	    queue<Pii> q;
	    q.push(Pii(x,0));
	    int no=x;
	    ll ans=0,y;
	    while(!q.empty())
	    {
	        x=q.front().first;
	        y=q.front().second;
	        q.pop();
	        if(y>ans)
	        {
	            no=x;
	            ans=y;
	        }
	        visit[x]=true;
	        for(int i=0;i<g[x].size();i++)
	            if(!visit[g[x][i].first])
	            {
	                visit[g[x][i].first]=true;
	                q.push(Pii(g[x][i].first,y+g[x][i].second));
	            }
	    }
	    return Pii(no,ans);
	}
	long long getLength(vector <int> A, vector <int> B, vector <int> L)
	{
		int N=A.size()+1;
	    g=VVPii(N);
	    for(int i=0;i<N-1;i++)
	    {
	        g[A[i]].push_back(Pii(B[i],L[i])); 
	        g[B[i]].push_back(Pii(A[i],L[i]));
	    }
	    ll ans=0,d1,d2;
	    Pii up;
	    for(int i=0;i<N-1;i++)
	    {
	  
			d1=d2=0;
	        int f1;
	        
	        memset(visit,false,sizeof visit); 
	        visit[B[i]]=true;
	        f1=furthest(A[i]).first;
	        memset(visit,false,sizeof visit);
	        visit[B[i]]=true;
	        up=furthest(f1);
	        d1=up.second;    
	        
	        memset(visit,false,sizeof visit);
	        visit[A[i]]=true;
	        f1=furthest(B[i]).first;
	        memset(visit,false,sizeof visit);
	        visit[A[i]]=true;
	        up=furthest(f1);
	        d2=up.second;
	        
	        ans=max(ans,d1+d2+L[i]);
	    }
	    return ans;
	}
};
