#include <bits/stdc++.h>
using namespace std;

#define MAX 52
char m[MAX][MAX];
int f,c,inix,iniy,finx,finy;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
vector<int> st;
string s;
bool trav(int a,int b,int ind)
{
	if(ind>=s.size())
	{
		if(a==finx && b==finy)
			return true;
		else
			return false;
	}
	if(a==finx && b==finy)
			return true;
	else if(m[b][a]=='#')
		return false;
	if(a+x[st[s[ind]-'0']]>=0 && a+x[st[s[ind]-'0']]<c && b+y[st[s[ind]-'0']]>=0 && b+y[st[s[ind]-'0']]<f)
		return trav(a+x[st[s[ind]-'0']],b+y[st[s[ind]-'0']],ind+1);
	else 
		return false;
}
int main() 
{
	

	cin>>f>>c;
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
		{
			cin>>m[i][j];
			if(m[i][j]=='S')
			{
				inix=j;
				iniy=i;
			}
			else if(m[i][j]=='E')
			{
				finx=j;
				finy=i;
			}
		}
			
	cin>>s;
	st=vector<int>(4);
	st[0]=0;
	st[1]=1;
	st[2]=2;
	st[3]=3;
	int ans=0;
	do {
    	if(trav(inix,iniy,0))
    		ans++;
  } while ( next_permutation(st.begin(),st.end()));
	cout<<ans<<endl;
	return 0;
}