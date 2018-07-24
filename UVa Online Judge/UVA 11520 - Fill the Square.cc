#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair <int,int> ii;

    int Tc;
    vs filas;
     int N;
     void print(){
          for (int i = 0; i < N; i++) {
            cout << filas[i]<<endl;
        }
     }
bool VACIO(int fil, int col){
    if(filas[fil][col] == '.') return true;
    return false;
}
bool valida(int fil, int col){
    char val  = filas[fil][col] ;
    bool SePuede = true;
    
    if(fil-1>=0){
         SePuede &= filas[fil-1][col] != val; 
    }
    if(col-1>=0){
         SePuede &= filas[fil][col-1]  != val; 
    }
    if(fil+1<N){
         SePuede &= filas[fil+1][col]  != val; 
    }
    if(col+1<N){
         SePuede &= filas[fil][col+1]  != val; 
    }
    
       return SePuede;
    
}
bool ya;
bool BT(int fil, int col){
   
    
    if(col>=N){
        /*BT(fil+1,0);*/fil+=1;col=0;
        }
        if(fil >= N) {if(!ya) print(); ya =true;return true;}
 // cout << fil<<" " << col<<endl;
    for (int i = 'A'; i <= 'G'; i++) {
        if(VACIO(fil,col)){
            filas[fil][col] = i;
            if(valida(fil,col)){
                if(BT(fil,col+1)){
                    return true;
                }
            }
            filas[fil][col] = '.';
        }else{
            if(BT(fil,col+1)){
                   
                    return true;
                }
        }
    }
    return false;
}
int main(){
    
    
    cin >> Tc ;
int tt=1;
    while(Tc--){
       ya =false;
        cin >>N;
        
        
        filas = vs();
        for (int i = 0; i < N; i++) {
            string aux;
            cin >> aux;
            filas.push_back(aux);
           
        }
        cout <<"Case "<<tt++<<":\n";
        BT(0,0);
        
        
        
        
        
    }
    
    
    
    return 0;
}