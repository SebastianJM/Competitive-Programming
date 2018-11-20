#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 10001050


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;

vector<int> x,y,xx,yy;
string bus(int pos)
{
	vi ans(x.size(),-1);
	bool haymin=false;
	for(int i=0;i<y.size();i++)
	{
		for(int k=0;k<x.size();k++)
		{
			
			if(i==pos)
			{
					if(x[k]>=0 && x[k]<y[i])
					{			
						haymin=true;
						ans[i]=x[k];
						x[k]=-1;
						break;
					}
			}
			else
			{
				 if(x[k]>=0){
				 	if(haymin)
					{
						//cout<<"min "<<x[k]<<endl;
						ans[i]=x[k];
						x[k]=-1;
						break;
					}
					else if(x[k]<=y[i])
					{
						if(x[k]<y[i])
						{						
							haymin=true;
						}
						ans[i]=x[k];
						x[k]=-1;
						break;
					}
				 }
					
					
			} 
		}
	}
	bool hayans=true;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]<0)
		{
			hayans=false;
		}
	}	
	if(!hayans)
	{
		return "no";
	}
	else
	{
		string res="";
		for(int i=0;i<ans.size();i++)
		{
			res.push_back(ans[i]+'0');
		}	
		return res;
	}
}

int main() 
{
	fastIO;
	ull a,b,c;
	cin>>a>>b;
	c=b;
	
	while(a)
	{
		x.push_back(a%10);
		xx.push_back(a%10);
		a/=10;
	}
	while(c)
	{
		y.push_back(c%10);
		yy.push_back(c%10);
		c/=10;
	}

	if(x.size()!=y.size())
	{
		sort(x.rbegin(),x.rend());
		for(int i=0;i<x.size();i++)
			cout<<x[i];
		cout<<endl;
	}
	else
	{
		vi ans(x.size(),-1);
		sort(x.rbegin(),x.rend());
		sort(xx.rbegin(),xx.rend());
		reverse(y.begin(),y.end());
		reverse(yy.begin(),yy.end());
		bool haymin=false;
		for(int i=0;i<y.size();i++)
		{
			for(int k=0;k<x.size();k++)
			{
				if(x[k]>=0)
				{
					if(haymin)
					{
						ans[i]=x[k];
						x[k]=-1;
						break;
					}
					else if(x[k]<=y[i])
					{
						if(x[k]<y[i])
						{						
							haymin=true;
						}
						ans[i]=x[k];
						x[k]=-1;
						break;
					}
					
				} 
			}
		}
		bool hayans=true;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i]<0)
			{
				hayans=false;
			}
		}
		if(!hayans)
		{
			string solu="";
			for(int i=0;i<x.size();i++)
			{
				for(int k=0;k<x.size();k++)
				{
					x[k]=xx[k];
					y[k]=yy[k];
				}
				string res=bus(i);
				
				if(res!="no")
				{
					solu=res;
				}
			}
			cout<<solu;
		}
		else
		{
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i];
			}
		}
		cout<<endl;
	}
	return 0;
} 