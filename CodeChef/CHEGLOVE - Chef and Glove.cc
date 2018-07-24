#include <bits/stdc++.h>
using namespace std;
 
#define MAX 100005
int main() 
{
	int t,n,fin[MAX],glo[MAX];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>fin[i];
		for(int i=0;i<n;i++)
			cin>>glo[i];
		bool front,back;
		front=back=true;
		for(int i=0;i<n;i++)
			if(fin[i]>glo[i])
			{
				front=false;
				break;
			}
		for(int i=0;i<n;i++)
			if(fin[i]>glo[n-i-1])
			{
				back=false;
				break;
			}
		if(front && back)
			cout<<"both\n";
		else if(front)
			cout<<"front\n";
		else if(back)
			cout<<"back\n";
		else
			cout<<"none\n";
				
		
	}
	return 0;
} 