#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int votos,ciudades,aux,max,mm;
    cin>>votos>>ciudades;
    vector<int> ganadores(105,0);
    for(int i=0;i<ciudades;i++)
    {
        max=0;
        mm=0;
        for(int e=0;e<votos;e++)
        {
            cin>>aux;
            if(mm<aux)
            {
                max=e;
                mm=aux;
            }
        }
        ganadores[max]++;
    }
    max=0;
    mm=0;
    for(int i=0;i<votos;i++)
    {
        if(ganadores[i]>max)
        {
            max=ganadores[i];
            mm=i;
        }
    }
    cout<<mm+1;

    return 0;
}