#pragma once
#ifndef LIST_H
#define LIST_H
class List {
	class elem {
	public:
		elem(int data);
		~elem();
		elem *next;
		int data;
	};
	elem *head;
	int count=0;
public:
	List() { head = NULL; }
	~List();

	void addEnd(int data);
	void addHome(int data);
	void show();
	void selectSort();
};
#endif LIST_H
