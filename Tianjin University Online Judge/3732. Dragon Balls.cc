#include <iostream>

using namespace std;

// Union-Find

int pset[10003];
int con[10003];
int can[10003];

void init(int n) 
{ 
	for(int i = 0; i < n; i++) 
	{
		pset[i] = i; 
		con[i]=0;
		can[i]=1;
	}
}
int findSet(int x){
    if(pset[x] != x)
	{
        int p = findSet(pset[x]);
        con[x] += con[ pset[x] ];
        pset[x] = p;
    }
    
    return pset[x];
}
void unionSet(int i, int j) 
{ 
	i=findSet(i);
	j=findSet(j);

	if(i!=j)
	{
		pset[i]=j;
		can[j]+=can[i];
		con[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,c,a,b,t,o=0;
	char p;
	cin>>t;
	while(1)
	{
		if(t==o)
			return 0;
		o++;
		cin>>n>>c;
		init(n);
		cout<<"Case "<<o<<":"<<endl;
		for(int i=0;i<c;i++)
		{
			cin>>p;
			if(p=='T')
			{
				cin>>a>>b;
				unionSet(a-1,b-1);
			}
			else
			{
				cin>>a;
				int h=findSet(a-1);
				cout<<h+1<<" "<<can[h]<<" "<<con[a-1]<<endl;
			}
		}
	}
	return 0;
}

