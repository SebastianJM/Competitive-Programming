#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t,n,c=1;
  bool falla;
  cin>>t;
 
  while(t--)
  {
    cin>>n;
    vector<int> vec(n+1);
    int maxi=0,itera;
	falla=false;
    vec[0]=0;
    for(int i=1;i<=n;i++)
    {    
      cin>>vec[i];
      if(vec[i]-vec[i-1]>maxi)
      {
        maxi=vec[i]-vec[i-1];
		falla=false;
        itera=maxi-1;
      }
      else if(vec[i]-vec[i-1]>itera)
		  falla=true;
	  else if(vec[i]-vec[i-1]==itera)
        itera--;
      
    }
    if(itera<0 || falla)
      cout<<"Case "<<c++<<": "<<maxi+1<<endl;
    else
      cout<<"Case "<<c++<<": "<<maxi<<endl;
    
  }
  return 0;
}