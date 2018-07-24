#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair <int,int> ii;
typedef vector<vi> vvi;
typedef vector<vector<ii>> vvii;
typedef vector<bool> vb;

int Tc;

vi match; // match[i]: Nodo al que está conectado el nodo i
vb visit; // 0: No visitado, 1: Visitado 
vb boy;
int n;
vvi g;
map<char,int> tipo;
map<char,int> num;
int augmenting(int v) // Busca un augmenting path desde el nodo v
{
  if(visit[v]) // Si el nodo esta visitado..
    return 0;  // No hay augmenting path
  visit[v] = true; // Marcar el nodo como visitado
  for(int i = 0; i < (int)g[v].size(); i++) // Por cada vecino..
  {
    int u = g[v][i]; // u es el vecino en el lado derecho
    // Si el vecino u está libre o si hay un augmenting path
    // a través de este nodo.
    if(match[u] == -1 || augmenting(match[u]))
    {
      match[u] = v; // Asignar el nodo u al nodo v
      return 1;     // El maximum match aumenta en 1
    }
  }
  return 0; // El maximum match no aumenta
}

int MCBM(int left) // left: Número de nodos en el lado izquierdo
{
  int ans = 0;       // Maximum matching es 0
  match = vi(n, -1); // Limpiar arreglo de asignación
  for(int i = 0; i < left; i++) // Por cada nodo en el lado izq..
  {
    visit = vb(left, false); // Limpiar arreglo de visitados
    ans += augmenting(i);      // Buscar augmenting path
  }
  return ans;
}

int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Tc;
    string s;
    tipo['D']=0;
    tipo['C']=1;
    tipo['H']=2;
    tipo['S']=3;
    num['2']=0;
    num['3']=1;
    num['4']=2;
    num['5']=3;
    num['6']=4;
    num['7']=5;
    num['8']=6;
    num['9']=7;
    num['T']=8;
    num['J']=9;
    num['Q']=10;
    num['K']=11;
    num['A']=12;
    n=52;
    
    while(Tc--)
    {
        boy=vb(52,false);
        for(int i=0;i<26;i++)
        {
            cin>>s;
            int sss=4*num[s[0]]+tipo[s[1]];
            boy[sss]=true;
        }
        g=vvi(n);
        int au1=0,au2=26;
        
        vi bip(52);
        for(int i=0;i<52;i++)
            if(boy[i])
                bip[i]=au1++;
            else
                bip[i]=au2++;
        for(int i=0;i<52;i++)
        {
            if(boy[i])
                for(int j=0;j<i;j++)
                    if(!boy[j])
                        g[bip[i]].push_back(bip[j]);
        }
        cout<<MCBM(26)<<endl;
    }
    
    
    
    return 0;
}