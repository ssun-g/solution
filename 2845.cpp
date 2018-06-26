#include<cstdio>
using namespace std;

int people[5];

int main() {
	int l, p;
	scanf("%d%d", &l, &p);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &people[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", people[i] - (l*p));
	}

	return 0;
}