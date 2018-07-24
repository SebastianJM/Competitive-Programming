#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 30005*2;

int n;

struct node
{
	int a,b,c;
	node(){ a = 0; b = 0; c = 0; }
	node(int ax, int bx,int cx): a(ax), b(bx), c(cx){}
};

node combine(const node &L, const node &R)
{
	int mini = min(L.b, R.c);
	return node(L.a+R.a+mini*2,L.b+R.b-mini,L.c+R.c-mini);
}
node t[MAX * 2 + 5];

void build()
{
	for (int i = n - 1; i > 0; i--)
		t[i] = combine(t[i << 1], t[i << 1 | 1]);
}

int query(int l, int r)
{
	node ansL, ansR;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if (l & 1) ansL = combine(ansL, t[l]);
		if (!(r & 1)) ansR = combine(t[r], ansR);
	}
	node aux = combine(ansL, ansR);
	return aux.a;
}

void update(int i)
{
	int b, c;
	if (t[i+n].b == 1)
			b = 0, c = 1;
	else
			b = 1, c = 0;
	
	for (t[i += n] =node(0, b, c); i >>= 1;)
	{
		t[i] = combine(t[i << 1], t[i << 1 | 1]);
	}
}

int main()
{
	string s;
	int num, l, r,aux;
	for (int e = 0; e < 10; e++)
	{
		cin >> num;
		cin >> s;
		cin >> num;
		
		n = s.length();
		for (int i = n; i < 2 * n; i++)
		{
			t[i] = node();
			if (s[i - n] == '(')
				t[i].b++;
			else
				t[i].c++;
		}
		build();
		cout << "Test " << e + 1 << ":" << endl;
		while (num--)
		{
			cin >> aux;
			if (aux > 0)
				update(aux - 1);
			else
			{
				if (query(0,s.length()-1) == s.length())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
				
		}
	}

	return 0;
}