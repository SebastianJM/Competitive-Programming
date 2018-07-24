#include <iostream>
#include <vector>

using namespace std;

int main()
{ 
	int g1,g2,sn;
	int t1,t2;
	while(true)
	{
		cin>>g1>>g2>>sn;
		if(g1==-1 && g2==-1 && sn==-1)
			return 0;
		t1=g1*10;
		t2=g2*10;
		sn==1?t1+=150:t2+=150;
		cout<<t1<<" x "<<t2<<endl;
		if(t1!=t2)
		{
			if(t1>t2)
				cout<<"Ganador: Equipo1!"<<endl;
			else
				cout<<"Ganador: Equipo2!"<<endl;
		}
		else
			cout<<"No hay ganador!"<<endl;
	}
    return 0;
}