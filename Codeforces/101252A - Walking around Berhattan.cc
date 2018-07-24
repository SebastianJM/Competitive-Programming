#include <bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m[500][500];
	bool visit[500][500];
	int f,c;
	memset(m,0,sizeof m);
	memset(visit,false,sizeof visit);
	cin>>f>>c;
	string s;
	
	for(int i=0,a=1;i<f;i++,a+=2)
	{
		cin>>s;
		for(int e=0,b=1,i;e<c;e++,b+=2)
		{
			m[a][b]=s[e]-'0';
		}
	}

	cin>>s;

	int dir=0,x=0,y=0,ans=0;
	
	for(int i=0;i<s.size();i++)
	{
		
		if(s[i]=='R')
		{
			dir++;
			dir%=4;
		}
		else if(s[i]=='L')
		{
			dir--;
			if(dir<0)
				dir=3;
		}
		else
		{
			
			if(dir==0) //derecha
			{
				
				if(y!=0)
				{
					if(!visit[y-1][x+1])
						ans+=m[y-1][x+1];
					else
						ans+=m[y-1][x+1]/2;
					visit[y-1][x+1]=true;
				}
				if(y!=f*2)
				{
					if(!visit[y+1][x+1])
						ans+=m[y+1][x+1];
					else
						ans+=m[y+1][x+1]/2;
					visit[y+1][x+1]=true;
				}
				x+=2;
			}
			else if(dir==1) //ARRIBA
			{
				if(x!=0)
				{
					if(!visit[y+1][x-1])
						ans+=m[y+1][x-1];
					else
						ans+=m[y+1][x-1]/2;
					visit[y+1][x-1]=true;
				}
				if(x!=2*c)
				{
					if(!visit[y+1][x+1])
						ans+=m[y+1][x+1];
					else
						ans+=m[y+1][x+1]/2;
					visit[y+1][x+1]=true;
				}
				y+=2;
			}
			else if(dir==2) //izquierda
			{
				if(y!=0)
				{
					if(!visit[y-1][x-1])
						ans+=m[y-1][x-1];
					else
						ans+=m[y-1][x-1]/2;
					visit[y-1][x-1]=true;
				}
				if(y!=f*2)
				{
					if(!visit[y+1][x-1])
						ans+=m[y+1][x-1];
					else
						ans+=m[y+1][x-1]/2;
					visit[y+1][x-1]=true;
				}
				x-=2;
			}
			else if(dir==3) // ABAJO
			{
				if(x!=0)
				{
					if(!visit[y-1][x-1])
						ans+=m[y-1][x-1];
					else
						ans+=m[y-1][x-1]/2;
					visit[y-1][x-1]=true;
				}
				if(x!=2*c)
				{
					if(!visit[y-1][x+1])
						ans+=m[y-1][x+1];
					else
						ans+=m[y-1][x+1]/2;
					visit[y-1][x+1]=true;
				}
				y-=2;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}