#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi g;
vi match; 
vb visit; 
int n;

int augmenting(int v) 
{
  if(visit[v])
    return 0;  
  visit[v] = true; 
  for(int i = 0; i < (int)g[v].size(); i++) 
  {
    int u = g[v][i];
   
    if(match[u] == -1 || augmenting(match[u]))
    {
      match[u] = v; 
      return 1;    
    }
  }
  return 0; 
}

int MCBM(int left) 
{
  int ans = 0;       
  match = vi(n, -1); 
  for(int i = 0; i < left; i++) 
  {
    visit = vb(left, false); 
    ans += augmenting(i);   
  }
  return ans;
}

int main()
{
	int t,tam,o=0;
	char matriz[602][602];
	int num[602][602];
	cin>>t;
	while(true)
	{
		if(t==o)
			return 0;
		o++;
		cin>>tam;
		g=vvi(tam*tam);
		for(int i=0;i<tam;i++)
			for(int e=0;e<tam;e++)
			{
				cin>>matriz[i][e];

			}
		int varA=0;
		int varB=(tam*tam)%2==0?(tam*tam)/2:(tam*tam+1)/2;
		for(int i=0;i<tam;i++)
		{
			for(int e=0;e<tam;e++)
			{
				if(i%2==0)
				{
					if(e%2==0)
						num[i][e]=varA++;		
					else
						num[i][e]=varB++;
				}
				else
				{
					if(e%2==0)
						num[i][e]=varB++;
					else			
						num[i][e]=varA++;
					
				}
				if(matriz[i][e]=='#')
				{
					if(i>0 && matriz[i-1][e]=='#')
					{
						g[num[i][e]].push_back(num[i-1][e]);
						g[num[i-1][e]].push_back(num[i][e]);
					}
					if(e>0 && matriz[i][e-1]=='#')
					{
						g[num[i][e]].push_back(num[i][e-1]);
						g[num[i][e-1]].push_back(num[i][e]);
					}
				}
			}
		}
		n=tam*tam;
		cout<<"Case "<<o<<": "<<MCBM(n/2)<<endl;
	}
	
	return 0;
}
