#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

using namespace std;
#define MAX 100005
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    char map[102][102];
    int i, M, N, Q, x, y;
    cin>>t;
    while(t--) 
    {
        cin>>M>>N>>Q;
        for(int i=0;i<M;i++)
        	for(int e=0;e<N;e++)
        		cin>>map[i][e];
        cout<<M<<" "<<N<<" "<<Q<<"\n";

        while(Q--) 
        {
            cin>>x>>y;
            int ans = 1,flag;
            int i, a, b;
            for(i = 0; i <= M || i <= N; i++) 
            {
                flag = 0;
                for(a = x-i; a <= x+i; a++) 
                {
                    for(b = y-i; b <= y+i; b++) 
                    {
                        if(a < 0 || b < 0 || a >= M || b >= N) 
                        {
                            flag = 1;
                            break;
                        }
                        if(map[a][b] != map[x][y])
                            flag = 1;
                    }
                }
                if(flag == 0) 
                {
                    if(ans < 2*i+1)
                        ans = i*2+1;
                } else
					break; 
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}