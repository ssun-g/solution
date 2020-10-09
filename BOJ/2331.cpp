#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int> v;

int main() {
	int A, P;
	int sum = 0;
	scanf("%d %d", &A, &P);

	v.push_back(A);
	while (true) {
		sum = 0;
		while (A) {
			sum += pow(A % 10, P);
			A /= 10;
		}
		if (v.end() == find(v.begin(), v.end(), sum))v.push_back(sum);
		else break;
		A = sum;
	}

	for (int i = 0; i < v.size(); i++) {
		if (sum == v[i]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}