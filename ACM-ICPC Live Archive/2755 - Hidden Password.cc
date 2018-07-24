// SUFFIX ARRAY CON COMPRESIÓN DE CADENA (REPETICIÓN DE SUBSTRING DENTRO DE UNA CADENA)
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
const int MAX = 200005,MAXLG=20;
string s;
int n;
int P[MAX][MAXLG],sa[MAX];
iii L[MAX];
int LCP[MAX];
char T[MAX];
void buildSA()
{
	if(n==1){sa[0]=0;return;}
	for(int i=0;i<n;i++)
		P[i][0]=s[i];
	for(int cont=1,step=1;cont<n;step++,cont<<=1)
	{
		for(int i=0;i<n;i++)
			L[i]=iii(ii(P[i][step-1],i+cont<n?P[i+cont][step-1]:-1),i);
	
		sort(L,L+n);
		for(int i=0;i<n;i++)
			P[L[i].second][step]=i && L[i].first==L[i-1].first?P[L[i-1].second][step]:i;
			
	}
	for(int i=0;i<n;i++)
		sa[i]=L[i].second;
}

vector<int> KMP(const string &s,const string &t)
{
	vi b(t.size() + 1, -1);
	 for(int i = 1; i <= t.size(); i++)
	 {
		 int p = b[i - 1];
		 while(p != -1 && t[p] != t[i - 1])
		 	p = b[p];
		 b[i] = p + 1;
		 }
		
		 vi ans;
		 for(int i = 0, p = 0; i < s.size(); i++)
		 {
			 while(p != -1 && (p == t.size() || t[p] != s[i]))
			 p = b[p];
			 p++;
			 if(p == t.size())
			 	ans.push_back(i + 1 - t.size());
	 	}
	 return ans;

}
int main() 
{
	int t,c;

	cin>>t;
	while(t--)
	{
		cin>>c>>T;
		s=string(T);
		n=s.size();
		vector<int> kmp;
		kmp=KMP(s+s,s);
		int len=n/(kmp.size()-1);
		strncpy(T,s.c_str(),len);
		T[len]='\0';
		n=(int)strlen(T);
		for(int i = n; i < 2*n; i++) T[i] = T[i - n];
		n*=2;
		s=string(T);
		buildSA();
		for(int i=0;i<n;i++)
			if(sa[i]<n/2)
			{
				cout<<sa[i]<<endl;break;
			}
		
	}
	return 0;
}
