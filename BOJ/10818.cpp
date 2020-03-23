#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	printf("%d %d\n", v[0], v[n - 1]);

	return 0;
}