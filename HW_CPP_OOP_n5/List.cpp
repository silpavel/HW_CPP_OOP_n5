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
		if (head) count++;//память выделена
	}
	else {//find last elem
		elem* buf = head;
		while (buf->next)
			buf = buf->next;
		buf->next = new elem(data);
		if (buf->next) count++;//память выделена
	}
}
void List::addHome(int data) {
	//добавление в начало практически мгновенно
	elem *tmp= new elem(data);
	if (tmp) {//память выделена
		count++;
		tmp->next = head;//сдвигаем список
		head = tmp;
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
void List::selectSort() {//сортировка выбором
	elem* prev=head; //указатель на текущий элемент
	if (!prev) return;//0 elems
	if (!prev->next) return;//1 elem
	int maxcount = count-2;//count of elems
	int currentcount;
	while (maxcount >= 0) {//12345 1234 123 12
		//возвращаемся к началу списка
		currentcount = 0;
		prev = head;
		while (currentcount <= maxcount) {
			currentcount++;
			/*
			Далее происходит обмен значениями (содержимым).
			Если бы содержимым были сложные объекты, то точно
			так же можно обменять значения указателей.
			*/
			if (prev->data > prev->next->data) {
				int tmpdata = prev->data;
				prev->data = prev->next->data;
				prev->next->data = tmpdata;
			}
			prev = prev->next;
			
		}
		maxcount--;
		
	}

}







