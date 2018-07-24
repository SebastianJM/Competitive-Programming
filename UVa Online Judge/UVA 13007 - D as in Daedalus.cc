#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int n,t,b,dae,a,actual,best,pozo,mejorPozo;
	int can[5]={1,10,100,1000,10000};
	while(cin>>n>>t)
	{
		pozo=mejorPozo=0;
 
		while(t--)
		{
			cin>>b>>dae;
			actual=dae;
			for(int i=1;i<n;i++)
				cin>>a,actual+=a;
			if(b>=actual)
				pozo+=dae;
			actual-=dae;
			int val=0;
			for(int i=0;i<5;i++)
				if(actual+can[i]<=b)
					val=can[i];
			mejorPozo+=val;
		}
		cout<<mejorPozo-pozo<<endl;
	}
	return 0;
}