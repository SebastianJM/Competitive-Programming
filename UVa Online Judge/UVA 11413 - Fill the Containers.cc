#include <bits/stdc++.h>

using namespace std;

int n,c;
vector<int> bot;
vector<vector<int> > grupos;
bool cumple(int x)
{
	int cont=1,rell=0;
	for(int i=0;i<n;i++)
	{
		if(bot[i]>x)
			return false;
		if(rell+bot[i]<=x)
			rell+=bot[i];
		else
		{
			cont++;
			rell=bot[i];
		}
		if(cont>c)
			return false;
	}
	return true;
}


int main()
{
    while(cin>>n>>c)
	{	
		bot=vector<int>(n);
		int suma=0;
		grupos=vector<vector<int> >();
		for(int i=0;i<n;i++)
		{
			cin>>bot[i];
			suma+=bot[i];
		}
		int lo=0,hi=suma+10;
		while(lo<hi)
		{
			int mid=(lo+hi)/2;
			if(cumple(mid))
				hi=mid;			
			else
				lo=mid+1;
		}
		
		cout<<lo<<endl;
		
	}
    return 0;
}