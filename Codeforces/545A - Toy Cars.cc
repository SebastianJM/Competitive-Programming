#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,aux,it;
	vector<int> vec;
	vec.clear();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		it=1;
		for(int j=0;j<n;j++)
		{
			cin>>aux;
			if(aux==1||aux==3)
				it=0;							
		}
		if(it)
			vec.push_back(i+1);
	}
	cout<<vec.size()<<endl;
	if(vec.size()>0)
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
	
	return 0;
}