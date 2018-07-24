#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int primes[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int con=0,num;
	string ans;
	for(int i=0;i<15;i++)
	{
		cout<<primes[i]<<endl;
		cin>>ans;
		if(ans=="yes")
		{
			con++;
			num=primes[i];
		}
			
	}
	if(con>1)
	{
		cout<<"composite"<<endl;
		return 0;
	}
	else if(con==0)
	{
		cout<<"prime"<<endl;
		return 0;
	}
	for(int i=num*num;i<=100;i*=num)
	{
		cout<<i<<endl;
		cin>>ans;
		if(ans=="yes")
		{
			cout<<"composite"<<endl;
			return 0;
		}
	}
	cout<<"prime"<<endl;
	return 0;
}