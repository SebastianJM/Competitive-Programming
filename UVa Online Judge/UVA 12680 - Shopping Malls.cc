#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair <double,int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<bool> vb;



struct nodo
{
    int piso,x,y;
    nodo(int ppiso,int px,int py):piso(ppiso),x(px),y(py){}
};

typedef vector<nodo> pn;
int N,M;
vvii g;
vd dist;
vi prevv;
vi path;
pn places;

void init()
{
    prevv=vi(N,-1);
    dist=vd(N,1e9);
}
void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,s));
    dist[s]=0;
    while(!pq.empty())
    {
        double d=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(dist[v]>=d)
        {
            for(int i=0;i<(int)g[v].size();i++)
            {
                int u=g[v][i].second;
                double w=g[v][i].first;
                if(dist[v]+w<dist[u])
                {
                    dist[u]=dist[v]+w;
                    prevv[u]=v;
                    pq.push(ii(dist[u],u));
                }
            }
        }
    }
}
int main()
{
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    string s;
    bool pri=true;

    while(cin>>N>>M)
    {
    	if(!pri)
    		cout<<endl;
    	pri=false;
        places=pn(N,nodo(0,0,0));
        g=vvii(N);
        init();
        for(int i=0;i<N;i++)
            cin>>places[i].piso>>places[i].x>>places[i].y;
            
        for(int i=0;i<M;i++)
        {
            cin>>a>>b>>s;
            if(s=="walking")
            {
                double dis=sqrt(pow(places[a].x-places[b].x,2)+pow(places[a].y-places[b].y,2));
                g[a].push_back(ii(dis,b));
                g[b].push_back(ii(dis,a));
            }
            else if(s=="stairs")
            {
                double dis=sqrt(pow(places[a].x-places[b].x,2)+pow(places[a].y-places[b].y,2)+pow((places[a].piso-places[b].piso)*5,2));
                g[a].push_back(ii(dis,b));
                g[b].push_back(ii(dis,a));
            }
            else if(s=="lift")
            {
                g[a].push_back(ii(1,b));
                g[b].push_back(ii(1,a));
            }
            else
            {
                double dis=sqrt(pow(places[a].x-places[b].x,2)+pow(places[a].y-places[b].y,2)+pow((places[a].piso-places[b].piso)*5,2))*3;
                g[a].push_back(ii(1,b));
                g[b].push_back(ii(dis,a));
            }
            
        }
        
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
        	
            cin>>a>>b;
            init();
            dijkstra(a);
            
            path=vi();
            int aux=b;
            path.push_back(b);
            
            while(aux!=a)
            {
                aux=prevv[aux];
                path.push_back(aux);
            }
            
            for(int e=path.size()-1;e>=0;e--)
            {
            	if(path.size()-1!=e)
            		cout<<" ";
                cout<<path[e];
            }
            cout<<endl;
        }
        
    }
    
    
    
    return 0;
}
