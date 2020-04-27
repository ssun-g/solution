#include<cstdio>
using namespace std;

char arr[8][8];

int main() {
	int answer = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &arr[i][j]);
			if ((i + j) % 2 == 0  && arr[i][j] == 'F') answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}