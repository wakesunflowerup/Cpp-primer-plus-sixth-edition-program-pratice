#include <iostream>
using namespace std;
class complex{
private:	
	double real;
	double imaginary;
public:	
	complex(double a,double b);
	complex();
	~complex();
	friend ostream & operator<<(ostream &os,const complex &a);
	friend istream & operator>>(istream &is,complex &a);
	friend complex operator+(const complex &a,const complex &b);
	friend complex operator-(const complex &a,const complex &b);
	friend complex operator*(const complex &a,const complex &b);
	friend complex operator*(double a,const complex &b);
	friend complex operator*(const complex &b,double a);
	friend complex operator-(const complex &b);
};
