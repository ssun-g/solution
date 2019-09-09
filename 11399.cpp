#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int timeSum = 0, answer = 0;
	scanf("%d", &n);
	vector<int> atm(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &atm[i]);
	}
	sort(atm.begin(), atm.end());

	for (int i = 0; i < n; i++) {
		timeSum += atm[i];
		answer += timeSum;
	}

	printf("%d\n", answer);

	return 0;
}