#include <bits/stdc++.h>

using namespace std;

string name[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main() 
{
	int n,l,r,i=1;
	cin>>n;
	r=0;
	while(1)
	{
		l=r+1;
		r+=5*i;
		if(n>=l && n<=r)
		{
			//n-=r
			for(int k=l+i,z=0;z<5;k+=i,z++)
				if(n<k)
				{
					cout<<name[z]<<endl;
					return 0;
				}
		}
		i<<=1;
	}
	return 0;
}