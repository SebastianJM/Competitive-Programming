// CON TREE POLICY STRUCTURES:

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,ope;
	char tipo;
	cin>>n;
	tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;

	for(int i=0;i<n;i++)
	{
		cin>>tipo>>ope;
		if(tipo=='I')
		{
			if(t.find(ope)==t.end())
				t.insert(ope);
		}
		else if(tipo=='D')
		{
			t.erase(ope);
		}
		else if(tipo=='K')
		{
			int res=*t.find_by_order(ope-1);
			if(res==0 && (t.find(ope)==t.end() || t.size()<ope))
				cout<<"invalid\n";
			else
				cout<<res<<"\n";
		}
		else
		{
			cout<<t.order_of_key(ope)<<"\n";
		}
	}
	return 0;
}

// CÓDIGO PPT

#include <bits/stdc++.h>

using namespace std;

struct node {
  int x, y, sz; 
  node *l, *r;  
  node(int x) : x(x), y(rand()), sz(1), l(NULL), r(NULL) {}
};

typedef node* pnode;

int sz(pnode t) { return t? t->sz : 0; }

void upd(pnode t) { if(t) t->sz = 1 + sz(t->l) + sz(t->r); } 

void split(pnode t, int x, pnode &l, pnode &r) 
{
  if(!t)
    l = r = NULL;
  else if(x < t->x)
    split(t->l, x, l, t->l), r = t;
  else
    split(t->r, x, t->r, r), l = t;
  upd(t);
}

void merge(pnode &t, pnode l, pnode r) 
{
  if(!l || !r)
    t = l? l : r;
  else if(l->y > r->y)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd(t);
}

bool find(pnode t, int x) 
{
  if(!t)
    return false;
  if(t->x == x) 
    return true;
  return find(x < t->x? t->l : t->r, x);
}

void insert(pnode &t, pnode it)
{
  if(!t)
    t = it;
  else if(it->y > t->y)
    split(t, it->x, it->l, it->r), t = it;
  else
    insert(it->x < t->x? t->l : t->r, it);
  upd(t);
}

void erase(pnode &t, int x) 
{
  if(!t)
    return;
  else if(t->x == x)
    merge(t, t->l, t->r);
  else
    erase(x < t->x? t->l : t->r, x);
  upd(t);
}
pnode kth(pnode t, int k)
{
  if(k >= sz(t))    
    return NULL;    
  int s = sz(t->l); 
  if(k == s)        
    return t;        
  else if(k < s)   
    return kth(t->l, k); 
  else             
    return kth(t->r, k - s - 1); 
}

int count(pnode t, int x) 
{
  if(!t)
    return 0;
  if(x > t->x)
    return 1 + sz(t->l) + count(t->r, x);
  else
    return count(t->l, x);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,ope;
	char tipo;
	cin>>n;
	pnode t=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>tipo>>ope;
		if(tipo=='I')
		{
			if(!find(t,ope))
				insert(t,new node(ope));
		}
		else if(tipo=='D')
		{
			erase(t,ope);
		}
		else if(tipo=='K')
		{
			pnode aux=kth(t,ope-1);
			if(aux==NULL)
				cout<<"invalid\n";
			else
				cout<<aux->x<<"\n";
		}
		else
		{
			cout<<count(t,ope)<<"\n";
		}
	}
	return 0;
}