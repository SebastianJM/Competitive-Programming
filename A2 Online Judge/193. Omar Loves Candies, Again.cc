#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string cad;
    int t,max,pos;
    char letra;
    vector<int> vec;
    cin>>t;
    while(t--)
    {
        vec=vector<int>(26,0);
        cin>>cad;
        max=0;
        pos=0;
        for(int i=0;i<cad.length();i++)
            vec[cad[i]-97]++;
        for(int i=0;i<26;i++)
            if(vec[i]>max)
            {
                max=vec[i];
                pos=i;
            }
        letra=pos+97;
        cout<<max<<" "<<letra<<endl;
    }
    return 0;
}