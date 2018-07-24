
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n,h,c,current;
	bool holding;
	cin>>n>>h;
	vector<int> vec=vector<int>(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	current=0;
	holding=false;
	while(1)
	{
		cin>>c;
		if(c==0)
			break;
		else if(c==1)
		{
			if(current>0)
				current--;
		}
		else if(c==2)
		{
			if(current<n-1)
				current++;
		}
		else if(c==3)
		{
			if(!holding && vec[current]>0)
			{
				vec[current]--;
				holding=true;
			}
		}
		else if(c==4)
		{
			if(holding && vec[current]<h)
			{
				vec[current]++;
				holding=false;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0)
			cout<<" ";
		cout<<vec[i];
	}

	return 0;
}