#ifndef MYTIME_H
#define MYTIME_H
#include <iostream>
using namespace std;

class Time{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m=0);
	void addmin(int m);
	void addhr(int h);
	void reset(int h=0,int m=0);
	friend Time operator+(const Time &a,const Time &b);
	friend Time operator-(const Time &a,const Time &b);
	friend Time operator*(const Time &a,double n);
	friend Time operator*(double n,const Time &a);
	friend ostream & operator<<(ostream &os,const Time &a);
};

#endif
