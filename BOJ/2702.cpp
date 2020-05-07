#include<cstdio>
using namespace std;

int main() {
	int n, a, b;
	int Max[1], Min;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		if (a < b) {
			int l = 1;
			while (1) {
				if ((b*l) % a == 0) {
					Min = b*l;
					break;
				}
				l++;
			}
			if (b%a == 0)
				Max[0] = a;
			else {
				for (int j = 1; j <= 1000; j++)
					if (a%j == 0 && b%j == 0)
						Max[0] = j;
			}
		}
		else {
			int l = 1;
			while (1) {
				if ((a*l) % b == 0) {
					Min = a*l;
					break;
				}
				l++;
			}
			if (a%b == 0)
				Max[0] = b;
			else {
				for (int j = 1; j <= 1000; j++)
					if (a%j == 0 && b%j == 0)
						Max[0] = j;
			}
		}
		printf("%d %d\n", Min, Max[0]);
	}
	return 0;
}