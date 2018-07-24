#include <bits/stdc++.h>

using namespace std;

string clean_zero(string s)
{
	int i=0;
	while(s[i]=='0')
		i++;
	return string(s.begin()+i,s.end());
}
int main()
{
  string a,b;
  cin>>a>>b;
  a=clean_zero(a);
  b=clean_zero(b);
  if(a.size()>b.size())
  	printf(">");
  else if(a.size()<b.size())
  	printf("<");
  else
  {
	if(a>b)
		printf(">");
	else if(a<b)
		printf("<");
	else
  		printf("=");
  }
  return 0;
}