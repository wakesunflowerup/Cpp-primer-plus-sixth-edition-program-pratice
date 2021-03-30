#include "11-4mytime.h"

 
Time::Time()
{
	hours=0;
	minutes=0;
}
Time::Time(int h,int m)
{
	hours=h;
	minutes=m;
}
void Time::addmin(int m)
{
	minutes+=m;
	hours+=minutes/60;
	minutes%=60;
}
void Time::addhr(int h)
{
	hours+=h;
}
void Time::reset(int h,int m)
{
	hours=h;
	minutes=m;
}
Time operator+(const Time &a,const Time &b)
{
	Time t;
	t.minutes=a.minutes+b.minutes;
	t.hours=a.hours+b.hours+t.minutes/60;
	t.minutes=t.minutes%60;
	return t;
}
Time operator-(const Time &a,const Time &b)
{
	Time t;
	int tot1,tot2;
	tot1=a.minutes+a.hours*60;
	tot2=b.minutes+b.hours*60;
	t.minutes=(tot1-tot2)%60;
	t.hours=(tot1-tot2)/60;
	return t; 
}
Time operator*(const Time &a,double n)
{
	Time t;
	long tot;
	tot=a.minutes*n+a.hours*60*n;
	t.minutes=tot%60;
	t.hours=tot/60;
	return t; 
}
Time operator*(double n,const Time &a)
{
	return (a*n);
}
ostream & operator<<(ostream &os,const Time &a)
{
	os<<a.hours<<" hours, "<<a.minutes<<" minutes";
	return os; 
}
