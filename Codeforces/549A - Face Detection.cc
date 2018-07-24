#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int s,b,suma(0);
	bool a,c,e;
	cin>>s>>b;
	vector<int> totalF;
	vector<string> vec=vector<string>(50);
	for(int i=0;i<s;i++)	
			cin>>vec[i];
	a=c=e=false;
	for(int i=0;i<s;i++)
	{
		for(int w=0;w<b;w++)
		{
			if(vec[i][w]=='f')
			{
				if(i-1>=0 && w-1>=0)
				{
					a=c=e=false;
					switch(vec[i-1][w-1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i-1][w])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i][w-1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					if(a==true && c==true && e==true)
					{
						suma++;
						a=c=e=false;
					}				
				}
				////
				if(i+1<s && w+1<b)
				{
					a=c=e=false;

					switch(vec[i+1][w+1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i+1][w])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i][w+1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					if(a==true && c==true && e==true)
					{
						suma++;
						a=c=e=false;
					}
				}
				if(i+1<s && w-1>=0)
				{
					a=c=e=false;

					switch(vec[i+1][w-1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i+1][w])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i][w-1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					if(a==true && c==true && e==true)
					{
						suma++;
						a=c=e=false;
					}
				}
				if(i-1>=0 && w+1<b)
				{
					a=c=e=false;

					switch(vec[i-1][w+1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i-1][w])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					switch(vec[i][w+1])
					{
					case 'a':a=true;
						break;
					case 'c':c=true;
						break;
					case 'e':e=true;
						break;
					}
					if(a==true && c==true && e==true)
					{
						suma++;
						a=c=e=false;
					}
				}
			}
		}
	}
	cout<<suma<<endl;
	return 0;
}