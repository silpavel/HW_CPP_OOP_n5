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
//////////////////////
mytime::mytime(int hr, int min, int sec) {
	//имитация переполнения
	seconds = (sec < 60) ? sec : sec%60;
	minutes = (min < 60) ? min : min%60;
	hours = (hr < 24) ? hr : hr % 24;
	ampm = 2;
}
mytime::mytime(int hr, int min, int sec, const char* ap) {
	//имитация переполнения
	seconds = (sec < 60) ? sec : sec % 60;
	minutes = (min < 60) ? min : min % 60;
	hours = (hr <= 12) ? hr : hr % 13+1;
	if (strcmp(ap, "am") == 0) ampm = 0;
	else if (strcmp(ap, "pm") == 0) ampm = 1;
	else ampm = 2;
}

void mytime::show() {
	if (hours == 0) cout << "00";
	else cout << hours;
	cout << ":";
	if (minutes < 10) cout << "0";
	cout << minutes;
	cout << ":";
	if (seconds < 10) cout << "0";
	cout << seconds;
	switch(ampm) {
	case 0:cout << " am"; break;
	case 1:cout << " pm"; break;
	}
	cout << endl;

}