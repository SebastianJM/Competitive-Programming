#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef complex<long double> base;

#define PI (2*acos(0.0))
 
void fft(vector<base> &a, bool invert)
{
    int n = (int)a.size();
    for(int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for(; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if(i < j)
            swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1)
    {
        long double ang = 2 * PI / len * (invert? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len)
        {
            base w(1);
            for(int j = 0; j < len / 2; j++)
            {
                base u = a[i + j], v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert)
        for(int i = 0; i < n; i++)
            a[i] /= n;
}
void mul(const vi &a, const vi &b, vi &res)
{
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);
    fft(fa, false), fft(fb, false);
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    res.resize(n);
    for(int i = 0; i < n; i++)
        res[i] = ll(fa[i].real() + 0.5);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vi a,b,ans;
    int n,x,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=b=vi(n+1);
        for(int i=0;i<=n;i++)
            cin>>a[i];
        for(int i=0;i<=n;i++)
            cin>>b[i];
        mul(a,b,ans);
        for(int i=0;i<2*n+1;i++)
        {
            if(i)
                cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";    
    }
    return 0;       
}
 