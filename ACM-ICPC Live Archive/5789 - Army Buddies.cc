#include <bits/stdc++.h>

using namespace std;

struct node
{
	int left;
	int right;
	node(){}
};

node sold[100005];

int main() 
{
	int n,q,l,r;
	while(1)
	{
		cin>>n>>q;
		if(!n && !q)
			break;
		for(int i=1;i<=n;i++)
		{
			sold[i].left=i-1;
			sold[i].right=i+1;
		}
		while(q--)
		{
			cin>>l>>r;
			if(sold[l].left>0)
				cout<<sold[l].left;
			else
				cout<<"*";
			cout<<" ";
			if(sold[r].right<=n)
				cout<<sold[r].right;
			else
				cout<<"*";
			cout<<endl;
			sold[sold[l].left].right=sold[r].right;
			sold[sold[r].right].left=sold[l].left;
		}
		cout<<"-"<<endl;
	}

	return 0;
}