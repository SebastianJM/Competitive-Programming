#include <bits/stdc++.h>

using namespace std;

double p,q,r,s,t,u,a;
double valor(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        int modo = valor(1.0)>valor(0.0)?1:0;
        double lo = 0, hi = 1, ans = -1;
        for(int k = 0; k < 50; k++)
        {
            double mid = lo + (hi-lo)/2; 
            a = valor(mid);
            if((a<0.0 && !modo)||(a>0.0 && modo))
                ans = hi = mid;
            else
                ans = lo = mid;
        }
        a = valor(ans);
        if(a>=-0.00001 && a<=0.00001)
            printf("%.4f\n",ans);
        else
            cout<<"No solution"<<endl;
    }
    return 0;
}
