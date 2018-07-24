#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<double> vec=vector<double>(3);
	while(1)
	{
		cin>>vec[0]>>vec[1]>>vec[2];
		if(!vec[0] && !vec[1] && !vec[2])
			break;
		sort(vec.begin(),vec.end());
		if( vec[2]== sqrt(vec[0]*vec[0]+vec[1]*vec[1]))
			cout<<"right"<<endl;
		else
			cout<<"wrong"<<endl;
	}	
	return 0;
}