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
public:
	List() { head = NULL; }
	~List();

	void addEnd(int data);
	void addHome(int data);
	void show();
};
#endif LIST_H
