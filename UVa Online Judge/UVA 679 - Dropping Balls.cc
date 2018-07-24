#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, d, i;
    cin>>t;
    while (t--)
    {
        cin>>d>>i;
        int k = 1;
        for (int e = 0; e < d - 1; e++)
            if (i % 2)
            {
                k = k * 2;
                i = (i + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                i /= 2;
            }
        cout<<k<<endl;
    }
	cin>>t;
    return 0;
}