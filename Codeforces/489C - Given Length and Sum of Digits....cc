#include <iostream>
#include <string>

using namespace std;

int main()
{
	int m,s,suma;
	cin>>m>>s;
	if(m>1&&s==0)
	{
		cout<<"-1 -1";
		return 0;
	}
	if(9*m>=s)
	{
		if(s==0&&m==1)
		{
			cout<<0<<" "<<0;
			return 0;
		}
		string stmax(m,'0');
		string stmin(m,'0');
		suma=0;
		for(int i=0;i<m;i++)
		{
			if(suma>=s)
				break;
			for(int e=9;e>=0;e--)
				if(suma+e<=s)
				{
					suma+=e;
					stmax[i]=e+'0';
					break;
				}
		}
		suma=1;
		stmin[0]='1';
		for(int i=m-1;i>0;i--)
		{
			if(suma>=s)
				break;
			for(int e=9;e>=0;e--)
				if(suma+e<=s)
				{
					suma+=e;
					stmin[i]=e+'0';
					break;
				}
		}
		if(suma<s)
			stmin[0]='1'-'0'+s-suma+'0';
		cout<<stmin<<" "<<stmax;
	}
	else
		cout<<"-1 -1";
	
	return 0;   
}
