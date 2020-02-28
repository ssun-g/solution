#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sum;
int arr[100][100];

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int num;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				scanf("%d", &arr[j][k]);
			}
		}

		// sum of rows
		for (int i = 0; i < 100; i++) {
			int s = 0;
			for (int j = 0; j < 100; j++) s += arr[i][j];
			sum.push_back(s);
		}

		// sum of cols
		for (int i = 0; i < 100; i++) {
			int s = 0;
			for (int j = 0; j < 100; j++) s += arr[j][i];
			sum.push_back(s);
		}

		// sum of diagonal_1
		int s = 0;
		for (int i = 0; i < 100; i++) {
			s += arr[i][i];
		}
		sum.push_back(s);

		// sum of diagonal_2
		s = 0;
		for (int i = 0; i < 100; i++) {
			s += arr[i][100 - i];
		}
		sum.push_back(s);

		sort(sum.begin(), sum.end(), desc);
		printf("#%d %d\n", num, sum[0]);
		sum.clear();
	}

	return 0;
}