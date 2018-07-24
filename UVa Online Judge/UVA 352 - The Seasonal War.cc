#include <bits/stdc++.h>

using namespace std;
char matriz[26][26];
int fi,co;

void fill(int c,int f)
{
	matriz[c][f]='0';
	if(f+1<fi)
	{
		if(c-1>=0 && matriz[c-1][f+1]=='1')
		{
			matriz[c-1][f+1]='0';
			fill(c-1,f+1);
		}
		if(matriz[c][f+1]=='1')
		{
			matriz[c][f+1]='0';
			fill(c,f+1);
		}
		if(c+1<co && matriz[c+1][f+1]=='1')
		{
			matriz[c+1][f+1]='0';
			fill(c+1,f+1);
		}
	}

	if(f-1>=0)
	{
		if(c-1>=0 && matriz[c-1][f-1]=='1')
		{
			matriz[c-1][f-1]='0';
			fill(c-1,f-1);
		}
		if(matriz[c][f-1]=='1')
		{
			matriz[c][f-1]='0';
			fill(c,f-1);
		}
		if(c+1<co && matriz[c+1][f-1]=='1')
		{
			matriz[c+1][f-1]='0';
			fill(c+1,f-1);
		}
	}
	if(c-1>=0 && matriz[c-1][f]=='1')
	{
		matriz[c-1][f]='0';
		fill(c-1,f);
	}
	if(c+1<co && matriz[c+1][f]=='1')
	{
		matriz[c+1][f]='0';
		fill(c+1,f);
	}
	
}
int main()
{
	int res,t=1;
	while(cin>>co)
	{
		fi=co;
		res=0;

		for(int i=0;i<co;i++)
			for(int e=0;e<fi;e++)
				cin>>matriz[i][e];

		for(int i=0;i<co;i++)
			for(int e=0;e<fi;e++)
				if(matriz[i][e]=='1')
				{
					res++;
					fill(i,e);
				}
		cout<<"Image number "<<t++<<" contains "<<res<<" war eagles."<<endl;
	}
	return 0;

}