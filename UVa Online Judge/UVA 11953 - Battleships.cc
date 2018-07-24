#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <string>
//#include <bits/stdc++.h>

using namespace std;

char matriz[103][103];
int co,fi,aux;

void fill(int c,int f)
{
		matriz[c][f]='0';
		if(f+1<fi && (matriz[c][f+1]=='x'||matriz[c][f+1]=='@'))
		{
			matriz[c][f+1]='0';
			fill(c,f+1);
		}
		if(f-1>=0 && (matriz[c][f-1]=='x'||matriz[c][f-1]=='@'))
		{
			matriz[c][f-1]='0';
			fill(c,f-1);
		}
		if(c-1>=0 && (matriz[c-1][f]=='x'||matriz[c-1][f]=='@'))
		{
			matriz[c-1][f]='0';
			fill(c-1,f);
		}
		if(c+1<co && (matriz[c+1][f]=='x'||matriz[c+1][f]=='@'))
		{
			matriz[c+1][f]='0';
			fill(c+1,f);
		}	
}
int main()
{
	int res,n,t;
	cin>>n;
	while(t<n)
	{
		cin>>co;
		fi=co;
		if(co==0 && fi==0)
			break;
		res=0;

		for(int i=0;i<co;i++)
			for(int e=0;e<fi;e++)
				cin>>matriz[i][e];

		for(int i=0;i<co;i++)
			for(int e=0;e<fi;e++)
				if(matriz[i][e]=='x')
				{
					res++;
					fill(i,e);			
				}
		cout<<"Case "<<t+1<<": "<<res<<endl;
		t++;
	}

	return 0;

}