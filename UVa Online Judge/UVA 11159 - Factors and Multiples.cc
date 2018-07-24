#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n;
vvi g;
vi match; 
vb visit; 

int augmenting(int v) 
{
    if(visit[v]) 
        return 0;  
    visit[v] = true;
    for(int i = 0; i < (int)g[v].size(); i++) 
    {
        int u = g[v][i];
 
        if(match[u] == -1 || augmenting(match[u]))
        {
            match[u] = v; 
            return 1;    
        }
    }
    return 0; 
}

int MCBM(int left) 
{
    int ans = 0;       
    match = vi(n, -1);
    for(int i = 0; i < left; i++) 
    {
        visit = vb(left, false); 
        ans += augmenting(i);  
    }
    return ans;
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,a,b,q=1;
	vector<int> v_a,v_b;
	cin>>t;
	while(t--)
	{
		cin>>a;
		v_a=vector<int>(a);
		for(int i=0;i<a;i++)
			cin>>v_a[i];
		cin>>b;
		v_b=vector<int>(b);
		for(int i=0;i<b;i++)
			cin>>v_b[i];
		n=a+b;
	
		g=vvi(n);
		for(int i=0;i<a;i++)
			for(int e=0;e<b;e++)
			{			
				if(v_a[i]==0)
				{
					if(v_b[e]==0)
						g[i].push_back(a+e);
					continue;
				}
				if(v_b[e] % v_a[i]==0)
					g[i].push_back(a+e);				
			}

		cout<<"Case "<<q++<<": "<<MCBM(a)<<endl;
	}
	return 0;
}