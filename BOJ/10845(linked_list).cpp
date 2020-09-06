#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class UnderflowException {};

class ListNode {
public:
	int value;
	ListNode *next;

	ListNode() {
		this->next = nullptr;
	}

	ListNode(int value, ListNode *next) {
		this->value = value;
		this->next = next;
	}
};

class Queue {
public:
	int size;
	ListNode *head, *tail;

	Queue() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	~Queue() {
		ListNode *t1 = head;
		ListNode *t2;
		while (t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	void push(int value) {
		if (this->size == 0) {
			head = new ListNode(value, nullptr);
			tail = new ListNode(value, nullptr);
			head = tail;
		}
		else {
			tail->next = new ListNode(value, nullptr);
			tail = tail->next;
		}
		this->size++;
	}

	int front() {
		return head->value;
	}

	int back() {
		return tail->value;
	}

	void pop() {
		cout << this->front() << '\n';

		ListNode *temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr) tail = nullptr;
		this->size--;
	}

	int get_size() {
		return this->size;
	}

	int get_empty() {
		if (this->size == 0) return 1;
		else return 0;
	}
};

int main() {
	Queue q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.get_empty()) cout << "-1" << '\n';
			else q.pop();
		}
		else if (s == "size") cout << q.get_size() << '\n';
		else if (s == "empty") cout << q.get_empty() << '\n';
		else if (s == "front") {
			if (q.get_empty()) cout << "-1" << '\n';
			else cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.get_empty()) cout << "-1" << '\n';
			else cout << q.back() << '\n';
		}
	}

	return 0;
}