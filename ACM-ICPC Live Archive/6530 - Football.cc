#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, g, f,au, c,pun;
	
	while (cin >> n >> g)
	{
		vector<int> vec;

		pun = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> f >> c;
			if (c-f >= 0)
				vec.push_back(c-f);
			else
				pun += 3;
		}
		sort(vec.begin(), vec.end());
		au = vec.size() + 1;
		for (int i = 0; i < vec.size(); i++)
			if (g >= vec[i] + 1)
			{
				g -= vec[i] + 1;
				pun += 3;
			}
			else if (g>0 && g == vec[i])
			{
				pun++;
				break;
			}
			else
			{
				au = i;
				break;
			}
		for (int i = au; i < vec.size(); i++)
			if (vec[i] == 0)
				pun++;
			else
				break;
		cout << pun << endl;
		
	}
	
	return 0;
}