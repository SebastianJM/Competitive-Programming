#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 10000005;

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


int main()
{
    string s;
    int num,l, r;
    cin >> s;
    cin >> num;
    n = s.length();
    for (int i = n; i < 2 * n ; i++)
    {
        t[i] = node();
        if (s[i-n] == '(')
            t[i].b++;
        else
            t[i].c++;
    }
    build();
    while (num--)
    {
    
        cin >> l >> r;
        cout << query(l-1, r-1) << endl;
    }

    return 0;
}