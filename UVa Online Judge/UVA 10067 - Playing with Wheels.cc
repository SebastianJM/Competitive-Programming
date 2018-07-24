#include <bits/stdc++.h>
using namespace std;

bool visitado[10005];
int distancia[10005];
int convertir(int vec[])
{
	int num=0;
	num+=vec[3];
	num+=vec[2]*10;
	num+=vec[1]*100;
	num+=vec[0]*1000;
	return num;
}

int main()
{
	int t,proh,aux,origen,destino;	
	int numero[4];
	//freopen ("out.txt","w",stdout);
	cin>>t;

	while(t--)
	{
		memset(visitado,0,sizeof visitado);
		memset(distancia,0,sizeof distancia);
		cin>>numero[0]>>numero[1]>>numero[2]>>numero[3];
		origen=convertir(numero);
		cin>>numero[0]>>numero[1]>>numero[2]>>numero[3];
		destino=convertir(numero);
		cin>>proh;
		for(int i=0;i<proh;i++)
		{
			cin>>numero[0]>>numero[1]>>numero[2]>>numero[3];
			aux=convertir(numero);
			visitado[aux]=true;
		}
		queue<int> cola;
		cola.push(origen);
		distancia[origen]=0;
		bool cumplio=false;
		while(!cola.empty() && !cumplio)
		{
			int nn=cola.front();		
			cola.pop();
			if(visitado[nn])
				continue;
			visitado[nn]=true;
			if(nn==destino)
			{
				cumplio=true;
				break;
			}
			numero[3]=nn%10;
			numero[2]=(nn/10)%10;
			numero[1]=(nn/100)%10;
			numero[0]=(nn/1000)%10;
			for(int i=0;i<4;i++)
			{
				numero[i]=(numero[i]+1)%10;
				aux=convertir(numero);
				if(!visitado[aux])
					cola.push(aux);
				distancia[aux]=distancia[nn]+1;
				numero[3]=nn%10;
				numero[2]=(nn/10)%10;
				numero[1]=(nn/100)%10;
				numero[0]=(nn/1000)%10;
			}
			for(int i=0;i<4;i++)
			{
				numero[i]-=1;
				if(numero[i]<0)
					numero[i]=9;
				aux=convertir(numero);
				if(!visitado[aux])
					cola.push(aux);
				distancia[aux]=distancia[nn]+1;
				
				numero[3]=nn%10;
				numero[2]=(nn/10)%10;
				numero[1]=(nn/100)%10;
				numero[0]=(nn/1000)%10;
			}
		}
		if(cumplio)
			cout<<distancia[destino]<<endl;
		else 
			cout<<-1<<endl;
	}
	
    return 0;
}