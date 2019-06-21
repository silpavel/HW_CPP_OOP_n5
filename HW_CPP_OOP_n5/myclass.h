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
	char seconds;// 0..59
	char minutes;// 0..59
	char hours;// 0..23
public:
	mytime operator+(mytime r_myt);
	mytime(char sec, char min, char hr);
	mytime() :seconds(0), minutes(0), hours(0) {};
	void show();
};


#endif MYCLASS_H
