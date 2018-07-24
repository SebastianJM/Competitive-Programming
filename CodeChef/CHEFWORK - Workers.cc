#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1003
#define MAX 100000004
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
 
 
int main() 
{
    fastIO;
    int n,t[MAX],cost[MAX],min1,min2,min3;
    min1=min2=min3=MAX;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cost[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    for(int i=0;i<n;i++)
    {
        if(t[i]==1)
            min1=min(min1,cost[i]);
        else if(t[i]==2)
            min2=min(min2,cost[i]);
        else 
            min3=min(min3,cost[i]);
    }
    cout<<min(min3,min1+min2)<<endl;
    return 0;
} 