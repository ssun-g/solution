#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class UnderflowException {};

class ListNode {
private:
	int value;
	ListNode *next;

public:
	ListNode() {
		this->next = NULL;
	}
	ListNode(int value, ListNode *next) {
		this->value = value;
		this->next = next;
	}

	ListNode *get_next() {
		return this->next;
	}

	int get_value() {
		return this->value;
	}
};

class Stack {
private:
	int size;
	ListNode *tail;

public:
	Stack() {
		this->size = 0;
		this->tail = NULL;
	}

	~Stack() {
		ListNode *t1 = this->tail;
		ListNode *t2;
		while (t1 != NULL) {
			t2 = t1->get_next();
			delete t1;
			t1 = t2;
		}
	}

	void push(int value) {
		tail = new ListNode(value, tail);
		this->size++;
	}

	int top() {
		if (size == 0) throw UnderflowException();
		return tail->get_value();
	}

	void pop() {
		ListNode *temp = tail->get_next();
		delete tail;
		tail = temp;
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
	Stack st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (s == "pop") {
			if (st.get_empty() == 1) cout << "-1" << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s == "size") cout << st.get_size() << '\n';
		else if (s == "empty") cout << st.get_empty() << '\n';
		else if (s == "top") {
			if (st.get_empty() == 1) cout << "-1" << '\n';
			else cout << st.top() << '\n';
		}
	}

	return 0;
}