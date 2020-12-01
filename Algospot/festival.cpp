#include<cstdio>
using namespace std;

int tc, team, day;
int cost[1001];
double sum, avg;

double festival();

int main() {
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d%d", &day, &team);
		for (int j = 0; j < day; j++) {
			scanf("%d", &cost[j]);
		}

		printf("%.11f\n", festival());
	}

	return 0;
}

double festival() {
	double Min = 100000;
	for (int i = team; i <= day; i++) {
		for (int j = 0; j <= day - i; j++) {
			sum = 0;
			avg = 0;
			for (int k = j; k < i + j; k++) {
				sum += cost[k];
			}
			avg = sum / i;
			if (avg < Min) Min = avg;
		}
	}

	return Min;
}