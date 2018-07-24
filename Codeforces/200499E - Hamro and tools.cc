#include <bits/stdc++.h>
using namespace std;

struct node
{
	int id;
	node* next;
	node(int pid, node* t)
	{
		id=pid;
		next=t;
	}
};
node* last[100004];
node* v[100004]; 
int ans[100004];
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q,u,z;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		node* a=new node(i,NULL);
		last[i]=a;
		v[i]=new node(0,a);
	}
	for(int i=0;i<q;i++)
	{
		cin>>u>>z;
		last[z]->next=v[u]->next;
		last[z]=last[u];
		v[u]->next=NULL;
		last[u]=v[u];
	}
	node* aux=new node(0,NULL);
	for(int i=1;i<=n;i++)
	{
		aux=v[i];
		while(aux->next!=NULL)
		{
			aux=aux->next;
			ans[aux->id]=i;
		}
	}
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		if(!f)
			cout<<" ";
		f=false;
		cout<<ans[i];
	}
	return 0;
}