#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int ansA,ansB,t,f,c;
	char m[200][200];
	
	cin>>t;
	while(t--)
	{
		cin>>f>>c;
		ansA=ansB=0;
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
				cin>>m[i][j];
		for(int i=0;i<f;i++)
		{
			for(int j=0;j<c;j++)
			{
				if((i%2==0 && j%2==0) ||(i&1 && j&1))
				{
					if(m[i][j]=='G')
						ansA+=3;
					if(m[i][j]=='R')
						ansB+=5;
				}
				else
				{
					if(m[i][j]=='R')
						ansA+=5;
					if(m[i][j]=='G')
						ansB+=3;
				}
			}
		}
		cout<<min(ansA,ansB)<<endl;
	}
	return 0;
} 