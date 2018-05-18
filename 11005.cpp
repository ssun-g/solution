#include<cstdio>
#include<stack>
using namespace std;
stack<int> st;

int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	while (n) {
		st.push(n % b);
		n /= b;
	}

	while (!st.empty()) {
		if (st.top() >= 10) {
			printf("%c", st.top() - 10 + 'A');
			st.pop();
		}
		else {
			printf("%d", st.top());
			st.pop();
		}
	}

	return 0;
}