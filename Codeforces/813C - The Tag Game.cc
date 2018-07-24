#include <bits/stdc++.h>

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using namespace std;

#define MAX 300004
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n,maxlen,ori;
vvi g;
queue<int> poss,alice,aux2;
queue<pair<int,int> > aux1;
int stepsBob;
bool danger[MAX],visit[MAX];
void dfsB(int x)
{
	if(danger[x])
		return;
    if(!visit[x])
        stepsBob++;
    //cout<<"VISITA BOB: "<<x<<" "<<stepsBob<<endl;
    visit[x]=true;
    for(int i=0;i<g[x].size();i++)
        if(!visit[g[x][i]] && !danger[g[x][i]])
        {
            aux1.push(make_pair(x,g[x][i]));
        }
}
void dfsA(int x)
{
    danger[x]=true;
    if(visit[x])
                stepsBob--;
    //cout<<"VISITA alice: "<<x<<" "<<stepsBob<<endl;
    for(int i=0;i<g[x].size();i++)
        if(!danger[g[x][i]])
        {
            
            aux2.push(g[x][i]);
        }
}
void dfs()
{
    maxlen=0;
    stepsBob=0;

    danger[0]=true;
    poss.push(ori-1);
    alice.push(0);
    while(!poss.empty())
    {
        while(!poss.empty())
        {
        	dfsB(poss.front());
        	poss.pop();
        }
        
        while(!alice.empty())
        {
        	dfsA(alice.front());
        	alice.pop();
        }
        while(!aux1.empty())
        {
        	if(!danger[aux1.front().first])
        		poss.push(aux1.front().second);
        	aux1.pop();
        }
        while(!aux2.empty())
        {
        	alice.push(aux2.front());
        	aux2.pop();
        }
        maxlen+=2;
    }
    //cout<<"SERPA"<<endl;
    
    while(stepsBob>0)
    {
    	//cout<<alice.size()<<" "<<stepsBob<<endl;
        while(!alice.empty())
        {
        	dfsA(alice.front());
        	
        	alice.pop();
        }
        while(!aux2.empty())
        {
        	alice.push(aux2.front());
        	aux2.pop();
        }
        maxlen+=2;
    }
}
int main() 
{
    fastIO;
    int x,y;
    cin>>n>>ori;
    g=vvi(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(visit,false,sizeof visit);
    memset(danger,false,sizeof danger);

    dfs();
    cout<<maxlen-2<<endl;
    return 0;
}