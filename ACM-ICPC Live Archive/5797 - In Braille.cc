#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string n1[10]={".*","*.","*.","**","**","*.","**","**","*.",".*"};
string n2[10]={"**","..","*.","..",".*",".*","*.","**","**","*."};
string n3[10]={"..","..","..","..","..","..","..","..","..",".."};

int main() 
{
	string cry,s1,s2,s3;
	char a1[300],a2[300],a3[300];
	int n;
	char tipo;
	while(true)
	{
		cin>>n;
		if(n==0)
			return 0;
		cin>>tipo;
		if(tipo=='S')
		{
			cin>>cry;
			s1=s2=s3="";
			for(int i=0;i<cry.length();i++)
			{
				if(i!=0)
				{
					s1+=" ";
					s2+=" ";
					s3+=" ";
				}
				s1+=n1[cry[i]-'0'];
				s2+=n2[cry[i]-'0'];
				s3+=n3[cry[i]-'0'];
			}
			cout<<s1<<endl<<s2<<endl<<s3<<endl;
		}
		else
		{
			getchar();
			gets(a1);
			gets(a2);
			gets(a3);
			cry="";
			for(int i=0;i<n*2+n-1;i+=3)
			{
				for(int e=0;e<10;e++)
					if(n1[e][0]==a1[i] && n1[e][1]==a1[i+1] && n2[e][0]==a2[i] && n2[e][1]==a2[i+1])
						cry.push_back(e+'0');
			}
			cout<<cry<<endl;
		}
	}
	return 0;
}