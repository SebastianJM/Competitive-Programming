#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,con;
	bool M[1005];
	string s[1005];
	memset(M, 1, sizeof M);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		
		for (int e = i - 1; e >= 0; e--)
		{
			con = 0;
			for (int z = 0; z < s[i].length(); z++)
				if (s[i][z] != s[e][z])
					con++;
			if (con > 1)
				M[i] = M[e] = false;
		}
			
		
	}
	for (int i = 0; i < n; i++)
		if (M[i])
		{
			cout << s[i];
			return 0;
		}
	return 0;
}