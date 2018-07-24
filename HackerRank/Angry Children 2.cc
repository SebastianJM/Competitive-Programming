#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(unsigned long long arr[], int N, int K) 
{
    unsigned long long ans=LLONG_MAX,a_sum;
    int aux,e;
    for(int i=0;i<=N-K;i++)
    {
        aux=K-1;
        e=i;
        a_sum=0;
        while(aux>0)
        {
            a_sum+=(arr[e+aux]-arr[e])*aux;
            e++;
            aux-=2;
        }
        ans=min(ans,a_sum);
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin>>N>>K;
    unsigned long long arr[N];
    for(int i = 0; i < N; i++) 
        cin>>arr[i];
    
    sort(arr,arr+N);
    cout<<solve(arr,N,K)<<endl;
    return 0;
}

