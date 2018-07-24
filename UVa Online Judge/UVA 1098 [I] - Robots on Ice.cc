#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <string> 
#include <queue>
#include <fstream>
#include <map>
#include <math.h>
//#include <bits/stdc++.h>
using namespace std;

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int checkx[3],checky[3],orden[3];
int f,c,res,bu;

int manhattan(int x1, int y1, int x2, int y2) 
{
    return abs(x1 - x2) + abs(y1 - y2);
}


void dfs(int i,int j,int ord,vector<vector<bool> > matriz)
{
	bu++;
	if(matriz[i][j])
		return;
	matriz[i][j]=true;
	if(i==0 && j==1) 
	{
		if(ord==f*c)
			res++;
		return;
	}
	if(i==f-1||i==0)
		if(j>0 && j<c-1 && !matriz[i][j-1] && !matriz[i][j+1])
			return;
	if(j==c-1||j==0)
		if(i>0 && i<f-1 && !matriz[i-1][j] && !matriz[i+1][j])
			return;	
	
	
	for(int e=0;e<3;e++)
	{
		if(i==checky[e] && j==checkx[e])
			if(ord!=orden[e])
				return;
			else
				break;
		
		if(ord>=orden[e] && !matriz[checky[e]][checkx[e]] )
			return;
		if(ord<orden[e] && manhattan(j,i,checkx[e],checky[e]) > (orden[e]-ord))
			return;

	}
	for(int e=0;e<4;e++)
		if(i+y[e]<f && i+y[e]>=0 && j+x[e]<c && j+x[e]>=0 && !matriz[i+y[e]][j+x[e]])
			dfs(i+y[e],j+x[e],ord+1,matriz);
}

int main()
{
	int con=1;
	//freopen ("out.txt","w",stdout);
	while(1)
	{
		cin>>f>>c;
		if(!f && !c)
			break;
		cin>>checky[0]>>checkx[0]>>checky[1]>>checkx[1]>>checky[2]>>checkx[2];
		orden[0]=(f*c)/4;
		orden[1]=(f*c)/2;
		orden[2]=(3*f*c)/4;
		res=0;
		bu=0;
		vector<vector<bool> > visitado(9,vector<bool>(9,false));
		// visitado[10][10];
		//memset(visitado,0,sizeof visitado);
		dfs(0,0,1,visitado);
		cout<<"Case "<<con++<<": "<<res<<" "<<bu<<endl;
	}
    return 0;
}


if(i!=0 && j!=1)
	{
	if(i==f-1||i==0)
		if(j>0 && j<c-1 && !matriz[i][j-1] && !matriz[i][j+1])
			return;
	if(j==c-1||j==0)
		if(i>0 && i<f-1 && !matriz[i-1][j] && !matriz[i+1][j])
			return;	
	}