#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    double pmb, pab, p1;
    cin >> pmb >> pab >> p1;
    printf("%.6f\n", p1 * (pmb * (1.0 - pab) + pab * (1.0 - pmb)));
    return 0;
}