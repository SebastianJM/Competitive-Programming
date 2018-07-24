#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> grafo;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<int,int> iii;
typedef queue<int> cola;

#define INF 9999999

vi pset;
void init(int n) 
{ pset = vi(n); for(int i = 0; i < n; i++) pset[i] = i; }
int findSet(int i) 
{ return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int dfs_cont;
vi dfs_num;
vi dfs_low;

grafo g;

int R,C,Q;
void dfs_visit(int v, int p){
    dfs_num[v] = dfs_low[v] = dfs_cont++;
    for (int i = 0; i < (int)g[v].size(); i++) 
    {
        int u = g[v][i];
         
        if(dfs_num[u]<0){
            
            dfs_visit(u,v);
            if(dfs_low[u]> dfs_num[v])
	    {
           
                if(!isSameSet(u,v))
                    unionSet(u,v);
               
            }
                
            dfs_low[v] = min(dfs_low[v],dfs_low[u]);
        } 
	else if(u != p)
            dfs_low[v] = min(dfs_low[v],dfs_num[u]);
    }
}
void dfs()
{
    dfs_cont = 0;
    dfs_num = vi(R,-1);
    dfs_low = vi(R,INF);
    for (int i = 0; i < R; i++) 
    {  
        if(dfs_num[i]<0)         
            dfs_visit(i,-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    while(1)
    {
       cin >>R>>C>>Q;
       if(R==0 && C==0)
        return 0;
       g = grafo(R);
       init(R);
        for (int i = 0; i < C; i++) {
            int u,v;
            cin >> u>>v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
            
        }

        dfs();
      
        for (int i = 0; i < Q; i++) {
            int u,v;
            cin >> u >> v;
            u--;v--;
          
            if(isSameSet(u,v))
            cout <<"Y"<<endl;
            else 
            cout << "N"<< endl;
        }
        cout<<"-\n";
    }
    return 0;
}