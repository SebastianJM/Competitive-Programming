#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,b;
	vector<int> vec,validacion;
	while(true)
	{
		cin>>n>>b;
		if(n==0&&b==0)
			break;
		vec=vector<int>(b);
		validacion=vector<int>(n,0);
		for(int i=0;i<b;i++)
			cin>>vec[i];
		sort(vec.begin(),vec.end());
		for(int i=0;i<b-1;i++)
			for(int e=i+1;e<b;e++)
				validacion[vec[e]-vec[i]-1]++;
		if(count(validacion.begin(),validacion.end(),0)>0)
			cout<<"N"<<endl;
		else
			cout<<"Y"<<endl;

	}
    return 0;
}