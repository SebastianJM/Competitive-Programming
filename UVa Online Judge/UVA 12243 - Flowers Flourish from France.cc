#include <bits/stdc++.h>

using namespace std;

int main()
{

	char s[1500], fin;
	fin = '*';
	while (1)
	{
		gets(s);
		int e = 0;
		while (s[e] == ' ')
			e++;
		char f = s[e];
		if (fin == f)
			return 0;
		bool es = true;


		for (int i = 1; i<strlen(s) - 1; i++)
		{
			if (s[i] == ' ')
			{
				i++;
				if (i < strlen(s))
				{
					if (s[i] != f && s[i] != f + 32 && s[i] != f - 32)
						es = false;
				}
			}
		}
		if (es)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}