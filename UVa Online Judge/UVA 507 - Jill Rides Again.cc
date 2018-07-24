#include <bits/stdc++.h>

using namespace std;

int t,iniR,finR,iniA,n,a,longit;
vector<int> vec;

int Kadane()
{
	int sum=0,ans=vec[0];
	iniA=iniR=longit=0;
	for(int i=0;i<vec.size();i++)
	{
		sum+=vec[i];
		if(sum>ans)
		{
			ans=sum;
			longit=i-iniA+1;
			iniR=iniA;
			finR=i;
		}
		else if(sum==ans && longit<i-iniA+1)
		{
			longit=i-iniA+1;
			iniR=iniA;
			finR=i;
		}
		if(sum<0)
		{
			sum=0;
			iniA=i+1;
		}
	}
	return ans;
}
int main()
{		
	int pp=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vec=vector<int>(n-1);
		for(int i=0;i<n-1;i++)
			cin>>vec[i];
		int res=Kadane();
		if(res<0)
			cout<<"Route "<<pp++<<" has no nice parts"<<endl;
		else
			cout<<"The nicest part of route "<<pp++<<" is between stops "<<iniR+1<<" and "<<finR+2<<endl;
	}
	return 0;
}