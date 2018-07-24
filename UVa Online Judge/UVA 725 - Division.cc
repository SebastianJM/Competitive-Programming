#include <bits/stdc++.h>

using namespace std;

bool unico(int num1,int num2)
{
	vector<bool> vec(10,false);
	int a;
	if(num1<=9999)
		vec[0]=true;
	while(num1>0)
	{
		a=num1%10;
		if(vec[a])
			return false;
		vec[a]=true;
		num1/=10;
	}
	while(num2>0)
	{
		a=num2%10;
		if(vec[a])
			return false;
		vec[a]=true;
		num2/=10;
	}
	return true;
}

int main()
{
	int n;
	bool pri=true;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		if(pri)
			pri=false;
		else
			cout<<endl;
		
		int con=0;
		for(int i=1234;i<=98765;i++)
		{
			int seg=i*n;
			if(seg>=12345 && seg<=98765 && unico(i,seg))
			{
				con++;
				cout<<seg<<" / ";
				if(i<10000)
					cout<<0;
				cout<<i<<" = "<<n<<endl;				
			}
		}
		if(!con)
			cout<<"There are no solutions for "<<n<<"."<<endl;
	}

	return 0;
}