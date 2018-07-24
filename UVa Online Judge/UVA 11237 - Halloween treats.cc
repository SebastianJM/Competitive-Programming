#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

using namespace std;
#define MAX 100005

int main () 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int c, n;
    int v[MAX], s[MAX], vis[MAX];
    while (1) 
    {
    	cin>>c>>n;
    	if(!c && !n)
    		break;
        for(int i=1;i<=n;i++)
        	cin>>v[i];
        memset(vis, -1, sizeof vis);

        vis[0] = s[0] = 0;
        for (int i = 1; i <= n; i++) 
        {
            s[i] = (s[i-1] + v[i]) % c;

            if (vis[s[i]] == -1)
                vis[s[i]] = i;
            else 
            {
                for (int j = vis[s[i]] + 1; j <= i; j++)
                {
                	cout<<j;
                	if(j!=i)
                		cout<<" ";
                }
                cout<<"\n";
                break;
            }
        }
    }
    return 0;
}