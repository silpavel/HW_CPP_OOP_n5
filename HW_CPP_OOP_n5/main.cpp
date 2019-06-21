#include <iostream>
#include "myclass.h"
#include "List.h"
#include <time.h>

using namespace std;
void task1();
void task2();
void task3();
int main() {
	//task1();
	//task2();
	task3();
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
	//список заполним генератором
	srand(time(0));
	int randint;
	for (int i = 1; i <= 15; i++) {
		randint = rand()%41;// from 0 to 40
		if (randint%2)//нечетные числа в конец
			lst.addEnd(randint);
		else//четные в начало
			lst.addHome(randint);
	}
	lst.show();
	/*
	Будет использована сортировка выбором наибольшего(пузырьком): в любой
	сортировке элементы переставляются местами, доступ к каждому
	осуществляется по индексу, в связном списке индекс не поможет быстро найти
	элемент в памяти, чтобы его найти, нужно пробежать список от начала.
	В сортировке пызырьком не нужно искать элементы по индексу: мы меняем два
	элемента местами пока пробегаем список.
	*/
	lst.selectSort();
	lst.show();

}
void task3() {
	mytime mt(13, 1, 51);
	mt.show();
}