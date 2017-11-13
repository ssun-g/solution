#include<stdio.h>
#include<string.h>

typedef struct Queue {
	int arr[10001];
	int front;
	int back;
	int size;
}Queue;

void Makequeue(Queue*);
int Empty(Queue*);
int Front(Queue*);
int Back(Queue*);
void Push(Queue*, int);
void Pop(Queue*);

int main(void) {
	int n, data;
	char str[6];

	Queue p;
	Makequeue(&p);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &data);
			Push(&p, data);
		}
		else if (!strcmp(str, "pop")) {
			Pop(&p);
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", p.size);
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", Empty(&p));
		}
		else if (!strcmp(str, "front")) {
			printf("%d\n", Front(&p));
		}
		else if (!strcmp(str, "back")) {
			printf("%d\n", Back(&p));
		}
	}



	return 0;
}

void Makequeue(Queue *p) {
	p->front = 0;
	p->back = 0;
	p->size = 0;
}
int Empty(Queue *p) {
	if (p->front == p->back) return 1;
	else return 0;
}

int Front(Queue *p) {
	if (Empty(p)) return -1;
	else return p->arr[p->front];
}

int Back(Queue *p) {
	if (Empty(p)) return -1;
	else return p->arr[p->back - 1];
}

void Push(Queue *p, int data) {
	p->arr[p->back] = data;
	(p->back)++;
	(p->size)++;
}

void Pop(Queue *p) {
	if (Empty(p)) printf("-1\n");
	else {
		printf("%d\n", p->arr[p->front]);
		(p->front)++;
		(p->size)--;
	}
}