#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
};

class Stack {
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		Stack() {
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void push(int x);
		void pop();
		void display();
};

void Stack::push(int x) {
	Node* ptemp = new Node;
	ptemp->data = x;
	ptemp->next = NULL;

	if (head == NULL) {
		head = ptemp;
		tail = ptemp;
		++n;
	} else {
		tail->next = ptemp;
		tail = ptemp;
		++n;
	}
}

void Stack::pop() {
	Node* move = head;
	for (int j=0; j<n-2; ++j)
		move=move->next;

	move->next = NULL;
	tail = move;
	--n;
}

void Stack::display() {
	if (head == NULL) {
		cout << "There are no elements in the stack." << endl;
	} else {
		Node* move = head;
		while(move != NULL) {
			cout << move->data << endl;
			move = move->next;
		}
	}
}

int main() {
	Stack stack1;
	int foo=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> foo;
		stack1.push(foo);
	}

	stack1.display();
	stack1.push(25);
	stack1.display();
	stack1.pop();
	stack1.display();

	return 0;
}