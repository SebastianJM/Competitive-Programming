#include <iostream>
#include <algorithm>
using namespace std;

int n;
char matriz[7][7];
int com[7][7];

bool cond(int posx,int posy)
{
	if(posx>=n||posy>=n||posy<0||posx<0)
		return false;
	if(matriz[posx][posy]=='0')
		return true;
	return false;
}
bool func(int posx,int posy)
{
	if(posx==n-1&&posy==n-1)
		return true;
	if(!cond(posx,posy)||com[posx][posy]==1)
		return false;
	com[posx][posy]=1;
	if(func(posx+1,posy)||func(posx,posy+1)||func(posx,posy-1)||func(posx-1,posy))
		return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	n=5;
	while(t--)
	{
		for(int i=0;i<5;i++)
			for(int e=0;e<5;e++)
			{
				cin>>matriz[i][e];
				com[i][e]=0;
			}
	
		if(func(0,0)||func(0,1)||func(0,2)||func(0,3)||func(0,4)||func(1,0)||func(2,0)||func(3,0)||func(4,0))
			cout<<"COPS";
		else
			cout<<"ROBBERS";	

		cout<<endl;
	}
	
	return 0;   
}

