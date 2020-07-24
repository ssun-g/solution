#include<cstdio>
#include<stack>
using namespace std;

int main() {
	int n;
	stack<int> st;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) st.pop();
		else st.push(num);
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	printf("%d\n", sum);

	return 0;
}