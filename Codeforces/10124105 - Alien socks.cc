#include <bits/stdc++.h>
using namespace std;
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define pb(x) push_back(x)
#define INF (1<<30)
#define eps 1e-9
#define PI acos(-1.0)
typedef pair <int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vector<ii> > vvii;
typedef priority_queue<iii, viii, greater<iii> > pq;
typedef long long ll;
typedef unsigned long long ull;
typedef map<int,int> mii;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);

	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    
	int n,l;
	
	while(cin>>n>>l)
	{
	    mii m;
	
	    for(int i=0; i<n; i++){
	        int nn;cin>>nn;
	        m[nn]++;
	    }
	
	    bool ok=true;
	    for(mii::iterator it=m.begin(); it!=m.end(); it++)
	        if((*it).second%l!=0)       
	            ok=false;break;            
	
	    if(ok)
		cout<<"OK"<<endl;
	    else 
		cout<<"ARGH!!1"<<endl;
    	}


	return 0;
}