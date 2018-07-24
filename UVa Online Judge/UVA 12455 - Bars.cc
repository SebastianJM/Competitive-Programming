#include<stdio.h>
#include<iostream>
// CON BITMASK

#include <bits/stdc++.h>
using namespace std;

int v[21],t,k,n;

bool solve(int bitmask,int suma)
{
	if(suma==k)
		return true;
	if(suma>k)
		return false;
	for(int i=0;i<n;i++)
		if(!(bitmask & (1<<i)) && solve(bitmask|(1<<i),suma+v[i]))
			return true;
	return false;
}
int main() 
{
	
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		for(int i=0;i<n;i++)
			cin>>v[i];
		if(solve(0,0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

// CON RECURSIVIDAD SIMPLE

#include<vector>
using namespace std;

vector<int> vec;
int lon,n;
bool Recursividad(int i,int suma)
{
	if(suma==lon)
		return true;
	for(int e=i+1;e<n;e++)
		if(Recursividad(e,suma+vec[e]))
			return true;
	if(suma>lon)
		return false;
	return false;
}

int main()
{
	int t,val;
	cin>>t;
	while(t--)
	{
		cin>>lon;
		cin>>n;
		val=0;
		vec=vector<int>(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		for(int i=0;i<n;i++)
			if(Recursividad(i,vec[i]))
			{
				val=1;
				break;
			}
		if(lon==0 || val==1)
			cout<<"YES"<<endl;	
		else
			cout<<"NO"<<endl;
	}
    return 0;
}