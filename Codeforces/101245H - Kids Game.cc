#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, prio, cnt;
    Node *l, *r;
    Node () {}
    Node (int key) : key (key), prio (rand()), l (NULL), r (NULL) {}
};
typedef Node * pNode;
inline int cnt (pNode t)
{
    return t ? t->cnt : 0;
}
inline void upd_cnt (pNode t)
{
    if (t)
        t->cnt = 1 + cnt (t->l) + cnt (t->r);
}
inline void split (pNode t, int key, pNode &l, pNode &r)
{
    if (!t)
        l = r = NULL;
    else if (key < t-> key)
        split (t->l, key, l, t->l), r = t;
    else
        split (t->r, key, t->r, r), l = t;
    upd_cnt(t);
}

inline void merge (pNode &t, pNode l, pNode r)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->prio > r->prio)
        merge (l->r, l->r, r), t = l;
    else
        merge (r->l, l, r->l), t = r;
    upd_cnt(t);
}
inline void insert(pNode &t, pNode it)
{
    if (!t)
        t = it;
    else if (it->prio > t->prio)
        split (t, it->key, it->l, it->r), t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}
inline  void erase(pNode &t, int key)
{
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}
inline pNode findKth(pNode t, int k)
{
    if (k >= cnt(t))
        return NULL;
    int curr = cnt(t->l);
    if (k == curr)
        return t;
    if (k > curr)
        return findKth(t->r, k - curr - 1);
    return findKth(t->l, k);    
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;

	cin >> n >> m >> k;
	m--;
	pNode t = NULL;
	for (int i = 1; i <= n; i++)
		insert(t, new Node(i));
	
	int pos = 0;
	pNode aux;
	for(int i = 0; i < n; i++)
	{ 
		pos += m;
		if (pos >= n - i)
			pos %= n - i;
		aux =  findKth(t, pos);
		if (aux->key == k)
		{
			cout << i + 1;
			return 0;
		}
		erase(t, aux->key);
	}
}