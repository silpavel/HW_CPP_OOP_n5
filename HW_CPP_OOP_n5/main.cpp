#include <iostream>
#include "myclass.h"
#include "List.h"
using namespace std;
void task1();
void task2();
int main() {
	//task1();
	task2();
	
	system("pause");
	return 0;
}
void task1() {
	// 1)
	//myclass mcl; //не должно работать - конструктор недоступен
	myclass *my1 = myclass::get_instance();
	my1->show();
	myclass *my2 = myclass::get_instance(1, 5);
	my2->show();
	//delete my1; //деструктор тоже недоступен
	myclass::free_instance(my1);
	myclass::free_instance(my2);
}
void task2() {
	List lst;
	lst.addEnd(1);
	lst.addEnd(4);
	lst.addEnd(9);
	lst.addEnd(16);
	lst.addEnd(25);
	lst.show();
}