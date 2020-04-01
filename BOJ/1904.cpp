#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

int main() {
	int n;
	scanf("%d", &n);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	
	for (int i = 3; i <= n; i++) {
		v.push_back((v[i - 2] + v[i - 1])%15746);
	}

	printf("%d\n", v[n]);

	return 0;
}