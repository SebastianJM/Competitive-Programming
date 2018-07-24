#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef struct num{
    int n;
    int mod;
 
    bool operator<(const num& e) const{
        if(mod != e.mod)
            return mod < e.mod;
             
        if(n%2 && (e.n)%2)
            return n > e.n;
 
        if(n%2 == 0 && (e.n)%2 == 0)
            return n < e.n;
 
        if(n%2)
            return true;
        else
            return false;
    }
 
 
} numero;
 
int main(){
    int n,m;
    numero aux;
    vector<numero> v;
 
    while(1){
        cin >> n >> m;
        v.clear();
        cout << n << " " << m << endl;
        if(n == 0 && m == 0)
            break;
 
        while(n--){
            cin >> aux.n;
            aux.mod = aux.n % m;
            v.push_back(aux);
        }
 
        sort(v.begin(),v.end());
 
        for (int i = 0; i < v.size(); ++i){
            cout << v[i].n << endl;
        }
    }
}