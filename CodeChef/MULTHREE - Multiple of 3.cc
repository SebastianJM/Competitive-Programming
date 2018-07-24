#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef map<int,int> mii;
typedef long long ll;
typedef unsigned long long ull;
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define MAX 100
 
 
int search(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    for (int i = 0; i <= N - M; i++) 
    {
        int j;
 
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) 
            return i;
    }
}
int main()
{
    fastIO;
    int t;
    ull n,x,y;
        cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
	bool haycero=false;
        ull suma=x+y;
        string s;
	        s.pb(x+'0');
	        s.pb(y+'0');
	        for(int i=2;i<MAX;i++)
	        {
	            s.pb((suma%10LL)+'0');
	            if(s[s.size()-1]=='0')
	            	haycero=true;
	            suma+=(suma%10LL);
	        }
        if(haycero)
        {
        	suma=0LL;
	for(int i=0;i<n && s[i]!='0';i++)
		suma+=(s[i]-'0');
		//cout<<suma<<endl;
	if(suma%3ULL==0ULL)
	cout<<"YES\n";
	        else
	        cout<<"NO\n";
        }
        else
        {
        	
	        //cout<<s<<endl;
	        string repe="6248";
	        //<<repe<<endl;
	        int lambda=search(repe,s);
	        //cout<<lambda<<endl;
	        if(n<=lambda)
	        {
	        	suma=0ULL;
		        for(int i=0;i<n;i++)
		            suma+=(s[i]-'0');
		            //cout<<suma<<endl;
		            suma%=3;
	        if(suma==0ULL)
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	        }
	        else
	        {
	        	suma=0ULL;
	        for(int i=0;i<lambda;i++)
	            suma+=(s[i]-'0');
	
	        n-=lambda;
	        ull sum_sub=0LL;
	        for(int i=0;i<repe.size();i++)
	            sum_sub+=(s[i+lambda]-'0');
	        suma%=3ULL;
	        suma+=((n/(ull)repe.size())%3ULL)*(sum_sub%3ULL);
	        suma%=3ULL;
	        if(n%repe.size()!=0)
	        {
	            for(int i=0;i<n%repe.size();i++)
	                suma+=(repe[i]-'0');
	        }
	        //cout<<suma<<endl;
	        suma%=3;
	        if(suma==0ULL)
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	        }
	        
        }
        
    }
    return 0;
}   