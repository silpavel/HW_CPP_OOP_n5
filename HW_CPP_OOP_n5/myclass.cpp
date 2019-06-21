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

mytime::mytime(int hr, int min, int sec, const char* ap) {
	//имитация переполнения
	seconds = (sec < 60) ? sec : sec % 60;
	minutes = (min < 60) ? min : min % 60;
	
	if (strcmp(ap, "am") == 0) ampm = 0;
	else if (strcmp(ap, "pm") == 0) ampm = 1;
	else ampm = 2;
	if(ampm==2)
		hours = (hr < 24) ? hr : hr % 24;
	else {
		hours = (hr <= 12) ? hr : hr % 13 + 1;
		if (hours == 0) hours = 12;
	}
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
void mytime::convertTime() {
	if (ampm < 2) {
		if (ampm == 0 && hours == 12) hours = 0;//12:00am = 00:00
		else if (ampm == 1 && hours != 12) hours = hours+12;//3:00pm=12+3=15
		ampm = 2;
	}
}
mytime mytime::operator+(mytime r_myt) {
	int h, m, s;
	if (this->ampm!=2) this->convertTime();
	if(r_myt.ampm!=2) r_myt.convertTime();
	s = this->seconds + r_myt.seconds;
	m = this->minutes + r_myt.minutes;
	h = this->hours + r_myt.hours;
	if (s >= 60) {
		m = m + 1;
		s = s % 60;
	}
	if (m >= 60) {
		h = h + 1;
		m = m % 60;
	}
	if (h >= 24) h = h % 24;
	return mytime(h, m, s);
}
mytime mytime::operator-(mytime r_myt) {
	int h, m, s;
	if (this->ampm != 2) this->convertTime();
	if (r_myt.ampm != 2) r_myt.convertTime();
	s = this->seconds - r_myt.seconds;
	m = this->minutes - r_myt.minutes;
	h = this->hours - r_myt.hours;
	if (s < 0) {
		s = s+60;
		m = m - 1;
	}
	if (m < 0) {
		m = m+60;
		h = h - 1;
	}
	if (h < 0) h = h+24;
	return mytime(h, m, s);
}
bool mytime::operator==(mytime r_myt) {
	if (this->ampm != 2) this->convertTime();
	if (r_myt.ampm != 2) r_myt.convertTime();
	return	this->hours == r_myt.hours		
			&& this->minutes == r_myt.minutes	
			&& this->seconds == r_myt.seconds;
}
/*
здесь private поля недоступны
ostream& operator<<(ostream& out, const mytime& mt) {
	mt.seconds
	return out;
}
*/