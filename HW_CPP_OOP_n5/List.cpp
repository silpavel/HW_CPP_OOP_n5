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
void List::addHome(int data) {
	elem *tmp = head;
	head = new elem(data);
	head->next = tmp;
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
	List lst;//создаем пустой список
	//список будет по возрастанию. Быстрее вставлять в начало.
	//искать будем максимальный элемент, брать будем первый из списка.
	//this - указать на список, который нужно отсортировать
	if (this->head == NULL) return;//список пуст
	elem *pmax = this->head;//указатель на первый элемент (контейнер)
	int vmax = pmax->data;//его полезная нагрузка
	//ищем элемент, который его больше
	elem *prevmax=NULL;//адрес элемента, стоящего перед максимальным
	while (pmax) {
		if (pmax->next->data > pmax->data) {
			
		}
	}

}







