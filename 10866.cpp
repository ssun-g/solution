#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
deque<int> dq;

char comm[10];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %s", comm);
		if (!strcmp(comm, "push_front")) {
			scanf("%d", &m);
			dq.push_front(m);
		}
		else if (!strcmp(comm, "push_back")) {
			scanf("%d", &m);
			dq.push_back(m);
		}
		else if (!strcmp(comm, "pop_front")) {
			if (dq.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.front());
			dq.pop_front();
		}
		else if (!strcmp(comm, "pop_back")) {
			if (dq.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.back());
			dq.pop_back();
		}
		else if (!strcmp(comm, "size")) {
			printf("%d\n", dq.size());
		}
		else if (!strcmp(comm, "empty")) {
			printf("%d\n", dq.empty());
		}
		else if (!strcmp(comm, "front")) {
			if (dq.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.front());
		}
		else if (!strcmp(comm, "back")) {
			if (dq.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", dq.back());
		}
	}

	return 0;
}