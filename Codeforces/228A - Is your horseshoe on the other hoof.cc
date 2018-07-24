#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	set<int> st;
	set<int>::iterator it;
	int a,res(0);
	cin>>a;
	st.insert(a);
	for(int i=0;i<3;i++)
	{
		cin>>a;
		it=st.find(a);
		if(it!=st.end())
			res++;
		else
			st.insert(a);
	}
	cout<<res;
	return 0;
}
