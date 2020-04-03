#include<cstdio>
using namespace std;

int main() {
	int n, kim, im;
	int rnd = 0;
	scanf("%d %d %d", &n, &kim, &im);

	while (kim != im) {
		kim = kim / 2 + kim % 2;
		im = im / 2 + im % 2;
		rnd++;
	}
	printf("%d\n", rnd);

	return 0;
}