#include <bits/stdc++.h>
using namespace std;

char matriz[205][205];
int x[6]={-1,-1,0,0,1,1};
int y[6]={-1,0,1,-1,0,1};
int n;
bool negroWins;
void isBlack(int i,int j)
{
	matriz[i][j]='.';
	for(int e=0;e<6;e++)
		if(matriz[i+y[e]][j+x[e]]=='b')
		{
			matriz[i+y[e]][j+x[e]]='.';
			if(i+y[e]==n)
				negroWins=true;
			isBlack(i+y[e],j+x[e]);
		}
}
int main()
{
	int t=1;
	//freopen ("out.txt","w",stdout);
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		memset(matriz,0,sizeof matriz);
		for(int i=1;i<=n;i++)
			for(int e=1;e<=n;e++)
				cin>>matriz[i][e];
		negroWins=false;
		for(int e=1;e<=n;e++)
			if(matriz[1][e]=='b')
				isBlack(1,e);
		cout<<t++<<" ";
		if(negroWins)
			cout<<'B'<<endl;
		else
			cout<<'W'<<endl;
	}
    return 0;
}