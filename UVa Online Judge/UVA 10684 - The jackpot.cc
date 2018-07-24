#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	//5
	//5 5 - 1 5 5
	while (1)
	{
		cin >> n;
		while (!n)
			return 0;
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		int maxi = -2000000000,temp=0;
		for (int i = 0; i < n; i++)
		{
			if (0 <= temp + vec[i])
				temp += vec[i];
			else
				temp = 0;
			if (temp > maxi)
				maxi = temp;
		}
		if (maxi == 0)
			cout << "Losing streak." << endl;
		else
			cout << "The maximum winning streak is "<<maxi <<"."<< endl;
		
	}
	return 0;
}