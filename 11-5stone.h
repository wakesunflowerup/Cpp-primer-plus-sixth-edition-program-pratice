#ifndef STONE_H
#define STONE_H
#include <iostream>
using namespace std;
class Stonewt{
private:	
	enum Mode{ST,PO};
	enum {Lbs_per_stn=14};
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
	void setpo();
	void setst(); 
public:
	Stonewt(double lbs);
	Stonewt(int stn,double lbs);
	Stonewt();
	~Stonewt();
	void st_mode();
	void po_mode();
	friend ostream & operator<<(ostream &os,const Stonewt &a); 
	friend Stonewt operator+(const Stonewt &a,const Stonewt &b);
	friend Stonewt operator-(const Stonewt &a,const Stonewt &b);
	friend Stonewt operator*(const Stonewt &a,double n);
	friend Stonewt operator*(double n,const Stonewt &a);
	friend bool operator>(const Stonewt &a,const Stonewt &b);
	friend bool operator>=(const Stonewt &a,const Stonewt &b);
	friend bool operator<(const Stonewt &a,const Stonewt &b);
	friend bool operator<=(const Stonewt &a,const Stonewt &b);
	friend bool operator==(const Stonewt &a,const Stonewt &b);
	friend bool operator!=(const Stonewt &a,const Stonewt &b);
};



#endif
