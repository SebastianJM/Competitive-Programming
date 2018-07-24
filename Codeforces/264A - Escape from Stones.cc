#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
	vector<int> v;
	cin >> str;
	v.clear();
	for (int i = 0; i <str.length(); i++){
		if (str[i] == 'r'){
			cout << i+1<<"\n";
		}
		else{
			v.push_back(i+1);
		}
	}

	for (int i = v.size()-1; i >=0; i--)
	{
		cout << v[i]<<"\n";
	}

	return 0;
}