#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> v;
    int c=1,p=1;
    while(p<=1000)
    {
        v.push_back(p);
        c++;
        p=c*(c+1)/2;
    }
    vector<int> g(1002,0);
    for(int i=0;i<v.size();i++)
        for(int j=i;j<v.size();j++)
            for(int k=j;k<v.size();k++)
                if(v[i]+v[j]+v[k]<=1000)
                    g[v[i]+v[j]+v[k]]=1;
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<g[n]<<endl;
	}
	return 0;
}