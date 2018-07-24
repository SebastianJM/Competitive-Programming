#include <iostream>
#include<string>
#include<stack>

using namespace std;
 void voltear(string a){
	stack<char> leer;

	for (int i = 0; i < (int)a.size(); i++)
	{
		switch (a[i])
		{
		case 'i': case 'o':case 'v': case 'w':
		case 'x':
			leer.push(a[i]);
			break;
		case 'b':
			leer.push('d');
			break;
		case 'd':
			leer.push('b');
			break;
		case 'p':
			leer.push('q');
			break;

		case 'q':
			leer.push('p');
			break;
			

		default:
			cout << "INVALID\n";
			return;

		}
	}
	string res = "";
	while (!leer.empty())
	{
		res += leer.top(); leer.pop();
	}
	cout << res<<endl;

}
int main(){
	string lectura;
	cin >> lectura;

	while (lectura != "#")
	{
		voltear(lectura);
		cin >> lectura;
	}
	return 0;
}