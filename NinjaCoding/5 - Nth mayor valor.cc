#include <iostream>
#include <vector>

using namespace std;

vector<int> vec=vector<int>(10);

void mayor()
{
	int p,mayor;
	mayor=vec[0];
	p=0;
	for(int i=1;i<10;i++)
		if(mayor<vec[i])
		{
			mayor=vec[i];
			p=i;
		}
	vec[p]=0;
}

int devolver()
{
	int mayor;
	mayor=vec[0];
	for(int i=1;i<10;i++)
		if(mayor<vec[i])
			mayor=vec[i];
	return mayor;
			
}
int main()
{ 
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<10;i++)
			cin>>vec[i];
		mayor();
		mayor();
		cout<<n<<" "<<devolver()<<endl;
	}
    return 0;
}