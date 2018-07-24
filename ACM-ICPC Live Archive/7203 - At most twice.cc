#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("out.txt", "a", stdout);
	string s;
	vector<int> con;
	int pos, c, val;
	while (cin >> s)
	{
		con = vector<int>(10, 0);
		pos = 0;
		for (int i = 0; i<s.size(); i++)
		{
			c = s[i] - '0';
			con[c]++;
			pos++;
			if (con[c]>2)
			{
				pos--; break;
			}
		}
		if (pos == s.size())
			cout << s << endl;
		else
		{
			//pos--;
			for (int i = pos; i >= 0; i--)
			{
				c = s[i] - '0'; val = -1;
				for (int e = c-1; e >= 0; e--)
					if (con[e]<2)
					{
						con[c]--;
						con[e]++;
						s[i] = e + '0';
						val = i + 1;
						break;
					}

				if (val >= 0)
					break;
				con[c]--;
			}
			for (int i = val; i<s.size(); i++)
				for (int e = 9; e >= 0; e--)
					if (con[e] < 2)
					{
						s[i] = e + '0';
						con[e]++;
						break;
					}
			if (s[0] == '0')
				cout << s.substr(1, s.size()) << endl;
			else
				cout << s << endl;
		}
	}
	return 0;
}