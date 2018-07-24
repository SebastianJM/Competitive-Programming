#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n;
	string ora, animal, goo, sound;
	cin >> n;
	getchar();
	while (n--)
	{
		
		vector<string> res;
		map<string, string> sonidos;
		map<string, string>::iterator it;
		getline(cin, ora);
		while (1)
		{
			cin >> animal;
			if (animal == "what")
			{
				getline(cin, goo);
				break;
			}
			cin >> goo >> sound;
			sonidos[sound] = animal;
		}
		int ant(-1), nue(-1);
		for (int i = 0; i < ora.length(); i++)
		{
			if (ant < 0)
				ant = 0;
			if (ora[i] == ' ')
			{
				nue = i;
				string aux = ora.substr(ant, nue - ant);
				ant = nue + 1;
				it = sonidos.find(aux);
				if (it == sonidos.end())
					res.push_back(aux);
			}
			else if (i == ora.length() - 1)
			{
				nue = i+1;
				string aux = ora.substr(ant, nue - ant);
				ant = nue + 1;
				it = sonidos.find(aux);
				if (it == sonidos.end())
					res.push_back(aux);
			}
		}
		for (int i = 0; i < res.size(); i++)
		{
			if (i != 0)
				cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
