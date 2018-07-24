#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int x,y,a,b;
	bool fir=true;
	while(cin>>x>>y)
	{
	    if(!fir)
	        cout<<endl;
	    fir=false;
	    a=min(x,y);
	    b=max(x,y);
	    int ans=b-(b-a+1)+2;
	    for(int i=0;i<b-a+1;i++)
	        cout<<ans+i<<endl;
	}
	return 0;
}