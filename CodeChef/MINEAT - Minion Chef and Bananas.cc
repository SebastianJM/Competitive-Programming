#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
double ar[N];
int n;
int isPossible(int x)
{
    int val=0;
    double y=(double)x;
    for(int i=0;i<n;i++)
    {
        val+=ceil(ar[i]/y);
    }
    return val;
}
int main() 
{
    fastIO;
    int t,h,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>h;
        for(int i=0;i<n;i++)
	cin>>ar[i];
        int lo = 1, hi = 1e9+2;
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2; // Find middle element (ROUNDED DOWN)
            if(isPossible(mid)<=h) // If mid satisfies the property..
            hi = mid; // Search in: [lo, mid], we are minimizing the value
            else // Else if mid does not satisfy the property..
            lo = mid + 1; // Search in: [mid+1, hi], we want a value that satisfies
        }
        cout<<lo<<"\n";
    }
    return 0;
}