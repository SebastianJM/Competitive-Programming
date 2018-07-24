#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void imprimir(vector<int> ar)
{
    for(int i=0;i<ar.size();i++)
        printf("%d ",ar[i]);
    printf("\n");
}
void insertionSort(vector <int>  ar) 
{
    int unsorted,temp;
    for(int i=0;i<ar.size()-1;i++)
    {
        if(ar[i]>ar[i+1])
        {
            unsorted=ar[i+1];
            temp=i+1;
            break;
        }
    }
    for(int i=temp;i>=0;i--)
    {
        if(i==0)
            ar[i]=unsorted;
        if(unsorted<ar[i-1])
            ar[i]=ar[i-1];
        else
        {
            ar[i]=unsorted;
            imprimir(ar);           
            break;
        }
        imprimir(ar);
    }

}
int main(void) 
{
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
   for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) 
   {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
   }

   insertionSort(_ar);
   
   return 0;
}