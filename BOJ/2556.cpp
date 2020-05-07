#include <cstdio>
using namespace std;
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}