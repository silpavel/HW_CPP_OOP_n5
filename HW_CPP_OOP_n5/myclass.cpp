#include "myclass.h"
#include <iostream>
using namespace std;
myclass *myclass::get_instance(int x, int y, int z) {
	return new myclass(x, y, z);
}
void myclass::set(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
int myclass::getX() { return x; }
int myclass::getY() { return y; }
int myclass::getZ() { return z; }
void myclass::show() {
	cout << "( " << x << ", " << y << ", " << z << " )\n";
}
myclass::myclass(int x, int y, int z) :x(x), y(y), z(z) {
	cout << "myclass(xyz) constr " << (int)this << endl;;
}
void myclass::free_instance(myclass *inst) {
	//дополнительные действия, помимо удаления объекта, невозможные внутри деструктора
	delete inst;
}
myclass::~myclass() {
	cout << "myclass destructor " << (int)this << endl;
}