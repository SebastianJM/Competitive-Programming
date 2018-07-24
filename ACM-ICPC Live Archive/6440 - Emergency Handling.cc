#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef long long ll;
const int INF = 200000000;
const int MAX = 26;

struct ing{
    int r,t,s;
    ing(int rr,int tt,int ss):r(rr),t(tt),s(ss){}
};
struct comp {
   bool operator()(const ing &a, const ing &b) const {
      return (a.s - a.r*a.t) < (b.s - b.r*b.t);
   }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,t0,s0,r0,c=1;
    ing aux(0,0,0);
    char a;
    priority_queue< ing ,vector<ing>,comp> q[101];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<c++<<":\n";
        for(int i=0;i<=100;i++)
            q[i]=priority_queue< ing ,vector<ing>,comp>();
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a=='P')
            {
                cin>>t0>>s0>>r0;
                q[r0].push(ing(r0,t0,s0));
            }
            else
            {
                cin>>t0;
                ll ans=0,r_ans=0;
                for(int i=0;i<=100;i++)
                    if(!q[i].empty())
                    {
                        aux=q[i].top();
                        if(ans<=aux.s+aux.r*(t0-aux.t))
                        {
                            ans=aux.s+aux.r*(t0-aux.t);
                            r_ans=i;
                        }
                    }
                q[r_ans].pop();
                cout<<ans<<" "<<r_ans<<"\n";
            }
        }
    }
    return 0;
}