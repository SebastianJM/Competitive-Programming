#include <stdio.h>

int main()
{
    int peso;
    scanf("%d", &peso);
    if (peso % 2 == 0 && peso>2)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
