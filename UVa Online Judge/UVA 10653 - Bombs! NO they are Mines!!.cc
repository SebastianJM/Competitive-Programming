#include <bits/stdc++.h>
using namespace std;

char matriz[1005][1005];
bool visitado[1005][1005];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int inif,inic,finf,finc,res,f,c;

void bfs()
{
	queue<pair<pair<int,int>,int>> cola;
	pair<pair<int,int>,int> aux;
	visitado[inif][inic]=true;
	int yy,xx,dis;
	bool cumplio=false;
	for(int i=0;i<4;i++)
		if(inif+y[i]<f && inif+y[i]>=0 && inic+x[i]<c && inic+x[i]>=0 && matriz[inif+y[i]][inic+x[i]]==0)
			cola.push(pair<pair<int,int>,int >(pair<int,int>(inif+y[i],inic+x[i]),1));
	while(!cumplio)
	{
		yy=cola.front().first.first;
		xx=cola.front().first.second;
		dis=cola.front().second;
		cola.pop();
		if(yy==finf && xx==finc)
		{
			cumplio=true;
			res=dis;
			break;
		}
		for(int i=0;i<4;i++)
			if(yy+y[i]<f && yy+y[i]>=0 && xx+x[i]<c && xx+x[i]>=0 && !visitado[yy+y[i]][xx+x[i]] && matriz[yy+y[i]][xx+x[i]]==0)
			{
				visitado[yy+y[i]][xx+x[i]]=true;
				cola.push(pair<pair<int,int>,int >(pair<int,int>(yy+y[i],xx+x[i]),dis+1));
			}

	}
}
int main()
{
	int b,s,q,a;
	while(1)
	{
		cin>>f>>c;
		if(!f && !c)
			break;
		memset(matriz,0,sizeof matriz);
		memset(visitado,0,sizeof visitado);
		cin>>b;
		for(int i=0;i<b;i++)
		{
			cin>>s;
			cin>>q;
			while(q--)
			{
				cin>>a;
				matriz[s][a]='.';
			}	
		}
		cin>>inif>>inic>>finf>>finc;
		bfs();
		cout<<res<<endl;

	}
    return 0;
}