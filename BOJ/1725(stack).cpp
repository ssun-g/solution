#include<cstdio>
#include<stack>
using namespace std;

int height[100001];

int main() {
	for (int i = 0; i < 100001; i++) height[i] = -1;

	stack<pair<int, int> > st;
	int n;
	int answer = -1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i]);
	}

	for (int i = 0; i <= n; i++) {
		while (!st.empty() && st.top().first > height[i]) {
			int sum;
			int top = st.top().first;
			st.pop();
			if (st.size() == 0) sum = top*i;
			else sum = top*(i - st.top().second - 1);
			answer = (answer < sum) ? sum : answer;
		}
		st.push(make_pair(height[i], i));
	}

	printf("%d\n", answer);


	return 0;
}