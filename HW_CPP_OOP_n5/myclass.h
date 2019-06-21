#pragma once
#ifndef MYCLASS_H
#define MYCLASS_H
class myclass {
	int x, y, z;
	myclass(int x = 0, int y = 0, int z = 0);
	~myclass();
public:
	static myclass *get_instance(int x=0, int y=0, int z=0);
	static void free_instance(myclass *inst);
	void set(int x=0, int y=0, int z=0);
	int getX();
	int getY();
	int getZ();
	void show();
};
class mytime {
	int seconds;// 0..59
	int minutes;// 0..59
	int hours;// 0..23
	int ampm;//0 - am, 1 - pm, 2 - 24
public:
	mytime operator+(mytime r_myt);
	mytime(int hr, int min, int sec, const char *ap="mm");
	//mytime(int hr, int min, int sec);
	void show();
	void convertTime();
};


#endif MYCLASS_H
