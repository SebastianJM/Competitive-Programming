#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,a;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		float res=0;
		map<string,float> pro;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			cin>>pro[s];
		}
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s>>a;
			res+=pro[s]*a;
		}
		printf("R$ %.2f\n",res);
	}
	return 0;
}