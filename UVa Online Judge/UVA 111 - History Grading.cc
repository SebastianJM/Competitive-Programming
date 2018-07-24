#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> orden,alumno,LIS;

int LongestIncreasingSubsequence()
{
	int maxx=-1;
	for(int i=0;i<n;i++)
	{
		int ans=1;
		for(int e=0;e<i;e++)
			if(alumno[i]>alumno[e])
				ans=max(ans,LIS[e]+1);
		LIS[i]=ans;
		maxx=max(maxx,ans);
	}
	return maxx;
}
int main()
{
	int a;
	cin>>n;
	orden=vector<int>(n);
	for(int i=0;i<n;i++)
	{
		cin>>orden[i];
		orden[i]--;	
	}
	while(cin>>a)
	{
		alumno=LIS=vector<int>(n);
		a--;
		alumno[a]=orden[0];
		for(int i=1;i<n;i++)
		{
			cin>>a;
			a--;
			alumno[a]=orden[i];
		}
		cout<<LongestIncreasingSubsequence()<<endl;
	}
    return 0;
}