#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;
}

void insert(HeapType *h, int item) {
	int i; i = ++(h->heap_size);
	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2]; i /= 2;
	}
	h->heap[i] = item;
}

int delete(HeapType *h) {
	int parent, child, item, temp;
	item = h->heap[1]; temp = h->heap[(h->heap_size)--];
	parent = 1; child = 2; while (child <= h->heap_size) {
		if ((child<h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		if (temp <= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child; child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	int n, i, tmp;
	HeapType h;
	init(&h);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (h.heap_size == 0)
				printf("0\n");
			else
				printf("%d\n", delete(&h));
		}
		else insert(&h, tmp);
	}
	return 0;
}