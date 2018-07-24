#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int main() 
{
	int n,k,carry=0,v[200004],neg=0,pri=0,i=0;
	cin>>n>>k;
	vi pos;
	while(i<n)
	{
		cin>>v[i];
		if(v[i]>=0)
			pri++;
		else
		{
			i++;
			neg++;
			break;
		}
		i++;	
	}
	for(;i<n;i++)
	{
		cin>>v[i];
		if(v[i]>=0)
			carry++;
		else
		{
			neg++;
			if(carry>0)
			{
				pos.push_back(carry);
				carry=0;
			}
		}
	}
	//cout<<pri<<" "<<carry<<endl;
	if(neg>k)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(pri==n)
	{
		cout<<0<<endl;
		return 0;
	}
	k-=neg;
	int ans=0;
	sort(pos.begin(),pos.end());
	for(i=0;i<pos.size();i++)
	{
		//cout<<pos[i]<<" "<<k<<endl;
		if(pos[i]<=k)
		{
			k-=pos[i];
		}
		else
			break;
	}
	
	//cout<<i<<endl;
	ans+=pos.size()-i;
	ans*=2;
	//cout<<ans<<endl;
	//cout<<k<<" "<<carry<<endl;
	if(k>=carry)
		k-=carry;
	else
		ans++;

	ans++;
	cout<<ans<<endl;
	return 0;
}