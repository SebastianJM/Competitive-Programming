#include <bits/stdc++.h>

using namespace std;

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,c,u,ans=0;
	string s;
	cin>>n>>c>>u;
	vector<int> cero,uno,dos;
	cin>>s;
	for(int i=0;i<n;i++)
			if(s[i]=='0')
				cero.push_back(i);
			else if(s[i]=='1')
				uno.push_back(i);
			else
				dos.push_back(i);
	if(c+u>n)
		cout<<-1<<endl;
	else
	{
		
		int cuno=uno.size(),cdos=dos.size(),ccero=cero.size();
		if(c>ccero)
		{
			int i=0,j=0;
			if(cuno>u)
			{
				j=min(cuno-u,c-ccero);
				for(i=0;i<j;i++)
				{
					s[uno[i]]='0';
					ans++;
					ccero++;
				}
				cuno-=j;
				
			}
	
			int op=c-ccero;
			if(c>ccero)
				for(j=0;j<op;j++)
				{
					s[dos[j]]='0';
					ans++;
					ccero++;
				}
			if(u<=cuno)
				for(int k=0;k<cuno-u;k++,i++)
				{
					
					ans++;
					s[uno[i]]='2';
				}
			else
			{
				for(int k=0;k<u-cuno;k++,j++)
				{
					
					ans++;
					s[dos[j]]='1';
				}
			}
		}
		else if(u>cuno)
		{
			int i=0,j=0;
			
			if(c<ccero)
			{
				j=min(ccero-c,u-cuno);
			
				for(i=0;i<j;i++)
				{
					s[cero[i]]='1';
					ans++;
					cuno++;
					
				}
				ccero-=j;
			}

			int op=u-cuno;
			if(u>cuno)
				for(j=0;j<op;j++)
				{
					s[dos[j]]='1';
					ans++;
					cuno++;
				}

			if(c<ccero)
				for(int k=0;k<ccero-c;k++,i++)
				{
					s[cero[i]]='2';
					ans++;
				}
			else
			{
				for(int k=0;k<c-ccero;k++,j++)
				{
					
					ans++;
					s[dos[j]]='0';
				}
			}
		}
		else
		{
			int i,j=min(ccero-c,n-u-c);
			if(c<ccero)
				for(i=0;i<j;i++)
				{
					s[cero[i]]='2';
					ans++;
					cdos++;
					
				}
			j=min(cuno-u,n-u-c);
			if(u<cuno)
				for(i=0;i<j;i++)
				{
					s[uno[i]]='2';
					ans++;
					cdos++;
					
				}
		}
		cout<<ans<<endl;
		cout<<s<<endl;
	}
	return 0;
}