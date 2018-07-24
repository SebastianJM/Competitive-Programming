#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s,x,y,up;
	int t,n,m;
	char c;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		s.clear();
		x.clear();
		y.clear();
		
		for(int i=0;i<m;i++)
		{
			cin>>c;
			x+=c;
		}

		for(int i=0;i<m;i++)
		{
			cin>>c;
			y+=c;
		}

		for(int i=0;i<n;i++)
		{
			cin>>c;
			s+=c;
		}
		
		s+=s.substr(0,m);

		int ans=0;
		for(int i=0;i<n;i++)
		{
			up=s.substr(i,m);
			if(x<=up && up<=y)
				ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}