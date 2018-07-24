#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n,sh,sm,dh,dm;
	cin >> n;
	while (n--)
	{
		cin >> sh >> sm >> dh >> dm;
		
		printf("------+---------\n");
		printf(" time | elapsed\n");
		printf("------+---------\n");
		if ((sm + dm) >= 60) dh++;
		if (sm == 0){
			printf("%2d:XX | XX\n", sh);
		}
		else{
			printf("%2d:XX | XX - %d\n", sh, sm);
			sm *= -1;
		}
		sh--;
		for (int i = 0; i < dh; i++)
		{
				sm += 60;
				printf("%2d:XX | XX + %d\n", (sh+i+1)%12+1,sm);
			
		}
	}
	return 0;
}