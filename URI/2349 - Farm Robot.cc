#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,c,s;
	cin>>n>>c>>s;
	int ans=0,con=1,op;
	if(s==con)
		ans++;
	for(int i=0;i<c;i++)
	{
		cin>>op;
		con+=op;
		
		if(con<1)
			con=n;
		if(con>n)
			con=1;
		if(s==con)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}