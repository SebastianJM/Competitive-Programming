#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
#include <string> 
#include <limits.h>
#include <queue>
#include <list>
#include <bitset>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef vector<VPii> VVPii;

using namespace std;
struct rect { double xmin, xmax, ymin, ymax; 
rect(){}
rect(double x1,double x2,double y1,double y2):xmin(x1),xmax(x2),ymin(y1),ymax(y2){}
}; 
struct edge // Cada lado vertical del rectangulo representa un evento
{
 double x, ymin, ymax; // Lado vertical: 1 punto en x, 2 puntos en y
 int m; // Tipo de evento: inicio(1)/fin(-1)
 bool operator<(const edge &e) const
 {
 return x < e.x;
 }
};
double areaUnionRect(vector<rect> R)
{
 int n = (int)R.size();
 vector<double> ys(2 * n); // Todas las coordenadas y
 vector<edge> e(2 * n); // Vector de eventos
 for(int i = 0; i < n; ++i) // Cada rectangulo define 2 eventos
 {
 e[2 * i].ymin = e[2 * i + 1].ymin = ys[2 * i] = R[i].ymin;
 e[2 * i].ymax = e[2 * i + 1].ymax = ys[2 * i + 1] = R[i].ymax;
 e[2 * i].x = R[i].xmin; e[2 * i + 1].x = R[i].xmax;
 e[2 * i].m = 1; e[2 * i + 1].m = -1; // inicio y fin
 }
 sort(ys.begin(), ys.end()); sort(e.begin(), e.end());
 double ans = 0, cur = 0; // cur: ancho de los rectangulos activos
 for(int i = 0; i < 2 * n; ++i) // Desplazamos una linea imaginaria en Y
 {
 if(i) ans += (ys[i] - ys[i - 1]) * cur; // area = base * altura
 int fag = 0; // Rectangulos activos
 double sx = cur = 0;
 for(int j = 0; j < 2 * n; ++j) // Recorrer todos los eventos
 if(e[j].ymin <= ys[i] && ys[i] < e[j].ymax) // La linea cruza el evento
 {
 if(!fag) sx = e[j].x; // Primer rectangulo activo
 fag += e[j].m; // Actualizamos los rectangulos activos
 if(!fag) cur += e[j].x - sx; // Ya no hay rectangulos activos
 }
 }
 return ans;
}

int main()
{
	int m,c=1;
	vector<rect> r;
	while (1)
	{
		cin>>m;
		if(!m)
			break;
		if(c>1)
			cout<<"\n";
		r.clear();
		cout<<"Test case #"<<c++<<"\n";
		for (int i = 0; i < m; i++)
		{
			double x1, y1, x2, y2;
			cin>>x1>>y1>>x2>>y2;
			r.push_back(rect(x1,x2,y1,y2));
		}
	
		printf("Total explored area: %.2lf\n", areaUnionRect(r));
	}
	return 0;
}
