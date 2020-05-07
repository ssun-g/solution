#include<cstdio>
using namespace std;

int arr[5];

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 5; i++)
		if (arr[i] < 40) arr[i] = 40;

	for (int i = 0; i < 5; i++)
		sum += arr[i];

	printf("%d", sum / 5);

	return 0;
}