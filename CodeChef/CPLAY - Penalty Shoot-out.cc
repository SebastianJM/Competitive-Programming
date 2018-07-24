#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	string s;
	int ronda,a,b,lefta,leftb;
	bool ans;
 
	while(cin>>s)
	{
 
		a=b=0;
		ans=false;
		for(ronda=1;ronda<=s.size();ronda++)
		{
			if(ronda&1 && s[ronda-1]=='1')
				a++;
			else if(ronda%2==0 && s[ronda-1]=='1')
				b++;
			if(ronda<=10)
			{
				if(ronda&1)
				{
					lefta=5-(ronda+1)/2;
					leftb=5-(ronda-1)/2;
				}
				else
				{
					lefta=leftb=5-ronda/2;
				}
				if(a<b && a+lefta<b)
				{
					cout<<"TEAM-B "<<ronda<<"\n";
					ans=true;
					break;
				}
				else if(a>b && b+leftb<a)
				{
					cout<<"TEAM-A "<<ronda<<"\n";
					ans=true;
					break;
				}
			}
			else
			{
				if(ronda%2==0)
				{
					if(a>b)
					{
						cout<<"TEAM-A "<<ronda<<"\n";
						ans=true;
						break;
					}
					else if(b>a)
					{
						cout<<"TEAM-B "<<ronda<<"\n";
						ans=true;
						break;
					}
				}
				
			}
		}
		if(!ans)
			cout<<"TIE\n";
	}
	
	return 0;
} 