#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> altos,largos,LIS,LDS;

int LongestIncreasingSubsequence()
{
	int maxx=-1;
	for(int i=0;i<n;i++)
	{
		int ans=largos[i];
		for(int e=0;e<i;e++)
			if(altos[i]>altos[e])
				ans=max(ans,LIS[e]+largos[i]);
		LIS[i]=ans;
		maxx=max(maxx,LIS[i]);
	}
	return maxx;
}

int LongestDecreasingSubsequence()
{
	int minn=-1;
	for(int i=0;i<n;i++)
	{
		int ans=largos[i];
		for(int e=0;e<i;e++)
			if(altos[i]<altos[e])
				ans=max(ans,LDS[e]+largos[i]);
		LDS[i]=ans;
		minn=max(minn,LDS[i]);
	}
	return minn;
}
int main()
{
	int t,q;
	cin>>t;
	q=1;
	while(t--)
	{
		cin>>n;
		altos=vector<int>(n);
		for(int i=0;i<n;i++)
			cin>>altos[i];
		largos=vector<int>(n);
		for(int i=0;i<n;i++)
			cin>>largos[i];
		LIS=LDS=vector<int>(n);
		int inc=LongestIncreasingSubsequence();
		int dec=LongestDecreasingSubsequence();
		if(inc>=dec)
			cout<<"Case "<<q++<<". Increasing ("<<inc<<"). Decreasing ("<<dec<<")."<<endl;
		else
			cout<<"Case "<<q++<<". Decreasing ("<<dec<<"). Increasing ("<<inc<<")."<<endl;

	}
    return 0;
}