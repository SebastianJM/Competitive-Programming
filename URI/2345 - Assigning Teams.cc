#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int v[4];
	for(int i=0;i<4;i++)
		cin>>v[i];
	sort(v,v+4);
	cout<<abs(v[3]+v[0]-(v[1]+v[2]))<<endl;
	
	return 0;
}