#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,v[1005],a[505];
	bool tie=true;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	for(int i=0,e=1;e<n;e+=2,i++)
	{
		a[i]=abs(v[e]-v[e-1]);
		if(a[i]>0)
			tie=false;
	}
	if(tie)
		cout<<-1<<endl;
	else
	{
		sort(a,a+n/2);
		int i=0,e=n/2-1,ger=0,gia=0,ans=0;
		
		while(i<e)
		{
			ger+=a[e];
			while(i<e)
			{
				if(gia+a[i]<ger)
				{
					gia+=a[i++];
					ans++;
				}
				else
					break;
			}
			e--;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 