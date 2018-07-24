#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct arbol
{
	int x;
	int can;
};

bool funcion(arbol a,arbol b)
{
	return a.x<b.x;
}

arbol pos[105];
arbol neg[105];

int main()
{
	int n,cn(0),cp(0),ax,ac;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ax>>ac;
		if(ax>0)
		{
			pos[cp].x=ax;
			pos[cp].can=ac;
			cp++;
		}
		else
		{
			neg[cn].x=-ax;
			neg[cn].can=ac;
			cn++;
		}
	}
	int min;
	if(cp>cn)
		min=cn;
	else if(cn>cp)
		min=cp;
	sort(pos,pos+cp,funcion);
	sort(neg,neg+cn,funcion);
	int res(0);
	for(int i=0;i<min;i++)
	{
		res+=pos[i].can;
		res+=neg[i].can;
	}
	if(min==cn)
		res+=pos[min].can;
	else
		res+=neg[min].can;
	cout<<res;
	return 0;
}