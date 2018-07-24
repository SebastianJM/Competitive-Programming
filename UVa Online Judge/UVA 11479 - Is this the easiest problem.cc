#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long n,a,b,c,t=1;
  cin>>n;
  while(n--)
  {
    cin>>a>>b>>c;
    cout<<"Case "<<t++<<": ";
    if(a>0 && b>0 && c>0 && a<b+c && a>abs(b-c) && b<a+c && b>abs(a-c) && c<a+b && c>abs(a-b))
    {
      if(a==b && b==c && a==c)
	cout<<"Equilateral"<<endl;
      else if(a!=b && b!=c && a!=c)
	cout<<"Scalene"<<endl;
      else
	cout<<"Isosceles"<<endl;
    }
    else
      cout<<"Invalid"<<endl;   
  }
}