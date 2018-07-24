#include <bits/stdc++.h>
using namespace std;

char matriz[1005][1005];
int visitado[1005][1005];
vector<pair<int,int> > fuego;
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int inif,inic,res,f,c;

void bfs()
{
	queue<pair<pair<int,int>,int> > cola;
	pair<pair<int,int>,int> aux;
	visitado[inif][inic]=1;
	int yy,xx,dis;
	bool cumplio=false;
	for(int e=0;e<fuego.size();e++)
		for(int i=0;i<4;i++)
			if(fuego[e].first+y[i]<f && fuego[e].first+y[i]>=0 && fuego[e].second+x[i]<c 
				&& fuego[e].second+x[i]>=0 && visitado[fuego[e].first+y[i]][fuego[e].second+x[i]]<2) 
			//&& matriz[fuego[e].first+y[i]][fuego[e].second+x[i]]==0)
			{
				visitado[fuego[e].first+y[i]][fuego[e].second+x[i]]=2;
				cola.push(pair<pair<int,int>,int >(pair<int,int>(fuego[e].first+y[i],fuego[e].second+x[i]),-1));
			}
	for(int i=0;i<4;i++)
		if(inif+y[i]<f && inif+y[i]>=0 && inic+x[i]<c && inic+x[i]>=0)
		{
			 if(!visitado[inif+y[i]][inic+x[i]])
			 {
				visitado[inif+y[i]][inic+x[i]]=1;
				cola.push(pair<pair<int,int>,int >(pair<int,int>(inif+y[i],inic+x[i]),1));	
			 }
		}
		else
		{
			cumplio=true;
			res=1;
			break;
		}
	while(!cola.empty() && !cumplio)
	{
		yy=cola.front().first.first;
		xx=cola.front().first.second;
		dis=cola.front().second;
		cola.pop();
	
		for(int i=0;i<4;i++)
		{
			if(yy+y[i]<f && yy+y[i]>=0 && xx+x[i]<c && xx+x[i]>=0)
			{
				if(dis==-1 && visitado[yy+y[i]][xx+x[i]]<2/* && matriz[yy+y[i]][xx+x[i]]==0*/)
				{
					visitado[yy+y[i]][xx+x[i]]=2;
					cola.push(pair<pair<int,int>,int >(pair<int,int>(yy+y[i],xx+x[i]),-1));
				}
				else if(dis>=0 && visitado[yy+y[i]][xx+x[i]]==0)
				{
					visitado[yy+y[i]][xx+x[i]]=1;
					cola.push(pair<pair<int,int>,int >(pair<int,int>(yy+y[i],xx+x[i]),dis+1));
				}

			}
			else if(dis>=0)
			{
				cumplio=true;
				res=dis+1;
				break;
			}
		}

	}
}
int main()
{
	int t;
	//freopen ("out.txt","w",stdout);

	cin>>t;
	while(t--)
	{
		cin>>f>>c;
		memset(matriz,0,sizeof matriz);
		memset(visitado,0,sizeof visitado);
		fuego=vector<pair<int,int> >();
		res=-1;
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
			{
				cin>>matriz[i][e];
				if(matriz[i][e]=='#')
					visitado[i][e]=5;
				else if(matriz[i][e]=='F')
				{
					visitado[i][e]=2;
					fuego.push_back(pair<int,int>(i,e));
				}
				else if(matriz[i][e]=='J')
				{
					inif=i;
					inic=e;
				}
			}
		bfs();
		if(res>=0)
			cout<<res<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
    return 0;
}