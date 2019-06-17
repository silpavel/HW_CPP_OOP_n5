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

#endif MYCLASS_H
