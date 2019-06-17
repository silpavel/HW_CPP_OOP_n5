#include <iostream>
#include "List.h"
using namespace std;
List::elem::elem(int data) : data(data), next(NULL) {
	cout << "Elem constr" << '\t' << (int)this << endl;
}
List::elem::~elem() {
	cout << "Elem destr" << '\t' << (int)this << endl;
}
void List::addEnd(int data) {
	if (head == NULL) {
		head = new elem(data);
	}
	else {//find last elem
		elem* buf = head;
		while (buf->next)
			buf = buf->next;
		buf->next = new elem(data);
	}
}
void List::show() {
	elem *buf = head;
	cout << "[ ";
	while (buf) {
		cout << buf->data << ", ";
		buf = buf->next;
	}
	cout << "]";
	cout << endl;
}
List::~List() {
	if (head) {
		elem* next = head->next;
		delete head;
		elem* tmp;
		while (next) {
			tmp = next;
			next = next->next;
			delete tmp;
		}
	}
}